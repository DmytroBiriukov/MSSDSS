//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBAccess.hpp"
#include "MemDS.hpp"
#include "MyAccess.hpp"
#include <Buttons.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
        TMyConnection *MyConnection1;
        TMyDataSource *MyDataSource1;
        TMyTable *MyTable1;
        TMyQuery *MyQuery1;
        TMyDataSource *MyDataSource2;
        TGroupBox *GroupBox4;
        TLabel *Label1;
        TLabel *Label2;
        TDBText *DBText2;
        TDBText *DBText3;
        TGroupBox *GroupBox2;
        TDBGrid *DBGrid1;
        TDBNavigator *DBNavigator1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn1;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
