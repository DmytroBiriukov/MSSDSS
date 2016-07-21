//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TS3ScomponentForm *S3ScomponentForm;
//---------------------------------------------------------------------------
__fastcall TS3ScomponentForm::TS3ScomponentForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TS3ScomponentForm::BitBtn1Click(TObject *Sender)
{
 validData=true;

 TPolynome poly;
 double d1[]={0.0};
 poly.init(d1, 1);

 try
 { poly[0]= (double)StrToFloat(Edit3->Text);
   po3.init(&poly, &d1[0],1);
   poly[0]= (double)StrToFloatDef(Edit2->Text,0.0);
   po2.init(&poly, &d1[0],1);
   poly[0]= (double)StrToFloatDef(Edit1->Text,0.0);
   po1.init(&poly, &d1[0],1);
   lambda32= (float) (StrToInt(Edit5->Text) / pow10( StrToInt(Edit7->Text)) );
   lambda31= (float) (StrToInt(Edit6->Text) / pow10( StrToInt(Edit8->Text)) );
   to=StrToFloat(Edit4->Text);
   ts=StrToFloat(Edit9->Text);
 }
 catch (Exception &exception)
 {   validData=false;
     Application->ShowException(&exception);
     ShowMessage("Wrong input data format");
 }

 if(equalOne(po3+po2+po1) && validData)
 {  ShowMessage("valid data");
    p3=po3;
    p3*=(double)(exp(-(lambda32+lambda31)*to));

    TExpolynome tmp;
    tmp.init(1);
    tmp.setb(-(lambda32+lambda31),0);
    poly[0]=1.0;
    tmp.seta(poly,0);

    p3*=tmp;

    tmp=po3; tmp-=p3; tmp*=( 1/(lambda32+lambda31) );
    p2=po2;
    p2+=(lambda32*tmp);
    p1=po1;
    p1+=(lambda31*tmp);

    ofstream out_stream;  out_stream.open("data/outstream.dat");
    if(! out_stream.fail())
    { out_stream<<"t="<<to<<":.1:"<<ts<<";\n";
      out_stream<<"P3= ";
      p3.expolynome2MatLab(out_stream);
      out_stream<<";\n";
      out_stream<<"P2= ";
      p2.expolynome2MatLab(out_stream);
      out_stream<<";\n";
      out_stream<<"P1= ";
      p1.expolynome2MatLab(out_stream);
      out_stream<<";\n";
      out_stream<<"Po3= ";
      po3.expolynome2MatLab(out_stream);
      out_stream<<";\n";
      out_stream<<"Po2= ";
      po2.expolynome2MatLab(out_stream);
      out_stream<<";\n";
      out_stream<<"Po1= ";
      po1.expolynome2MatLab(out_stream);
      out_stream<<";\n P=P1+P2+P3; \n PL=[P1; P2; P3; P]; \n myplot=plot(t,PL,'-k') \n box off \n axis(["<<to<<" "<<ts<<" 0.0 1.0]) \n grid on \n axis manual \n print -dmeta myplot";

      out_stream.close();
      Memo1->Lines->LoadFromFile(AnsiString("data/outstream.dat"));
    }

    BitBtn3->Enabled=true;

 } else  ShowMessage("invalid data");
}
//---------------------------------------------------------------------------
void __fastcall TS3ScomponentForm::BitBtn2Click(TObject *Sender)
{
  this->Close();        
}
//---------------------------------------------------------------------------

void __fastcall TS3ScomponentForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TS3ScomponentForm::BitBtn3Click(TObject *Sender)
{
  if(SaveDialog1->Execute())
  {
      ofstream out_stream;
      out_stream.open(SaveDialog1->FileName.c_str());
      if(! out_stream.fail())
      {
        out_stream<<"3\n 0 1 100 180 ";
        po3.expolynome2MatLab(out_stream);
        out_stream<<"\n 0 1 100 100 ";
        po2.expolynome2MatLab(out_stream);
        out_stream<<"\n 2 0 40 140 ";
        po1.expolynome2MatLab(out_stream);
        out_stream<<"\n 2 "<<lambda31<<"\n 2 "<<lambda32<<"\n 0 "<<lambda31<<" 1 "<<lambda32;
        out_stream<<"\n 1 ";
        p1.expolynome2MatLab(out_stream);
        out_stream<<"\n";
        p2.expolynome2MatLab(out_stream);
        out_stream<<"\n";
        p3.expolynome2MatLab(out_stream);

        out_stream.close();
//        Memo1->Lines->LoadFromFile(SaveDialog1->FileName);
    }

  }
}
//---------------------------------------------------------------------------

