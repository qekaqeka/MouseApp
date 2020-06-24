#include "graph.h"
graph::graph(int clicks_a[] , QWidget *parent)  :  QWidget(parent)
{
   pointsNumber = _msize(clicks_a) / sizeof(int);//узнаём сколько точек должно быть на графике
   clicks = new int[pointsNumber]; // создаём динамический массив
   memcpy(clicks,clicks_a,pointsNumber*sizeof(int));//копируем значение из одного массива в другой
}

void graph::paintEvent(QPaintEvent *)//функция котороая вызывается с каждой перересовкой окна
{
    QPainter painter(this);//класс художника
    painter.translate(0, rect().height());//перемещаем нулевую кооринату в нижний левый угол экрана
    QPoint *points = new QPoint[pointsNumber];//динамический массив с точками
    int largestElement = clicks[0];//иницианилизируем переменную самого большого элемента масива с числом кликов
    for(int i = 0; i < pointsNumber-1; i++)//
        if(largestElement < clicks[i])     //находим самый большой элемент массисва с числом кликов
            largestElement = clicks[i];    //

    painter.setPen(QPen(Qt::gray,1,Qt::DashLine));//устанавливаем цвет,тощину,тип линии ручки с помощью которой ресуются линии и контур
    for(int i = 0; i < pointsNumber; i++)
    {
        points[i] = QPoint(width()/(pointsNumber-1)*i,-height() / largestElement * clicks[i]);//расчитываем расположение точек
        painter.drawLine(points[i],QPoint(points[i].rx(),0));//ресуем серые линии графика
    }
        painter.setPen(QPen(Qt::green,1,Qt::SolidLine));//изменяем цвет,тощину,тип линии ручки
    for(int i = 0; i < pointsNumber-1; i++)
    {
        painter.drawLine(points[i],points[i+1]);//ресуем зелёные линии графика
    }
        painter.setPen(QPen(Qt::red,1));//изменяем цвет ручки,толщину ручки
        painter.setBrush(QBrush(Qt::red));//уставаливаем цвет кисти с помощью которой рисуется внутреняя часть фигур
    for(int i = 0; i < pointsNumber ; i++)
    {
        painter.drawEllipse(points[i],2,2);//рисуем красные точки
        if(points[i].ry() > -height()/2 && points[i].rx() < width() / 2)                             //
            painter.drawText(QPoint(points[i].rx()+10,points[i].ry()-10),QString::number(clicks[i]));//
        if(points[i].ry() < -height()/2 && points[i].rx() > width() / 2)                             //
            painter.drawText(QPoint(points[i].rx()-10,points[i].ry()+10),QString::number(clicks[i]));//определяем место цифры относительно красной
        if(points[i].ry() > -height()/2 && points[i].rx() > width() / 2)                             //точки исходя из того в какой части экрана она находится
            painter.drawText(QPoint(points[i].rx()-10,points[i].ry()-10),QString::number(clicks[i]));//
        if(points[i].ry() < -height()/2 && points[i].rx() < width() / 2)                             //
            painter.drawText(QPoint(points[i].rx()+10,points[i].ry()+10),QString::number(clicks[i]));//
    }
}
