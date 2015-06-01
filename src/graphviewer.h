#ifndef GRAPHVIEWER_H
#define GRAPHVIEWER_H
#include "dataitem.h"
#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class GraphViewer;
}

class GraphViewer : public QWidget
{
    Q_OBJECT

public:
    explicit GraphViewer(QWidget *parent = 0);
    ~GraphViewer();
    void setresult(DataItem data,Results result);
    void setGraph();

private slots:
    void on_pushButton_clicked();

    void on_yrmk_clicked();

private:
    Ui::GraphViewer *ui;
    DataItem Data;
    Results Result;
    QList<double> Time;
    QList<double> Growthincm;
    QList<QCPItemLine*> yrs;
    QCPAxisRect *wideAxisRect1; // OutputAxisRectangle
};

#endif // GRAPHVIEWER_H
