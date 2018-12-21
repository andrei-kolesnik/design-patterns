program SingletonDemo;

uses
  Forms,
  SingletonDemoMain in 'SingletonDemoMain.pas' {Form1},
  Singleton in 'Singleton.pas';

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
