#include "widget_tab2.h"
#include "ui_tab2.h"

WidgetTab2::WidgetTab2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab2)
{
    ui->setupUi(this);
}

WidgetTab2::~WidgetTab2()
{
    delete ui;
}
