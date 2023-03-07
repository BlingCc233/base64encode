#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    // 声明构造函数和析构函数
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void encrypt();
    void decrypt();

private:
    QTextEdit *inputEdit;
    QTextEdit *outputEdit;
    QPushButton *encryptButton;
    QPushButton *decryptButton;
    QLabel *inputLabel;
    QLabel *outputLabel;
};

#endif // MAINWINDOW_H
