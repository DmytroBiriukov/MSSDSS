/*------------------------------------------------------------------------------
        This source is developed by Dmitrij Birjukov
        to support various optimization methods of
        discrete optimization in complex systems
------------------------------------------------------------------------------*/

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SwitchDebug.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
using namespace std;
  AnsiString str=ExtractFilePath(Application->ExeName)+"/data/crf/test0.crf";
  ifstream in_stream;   in_stream.open(str.c_str());
  str=ExtractFilePath(Application->ExeName)+"/data/output.log";
  ofstream out_stream;  out_stream.open(str.c_str());
  if(! (in_stream.fail() || out_stream.fail() ))
  { //if(swsys != NULL) delete swsys;
    TSwitchSystem<TExpolynome>* swsys=new TSwitchSystem<TExpolynome>(in_stream);
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
 