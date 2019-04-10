//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Forms::TScreen* Screen= new Forms::TScreen(Owner);
	TSize ScreenSize = Screen->Size();
	TControl *current_comp;
	float XFactor,YFactor;

	XFactor = float(ScreenSize.Width)/Form1->ClientWidth;
	YFactor = float(ScreenSize.Height)/Form1->ClientHeight;

	Label1->Text = "W:"+String(XFactor);
	Label2->Text = "H:"+String(YFactor);

	for (int comp=0; comp < Form1->ComponentCount; comp++) {
		current_comp = dynamic_cast<TControl*>(Form1->Components[comp]);
		if (current_comp == 0) {
			current_comp->Position->X *= XFactor;
			current_comp->Position->Y *= YFactor;
			current_comp->Repaint();
		}
	}
	delete Screen;
}
//---------------------------------------------------------------------------
