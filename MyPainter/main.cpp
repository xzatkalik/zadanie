#include "mypainter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//a.setWindowIcon(QIcon(":/cell.svg"));
	MyPainter w;
	w.show();
	return a.exec();
}
