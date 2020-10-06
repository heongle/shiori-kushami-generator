#include <QPixmap>
#include <QLabel>
#include <QIcon>
#include <QVBoxLayout>
#include <QSystemTrayIcon>
#include <vector>

#include "Component/MainWidget.hpp"
#include "Component/StartButton.hpp"
#include "CustomWindow.hpp"
#include "TrayMenu.hpp"
//Header
class MainFrame {
  private:
    QVBoxLayout mainBox;
    QPixmap kushamiPix;
    QLabel kushamiImg;
    QIcon iconList;

    MainWidget mainWidget;
    CustomWindow window;
    TrayMenu kushamiTray;

  public:
    MainFrame();
    int keepAlive();

  private:
    //void setMargin(Gtk::Box &box, int pixel);
    //void setupCSS();
    void setupIconList();
};