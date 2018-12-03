#include "mypainter.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

MyPainter::MyPainter(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MyPainterClass)
{
	p_histogramWidget = new ScribbleArea();
	paintWidget = new PaintWidget(ui, p_histogramWidget);
	
	

	ui->setupUi(this);
	ui->scrollArea->setWidget(this->paintWidget);
	ui->scrollArea->setBackgroundRole(QPalette::Dark);

	
	//ui->scrollAreaHistogram->setWidget(&this->histogramWidget);
	ui->scrollAreaHistogram->setWidget(this->p_histogramWidget);
	ui->scrollAreaHistogram->setBackgroundRole(QPalette::Dark);
	//histogramWidget.clearImage();
}

MyPainter::~MyPainter()
{
	
	/*free(otvoreny);
	otvorene_fronta.clear();*/
}

/*
void MyPainter:::resizeEvent(QResizeEvent* event)
{
	QMainWindow::resizeEvent(event);
	// Your code here.
}*/


void MyPainter::ActionOpen()
{
	//otvoreny = new PaintWidget();
	//ui.scrollArea->setWidget(this->otvoreny);
	bool otvorilo = false;

	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "image files (*.png *.jpg *.bmp)");
	if (!fileName.isEmpty())
		 otvorilo = paintWidget->openImage(fileName);
		//otvoreny->openImage(fileName);
		
	if(otvorilo) ui->listWidget->addItem(fileName);

	if (i_typ_grayscale >= 0) {
		paintWidget->grayscale(i_typ_grayscale);
	}
	
}
	
void MyPainter::ActionSave()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), "untitled.png", tr("png Files (*.png)"));
	if (fileName.isEmpty()) {
		return;
	}
	else {
		paintWidget->saveImage(fileName);
	}
}

void MyPainter::EffectClear()
{
	paintWidget->clearImage();
}

void MyPainter::ActionNew()
{
	paintWidget->newImage(800, 600);
}

void MyPainter::ActionLeft()
{
	QMessageBox mbox;
	QElapsedTimer timer;
	timer.start();
	paintWidget->RotateLeft();
	/*QString text = "The operation took " + QString::number(timer.nsecsElapsed() / 1000000.0) + " milliseconds";
	mbox.setText(text);
	mbox.exec();*/
}

void MyPainter::ActionRight()
{
	QMessageBox mbox;
	QElapsedTimer timer;
	timer.start();
	paintWidget->RotateRight();
	/*QString text = "The operation took " + QString::number(timer.nsecsElapsed() / 1000000.0) + " milliseconds";
	mbox.setText(text);
	mbox.exec();*/
}

void MyPainter::zmena_itemu()
{

	QString fileName = ui->listWidget->currentItem()->text();



//	paintWidget = otvorene_fronta[subor];
	if (!fileName.isEmpty())
	{
		paintWidget->changeImage(fileName);
		//paintWidget.update();
		if (i_typ_grayscale >= 0) { 
			//std::thread t0(&PaintWidget::grayscale, &paintWidget, i_typ_grayscale);
				paintWidget->grayscale(i_typ_grayscale);
				//t0.join();
		}
		//paintWidget.update();
	}

}

void MyPainter::vymaz_item()
{

	

	ui->listWidget->removeItemWidget(ui->listWidget->currentItem());


	
	paintWidget->closeImage();
		

}

void MyPainter::grayscale()
{
	if (ui->actionGrayscale->isChecked())
	{
		
		QMessageBox msgBox;
		msgBox.setText("Choose algorithm type for grayscaling");
		//msgBox.setInformativeText("Choose algorithm type");
		//QPixmap exportSuccess(":/ikonky/resources/icon_grayscale1.jpg");
		//msgBox.setIconPixmap(exportSuccess);
		msgBox.setWindowTitle("Grayscale type");
		msgBox.addButton(tr("Average"), QMessageBox::NoRole);
		msgBox.addButton(tr("Weightened"), QMessageBox::NoRole);
		msgBox.addButton(tr("Desaturation"), QMessageBox::NoRole);
		////msgBox.setStandardButtons(QMessageBox::Average | QMessageBox::Discard | QMessageBox::Cancel);
		//msgBox.setDefaultButton(QMessageBox::Save);
		 i_typ_grayscale = msgBox.exec();
		paintWidget->grayscale(i_typ_grayscale);

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

void MyPainter::grayscale_ave()
{
	if (ui->listWidget->count() < 1) {
		QMessageBox hlaska;
		hlaska.setWindowTitle("Varovanie");
		hlaska.setText("Nie je otvoren ziadny obrazok");
		hlaska.exec();
		ui->actionGrayscale->setChecked(false);
	}
	else {

		if (ui->actionGrayscale->isChecked())
		{
			paintWidget->grayscale_uncheck();
			paintWidget->grayscale(0);

			ui->actionGrayscale_Desaturation->setChecked(false);
			ui->actionGrayscale_Weightened->setChecked(false);

		}
		else
		{
			paintWidget->grayscale_uncheck();
		}
	}
}

void MyPainter::grayscale_des()
{
	if (ui->listWidget->count() < 1) {
		QMessageBox hlaska;
		hlaska.setWindowTitle("Varovanie");
		hlaska.setText("Nie je otvoren ziadny obrazok");
		hlaska.exec();
		ui->actionGrayscale_Desaturation->setChecked(false);
	}
	else {
		if (ui->actionGrayscale_Desaturation->isChecked())
		{
			paintWidget->grayscale_uncheck();
			paintWidget->grayscale(2);
			ui->actionGrayscale->setChecked(false);
			ui->actionGrayscale_Weightened->setChecked(false);

		}
		else
		{
			paintWidget->grayscale_uncheck();
		}
	}
}

void MyPainter::grayscale_wei()
{
	if (ui->listWidget->count() < 1) {
		QMessageBox hlaska;
		hlaska.setWindowTitle("Varovanie");
		hlaska.setText("Nie je otvoren ziadny obrazok");
		hlaska.exec();
		ui->actionGrayscale_Weightened->setChecked(false);
	}
	else {
		if (ui->actionGrayscale_Weightened->isChecked())
		{
			paintWidget->grayscale_uncheck();
			paintWidget->grayscale(1);
			ui->actionGrayscale_Desaturation->setChecked(false);
			ui->actionGrayscale->setChecked(false);

		}
		else
		{
			paintWidget->grayscale_uncheck();
		}
	}
}

