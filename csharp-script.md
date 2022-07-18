# csharp-script
- Unity C# Script
- 누른상태에서 tab 누르면 자동완성
## 변수와 자료형
### 변수선언
- 문자, 언더바(_)로 시작 가능
- 숫자로 시작할 수 없음
- 예약어를 사용할 수 없음

### 변수종류
- 전역변수(필드): 인스턴스 생성시 초기화, 클래스 반환시 반환
- 지역변수: 메소드 호출시 초기화, 사용 종료시 반환
- 정적변수(공유자원): 전역변수에만 선언, 프로그램 종료시 반환
- 매개변수: 초기화된 변수는 항상 뒤에

### 변수타입
- Primitive Type(int, float, bool, char 와 같은 기본 데이터 타입)과 구조체(struct)
  - 변수의 선언과 동시에 값을 할당할 수 있으며 스텍에 메모리가 생성
  - 생선된 데이터는 직접적이며 변수의 대입이나 매개변수로 데이타를 전달할 때 메모리 복사
- Reference Type(class, string, object, array)
  - 참조 타입을 사용하기 위해선 new 키워드를 통해 객체를 초기화한 후 힙에 할당된 메모리를 스택공간에서 참조

### 자료형
- 정수형
  - 8bit, sbyte, byte
  - 16bit, short, ushort
  - 32bit, int, uint
  - 64bit, long, ulong (접미어 l)
- 부동소수점형
  - 4byte(32bit), float (접미어 f)
  - 8byte(64bit), double (접미어 d)
  - 16byte(128bit), decimal (접미어 m)
- 문자형
  - 4byte(32bit), bool
- 논리형
  - 2byte(16bit), char
- var형
  - 변수 선언시 초기화

### 접근제한자 (기본: private)
- public: 클래서 외부에서도 접근, 인스펙터에 노출
- private: 클래스 내부에서만 접근
- protected: 외부 클래스 접근불가, 파생 클래스에서만 접근
- internal: 외부 어셈블리 접근불가, 내부 어셈블리 접근

### 상수
- const: 변경불가, 컴파일, static
- readonly: 권장, 읽기전용, 런타임, non-static

### 연산자
- 대입연산자: (+), (-), (*), (/), (%)
- 복합대입연산자: (+=), (-=), (*=), (/=), (%=)
- 증감연산자(전위, 후위): (++), (--)
  - 전위연산자: 문장이 끝나기 전에 실행
  - 후위연산자: 문자이 끝난 후에 실행
- 관계연산자 (bool return 타입으로도 사용): (==), (!=), (<), (>), (<=), (>=)
- 논리연산자: (&&), (||), (!)
- 비트연산자: &(AND), |(OR), ^(XOR), ~(NOT), >>, <<
  - XOR: 다르면1, 같으면 0

## 조건문
- if, if-else, switch-case
- 삼항연산자: 조건 ? 참 : 거짓

## 반복문
- for, foreach, while, do-while
- break: 현재 루프 탈출
- continue: 현재 루프 통과
``` csharp
string text = "가나다라"
foreach(char a in text)
// output: 가, 나, 다, 라
```

## 배열
- 배열의 크기가 지정되면 수정 불가능
```csharp
// 1차원 배열
int[] arr1 = { 0, 5 }; // 선언 및 할당
int[] arr2 = new int[10]; // 크기만 지정
int[] arr3; // 선언
arr3 = new int [10]; // 크기만 지정
arr2 = new int [arr2.Length]; // 크기 참조

// 2차원 배열
int[,] arr = { {0 ,1, 2}, {10, 20, 30} };
arr[0, 2];
// output: 2

// 3차원 배열
int[,,] arr = ( { {0 ,1, 2}, {10, 20, 30} }, { {0 ,1, 2}, {10, 20, 30} } );
arr[1,0,1]
// output: 1
```

## 클래스
```csharp
public class CLASS1
{
	public int a;
	public static int b;
}

public class CLASS2 : MonoBehaviour
{
  CLASS1 class1 = new CLASS1();
	class1.a = 1;
	CLASS1.b = 2;
}
```

## 인터페이스
- 클래스 <-> 다중상속이 가능하다
- override를 사용하지 않는다
- 단, 변수는 사용불가능

## 열거형
```csharp
public enum item
{
  Grenade,
}

public class CLASS1 : MonoBehaviour
{
  item myitem;
  myitem = item.Grenade;
}
```

## 네임스페이스
- namespace 로 선언, using 으로 사용
- 변수 충돌 방지 등 협업을 위해 사용

## 컬렉션
- 배열의 Length -> Count
- ArrayList arrayList = new ArrayList();
```csharp
ArrayList arrayList = new ArrayList();
arrayList.Add(VALUE);
arrayList.Remove(VALUE); // arrayList 안에 있는 리터럴과 일치하는 값을 지움
arrayList.RemoveAt(INDEX); // arrayList 인덱스의 리터럴을 지움
arrayList.RemoveRanger(0, 5); // 0의 인덱스부터 5의 인덱스까지 지움
arrayList[1] = 2; // 1의 인덱스의 값을 2로 변경
arrayList.Clear(); // 초기화
arrayList.CopyTo(ArrayList); // ArrayList의 값을 복사
arrayList.Contains(VALUE); // 값이 있으면 논리로 반환
arrayList.Insert(1, 1.5); // 1 인덱스에 1.5 값을 넣고 기존 1인덱스는 2로 미룸
```
- List<DATA_TYPE> list = new List<DATA_TYPE>();
  - ArrayList <=> 자료형 선언차이, 연산의 차이
- Hashtable hashtable = new Hashtable();
  - hashtable.Add(KEY, VALUE);
  - hashtable[KEY];
- Dictionary<KEY DATA_TYPE, VALUE, DATA_TYPE> dictionary = new Dictionary<KEY DATA_TYPE, VALUE, DATA_TYPE>();
  - Hashtable <=> 자료형 선언차이, 연산의 차이
- Queue<DATA_TYPE> queue = new Queue<DATA_TYPE>();
  - // FIFO
  - queue.Enqueue(VALUE);
  - queue.Dequeue(); // if (queue.Count != 0) 과 함께
- Stack<DATA_TYPE> stack = new Stack<DATA_TYPE>();
  - // FILO
  - stack.Push(VALUE);
  - stack.Pop(); // if (queue.Count != 0) 과 함께

## 상속
- virtual: 파생클래스에서 선택구현, 기능구현 가능
```csharp
public class CLASS1 : CLASS2
{
	num = 0; // CLASS2의 변수
	void Start() => Info();

	protected override void Info()
	{
		base.Info(); // CLASS2의 Info()부터 실행
		// 선택 재정의
	}
}

public class CLASS2 : MonoBehaviour
{
	protected int num;

	protected virtual void Info()
  {
    // 정의
  }
	
}
```
- abstract: 파생클래스에서 필수구현, 기능구현 불가능
```csharp
public class CLASS1 : CLASS2
{
	num = 0; // CLASS2의 변수
	void Start() => Info();

	protected override void Info()
	{
		// 필수 재정의
	}
}

public class CLASS2 : MonoBehaviour
{
	protected int num;

	protected abstract void Info();
	
}
```

## 람다식
```csharp
// 호출
void Start() => Plus();

// 구현
void Plus = (매개변수) => { 내용 }

// 델리게이트
changeFunc += delegate() { } // 무명메소드
changeFunc += () { } // 람다식
```

## 형식 매개 변수
- 호출시 T에 대한 타입 지정
```csharp
void Print<T> (T value)
{
	print(value);
}

void Start()
{
	Print<string>("abc");
	Print<int>(1);
}
```
- struct/class에서 호출시 T에 대한 타입 지정
```csharp
void Print<T> (T value) where T : struct/class
{
	print(value);
}

void Start()
{
	Print<string>("abc"); // class
	Print<int>(1); // struct
}
```
- struct/class에서 호출시 T에 대한 타입 지정

## 델리게이트
- 타 클래스에서 직접적인 접근 방지
- 클래스끼리의 변수 참조 디커플링(어느 한 코드를 변경했을 때 다른 코드를 변경하지 않아도 되는 것)

### 델리게이트 체인
- 함수를 보관(대리자)하고 호출
```csharp
public delegate void ChangeFunc(int value);
ChangeFunc changeFunc;

changeFunc += 메소드1(); // 델리게이트 추가
changeFunc += 메소드2();
changeFunc(); // 메소드1, 메소드2 동시호출

changeFunc -= 메소드2(); // 델리게이트 빼기

changeFunc = 메소드0()
changeFunc += 메소드1(); // 메소드 0 안에 메소드 1
```

### 이벤트
```csharp
public delegate void ChangeFunc(int value);
public static event ChangeFunc Onstart;
Onstart += 메소드1(); // 델리게이트 추가
Onstart += 메소드2();

CLASS1.Onstart += 메소드3(); // 타 클래스에서도 사용가능
```

### Action, Func
```csharp
using System;

delegate void DE<T1, T2> (T1 a, T2 b); // void라면 Action 아니라면 Func
DE<int, int> dde;

// 델리게이트 미선언
Action<int, int> dde;
Func<int, int, 반환타입> dde;
```

## 프로퍼티
```csharp
prviate int salary;
public int Salary { get { return salary; } set { salary = value; } } // value는 예약어
public int Salary { get; set; } // 변수 할당, 반환만 사용시
```

## 인덱서
- 클래스를 바로 사용할 때
```csharp
public class CLASS1 : MonoBehaviour
{
	public int this[]
	{
		get { }
		set { }
	}
	
}

public class CLASS2 : MonoBehaviour
{
	CLASS1 class1 = new CLASS1();
	class1[] // 바로사용
	
}
```
----------------------

## 예외처리
- try-catch-finally
```csharp
try { } // 실행문
catch(DividByZeroException ie) { } // 오류검사
finally { } // 최종실행문 (오류발생여부 상관없음)
// Exception 모든오류
throw new Exception(""); // 일부로 오류 발생
```
