#ifndef MYPAINTER_H
#define MYPAINTER_H

#include <QtWidgets/QMainWindow>
#include "ui_mypainter.h"
#include "paintwidget.h"


#include "HistogramWidget.h"
//#include "ScribbleArea.h"


#include <QElapsedTimer>

#include <QListView>
#include <QListWidget>
#include <QMap>

#include <QPixmap>

//#include <omp.h>



class MyPainter : public QMainWindow
{
	Q_OBJECT

public:
	MyPainter(QWidget *parent = 0);
	~MyPainter();

	ScribbleArea *p_histogramWidget;

public slots:
	void ActionOpen();
	void ActionSave();
	void EffectClear();
	void ActionNew();

	void ActionLeft();
	void ActionRight();

	void zmena_itemu();
	void vymaz_item();

	void grayscale();

	void grayscale_ave();
	void grayscale_des();
	void grayscale_wei();


	

private:
	Ui::MyPainterClass *ui;
	PaintWidget *paintWidget;

	const QString window_text = "Zadanie ZATKALIK";

	int timerId;

	ScribbleArea histogramWidget;
	

	//PaintWidget paintWidget = PaintWidget(&histogramWidget,this);
	//HistogramWidget histogramWidget;
	
	

	PaintWidget *otvoreny;
	QList<PaintWidget> otvorene_fronta;
	QList<QString> otvorene_filenames;

	int i_typ_grayscale = -10;


protected:
	void timerEvent(QTimerEvent *event);
	
};

#endif // MYPAINTER_H
