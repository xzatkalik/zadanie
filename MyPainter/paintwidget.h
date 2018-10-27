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



class PaintWidget : public QWidget
{
	Q_OBJECT

public:
	PaintWidget(QWidget *parent = 0);

	bool openImage(const QString &fileName);
	bool changeImage(const QString & fileName);
	bool newImage(int x, int y);
	bool saveImage(const QString &fileName);
	void setPenColor(const QColor &newColor);
	void setPenWidth(int newWidth);
	
	void RotateLeft();
	void RotateRight();

	void grayscale();


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

private:
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
	QPoint lastPoint;

	int opened;
	

	
};



#endif // PAINTWIDGET_H
