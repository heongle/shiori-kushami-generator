#include "CustomWidget.h"

void CustomWidget::hideEvent(QHideEvent *event) {
    if(isVisible()) {
        setVisible(false);
    }
    QWidget::hideEvent(event);
}