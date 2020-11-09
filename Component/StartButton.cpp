#include "StartButton.hpp"

StartButton::StartButton(Timer &kushamiTimer, QLineEdit &fixTimeInput, QLineEdit &randomTimeInput) : kushamiTimer(kushamiTimer),fixTime(fixTimeInput), randomTime(randomTimeInput) {
    startBtn.setText("開始");
    startBtn.setCursor(Qt::PointingHandCursor);
    startBtn.setStyleSheet("padding: 5px 5px;font-size: 18px; margin-top:10px;");
    QObject::connect(&startBtn, &QPushButton::clicked,std::bind(&StartButton::btnPressed, this));
}

QPushButton &StartButton::getWidget() {
    return startBtn;
}

void StartButton::btnPressed() {
    if (!kushamiTimer.isStarted()) {
        startBtn.setText("終了");
        kushamiTimer.startTimer(getInput(fixTime, 1), getInput(randomTime, 0));
    } else {
        startBtn.setText("開始");
        kushamiTimer.stopTimer();
    }
}

int StartButton::getInput(QLineEdit &input, int minValue) {
    if (input.text().isEmpty()) {
        return minValue;
    }
    int inputValue = input.text().toInt(nullptr,10);
    return inputValue <= minValue ? minValue : inputValue;
}