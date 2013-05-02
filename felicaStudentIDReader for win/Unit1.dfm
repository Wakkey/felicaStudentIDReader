object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 417
  ClientWidth = 728
  Color = clMenu
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
  object Panel1: TPanel
    Left = 0
    Top = 188
    Width = 728
    Height = 229
    Align = alClient
    Caption = 'Panel1'
    TabOrder = 0
    object Panel2: TPanel
      Left = 265
      Top = 1
      Width = 462
      Height = 227
      Align = alClient
      Caption = 'Panel2'
      ParentBackground = False
      TabOrder = 0
      object StringGrid1: TStringGrid
        Left = 1
        Top = 32
        Width = 460
        Height = 194
        Align = alClient
        ColCount = 8
        RowCount = 1
        FixedRows = 0
        TabOrder = 0
      end
      object Panel5: TPanel
        Left = 1
        Top = 1
        Width = 460
        Height = 31
        Align = alTop
        Caption = #20986#24109#32773#19968#35239
        TabOrder = 1
      end
    end
    object Panel3: TPanel
      Left = 1
      Top = 1
      Width = 264
      Height = 227
      Align = alLeft
      Caption = 'Panel3'
      ParentBackground = False
      TabOrder = 1
      object StringGrid2: TStringGrid
        Left = 1
        Top = 32
        Width = 262
        Height = 194
        Align = alClient
        ColCount = 4
        RowCount = 1
        FixedRows = 0
        TabOrder = 0
        RowHeights = (
          24)
      end
      object Panel4: TPanel
        Left = 1
        Top = 1
        Width = 262
        Height = 31
        Align = alTop
        Caption = #23398#29983#21517#31807
        ParentBackground = False
        TabOrder = 1
      end
    end
  end
  object Panel6: TPanel
    Left = 0
    Top = 0
    Width = 728
    Height = 188
    Align = alTop
    Color = clWhite
    ParentBackground = False
    TabOrder = 1
    object Label3: TLabel
      Left = 318
      Top = 105
      Width = 20
      Height = 77
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -64
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
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
    object Label4: TLabel
      Left = 152
      Top = 105
      Width = 160
      Height = 77
      Caption = #21517#21069#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -64
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 318
      Top = 24
      Width = 20
      Height = 77
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -64
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 299
      Top = 8
      Width = 121
      Height = 21
      TabOrder = 0
      Text = 'Edit1'
      Visible = False
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
  end
  object Timer1: TTimer
    Interval = 500
    OnTimer = Timer1Timer
    Left = 507
    Top = 8
  end
end
