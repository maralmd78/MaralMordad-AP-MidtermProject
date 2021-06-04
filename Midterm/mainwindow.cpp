#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->showMaximized();








    maze = new Maze{10, 10};
    maze->generate_maze();

    solver = new MazeSolver{*maze};
    auto path = solver->DFS_path();
    qDebug() << path.size();



    mainWidget = maze->render(&maze->maze[0][0]);
    this->setCentralWidget(mainWidget);

//    timer =  new QTimer;
//    connect(timer, SIGNAL(timeout()), this, SLOT(timer_end()));
//    timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete maze;
    delete timer;
}

void MainWindow::timer_end(){
    qDebug() << "hello";
    mainWidget = maze->render(&maze->maze[1][0]);
    this->setCentralWidget(mainWidget);




}

