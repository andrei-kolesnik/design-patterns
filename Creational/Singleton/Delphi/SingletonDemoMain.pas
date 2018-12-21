unit SingletonDemoMain;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls;

type
  TForm1 = class(TForm)
    Memo1: TMemo;
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

uses Singleton;

{$R *.DFM}

procedure TForm1.FormCreate(Sender: TObject);
var
  s1, s2: TSingleton;
begin
  try
    s1 := TSingleton.Create;
    s1.Prop := 100;
    Memo1.Text := Memo1.Text + #13#10 + IntToStr(s1.RefCount);
    Memo1.Text := Memo1.Text + #13#10 + IntToStr(s1.Prop);
    s2 := TSingleton.Create;
    s2.Prop := 200;
    Memo1.Text := Memo1.Text + #13#10 + IntToStr(s2.RefCount);
    Memo1.Text := Memo1.Text + #13#10 + IntToStr(s1.Prop);
    Memo1.Text := Memo1.Text + #13#10 + IntToStr(s2.Prop);

  finally
    s1.Free;
    Memo1.Text := Memo1.Text + #13#10 + IntToStr(s2.RefCount);
    s2.Free;
  end;
end;

end.
