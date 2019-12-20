#include "widget_tab1.h"
#include "ui_widget_tab1.h"

#include "gallery_item.h"

WidgetTab1::WidgetTab1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_tab1)
{
    ui->setupUi(this);

    ui->comboBox->addItem("country");
    ui->comboBox->addItem("popular");

    for (int i = 0; i < 6; ++i) {
        gallery_item_widget* galleryItem1 = new gallery_item_widget(this);
        ui->gridLayout->addWidget(galleryItem1, i / 3, i % 3);
    }

}

WidgetTab1::~WidgetTab1()
{
    delete ui;
}
