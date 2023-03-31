#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
    Q_OBJECT
    bool isFirstInput = true, isFirstCalculation = true;
    double result = 0;
    int operatorValue = 0, operatorPriority[2], x;
    QString displayNum = "0", y;

    void removeZeros();
    void getNumber();
    void calculate(int tempOperatorValue, bool tempIsFirstInput);
    void writeLineEditNum();

    public:
        MainWindow(QWidget * parent = nullptr);
    ~MainWindow();

    private slots:
    void on_plus_buttn_clicked();

    void on_minus_buttn_clicked();

    void on_mult_buttn_clicked();

    void on_div_buttn_clicked();

    void on_one_clicked();

    void on_two_clicked();

    void on_three_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

    void on_zero_clicked();

    void on_clear_clicked();

    void on_equal_clicked();

    void on_backspace_clicked();

    private:
        Ui::MainWindow * ui;
};
#endif // MAINWINDOW_H
