#include "StartButton.hpp"

/**
 * StartButton constructor
 * @param Timer reference to timer object
 * @param QLineEdit reference to fix time input of MainWidget
 * @param QLineEdit reference to random time input of MainWidget
 */
StartButton::StartButton(Timer &kushamiTimer, QLineEdit &fixTimeInput, QLineEdit &randomTimeInput) : kushamiTimer(kushamiTimer),fixTime(fixTimeInput), randomTime(randomTimeInput) {
    startBtn.setText("開始");
    startBtn.setCursor(Qt::PointingHandCursor);
    startBtn.setStyleSheet("padding: 5px 5px;font-size: 18px; margin-top:10px;");
    QObject::connect(&startBtn, &QPushButton::clicked,std::bind(&StartButton::btnPressed, this));
}

/**
 * Return a reference to StartButton
 * @return StartButton&
 */
QPushButton &StartButton::getWidget() {
    return startBtn;
}

/**
 * Function to handle the button press event
 */
void StartButton::btnPressed() {
    if (!kushamiTimer.isStarted()) {
        startBtn.setText("終了");
        kushamiTimer.startTimer(getInput(fixTime, 1), getInput(randomTime, 0));
    } else {
        startBtn.setText("開始");
        kushamiTimer.stopTimer();
    }
}

/**
 * Parse input from user and use min value if use input is empty
 * @param QLineEdit& input
 * @param int minValue
 * @return int parsed result
 */
int StartButton::getInput(QLineEdit &input, int minValue) {
    if (input.text().isEmpty()) {
        return minValue;
    }
    int inputValue = input.text().toInt(nullptr,10);
    return inputValue <= minValue ? minValue : inputValue;
}