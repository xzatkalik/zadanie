#include "paintwidget.h"


PaintWidget::PaintWidget(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_StaticContents);
	modified = false;
	painting = false;
	myPenWidth = 1;
	myPenColor = Qt::blue;

	
}

bool PaintWidget::openImage(const QString &fileName)
{
	QImage loadedImage;
	if (!loadedImage.load(fileName))
		return false;

	if (otvorene_filename.indexOf(fileName) >= 0)
	{
		QMessageBox mbox;
		QString text = "Tento obrazok uz je otvoreny";
		mbox.setText(text);
		mbox.exec();

		return false;
	}
	else {
		//ulozenie aktualneho obrazku
		if (opened > -1) otvorene_image[opened] = image;

		
		//natiahnutie noveho
		QSize newSize = loadedImage.size();
		resizeImage(&loadedImage, newSize);
		image = loadedImage;

		otvorene_image.append(image);
		otvorene_filename.append(fileName);
		opened = otvorene_image.size() - 1;

		grayscalovane_image.append(image);


		this->resize(image.size());
		this->setMinimumSize(image.size());
		modified = false;
		update();
		return true;
	}
}

bool PaintWidget::changeImage(const QString &fileName)
{
	otvorene_image[opened] = image;

	//int index = otvorene_filename.indexOf(fileName);
	//image = otvorene_image[index];
	//opened = index;
	opened = otvorene_filename.indexOf(fileName);
	image = otvorene_image[opened];

	update();

	return true;
}

bool PaintWidget::closeImage()
{
	

	otvorene_image.removeAt(opened);
	otvorene_filename.removeAt(opened);
	
	opened = -1;
	clearImage();

	update();

	return true;
}


bool PaintWidget::newImage(int x, int y)
{
	QImage loadedImage(x,y,QImage::Format_RGB32);
	loadedImage.fill(qRgb(255, 255, 255));
	QSize newSize = loadedImage.size();
	resizeImage(&loadedImage, newSize);
	image = loadedImage;
	this->resize(image.size());
	this->setMinimumSize(image.size());
	modified = false;
	update();
	return true;
}

bool PaintWidget::saveImage(const QString &fileName)
{
	QImage visibleImage = image;
	resizeImage(&visibleImage, size());

	if (visibleImage.save(fileName,"png")) {
		modified = false;
		return true;
	}
	else {
		return false;
	}
}

void PaintWidget::setPenColor(const QColor &newColor)
{
	myPenColor = newColor;
}

void PaintWidget::setPenWidth(int newWidth)
{
	myPenWidth = newWidth;
}

void PaintWidget::RotateLeft()
{
	QImage druhy(image.height(), image.width(), QImage::Format_RGB32);
	int x = image.height();
	int y = image.width();
	QRgb *data = (QRgb *)image.bits();
	QRgb *data2 = (QRgb *)druhy.bits();
	int riadok1 = image.bytesPerLine()/4;
	int riadok2 = druhy.bytesPerLine()/4;
#pragma omp parallel for
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			data2[i + (y-j-1)*riadok2] = data[j + i*riadok1];
		}
	}
	image = druhy;
	update();
}

void PaintWidget::RotateRight()
{
	QImage druhy(image.height(), image.width(), QImage::Format_RGB32);
	int x = image.height();
	int y = image.width();
	QRgb *data = (QRgb *)image.bits();
	QRgb *data2 = (QRgb *)druhy.bits();
	int riadok1 = image.bytesPerLine() / 4;
	int riadok2 = druhy.bytesPerLine() / 4;
#pragma omp parallel for
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			data2[x - i - 1 + j*riadok2] = data[j + i*riadok1];
		}
	}
	image = druhy;
	update();
}


void PaintWidget::vypocet_grayscale()
{
	for (int i = 0; i < image.width(); i++)
	{
		for (int j = 0; j < image.height(); j++)
		{
			QColor tmp = image.pixelColor(i, j);
			int average = (tmp.red() + tmp.blue() + tmp.red()) / 3;
			tmp.setBlue(average);
			tmp.setRed(average);
			tmp.setGreen(average);
			image.setPixelColor(i, j, tmp);


			//std::thread::id main_thread_id = std::this_thread::get_id();

		}
	}
}

void PaintWidget::grayscale(int typ)
{

	
	//if (!image.isGrayscale())
	//{
//#pragma omp parallel for default(none)  
		//std::thread::id main_thread_id = std::this_thread::get_id();
		switch(typ) {
		case 0: {
			std::thread t0(&PaintWidget::vypocet_grayscale, this);

			t0.join();
			break; }
		case 1: {
			std::thread t1(&PaintWidget::grayscale_vazeny, this);
			t1.join();
			break; }
		case 2: {
			std::thread t1(&PaintWidget::grayscale_desaturation, this);
			t1.join();
			break; }


		}
		  	
		update();
	//}
}

void PaintWidget::grayscale_uncheck()
{
	grayscalovane_image[opened] = image;
	image = otvorene_image[opened];
}

void PaintWidget::grayscale_vazeny()
{
	//grayscale weightened method
	//if (!image.isGrayscale())
	//{
		for (int i = 0; i < image.width(); i++)
		{
			for (int j = 0; j < image.height(); j++)
			{
				QColor tmp = image.pixelColor(i, j);
				int average = (int)((0.3*tmp.red() + 0.59*tmp.blue() + 0.11*tmp.red()) + 0.5);
				tmp.setBlue(average);
				tmp.setRed(average);
				tmp.setGreen(average);
				image.setPixelColor(i, j, tmp);

				int th = omp_get_thread_num();
				if (th > 0)
				{

				}
			}
		}

		//update();
	//}
}

void PaintWidget::grayscale_desaturation()
{
	
	for (int i = 0; i < image.width(); i++)
	{
		for (int j = 0; j < image.height(); j++)
		{
			QColor tmp = image.pixelColor(i, j);
			int max = std::max(tmp.red(), tmp.blue());
				max = std::max(max, tmp.red());
			int min = std::min(tmp.red(), tmp.blue());
				min = std::min(max, tmp.red());
			int average = (int)(((max+min)/2 ) + 0.5);
			tmp.setBlue(average);
			tmp.setRed(average);
			tmp.setGreen(average);
			image.setPixelColor(i, j, tmp);

			int th = omp_get_thread_num();
			if (th > 0)
			{

			}
		}
	}

	//update();
//}
}

void PaintWidget::clearImage()
{
	image.fill(qRgb(255, 255, 255));
	modified = true;
	update();
}

void PaintWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		lastPoint = event->pos();
		
		painting = true;
	}
	if (event->button() == Qt::RightButton) {
		

		//lastPoint = event->pos();
		
		painting = true;
	}
	
}

void PaintWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
	if ((event->buttons() & Qt::LeftButton) && painting)
		drawLineTo(event->pos());
	
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && painting) {
		drawLineTo(event->pos());
		
		painting = false;
	}

	if (event->button() == Qt::RightButton && painting) {
		QPainter painter(&image);
		painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

	//	printf("%d\n", event->pos());
		//bb.push_back(event->pos());
		//painter.drawEllipse(event->pos(), 5, 5);
		painter.drawPoint(event->pos());
		update();
		//slvypln();
		//drawLineTo(event->pos());
		painting = false;
	}
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QRect dirtyRect = event->rect();
	painter.drawImage(dirtyRect, image, dirtyRect);
}

void PaintWidget::resizeEvent(QResizeEvent *event)
{
	QWidget::resizeEvent(event);
}

void PaintWidget::drawLineTo(const QPoint &endPoint)
{
	QPainter painter(&image);
	painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	//painter.drawLine(lastPoint, endPoint);
	
	
	modified = true;
	
	

	int rad = (myPenWidth / 2) + 2;
	update(QRect(lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
	lastPoint = endPoint;

//	bb.push_back(lastPoint);
	
	//printf("%d\n", lastPoint);


}

void PaintWidget::resizeImage(QImage *image, const QSize &newSize)
{
	if (image->size() == newSize)
		return;

	QImage newImage(newSize, QImage::Format_RGB32);
	newImage.fill(qRgb(255, 255, 255));
	QPainter painter(&newImage);
	painter.drawImage(QPoint(0, 0), *image);
	*image = newImage;
}

int PaintWidget::selectKth(int * data, int s, int e, int k)
{
	// 5 or less elements: do a small insertion sort
	if (e - s <= 5)
	{
		for (int i = s + 1; i < e; i++)
			for (int j = i; j > 0 && data[j - 1] > data[j]; j--) std::swap(data[j], data[j - 1]);
		return s + k;
	}

	int p = (s + e) / 2; // choose simply center element as pivot

						 // partition around pivot into smaller and larger elements
	std::swap(data[p], data[e - 1]); // temporarily move pivot to the end
	int j = s;  // new pivot location to be calculated
	for (int i = s; i + 1 < e; i++)
		if (data[i] < data[e - 1]) std::swap(data[i], data[j++]);
	std::swap(data[j], data[e - 1]);

	// recurse into the applicable partition
	if (k == j - s) return s + k;
	else if (k < j - s) return selectKth(data, s, j, k);
	else return selectKth(data, j + 1, e, k - j + s - 1); // subtract amount of smaller elements from k
}
