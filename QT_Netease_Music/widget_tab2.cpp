#include "widget_tab2.h"
#include "ui_tab2.h"
#include "gallery_item.h"

WidgetTab2::WidgetTab2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tab2)
{
    ui->setupUi(this);

    for (int i = 0; i < 6; ++i) {
        gallery_item_widget* galleryItem1 = new gallery_item_widget(this);
        ui->gridLayout->addWidget(galleryItem1, i / 3, i % 3);
    }
}

WidgetTab2::~WidgetTab2()
{
    delete ui;
}
