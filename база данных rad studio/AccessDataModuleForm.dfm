object AccessDataModule: TAccessDataModule
  OldCreateOrder = False
  Height = 150
  Width = 393
  object AccessConnect: TADOConnection
    ConnectionString = 
      'Provider=Microsoft.ACE.OLEDB.12.0;Data Source=F:\c++ rad studio\' +
      #1073#1072#1079#1072' '#1076#1072#1085#1085#1099#1093'\IST219Base.accdb;Persist Security Info=False'
    Mode = cmShareDenyNone
    Provider = 'Microsoft.ACE.OLEDB.12.0'
    Left = 56
    Top = 32
  end
  object AсTab: TADOTable
    Connection = AccessConnect
    CursorType = ctStatic
    TableName = 'StyudentList'
    Left = 160
    Top = 32
  end
  object DaS: TDataSource
    DataSet = AсTab
    Left = 240
    Top = 40
  end
  object pQf: TADOQuery
    Connection = AccessConnect
    Parameters = <>
    Left = 320
    Top = 32
  end
end
