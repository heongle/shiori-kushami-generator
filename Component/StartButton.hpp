#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include "KushamiFunc/Timer.hpp"
#include <functional>
#include <QPushButton>
#include <QLineEdit>
class StartButton {
  private:
    Timer &kushamiTimer;
    QLineEdit &fixTime, &randomTime;
    QPushButton startBtn;
    
  public:
    StartButton(Timer &pTimer, QLineEdit &fixTimeInput, QLineEdit &randomTimeInput);
    QPushButton &getWidget();

  private:
    void btnPressed();
    int getInput(QLineEdit &input, int minValue);
};

#endif /* STARTBUTTON_H */
