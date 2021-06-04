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
#include <QLineEdit>
#include <vector>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void constructMainWidget();
    void deleteMainWidget();



private:
    QWidget* mainWidget;
    QWidget* mazeWidget;
    QWidget* settingWidget;
    QGridLayout* settinglayout;
    QPushButton* DFSbutton;
    QPushButton* BFSbutton;
    QLabel* rowLabel;
    QLabel* columnLabel;
    QHBoxLayout* mainLayout;
    QLineEdit* rowEdit;
    QLineEdit* columnEdit;
    QTimer* timer;
    Maze* maze;
    MazeSolver* solver;
    std::vector<const Cell*> path;



public slots:
    void timer_end();
    void DFS_callback();
    void BFS_callback();

};

#endif // MAINWINDOW_H
