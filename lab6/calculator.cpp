#include "calculator.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QStringList>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent) {

    this->operandInput = new QLineEdit(this);
    this->resultDisplay = new QLineEdit(this);
    this->resultDisplay->setReadOnly(true);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    layout->addWidget(operandInput);
    layout->addWidget(resultDisplay);
    setCentralWidget(centralWidget);

    this->createMenus();
    this->createToolBars();
}

Calculator::~Calculator() {}

void Calculator::createMenus() {
    QMenu *menu = menuBar()->addMenu(tr("&Operations"));

    QAction *addAction = new QAction(tr("&Add"), this);
    QAction *subtractAction = new QAction(tr("&Subtract"), this);
    QAction *multiplyAction = new QAction(tr("&Multiply"), this);
    QAction *divideAction = new QAction(tr("&Divide"), this);

    connect(addAction, &QAction::triggered, this, &Calculator::add);
    connect(subtractAction, &QAction::triggered, this, &Calculator::subtract);
    connect(multiplyAction, &QAction::triggered, this, &Calculator::multiply);
    connect(divideAction, &QAction::triggered, this, &Calculator::divide);

    menu->addAction(addAction);
    menu->addAction(subtractAction);
    menu->addAction(multiplyAction);
    menu->addAction(divideAction);
}

void Calculator::createToolBars() {
    QToolBar *toolbar = addToolBar(tr("Operations"));

    QAction *addAction = new QAction(tr("Add"), this);
    QAction *subtractAction = new QAction(tr("Subtract"), this);
    QAction *multiplyAction = new QAction(tr("Multiply"), this);
    QAction *divideAction = new QAction(tr("Divide"), this);

    connect(addAction, &QAction::triggered, this, &Calculator::add);
    connect(subtractAction, &QAction::triggered, this, &Calculator::subtract);
    connect(multiplyAction, &QAction::triggered, this, &Calculator::multiply);
    connect(divideAction, &QAction::triggered, this, &Calculator::divide);

    toolbar->addAction(addAction);
    toolbar->addAction(subtractAction);
    toolbar->addAction(multiplyAction);
    toolbar->addAction(divideAction);
}

double Calculator::getOperands(double &operandOne, double &operandTwo) {
    QString input = operandInput->text();
    QStringList operands = input.split(" ");

    if (operands.size() != 2) {
        QMessageBox::warning(this, tr("Input Error"), tr("Please enter two operands separated by a space."));
        return false;
    }

    bool isOperandOneValid, isOperandTwoValid;

    operandOne = operands[0].toDouble(&isOperandOneValid);
    operandTwo = operands[1].toDouble(&isOperandTwoValid);

    if (!isOperandOneValid || !isOperandTwoValid) {
        QMessageBox::warning(this, tr("Input Error"), tr("Invalid number format."));
        return false;
    }

    return true;
}

void Calculator::add() {
    double operandOne = 0, operandTwo = 0;

    if (!getOperands(operandOne, operandTwo)) {
        return;
    }

    double result = operandOne + operandTwo;
    resultDisplay->setText(QString::number(result));
}

void Calculator::subtract() {
    double operandOne = 0, operandTwo = 0;

    if (!getOperands(operandOne, operandTwo)) {
        return;
    }

    double result = operandOne - operandTwo;
    resultDisplay->setText(QString::number(result));
}

void Calculator::multiply() {
    double operandOne = 0, operandTwo = 0;

    if (!getOperands(operandOne, operandTwo)) {
        return;
    }

    double result = operandOne * operandTwo;
    resultDisplay->setText(QString::number(result));
}

void Calculator::divide() {
    double operandOne = 0, operandTwo = 0;

    if (!getOperands(operandOne, operandTwo)) {
        return;
    }

    if (operandTwo == 0) {
        QMessageBox::warning(this, tr("Math Error"), tr("Division by zero."));
        return;
    }

    double result = operandOne / operandTwo;
    resultDisplay->setText(QString::number(result));
}
