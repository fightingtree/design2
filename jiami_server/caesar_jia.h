#ifndef CAESAR_JIA_H
#define CAESAR_JIA_H
#include <QTcpSocket>
#include <QTcpServer>
#include <QWidget>
#include <QProcess>
namespace Ui {
class Caesar_jia;
}

class Caesar_jia : public QWidget
{
    Q_OBJECT

public:
    explicit Caesar_jia(QWidget *parent = nullptr);
    ~Caesar_jia();

private slots:
    void on_cut_clicked();

    void on_decrption_clicked();
    void readOutput();
    void change(int i);

    void on_inFile_clicked();

    void on_outFile_clicked();

    void on_zero_clicked();

private:
    Ui::Caesar_jia *ui;
    QTcpSocket *tcpSocket;
    QTcpServer *tcpServer;
    QProcess *process;
    QString out;
    QString str;
    int flag;
};

#endif // CAESAR_JIA_H
