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
#include "Unit2.h"
#include <Menus.hpp>
#include <Graphics.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <ImgList.hpp>
#include <jpeg.hpp>
#include <ostream> 
//---------------------------------------------------------------------------
class TSystemLayerForm : public TForm
{
__published:
        TScrollBox *ScrollBox1;
        TImage *Image1;
        TStatusBar *StatusBar1;
        TImage *Image2;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton1;
        TSpeedButton *MoveButton;
        TSaveDialog *SaveDialog1;
        TSavePictureDialog *SavePictureDialog1;
        TSpeedButton *SpeedButton5;
        TPopupMenu *PopupMenu1;
        TMenuItem *Attachcomponent1;
        TMenuItem *Redundancy1;
        TMenuItem *Cold1;
        TMenuItem *Hot1;
        TMenuItem *Subsystem1;
        TImageList *ImageList1;
        TSpeedButton *SpeedButton6;
        TOpenDialog *OpenDialog1;
        TSpeedButton *SpeedButton7;
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall MoveButtonClick(TObject *Sender);
        void __fastcall Image1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall SpeedButton5Click(TObject *Sender);
        void __fastcall PopupMenu1Popup(TObject *Sender);
        void __fastcall SpeedButton6Click(TObject *Sender);
        void __fastcall SpeedButton7Click(TObject *Sender);
private:
        bool Drawing;
        bool Moving;
        int movingIndex;
        TPoint Origin, MovePt;
        TDrawingTool DrawingTool;
        TVertexAction VertexAction;
        AnsiString CurrentFile;
        int Xpos;
        int Ypos;
        unsigned int* X;
        unsigned int* Y;
        TmyDeque<TVertex> vertexDeque;
        TmyDeque<TTransition> arrowDeque;
        int compIndex;
        int BelongsTo(int x, int y);

        TMSSystem<TExpolynome> MSSHE;

public:
        void __fastcall DrawShape(TPoint TopLeft, TPoint BottomRight, TPenMode AMode);
        void __fastcall FinalDrawShape(TPoint a, TPoint b, TPenMode AMode);
        void LoadSystemFile(AnsiString);
        __fastcall TSystemLayerForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
//extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
