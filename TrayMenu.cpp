#include "TrayMenu.hpp"

/**
 * Custom Tray menu constructor
 */
TrayMenu::TrayMenu(QWidget &window) : refFrame(window) {
    // Setup Tray
    kushamiTray.setToolTip("ユメノくしゃみ");
    // Attach the activated signal emit by QSystemTrayIcon to showWindow callback
    QObject::connect(&kushamiTray, &QSystemTrayIcon::activated, std::bind(&TrayMenu::showWindow, this, std::placeholders::_1));
}

/**
 * Set the icon of tray menu
 * @param QIcon&
 */
void TrayMenu::setIcon(QIcon &icon) {
    kushamiTray.setIcon(icon);
    kushamiTray.show();
}

/**
 * Callback function triggeren by &QSystemTrayIcon::activated. Manipulate the activate reason
 * @param QSystemTrayIcon::ActivationReason
 */
void TrayMenu::showWindow(QSystemTrayIcon::ActivationReason reason) {
    if (reason == QSystemTrayIcon::Trigger) {
        if (!refFrame.isVisible()) {
            refFrame.setVisible(true);
            refFrame.showNormal();
        }
    }
}