#include "diagramandgraph.h"
#include "ui_diagramandgraph.h"

DiagramAndGraph::DiagramAndGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiagramAndGraph)
{
    ui->setupUi(this);
}

DiagramAndGraph::~DiagramAndGraph()
{
    delete ui;
}
