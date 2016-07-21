//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBAccess"
#pragma link "MemDS"
#pragma link "MyAccess"
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm6::SpeedButton3Click(TObject *Sender)
{
  using namespace std;
  AnsiString str=ExtractFilePath(Application->ExeName)+"/data/crf/test0.crf";
  ifstream in_stream;   in_stream.open(str.c_str());
  str=ExtractFilePath(Application->ExeName)+"/data/output.log";
  ofstream out_stream;  out_stream.open(str.c_str());
  if(! (in_stream.fail() || out_stream.fail() ))
  { //if(swsys != NULL) delete swsys;
    swsys=new TSwitchSystem<TExpolynome>(in_stream);
    unsigned short kappa[]={0,1};
    unsigned short lambda=2;
    swsys->eval(lambda,kappa);
//    swsys->printf(out_stream);
//    delete swsys;
    out_stream.close();
    in_stream.close();
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm6::SpeedButton9Click(TObject *Sender)
{
    AnsiString str=ExtractFilePath(Application->ExeName)+"/data/output.log";

    using namespace std;
    ofstream stream;
    stream.open(str.c_str());
    if(! stream.fail())
    {
      for(int i=0;i<swsys->stateCount();i++)
      { stream<<"$P_"<<i<<"=";
        swsys->Pi(i).expolynome2TeX(stream); stream<<"$\n";
      }
      stream.close();
      Memo1->Lines->LoadFromFile(str);
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm6::SpeedButton6Click(TObject *Sender)
{
    AnsiString str=ExtractFilePath(Application->ExeName)+"/data/output.log";
    double to=0.0, ts=5000;
    using namespace std;
    ofstream stream;
    stream.open(str.c_str());
    if(! stream.fail())
    { stream<<"t="<<to<<":.1:"<<ts<<";\n";
      for(int i=0;i<swsys->versionCount();i++)
      { stream<<"\n % version #"<<i+1<<" characteristics";
        for(int s=0;s<swsys->stateCount();s++)
        { stream<<"\n rho_"<<i+1<<"_"<<s+1<<"=";
          swsys->Rho(i,s).expolynome2MatLab(stream);
        }
        stream<<"\n P_"<<i<<"=[";
        for(int s=0;s<swsys->stateCount();s++)
        { if(s)stream<<"; ";
          stream<<"rho_"<<i+1<<"_"<<s+1;
        }
        stream<<"]; ";
        stream<<"\n myplot=plot(t,P_"<<i<<",'-k');  box on;  axis(["<<to<<" "<<ts<<" 0.0 1.0]); grid off; xlabel('\\itt')";
        for(int s=0;s<swsys->stateCount();s++)
        { stream<<"\n p0_"<<i<<"_"<<s<<"=rho_"<<i+1<<"_"<<s+1<<"(find(t=="<<(2250-500*s)<<"));";
          stream<<"\n s=strcat(' \\fontname{times}{\\it\\rho} _{{\\iti}"<<i+1<<"} ^"<<s+1<<"({\\itt})');";
          stream<<"\n X=["<<(2250-500*s)<<", 2750]; Y=[p0_"<<i<<"_"<<s<<" , "<<(0.55+0.12*s) <<"];";
          stream<<"\n text(2750, "<<(0.55+0.12*s)<<",s,'Fontsize',16); line(X,Y);";
        }
        stream<<"\n  print -dmeta comp_version_"<<i+1<<"\n\n";

      }

      for(int i=0;i<swsys->getLambda()+1;i++)
      { stream<<"\npi_"<<i<<"=";
        swsys->Pi(i).expolynome2MatLab(stream);
      }
      stream<<"\nPi_sum=";
      for(int i=0;i<swsys->getLambda()+1;i++) stream<<"pi_"<<i<<"+";
      stream<<"0.0;\n PiL=[";
      for(int i=0;i<swsys->getLambda()+1;i++) stream<<"pi_"<<i<<"; ";
      stream<<" Pi_sum]; \n myplot=plot(t,PiL,'-k') \n box off \n axis(["<<to<<" "<<ts<<" 0.0 1.0]) \n grid on \n axis manual";
      stream<<"\n print -dmeta pi";

      for(int i=0;i<swsys->stateCount();i++)
      { stream<<"\np_"<<i+1<<"=";
        swsys->P(i).expolynome2MatLab(stream);
      }
      stream<<"\nP_sum=";
      for(int i=0;i<swsys->stateCount();i++) stream<<"p_"<<i+1<<"+";
      stream<<"0.0;\n PL=[";
      for(int i=0;i<swsys->stateCount();i++) stream<<"p_"<<i+1<<"; ";
      stream<<" P_sum]; \n myplot=plot(t,PL,'-k') \n box off \n axis(["<<to<<" "<<ts<<" 0.0 1.0]) \n grid on \n axis manual";
      stream<<"\n print -dmeta p";

      stream.close();
      Memo1->Lines->LoadFromFile(str);
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm6::SpeedButton8Click(TObject *Sender)
{
  AnsiString str=ExtractFilePath(Application->ExeName)+"/data/output.log";
  Memo1->Lines->LoadFromFile(str);
}
//---------------------------------------------------------------------------


void __fastcall TForm6::FormShow(TObject *Sender)
{
  MyConnection1->Connect();
  MyTable1->Active=true;
  MyQuery1->Close();
  MyQuery1->Params->Items[0]->AsInteger=MyDataSource1->DataSet->Fields->Fields[0]->AsInteger;
  MyQuery1->Execute();
  MyQuery1->Open();        
}
//---------------------------------------------------------------------------







void __fastcall TForm6::SpeedButton5Click(TObject *Sender)
{
  this->Close();        
}
//---------------------------------------------------------------------------


void __fastcall TForm6::SpeedButton7Click(TObject *Sender)
{
  Memo1->Clear();        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::SpeedButton4Click(TObject *Sender)
{
 Memo1->SelectAll();
 Memo1->CopyToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::DBNavigator1Click(TObject *Sender,
      TNavigateBtn Button)
{
  MyQuery1->Close();
  MyQuery1->Params->Items[0]->AsInteger=MyDataSource1->DataSet->Fields->Fields[0]->AsInteger;
  MyQuery1->Execute();
  MyQuery1->Open();
        
}
//---------------------------------------------------------------------------

