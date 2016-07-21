//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <SysUtils.hpp>

#include"mss\mss.h"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TS3ScomponentForm : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TEdit *Edit5;
        TEdit *Edit6;
        TEdit *Edit7;
        TEdit *Edit8;
        TBitBtn *BitBtn1;
        TEdit *Edit9;
        TMemo *Memo1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TSaveDialog *SaveDialog1;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BitBtn3Click(TObject *Sender);
private:	// User declarations
 float to, ts;
 float lambda32;
 float lambda31;
 bool validData;

 TExpolynome po3;
 TExpolynome po2;
 TExpolynome po1;

 TExpolynome p3;
 TExpolynome p2;
 TExpolynome p1;


public:		// User declarations
        __fastcall TS3ScomponentForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TS3ScomponentForm *S3ScomponentForm;
//---------------------------------------------------------------------------
#endif
