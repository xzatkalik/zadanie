#include "mypainter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyPainter w;
	w.show();
	return a.exec();
}
