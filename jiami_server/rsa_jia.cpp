#include "rsa_jia.h"
#include "ui_rsa_jia.h"
#include <QFile>
#include <QFileDialog>
RSA_jia::RSA_jia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RSA_jia)
{
    ui->setupUi(this);
    int e =1;
    change(e);
    ui->ciphertext->setPlaceholderText("密文");
    ui->condition->setPlaceholderText("连接状态");
    ui->keyword_a->setPlaceholderText("解密时需输入私钥");
    ui->keyword_b->setPlaceholderText("解密时需输入私钥");
    this->process = new QProcess;
    QObject::connect(process,SIGNAL(readyRead()),this,SLOT(readOutput()));
    tcpServer = NULL;
    tcpSocket = NULL;
    tcpServer = new QTcpServer(this);
    tcpServer ->listen(QHostAddress::Any,10000);
    connect(tcpServer,&QTcpServer::newConnection,[=](){
        tcpSocket = tcpServer->nextPendingConnection();
        QString ip = tcpSocket->peerAddress().toString();
        qint16 port=tcpSocket->peerPort();
        QString temp = QString("[%1:%2]:成功连接").arg(ip).arg(port);
        ui->condition->setText(temp);

        connect(tcpSocket,&QTcpSocket::readyRead,[=](){
            QByteArray array = tcpSocket->readAll();
            //ui->ciphertext->setText(array);
            QString cmd = "./rsa.py 1 "+array;
            //qDebug()<<cmd;
            process->start(cmd);
            out = tr("");
            ui->ciphertext->setText(out);
        });
    });
}

RSA_jia::~RSA_jia()
{
    delete ui;
}

void RSA_jia::on_decrption_clicked()
{
    if(NULL == tcpSocket){
        return;
    }
    qDebug()<<flag;
    int d = 2;
    change(d);
    QString str = ui->ciphertext->toPlainText();
    QString cmd = "./rsa.py 2 "+ui->keyword_a->text()+" "+ui->keyword_b->text()+" "+str;
    qDebug()<<cmd;
    process->start(cmd);
    out=tr("");
}

void RSA_jia::on_cut_clicked()
{
    if(tcpSocket == NULL){
        return;
    }
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket = NULL;
    ui->condition->setText("连接已断开");
}

void RSA_jia::readOutput(){
    qDebug()<<flag;
   out += process->readAll();
   if(flag == 1){
   ui->ciphertext->setText(out);
   }
   else{
      // qDebug()<<out;
       tcpSocket->write(out.toUtf8().data());
   }
   flag = 1;
}

void RSA_jia::change(int i){
    flag = i ;
}


void RSA_jia::on_inFile_clicked()
{
    QString path= QFileDialog::getOpenFileName(this,"open","../","TXT(*.txt)");
    if(path.isEmpty()==false){
        QFile file(path);
        bool isOK=file.open(QIODevice::ReadOnly);
        if(isOK==true){
            QByteArray array=file.readAll();
            ui->ciphertext->setText(array);
        }
        file.close();
}
}

void RSA_jia::on_outFile_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"save","../","TXT(*.txt)");
    if(path.isEmpty()==false){
        QFile file;
        file.setFileName(path);
        bool isOK=file.open(QIODevice::WriteOnly);
        if(isOK==true){
            QString str=ui->ciphertext->toPlainText();
            file.write(str.toUtf8());
        }
        file.close();
    }
}

void RSA_jia::on_zero_clicked()
{
    ui->ciphertext->setText(" ");
    ui->keyword_a->setText(" ");
    ui->keyword_b->setText(" ");
}
