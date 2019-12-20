#include "gallery_item.h"
#include "ui_gallery_item.h"

#include <QImageReader>
#include <QMessageBox>
#include <QDir>

gallery_item_widget::gallery_item_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gallery_item)
{
    ui->setupUi(this);

    //loadfile("D:\\Dev-Study\\QT_Netease_Music\\QT_Netease_Music\\Resources\\Logo.png");
    loadfile("../QT_Netease_Music/Resources/Logo.png");
}

gallery_item_widget::~gallery_item_widget()
{
    delete ui;
}

bool gallery_item_widget::loadfile(const QString& fileName)
{
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
    }
    setImage(newImage);

    return true;
}

void gallery_item_widget::setImage(const QImage &newImage)
{
    ui->label->setPixmap(QPixmap::fromImage(newImage));
}
