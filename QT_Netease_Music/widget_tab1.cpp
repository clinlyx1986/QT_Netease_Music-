#include "widget_tab1.h"
#include "ui_widget_tab1.h"

WidgetTab1::WidgetTab1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_tab1)
{
    ui->setupUi(this);

    ui->comboBox->addItem("country");
    ui->comboBox->addItem("popular");
}

WidgetTab1::~WidgetTab1()
{
    delete ui;
}
