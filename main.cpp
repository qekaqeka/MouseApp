#include "mouseapp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//
    MouseApp w;                //запускаем
    w.show();                  //приложение
    return a.exec();           //
}
