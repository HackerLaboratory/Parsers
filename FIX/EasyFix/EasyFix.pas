unit EasyFix;

interface
uses
  StrUtils, SysUtils, Classes;

const
  SOH = #1;
  SEQUAL = '='; 

type
  TBaseFix = class
  public
    constructor Create; overload;
    constructor Create(fixPkg: string); overload;
    destructor Destroy; override;
  protected
    //��ȡ�Ӵ�subStr������Str�е�i�ζ�Ӧ��λ�ã�δ�ҵ�ʱ����0
    function NPos(subStr: string; Str: string; n: Integer): Integer;
    //sText��Key=Value<SOH>��ʽ���ַ��������ݸ��ַ�����ȡ����ֵ
    procedure GetNameValue(sText: string; var iKey, sValue: string);
  protected
    sBuffer: string;
  end;

  TFixValue = class(TBaseFix)
  public
    function GetFixValue(key: Integer; index: Integer = 1): TFixValue;
    
    procedure SetKey(key: Integer);
    procedure SetValue(value: string);
    function GetKey: Integer;
    function AsString: string; 
    function AsInteger: Integer;
    function AsFloat: Double; 
  private
    iKey: Integer;
    sValue: string;
  end;

  TEasyFix = class(TBaseFix)
  public
    function GetFixValue(key: Integer; index: Integer = 1): TFixValue;

    procedure AddValue(key: Integer; value: string; iLen: Integer); overload;
    procedure AddValue(key: Integer; value: Integer; iLen: Integer); overload;
    procedure AddValue(key: Integer; value: Double; iLen: Integer); overload;
    function GetBuffer: string;
  private
    function GetSpaceText(value: string; iLen: Integer): string; overload;
    function GetSpaceText(value: Integer; iLen: Integer): string; overload;
    function GetSpaceText(value: Double; iLen: Integer): string; overload;
  end;

implementation

constructor TBaseFix.Create;
begin
  inherited;
  sBuffer := '';
end;

constructor TBaseFix.Create(fixPkg: string);
begin
  inherited Create;
  sBuffer := fixPkg;
  sBuffer := StringReplace(sBuffer, ' ', '', [rfReplaceAll]);
end;

destructor TBaseFix.Destroy;
begin
  sBuffer := '';
  inherited;
end;

//����ֵ0��ʾû��������
function TBaseFix.NPos(subStr: string; Str: string; n: Integer): Integer;
var
  i, position: Integer;
  x, y: Integer;
begin
  Result := 0;
  for i:=1 to n do
  begin
    position := Pos(subStr, Str);

    x := position + Length(subStr);
    y := Length(Str) - position - Length(subStr)+1;
    Str := Copy(Str, x, y);
    if (0 = position) then
    begin
      Result := 0;
      Break;
    end;
    Result := Result + position;
  end;
  if (0 <> Result) then
  begin
    Result := Result + (n-1) * (Length(subStr)-1);
  end;
end;

procedure TBaseFix.GetNameValue(sText: string; var iKey, sValue: string);
var
  index: Integer;
begin
  iKey := '';
  sValue := '';
  index := Pos(SEQUAL, sText);
  if (0 = index) then
  begin
    Exit;
  end;
  iKey := LeftStr(sText, index-1);
  sValue := Trim(RightStr(sText, Length(sText)-index));
end;

function TFixValue.GetFixValue(key: Integer; index: Integer = 1): TFixValue;
var
  searchKey, searchBuffer: string;
  position1, position2: Integer;
  sTemp, iKey, sValue: string;
begin
  searchKey := IntToStr(key) + SEQUAL;
  position1 := NPos(searchKey, sBuffer, index);
  if 0 <> position1 then
  begin
    searchBuffer := Copy(sBuffer, position1, Length(sBuffer)-position1+1);
    position2 := Pos(SOH, searchBuffer);
    sTemp := Copy(searchBuffer, 1, position2);
    GetNameValue(sTemp, iKey, sValue);
    searchBuffer := Copy(searchBuffer, position2+1, Length(searchBuffer)-position2);
  end
  else
  begin
    searchBuffer := '';
    sValue := '';
  end;

  Result := TFixValue.Create(searchBuffer);
  Result.SetKey(key);
  Result.SetValue(sValue);
end;

procedure TFixValue.SetKey(key: Integer);
begin
  iKey := key;  
end;

procedure TFixValue.SetValue(value: string);
begin
  sValue := value;
end;

function TFixValue.GetKey: Integer;
begin
  Result := iKey;
end;

function TFixValue.AsString: string;
begin
  Result := sValue;
end;

function TFixValue.AsInteger: Integer;
begin
  try
    Result := StrToInt(sValue);
  except
    Result := 0;
  end;
end;

function TFixValue.AsFloat: Double;
begin
  try
    Result := StrToFloat(sValue);
  except
    Result := 0.0;
  end;
end;

function TEasyFix.GetFixValue(key: Integer; index: Integer = 1): TFixValue;
var
  searchKey, searchBuffer: string;
  sTemp, iKey, sValue: string;
  position1, position2: Integer;
begin
  searchKey := IntToStr(key) + SEQUAL;
  position1 := NPos(searchKey, sBuffer, index);
  if 0 <> position1 then
  begin
    searchBuffer := Copy(sBuffer, position1, Length(sBuffer)-position1+1);

    position2 := Pos(SOH, searchBuffer);
    sTemp := Copy(searchBuffer, 1, position2);
    GetNameValue(sTemp, iKey, sValue);
    searchBuffer := Copy(searchBuffer, position2+1, Length(searchBuffer)-position2);
  end
  else
  begin
    searchBuffer := ''; 
    sValue := '';
  end;

  Result := TFixValue.Create(searchBuffer);
  Result.SetKey(key);
  Result.SetValue(sValue);    
end;

procedure TEasyFix.AddValue(key: Integer; value: string; iLen: Integer);
begin
  sBuffer := sBuffer + IntToStr(key) + SEQUAL + GetSpaceText(value, iLen) + SOH;
end;

procedure TEasyFix.AddValue(key: Integer; value: Integer; iLen: Integer);
begin
  sBuffer := sBuffer + IntToStr(key) + SEQUAL + GetSpaceText(value, iLen) + SOH;
end;

procedure TEasyFix.AddValue(key: Integer; value: Double; iLen: Integer);
begin
  sBuffer := sBuffer + IntToStr(key) + SEQUAL + GetSpaceText(value, iLen) + SOH;
end;

function TEasyFix.GetBuffer: string;
begin
  //�����ͷ����һ����ֵ����FIX���ĳ��ȣ�ʵ��Ҫ��Ҫ���Ҳ����Ҫ��˫��Լ��
  sBuffer := '9' + SEQUAL + GetSpaceText((Length(sBuffer)), 5) + SOH + sBuffer;

  //�����β
  //�����ͨ��˫����Լ������ЩԼ��Ҫ�ڰ�β��ר�ŵ��ֶδ��У��ֵ����Ϣ����Щ��û��

  //��ȡ����FIX��
  Result := sBuffer;
end;

function TEasyFix.GetSpaceText(value: string; iLen: Integer): string;
begin
  //string���͵�Ҫ�ں󲹿ո�
  //Result := value + StringOfChar(' ', iLen - Length(value));
  Result := value;
end;

function TEasyFix.GetSpaceText(value: Integer; iLen: Integer): string;
begin
  //number����Ҫ��ǰ���ո�
  //Result := StringOfChar(' ', iLen - Length(IntToStr(value))) + IntToStr(value);
  Result := IntToStr(value);
end;

function TEasyFix.GetSpaceText(value: Double; iLen: Integer): string; 
begin
  //number����Ҫ��ǰ���ո�
  //Result := StringOfChar(' ', iLen - Length(FloatToStr(value))) + FloatToStr(value);
  Result := FloatToStr(value);
end;

end.
