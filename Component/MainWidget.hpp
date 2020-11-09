#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include "KushamiFunc/Timer.hpp"
#include "StartButton.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QIntValidator>

class MainWidget {
  private:
    Timer kushamiTimer;
    QWidget topWidget, settingWidget;
    QVBoxLayout mainBox, settingBox, verticalBox;
    QHBoxLayout fixTimeBox, randomTimeBox;
    QLabel name, plusMinus, fixTimeLabel, randomTimeLabel;
    QLineEdit fixTimeInput, randomTimeInput;

    StartButton startBtn;

  public:
    MainWidget();
    ~MainWidget();
    QWidget &getWidget();

  private:
    void stopAll();
};

#endif