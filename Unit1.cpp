//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;

float DesinWidth;
float DesinHeight;

void define_size(void){
	DesinWidth = 360;
	DesinHeight = 740;
}
#pragma startup define_size


//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	TControl *current_comp;

	Label1->Text = Form1->ClientWidth;
	Label2->Text = DesinWidth;

	float XFactor,YFactor;

	XFactor = Form1->ClientWidth/DesinWidth;
	YFactor = Form1->ClientHeight/DesinHeight;

	for (int comp=0; comp < Form1->ComponentCount; comp++) {
		current_comp = dynamic_cast<TControl*>(Form1->Components[comp]);
		if (current_comp != 0) {
			current_comp->Position->X *= XFactor;
			current_comp->Position->Y *= YFactor;
			current_comp->Width *= XFactor;
			current_comp->Height *= YFactor;
			current_comp->Repaint();
		}
	}
}
//---------------------------------------------------------------------------
