object Form5: TForm5
  Left = 377
  Top = 209
  BorderStyle = bsSingle
  Caption = 'Attach Single Unit from Database'
  ClientHeight = 340
  ClientWidth = 607
  Color = clBtnFace
  DefaultMonitor = dmMainForm
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox4: TGroupBox
    Left = 16
    Top = 8
    Width = 577
    Height = 81
    Caption = 'General Properties'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 24
      Width = 20
      Height = 13
      Caption = 'Title'
    end
    object Label2: TLabel
      Left = 16
      Top = 48
      Width = 24
      Height = 13
      Caption = 'Type'
    end
    object DBText2: TDBText
      Left = 64
      Top = 24
      Width = 457
      Height = 17
      DataField = 'title'
      DataSource = MyDataSource1
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText3: TDBText
      Left = 64
      Top = 48
      Width = 241
      Height = 17
      DataField = 'type'
      DataSource = MyDataSource1
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object GroupBox2: TGroupBox
    Left = 16
    Top = 96
    Width = 577
    Height = 153
    Caption = 'Component'#39's States'
    TabOrder = 1
    object DBGrid1: TDBGrid
      Left = 8
      Top = 24
      Width = 561
      Height = 121
      DataSource = MyDataSource2
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit]
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      Columns = <
        item
          Expanded = False
          FieldName = 'idx'
          Title.Caption = 'index'
          Width = 65
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'title'
          Width = 285
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'description'
          Visible = True
        end>
    end
  end
  object DBNavigator1: TDBNavigator
    Left = 17
    Top = 254
    Width = 576
    Height = 33
    DataSource = MyDataSource1
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
    Flat = True
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
  end
  object BitBtn2: TBitBtn
    Left = 16
    Top = 296
    Width = 289
    Height = 33
    Caption = 'Attach single unit'
    TabOrder = 3
    Glyph.Data = {
      0E060000424D0E06000000000000360000002800000016000000160000000100
      180000000000D805000000000000000000000000000000000000EBF1F1EBF1F1
      ECF1F0ECF1F0ECF1F0ECF1F0EBF1F1EBF1F1EBF1F1EBF0F1EBF0F1EBF0F1EBF1
      F0EBF1F0EBF1F0EBF0F0EBF0F0EBF0F0EBF0F1EBF0F1EBF0F1EBF0F10000EBF1
      F1EBF1F1ECF1F0ECF1F0ECF1F0ECF1F0EBF1F1EBF1F1EBF1F1EBF0F1EBF0F1EB
      F0F1EBF1F0EBF1F0EBF1F0EBF0F0EBF0F0EBF0F0EBF0F1EBF0F1EBF0F1EBF0F1
      0000EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1
      EEF2F1EEF2F1EEF1F0EEF1F0EEF1F0EEF1F1EEF1F1EEF1F1EDF2F1EDF2F1EDF2
      F1EDF2F10000EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1EEF2
      F1EEF2F1EEF2F1EEF2F1EEF1F0EEF1F0EEF1F0EEF1F1EEF1F1EEF1F1EDF2F1ED
      F2F1EDF2F1EDF2F10000EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1EE
      F2F1EEF2F1EEF2F1EEF2F1EEF2F1EEF1F0EEF1F0EEF1F0EEF1F1EEF1F1EEF1F1
      EDF2F1EDF2F1EDF2F1EDF2F10000EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1
      EEF2F1EEF2F1EEF2F1EDF1F0EBEFEEEBEFEEEEF1F0EEF1F0EEF1F0EEF1F1EEF1
      F1EEF1F1EDF2F1EDF2F1EDF2F1EDF2F10000EEF2F1EEF2F1EEF2F1EEF2F1EEF2
      F1EEF2F1EEF2F1EEF2F1DADDDCB2B5B5AAADACACAFAED2D5D4EEF1F0EEF1F0EE
      F1F1EEF1F1EEF1F1EDF2F1EDF2F1EDF2F1EDF2F10000EEF2F1EEF2F1EEF2F1EE
      F2F1EEF2F1EEF2F1EEF2F1EEF2F1348F3C2B853C277736195521797D7AEEF1F0
      EEF1F0EEF1F1EEF1F1EEF1F1EDF2F1EDF2F1EDF2F1EDF2F10000EEF2F1EEF2F1
      EEF2F1EEF2F1EEF2F1EEF2F1EEF2F1EEF2F177C28077FFA46CFF9A3998506D70
      6EEEF1F0EEF1F0EEF1F1EEF1F1EEF1F1EDF2F1EDF2F1EDF2F1EDF2F10000EEF2
      F1EEF2F1EEF2F1EEF2F1EEF2F1EDF1F0EBEFEEEEF2F1619C6979FFA46CFF9A3A
      9B516C706DEEF1F0EEF1F0EEF1F1EEF1F1EEF1F1EDF2F1EDF2F1EDF2F1EDF2F1
      0000EEF2F1EEF2F1EEF2F1EEF2F1DADDDCB2B5B5AAADACC1C4C441894873FFA0
      6CFF9A399C515E625FB4B8B6ADB1AEACB1AEC7CCCAE0ECE4EBF2EFEDF2F1EDF2
      F1EDF2F10000EEF2F1EEF2F1EEF2F1EEF2F1358F3C2B853C2675352B873949CA
      656CFF996BFF9852D075287A37267735297B371A58226A6C6CEDF0F0EDF2F1ED
      F2F1EDF2F1EDF2F10000EEF2F1EEF2F1EEF2F1EEF2F170B97976FFA368FF956B
      FF986CFF9969FF9569FF956AFF966AFF976AFF976EFF9C3A99516A6D6CEEF1F1
      EDF2F1EDF2F1EDF2F1EDF2F10000F0F2F1F0F2F1EFF2F1EFF2F178BD807EFFA9
      6FFF9E71FF9E6DFF9A69FF9569FF956AFF9771FF9F72FF9F75FFA53EA7586E71
      6FEFF3F1EFF3F1EFF3F1EFF3F1EFF3F10000F0F2F1F0F2F1EFF2F1EFF2F184BE
      896EC57D64C1746DC47C72DB896EFF996AFF985BE7813EAD5161C17169C87A36
      9C43879088EFF3F1EFF3F1EFF3F1EFF3F1EFF3F10000F0F2F1F0F2F1EFF2F1EF
      F2F1ECF1EEE9F0ECE9EFEBEFF2F177BB7D75FF9F6CFF9A3FB158676A68E6EBE8
      EBF1EDE7F0E9EEF2F0EFF3F1EFF3F1EFF3F1EFF3F1EFF3F10000F0F2F1F0F2F1
      EFF2F1EFF2F1EFF2F1EFF2F1EFF2F1EFF2F175BB7D75FF9F6AFF983A9A506D71
      6EEFF3F1EFF3F1EFF3F1EFF3F1EFF3F1EFF3F1EFF3F1EFF3F1EFF3F10000F0F2
      F1F0F2F1EFF2F1EFF2F1EFF2F1EFF2F1EFF2F1EFF2F177BC7F7EFFA873FFA33D
      A5576E716FEFF3F1EFF3F1EFF3F1EFF3F1EFF3F1EFF3F1EFF3F1EFF3F1EFF3F1
      0000F0F2F1F0F2F1EFF2F1EFF2F1EFF2F1EFF2F1EFF2F1EFF2F184BE896FC67E
      65C576369C43879088EFF3F1EFF3F1EFF3F1EFF3F1EFF3F1EFF3F1EFF3F1EFF3
      F1EFF3F10000F0F2F1F0F2F1EFF2F1EFF2F1EFF2F1EFF2F1EFF2F1EFF2F1ECF1
      EEEAF0EDE9EFECE7EFEAEEF2F0EFF3F1EFF3F1EFF3F1EFF3F1EFF3F1EFF3F1EF
      F3F1EFF3F1EFF3F10000F0F2F1F0F2F1EFF2F1EFF2F1EFF2F1EFF2F1EFF2F1EF
      F2F1EFF2F1EFF2F2EFF2F2EFF2F2EFF3F1EFF3F1EFF3F1EFF3F1EFF3F1EFF3F1
      EFF3F1EFF3F1EFF3F1EFF3F10000F0F2F1F0F2F1EFF2F1EFF2F1EFF2F1EFF2F1
      EFF2F1EFF2F1EFF2F1EFF2F2EFF2F2EFF2F2EFF3F1EFF3F1EFF3F1EFF3F1EFF3
      F1EFF3F1EFF3F1EFF3F1EFF3F1EFF3F10000}
  end
  object BitBtn1: TBitBtn
    Left = 304
    Top = 296
    Width = 289
    Height = 33
    Caption = 'Close'
    TabOrder = 4
    OnClick = BitBtn1Click
  end
  object MyConnection1: TMyConnection
    Database = 'mcdm'
    Username = 'root'
    Server = 'localhost'
    Connected = True
    LoginPrompt = False
    Left = 288
    Top = 192
  end
  object MyDataSource1: TMyDataSource
    AutoEdit = False
    DataSet = MyTable1
    Left = 320
    Top = 192
  end
  object MyTable1: TMyTable
    TableName = 'component'
    Connection = MyConnection1
    Active = True
    Left = 320
    Top = 224
  end
  object MyQuery1: TMyQuery
    Connection = MyConnection1
    SQL.Strings = (
      
        'SELECT s.ID, s.idx, s.title, s.description FROM state s, compSta' +
        'tes cs WHERE cs.IDcomponent=:F1 AND cs.IDstate=s.ID')
    MasterSource = MyDataSource1
    KeyFields = 'ID'
    Active = True
    Left = 352
    Top = 192
    ParamData = <
      item
        DataType = ftInteger
        Name = 'F1'
        ParamType = ptInput
        Value = 0
      end>
  end
  object MyDataSource2: TMyDataSource
    DataSet = MyQuery1
    Left = 352
    Top = 224
  end
end
