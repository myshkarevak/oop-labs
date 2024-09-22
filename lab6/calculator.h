#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QLineEdit>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>

class Calculator : public QMainWindow {
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void add();
    void subtract();
    void multiply();
    void divide();

private:
    QLineEdit *operandInput;
    QLineEdit *resultDisplay;

    void createMenus();
    void createToolBars();
    double getOperands(double &operandOne, double &operandTwo);
};

#endif
