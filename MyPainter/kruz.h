#ifndef KRUZ_H
#define KRUZ_H

#include <QDialog>
#include <QRadioButton>
#include <QSpinBox>
#include "ui_kruz.h"
#include "paintwidget.h"
#include "mypainter.h"
#include <QColor>
#include <QColorDialog>


class kruz : public QDialog
{
	Q_OBJECT

public:
	kruz(QWidget *parent = 0);
	~kruz();

	//void posliwidget(PaintWidget* pw);
	//mypainter *akt;
	PaintWidget *paintWidget;

private:
	Ui::kruz ui;
	QColor color;
	

public slots:
	void kresli();
	void kreslikruznicu();
	void farba();
};

#endif // KRUZ_H
