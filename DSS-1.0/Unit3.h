//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Dialogs.hpp>
#include <ImgList.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TmainForm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Data1;
        TMenuItem *LoadSystemFile1;
        TMenuItem *Exit1;
        TMenuItem *N1;
        TMenuItem *CreateSystemStructure1;
        TMenuItem *CreateComponentFile1;
        TMenuItem *Models1;
        TMenuItem *Monotone1;
        TMenuItem *Binary1;
        TMenuItem *MultyState1;
        TMenuItem *S3S1;
        TMenuItem *Generate1;
        TMenuItem *SingleUnit1;
        TMenuItem *Redundancy1;
        TMenuItem *ActiveRedundancy;
        TMenuItem *Cold1;
        TMenuItem *ReliabilityOptimization1;
        TMenuItem *Redundancy2;
        TMenuItem *Maintenance1;
        TOpenDialog *OpenDialog1;
        TMenuItem *N2;
        TImageList *ImageList1;
        TMenuItem *ActiveNversionRedundancy1;
        TMenuItem *ColdstandbyRedundancy1;
        TMenuItem *S3SStructureRedundancy1;
        TMenuItem *DynamicRedundancy1;
        TMenuItem *MSSHE1;
        TMenuItem *MonotoneMSS1;
        TMenuItem *MonotoneBinarystateSystem1;
        TMenuItem *Systemwith3stateComponents1;
        TMenuItem *GeneralCase1;
        TMenuItem *Binarystate1;
        TMenuItem *MonotoneMS1;
        TMenuItem *N3state1;
        TTable *Table1;
        TMenuItem *ComponentsDataBase1;
        TMenuItem *SetConnection1;
        TMenuItem *Properties1;
        TMenuItem *Encription1;
        TMenuItem *ComponentsData1;
        TMenuItem *Disconnect1;
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall LoadSystemFile1Click(TObject *Sender);
        void __fastcall MSSHE1Click(TObject *Sender);
        void __fastcall GeneralCase1Click(TObject *Sender);
        void __fastcall N3state1Click(TObject *Sender);
        void __fastcall ComponentsDataBase1Click(TObject *Sender);
        void __fastcall SetConnection1Click(TObject *Sender);
        void __fastcall Cold1Click(TObject *Sender);
        void __fastcall ActiveRedundancyClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TmainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmainForm *mainForm;
//---------------------------------------------------------------------------
#endif
