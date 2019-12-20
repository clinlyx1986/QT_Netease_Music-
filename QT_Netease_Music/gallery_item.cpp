#include "gallery_item.h"
#include "ui_gallery_item.h"

gallery_item_widget::gallery_item_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gallery_item)
{
    ui->setupUi(this);
}

gallery_item_widget::~gallery_item_widget()
{
    delete ui;
}
