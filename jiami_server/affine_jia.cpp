#include "affine_jia.h"
#include "ui_affine_jia.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
Affine_jia::Affine_jia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Affine_jia)
{
    ui->setupUi(this);
    int e = 1;
    change(e);
    ui->condition->setPlaceholderText("连接状态");
    ui->ciphertext->setPlaceholderText("密文");
    ui->keyword_a->setPlaceholderText("0-25,(a,26)=1");
    ui->keyword_b->setPlaceholderText("0-25");
    this->process = new QProcess;
    QObject::connect(process,SIGNAL(readyRead()),this,SLOT(readOutput()));
    tcpServer = NULL;
    tcpSocket = NULL;
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,3333);
    connect(tcpServer,&QTcpServer::newConnection,[=](){
        tcpSocket = tcpServer->nextPendingConnection();
        QString ip = tcpSocket->peerAddress().toString();
        qint16 port= tcpSocket->peerPort();
        QString temp = QString("[%1:%2]:成功连接").arg(ip).arg(port);
        ui->condition->setText(temp);

        connect(tcpSocket,&QTcpSocket::readyRead,[=](){
            QByteArray array = tcpSocket->readAll();
            //服务器传来的字符串array
            QString cmd = "./test.py 1 "+array;
            qDebug()<<cmd;
            process->start(cmd);
            out = tr("");
            ui->ciphertext->setText(out);
        });
    });
}

Affine_jia::~Affine_jia()
{
    delete ui;
}

void Affine_jia::on_decrption_clicked()
{
    if(NULL == tcpSocket){
        QMessageBox::critical(NULL,"错误","未进行连接",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
        return;
    }
    int e = 2;
    change(e);
    QString str = ui->ciphertext->toPlainText();
    QString cmd = "./test.py 2 "+ui->keyword_a->text()+" "+ui->keyword_b->text()+" "+str;
    process->start(cmd);
    out = tr("");
    //tcpSocket->write();
}

void Affine_jia::on_cut_clicked()
{
    if(tcpSocket == NULL){
        return;
    }
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    ui->condition->setText("连接已经断开");
    tcpSocket= NULL;
}
void Affine_jia::change(int i){
    flag = i;
}

void Affine_jia::readOutput(){
    out +=process->readAll();
    if(flag==1){
        ui->ciphertext->setText(out);
    }
    else{
        tcpSocket->write(out.toUtf8().data());
    }
    flag = 1;
}

void Affine_jia::on_inFile_clicked()
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

void Affine_jia::on_outFile_clicked()
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

void Affine_jia::on_zero_clicked()
{
    ui->ciphertext->setText(" ");
    ui->keyword_a->setText(" ");
    ui->keyword_b->setText(" ");
}
