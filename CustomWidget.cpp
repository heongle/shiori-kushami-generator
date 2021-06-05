#include "CustomWidget.hpp"

/**
 * Override the hideEvent function to toggle window visible state
 * @param QHideEvent event
 */
void CustomWidget::hideEvent(QHideEvent *event) {
    if(isVisible()) {
        setVisible(false);
    }
    QWidget::hideEvent(event);
}
