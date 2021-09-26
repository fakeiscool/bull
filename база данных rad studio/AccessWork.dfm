object AccessWorkForm: TAccessWorkForm
  Left = 0
  Top = 0
  Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1082#1072' '#1088#1072#1073#1086#1090#1099' '#1089' Access'
  ClientHeight = 433
  ClientWidth = 657
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = BigMenu
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ViewTab: TDBGrid
    Left = 8
    Top = 112
    Width = 612
    Height = 89
    DataSource = AccessDataModule.DaS
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object DBNavigator1: TDBNavigator
    Left = 200
    Top = 207
    Width = 240
    Height = 25
    DataSource = AccessDataModule.DaS
    TabOrder = 1
  end
  object TableList: TListBox
    Left = 499
    Top = 207
    Width = 121
    Height = 216
    ItemHeight = 13
    TabOrder = 2
    OnDblClick = N3Click
  end
  object BigMenu: TMainMenu
    Left = 40
    Top = 40
    object N1: TMenuItem
      Caption = #1060#1091#1085#1082#1094#1080#1080
      object N2: TMenuItem
        Caption = #1057#1086#1077#1076#1080#1085#1080#1090#1100#1089#1103' '#1089' '#1073#1072#1079#1086#1081' '#1076#1072#1085#1085#1099#1093
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1055#1077#1088#1082#1083#1102#1095#1080#1090#1089#1103' '#1084#1077#1078#1076#1091' '#1090#1072#1073#1083#1080#1094#1072#1084#1080
        OnClick = N3Click
      end
    end
    object SQL1: TMenuItem
      Caption = 'SQL'
      object SQL2: TMenuItem
        Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' SQL'
        OnClick = SQL2Click
      end
      object SQLexec1: TMenuItem
        Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' SQL - exec'
        OnClick = SQLexec1Click
      end
    end
    object N4: TMenuItem
      Caption = #1058#1072#1073#1083#1080#1094#1072
      object N5: TMenuItem
        Caption = #1057#1090#1088#1091#1082#1090#1091#1088#1072' '#1090#1072#1073#1083#1080#1094#1099
        OnClick = N5Click
      end
    end
  end
  object OpDi: TOpenDialog
    Left = 160
    Top = 40
  end
  object OpenDialog1: TOpenDialog
    Filter = 
      'sql - '#1091#1090#1074#1077#1088#1078#1076#1077#1085#1080#1103'|*.sql|'#1090#1077#1082#1089#1090#1086#1074#1099#1077' '#1092#1072#1081#1083#1099'|*.txt|'#1087#1088#1086#1075#1088#1072#1084#1084#1099' '#1085#1072' '#1057'++|*' +
      '.cpp'
    Left = 272
    Top = 40
  end
end
