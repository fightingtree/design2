#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QHostAddress>
#include <QMessageBox>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plaintext->setPlaceholderText("明文");
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(choose()));
/*    tcpSocket= NULL;
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,&QTcpSocket::connected,[=](){
        ui->condition->setText("成功与加密端连接");
    });
    connect(tcpSocket,&QTcpSocket::readyRead,[=](){
        QByteArray array = tcpSocket->readAll();
        ui->plaintext->setText(array);
    });*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::choose(){
    if(ui->comboBox->currentIndex()==0){
        ui->port_line->setText(" ");
    }
    else if(ui->comboBox->currentIndex()==1){
        ui->port_line->setText("2222");
        ui->keyword_a->setPlaceholderText("输入数字");
        ui->keyword_b->setText(" ");
        ui->keyword_b->setEnabled(false);

    }
    else if(ui->comboBox->currentIndex()==2){
        ui->port_line->setText("3333");
        ui->keyword_a->setPlaceholderText("0-25,(a,26)=1");
        ui->keyword_b->setPlaceholderText("(0-25");
        ui->keyword_b->setEnabled(true);
    }
    else if(ui->comboBox->currentIndex()==3){
        ui->port_line->setText("4444");
        ui->keyword_a->setPlaceholderText("输入字母");
        ui->keyword_b->setText(" ");
        ui->keyword_b->setEnabled(false);
    }
    else if(ui->comboBox->currentIndex()==4){
        ui->port_line->setText("5555");
        ui->keyword_a->setPlaceholderText("输入字母");
        ui->keyword_b->setText(" ");
        ui->keyword_b->setEnabled(false);
        ui->plaintext->setPlaceholderText("明文字母数为偶数");
    }
    else if(ui->comboBox->currentIndex()==5){
        ui->port_line->setText("6666");
        ui->keyword_a->setPlaceholderText("输入字母");
        ui->keyword_b->setText(" ");
        ui->keyword_b->setEnabled(false);
     }
    else if(ui->comboBox->currentIndex()==6){
        ui->port_line->setText("7777");
        ui->keyword_a->setPlaceholderText("1<=n<=5,n=5");
        ui->keyword_b->setText(" ");
        ui->keyword_b->setEnabled(false);

    }
    else if(ui->comboBox->currentIndex()==7){
        ui->port_line->setText("8888");
        ui->keyword_a->setPlaceholderText("输入字母");
        ui->keyword_b->setText(" ");
        ui->keyword_b->setEnabled(false);
    }
    else if(ui->comboBox->currentIndex()==8){
        ui->port_line->setText("9999");
        ui->keyword_a->setPlaceholderText("8 byte");
        ui->keyword_b->setText(" ");
        ui->keyword_b->setEnabled(false);
    }
    else if(ui->comboBox->currentIndex()==9){
        ui->port_line->setText("10000");
        ui->keyword_a->setText(" ");
        ui->keyword_a->setEnabled(false);
        ui->keyword_b->setText(" ");
        ui->keyword_b->setEnabled(false);
        ui->plaintext->setPlaceholderText("明文输入数字");
    }
    else {
        ui->port_line->setText("1111");
    }

}
//与加密端建立连接
void MainWindow::on_pushButton_clicked()
{

    tcpSocket= NULL;
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,&QTcpSocket::connected,[=](){
        ui->condition->setText("成功与加密端连接");
    });
    connect(tcpSocket,&QTcpSocket::readyRead,[=](){
        QByteArray array = tcpSocket->readAll();
        ui->plaintext->setText(array);
    });
    //获取IP、端口
    QString ip = ui->ip_line->text();
    qint16 port = ui->port_line->text().toInt();
    //主动与加密端建立连接
    tcpSocket->connectToHost(QHostAddress(ip),port);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString str = ui->keyword_a->text()+" "+ui->keyword_b->text()+" "+ui->plaintext->toPlainText();
  //  qDebug()<<str;
    tcpSocket->write(str.toUtf8().data());
}

void MainWindow::on_pushButton_6_clicked()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    ui->condition->setText("连接已断开");
}

void MainWindow::on_pushButton_3_clicked()
{
    QString path= QFileDialog::getOpenFileName(this,"open","../","TXT(*.txt)");
    if(path.isEmpty()==false){
        QFile file(path);
        bool isOK=file.open(QIODevice::ReadOnly);
        if(isOK==true){
            QByteArray array=file.readAll();
            ui->plaintext->setText(array);
        }
        file.close();
}
}

void MainWindow::on_pushButton_4_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"save","../","TXT(*.txt)");
    if(path.isEmpty()==false){
        QFile file;
        file.setFileName(path);
        bool isOK=file.open(QIODevice::WriteOnly);
        if(isOK==true){
            QString str=ui->plaintext->toPlainText();
            file.write(str.toUtf8());
        }
        file.close();
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->plaintext->setText(" ");
    ui->keyword_a->setText(" ");
    ui->keyword_b->setText(" ");
}
