#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("简易进制转换器");
    connect(ui->lineEdit_10, SIGNAL(editingFinished()), this, SLOT(on_pushButton_clicked()));
    connect(ui->lineEdit_2, SIGNAL(editingFinished()), this, SLOT(on_pushButton_2_clicked()));
    connect(ui->lineEdit_8, SIGNAL(editingFinished()), this, SLOT(on_pushButton_3_clicked()));
    connect(ui->lineEdit_16, SIGNAL(editingFinished()), this, SLOT(on_pushButton_4_clicked()));


    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::on_pushButton_clicked);   //10
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::on_pushButton_2_clicked); //2
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::on_pushButton_3_clicked); //8
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::on_pushButton_4_clicked); //16

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{

    // 获取lineEdit_10中的输入值
    QString inputText = ui->lineEdit_10->text();

    // 检查输入是否为空
    if (inputText.isEmpty()) {
        QMessageBox::warning(this, "警告", "输入不能为空！");
        return;
    }

    bool ok;
    // 将输入的字符串转换为unsigned int
    unsigned int decimalNumber = inputText.toUInt(&ok);

    // 检查转换是否成功
    if (!ok) {
        QMessageBox::warning(this, "警告", "请输入有效的十进制数！");
        return;
    }

    // 十进制转二进制
    QString binaryStr = QString::number(decimalNumber, 2);
    ui->lineEdit_2->setText(binaryStr);

    // 十进制转八进制
    QString octalStr = QString::number(decimalNumber, 8);
    ui->lineEdit_8->setText(octalStr);

    // 十进制转十六进制
    QString hexStr = QString::number(decimalNumber, 16).toUpper();
    ui->lineEdit_16->setText(hexStr);
    }




void Widget::on_pushButton_2_clicked()
{
        // 获取lineEdit_2中的输入值
        QString inputText = ui->lineEdit_2->text();

        // 检查输入是否为空
        if (inputText.isEmpty()) {
            QMessageBox::warning(this, "警告", "输入不能为空！");
            return;
        }

        // 二进制字符串转换为整数，注意使用基数2
        bool ok;
        unsigned int decimalNumber = inputText.toUInt(&ok, 2);

        // 检查
        if (!ok) {
            QMessageBox::warning(this, "警告", "请输入有效的二进制数！");
            return;
        }

        // 二转八
        QString binaryStr = QString::number(decimalNumber, 8);
        ui->lineEdit_8->setText(binaryStr);

        // 二转十
        QString decimalStr = QString::number(decimalNumber);
        ui->lineEdit_10->setText(decimalStr); // 假设lineEdit_10用于显示十进制结果

        // 二转十六
        QString hexStr = QString::number(decimalNumber, 16).toUpper();
        ui->lineEdit_16->setText(hexStr);
}

void Widget::on_pushButton_3_clicked()
{
        // 获取lineEdit_8中的输入值，假定这是八进制输入
        QString inputText = ui->lineEdit_8->text();

        // 检查输入是否为空
        if (inputText.isEmpty()) {
            QMessageBox::warning(this, "警告", "输入不能为空！");
            return;
        }

        // 八进制字符串转换为整数，注意使用基数8
        bool ok;
        unsigned int decimalNumber = inputText.toUInt(&ok, 8);

        // 检查
        if (!ok) {
            QMessageBox::warning(this, "警告", "请输入有效的八进制数！");
            return;
        }

        // 八转二
        QString binaryStr = QString::number(decimalNumber, 2);
        ui->lineEdit_2->setText(binaryStr);

        // 八转十
        QString decimalStr = QString::number(decimalNumber);
        ui->lineEdit_10->setText(decimalStr); // 假设lineEdit_10用于显示十进制结果

        // 八转十六
        QString hexStr = QString::number(decimalNumber, 16).toUpper();
        ui->lineEdit_16->setText(hexStr);

}

void Widget::on_pushButton_4_clicked()
{
    // 获取lineEdit_16中的输入值，假定这是八进制输入
    QString inputText = ui->lineEdit_16->text();

    // 检查输入是否为空
    if (inputText.isEmpty()) {
        QMessageBox::warning(this, "警告", "输入不能为空！");
        return;
    }

    // 十六进制字符串转换为整数，注意使用基数16
    bool ok;
    unsigned int decimalNumber = inputText.toUInt(&ok, 16);

    // 检查
    if (!ok) {
        QMessageBox::warning(this, "警告", "请输入有效的十六进制数！");
        return;
    }

    // 十六转二
    QString binaryStr = QString::number(decimalNumber, 2);
    ui->lineEdit_2->setText(binaryStr);

    // 十六转十
    QString decimalStr = QString::number(decimalNumber);
    ui->lineEdit_10->setText(decimalStr); // 假设lineEdit_10用于显示十进制结果

    // 十六转八
    QString hexStr = QString::number(decimalNumber, 8).toUpper();
    ui->lineEdit_8->setText(hexStr);

}
