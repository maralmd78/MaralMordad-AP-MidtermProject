#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    mainWidget = new QWidget;
    mazeWidget = new QWidget;
    mazeWidget->setStyleSheet("background-color: white");
    settingWidget = new QWidget;
    settinglayout = new QGridLayout;
    DFSbutton = new QPushButton{"DFS algorithm"};
    BFSbutton = new QPushButton{"BFS algorithm"};
    rowLabel = new QLabel{"Number of rows"};
    columnLabel = new QLabel{"Number of columns"};
    timeLabel = new QLabel{"Time interval"};
    mainLayout = new QGridLayout;
    rowEdit = new QLineEdit{"20"};
    columnEdit = new QLineEdit{"20"};
    timeEdit = new QLineEdit{"500"};
    timer = new QTimer;

    connect(timer, SIGNAL(timeout()), this, SLOT(timer_end()));
    connect(BFSbutton, SIGNAL(pressed()), this, SLOT(BFS_callback()));
    connect(DFSbutton, SIGNAL(pressed()), this, SLOT(DFS_callback()));






   constructMainWidget();



}
void MainWindow::constructMainWidget()
{
    mainWidget->setLayout(mainLayout);
    mainLayout->addWidget(mazeWidget, 0, 0, 1, 5);
    mainLayout->addWidget(settingWidget, 0, 5, 1, 1);
    settingWidget->setLayout(settinglayout);
    settinglayout->addWidget(rowLabel, 2, 2, 2, 3);
    settinglayout->addWidget(rowEdit, 2, 6, 2, 3);
    settinglayout->addWidget(columnLabel, 5, 2, 2, 3);
    settinglayout->addWidget(columnEdit, 5, 6, 2, 3);
    settinglayout->addWidget(timeLabel, 8, 2, 2, 3);
    settinglayout->addWidget(timeEdit, 8, 6, 2, 3);
    settinglayout->addWidget(BFSbutton, 12, 1, 4, 4);
    settinglayout->addWidget(DFSbutton, 12, 5, 4, 4);
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
    timer->start(timeEdit->text().toInt());
}

void MainWindow::DFS_callback()
{
    timer->stop();
    maze = new Maze{rowEdit->text().toInt(), columnEdit->text().toInt()};
    maze->generate_maze();
    solver =  new MazeSolver{*maze};
    path = solver->DFS_path();
    std::reverse(path.begin(), path.end());
    timer->start(timeEdit->text().toInt());

}

MainWindow::~MainWindow()
{
    delete maze;
    delete timer;
}

void MainWindow::timer_end(){
    mainLayout->removeWidget(mazeWidget);
    mainLayout->removeWidget(settingWidget);
    if(path.size() == 0)
    {
        timer->stop();
        return;
    }
    mazeWidget = maze->render(path[path.size() - 1]);
    path.pop_back();
    constructMainWidget();

}

