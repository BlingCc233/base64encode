#include "mainwindow.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QByteArray>

// 实现构造函数
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // 创建文本编辑框
    inputEdit = new QTextEdit;
    outputEdit = new QTextEdit;
    inputEdit->setPlaceholderText("请输入原文");
    outputEdit->setPlaceholderText("输出加密内容或解密内容");
    outputEdit->setReadOnly(true);

    // 创建按钮
    encryptButton = new QPushButton("加密内容");
    decryptButton = new QPushButton("解密内容");

    // 创建标签
    inputLabel = new QLabel("原文");
    outputLabel = new QLabel("加密/解密");

    // 创建布局
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(encryptButton);
    buttonLayout->addWidget(decryptButton);

    QVBoxLayout *inputLayout = new QVBoxLayout;
    inputLayout->addWidget(inputLabel);
    inputLayout->addWidget(inputEdit);

    QVBoxLayout *outputLayout = new QVBoxLayout;
    outputLayout->addWidget(outputLabel);
    outputLayout->addWidget(outputEdit);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(outputLayout);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(mainLayout);
    layout->addLayout(buttonLayout);

    // 创建中心窗口
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // 连接信号和槽
    connect(encryptButton, &QPushButton::clicked, this, &MainWindow::encrypt);
    connect(decryptButton, &QPushButton::clicked, this, &MainWindow::decrypt);
}

// 实现析构函数
MainWindow::~MainWindow()
{
    // 释放内存
    delete inputEdit;
    delete outputEdit;
    delete encryptButton;
    delete decryptButton;
    delete inputLabel;
    delete outputLabel;
}

// 实现加密槽函数
void MainWindow::encrypt()
{
    // 获取原文
    QString input = inputEdit->toPlainText();
    // 判断是否为空
    if (input.isEmpty())
    {
        QMessageBox::warning(this, "警告", "原文不能为空");
        return;
    }
    // 转换为字节数组
    QByteArray inputBytes = input.toUtf8();
    // 使用base64编码
    QByteArray outputBytes = inputBytes.toBase64();
    // 转换为字符串
    QString output = QString::fromUtf8(outputBytes);
    // 显示输出
    outputEdit->setText(output);
}

// 实现解密槽函数
void MainWindow::decrypt()
{
    // 获取原文
    QString input = inputEdit->toPlainText();
    // 判断是否为空
    if (input.isEmpty())
    {
        QMessageBox::warning(this, "警告", "原文不能为空");
        return;
    }
    // 转换为字节数组
    QByteArray inputBytes = input.toUtf8();
    // 使用base64解码
    QByteArray outputBytes = QByteArray::fromBase64(inputBytes);
    // 转换为字符串
    QString output = QString::fromUtf8(outputBytes);
    // 显示输出
    outputEdit->setText(output);
}
