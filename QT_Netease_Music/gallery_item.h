#ifndef GALLERY_ITEM_H
#define GALLERY_ITEM_H

#include <QWidget>

namespace Ui {
class gallery_item;
}

class gallery_item_widget : public QWidget
{
    Q_OBJECT

public:
    explicit gallery_item_widget(QWidget *parent = nullptr);
    ~gallery_item_widget();

    bool loadfile(const QString& fileName);
    void setImage(const QImage &newImage);
private:
    Ui::gallery_item *ui;
};

#endif // GALLERY_ITEM_H
