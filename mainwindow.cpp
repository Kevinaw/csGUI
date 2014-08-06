#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QListWidget>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // central widget
    QTabWidget* mainWidget = new QTabWidget(this);
    setCentralWidget(mainWidget);

    // dockable widget
    QDockWidget* docWidget = new QDockWidget(this);
    QListWidget* listWidget = new QListWidget(this);
    listWidget->setViewMode(QListView::IconMode);
    listWidget->setGridSize(QSize(110, 90));
    docWidget->setWidget(listWidget);
    docWidget->setAllowedAreas(Qt::LeftDockWidgetArea);
    docWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    docWidget->setWindowTitle("Components");
    addDockWidget(Qt::LeftDockWidgetArea, docWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}
