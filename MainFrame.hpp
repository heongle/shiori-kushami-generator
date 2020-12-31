#include <QPixmap>
#include <QLabel>
#include <QIcon>
#include <QVBoxLayout>
#include <QSystemTrayIcon>
#include <vector>

#include "CustomWidget.h"
#include "Component/MainWidget.hpp"
#include "TrayMenu.hpp"

//Header
class MainFrame {
  private:
    CustomWidget window;
    MainWidget mainWidget;

    QVBoxLayout mainBox;
    QPixmap kushamiPix;
    QLabel kushamiImg;
    QIcon iconList;

    TrayMenu kushamiTray;

  public:
    MainFrame();

  private:
    void setupIconList();
};