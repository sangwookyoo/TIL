# 📌 code-convention-example (C#)

✔ C# 모범 사례를 제시합니다. <br>
✔ 레이아웃이 아닌 내용에 집중할 수 있도록 일관성 있게 표시되는 코드를 만듭니다. <br>
✔ 이전 경험을 토대로 한 가정을 통해 코드를 보다 빠르게 이해할 수 있도록 합니다. <br>
✔ 코드를 보다 쉽게 복사, 변경 및 유지 관리할 수 있도록 합니다. <br>

### 📢 레이아웃 규칙
- 기본 코드 편집기 설정(스마트 들여쓰기, 4자 들여쓰기, 탭을 공백으로 저장)을 사용한다.
- 한 줄에 한 문장만 작성한다.
- 한 줄에 하나의 선언만 작성한다.
- 메서드 정의와 속성 정의 사이에 하나 이상의 빈 줄을 추가한다.
- 중괄호의 위치는 BSD 스타일을 준수한다.
- 메소드는 Unity Script Lifecycle Flowchart 순서대로 작성한다.
- 다음 예와 같이, 괄호를 사용하여 식의 절을 명확하게 구분합니다.
 ```cs
if ((val1 > val2) && (val1 > val3))
{
    // Take appropriate action.
}
```

### 📢 주석처리 규칙
- 대문자로 주석 텍스트를 시작한다.
- 마침표로 주석 텍스트를 종료한다.
- 다음 예와 같이, 주석 구분 기호(//)와 주석 텍스트 사이에 공백을 하나 삽입한다.
```cs
// The following declaration creates a query. It does not run
// the query.
```
- 다음 예와 같이, 문서화가 필요한 주석은 /* ... */ 을 사용하여 작성한다.
```cs
/*
* The following declaration creates a query. It does not run
* the query.
*/
```

### 📢 명명규칙
- 예약어를 사용하지 않는다.
- 다음 예와 같이, 메소드명은 파스칼 케이스(Pascal case)를 사용하며 동사로 시작한다.
```cs
public void SetMethod()
{
    // Take appropriate action.
}
```
- 다음 예와 같이, 메소드 인자 및 변수에는 카멜 케이스(Camel case)를 사용하며 명사로 시작한다.
```cs
public float myTimer;
public int myCount;
public string myName;
```
- 다음 예와 같이, private 변수명은 '_'를 추가한다.
```cs
private float _myTimer;
private int _myCount;
private string _myName;
```
- 다음 예와 같이, 열거형 키워드는 영문 대문자를 사용한다.
```cs
public enum Sound
{
    BGM,
    EFFECT,
    3DSOUND
}
```
- 다음 예와 같이, URL, HTML와 같은 범용적인 대문자 약어는 대문자 그대로 사용한다.
```cs
parseHTML
parseXML
```

### 📢 언어지침
  - 다음 예와 같이, 접근제한자는 public-private 순서대로 선언한다.
```cs
// Bad:
public float timer = 1.2f;
private string _name = "myString";
public int count = 1;

// Good:
public float timer = 1.2f;
public int count = 1;
private string _name = "myString";
```
  - 다음 예와 같이, 선언과 동시에 할당하는 변수 먼저 선언한다.
```cs
// Bad:
public float timer = 1.2f;
public int count;
public string name = "myString";

// Good:
public float timer = 1.2f;
public string name = "myString";
public int count;
```
  - 다음 예와 같이, 리터럴 정의 시 대입연산자 앞뒤에 공백을 추가한다.
```cs
// Bad:
public float timer= 1.2f;
public int count =1;
public string name="myString";

// Good:
public float timer = 1.2f;
public int count = 1;
public string name = "myString";
```
  - 다음 예와 같이, 연산자 앞뒤에 공백을 추가한다.
```cs
// Bad:
a+b +c+ d = 15;
new Vector3(1,0,0);

// Good:
a + b + c + d = 15;
new Vector3(1, 0, 0);
```
  - 다음 예와 같이, 축약이 가능한 산술연산자는 축약한다.
```cs
// Bad:
a = a + b;
a = a - b;
a = a * b;
a = a / b;
a = a % b;

// Good:
a += b;
a -= b;
a *= b;
a /= b;
a %= b;
```
  - 다음 예와 같이, 성능개선을 위해 가능한 경우 산술연산자를 대체한다.
```cs
// Bad:
int count = 1;
int num = count / 10;

// Good:
int count = 1;
int num = count * 0.1;
```

### 📢 참고문서
- [C# 코딩 규칙 | Microsoft Docs](https://docs.microsoft.com/ko-kr/dotnet/csharp/fundamentals/coding-style/coding-conventions)
