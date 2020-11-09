#include "MainWidget.hpp"

MainWidget::MainWidget() : startBtn(kushamiTimer, fixTimeInput, randomTimeInput) {
    verticalBox.setMargin(0);
    settingBox.setMargin(0);
    mainBox.setMargin(0);
    name.setText("くしゃみする間隔");
    name.setStyleSheet("font-size: 20px; margin: 0px 0px 5px 0px;");
    name.setAlignment(Qt::AlignCenter);

    fixTimeLabel.setText("分間（固定）");
    fixTimeLabel.setStyleSheet("font-size: 14px;");
    fixTimeInput.setMaxLength(3);
    fixTimeInput.setValidator(new QIntValidator( 0, 999, &topWidget));
    fixTimeInput.setAlignment(Qt::AlignRight);
    fixTimeInput.setFixedSize(fixTimeInput.minimumSizeHint().width(), fixTimeLabel.sizeHint().height());

    randomTimeLabel.setText("分間（ランダム）");
    randomTimeLabel.setStyleSheet("font-size: 14px;");
    randomTimeInput.setMaxLength(3);
    randomTimeInput.setAlignment(Qt::AlignRight);
    randomTimeInput.setFixedSize(randomTimeInput.minimumSizeHint().width(), fixTimeLabel.sizeHint().height());
    randomTimeInput.setValidator(new QIntValidator( 0, 999, &topWidget));

    plusMinus.setText("+/-");
    plusMinus.setStyleSheet("font-family: arial,helvetica; font-size: 38px; margin: 15px 0px 15px 0px;");
    plusMinus.setAlignment(Qt::AlignCenter);

    verticalBox.addWidget(&name);
    fixTimeBox.addWidget(&fixTimeInput);
    fixTimeBox.addWidget(&fixTimeLabel);
    verticalBox.addLayout(&fixTimeBox);

    verticalBox.addWidget(&plusMinus);

    randomTimeBox.addWidget(&randomTimeInput);
    randomTimeBox.addWidget(&randomTimeLabel);
    verticalBox.addLayout(&randomTimeBox);

    settingWidget.setLayout(&verticalBox);
    settingWidget.setFixedSize(settingWidget.sizeHint().width(), settingWidget.sizeHint().height());

    settingBox.addWidget(&settingWidget);
    settingBox.setAlignment(Qt::AlignCenter);

    mainBox.addLayout(&settingBox);
    mainBox.addWidget(&startBtn.getWidget());

    topWidget.setLayout(&mainBox);
}

MainWidget::~MainWidget() {
    stopAll();
}

QWidget &MainWidget::getWidget() {
    return topWidget;
}

void MainWidget::stopAll() {
    if (kushamiTimer.isStarted()) {
        kushamiTimer.stopTimer();
    } else {
        std::cout << "kushamiTimer not running\n";
    }
}