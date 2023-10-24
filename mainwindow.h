#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPrintPreviewWidget>

#include <QPainter>
#include <QDateTime>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPrinter *printer;
    QPrintPreviewWidget *preview;


private slots:
    void on_pushButton_clicked();
    void print(QPrinter *printer);
    void holaMundo();

private:
    Ui::MainWindow *ui;
    void Print(QPrinter *printer);
    QTextEdit *textEdit2;

};
#endif // MAINWINDOW_H
