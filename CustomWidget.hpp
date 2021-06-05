#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H
#include <QWidget>

/**
 * Custom Widget class used by MainFrame
 */
class CustomWidget : public QWidget {
    public:
    void hideEvent(QHideEvent *event);
};


#endif /* CUSTOMWIDGET_H */
