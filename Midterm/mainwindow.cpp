#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    mainWidget = new QWidget;
    mazeWidget = new QWidget;
    settingWidget = new QWidget;
    settinglayout = new QGridLayout;
    DFSbutton = new QPushButton{"DFS algorithm"};
    BFSbutton = new QPushButton{"BFS algorithm"};
    rowLabel = new QLabel{"Number of rows"};
    columnLabel = new QLabel{"Number of columns"};
    mainLayout = new QHBoxLayout;
    rowEdit = new QLineEdit{"20"};
    columnEdit = new QLineEdit{"20"};
    timer = new QTimer;

    connect(timer, SIGNAL(timeout()), this, SLOT(timer_end()));
    connect(BFSbutton, SIGNAL(pressed()), this, SLOT(BFS_callback()));
    connect(DFSbutton, SIGNAL(pressed()), this, SLOT(DFS_callback()));






   constructMainWidget();











//    maze = new Maze{10, 10};
//    maze->generate_maze();

//    solver = new MazeSolver{*maze};
//    auto path = solver->DFS_path();
//    qDebug() << path.size();



//    mainWidget = maze->render(&maze->maze[0][0]);
//    this->setCentralWidget(mainWidget);

//    timer =  new QTimer;
//    connect(timer, SIGNAL(timeout()), this, SLOT(timer_end()));
//    timer->start(1000);

}
void MainWindow::constructMainWidget()
{
    mainWidget->setLayout(mainLayout);
    mainLayout->addWidget(mazeWidget);
    mainLayout->addWidget(settingWidget);
    settingWidget->setLayout(settinglayout);
    settinglayout->addWidget(rowLabel, 2, 2, 2, 3);
    settinglayout->addWidget(rowEdit, 2, 6, 2, 3);
    settinglayout->addWidget(columnLabel, 5, 2, 2, 3);
    settinglayout->addWidget(columnEdit, 5, 6, 2, 3);
    settinglayout->addWidget(BFSbutton, 9, 1, 4, 4);
    settinglayout->addWidget(DFSbutton, 9, 5, 4, 4);
    this->setCentralWidget(mainWidget);
    this->showMaximized();

}

void MainWindow::deleteMainWidget()
{
    delete mainWidget;
    delete mazeWidget;
    delete settingWidget;
    delete settinglayout;
    delete DFSbutton;
    delete BFSbutton;
    delete rowLabel;
    delete columnLabel;
    delete mainLayout;
    delete rowEdit;
    delete columnEdit;
}


void MainWindow::BFS_callback()
{
    timer->stop();
    maze = new Maze{rowEdit->text().toInt(), columnEdit->text().toInt()};
    maze->generate_maze();
    solver =  new MazeSolver{*maze};
    path = solver->BFS_path();
    std::reverse(path.begin(), path.end());
    timer->start(500);
}

void MainWindow::DFS_callback()
{
    timer->stop();
    maze = new Maze{rowEdit->text().toInt(), columnEdit->text().toInt()};
    maze->generate_maze();
    solver =  new MazeSolver{*maze};
    path = solver->DFS_path();
    std::reverse(path.begin(), path.end());
    timer->start(500);

}

MainWindow::~MainWindow()
{
    delete maze;
    delete timer;
}

void MainWindow::timer_end(){
    if(path.size() == 0)
    {
        timer->stop();
        return;
    }
    mazeWidget = maze->render(path[path.size() - 1]);
    path.pop_back();
    constructMainWidget();

}

