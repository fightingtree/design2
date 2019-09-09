#ifndef VIGENERE_JIA_H
#define VIGENERE_JIA_H
#include <QTcpSocket>
#include <QTcpServer>
#include <QWidget>
#include <QProcess>
namespace Ui {
class Vigenere_jia;
}

class Vigenere_jia : public QWidget
{
    Q_OBJECT

public:
    explicit Vigenere_jia(QWidget *parent = nullptr);
    ~Vigenere_jia();

private slots:
    void on_decrption_clicked();

    void on_cut_clicked();
    void change(int i);
    void readOutput();

    void on_inFile_clicked();

    void on_outFile_clicked();

    void on_zero_clicked();

private:
    Ui::Vigenere_jia *ui;
    QTcpSocket *tcpSocket;
    QTcpServer * tcpServer;
    QProcess *process;
    QString out;
    QString str;
    int flag;
};

#endif // VIGENERE_JIA_H
