unit AbstractFactoryDemoMain;

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

uses
  AbstractFactory;

{$R *.DFM}

procedure TForm1.FormCreate(Sender: TObject);
var
  bag: IBag;
  shoes: IShoes;
  factory: IFactory;
begin
  factory := TGucciFactory.Create;
  bag := factory.CreateBag;
  shoes := factory.CreateShoes;

  Memo1.Text := Memo1.Text + #13#10 +
    'I bought a Bag which is made from ' + bag.Material;
  Memo1.Text := Memo1.Text + #13#10 +
    'I bought some shoes which cost ' + IntToStr(shoes.Price);

  factory := TPoochyFactory.Create;
  bag := factory.CreateBag;
  shoes := factory.CreateShoes;

  Memo1.Text := Memo1.Text + #13#10;
  Memo1.Text := Memo1.Text + #13#10 +
    'I bought a Bag which is made from ' + bag.Material;
  Memo1.Text := Memo1.Text + #13#10 +
    'I bought some shoes which cost ' + IntToStr(shoes.Price);
end;

end.

