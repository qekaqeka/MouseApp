#ifndef DIAGRAMANDGRAPH_H
#define DIAGRAMANDGRAPH_H

#include <QWidget>

namespace Ui {
class DiagramAndGraph;
}

class DiagramAndGraph : public QWidget
{
    Q_OBJECT

public:
    explicit DiagramAndGraph(QWidget *parent = nullptr);
    ~DiagramAndGraph();

private:
    Ui::DiagramAndGraph *ui;
};

#endif // DIAGRAMANDGRAPH_H
