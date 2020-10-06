#include "MainFrame.hpp"

MainFrame::MainFrame() : window(mainWidget) ,kushamiTray(window) {
    window.setWindowTitle("Shiori Kushami Generator");
    mainBox.setAlignment(Qt::AlignCenter);
    // Setup icon list to main window
	// ok
    setupIconList();
    window.setWindowIcon(iconList);
    kushamiTray.setIcon(iconList);
    // Set Header Img
    kushamiPix.load(":/img/shiori_header.png");
    kushamiImg.setPixmap(kushamiPix.scaledToWidth((int)(kushamiPix.width() * 0.50), Qt::SmoothTransformation));

    // Add Widget
    mainBox.addWidget(&kushamiImg);
    mainWidget.getWidget().setFixedSize(kushamiImg.sizeHint().width(), mainWidget.getWidget().sizeHint().height());
    mainBox.addWidget(&mainWidget.getWidget());

    window.setLayout(&mainBox);
    // Show the Main Window after all call is done
    window.show();
}

void MainFrame::setupIconList() {
    // Load resources from glib compiled resource and puch into vector
    iconList.addFile(":/img/icon/shiori_icon_16.png");
    iconList.addFile(":/img/icon/shiori_icon_32.png");
    iconList.addFile(":/img/icon/shiori_icon_64.png");
    iconList.addFile(":/img/icon/shiori_icon_128.png");
    iconList.addFile(":/img/icon/shiori_icon_256.png");
    iconList.addFile(":/img/icon/shiori_icon_512.png");
}