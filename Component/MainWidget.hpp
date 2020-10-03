#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include "KushamiFunc/Timer.hpp"
#include "StartButton.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>

class MainWidget {
  private:
    //Gtk::Box mainBox, settingBox, verticalBox, fixTimeBox, randomTimeBox;
    //Gtk::Label name, plusMinus, fixTimeLabel, randomTimeLabel;
    //NumEntry fixTimeInput;
    //NumEntry randomTimeInput;
    Timer kushamiTimer;
    StartButton startBtn;

    ////
    QWidget topWidget, settingWidget;
    QVBoxLayout mainBox, settingBox, verticalBox;
    QHBoxLayout fixTimeBox, randomTimeBox;
    QLabel name, plusMinus, fixTimeLabel, randomTimeLabel;
    QLineEdit fixTimeInput, randomTimeInput;

  public:
    MainWidget();
    void stopAll();
    QWidget &getWidget();
};

#endif