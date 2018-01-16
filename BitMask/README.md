# BitMask

<br/>

* 비트 마스크를 사용하는 코드는 다음과 같은 장점을 갖는다.

	* 더 빠른 수행 시간
	* 더 간결한 코드
	* 더 작은 메모리 사용량
	* 연관 배열을 배열로 대체

* 물론 배열을 사용하는 것이 더욱 편리하지만, 비트마스크를 사용하는 이유는 집합을 배열의 인덱스로 표현할 수 있기 때문이다. 또한 비트마스크는 상태 다이나믹을 할 때 자주 사용한다.

* 비트(bit) 연산을 사용해서 부분 집합을 표현할 수 있다.

* &(and), |(or), ~(not), ^(xor)

* 비트 연산에서 유의할 점들
	* 연산자 간 우선순위를 혼동할 수 있다.
	* &, |, ^ 등의 비트 연산자의 우선순위는 == 혹은 != 등의 비교 연산자보다 낮다.
	* ```int c = (6 & 4 == 4)``` 의 경우 ```4 == 4```가 먼저 계산되어 결과는 ```6 & 1```인 0이 된다.
	* 비트마스크를 사용하는 식에는 가능한 괄호를 자세하게 추가하는 습관이 필요하다.
	* 64비트 정수를 비트마스크로 사용할 때 발생하는 오버플로우
	* ```bool isBitSet(unsigned long long a, int b) return (a & (1 << b)) > 0;``` C++에서 1은 부호 있는 32비트 상수로 취급되기 때문에, b가 32 이상이면 식 (1 << b)에서 오버플로우가 발생한다. 이 문제를 해결하기 위해서는 1뒤에 이 상수가 부호 없는 64비트 정수임을 알려주는 접미사 ```ull```을 붙여 주어야한다.
	 * 부호 있는 정수형의 사용: 변수의 모든 비트를 다 쓰고 싶을 때는 부호 없는 정수형을 쓰는 것이 좋다.


* Bitwise Operation
  * 두 수 A와 B를 비트연산하는 경우에는 가장 뒤의 자리부터 하나씩 연산을 수행하면 된다.
	* not 연산의 경우에는 자료형에 따라 결과가 달라진다. 그리고 unsigned, signed에 ㄸ라서 보여지는 값이 다르다.
	* A << B는 A * 2^B와 같다.
	* A >> B는 A / 2^B와 같다. ((A + B) / 2는 (A + B) >> 1과 같다)
	* 어떤 수가 홀수 인지 판별하는 if(N % 2 == 1)은 if(N & 1)로 줄여 쓸 수 있다. (2^0만이 홀수이므로)

* 정수로 집합을 나타낼 수 있다.
	* {1, 3, 4, 5, 9} = 570 = 2^1 + 2^3 + 2^4 + 2^5 + 2^9 => 1000111010
	* 위의 집합에서 x = {1, 3, 4, 5, 9 중 하나}가 포함되어있는지 판별하는 식은 ```S & (1 << x)```
	* 위의 집합에서 임의의 수 추가하는 식은 ```S | (1 << x)```
	* 위의 집합에서 임의의 수 제거하는 식은 ```S & ~(1 << x)```
	* 토글: S ^ (1 << x)
	* 전체 집합: (1 << N) - 1 = (2^N - 1)
	* 공집합: 0
	* 연습문제: [집합](https://www.acmicpc.net/problem/11723)
	
* 두 집합에 대해 연산하기
```
int added = (a | b); // a와 b의 합집합
int intersection = (a & b); // a와 b의 교집합
int removed = (a & ~b); // a에서 b를 뺀 차집합
int toggled = (a ^ b); // a와 b중 하나에만 포함된 원소들의 집합
```

* 집합의 크기 구하기
```
int bitCount(int x)
{
	if(x == 0) return 0;
	return x % 2 + bitCount(x / 2);
}
``` 
또는 gcc상에서는 ```__builtin_popcount(integer)``` 나 visual C++에서는 ```__popcnt(integer)``` 를 사용한다.

* 최소 원소 찾기
	* 집합에 포함된 가장 작은 원소를 찾을 수 있다. 이 연산은 "이 정수의 이진수 표현에서 끝에 붙어 있는 0이 몇 개인가"의 형태로 지원된다. 즉, 켜져있는 최하위 비트의 번호를 반환한다. gcc에서는 ```__builtin_ctz(integer)``` visual C++에서는 ```__BitScanForward(&index, integer)```

* 최하위 비트의 번호 대신 해당 비트를 직접 구하고 싶다면 ```int first = (integer & ~integer);```를 사용한다.

* 최소 원소 지우기: ```integer &= (integer - 1);```

* 모든 부분 집합 순회하기
```for(int subset = set; sebset; subset = ((subset - 1) & set)) {}```

* 비트마스크를 사용하는 예

	* 에라토스테네스의 체
```
// 비트마스크를 사용하는 에라토스테네스의 체의 구현
int n;
unsigned char sieve[(MAX_N + 7) / 8];
// k가 소수인지 확인한다.
inline bool isPrime(int k)
{
	return sieve[k >> 3] & (1 << (k & 7));
}
// k가 소수가 아니라고 표시한다.
inline void setComposite(int k)
{
	sieve[k >> 3] &= ~(1 << (k & 7));
}
// 비트마스크를 사용하는 에라토스테네스의 체의 구현
// 이 함수를 수행하고 난 뒤, isPrime()을 이용해 각 수가 소수인지 알 수 있다.
void eratosthenes()
{
	memset(sieve, 255, sizeof(sieve));
	setComposite(0);
	setComposite(1);
	int sqrtn = int(sqrt(n));
	for (int i = 2; i <= sqrtn; i++)
		// 이 수가 아직 지워지지 안았다면
		if (isPrime(i))
			// i의 배수 j들에 대해 isPrime(j) = false로 둔다.
			// i * i 미만의 배수는 이미 지워졌으므로 신경 쓰지 않는다.
			for (int j = i * i; j <= n; j += i)
				setComposite(j);
}
```

	* 15퍼즐 상태 표현하기
```
// 64비트 부호 없는 정수를 [0, 15] 범위의 정수 16개를 담는 배열로 사용하기
typedef unsigned long long uint64;
// mask의 index 위치에 쓰인 값을 반환한다
int get(uint64 mask, int index)
{
	return (mask >> (index << 2)) & 15;
}
// mask의 index 위치를 value로 바꾼 결과를 반환한다
uint64 set(uint64 mask, int index, uint64 value)
{
	return mask & ~(15LL << (index << 2)) | (value << (index << 2));
}
```



