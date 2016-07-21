//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TComponentForm *ComponentForm;
//---------------------------------------------------------------------------
__fastcall TComponentForm::TComponentForm(TComponent* Owner)
        : TForm(Owner)
{  Image1->Canvas->MoveTo(0,0);
   Image1->Canvas->Pen->Width=2;
   VertexAction=vaDrawing;
   graph=new TSTGraph<TExpolynome>();
   pMetafile = new TMetafile;
   pMetafile->Height=275;
   pMetafile->Width=275;   
}
//---------------------------------------------------------------------------
void __fastcall TComponentForm::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{ if(Button == mbLeft)
  { if(VertexAction==vaDrawing)
    { Image1->Canvas->MoveTo(X, Y);
      Origin = Point(X, Y);
      MovePt = Origin;
      TVarRec tempvar[2] = {X, Y};
      StatusBar1->Panels->Items[0]->Text = Format("Origin: (%d, %d)", tempvar, 2);
      movingIndex=-1;
    }else
    {
   //detect the nearest object and move it with all arrows
      movingIndex=BelongsTo(X, Y);
      TVarRec tempvar[3] = {movingIndex, X, Y};
      StatusBar1->Panels->Items[0]->Text = Format("Moving %d (%d, %d)", tempvar, 3);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TComponentForm::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
  if (VertexAction==vaDrawing)
  {
//DrawShape(Origin, MovePt, pmNotXor);
    MovePt = Point(X, Y);
//DrawShape(Origin, MovePt, pmNotXor);
  }

  TVarRec tempvar[2] = {X, Y};
  StatusBar1->Panels->Items[1]->Text = Format("Current: (%d, %d)", tempvar, 2);

  if(VertexAction==vaMoving && movingIndex >= 0)
  {
   Image1->Canvas->FillRect(TRect(TPoint(0,0), TPoint(Image1->Width, Image1->Height)));
   //Draw(Image1, vertexDeque, arrowDeque, pmNotXor, dtSquare, dtArrow); //pmXor, pmNotXor
   vertexDeque[movingIndex].x=X;
   vertexDeque[movingIndex].y=Y;
   Draw(Image1, vertexDeque, arrowDeque, pmCopy, dtEllipse, dtArrow); //pmXor, pmNotXor
  }
}
//---------------------------------------------------------------------------
void __fastcall TComponentForm::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
if(Button == mbLeft)
{
  if(VertexAction==vaDrawing)
  {
    FinalDrawShape(Origin, Point(X, Y), pmCopy);
  }
  if(VertexAction==vaMoving)
  {
   //detect the X Y to drop the object
   TVarRec tempvar[3] = {movingIndex, X, Y};
   StatusBar1->Panels->Items[0]->Text = Format("Droped %d on (%d, %d)", tempvar, 3);

   Image1->Canvas->FillRect(TRect(TPoint(0,0), TPoint(Image1->Width, Image1->Height)));
   //Draw(Image1, vertexDeque, arrowDeque, pmNotXor, dtSquare, dtArrow); //pmXor, pmNotXor
   vertexDeque[movingIndex].x=X;
   vertexDeque[movingIndex].y=Y;
   Draw(Image1, vertexDeque, arrowDeque, pmCopy, dtEllipse, dtArrow); //pmXor, pmNotXor
   movingIndex=-1;
//   VertexAction=vaDrawing;
  }
}  

}
//---------------------------------------------------------------------------
int TComponentForm::BelongsTo(int x, int y)
{ int cnt=vertexDeque.GetCount();
  int index=-1;
  double dist=sqrt(pow(1000,2)+pow(1000,2));
  for(int k=0;k<cnt;k++)
     {int x1=vertexDeque[k].x;
      int y1=vertexDeque[k].y;
      double dist1=sqrt(pow(x-x1,2)+pow(y-y1,2));
      if(dist1<dist){dist=dist1; index=k;}
     }
  return index;
}

//---------------------------------------------------------------------------
void __fastcall TComponentForm::FinalDrawShape(TPoint a, TPoint b, TPenMode AMode)
{   /*
    Image1->Canvas->Pen->Mode = AMode;
    Image1->Canvas->Pen->Style= psSolid;
    Image1->Canvas->Pen->Color= clBlack;
    Image1->Canvas->Pen->Width=1;
    Image1->Canvas->Brush->Style= bsSolid;
      */
//    pCanvas->Draw(0,0,pMetafile);

    pCanvas = new TMetafileCanvas(pMetafile, 0);
    pCanvas->Pen->Mode = AMode;
    pCanvas->Pen->Style= psSolid;
    pCanvas->Pen->Color= clBlack;
    pCanvas->Pen->Width=1;
    pCanvas->Brush->Style= bsSolid;
    switch (DrawingTool)
    {
           case dtLine : {
                //add new arrow
                int ind1=BelongsTo(a.x, a.y);
                int ind2=BelongsTo(b.x, b.y);
                if(vertexDeque.GetCount()>1 && ind1!=ind2)
                { int x0, x1, y0, y1;
                  double hyp;


                  x0=vertexDeque[ind1].x;
                  y0=vertexDeque[ind1].y;



                  
                 int cnt=StringGrid1->RowCount;
                 StringGrid1->RowCount++;
                 StringGrid1->Cells[0][cnt]="( "+IntToStr(ind1+1)+" -> "+IntToStr(ind2+1)+" )";

                  x1=vertexDeque[ind2].x;
                  y1=vertexDeque[ind2].y;

                  hyp=sqrt(pow(x0-x1,2)+pow(y0-y1,2));

                  a.x=x0 + rds*(x1-x0)/hyp;
                  a.y=y0 + rds*(y1-y0)/hyp;
                  b.x=x1 - rds*(x1-x0)/hyp;
                  b.y=y1 - rds*(y1-y0)/hyp;

                  arrowDeque.InsertNode(TTransition(ind1,ind2,0.005));
//DrawArrow(a.x, a.y, b.x, b.y, Image->Canvas->MoveTo, Image->Canvas->LineTo)
/*
                  Image1->Canvas->MoveTo(a.x, a.y);
                  Image1->Canvas->LineTo(b.x, b.y);
*/
                  pCanvas->MoveTo(a.x, a.y);
                  pCanvas->LineTo(b.x, b.y);
                  double alpha= M_PI / 12;
                  double dX=(b.x-a.x);
                  double dY=(b.y-a.y);
                  double phi;
                  if(!dY) phi=M_PI_2;
                          else phi=atan(dX/dY);
                  double t1=phi+alpha;
                  double t2=phi-alpha;
                  if(dY>=0)
                     {
        x0=b.x-ard*sin(t1);
        y0=b.y-ard*cos(t1);
        x1=b.x-ard*sin(t2);
        y1=b.y-ard*cos(t2);
                     }else
                     {
        x0=b.x+ard*sin(t1);
        y0=b.y+ard*cos(t1);
        x1=b.x+ard*sin(t2);
        y1=b.y+ard*cos(t2);
                     }
/*
                  Image1->Canvas->MoveTo(b.x, b.y);
                  Image1->Canvas->LineTo(x0, y0);
                  Image1->Canvas->MoveTo(b.x, b.y);
                  Image1->Canvas->LineTo(x1, y1);
*/
                  pCanvas->MoveTo(b.x, b.y);
                  pCanvas->LineTo(x0, y0);
                  pCanvas->MoveTo(b.x, b.y);
                  pCanvas->LineTo(x1, y1);

                }


                break;
           }
           case dtEllipse :
           {
                //add new vertex
                unsigned int cnt=vertexDeque.GetCount();
                StringGrid2->RowCount++;
                StringGrid2->Cells[0][cnt+1]=IntToStr(cnt+1);
                vertexDeque.InsertNode(TVertex(cnt,1.0, IntToStr(cnt).c_str(), a.x, a.y));
                a.x=(a.x/20)*20;
                a.y=(a.y/20)*20;
                vertexDeque[cnt].x=a.x;
                vertexDeque[cnt].y=a.y;
/*
                Image1->Canvas->Ellipse(a.x-rds, a.y-rds, a.x+rds, a.y+rds);
                Image1->Canvas->TextOutA(a.x-rds/2, a.y-rds/2, IntToStr(cnt+1).c_str());
                */
                pCanvas->Ellipse(a.x-rds, a.y-rds, a.x+rds, a.y+rds);
                pCanvas->TextOutA(a.x-rds/2, a.y-rds/2, IntToStr(cnt+1).c_str());
                break;
           }
    }
    pCanvas->Draw(0,0,pMetafile);
   delete pCanvas;
  // this->Image1->Canvas->Draw(0,0,pMetafile);
 Draw(Image1, vertexDeque, arrowDeque, pmCopy, dtEllipse, dtArrow);
}
//---------------------------------------------------------------------------
void __fastcall TComponentForm::DrawShape(TPoint TopLeft, TPoint BottomRight, TPenMode AMode)
{
    Image1->Canvas->Pen->Mode = AMode;
    Image1->Canvas->Pen->Style= psDot;
    Image1->Canvas->Pen->Color= clGray;
    Image1->Canvas->Brush->Style= bsClear;
    switch (DrawingTool)
    {
           case dtLine :
           {
                Image1->Canvas->MoveTo(TopLeft.x, TopLeft.y);
                Image1->Canvas->LineTo(BottomRight.x, BottomRight.y);
                break;
           }
           case dtEllipse :
           {
                Image1->Canvas->Ellipse(TopLeft.x-20, TopLeft.y-20, TopLeft.x+20, TopLeft.y+20);
                break;
           }
    }
}
void __fastcall TComponentForm::SpeedButton1Click(TObject *Sender)
{
DrawingTool = dtEllipse;
 VertexAction=vaDrawing;
   Screen->Cursor= crArrow;
}
//---------------------------------------------------------------------------
void __fastcall TComponentForm::SpeedButton2Click(TObject *Sender)
{
DrawingTool = dtLine;
 VertexAction=vaDrawing;
   Screen->Cursor= crArrow;        
}
//---------------------------------------------------------------------------
void __fastcall TComponentForm::MoveButtonClick(TObject *Sender)
{
if(VertexAction==vaMoving)
 {VertexAction=vaDrawing;
  Screen->Cursor= crArrow;
  //SpeedButton1->Down=true;
  //SpeedButton2->Down=true;
  MoveButton->Down=false;
  MoveButton->Flat=true;
  SpeedButton1->Enabled=true;
  SpeedButton2->Enabled=true;
  Screen->Cursor= crArrow;
 }else
 {VertexAction=vaMoving;
   //SpeedButton1->Down=false;
  //SpeedButton2->Down=false;
  MoveButton->Down=true;
    MoveButton->Flat=false;
  SpeedButton1->Enabled=false;
  SpeedButton2->Enabled=false;
 Screen->Cursor= crHandPoint;
 }
        
}
//---------------------------------------------------------------------------
void __fastcall TComponentForm::FormCreate(TObject *Sender)
{ //Cells[int ACol][int ARow]
 StringGrid1->Cells[0][0]="transition";
 StringGrid1->Cells[1][0]="alpha";
 StringGrid1->Cells[2][0]="10^- betta";
 StringGrid2->Cells[0][0]="state #";
 StringGrid2->Cells[1][0]="description";
}
//---------------------------------------------------------------------------
void __fastcall TComponentForm::SpeedButton3Click(TObject *Sender)
{
/*  //Draw(Image1, vertexDeque, arrowDeque, pmNotXor);
   Draw(Image1, vertexDeque, arrowDeque, pmCopy);
*/
   bool validData=true;
   unsigned int p=arrowDeque.GetCount();
   for(unsigned int i=0;i<p;i++)
   try
   {
//     ShowMessage(" lambda "+IntToStr(i)+" is "+StringGrid1->Cells[1][i+1]+" pow10 "+StringGrid1->Cells[2][i+1]);
     arrowDeque[i].lambda= (double) StrToInt( StringGrid1->Cells[1][i+1])/pow10(StrToInt(StringGrid1->Cells[2][i+1]));
   }
   catch (Exception &exception)
   {   validData=false;
       Application->ShowException(&exception);
       ShowMessage("Wrong lambda "+IntToStr(i)+" input data format");
       arrowDeque[i].lambda=0.0;
   }
   p=vertexDeque.GetCount();
   for(unsigned int i=0;i<p;i++)
   try
   { vertexDeque[i].pr0= StrToFloat( StringGrid2->Cells[2][i+1]) ;
   }
   catch (Exception &exception)
   {   validData=false;
       Application->ShowException(&exception);
       ShowMessage("Wrong pr0 "+IntToStr(i)+" input data format");
       vertexDeque[i].pr0=0.0;
   }

   if(validData)
   {
     Drawing2STGraph(&vertexDeque, &arrowDeque, graph);
     graph->eval();
//     delete graph;
   }
}
//---------------------------------------------------------------------------

void TComponentForm::refresh()
{ if(graph!=NULL) delete graph;
  vertexDeque.free();
  arrowDeque.free();
  StringGrid1->RowCount=1;
  StringGrid2->RowCount=1;
  Image1->Refresh();

}
void __fastcall TComponentForm::SpeedButton5Click(TObject *Sender)
{
OpenDialog1->FilterIndex=2;

if(OpenDialog1->Execute())
{
 AnsiString str=OpenDialog1->FileName;
 using namespace std;
 ifstream stream;
 stream.open(str.c_str());
 this->refresh();
 graph=new TSTGraph<TExpolynome>(stream);
 STGraph2Drawing(&vertexDeque, &arrowDeque, graph);
 Draw(Image1, vertexDeque, arrowDeque, pmCopy, dtEllipse, dtArrow);
 stream.close();

 int verNo=vertexDeque.GetCount();
 int arrNo=arrowDeque.GetCount();
 for(int i=0;i<verNo;i++)
 {
  StringGrid2->RowCount++;
  StringGrid2->Cells[0][i+1]=IntToStr(vertexDeque[i].state+1);
  StringGrid2->Cells[2][i+1]=FloatToStr(graph->PrF(i).value(0.0));
 }

 for(int i=0;i<arrNo;i++)
 {
  StringGrid1->RowCount++;
  StringGrid1->Cells[0][i+1]="( "+IntToStr(arrowDeque[i].vout+1)+" -> "+IntToStr(arrowDeque[i].vin+1)+" )";
  double b=arrowDeque[i].lambda;
  int pw=0;
  while(fabs(b)<1.0){b*=10.0; pw++;}
  StringGrid1->Cells[1][i+1]=FloatToStr(b);
  StringGrid1->Cells[2][i+1]=IntToStr(pw);
 }
}
}
//---------------------------------------------------------------------------

void __fastcall TComponentForm::SpeedButton10Click(TObject *Sender)
{
OpenDialog1->FilterIndex=4;
if(OpenDialog1->Execute() && ExtractFileExt(OpenDialog1->FileName)==AnsiString(".crf"))
{AnsiString str=OpenDialog1->FileName;
 using namespace std;
 ifstream stream1;
 stream1.open(str.c_str());
 TSwitchSystem<TExpolynome>* swsys=new TSwitchSystem<TExpolynome>(stream1);
 unsigned short w[]={0,1};
 swsys->eval(2,w);
 stream1.close();
 ofstream stream2;
 stream2.open(str.c_str());
 swsys->printf(stream2);
 stream2.close();
 delete swsys;
}

}
//---------------------------------------------------------------------------

void __fastcall TComponentForm::SpeedButton7Click(TObject *Sender)
{
  Memo1->Clear();        
}
//---------------------------------------------------------------------------

void __fastcall TComponentForm::SpeedButton4Click(TObject *Sender)
{
 Memo1->SelectAll();
 Memo1->CopyToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TComponentForm::SpeedButton8Click(TObject *Sender)
{ AnsiString FileName=ExtractFilePath(Application->ExeName)+"/data/output.log";
  Memo1->Lines->LoadFromFile(FileName);
}
//---------------------------------------------------------------------------

void __fastcall TComponentForm::SpeedButton12Click(TObject *Sender)
{

// Save to stg-File
  SaveDialog1->FilterIndex=1;
  if(SaveDialog1->Execute())
  { AnsiString str=SaveDialog1->FileName;
    using namespace std;
    ofstream stream;
    stream.open(str.c_str());
    graph->printf(stream);
    stream.close();
    Memo1->Lines->LoadFromFile(SaveDialog1->FileName);
  }

}
//---------------------------------------------------------------------------

void __fastcall TComponentForm::FormClose(TObject *Sender, TCloseAction &Action)
{  Action=caFree;
}
//---------------------------------------------------------------------------


void __fastcall TComponentForm::SpeedButton13Click(TObject *Sender)
{
  this->Close();
}
//---------------------------------------------------------------------------


void __fastcall TComponentForm::FormDestroy(TObject *Sender)
{
  delete graph;        
}
//---------------------------------------------------------------------------

void __fastcall TComponentForm::SpeedButton6Click(TObject *Sender)
{
// Save to m-File
//  SaveDialog1->FilterIndex=2;
//  if( SaveDialog1->Execute())
//  {  AnsiString str=SaveDialog1->FileName;

     AnsiString str=ExtractFilePath(Application->ExeName)+"/data/output.log";

     double to=0.0, ts=5000;
     using namespace std;
     ofstream out_stream;
     out_stream.open(str.c_str());
     if(! out_stream.fail())
     {
      out_stream<<"t="<<to<<":.1:"<<ts<<";\n";
      unsigned int sCount=graph->stateCount();
      for(unsigned int s=0; s<sCount; s++)
      { out_stream<<"P"<<s<<"= ";
        graph->GetNode(s).GetNode().expolynome2MatLab(out_stream);
        out_stream<<";\n";
        out_stream<<"Po"<<s<<"= ";
        graph->PrF(s).expolynome2MatLab(out_stream);
        out_stream<<";\n";
      }
      out_stream<<"P=";
      for(unsigned int s=0; s<sCount; s++) out_stream<<"P"<<s<<"+";
      out_stream<<"0.0;\n PL=[";
      for(unsigned int s=0; s<sCount; s++) out_stream<<"P"<<s<<"; ";
      out_stream<<" P]; \n myplot=plot(t,PL,'-k') \n box off \n axis(["<<to<<" "<<ts<<" 0.0 1.0]) \n grid on \n axis manual";
      out_stream.close();
      Memo1->Lines->LoadFromFile(str);
     }
//  }  
}
//---------------------------------------------------------------------------

void __fastcall TComponentForm::SpeedButton9Click(TObject *Sender)
{  // Save to TeX-File
//  SaveDialog1->FilterIndex=3;
//  if(SaveDialog1->Execute())
//  { AnsiString str=SaveDialog1->FileName;

    AnsiString str=ExtractFilePath(Application->ExeName)+"/data/output.log";

    using namespace std;
    ofstream stream;
    stream.open(str.c_str());
    if(! stream.fail())
    {
      for(int i=0;i<graph->stateCount();i++)
      { stream<<"$P_"<<i<<"=";
        graph->GetNode(i).GetNode().expolynome2TeX(stream); stream<<"$\n";
      }
      stream.close();
      Memo1->Lines->LoadFromFile(str);
    }  
//  }
}
//---------------------------------------------------------------------------


