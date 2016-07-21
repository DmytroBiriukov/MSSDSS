//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>


#include <vcl.h>
#include <printers.hpp>
#include <Clipbrd.hpp>
#include <ComCtrls.hpp>
#include<list>
#include"mss\mss.h"

struct TGraphNodeInfo
{ AnsiString title;
  AnsiString hint;
  AnsiString imgfile;
  TColor color;         //{clGray; clLtGray; clMedGray; clRed; clTeal; clWhite; clYellow; ...}
  int height;
  int width;
  int left;
  int top;
  TWinControl* parent;
  TCursor cursor;       //{crDefault; crArrow; crHandPoint; crMultiDrag}
};

class TGraphNode: public TImage
{private:
        TGraphNodeInfo settings;
 public:
    void __fastcall OnStartDrag(TObject *Sender,
      TDragObject *&DragObject){Canvas->Brush->Color=clGray;};
    void __fastcall OnEndDrag(TObject *Sender, TObject *Target,
      int X, int Y) { Left+=X; Top+=Y; Canvas->Brush->Color=clRed; };
    void __fastcall OnDragDrop(TObject *Sender, TObject *Target,
      int X, int Y) { Left+=X; Top+=Y;};
    void __fastcall OnDragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept){ Accept=true; };
void __fastcall OnClick(TObject *Sender)
{ //  Picture->OnChange();     Repaint();  Canvas->Refresh();
}
void __fastcall OnDblClick(TObject *Sender)
{ //  Picture->OnChange();     Repaint();  Canvas->Refresh();
}
void __fastcall OnMouseDown(TObject* Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
//enum TMouseButton { mbLeft, mbRight, mbMiddle };
  /*   The TShiftState type is used by key-event and mouse-event handlers
ssShift	        The Shift key is held down.
ssAlt	        The Alt key is held down.
ssCtrl	        The Ctrl key is held down.
ssLeft	        The left mouse button is held down.
ssRight	        The right mouse button is held down.
ssMiddle	The middle mouse button is held down.
ssDouble	The mouse was double-clicked.
  */
 // Canvas->Brush->Bitmap->LoadFromFile("img/and.bmp");
}
        __fastcall TGraphNode(TComponent* AOwner, TGraphNodeInfo in): TImage(Owner)
{   DragMode=dmAutomatic;
    SetAutoSize(false);
    Enabled=true;
    Parent=in.parent;
    Left=in.left;
    Top=in.top;
    Canvas->Pen->Style= psSolid;
    Canvas->Pen->Color= clBlack;
    Canvas->Pen->Width=2;
//
    Canvas->Brush->Color=in.color;
    Height=in.height;
    Width=in.width;
    Cursor=in.cursor;

    Picture->LoadFromFile(in.imgfile);
//    Canvas->TextOutA(10,10, in.title);
    Visible=true;
};
};
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TPanel *Panel2;
        TScrollBox *ScrollBox1;
        TImage *Image1;
        TStatusBar *StatusBar1;
        TSpeedButton *MoveButton;
        void __fastcall Panel2MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Panel2DragOver(TObject *Sender, TObject *Source,
          int X, int Y, TDragState State, bool &Accept);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall Image1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall MoveButtonClick(TObject *Sender);
private:
        //actions
        bool Drawing;
        bool Moving;
        int movingIndex;
        TPoint Origin, MovePt;
        TDrawingTool DrawingTool;
        AnsiString CurrentFile;
int Xpos;
int Ypos;
std::list<TGraphNode*> node_list;

public:
void __fastcall DrawShape(TPoint TopLeft, TPoint BottomRight, TPenMode AMode);
void __fastcall FinalDrawShape(TPoint a, TPoint b, TPenMode AMode);
        __fastcall TForm1(TComponent* Owner);
};
void __fastcall TForm1::Panel2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   if(Button==mbRight)
  { Xpos=X; Ypos=Y;
    Caption="right click";
    TGraphNodeInfo inf;
    inf.title="1";
    inf.imgfile="img/and.bmp";
    inf.hint="new component";
    inf.height=40;
    inf.width=40;
    inf.left=Xpos;
    inf.top=Ypos;
    inf.color=clWhite;
    inf.cursor=crHandPoint;
    inf.parent=Panel2;
    TGraphNode* sp=new TGraphNode(Panel2, inf);
    node_list.push_front(sp);
  } else
  if(Button==mbLeft )
  { //Xpos=X; Ypos=Y;        && Shift==ssLeft
    Caption="dragging";
  }  else
  if(Button==mbLeft)
  {   Caption="left click";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel2DragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept)
{
  if (Source->InheritsFrom(__classid(TImage)))
   { Accept = true;
     TImage* tmp=new TImage(this); tmp=(TImage*)Source;
     tmp->Left=X; tmp->Top=Y;
   }        
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
