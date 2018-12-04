#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include <QtWidgets>
#include <QMessageBox>
#include <random>
#include <algorithm>
#include <QList>

#include <omp.h>
#include <thread>
#include <chrono>

#include "ScribbleArea.h"
#include"ui_mypainter.h"



class PaintWidget : public QWidget
{
	Q_OBJECT

public:
	//PaintWidget(QWidget *parent = 0);

	int stav = -1;

	int get_progress_percent();

	PaintWidget(Ui::MyPainterClass *parentUI, QWidget *parent = 0);

	PaintWidget(Ui::MyPainterClass *parentUI, ScribbleArea *histoWidget, QWidget *parent = 0);

	void timer_check();



	bool openImage(const QString &fileName);
	bool changeImage(const QString & fileName);
	bool closeImage();
	bool newImage(int x, int y);
	bool saveImage(const QString &fileName);
	void setPenColor(const QColor &newColor);
	void setPenWidth(int newWidth);
	
	void RotateLeft();
	void RotateRight();

	
	void vypocet_grayscale(int * spracovane);
	//void vypocet_grayscale();
	void grayscale(int typ);
	void grayscale_uncheck();
	//void grayscale_vazeny(QProgressDialog * spracovane);
	//void grayscale();

	void grayscale_vazeny(int * spracovane);

	void grayscale_desaturation(int * spracovane);


	bool isModified() const { return modified; }
	QColor penColor() const { return myPenColor; }
	int penWidth() const { return myPenWidth; }

	public slots:
	void clearImage();
	

protected:
	void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
	void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
	void mouseDoubleClickEvent(QMouseEvent *event);

	void timerEvent(QTimerEvent *event);

private:
	Ui::MyPainterClass *ui;
	ScribbleArea *p_histogram;

	std::thread thread_0;
	


	void drawLineTo(const QPoint &endPoint);
	void resizeImage(QImage *image, const QSize &newSize);
	int selectKth(int* data, int s, int e, int k);

	bool modified;
	bool painting;
	int myPenWidth;
	QColor myPenColor;
	QImage image;
	QList<QImage> otvorene_image;
	QList<QString> otvorene_filename;
	QList<QImage> grayscalovane_image;
	QPoint lastPoint;

	int opened=-1;

	int selected_grayscale = -1;
	
	
	
};



#endif // PAINTWIDGET_H
