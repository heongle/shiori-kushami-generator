#include <QPixmap>
#include <QLabel>
#include <QIcon>
#include <QVBoxLayout>
#include <QSystemTrayIcon>
#include <vector>

#include "Component/MainWidget.hpp"
#include "TrayMenu.hpp"
//Header
class MainFrame {
  private:
    QWidget window;
    MainWidget mainWidget;

    QVBoxLayout mainBox;
    QPixmap kushamiPix;
    QLabel kushamiImg;
    QIcon iconList;

    TrayMenu kushamiTray;

  public:
    MainFrame();
    int keepAlive();

  private:
    void setupIconList();
};