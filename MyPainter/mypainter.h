#ifndef MYPAINTER_H
#define MYPAINTER_H

#include <QtWidgets/QMainWindow>
#include "ui_mypainter.h"
#include "paintwidget.h"
#include <QElapsedTimer>

#include <QListView>
#include <QListWidget>
#include <QMap>

#include <QPixmap>


class MyPainter : public QMainWindow
{
	Q_OBJECT

public:
	MyPainter(QWidget *parent = 0);
	~MyPainter();

	

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

	

private:
	Ui::MyPainterClass ui;
	PaintWidget paintWidget;

	PaintWidget *otvoreny;
	QList<PaintWidget> otvorene_fronta;
	QList<QString> otvorene_filenames;

	int i_typ_grayscale = -10;
	
};

#endif // MYPAINTER_H
