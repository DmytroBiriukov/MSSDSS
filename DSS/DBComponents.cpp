//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "DBComponents.h"
#include "Unit4.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBAccess"
#pragma link "MemDS"
#pragma link "MyAccess"
#pragma link "DBAccess"
#pragma link "MemDS"
#pragma resource "*.dfm"
TComponentsDBForm *ComponentsDBForm;
//---------------------------------------------------------------------------
__fastcall TComponentsDBForm::TComponentsDBForm(TComponent* Owner)
        : TForm(Owner)
{ Hide();
}
//---------------------------------------------------------------------------

void __fastcall TComponentsDBForm::DBNavigator1Click(TObject *Sender,
      TNavigateBtn Button)
{
  MyQuery1->Close();
  MyQuery1->Params->Items[0]->AsInteger=MyDataSource1->DataSet->Fields->Fields[0]->AsInteger;
  MyQuery1->Execute();
  MyQuery1->Open();
  MyQuery2->Close();
  MyQuery2->Params->Items[0]->AsInteger=MyDataSource1->DataSet->Fields->Fields[0]->AsInteger;
  MyQuery2->Execute();
  MyQuery2->Open();
  MyQuery4->Close();
  MyQuery4->Params->Items[0]->AsInteger=MyDataSource1->DataSet->Fields->Fields[0]->AsInteger;
  MyQuery4->Execute();
  MyQuery4->Open();
  MyQuery5->Close();
  MyQuery5->Params->Items[0]->AsInteger=MyDataSource1->DataSet->Fields->Fields[0]->AsInteger;
  MyQuery5->Execute();
  MyQuery5->Open();

}
//---------------------------------------------------------------------------

void __fastcall TComponentsDBForm::BitBtn1Click(TObject *Sender)
{
  MyQuery3->SQL->Clear();
  MyQuery3->SQL->Add("INSERT INTO state (idx, title, description, type) VALUES (:F1, :F2, :F3, :F4);");
  try
  { MyQuery3->Params->Items[0]->AsInteger=StrToInt(LabeledEdit2->Text);
  }
  catch (Exception &exception)
  { MyQuery3->Params->Items[0]->AsInteger=0;
    ShowMessage("State index isn't defined! Default value will be inserted to data base.");
  }

  MyQuery3->Params->Items[1]->AsString=LabeledEdit1->Text;
  MyQuery3->Params->Items[2]->AsString=LabeledEdit3->Text;
  MyQuery3->Params->Items[3]->AsString=ComboBox1->Text;

  MyQuery3->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TComponentsDBForm::BitBtn4Click(TObject *Sender)
{
  MyQuery3->SQL->Clear();
  MyQuery3->SQL->Add("INSERT INTO characteristic (title, measure) VALUES (:F1, :F2);");
  MyQuery3->Params->Items[0]->AsString=LabeledEdit4->Text;
  MyQuery3->Params->Items[1]->AsString=LabeledEdit5->Text;
  MyQuery3->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TComponentsDBForm::BitBtn2Click(TObject *Sender)
{
  MyQuery3->SQL->Clear();
  MyQuery3->SQL->Add("INSERT INTO compStates (IDstate, IDcomponent) VALUES (:F1, :F2);");
  MyQuery3->Params->Items[0]->AsInteger=MyDataSource4->DataSet->Fields->Fields[0]->AsInteger;
  MyQuery3->Params->Items[1]->AsInteger=MyDataSource1->DataSet->Fields->Fields[0]->AsInteger;
  MyQuery3->Execute();
}
//---------------------------------------------------------------------------


void __fastcall TComponentsDBForm::BitBtn5Click(TObject *Sender)
{
  MyQuery3->SQL->Clear();
  MyQuery3->SQL->Add("INSERT INTO resourceUsage (IDcharacteristic, IDcomponent, value) VALUES (:F1, :F2, :F3);");
  MyQuery3->Params->Items[0]->AsInteger=MyDataSource5->DataSet->Fields->Fields[0]->AsInteger;
  MyQuery3->Params->Items[1]->AsInteger=MyDataSource1->DataSet->Fields->Fields[0]->AsInteger;
  try
  { MyQuery3->Params->Items[2]->AsFloat=StrToFloat(LabeledEdit6->Text);
  }
  catch (Exception &exception)
  { MyQuery3->Params->Items[2]->AsFloat=0.0;
    ShowMessage("Resource usage value isn't defined correctly!");
  }
  MyQuery3->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TComponentsDBForm::BitBtn7Click(TObject *Sender)
{
  TS3ScomponentForm* S3Scomponentform=new TS3ScomponentForm(this->Owner);
  S3Scomponentform->Show();
}
//---------------------------------------------------------------------------

void __fastcall TComponentsDBForm::BitBtn8Click(TObject *Sender)
{
  TComponentForm* form=new TComponentForm(this->Owner);
  form->Show();
}
//---------------------------------------------------------------------------



void TComponentsDBForm::Connect()
{
  MyConnection1->Connect();
  MyTable1->Active=true;
  MyQuery1->Close();
  MyQuery1->Params->Items[0]->AsInteger=MyDataSource1->DataSet->Fields->Fields[0]->AsInteger;
  MyQuery1->Execute();
  MyQuery1->Open();
  MyQuery2->Close();
  MyQuery2->Params->Items[0]->AsInteger=MyDataSource1->DataSet->Fields->Fields[0]->AsInteger;
  MyQuery2->Execute();
  MyQuery2->Open();
  MyQuery4->Close();
  MyQuery4->Params->Items[0]->AsInteger=MyDataSource1->DataSet->Fields->Fields[0]->AsInteger;
  MyQuery4->Execute();
  MyQuery4->Open();
  MyQuery5->Close();
  MyQuery5->Params->Items[0]->AsInteger=MyDataSource1->DataSet->Fields->Fields[0]->AsInteger;
  MyQuery5->Execute();
  MyQuery5->Open();
}
