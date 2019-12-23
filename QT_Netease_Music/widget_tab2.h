#ifndef TAB2_H
#define TAB2_H

#include <QWidget>

namespace Ui {
class widget_tab2;
}

class WidgetTab2 : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetTab2(QWidget *parent = nullptr);
    ~WidgetTab2();

private:
    Ui::widget_tab2 *ui;
};

#endif // TAB2_H
