#include <QWidget>

#include <iostream>
#include "Component/MainWidget.hpp"
class CustomWindow : public QWidget {
  private:
    MainWidget &mainWidget;
  public:
    explicit CustomWindow(MainWidget &mainWidget);

  protected:
    void closeEvent(QCloseEvent *event);
};