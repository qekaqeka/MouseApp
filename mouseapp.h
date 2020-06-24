#ifndef MOUSEAPP_H
#define MOUSEAPP_H
#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include "graph.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MouseApp; }
QT_END_NAMESPACE

class MouseApp : public QMainWindow
{
    Q_OBJECT

public:
    MouseApp(QWidget *parent = nullptr);
    ~MouseApp();

private slots:
    void on_pushButton_clicked();
    void on_graphButton_clicked();
private:
    Ui::MouseApp *ui;
    int *clicks;
    int allClicks;
    int pointsNumber;
    int timeForTimer;
    int timerLoop;
    QTimer timer;
};
#endif // MOUSEAPP_H
