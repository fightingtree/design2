#ifndef DH_JIA_H
#define DH_JIA_H

#include <QWidget>

namespace Ui {
class DH_jia;
}

class DH_jia : public QWidget
{
    Q_OBJECT

public:
    explicit DH_jia(QWidget *parent = nullptr);
    ~DH_jia();

private:
    Ui::DH_jia *ui;
};

#endif // DH_JIA_H
