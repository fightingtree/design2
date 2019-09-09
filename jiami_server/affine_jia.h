#ifndef AFFINE_JIA_H
#define AFFINE_JIA_H
#include <QTcpSocket>
#include <QTcpServer>
#include <QWidget>
#include <QProcess>
namespace Ui {
class Affine_jia;
}

class Affine_jia : public QWidget
{
    Q_OBJECT

public:
    explicit Affine_jia(QWidget *parent = nullptr);
    ~Affine_jia();

private slots:
    void on_decrption_clicked();

    void on_cut_clicked();
    void change(int i);
    void readOutput();
    void on_inFile_clicked();

    void on_outFile_clicked();

    void on_zero_clicked();

private:
    Ui::Affine_jia *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QProcess *process;
    QString out;
    QString str;
    int flag;
};

#endif // AFFINE_JIA_H
