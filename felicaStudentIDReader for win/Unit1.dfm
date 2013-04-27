object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 419
  ClientWidth = 652
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 24
    Width = 288
    Height = 77
    Caption = #23398#31821#30058#21495#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -64
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 312
    Top = 35
    Width = 20
    Height = 77
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -64
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object StringGrid1: TStringGrid
    Left = 0
    Top = 118
    Width = 652
    Height = 301
    Align = alBottom
    ColCount = 7
    RowCount = 1
    FixedRows = 0
    TabOrder = 0
  end
  object Button1: TButton
    Left = 419
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 1
    Visible = False
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 500
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 2
    Visible = False
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 299
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 3
    Text = 'Edit1'
    Visible = False
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 507
    Top = 8
  end
end
