//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
#include <vcl\Clipbrd.hpp>
#include"mss\mss.h"
#include"mss\utils.h"
#include <ImgList.hpp>
#include <Dialogs.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TComponentForm : public TForm
{
__published:	// IDE-managed Components
        TScrollBox *ScrollBox1;
        TScrollBox *ScrollBox2;
        TImageList *ImageList1;
        TStringGrid *StringGrid1;
        TSaveDialog *SaveDialog1;
        TOpenDialog *OpenDialog1;
        TEdit *Edit1;
        TEdit *Edit2;
        TStringGrid *StringGrid2;
        TMemo *Memo1;
        TPanel *Panel2;
        TPanel *Panel3;
        TImage *Image1;
        TStatusBar *StatusBar1;
        TPanel *Panel1;
        TImage *Image2;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *MoveButton;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton12;
        TSpeedButton *SpeedButton13;
        TSpeedButton *SpeedButton9;
        TImage *Image3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        void __fastcall Image1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall MoveButtonClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall SpeedButton5Click(TObject *Sender);
        void __fastcall SpeedButton10Click(TObject *Sender);
        void __fastcall SpeedButton7Click(TObject *Sender);
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall SpeedButton8Click(TObject *Sender);
        void __fastcall SpeedButton12Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall SpeedButton13Click(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall SpeedButton6Click(TObject *Sender);
        void __fastcall SpeedButton9Click(TObject *Sender);
private:
        bool Drawing;
        bool Moving;
        int movingIndex;
        TPoint Origin, MovePt;
        TDrawingTool DrawingTool;
        TVertexAction VertexAction;
        AnsiString CurrentFile;
        TMetafile *pMetafile ;
        TMetafileCanvas *pCanvas ;        
        int Xpos;
        int Ypos;
        TmyDeque<TVertex> vertexDeque;
        TmyDeque<TTransition> arrowDeque;
        TSTGraph<TExpolynome>* graph;
        int BelongsTo(int x, int y);
        void refresh();
public:
        void __fastcall DrawShape(TPoint TopLeft, TPoint BottomRight, TPenMode AMode);
        void __fastcall FinalDrawShape(TPoint a, TPoint b, TPenMode AMode);
        __fastcall TComponentForm(TComponent* Owner);
};
/*
template<class T>
void Draw(TImage* img, TSTGraph<T>* graph)
{
 unsigned int m=graph->stateCount();

}
*/

void Draw(TImage* img, TmyDeque<TVertex>& vertexDeque, TmyDeque<TTransition>& arrowDeque, TPenMode AMode, unsigned short vertexdtType, unsigned short arrowdtType )
{//pmCopy, pmXor, pmNotXor
 img->Canvas->Pen->Mode = AMode;
 img->Canvas->Pen->Style= psSolid;
 img->Canvas->Pen->Color= clBlack;
 img->Canvas->Pen->Width=1;
 img->Canvas->Brush->Style= bsSolid;
 unsigned int m=vertexDeque.GetCount();
 for(unsigned int i=0;i<m;i++)
 { int x=vertexDeque[i].x;
   int y=vertexDeque[i].y;
   if(vertexdtType == dtEllipse)
   img->Canvas->Ellipse(x-rds, y-rds, x+rds, y+rds);
   else
   if(vertexdtType == dtSquare)
   img->Canvas->Rectangle(x-rds, y-rds, x+rds, y+rds);

   img->Canvas->TextOutA(x-rds/2, y-rds/2, IntToStr(i+1).c_str());
 }
 m=arrowDeque.GetCount();
 for(unsigned int i=0;i<m;i++)
 { int x0=vertexDeque[arrowDeque[i].vout].x;
   int y0=vertexDeque[arrowDeque[i].vout].y;
   int x1=vertexDeque[arrowDeque[i].vin].x;
   int y1=vertexDeque[arrowDeque[i].vin].y;
   double  hyp=sqrt(pow(x0-x1,2)+pow(y0-y1,2));
   int rds1=rds;
   if(vertexdtType == dtSquare) rds1+=4;
   int ax=x0 + rds1*(x1-x0)/hyp;
   int ay=y0 + rds1*(y1-y0)/hyp;
   img->Canvas->MoveTo(ax, ay);
   int bx=x1 - rds1*(x1-x0)/hyp;
   int by=y1 - rds1*(y1-y0)/hyp;
   img->Canvas->LineTo(bx, by);
   double alpha= M_PI / 12;
   double dX=(bx-ax);
   double dY=(by-ay);
   double phi;
   if(!dY) phi=M_PI_2;
     else phi=atan(dX/dY);
   double t1=phi+alpha;
   double t2=phi-alpha;
   if(dY>=0)
   {
        x0=bx-ard*sin(t1);
        y0=by-ard*cos(t1);
        x1=bx-ard*sin(t2);
        y1=by-ard*cos(t2);
   }else
   {
        x0=bx+ard*sin(t1);
        y0=by+ard*cos(t1);
        x1=bx+ard*sin(t2);
        y1=by+ard*cos(t2);
   }
   img->Canvas->MoveTo(bx, by);
   img->Canvas->LineTo(x0, y0);
   img->Canvas->MoveTo(bx, by);
   img->Canvas->LineTo(x1, y1);
 }
}
//---------------------------------------------------------------------------
//extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
