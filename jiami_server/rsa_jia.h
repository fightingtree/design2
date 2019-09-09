#ifndef RSA_JIA_H
#define RSA_JIA_H

#include <QWidget>
#include <QProcess>
#include <QTcpSocket>
#include <QTcpServer>
namespace Ui {
class RSA_jia;
}

class RSA_jia : public QWidget
{
    Q_OBJECT

public:
    explicit RSA_jia(QWidget *parent = nullptr);
    ~RSA_jia();

private slots:
    void on_decrption_clicked();
    void readOutput();
    void change(int i);
    void on_cut_clicked();

    void on_inFile_clicked();

    void on_outFile_clicked();

    void on_zero_clicked();

private:
    Ui::RSA_jia *ui;
    QTcpSocket *tcpSocket;
    QTcpServer *tcpServer;
    QProcess *process;
    QString out;
    QString str;
    int flag;
};

#endif // RSA_JIA_H
