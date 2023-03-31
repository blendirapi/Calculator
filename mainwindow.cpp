#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget * parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui -> setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::writeLineEditNum() {
    ui -> lineEdit -> setText(QString::number(result));
    displayNum = "";
}

void MainWindow::removeZeros() {
    while (displayNum.length() > 1 && displayNum[0] == '0') {
        displayNum.remove(0, 1);
    }
}

void MainWindow::getNumber() {
    displayNum = ui -> lineEdit -> text();
}

void MainWindow::calculate(int tempOperatorValue, bool tempIsFirstInput) {

    if (isFirstCalculation == true) {
        operatorPriority[0] = operatorValue;
    } else {
        operatorPriority[1] = operatorValue;
    }

    switch (operatorPriority[0]) {

        // this is for +
    case 1:
        if (isFirstInput == true) {
            result = displayNum.toInt();
        } else {
            result += displayNum.toInt();
        }
        isFirstInput = false;
        break;

        // this is for -
    case 2:
        if (isFirstInput == true) {
            result = displayNum.toInt();
        } else {
            result -= displayNum.toInt();
        }
        isFirstInput = false;
        break;

        // this is for *
    case 3:
        if (isFirstInput == true) {
            result = displayNum.toInt();
        } else {
            result *= displayNum.toInt();
        }
        isFirstInput = false;
        break;

        // this is for /
    case 4:
        if (isFirstInput == true) {
            result = displayNum.toInt();
        } else {
            result /= displayNum.toInt();
        }
        isFirstInput = false;
        break;

    default:
        break;

    }

    if (isFirstCalculation == false) {
        operatorPriority[0] = operatorPriority[1];
    }

    isFirstCalculation = false;
}

void MainWindow::on_plus_buttn_clicked() {
    getNumber();
    x = displayNum.length();
    y = displayNum[x];

    if (y == "+") {
        displayNum.chop(1);
    }
    ui->lineEdit -> setText(ui -> lineEdit -> text() + "+");

//    if (displayNum[x] == "+"
//       || displayNum[x] == "-"
//       || displayNum[x] == "*"
//       || displayNum[x] == "/") {

//        displayNum[x] = "+";
//        ui -> lineEdit -> setText(QString::number(displayNum));
//    } else { ui->lineEdit->setText(ui->lineEdit->text()+ "+");}
}

void MainWindow::on_minus_buttn_clicked() {
    getNumber();
    operatorValue = 2;
    calculate(operatorValue, isFirstInput);
    writeLineEditNum();
}

void MainWindow::on_mult_buttn_clicked() {
    getNumber();
    operatorValue = 3;
    calculate(operatorValue, isFirstInput);
    writeLineEditNum();
}

void MainWindow::on_div_buttn_clicked() {
    getNumber();
    operatorValue = 4;
    calculate(operatorValue, isFirstInput);
    writeLineEditNum();
}

void MainWindow::on_one_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text()+ "1");
}

void MainWindow::on_two_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text()+ "2");
}

void MainWindow::on_three_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text()+ "3");
}

void MainWindow::on_four_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text()+ "4");
}

void MainWindow::on_five_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text()+ "5");
}

void MainWindow::on_six_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text()+ "6");
}

void MainWindow::on_seven_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text()+ "7");
}

void MainWindow::on_eight_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text()+ "8");
}

void MainWindow::on_nine_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text()+ "9");
}

void MainWindow::on_zero_clicked() {
    ui->lineEdit->setText(ui->lineEdit->text()+ "0");
}

void MainWindow::on_clear_clicked() {
    operatorValue = 0;
    result = 0;
    displayNum = "";
    isFirstInput = true;
    isFirstCalculation == true;
    ui -> lineEdit -> setText("0");
}

void MainWindow::on_equal_clicked() {
    isFirstCalculation == true;
    calculate(operatorValue, isFirstInput);
    operatorPriority[0] = 0;
    operatorPriority[1] = 0;
    ui -> lineEdit -> setText(QString::number(result));
}

void MainWindow::on_backspace_clicked() {
    if (displayNum == "" || displayNum == "0") {
        displayNum = "0";
        ui -> lineEdit -> setText(displayNum);
    } else {
        getNumber();
        displayNum.chop(1);
        ui -> lineEdit -> setText(displayNum);
    }
}
