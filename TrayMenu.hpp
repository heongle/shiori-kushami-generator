#include <QWidget>
#include <QIcon>
#include <QSystemTrayIcon>
#include <iostream>
#include <functional>

class TrayMenu {
  private:
    QWidget &refFrame;
    QSystemTrayIcon kushamiTray;

  public:
    explicit TrayMenu(QWidget &window);
    void setIcon(QIcon &icon);
  
  private:
    void showWindow(QSystemTrayIcon::ActivationReason reason);
};
