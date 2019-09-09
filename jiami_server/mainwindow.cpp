#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QToolBar>
#define SHADOW_WIDT 5
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget w;
    createAction();
    createToolBar();
    content = new Content(this);
    setCentralWidget(content);
    w.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createAction(){
    openStack[0]=new QAction(tr("Caesar"),this);
    openStack[0]->setStatusTip(tr("Caesar 加密端:2222"));
    connect(openStack[0],SIGNAL(triggered(bool)),this,SLOT(openCaesar()));

    openStack[1]=new QAction(tr("Affine"),this);
    openStack[1]->setStatusTip(tr("Affine 加密端:3333"));
    connect(openStack[1],SIGNAL(triggered(bool)),this,SLOT(openAffine()));

    openStack[2]=new QAction(tr("Vigenere"),this);
    openStack[2]->setStatusTip(tr("Vigenere 加密端:4444"));
    connect(openStack[2],SIGNAL(triggered(bool)),this,SLOT(openVigenere()));

    openStack[3]=new QAction(tr("Playfair"),this);
    openStack[3]->setStatusTip(tr("Playfair 加密端:5555"));
    connect(openStack[3],SIGNAL(triggered(bool)),this,SLOT(openPlayfair()));

    openStack[4]=new QAction(tr("Permutation"),this);
    openStack[4]->setStatusTip(tr("Permutation 加密端:6666"));
    connect(openStack[4],SIGNAL(triggered(bool)),this,SLOT(openPermutation()));

    openStack[5]=new QAction(tr("Column"),this);
    openStack[5]->setStatusTip(tr("Column 加密端:7777"));
    connect(openStack[5],SIGNAL(triggered(bool)),this,SLOT(openColumn()));

    openStack[6]=new QAction(tr("RC4"),this);
    openStack[6]->setStatusTip(tr("RC4 加密端:8888"));
    connect(openStack[6],SIGNAL(triggered(bool)),this,SLOT(openRC4()));

    openStack[7]=new QAction(tr("DES"),this);
    openStack[7]->setStatusTip(tr("DES 加密端:9999"));
    connect(openStack[7],SIGNAL(triggered(bool)),this,SLOT(openDES()));

    openStack[8]=new QAction(tr("RSA"),this);
    openStack[8]->setStatusTip(tr("RSA 加密端:10000"));
    connect(openStack[8],SIGNAL(triggered(bool)),this,SLOT(openRSA()));

    openStack[9]=new QAction(tr("DH"),this);
    openStack[9]->setStatusTip(tr("DH:1111"));
    connect(openStack[9],SIGNAL(triggered(bool)),this,SLOT(openDH()));


}

void MainWindow::createToolBar(){
    stackTool = addToolBar("tools");
    stackTool->addAction(openStack[0]);
    stackTool->addAction(openStack[1]);
    stackTool->addAction(openStack[2]);
    stackTool->addAction(openStack[3]);
    stackTool->addAction(openStack[4]);
    stackTool->addAction(openStack[5]);
    stackTool->addAction(openStack[6]);
    stackTool->addAction(openStack[7]);
    stackTool->addAction(openStack[8]);
    stackTool->addAction(openStack[9]);
}

void MainWindow::openCaesar(){
    this->content->stack->setCurrentIndex(0);
}

void MainWindow::openAffine(){
    this->content->stack->setCurrentIndex(1);
}

void MainWindow::openVigenere(){
    this->content->stack->setCurrentIndex(2);
}

void MainWindow::openPlayfair(){
    this->content->stack->setCurrentIndex(3);
}

void MainWindow::openPermutation(){
    this->content->stack->setCurrentIndex(4);
}

void MainWindow::openColumn(){
    this->content->stack->setCurrentIndex(5);
}

void MainWindow::openRC4(){
    this->content->stack->setCurrentIndex(6);
}

void MainWindow::openDES(){
    this->content->stack->setCurrentIndex(7);
}

void MainWindow::openRSA(){
    this->content->stack->setCurrentIndex(8);
}

void MainWindow::openDH(){
    this->content->stack->setCurrentIndex(9);
}
