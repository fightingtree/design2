#include "dh_jia.h"
#include "ui_dh_jia.h"

DH_jia::DH_jia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DH_jia)
{
    ui->setupUi(this);
}

DH_jia::~DH_jia()
{
    delete ui;
}
