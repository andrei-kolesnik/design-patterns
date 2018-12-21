unit Singleton;

interface

type
  TSingleton = class(TObject)
public
  Prop: integer;

  class function NewInstance: TObject; override;
  procedure FreeInstance; override;
  class function RefCount: Integer;
end;

var
  Instance : TSingleton = nil;
  Ref_Count: Integer    = 0;

implementation

{ TOSingleton }

procedure TSingleton.FreeInstance;
begin
  Dec(Ref_Count);
  if (Ref_Count = 0) then
  begin
    Instance := nil;
    // Destroy private variables here
    inherited FreeInstance;
  end;
end;

class function TSingleton.NewInstance: TObject;
begin
  if not Assigned(Instance) then
  begin
    Instance := TSingleton(inherited NewInstance);
    // Initialize private variables here, like this:
    //   TSingleton(Instance).Variable := Value;
    TSingleton(Instance).Prop := 0;
  end;
  Result := Instance;
  Inc(Ref_Count);
end;

class function TSingleton.RefCount: Integer;
begin
  Result := Ref_Count;
end;

end.

