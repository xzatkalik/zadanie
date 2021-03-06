#include "ScribbleArea.h"



ScribbleArea::ScribbleArea(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_StaticContents);
	modified = false;
	scribbling = false;
	myPenWidth = 1;
	myPenColor = Qt::blue;
}


bool ScribbleArea::openImage(const QString &fileName)
{
	QImage loadedImage;
	if (!loadedImage.load(fileName))
		return false;

	QSize newSize = loadedImage.size().expandedTo(size());
	resizeImage(&loadedImage, newSize);
	image = loadedImage;
	modified = false;
	update();
	return true;
}

bool ScribbleArea::saveImage(const QString &fileName, const char *fileFormat)
{
	QImage visibleImage = image;
	resizeImage(&visibleImage, size());

	if (visibleImage.save(fileName, fileFormat)) {
		modified = false;
		return true;
	}
	else {
		return false;
	}
}

void ScribbleArea::setPenColor(const QColor &newColor)
{
	myPenColor = newColor;
}

void ScribbleArea::setPenWidth(int newWidth)
{
	myPenWidth = newWidth;
}

void ScribbleArea::clearImage()
{
	image.fill(qRgb(255, 255, 255));
	modified = true;
	update();
}

void ScribbleArea::mousePressEvent(QMouseEvent *event)
{
	/*if (event->button() == Qt::LeftButton) {
		lastPoint = event->pos();
		scribbling = true;
	}*/
	QMessageBox info;
	info.setWindowTitle("Histogram info");
	QString text;
	QPoint bodik = event->pos();

	double krok = (double)width() / (double)256;
	int hodnota = bodik.x() / krok ;
	info.setText("Value " + QString::number(hodnota) +
		"\n Red je: " + QString::number(pocetnost_red[hodnota]) + 
		"\n Green je: " + QString::number(pocetnost_green[hodnota]) + 
		"\n Blue je: " + QString::number(pocetnost_blue[hodnota])
	);
	info.exec();
}

void ScribbleArea::mouseMoveEvent(QMouseEvent *event)
{
	/*if ((event->buttons() & Qt::LeftButton) && scribbling)
		drawLineTo(event->pos());*/

}

void ScribbleArea::mouseReleaseEvent(QMouseEvent *event)
{
	/*if (event->button() == Qt::LeftButton && scribbling) {
		drawLineTo(event->pos());
		scribbling = false;
	}*/
}

void ScribbleArea::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QRect dirtyRect = event->rect();
	painter.drawImage(dirtyRect, image, dirtyRect);
}

void ScribbleArea::resizeEvent(QResizeEvent *event)
{
	/*if (width() > image.width() || height() > image.height()) {
		int newWidth = qMax(width() + 128, image.width());
		int newHeight = qMax(height() + 128, image.height());
		resizeImage(&image, QSize(newWidth, newHeight));
		update();
	}*/
	
	int newWidth = width() ;
	int newHeight = height();

	image = image.scaled(QSize(newWidth, newHeight));

	resizeImage(&image, QSize(newWidth, newHeight));

	
	update();
	if(b_vyratane) kresli_histogram();

	QWidget::resizeEvent(event);
}

void ScribbleArea::drawLineTo(const QPoint &endPoint)
{
	QPainter painter(&image);
	painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
		Qt::RoundJoin));
	painter.drawLine(lastPoint, endPoint);
	modified = true;

	int rad = (myPenWidth / 2) + 2;
	update(QRect(lastPoint, endPoint).normalized()
		.adjusted(-rad, -rad, +rad, +rad));
	lastPoint = endPoint;
}

void ScribbleArea::resizeImage(QImage *image, const QSize &newSize)
{
	if (image->size() == newSize)
		return;

	QImage newImage(newSize, QImage::Format_RGB32);
	newImage.fill(qRgb(255, 255, 255));
	QPainter painter(&newImage);
	painter.drawImage(QPoint(0, 0), *image);
	*image = newImage;
}

void ScribbleArea::cisti_pocetnosti()
{
	for (int i = 0; i < 256; i++)
	{
		pocetnost_red[i] = 0;
		pocetnost_green[i] = 0;
		pocetnost_blue[i] = 0;
	}
}



void ScribbleArea::najdi_maxima()
{
	max = 0;
	for (int i = 0; i < 256; i++)
	{
		if (pocetnost_red[i] > max) max = pocetnost_red[i];
		if (pocetnost_green[i] > max) max = pocetnost_green[i];
		if (pocetnost_blue[i] > max) max = pocetnost_blue[i];

	}
}

void ScribbleArea::kresli_ciaru(QPainter * platno, int * pocetnosti)
{
	int newWidth = width();
	int newHeight = height();
	int os_y = newHeight;

	double krok = (double)newWidth / (double)256;

	bod aktualny;
	bod predosly;

	double ykrok = ((double)newHeight / (double)max);

	predosly.x = 0;
	predosly.y = (os_y - pocetnosti[0] * ykrok);

	for (int i = 1; i < 256; i++)
	{
		aktualny.x = (predosly.x + krok);
		aktualny.y = (os_y - pocetnosti[i] * ykrok);
		platno->drawLine(QPoint(predosly.x + 0.5, predosly.y + 0.5), QPoint(aktualny.x + 0.5, aktualny.y + 0.5));
		predosly = aktualny;
	}

}

bool ScribbleArea::rataj_histogram(QImage * zdroj)
{
	QColor tmp;

	this->cisti_pocetnosti();

	for (int i = 0; i < zdroj->width(); i++)
	{
		for (int j = 0; j < zdroj->height(); j++)
		{
			tmp = zdroj->pixelColor(i, j);
			

			pocetnost_red[tmp.red()]++;
			pocetnost_green[tmp.green()]++;
			pocetnost_blue[tmp.blue()]++;

		}
	}

	najdi_maxima();
	kresli_histogram();

	b_vyratane = true;
	return true;
}

void ScribbleArea::kresli_histogram()
{
	clearImage();
	
		
	QColor PenColor;
	PenColor.setRgb(255, 0, 0);
	QPainter painter(&image);
	painter.setPen(QPen(PenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

	kresli_ciaru(&painter, pocetnost_red);

	painter.setPen(QPen(QColor(0,255,0), myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	kresli_ciaru(&painter, pocetnost_green);

	painter.setPen(QPen(QColor(0, 0,255), myPenWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
	kresli_ciaru(&painter, pocetnost_blue);

	update();
}

void ScribbleArea::print()
{
	/*
#if QT_CONFIG(printdialog)
	QPrinter printer(QPrinter::HighResolution);

	QPrintDialog printDialog(&printer, this);
	if (printDialog.exec() == QDialog::Accepted) {
		QPainter painter(&printer);
		QRect rect = painter.viewport();
		QSize size = image.size();
		size.scale(rect.size(), Qt::KeepAspectRatio);
		painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
		painter.setWindow(image.rect());
		painter.drawImage(0, 0, image);
	}
#endif // QT_CONFIG(printdialog)*/
}

