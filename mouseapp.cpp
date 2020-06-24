#include "mouseapp.h"
#include "ui_mouseapp.h"
MouseApp::MouseApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MouseApp)
    , timer(this)
{
    setWindowIcon(QIcon("MouseAppIcon.png"));//устанавливаем иконку
    ui->setupUi(this);
    ui->graphButton->hide();
    ui->spinBox->setMinimum(1);
    ui->spinBox_2->setMinimum(1);
    ui->spinBox->setValue(10);
    ui->spinBox_2->setValue(10);
    ui->spinBox->setMaximum(3600);
    connect(ui->spinBox,QOverload<int>::of(&QSpinBox::valueChanged),ui->spinBox_2,[this](){ui->spinBox_2->setMaximum(ui->spinBox->value()*10);});
    //делаем так чтобы число в spinBox_2 было максимум в 10 раз больше чем в spinBox
}

MouseApp::~MouseApp()
{
    delete ui;
}

void MouseApp::on_pushButton_clicked()
{
    timeForTimer = ui->spinBox->value()*1000;//время таймера в сек
    pointsNumber = ui->spinBox_2->value();//кол-во точек на графике
    ui->graphButton->hide();
    delete[] clicks;//удаляем массив с числом кликов если он уже существовал
    allClicks = 0;//
    timerLoop = 0;//обнуление переменных на случай если у них было значение
    ui->pushButton->disconnect(this);//кнопка теперь ничего не делает
    ui->pushButton->setText("Кликай сюда!");
    ui->clickNumberLabel->setText("Кликов сделано: 0");
    clicks = new int[pointsNumber]; //создаём массив с кол-во кликов за timeForTimer(сек.) / pointsNumber времени ,и колво элементов масива равно кол-во точек на графике
    memset(clicks,0,pointsNumber*sizeof(int));//заполняем массив нулями
    timer.start(timeForTimer / pointsNumber);//запускаем таймер
    connect(&timer,&QTimer::timeout,this,[&]()
    {//если таймео срабатывает , то выполняется код
        if(timerLoop == pointsNumber-1)
        {
            timer.disconnect(this);//таймер теперь ничего не делает
            timer.stop();
            ui->pushButton->setText("Старт");
            ui->pushButton->setEnabled(false);                                        //защита от случайного повторного запуска
            QTimer::singleShot(1500,this,[this](){ui->pushButton->setEnabled(true);});//
            connect(ui->pushButton,&QPushButton::clicked,this,&MouseApp::on_pushButton_clicked);//кнопка теперь при нажатиии вызвает функцию on_pushButton_clicked()
            ui->graphButton->show();
            return;
        }
        timerLoop++;
    });//код до этого места
    connect(ui->pushButton,&QPushButton::clicked,this,[this]()
    {//если кнопка будет нажата то выполнится код ниже
        clicks[timerLoop]++;
        ui->clickNumberLabel->setText("Кликов сделано: " + QString::number(++allClicks));
    });//до этого места
}

void MouseApp::on_graphButton_clicked()
{
    graph *_graph = new graph(clicks);//создаём график
    _graph->show();
}
