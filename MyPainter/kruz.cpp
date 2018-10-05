#include "kruz.h"

kruz::kruz(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

kruz::~kruz()
{

}

void kruz::farba() {



	color = QColorDialog::getColor(Qt::black, this, "Text Color", QColorDialog::DontUseNativeDialog);


}

void kruz::kresli() {

	
	
	int n = ui.spinBox->value();
	int r = ui.spinBox_2->value();
	bool dda;
	if (ui.radioButton->isChecked()) dda = true;
	if (ui.radioButton_2->isChecked()) dda = false;

	paintWidget->kruznicakresli(n, r, dda, color);

	
	
}
void kruz::kreslikruznicu() {



	int r = ui.spinBox_3->value();
	
	paintWidget->kruznicabresham(r, color);



}