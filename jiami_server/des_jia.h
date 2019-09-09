#ifndef DES_JIA_H
#define DES_JIA_H
#include <QTcpSocket>
#include <QTcpServer>
#include <QProcess>
#include <QWidget>

namespace Ui {
class DES_jia;
}

class DES_jia : public QWidget
{
    Q_OBJECT

public:
    explicit DES_jia(QWidget *parent = nullptr);
    ~DES_jia();

private slots:
    void on_decrption_clicked();
    void readOutput();
    void change(int i);

    void on_cut_clicked();

    void on_inFile_clicked();

    void on_outFile_clicked();

    void on_zero_clicked();

private:
    Ui::DES_jia *ui;
    QTcpSocket *tcpSocket;
    QTcpServer *tcpServer;
    QProcess *process;
    QString out;
    QString str;
    int flag;
};

#endif // DES_JIA_H
