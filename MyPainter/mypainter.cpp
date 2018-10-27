#include "mypainter.h"

MyPainter::MyPainter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.scrollArea->setWidget(&this->paintWidget);
	ui.scrollArea->setBackgroundRole(QPalette::Dark);
}

MyPainter::~MyPainter()
{
	
	/*free(otvoreny);
	otvorene_fronta.clear();*/
}

void MyPainter::ActionOpen()
{
	//otvoreny = new PaintWidget();
	//ui.scrollArea->setWidget(this->otvoreny);
	bool otvorilo = false;

	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "image files (*.png *.jpg *.bmp)");
	if (!fileName.isEmpty())
		 otvorilo = paintWidget.openImage(fileName);
		//otvoreny->openImage(fileName);
		
	if(otvorilo) ui.listWidget->addItem(fileName);
	
}
	
void MyPainter::ActionSave()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), "untitled.png", tr("png Files (*.png)"));
	if (fileName.isEmpty()) {
		return;
	}
	else {
		paintWidget.saveImage(fileName);
	}
}

void MyPainter::EffectClear()
{
	paintWidget.clearImage();
}

void MyPainter::ActionNew()
{
	paintWidget.newImage(800, 600);
}

void MyPainter::ActionLeft()
{
	QMessageBox mbox;
	QElapsedTimer timer;
	timer.start();
	paintWidget.RotateLeft();
	/*QString text = "The operation took " + QString::number(timer.nsecsElapsed() / 1000000.0) + " milliseconds";
	mbox.setText(text);
	mbox.exec();*/
}

void MyPainter::ActionRight()
{
	QMessageBox mbox;
	QElapsedTimer timer;
	timer.start();
	paintWidget.RotateRight();
	/*QString text = "The operation took " + QString::number(timer.nsecsElapsed() / 1000000.0) + " milliseconds";
	mbox.setText(text);
	mbox.exec();*/
}

void MyPainter::zmena_itemu()
{

	QString fileName = ui.listWidget->currentItem()->text();



//	paintWidget = otvorene_fronta[subor];
	if (!fileName.isEmpty())
	{
		paintWidget.changeImage(fileName);
		if (ui.actionGrayscale->isChecked())
		{
			paintWidget.grayscale();
		}
	}

}

void MyPainter::grayscale()
{
	if (ui.actionGrayscale->isChecked())
	{
		paintWidget.grayscale();
	}
}

