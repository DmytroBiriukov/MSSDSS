//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm7::SpeedButton13Click(TObject *Sender)
{
  this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::SpeedButton3Click(TObject *Sender)
{
  OpenDialog1->FilterIndex=1;
  if(OpenDialog1->Execute())
  { AnsiString str=OpenDialog1->FileName;
    using namespace std;
    ifstream in_stream;
    in_stream.open(str.c_str());
// argv[1]="examples/exampleRA.dat";
// argv[1]="examples/exampleRB.dat";
// argv[1]="examples/exampleRC.dat";
//  argv[1]="examples/exampleRD6.dat";
// argv[1]="examples/exampleA.dat";
// argv[1]="examples/exampleB.dat";
// argv[1]="examples/exampleC.dat";
//  argv[1]="examples/exampleD.dat";
//  argv[2]="examples/result1.tex";

     ofstream out_stream;  out_stream.open("data/output.log");
     if(! (in_stream.fail() || out_stream.fail()))
     { TMSSystem<TExpolynome> ExampleSystem;
       ExampleSystem.scanf(in_stream);
       ExampleSystem.eval();
       for(int j=0;j<ExampleSystem.ComponentCount();j++)
         out_stream<<ExampleSystem(j);
//    out_stream<<"\n System Performance Level="<<ExampleSystem.ExpectedPerformance();

       TDrawParams p;
       p.height=100; p.width=200; p.Xscale=5000; p.n=5;
/*
     for(int j=0;j<ExampleSystem.ComponentCount();j++)
        { out_stream<<"\n \n \n Component No."<<j<<"\n \n \n";
          exponomicDraw2TeX(out_stream, p, ExampleSystem[j].GetNode());
        }
*/
       out_stream<<"\n \n \n ";
       exponomicDraw2TeX(out_stream, p, ExampleSystem[ExampleSystem.ComponentCount()-1].GetNode());
       out_stream.close();
       in_stream.close();
     }
  }
}
//---------------------------------------------------------------------------

