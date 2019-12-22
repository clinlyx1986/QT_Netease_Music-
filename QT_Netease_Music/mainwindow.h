#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class TurntableWidget;
class SongListFrame;
class BottomWidget;
class SkinWidget;
class TitleBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void newProject();
    void openProject();
    void aboutDialog();
    void toolBtnDialog();

    void slot_showTurnTableWidget();
    void slot_hideTurnTableWidget();
    void slot_showSongListWidget();
    void slot_showSkinWidget();
private:
    Ui::MainWindow *ui;
    QWidget* m_turnTableLayoutWidget;
    TurntableWidget* m_turntableWidget;
    SongListFrame* m_SongListFrame;
    BottomWidget* bottomPlayWidget;
    SkinWidget* m_skinWidget;
    TitleBar* m_TitleBar;
};
#endif // MAINWINDOW_H
