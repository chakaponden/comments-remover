#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QString>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QDir GetOutputFolder() const;
    QVector<QString> GetInputFiles() const;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
