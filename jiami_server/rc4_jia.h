#ifndef RC4_JIA_H
#define RC4_JIA_H
#include <QProcess>
#include <QTcpSocket>
#include <QTcpServer>
#include <QWidget>

namespace Ui {
class RC4_jia;
}

class RC4_jia : public QWidget
{
    Q_OBJECT

public:
    explicit RC4_jia(QWidget *parent = nullptr);
    ~RC4_jia();

private slots:
    void on_decrption_clicked();
    void readOutput();
    void change(int i);

    void on_cut_clicked();

    void on_inFile_clicked();

    void on_outFile_clicked();

    void on_zero_clicked();

private:
    Ui::RC4_jia *ui;
    QTcpSocket *tcpSocket;
    QTcpServer *tcpServer;
    QProcess *process;
    QString out;
    QString str;
    int flag;
};

#endif // RC4_JIA_H
