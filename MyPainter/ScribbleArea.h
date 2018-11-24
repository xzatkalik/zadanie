#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>
#include <QtWidgets>
#include <QMessageBox>

struct bod {
	double x;
	double y;
	
};

class ScribbleArea : public QWidget
{
	Q_OBJECT

public:
	ScribbleArea(QWidget *parent = 0);

	bool openImage(const QString &fileName);
	bool saveImage(const QString &fileName, const char *fileFormat);
	void setPenColor(const QColor &newColor);
	void setPenWidth(int newWidth);

	bool isModified() const { return modified; }
	QColor penColor() const { return myPenColor; }
	int penWidth() const { return myPenWidth; }

	bool rataj_histogram(QImage *zdroj);
	void kresli_histogram();

public slots:
	void clearImage();
	void print();

protected:
	void mousePressEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
	void paintEvent(QPaintEvent *event) override;
	void resizeEvent(QResizeEvent *event) override;

private:
	void drawLineTo(const QPoint &endPoint);
	void resizeImage(QImage *image, const QSize &newSize);

	bool b_vyratane = false;

	bool modified;
	bool scribbling;
	int myPenWidth;
	QColor myPenColor;
	QImage image;
	QPoint lastPoint;

	int pocetnost_red[256];
	int pocetnost_green[256];
	int pocetnost_blue[256];

	int max = 0;
	

	void cisti_pocetnosti();
	void najdi_maxima();

	void kresli_ciaru(QPainter *platno, int *pocetnosti);

};