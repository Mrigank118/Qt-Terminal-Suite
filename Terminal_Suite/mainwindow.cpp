#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load background image
    QPixmap backgroundImage("C:/Users/mriga/Downloads/TERMINAL SUITE 1.0 4.png");
    backgroundImage = backgroundImage.scaled(this->size(), Qt::KeepAspectRatioByExpanding);
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(backgroundImage);
    setCentralWidget(backgroundLabel);

    // Set common button styles
    QString buttonStyle = "QPushButton {"
                          "    display: inline-block;"
                          "    outline: 0;"
                          "    border: 0;"
                          "    background-color: #000000;"
                          "    cursor: pointer;"
                          "    border-radius: 8px;"
                          "    color: #fff;"
                          "    font-weight: 500;"
                          "    text-align: center;"
                          "    text-transform: uppercase;"
                          "    height: 45px;"  // Increased button height
                          "    line-height: 35px;"
                          "    padding: 0 12px;" // Increased padding
                          "    font-size: 14px;" // Slightly larger font size
                          "}"
                          "QPushButton:hover {"
                          "    background-color: #333333;"
                          "    transform: scale(1.1);"
                          "}";

    // Create buttons
    QPushButton *calculatorButton = new QPushButton("Calculator", this);
    QPushButton *converterButton = new QPushButton("To Do", this);
    QPushButton *gameButton = new QPushButton("Four Row", this);
    QPushButton *gameButton2 = new QPushButton("Slot Machine", this);
    QPushButton *alarmButton = new QPushButton("Alarm", this);
    QPushButton *cameraButton = new QPushButton("PayBuddy", this);
    QPushButton *musicButton = new QPushButton("Music", this);

    // Apply button styles
    calculatorButton->setStyleSheet(buttonStyle);
    converterButton->setStyleSheet(buttonStyle);
    gameButton->setStyleSheet(buttonStyle);
    gameButton2->setStyleSheet(buttonStyle);
    alarmButton->setStyleSheet(buttonStyle);
    cameraButton->setStyleSheet(buttonStyle);
    musicButton->setStyleSheet(buttonStyle);

    // Calculate button sizes and positions
    int buttonWidth = 220; // Increased button width
    int buttonHeight = 45; // Increased button height
    int margin = 20;
    int columnCount = 2;
    int rowCount = 3;
    int colSpacing = 20;
    int rowSpacing = 20;

    int xStartFirstColumn = width() / 6 - buttonWidth / 2 + 40; // Shifted right by 50 pixels
    int yStartFirstColumn = (height() - (buttonHeight * rowCount + rowSpacing * (rowCount - 1))) / 1.5;

    int xStartSecondColumn = 3 * width() / 6 - buttonWidth / 2 + 135; // Shifted right by 50 pixels
    int yStartSecondColumn = yStartFirstColumn;

    // Set button geometries
    musicButton->setGeometry(xStartFirstColumn, yStartFirstColumn, buttonWidth, buttonHeight);
    yStartFirstColumn += buttonHeight + rowSpacing;

    gameButton->setGeometry(xStartFirstColumn, yStartFirstColumn, buttonWidth, buttonHeight);
    yStartFirstColumn += buttonHeight + rowSpacing;

    gameButton2->setGeometry(xStartFirstColumn, yStartFirstColumn, buttonWidth, buttonHeight);
    yStartFirstColumn += buttonHeight + rowSpacing;

    calculatorButton->setGeometry(xStartSecondColumn, yStartSecondColumn, buttonWidth, buttonHeight);
    yStartSecondColumn += buttonHeight + rowSpacing;

    converterButton->setGeometry(xStartSecondColumn, yStartSecondColumn, buttonWidth, buttonHeight);
    yStartSecondColumn += buttonHeight + rowSpacing;

    alarmButton->setGeometry(xStartSecondColumn, yStartSecondColumn, buttonWidth, buttonHeight);
    yStartSecondColumn += buttonHeight + rowSpacing;

    cameraButton->setGeometry(xStartSecondColumn, yStartSecondColumn, buttonWidth, buttonHeight);
    yStartSecondColumn += buttonHeight + rowSpacing;

    // Adjusted position for time label
    currentTimeLabel = new QLabel(this);
    currentTimeLabel->setStyleSheet("color: white; font-size: 16px;");
    currentTimeLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    currentTimeLabel->setGeometry(width() - 270, 10, 190, 20); // Shifted right by 20 pixels

    //progress bar
    batteryProgressBar = new QProgressBar(this);
    batteryProgressBar->setOrientation(Qt::Horizontal);
    batteryProgressBar->setGeometry(10, 10, 200, 20);
    batteryProgressBar->setValue(100);

    //battery label
    batteryLabel = new QLabel(this);
    batteryLabel->setAlignment(Qt::AlignCenter);
    batteryLabel->setStyleSheet("color: #000000;");
    batteryLabel->setGeometry(70, 10, 50, 20); // Adjusted position

    // Initialize timer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    timer->start(1000);

    // Connect button clicks to slots
    connect(calculatorButton, &QPushButton::clicked, this, &MainWindow::on_CalculatorButton_clicked);
    connect(converterButton, &QPushButton::clicked, this, &MainWindow::on_ToDoButton_clicked);
    connect(gameButton, &QPushButton::clicked, this, &MainWindow::on_FourRowButton_clicked);
    connect(gameButton2, &QPushButton::clicked, this, &MainWindow::on_SlotMachineButton_clicked);
    connect(alarmButton, &QPushButton::clicked, this, &MainWindow::on_AlarmButton_clicked);
    connect(cameraButton, &QPushButton::clicked, this, &MainWindow::on_CameraButton_clicked);
    connect(musicButton, &QPushButton::clicked, this, &MainWindow::on_MusicButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CalculatorButton_clicked()
{
    decrementBattery();
    QString filePath = "C:\\Users\\mriga\\OneDrive\\Desktop\\Stuff\\QT_Integrated_Terminal_Suite\\Calculator\\Calculator.exe"; //path of Calculator
    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    if (!QDesktopServices::openUrl(fileUrl)) {
        qDebug() << "Failed to open file!";
    }
}

void MainWindow::on_ToDoButton_clicked()
{
    decrementBattery();
    QString filePath = "C:\\Users\\mriga\\OneDrive\\Desktop\\Stuff\\QT Terminal Suite - Semester 2\\ToDoList\\ToDoList.exe"; //path to ToDo
    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    if (!QDesktopServices::openUrl(fileUrl)) {
        qDebug() << "Failed to open file!";
    }
}

void MainWindow::on_FourRowButton_clicked()
{
    decrementBattery();
    QString filePath = "C:\\Users\\mriga\\OneDrive\\Desktop\\Stuff\\QT_Integrated_Terminal_Suite\\Game_01\\Game.exe"; //path to FourRow
    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    if (!QDesktopServices::openUrl(fileUrl)) {
        qDebug() << "Failed to open file!";
    }
}

void MainWindow::on_SlotMachineButton_clicked()
{
    decrementBattery();
    QString filePath = "C:\\Users\\mriga\\OneDrive\\Desktop\\Stuff\\QT_Integrated_Terminal_Suite\\Game_02\\Game_03.exe"; //path to SlotMachine
    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    if (!QDesktopServices::openUrl(fileUrl)) {
        qDebug() << "Failed to open file!";
    }
}

void MainWindow::on_AlarmButton_clicked()
{
    decrementBattery();
    QString filePath = "C:\\Users\\mriga\\OneDrive\\Desktop\\Stuff\\QT_Integrated_Terminal_Suite\\Alarm\\Alarm.exe"; //Update path to Alarm
    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    if (!QDesktopServices::openUrl(fileUrl)) {
        qDebug() << "Failed to open file!";
    }
}

void MainWindow::on_CameraButton_clicked()
{
    decrementBattery();
    QString filePath = "C:\\Users\\mriga\\OneDrive\\Desktop\\Stuff\\QT_Integrated_Terminal_Suite\\PayBuddy\\PayBuddy.exe"; //Update path to Camera
    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    if (!QDesktopServices::openUrl(fileUrl)) {
        qDebug() << "Failed to open file!";
    }
}

void MainWindow::on_MusicButton_clicked()
{
    decrementBattery();
    QString filePath = "C:\\Users\\mriga\\OneDrive\\Desktop\\Stuff\\QT_Integrated_Terminal_Suite\\MusicPlayer\\bin\\Debug\\AudioON.exe"; //Update path to Music
    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    if (!QDesktopServices::openUrl(fileUrl)) {
        qDebug() << "Failed to open file!";
    }
}

void MainWindow::decrementBattery()
{
    int currentValue = batteryProgressBar->value();
    if (currentValue >= 5) {
        batteryProgressBar->setValue(currentValue - 5);
        updateBatteryLabel(currentValue - 5);
        if (currentValue == 20) {
            QMessageBox::warning(this, "Battery Warning", "Battery is low! Please plug in your device.");
        } else if (currentValue == 0) {
            QMessageBox::information(this, "Battery Alert", "Battery is drained! Closing the application.");
            close(); // Close the application
        }
    } else {
        batteryProgressBar->setValue(0);
        updateBatteryLabel(0);
        close();

    }
}

void MainWindow::updateBatteryLabel(int value)
{
    batteryLabel->setText(QString("%1%").arg(value));
}

void MainWindow::updateTime()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentTime = currentDateTime.toString("hh:mm:ss");
    currentTimeLabel->setText(currentTime);
}
