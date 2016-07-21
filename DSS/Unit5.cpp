//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBAccess"
#pragma link "MemDS"
#pragma link "MyAccess"
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm5::FormShow(TObject *Sender)
{
  MyConnection1->Connect();
  MyTable1->Active=true;
  MyQuery1->Close();
  MyQuery1->Params->Items[0]->AsInteger=MyDataSource1->DataSet->Fields->Fields[0]->AsInteger;
  MyQuery1->Execute();
  MyQuery1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::BitBtn1Click(TObject *Sender)
{ MyConnection1->Disconnect();
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormClose(TObject *Sender, TCloseAction &Action)
{
  Action=caFree;        
}
//---------------------------------------------------------------------------
