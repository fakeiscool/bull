object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 558
  ClientWidth = 935
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Edit1: TEdit
    Left = 8
    Top = 184
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'ColorTable00'
  end
  object Button1: TButton
    Left = 8
    Top = 224
    Width = 121
    Height = 25
    Caption = #1055#1086#1080#1089#1082
    TabOrder = 1
    OnClick = Button1Click
  end
  object StringGrid1: TStringGrid
    Left = 183
    Top = 8
    Width = 744
    Height = 545
    ColCount = 1
    DefaultColWidth = 720
    FixedCols = 0
    RowCount = 99
    TabOrder = 2
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 273
    Width = 169
    Height = 105
    Caption = #1050#1086#1088#1077#1085#1100
    ItemIndex = 1
    Items.Strings = (
      'HKEY_CLASSES_ROOT'
      'HKEY_CURRENT_USER'
      'HKEY_LOCAL_MACHINE'
      'HKEY_USERS'
      'HKEY_CURRENT_CONFIG')
    TabOrder = 3
  end
end
