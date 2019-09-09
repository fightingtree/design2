#include "content.h"
#include "ui_content.h"

Content::Content(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Content)
{
    ui->setupUi(this);
    stack = new QStackedWidget(this);
    stack->setFrameStyle(QFrame::Panel | QFrame::Raised);
    caesar_jia = new Caesar_jia();
    affine_jia = new Affine_jia();
    vigenere_jia = new Vigenere_jia();
    playfair_jia = new Playfair_jia();
    permutation_jia = new Permutation_jia();
    column_jia = new Column_jia();
    rc4_jia = new RC4_jia();
    des_jia = new DES_jia();
    rsa_jia = new RSA_jia();
    dh_jia = new DH_jia();

    stack->addWidget(caesar_jia);
    stack->addWidget(affine_jia);
    stack->addWidget(vigenere_jia);
    stack->addWidget(playfair_jia);
    stack->addWidget(permutation_jia);
    stack->addWidget(column_jia);
    stack->addWidget(rc4_jia);
    stack->addWidget(des_jia);
    stack->addWidget(rsa_jia);
    stack->addWidget(dh_jia);

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(2);
    mainLayout->addWidget(stack,0,0);
}

Content::~Content()
{
    delete ui;
}
