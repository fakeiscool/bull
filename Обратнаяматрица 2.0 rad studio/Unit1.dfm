object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 468
  ClientWidth = 712
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object StringGrid1: TStringGrid
    Left = 24
    Top = 43
    Width = 418
    Height = 174
    Cursor = crArrow
    ColCount = 3
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 32
    Top = 14
    Width = 33
    Height = 21
    TabOrder = 1
    Text = '3'
  end
  object Button1: TButton
    Left = 71
    Top = 10
    Width = 99
    Height = 25
    Caption = #1088#1072#1079#1084#1077#1088#1085#1086#1089#1090#1100
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 198
    Top = 10
    Width = 99
    Height = 25
    Caption = #1079#1072#1087#1086#1083#1085#1080#1090#1100' '#1085#1072#1091#1075#1072#1076
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 369
    Top = 8
    Width = 73
    Height = 29
    Caption = #1055#1086#1089#1095#1080#1090#1072#1090#1100
    TabOrder = 4
    OnClick = Button3Click
  end
  object StringGrid2: TStringGrid
    Left = 24
    Top = 223
    Width = 418
    Height = 174
    Cursor = crArrow
    ColCount = 3
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
    TabOrder = 5
  end
  object Button4: TButton
    Left = 456
    Top = 200
    Width = 161
    Height = 49
    Caption = #1055#1088#1086#1074#1077#1088#1082#1072' '#1086#1073#1088#1072#1090#1085#1086#1081' '#1084#1072#1090#1088#1080#1094#1099
    TabOrder = 6
    OnClick = Button4Click
  end
end
