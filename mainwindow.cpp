#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    textEdit2 = new QTextEdit();
   /* printer = new QPrinter(QPrinter::PrinterResolution);
    printer->setOutputFormat(QPrinter::PdfFormat);
    printer->setOutputFileName("sample.pdf");
    //printer->setPaperSize(QPrinter::A4);
    printer->setPageSize(QPageSize::A4);
    printer->setFullPage(true);
    printer->setResolution(300);

    preview = new QPrintPreviewWidget(printer, this);
    ui->verticalLayout->addWidget(preview);
    preview->setFont(QFont("Arial",18,QFont::Bold));

    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(bprint()));
    connect(preview, SIGNAL(paintRequested(QPrinter*)), this, SLOT(MainWindow::Print(QPrinter*)));

    preview->setZoomFactor(1);
    preview->show();*/
    QString mensaje="GRACIAS POR SU COMPRA";
   /*QString html =
         "<div align=right>"
            "Santa Cruz, 03/08/2020"
         "</div>"
         "<div align=left>"
            "Graciela Gomez<br>"
            "2do anillo<br>"
            "121-43 city"
         "</div>"
         "<h1 align=center>CAMARA ALEMANA SANTA CRUZ</h1>"
         "<p align=justify>"
            "document content document content document content document content document content document content document content content "
            "document content document content document content document content document content document content document content content "
         "</p>"
         "<div align=right>Saludos y "+mensaje+"</div>";
         ui->textEdit->setText(html);*/
    QString cantidad,descripcion,precio,total;
    cantidad="70";
    descripcion="lavandina";
    precio="56.6";
    total="89.21";

    QString html =
         "<div align=center>"
            "<h2 align=center>CAMARA ALEMANA SANTA CRUZ</h2><br>"
            "Numero de NIT:<br>"
            "Direccion:<br>"
            "Santa Cruz, 03/08/2020"
         "</div>"
         "<div align=center>"
            "Nro. Boleta de venta:<br>"
            "Cliente:<br>"
            "Fecha:<br>"
         "</div>"
         "<div align=center "
               "<table style='border:hidden' align=center>"
               "<tbody>"
               "<tr>"
                   "<th>CANTIDAD </th>"
                   "<th>DESCRIPCION </th>"
                   "<th>PRECIO </th>"
                   "<th>TOTAL</th>"
               "</tr>";
                int numero=0;
                QString html2;
                while(numero<5)
                {
                  html2= html2+"<tr >"
                       "<td align=center>"+cantidad+"</td>"
                       "<td align=center>"+descripcion+"</td>"
                       "<td align=center>"+precio+"</td>"
                       "<td align=center><h4>"+total+"</h4></td>"
                   "</tr>";
                    numero++;
                }

               QString html3="</tbody>"
               "</table>"
         "</div>"
            "<br>"
            "<br>"
         "<div align=center>"+mensaje+"</div>";
         ui->textEdit->setText(html+html2+html3);
         textEdit2->setText(html+html2+html3);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::Print(QPrinter *printer)
{
       /* QPainter p(printer);
        p.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform, true);


        for (int page = 0; page < 5; page++)
        {
            p.drawText(1750, 200, QString("Date: %1").arg(QDateTime::currentDateTime().toString("dd.MM.yyyy")));


         p.fillRect(QRect(150,150,2179,125),QBrush(QColor(222,222,230,255)));
            printer->newPage();
        }*/
}




void MainWindow::on_pushButton_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPageSize::B6);
    QPrintPreviewDialog preview2(&printer, this);
    preview2.setWindowFlags ( Qt::Window );
    QObject::connect(&preview2, SIGNAL(paintRequested(QPrinter* )),this, SLOT(print(QPrinter* )));
    preview2.exec();
}
void MainWindow::print(QPrinter *printer)
{
    //ui->textEdit->print(printer);
    textEdit2->print(printer);
    //QMessageBox::information(this,"","mentro a bprint");
}
void MainWindow::holaMundo()
{
  QMessageBox::information(this,"","hola mundo");
  std::cout<<"hola mundo"<<std::endl;
}
