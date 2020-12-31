#include "TrayMenu.hpp"

TrayMenu::TrayMenu(QWidget &window) : refFrame(window) {
    // Setup Tray
    kushamiTray.setToolTip("ユメノくしゃみ");
    QObject::connect(&kushamiTray, &QSystemTrayIcon::activated, std::bind(&TrayMenu::showWindow, this, std::placeholders::_1));
}

void TrayMenu::setIcon(QIcon &icon) {
    kushamiTray.setIcon(icon);
    kushamiTray.show();
}

void TrayMenu::showWindow(QSystemTrayIcon::ActivationReason reason) {
    if (reason == QSystemTrayIcon::Trigger) {
        if (!refFrame.isVisible()) {
            refFrame.setVisible(true);
            refFrame.showNormal();
        }
    }
}