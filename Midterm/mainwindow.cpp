#include "mainwindow.h"
#include "cell.h"
#include "maze.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    Cell cell{4, 5};
//    cell.remove_wall_up();
//    this->setCentralWidget(cell.get_widget());
    Maze maze{10, 10};
    maze.generate_maze();
    maze.render(nullptr);
    this->setCentralWidget(maze.render(&maze.maze[5][0]));
//    QTableWidget* table = new QTableWidget;
//    table->setRowCount(5);
//    table->setColumnCount(5);
//    Cell cell{4, 5};
//    table->setCellWidget(0, 0, cell.get_widget());
//    table->verticalHeader()->setVisible(false);
//    table->horizontalHeader()->setVisible(false);
//    this->setCentralWidget(table);




}

MainWindow::~MainWindow()
{
}

