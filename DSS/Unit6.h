//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include "DBAccess.hpp"
#include "MemDS.hpp"
#include "MyAccess.hpp"
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>

#include<iostream>
#include<fstream>
#include"mss\utils.h"
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
        TScrollBox *ScrollBox1;
        TMemo *Memo1;
        TPanel *Panel2;
        TImage *Image3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TPanel *Panel3;
        TPanel *Panel1;
        TImage *Image2;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton9;
        TGroupBox *GroupBox4;
        TLabel *Label1;
        TLabel *Label2;
        TDBText *DBText2;
        TDBText *DBText3;
        TGroupBox *GroupBox2;
        TDBGrid *DBGrid1;
        TDBNavigator *DBNavigator1;
        TMyConnection *MyConnection1;
        TMyDataSource *MyDataSource1;
        TMyTable *MyTable1;
        TMyQuery *MyQuery1;
        TMyDataSource *MyDataSource2;
        TSpeedButton *SpeedButton10;
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall SpeedButton9Click(TObject *Sender);
        void __fastcall SpeedButton6Click(TObject *Sender);
        void __fastcall SpeedButton8Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall SpeedButton5Click(TObject *Sender);
        void __fastcall SpeedButton7Click(TObject *Sender);
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall DBNavigator1Click(TObject *Sender,
          TNavigateBtn Button);
private:	// User declarations
        TSwitchSystem<TExpolynome>* swsys;
public:		// User declarations
        __fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
