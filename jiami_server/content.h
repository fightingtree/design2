#ifndef CONTENT_H
#define CONTENT_H
#include "caesar_jia.h"
#include "affine_jia.h"
#include "vigenere_jia.h"
#include "playfair_jia.h"
#include "permutation_jia.h"
#include "column_jia.h"
#include "rc4_jia.h"
#include "des_jia.h"
#include "rsa_jia.h"
#include "dh_jia.h"
#include <QFrame>
#include <QStackedWidget>
#include <QGridLayout>
namespace Ui {
class Content;
}

class Content : public QFrame
{
    Q_OBJECT

public:
    explicit Content(QWidget *parent = nullptr);
    QStackedWidget *stack;
    Caesar_jia *caesar_jia;
    Affine_jia *affine_jia;
    Vigenere_jia *vigenere_jia;
    Playfair_jia *playfair_jia;
    Permutation_jia *permutation_jia;
    Column_jia *column_jia;
    RC4_jia *rc4_jia;
    DES_jia *des_jia;
    RSA_jia *rsa_jia;
    DH_jia *dh_jia;

    ~Content();

private:
    Ui::Content *ui;
    QGridLayout *mainLayout;
};

#endif // CONTENT_H
