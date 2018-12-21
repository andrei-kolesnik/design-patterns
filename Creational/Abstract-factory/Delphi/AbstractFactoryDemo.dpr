program AbstractFactoryDemo;

uses
  Forms,
  AbstractFactoryDemoMain in 'AbstractFactoryDemoMain.pas' {Form1},
  AbstractFactory in 'AbstractFactory.pas';

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
