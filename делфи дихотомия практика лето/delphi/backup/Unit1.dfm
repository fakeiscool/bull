object Form1: TForm1
  Left = 1912
  Top = -8
  Width = 1936
  Height = 1056
  Caption = #1042#1099#1095#1080#1089#1083#1077#1085#1080#1077' '#1084#1080#1085#1080#1084#1091#1084#1072
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object a: TLabel
    Left = 8
    Top = 128
    Width = 150
    Height = 21
    Caption = #1051#1077#1074#1099#1081' '#1080#1085#1090#1077#1088#1074#1072#1083' a:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object lbl1: TLabel
    Left = 168
    Top = 128
    Width = 158
    Height = 21
    Caption = #1055#1088#1072#1074#1099#1081' '#1080#1085#1090#1077#1088#1074#1072#1083' b:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 336
    Top = 125
    Width = 97
    Height = 21
    Caption = #1058#1086#1095#1085#1086#1089#1090#1100' e :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 400
    Width = 307
    Height = 40
    Caption = #1047#1085#1072#1095#1077#1085#1080#1077' '#1084#1080#1085#1080#1084#1091#1084#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -33
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object lbl2: TLabel
    Left = 8
    Top = 496
    Width = 450
    Height = 40
    Caption = #1047#1085#1072#1095#1077#1085#1080#1077' '#1092#1091#1085#1082#1094#1080#1080' '#1084#1080#1085#1080#1084#1091#1084#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -33
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object lbl3: TLabel
    Left = 184
    Top = 48
    Width = 146
    Height = 24
    Caption = #1060#1091#1085#1082#1094#1080#1103': x^2-1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object lbl4: TLabel
    Left = 520
    Top = 72
    Width = 1322
    Height = 33
    Caption = 
      '    '#1064#1072#1075#1080'              a                 b               x1      ' +
      '         x2             f(x1)         f(x2)     |(b-a)/2|<e   '#1087#1086 +
      #1075#1088#1077#1096#1085#1086#1089#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object edt1: TEdit
    Left = 8
    Top = 152
    Width = 137
    Height = 32
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = '-4'
  end
  object edt2: TEdit
    Left = 168
    Top = 152
    Width = 137
    Height = 32
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Text = '3'
  end
  object edt3: TEdit
    Left = 336
    Top = 152
    Width = 137
    Height = 32
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Text = '0,1'
  end
  object btn1: TBitBtn
    Left = 48
    Top = 248
    Width = 297
    Height = 81
    Caption = #1053#1072#1081#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -67
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = btn1Click
  end
  object edt4: TEdit
    Left = 8
    Top = 440
    Width = 401
    Height = 48
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -33
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object edt5: TEdit
    Left = 8
    Top = 544
    Width = 401
    Height = 48
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -33
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object strngrd1: TStringGrid
    Left = 513
    Top = 112
    Width = 1309
    Height = 785
    ColCount = 9
    DefaultColWidth = 140
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Tahoma'
    Font.Style = []
    GridLineWidth = 5
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 6
  end
end
