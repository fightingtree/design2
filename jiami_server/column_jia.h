#ifndef COLUMN_JIA_H
#define COLUMN_JIA_H
#include <QTcpSocket>
#include <QTcpServer>
#include <QProcess>
#include <QWidget>

namespace Ui {
class Column_jia;
}

class Column_jia : public QWidget
{
    Q_OBJECT

public:
    explicit Column_jia(QWidget *parent = nullptr);
    ~Column_jia();

private slots:
    void on_decrption_clicked();
    void readOutput();
    void change(int i);

    void on_cut_clicked();

    void on_inFile_clicked();

    void on_outFile_clicked();

    void on_zero_clicked();

private:
    Ui::Column_jia *ui;
    QTcpSocket *tcpSocket;
    QTcpServer *tcpServer;
    QProcess *process;
    QString out;
    QString str;
    int flag;
};

#endif // COLUMN_JIA_H
