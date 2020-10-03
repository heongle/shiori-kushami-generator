#include "CustomWindow.hpp"

CustomWindow::CustomWindow(MainWidget &mainWidget): mainWidget(mainWidget){}

void CustomWindow::closeEvent(QCloseEvent *event) {
    mainWidget.stopAll();
    QWidget::closeEvent(event);
}