#include "mypainter.h"

using namespace std;

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
		//this->grayscale();
		if(i_typ_grayscale>0) paintWidget.grayscale(i_typ_grayscale);
	}

}

void MyPainter::grayscale()
{
	if (ui.actionGrayscale->isChecked())
	{
		
		QMessageBox msgBox;
		msgBox.setText("Choose algorithm type");
		//msgBox.setInformativeText("Choose algorithm type");
		msgBox.addButton(tr("Average"), QMessageBox::NoRole);
		msgBox.addButton(tr("Weightened"), QMessageBox::NoRole);
		msgBox.addButton(tr("Desaturation"), QMessageBox::NoRole);
		////msgBox.setStandardButtons(QMessageBox::Average | QMessageBox::Discard | QMessageBox::Cancel);
		//msgBox.setDefaultButton(QMessageBox::Save);
		 i_typ_grayscale = msgBox.exec();
		paintWidget.grayscale(i_typ_grayscale);

		/*switch (ret) {
		case 0:
			paintWidget.grayscale();
			break;
		case 1:
			std::thread t0(&PaintWidget::grayscale_vazeny, &paintWidget);
			//paintWidget.grayscale_vazeny();
			t0.join();
			break;

		}*/

		//std::thread t0(&PaintWidget::grayscale, &paintWidget);
		
		
	}
	else
	{
		i_typ_grayscale = -10;
	}
}

