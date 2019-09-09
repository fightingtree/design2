#ifndef PLAYFAIR_JIA_H
#define PLAYFAIR_JIA_H
#include <QTcpSocket>
#include <QTcpServer>
#include <QProcess>
#include <QWidget>

namespace Ui {
class Playfair_jia;
}

class Playfair_jia : public QWidget
{
    Q_OBJECT

public:
    explicit Playfair_jia(QWidget *parent = nullptr);
    ~Playfair_jia();

private slots:
    void on_decrption_clicked();
    void readOutput();
    void change(int i);

    void on_cut_clicked();

    void on_inFile_clicked();

    void on_outFile_clicked();

    void on_zero_clicked();

private:
    Ui::Playfair_jia *ui;
    QTcpSocket *tcpSocket;
    QTcpServer *tcpServer;
    QProcess *process;
    QString out;
    QString str;
    int flag;
};

#endif // PLAYFAIR_JIA_H
