# unity-optimization
- 유니티는 CBD(Component-based Development), 스크립트 언어(컴파일하지 않고 실행, 응용 소프트웨어 제어)를 사용

## 스크립트
- Instantiate, Destroy는 비용이 상당히 크다.
  - 프리팹의 수가 많다면 시작 전 미리 생성 후 오브젝트 풀을 활용
- 나눗셈보다 곱셈을 사용하자.
  - 나눗셈은 곱셈보다 연산속도가 월등히 느리다. ex) 1/10 대신 * 0.1을 사용
- 복합적 수학연산은 자제하자.
  - 초월함수(pow, exp, log, cos, sin, tan )는 리소스가 상당히 많이 소요
- 오브젝트의 자식이 많다면 transform 변경시 많은 비용 발생한다.
- 콜백함수가 비어있다면 지우자.
  - Start, Update등 콜백함수는 비어있어도 호출
- GetComponent(), Find() 사용을 줄이자.
  - 객체 참조가 필요할 때마다 Update에서 호출하는 방식은 지양
  - 최대한 Awake, Start 메소드에서 Get, Find 메소드로 통해 객체들을 필드에 캐싱
```cs
// Bad
private void Update()
{
    GetComponent<Rigidbody>().AddForce(Vector3.right);
}

// Good
private Rigidbody rb;

private void Awake()
{
    rb = GetComponent<Rigidbody>();
}

private void Update()
{
    rb.AddForce(Vector3.right);
}
```
- 코루틴 yield를 캐싱하자.
  - new로 동적생성할 경우, 전부 GC의 대상
```cs
// Bad
private IEnumerator Coroutine()
{
    while(true)
    {
        // ...
        yield return new WaitForSeconds(1f);
    }
}

// Good
private IEnumerator Coroutine()
{
	var wfs = new WaitForSeconds(1f);
    while(true)
    {
        // ...
        yield return var;
    }
}
```
- GetComponent() 대신 TryGetComponent()를 사용하자.
  - GetComponent() 메소드는 할당에 성공하거나 실패해도 언제나 GC Allocation이 발생
  - TryGetComponent()를 이용하면 GC 걱정 없이 깔끔하게 사용
  - 할당 성공 여부를 bool 타입으로 리턴
- 태그 비교에서는 CompareTag()를 사용하도록 한다.
  - Object.name, GameObject.tag는 GC의 대상
- 메소드 호출을 줄이자.
  - 메소드 호출 때문에 비용이 더 들지만 가독성에 따라 선택
  - 비교연산에서 해당 메소드 호출의 결과값이 범위 내에서 달라질 수 있는 경우, 바로 사용
  - 비교연산에서 해당 메소드 호출의 결과값이 범위 내에서 항상 같은 경우, bool형으로 캐싱하여 사용
- 모든 비교문에서 .equals()를 사용하도록 하자.
  - == 구문은 사용하면 임시적인 메모리가 나오게 되어 GC의 대상
- foreach 대신에 for문을 사용하자.
  - foreach는 한번 반복시 24byte의 가비지 메모리를 생성하며 수없이 돌면 더 많은 메모리를 생성
- 빌드 이후 Debug.Log() 사용하지 않기
  - Debug의 메소드들은 디버깅을 할 때 도움이 되지만 빌드 이후에도 호출되면 성능을 많이 소모
- 참조 캐싱을 활용하자.
  - 프로퍼티는 필드가 아닌 호출할 수 있는 메소드다.
  - 메소드 호출만큼의 오버헤드가 발생 (실제로 내부적으로는 Setter, Getter 메소드)
```cs
private Camera _mainCam;
private GameObject _mainCamObject;
private Transform  _mainCamTransform;
private GameObject _targetParentObject;
private float _deltaTime;

void Start()
{
    _mainCam = Camera.main;
    _mainCamObject = Camera.main.gameObject;
    _mainCamTransform = Camera.main.transform;
    _targetParentObject = targetObject.transform.parent.gameObject;
}

void Update()
{
    _deltaTime = Time.deltaTime;
}
```
- Transform 변경은 한번에 하자.
  - position과 rotation을 모두 변경해야 하는 경우 SetPositionAndRotation() 메소드를 사용
- 벡터 연산의 순서를 주의하자
  - 벡터와 스칼라의 곱은 각 스칼라에 대한 곱
```cs
Vector3 vec = new Vector3(1f, 2f, 3f);
float a = 4f;
float b = 5f;

// Bad
Vector3 vec2 = vec * a * b;

Vector3 temp = new Vector3(vec.x  * a, vec.y  * a, vec.z  * a);
Vector3 vec2 = new Vector3(temp.x * b, temp.y * b, temp.z * b);

// Good
Vector3 vec2 = a * b * vec;

float temp   = a * b;
Vector3 vec2 = new Vector3(vec.x * temp, vec.y * temp, vec.z * temp);
```

### null 연산
> #### fake null (댕글링 포인터 방지)
```cs
GameObject go = null; // 레퍼런스 유지, 메모리 유지
Destroy(go); // 레퍼런스 제거, 메모리 유지 (GC에서 처리)

// 메모리에는 남아있기에 C#같은 managed언어는 시간이 지나면 GC가 메모리의 각 블럭에 대한 레퍼런스의 수를 내부적으로 계속 추적하여 제거
// managed언어가 unmanaged언어보다 느린 이유

if (go == null) // true
    Debug.Log("as UnityEngine.Object");
if ((object)go == null) // false
    Debug.Log("as System.Object");
```
> #### 오브젝트 null 체크
- 오브젝트를 bool로 묵시적 형변환
```cs
if (gameObject)
```

- Destroy 후 null(System.Object) 대입
```cs
Destroy(go);
go = null;
```

- System.Object로 형변환하여 비교 (혹은 obejct.ReferenceEquals 함수 사용
```cs
ReferenceEquals(obj, null);  
if ((object)obj == null)
```

## 이미지와 오디오
- 디바이스별로 권장하는 압축 텍스쳐 포맷
  - 아이폰(powerVR): RVRCT
  - 안드로이드(Tegra): DXT
  - 안드로이드(Adreno) : ATC
  - 안드로이드(공통) : ETC

- 이미지 가로세로는 2의 제곱을 선택
  - 메모리상에서 로드할 때 2의 베곱으로 로드를 하게 되는데, 2의 제곱의 사이즈가 아닌 이미지도 2의 제곱으로 로드하므로 상당한 메모리 낭비가 일어나게 된다.

- 압축된 텍스쳐와 밉맵 활용
  - 32비트가 아닌 16비트의 텍스쳐도 상황에 따라 활용

- 오디오는 92kb모노 인코딩
  - 모바일에서 스테레오는 의미가 없음

- 오디오는 .wav로 저장
  - 용량을 줄이기 위해 mp3로 저장하지 않아도, 자체 인코더가 용량을 원하는데로 압축하기 때문에 음향 손실을 피하기 위해 wav로 저장
