#ifndef PLOTSELECT_H
#define PLOTSELECT_H
#include "dataitem.h"
#include "qcustomplot.h"
#include "customseason.h"
#include "showavg.h"
#include "alglib/statistics.h"
#include <QStandardItemModel>
#include <QCheckBox>
#include <QMessageBox>
#include <QFileDialog>
#include <QLabel>
#include <QMainWindow>
#include <cmath>

namespace Ui {
class PlotSelect;
}

class PlotSelect : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlotSelect(QWidget *parent = 0);
    void setresult(const DataItem data, const Results result);
    void setGraph();
    ~PlotSelect();

private slots:
    void fgclicked(bool clicked, int row);
    void sgclicked(bool clicked, int row);

    void on_pushButton_clicked();

    void on_customSeason_clicked();

    void season_accepted();

    void on_Sbias_button_clicked();

    void on_savepng_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PlotSelect *ui;
    DataItem Data;
    Results Result;
    QDate start, end;
    QList<double> Growthincm;
    QList<double> Time;
    QList<QCheckBox*> SG;
    QList<QCheckBox*> FG;
    CustomSeason *cs;
    bool csran;
    bool error;
    QList<Avg> LAvg;
    double Favg, Savg;
    QCPGraph *graph;
    QCPGraph *SGoverlay;
    QCPGraph *FGoverlay;
    QCPGraph *mainGraph42; // Copied
    QCPAxis *mainX;
    ShowAvg *sa;
    void seasonality_test();
};

#endif // PLOTSELECT_H


class mycheck : public QCheckBox
{
    Q_OBJECT

public:
    mycheck(int rown, QWidget *parent = 0);

signals:
    void toggled(bool checked, int row);

private slots:
    void togcustom(bool checked);

private:
    int row;
};
