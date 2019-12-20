#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include <QMenuBar>

#include <QToolBar>
#include <QStatusBar>

#include <QDockWidget>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QTreeWidget>
#include <QTreeWidgetItem>

#include <QTabWidget>
#include <QComboBox>
#include <QGridLayout>

#include <QtDebug>
#include <QAction>

#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>

#include "widget_tab2.h"

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
    QAction* pNew  = pFile->addAction("New",  this, &MainWindow::newProject);
    QAction* pOPen = pFile->addAction("Open", this, &MainWindow::openProject);
    // 添加分割线
    pFile->addSeparator();
    pFile->addAction("Quit", this, &QWidget::close);

    //添加菜单2
    QMenu* pHelp   = mBar->addMenu("Help");
    pHelp->addAction("About", this, &MainWindow::aboutDialog);

    // 工具栏
    QToolBar* toolBar = addToolBar("toolbar");
    // 工具栏中，添加菜单
    toolBar->addAction(pNew);
    toolBar->addAction(pOPen);
    // 工具栏上，添加button
    QPushButton* tool_btn = new QPushButton(this);
    tool_btn->setText("tool_btn");
    toolBar->addWidget(tool_btn);
    this->connect(tool_btn, &QPushButton::clicked, this, &MainWindow::toolBtnDialog);

    // 状态栏
    QStatusBar* sBar = statusBar();
    QLabel *status_label1 = new QLabel(this);
    status_label1->setText("part 1");
    sBar->addWidget(status_label1);
    //addWidget从左往右添加
    QLabel *status_label2 = new QLabel(this);
    status_label2->setText("part 2");
    sBar->addWidget(status_label2);
    //addpermanentwidget从右往左添加
    QLabel *status_label3 = new QLabel(this);
    status_label3->setText("part 3");
    sBar->addPermanentWidget(status_label3);

//    // 浮动窗口----暂时关闭右侧的浮动窗口
//    QDockWidget* dock = new QDockWidget("dock1", this);
//    addDockWidget(Qt::RightDockWidgetArea, dock);
//    // 浮动窗口，添加各种控件
//    QTextEdit* dock_edit = new QTextEdit(this);
//    dock->setWidget(dock_edit);

//    QDockWidget* dock2 = new QDockWidget("dock2", this);
//    addDockWidget(Qt::BottomDockWidgetArea, dock2);
//    // 浮动窗口，添加各种控件
//    QTextEdit* dock_edit2 = new QTextEdit(this);
//    dock2->setWidget(dock_edit2);

    // 将客户区域，简单的拆分为2行，共3个区域
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    QHBoxLayout* hLayout = new QHBoxLayout(this);

    // TreeWidget控件
    QTreeWidget* treeWidget = new QTreeWidget(this);
    //第一组
    QTreeWidgetItem *group1=new QTreeWidgetItem();
    group1->setText(0,"group1");
    group1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    group1->setCheckState(0,Qt::Unchecked);
    QTreeWidgetItem *item11=new QTreeWidgetItem(group1);
    item11->setText(0,"item11");
    item11->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    item11->setCheckState(0,Qt::Unchecked);
    QTreeWidgetItem *item12=new QTreeWidgetItem(group1);
    item12->setText(0,"item12");
    item12->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    item12->setCheckState(0,Qt::Unchecked);
    QTreeWidgetItem *item13=new QTreeWidgetItem(group1);
    item13->setText(0,"item13");
    item13->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    item13->setCheckState(0,Qt::Unchecked);

    // 添加tree的顶层节点
    treeWidget->insertTopLevelItem(0, group1);
    // 节点始终展开某个节点
    //treeWidget->setItemsExpandable(false);
    treeWidget->expandItem(group1);

    treeWidget->setMaximumWidth(190);

    // 右侧区域 修改为TabWidget控件
    //QTextEdit *textedit = new QTextEdit(this);
    QTabWidget* tabWidget = new QTabWidget(this);

    // 第一个tab选项卡
    {
        QVBoxLayout* vLayout = new QVBoxLayout(this);
        QHBoxLayout* hLayout = new QHBoxLayout(this);

        QWidget* nanWidget = new QWidget(this);
        nanWidget->setLayout(hLayout);

        QWidget* nanWidget2 = new QWidget(this);
        nanWidget2->setLayout(vLayout);

        QComboBox* comboBox1 = new QComboBox(this);
        hLayout->addWidget(comboBox1);
        comboBox1->addItem("country");
        comboBox1->addItem("rock");

        QPushButton* btn1 = new QPushButton("popular", this);
        hLayout->addWidget(btn1);

        QPushButton* btn2 = new QPushButton("popular", this);
        hLayout->addWidget(btn2);

        vLayout->addWidget(nanWidget);

        QGridLayout* grid = new QGridLayout(this);

        QWidget* nanWidget3 = new QWidget(this);
        nanWidget3->setLayout(grid);

        QPushButton* btn3 = new QPushButton("btn3", this);
        grid->addWidget(btn3, 0, 0);
        QPushButton* btn4 = new QPushButton("btn4", this);
        grid->addWidget(btn4, 0, 1);
        QPushButton* btn5 = new QPushButton("btn5", this);
        grid->addWidget(btn5, 1, 0);
        QPushButton* btn6 = new QPushButton("btn6", this);
        grid->addWidget(btn6, 1, 1);

        vLayout->addWidget(nanWidget3);


        tabWidget->addTab(nanWidget2, "tab1");
    }



    // 第二个tab选项卡
    //QLabel* tab1_label2 = new QLabel("label2", this);
    WidgetTab2* tab2 = new WidgetTab2(this);
    tabWidget->addTab(tab2, "tab2");

    // 底部区域
    QTextEdit *textedit2 = new QTextEdit(this);
    textedit2->setMaximumHeight(60);
    //
    hLayout->addWidget(treeWidget);
    hLayout->addWidget(tabWidget);

    // 给水平布局器，增加一个widget封装
    QWidget *nan_hlayout_widget = new QWidget() ;
    nan_hlayout_widget->setLayout(hLayout);

    vLayout->addWidget(nan_hlayout_widget);
    vLayout->addWidget(textedit2);

    // 给垂直布局器，增加一个widget封装
    QWidget *nan_vlayout_widget = new QWidget() ;
    nan_vlayout_widget->setLayout(vLayout);
    nan_vlayout_widget->setWindowTitle("centralwidget");

    // 核心客户区域
    setCentralWidget(nan_vlayout_widget);

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

void MainWindow::toolBtnDialog()
{
    QMessageBox::information(this, tr("info"), "toolBtnDialog");
}
