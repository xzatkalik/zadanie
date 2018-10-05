#ifndef MYPAINTER_H
#define MYPAINTER_H

#include <QtWidgets/QMainWindow>
#include "ui_mypainter.h"
#include "paintwidget.h"
#include <QElapsedTimer>

#include <QListView>
#include <QListWidget>


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

	

private:
	Ui::MyPainterClass ui;
	PaintWidget paintWidget;
};

#endif // MYPAINTER_H
