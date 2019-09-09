#ifndef PERMUTATION_JIA_H
#define PERMUTATION_JIA_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QProcess>
namespace Ui {
class Permutation_jia;
}

class Permutation_jia : public QWidget
{
    Q_OBJECT

public:
    explicit Permutation_jia(QWidget *parent = nullptr);
    ~Permutation_jia();

private slots:
    void on_decrption_clicked();
    void readOutput();
    void change(int i);

    void on_cut_clicked();

    void on_inFile_clicked();

    void on_outFile_clicked();

    void on_zero_clicked();

private:
    Ui::Permutation_jia *ui;
    QTcpSocket *tcpSocket;
    QTcpServer *tcpServer;
    QProcess *process;
    QString out;
    QString str;
    int flag;
};

#endif // PERMUTATION_JIA_H
