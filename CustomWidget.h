#include <QWidget>

/**
 * Custom Widget class used by MainFrame
 */
class CustomWidget : public QWidget {
    public:
    void hideEvent(QHideEvent *event);
};