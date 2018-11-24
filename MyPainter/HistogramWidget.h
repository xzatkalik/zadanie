//#pragma once
#ifndef HISTOGRAMWIDGET_H
#define HISTOGRAMWIDGET_H

#include <QPainter>

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
class HistogramWidget : public QWidget
{
	Q_OBJECT

public:
	HistogramWidget(QWidget *parent = 0);
	~HistogramWidget();

	void clearImage();

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;


private:
	bool modified;
	bool painting;
	int myPenWidth;
	QColor myPenColor;
	QImage image;

	void resizeImage(QImage *image, const QSize &newSize);
};

#endif // HISTOGRAMWIDGET_H