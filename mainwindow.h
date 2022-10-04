#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_start_pushButton_clicked();

    void on_stop_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_close_clicked();

private:
    Ui::MainWindow *ui;
};
