#include "mypainter.h"

MyPainter::MyPainter(QWidget *parent)
	: QMainWindow(parent)
{
	prve = new PaintWidget();
	paintWidget.append(prve);

	ui.setupUi(this);
	ui.scrollArea->setWidget(this->paintWidget[otvorene]);
	ui.scrollArea->setBackgroundRole(QPalette::Dark);
}

MyPainter::~MyPainter()
{
	free(prve);
	paintWidget.clear();
}

void MyPainter::ActionOpen()
{
	//otvoreny = new PaintWidget();
	//ui.scrollArea->setWidget(this->otvoreny);
	PaintWidget *temp = new PaintWidget();
	paintWidget.append(temp);
	otvorene++;
	ui.scrollArea->setWidget(this->paintWidget[otvorene]);
	ui.scrollArea->setBackgroundRole(QPalette::Dark);



	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "image files (*.png *.jpg *.bmp)");
	if (!fileName.isEmpty())
		paintWidget[otvorene]->openImage(fileName);
		//otvoreny->openImage(fileName);
		

	ui.listWidget->addItem(fileName);
<<<<<<< HEAD
	otvorene_filenames.append(fileName);
	
=======
	otvorene_fronta.append(otvoreny);
	otvorene_filenames.append(fileName);
>>>>>>> parent of d17c89f... ide ale kopiruje
}
	
void MyPainter::ActionSave()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), "untitled.png", tr("png Files (*.png)"));
	if (fileName.isEmpty()) {
		return;
	}
	else {
		paintWidget[otvorene]->saveImage(fileName);
	}
}

void MyPainter::EffectClear()
{
	paintWidget[otvorene]->clearImage();
}

void MyPainter::ActionNew()
{
	paintWidget[otvorene]->newImage(800, 600);
}

void MyPainter::ActionLeft()
{
	QMessageBox mbox;
	QElapsedTimer timer;
	timer.start();
	paintWidget[otvorene]->RotateLeft();
	QString text = "The operation took " + QString::number(timer.nsecsElapsed() / 1000000.0) + " milliseconds";
	mbox.setText(text);
	mbox.exec();
}

void MyPainter::ActionRight()
{
	QMessageBox mbox;
	QElapsedTimer timer;
	timer.start();
	paintWidget[otvorene]->RotateRight();
	QString text = "The operation took " + QString::number(timer.nsecsElapsed() / 1000000.0) + " milliseconds";
	mbox.setText(text);
	mbox.exec();
}

void MyPainter::zmena_itemu()
{

	QString fileName = ui.listWidget->currentItem()->text();
<<<<<<< HEAD
	int otvorene = otvorene_filenames.indexOf(fileName);
=======
	//int subor = otvorene_filenames.indexOf(fileName);
>>>>>>> parent of d17c89f... ide ale kopiruje


	//ui.scrollArea->setWidget(this->paintWidget[otvorene]);
//	ui.scrollArea->setBackgroundRole(QPalette::Dark);
//	paintWidget = otvorene_fronta[subor];
	/*if (!fileName.isEmpty())
		paintWidget[otvorene]->changeImage(fileName);*/

}

