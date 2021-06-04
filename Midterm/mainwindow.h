#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cell.h"
#include "maze.h"
#include "mazesolver.h"
#include <QWidget>
#include <chrono>
#include <thread>
#include <QTimer>
#include <QGridLayout>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    QWidget* mainWidget;
    QWidget* mazeWidget;
    QWidget* settingWidget;
    QGridLayout* settinglayout;
    QPushButton* DFSbutton;
    QPushButton* BFSbutton;
    QLabel* rowLabel;
    QLabel* columnLabel;
    QTimer* timer;
    Maze* maze;
    MazeSolver* solver;



public slots:
    void timer_end();

};

#endif // MAINWINDOW_H
