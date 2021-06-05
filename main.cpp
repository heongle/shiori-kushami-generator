#include <QApplication>
#include "MainFrame.hpp"

/*
* Program entry point
*/
int main(int argc, char *argv[]) {
    QApplication kushamiApp(argc, argv);
    kushamiApp.setStyleSheet("*{font-family:\"ヒラギノ角ゴ Pro W3\", \"Hiragino Kaku Gothic Pro\",Osaka, \"メイリオ\", Meiryo, \"ＭＳ Ｐゴシック\", \"MS PGothic\", sans-serif;}");
    MainFrame MF;
    return kushamiApp.exec();
}
