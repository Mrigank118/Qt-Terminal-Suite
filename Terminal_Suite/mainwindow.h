#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>
#include <QDateTime>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QProcess>

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
    void on_CalculatorButton_clicked();
    void on_ToDoButton_clicked();
    void on_FourRowButton_clicked();
    void on_SlotMachineButton_clicked();
    void on_AlarmButton_clicked();
    void on_CameraButton_clicked();
    void on_MusicButton_clicked();

private:
    void decrementBattery();
    void updateBatteryLabel(int value);
    void updateTime();

    Ui::MainWindow *ui;
    QProgressBar *batteryProgressBar;
    QLabel *batteryLabel;
    QLabel *currentTimeLabel;
    QTimer *timer;
};

#endif // MAINWINDOW_H
