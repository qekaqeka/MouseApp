#ifndef GRAPH_H//защита от многократного дополнение кода при включении одного заголовочного файла несколько раз в одно место
#define GRAPH_H
#include <QPainter>
#include <QWidget>
class graph : public QWidget
{
    Q_OBJECT
public:
    explicit graph(int clicks_a[] , QWidget *parent = nullptr);//коструктор

public slots:
    void paintEvent(QPaintEvent *);//функция для рисования
private:
    int *clicks;//указатель на массив с числом клиокв
    int pointsNumber;//кол-во точек на графике
};

#endif // GRAPH_H
