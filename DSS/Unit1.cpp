//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSystemLayerForm *SystemLayerForm;
//---------------------------------------------------------------------------
__fastcall TSystemLayerForm::TSystemLayerForm(TComponent* Owner): TForm(Owner)
{ Image1->Canvas->MoveTo(0,0);
  Image1->Canvas->Pen->Width=2;
  VertexAction=vaDrawing;
}

void TSystemLayerForm::LoadSystemFile(AnsiString fileName)
{ Caption=fileName;
  using namespace std;
  ifstream in_stream;
  in_stream.open(fileName.c_str());
  if(! in_stream.fail())
  {
//1-6
    MSSHE.scanf(in_stream);
//7
// Allocation on drawing
// Xi, Yi
    int n=MSSHE.ComponentCount();
    X=new unsigned int[n];
    Y=new unsigned int[n];
    for(int i=0;i<n;i++)
    { in_stream>>X[i];
      in_stream>>Y[i];
      TVertex v;
      v.x=X[i];
      v.y=Y[i];
      vertexDeque.InsertNode(v);
    }

    for(int i=0;i<n;i++)
    { int vout= MSSHE[i].GetNextCount();
      for(int j=0;j<vout;j++)
      { int vi= MSSHE[i].GetOutNode(j).GetIndex();
        TTransition t; t.vout=i; t.vin= vi;
        arrowDeque.InsertNode(t ) ;
      }
    }

    Draw(Image1, vertexDeque, arrowDeque, pmCopy, dtSquare, dtArrow);

  }

  in_stream.close();
}

void __fastcall TSystemLayerForm::SpeedButton2Click(TObject *Sender)
{ DrawingTool = dtLine;
  VertexAction=vaDrawing;
  Screen->Cursor= crArrow;
}
void __fastcall TSystemLayerForm::SpeedButton1Click(TObject *Sender)
{ DrawingTool = dtEllipse;
  VertexAction=vaDrawing;
  Screen->Cursor= crArrow;
}
//---------------------------------------------------------------------------
void __fastcall TSystemLayerForm::Image1MouseDown(TObject *Sender,
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
  }else
  { compIndex=BelongsTo(X, Y);
    /*
    TComponentForm* form=new TComponentForm(this->Owner);
    form->Show();
    */

}
}
//---------------------------------------------------------------------------
void __fastcall TSystemLayerForm::Image1MouseMove(TObject *Sender, TShiftState Shift,
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
   Draw(Image1, vertexDeque, arrowDeque, pmCopy, dtSquare, dtArrow); //pmXor, pmNotXor
  }
}
//---------------------------------------------------------------------------
void __fastcall TSystemLayerForm::Image1MouseUp(TObject *Sender, TMouseButton Button,
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
   Draw(Image1, vertexDeque, arrowDeque, pmCopy, dtSquare, dtArrow); //pmXor, pmNotXor
   movingIndex=-1;
//   VertexAction=vaDrawing;
  }
}
}
//---------------------------------------------------------------------------
int TSystemLayerForm::BelongsTo(int x, int y)
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
void __fastcall TSystemLayerForm::FinalDrawShape(TPoint a, TPoint b, TPenMode AMode)
{
    Image1->Canvas->Pen->Mode = AMode;
    Image1->Canvas->Pen->Style= psSolid;
    Image1->Canvas->Pen->Color= clBlack;
    Image1->Canvas->Pen->Width=1;
    Image1->Canvas->Brush->Style= bsSolid;
    switch (DrawingTool)
    { case dtLine :
      { int ind1=BelongsTo(a.x, a.y);
        int ind2=BelongsTo(b.x, b.y);
        //add new arrow
        if(vertexDeque.GetCount()>1 && ind1 != ind2)
        { arrowDeque.InsertNode(TTransition(ind1,ind2,0.005));
          Image1->Canvas->FillRect(TRect(TPoint(0,0), TPoint(Image1->Width, Image1->Height)));
          Draw(Image1, vertexDeque, arrowDeque, pmCopy, dtSquare, dtArrow);
        /*
          int x0, x1, y0, y1;
          double hyp;
          x0=vertexDeque[ind1].x;
          y0=vertexDeque[ind1].y;
          x1=vertexDeque[ind2].x;
          y1=vertexDeque[ind2].y;
          if(abs(x0-x1)>abs(y0-y1))
          { if(x0<x1)
            { a.x=x0+rds;
              b.x=x1-rds;
            } else
            { a.x=x0-rds;
              b.x=x1+rds;
            }
            a.y=y0;
            b.y=y1;
          }else
          { if(y0<y1)
            { a.y=y0+rds;
              b.y=y1-rds;
            } else
            { a.y=y0-rds;
              b.y=y1+rds;
            }
            a.x=x0;
            b.x=x1;
          }

          Image1->Canvas->MoveTo(a.x, a.y);
          Image1->Canvas->LineTo(b.x, b.y);

          double alpha= M_PI / 12;
          double dX=(b.x-a.x);
          double dY=(b.y-a.y);
          double phi;
          if(!dY) phi=M_PI_2;
          else phi=atan(dX/dY);
          double t1=phi+alpha;
          double t2=phi-alpha;
          if(dY>=0)
          { x0=b.x-ard*sin(t1);
            y0=b.y-ard*cos(t1);
            x1=b.x-ard*sin(t2);
            y1=b.y-ard*cos(t2);
          }else
          { x0=b.x+ard*sin(t1);
            y0=b.y+ard*cos(t1);
            x1=b.x+ard*sin(t2);
            y1=b.y+ard*cos(t2);
          }
          Image1->Canvas->MoveTo(b.x, b.y);
          Image1->Canvas->LineTo(x0, y0);
          Image1->Canvas->MoveTo(b.x, b.y);
          Image1->Canvas->LineTo(x1, y1);

          */

        }
        break;
      }
      case dtEllipse :
      { //add new vertex
        unsigned int cnt=vertexDeque.GetCount();
        vertexDeque.InsertNode(TVertex(cnt,1.0, IntToStr(cnt).c_str(), a.x, a.y));
        a.x=(a.x/20)*20;
        a.y=(a.y/20)*20;
        vertexDeque[cnt].x=a.x;
        vertexDeque[cnt].y=a.y;
        Image1->Canvas->Rectangle(a.x-rds, a.y-rds, a.x+rds, a.y+rds);
        Image1->Canvas->TextOutA(a.x-rds/2, a.y-rds/2, IntToStr(cnt+1).c_str());
        break;
      }
    }
}
//---------------------------------------------------------------------------
void __fastcall TSystemLayerForm::DrawShape(TPoint TopLeft, TPoint BottomRight, TPenMode AMode)
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
//---------------------------------------------------------------------------
void __fastcall TSystemLayerForm::MoveButtonClick(TObject *Sender)
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
/*
void __fastcall TFTAForm::Save1Click(TObject *Sender)
{
  if (CurrentFile != EmptyStr){
    Image->Picture->SaveToFile(CurrentFile);
  }
  else{
   SaveAs1Click(Sender);
  }
}

void __fastcall TFTAForm::SaveAs1Click(TObject *Sender)
{
  if (SaveDialog1->Execute()){
    CurrentFile = SaveDialog1->FileName;
    if(SaveDialog1->FilterIndex==2)
    {Caption="save to tex";
     SaveToTex(ofstream(CurrentFile.c_str()));
    }
    else Save1Click(Sender);
  }
}


void __fastcall TFTAForm::Copy1Click(TObject *Sender)
{
  Clipboard()->Assign(Image1->Picture);
}
*/
//---------------------------------------------------------------------------
/*
void __fastcall TSTGForm::Print1Click(TObject *Sender)
{
    unsigned int BitmapInfoSize, BitmapImageSize;
    long DIBWidth, DIBHeight;
    PChar BitmapImage;
    Windows::PBitmapInfo BitmapInfo;
    Graphics::TBitmap *Bitmap;

    Printer()->BeginDoc();
    Bitmap = new Graphics::TBitmap();
    Bitmap->Assign(Image->Picture);
    GetDIBSizes(Bitmap->Handle, BitmapInfoSize, BitmapImageSize);
    BitmapInfo  = (PBitmapInfo) new char[BitmapInfoSize];
    BitmapImage = (PChar) new char [BitmapImageSize];
    GetDIB(Bitmap->Handle, 0, BitmapInfo, BitmapImage);
    DIBWidth  = BitmapInfo->bmiHeader.biWidth;
    DIBHeight = BitmapInfo->bmiHeader.biHeight;
    StretchDIBits(Printer()->Canvas->Handle,
                0, 0, DIBWidth, DIBHeight,
                0, 0, DIBWidth, DIBHeight,
                BitmapImage, BitmapInfo,
                DIB_RGB_COLORS, SRCCOPY);
    delete [] BitmapImage;
    delete [] BitmapInfo;
    delete Bitmap;

    Printer()->EndDoc();
}
//---------------------------------------------------------------------
void __fastcall TFormMain::SetPenStyle(TObject *Sender)
{
    if (Sender == SolidPen){
       Image->Canvas->Pen->Style = psSolid;
    }
    else if (Sender == DashPen){
            Image->Canvas->Pen->Style = psDash;
    }
    else if (Sender == DotPen){
         Image->Canvas->Pen->Style = psDot;
    }
    else if (Sender == DashDotPen){
         Image->Canvas->Pen->Style = psDashDot;
    }
    else if (Sender == DashDotDotPen){
         Image->Canvas->Pen->Style = psDashDotDot;
    }
    else if (Sender == ClearPen){
         Image->Canvas->Pen->Style = psClear;
    }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::PenColorClick(TObject *Sender)
{
  ColorDialog1->Color = Image->Canvas->Pen->Color;
  if (ColorDialog1->Execute()){
    Image->Canvas->Pen->Color = ColorDialog1->Color;
  }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::PenSizeChange(TObject *Sender)
{
  Image->Canvas->Pen->Width = PenWidth->Position;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::SetBrushStyle(TObject *Sender)
{
    if (Sender == SolidBrush){
       Image->Canvas->Brush->Style = bsSolid;
    }
    else if (Sender == ClearBrush){
         Image->Canvas->Brush->Style = bsClear;
    }
    else if (Sender == HorizontalBrush){
         Image->Canvas->Brush->Style = bsHorizontal;
    }
    else if (Sender == VerticalBrush){
         Image->Canvas->Brush->Style = bsVertical;
    }
    else if (Sender == FDiagonalBrush){
         Image->Canvas->Brush->Style = bsFDiagonal;
    }
    else if (Sender == BDiagonalBrush){
         Image->Canvas->Brush->Style = bsBDiagonal;
    }
    else if (Sender == CrossBrush){
         Image->Canvas->Brush->Style = bsCross;
    }
    else if (Sender == DiagCrossBrush){
         Image->Canvas->Brush->Style = bsDiagCross;
    }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::BrushColorClick(TObject *Sender)
{
  ColorDialog1->Color = Image->Canvas->Brush->Color;
  if (ColorDialog1->Execute()){
    Image->Canvas->Brush->Color = ColorDialog1->Color;
  }
}

//---------------------------------------------------------------------------
void __fastcall TSTGForm::SpeedButton1Click(TObject *Sender)
{
  Graphics::TBitmap *Bitmap1 = new Graphics::TBitmap();
  Graphics::TBitmap *Bitmap2 = new Graphics::TBitmap();
  try
  {
    Bitmap1->LoadFromFile(ExtractFilePath(Application->ExeName)+"lambda.bmp");
    Bitmap2->Assign(Bitmap1);     // Copy Bitmap1 into Bitmap2
    Bitmap2->Dormant();           // Free up GDI resources
    Bitmap2->FreeImage();         // Free up Memory.
    Image->Canvas->Draw(20,20,Bitmap2);  // Note that previous calls don't lose the image

    Bitmap2->Monochrome = true;
    Image->Canvas->Draw(80,80,Bitmap2);
    Image->Canvas->Font->Name="Times";
    Image->Canvas->Font->Size=8;
    Image->Canvas->TextOutA(100,90,"12");
    Image->Canvas->Font->Size=12;
    Image->Canvas->TextOutA(116,80,"=12.34");
    Bitmap2->ReleaseHandle();       // This will actually lose the bitmap;
  }
  catch (...)
  {
    MessageBeep(0);
  }
  delete Bitmap1;
  delete Bitmap2;

}
//---------------------------------------------------------------------------
*/
void __fastcall TSystemLayerForm::FormClose(TObject *Sender, TCloseAction &Action)
{ Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TSystemLayerForm::Close1Click(TObject *Sender)
{ this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TSystemLayerForm::Image3Click(TObject *Sender)
{ if(SavePictureDialog1->Execute()) Image1->Picture->SaveToFile(SavePictureDialog1->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TSystemLayerForm::SpeedButton5Click(TObject *Sender)
{
  if(SaveDialog1->Execute())
  { using namespace std;
    ofstream stream;
    stream.open(SaveDialog1->FileName.c_str());
    if(! stream.fail())
    {MSSHE.printf(stream);
     int n=MSSHE.ComponentCount();
     for(int i=0;i<n;i++) stream<<vertexDeque[i].x<<" "<<vertexDeque[i].y<<endl;

     ShowMessage("Model saved to file "+SaveDialog1->FileName);
    }else ShowMessage("Cant save to file "+SaveDialog1->FileName);
    stream.close();
  }
}
//---------------------------------------------------------------------------
void __fastcall TSystemLayerForm::PopupMenu1Popup(TObject *Sender)
{
    TVarRec tempvar[1] = {compIndex};
    StatusBar1->Panels->Items[0]->Text = Format("Accesing comp # %d", tempvar, 1);
}
//---------------------------------------------------------------------------
void __fastcall TSystemLayerForm::SpeedButton6Click(TObject *Sender)
{
  this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TSystemLayerForm::SpeedButton7Click(TObject *Sender)
{
  if(OpenDialog1->Execute())
  {
    this->LoadSystemFile(OpenDialog1->FileName);
  }

}
//---------------------------------------------------------------------------

