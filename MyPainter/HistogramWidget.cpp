#include "HistogramWidget.h"



HistogramWidget::HistogramWidget(QWidget *parent)
	: QWidget(parent)
{
	
	/*QPainter painter(this);
	painter.setPen(Qt::blue);
	painter.setFont(QFont("Arial", 30));
	painter.drawText(rect(), Qt::AlignCenter, "Qt");*/
	
	
	setAttribute(Qt::WA_StaticContents);
	modified = false;
	painting = false;
	myPenWidth = 1;
	myPenColor = Qt::blue;


	
	QImage loadedImage(400, 400, QImage::Format_RGB32);
	loadedImage.fill(qRgb(255, 255, 255));
	//QSize newSize = loadedImage.size();
	//resizeImage(&loadedImage, newSize);
	image = loadedImage;
	this->resize(image.size());
	this->setMinimumSize(image.size());
	modified = false;
	update();

	


}


HistogramWidget::~HistogramWidget()
{
}

void HistogramWidget::clearImage()
{
	image.fill(qRgb(255, 255, 255));
	modified = true;

	//DrawLi
 	update();
}

void HistogramWidget::resizeImage(QImage * image, const QSize & newSize)
{
	if (image->size() == newSize)
		return;

	QImage newImage(newSize, QImage::Format_RGB32);
	newImage.fill(qRgb(255, 255, 255));
	QPainter painter(&newImage);
	painter.drawImage(QPoint(0, 0), *image);
	*image = newImage;
}

void HistogramWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QRect dirtyRect = event->rect();
	painter.drawImage(dirtyRect, image, dirtyRect);
}
