#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include <QMenuBar>

#include <QtDebug>
#include <QAction>

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 标题栏文本
    setWindowTitle(tr("Main Window"));

    // 菜单栏
    QMenuBar* mBar = menuBar();

    //添加菜单1
    QMenu* pFile = mBar->addMenu("File");
    pFile->addAction("New",  this, &MainWindow::newProject);
    pFile->addAction("Open", this, &MainWindow::openProject);
    // 添加分割线
    pFile->addSeparator();
    pFile->addAction("Quit", this, &QWidget::close);

    //添加菜单2
    QMenu* pHelp   = mBar->addMenu("Help");
    pHelp->addAction("About", this, &MainWindow::aboutDialog);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newProject()
{
    QMessageBox::information(this, "warning", "newProject");
}

void MainWindow::openProject()
{
    QMessageBox::warning(this, "warning", "openProject");
}

void MainWindow::aboutDialog()
{
    static const char message[] = "<p><b>Qt Main Window Example</b></p>";
    QMessageBox::about(this, tr("About MainWindows"), message);
}
