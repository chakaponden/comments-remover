#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


QDir MainWindow::GetOutputFolder() const
{
    return QDir();
}

QVector<QString> MainWindow::GetInputFiles() const
{
    return QVector<QString>();
}

MainWindow::~MainWindow()
{
    delete ui;
}
