#ifndef WIDGET_TAB1_H
#define WIDGET_TAB1_H

#include <QWidget>

namespace Ui {
class widget_tab1;
}

class WidgetTab1 : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetTab1(QWidget *parent = nullptr);
    ~WidgetTab1();

private:
    Ui::widget_tab1 *ui;
};

#endif // WIDGET_TAB1_H
