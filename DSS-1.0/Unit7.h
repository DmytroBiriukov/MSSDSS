//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Dialogs.hpp>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include"mss\mss.h"
#include"mss\utils.h"
#include"mss\exponome.h"
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TImage *Image2;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *MoveButton;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton12;
        TSpeedButton *SpeedButton13;
        TSpeedButton *SpeedButton9;
        TScrollBox *ScrollBox1;
        TMemo *Memo1;
        TPanel *Panel2;
        TImage *Image3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TPanel *Panel3;
        TOpenDialog *OpenDialog1;
        void __fastcall SpeedButton13Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
