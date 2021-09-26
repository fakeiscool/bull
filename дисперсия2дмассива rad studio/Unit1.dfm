object v: Tv
  Left = 0
  Top = 0
  Caption = 'v'
  ClientHeight = 441
  ClientWidth = 726
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
    Left = 136
    Top = 80
    Width = 449
    Height = 249
    ColCount = 1
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 176
    Top = 48
    Width = 49
    Height = 21
    TabOrder = 1
    Text = '5'
  end
  object Edit2: TEdit
    Left = 320
    Top = 48
    Width = 49
    Height = 21
    TabOrder = 2
    Text = '5'
  end
  object Button1: TButton
    Left = 320
    Top = 352
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 3
    OnClick = Button1Click
  end
end
