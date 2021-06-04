#include "mainwindow.h"
#include "cell.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Cell cell{4, 5};
//    cell.remove_wall_left();
//    cell.remove_wall_down();
    cell.remove_wall_right();
    cell.remove_wall_up();
    this->setCentralWidget(cell.get_widget());
}

MainWindow::~MainWindow()
{
}

