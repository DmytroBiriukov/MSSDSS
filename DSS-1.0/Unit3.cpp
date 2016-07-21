//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit3.h"
#include "Unit1.h"
#include "Unit6.h"
#include "Unit7.h"
#include "DBComponents.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TmainForm *mainForm;
//---------------------------------------------------------------------------
__fastcall TmainForm::TmainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TmainForm::Exit1Click(TObject *Sender)
{ Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TmainForm::LoadSystemFile1Click(TObject *Sender)
{
 if(OpenDialog1->Execute())
 { TSystemLayerForm* form=new TSystemLayerForm(Application);
   form->LoadSystemFile(OpenDialog1->FileName);
   form->Show();
 }

}
//---------------------------------------------------------------------------

void __fastcall TmainForm::MSSHE1Click(TObject *Sender)
{
  TSystemLayerForm* form=new TSystemLayerForm(Application);
  form->Show();
}
//---------------------------------------------------------------------------


void __fastcall TmainForm::GeneralCase1Click(TObject *Sender)
{
  TComponentForm* form=new TComponentForm(this->Owner);
  form->Show();
}
//---------------------------------------------------------------------------


void __fastcall TmainForm::N3state1Click(TObject *Sender)
{
  TS3ScomponentForm* S3Scomponentform=new TS3ScomponentForm(this->Owner);
  S3Scomponentform->Show();
}
//---------------------------------------------------------------------------


void __fastcall TmainForm::ComponentsDataBase1Click(TObject *Sender)
{
  ComponentsDBForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::SetConnection1Click(TObject *Sender)
{
  ComponentsDBForm->Connect();
}
//---------------------------------------------------------------------------


void __fastcall TmainForm::Cold1Click(TObject *Sender)
{
 Form6->Show();
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::ActiveRedundancyClick(TObject *Sender)
{
 Form7->Show();        
}
//---------------------------------------------------------------------------

