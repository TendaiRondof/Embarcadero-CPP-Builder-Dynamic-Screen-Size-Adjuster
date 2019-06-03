//Dimensions at Design time
float DesinWidth =  400;
float DesinHeight = 800;

void __fastcall TForm1::FormResize(TObject *Sender)
{
	TControl *current_comp;
	TPresentedTextControl *dummyTextComp;

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

			dummyTextComp = dynamic_cast<TPresentedTextControl*>(current_comp);

			if(dummyTextComp != 0)
				dummyTextComp->TextSettings->Font->Size *= (XFactor+YFactor)/2;

			current_comp->Repaint();
		}
	}

	DesinWidth = Form1->ClientWidth;
	DesinHeight = Form1->ClientHeight;
}