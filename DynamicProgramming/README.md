# Dynamic Programming

<br/>

### 다이나믹 프로그래밍(Dynamic Programming)
	
* 큰 문제를 작은 문제로 나눠서 푸는 알고리즘

* 두 가지 속성을 만족해야 다이나믹 프로그래밍으로 문제를 풀 수 있다.
  * Overlapping Subproblem
  * Optimal Substructure
  
* 다이나믹 프로그래밍에서 각 문제는 한 번만 풀어야 한다.

* Optimal Substructure를 만족하기 때문에, 같은 문제는 구할 때마다 정답이 같다.

* 따라서, 정답을 한 번 구했으면 정답을 어딘가에 메모해놓는다(주로 배열에, Memoization)

* 피보나치 수로 보는 예
	```
	int memo[100];
	int fibonacci(int n)
	{
		if(n <= 1)
			return n;
		else
		{
			memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
			return memo[n];
		}
	}
	```
	
* 다이나믹을 푸는 두 가지 방식이 있다.
  
  * Top-down
  
    * 문제를 작은 문제를 나눈다.
    
    * 작은 문제를 푼다.
    
    * 작은 문제를 풀었으니, 이제 문제를 푼다.
   
    * 재귀호출을 이용하여 풀 수 있다.
	
  * Bottom-up 
     
    * 문제를 크기가 작은 문제부터 자례대로 푼다.
		
    * 문제의 크기를 조금씩 크게 만들면서 문제를 점점 푼다.
     
    * 작은 문제를 풀면서 왔기 때문에, 큰 문제는 항상 풀 수 있다.
     
    * 그러다보면, 언젠간 풀어야 하는 문제를 풀 수 있다.

<br/>

### 다이나믹 문제 풀이 전략

* 문제에서 구하려고 하는 답을 문장으로 나타낸다. (예: N번째 피보나치 수)

* 이제 그 문장에 나와있는 변수의 개수만큼 메모하는 배열을 만든다. (Top-down인 경우에는 재귀 호출의 인자의 개수)
* 문제를 작은 문제로 나누고, 수식을 이용해서 문제를 표현해야 한다.

* 다이나믹 문제 풀이
	* [1로 만들기](https://www.acmicpc.net/problem/1463)
	* [2 x n 타일링](https://www.acmicpc.net/problem/11726)
	* [2 x n 타일링 2](https://www.acmicpc.net/problem/11727)
	* [1, 2, 3 더하기](https://www.acmicpc.net/problem/9095)
	* [붕어빵 판매하기](https://www.acmicpc.net/problem/11052)
	* [쉬운 계단 수](https://www.acmicpc.net/problem/10844)
	* [오르막 수](https://www.acmicpc.net/problem/11057)
	* [이친수](https://www.acmicpc.net/problem/2193)
	* [스티커](https://www.acmicpc.net/problem/9465)
	* [포도주 시식](https://www.acmicpc.net/problem/2156)
	* [가장 긴 증가하는 부분 수열](https://www.acmicpc.net/problem/11053)
	* [가장 큰 증가하는 부분 수열](https://www.acmicpc.net/problem/11055)
	* [가장 긴 감소하는 부분 수열](https://www.acmicpc.net/problem/11722)
	* [가장 긴 바이토닉 부분 수열](https://www.acmicpc.net/problem/11054)
	* [연속합](https://www.acmicpc.net/problem/1912)
	* [계단 오르기](https://www.acmicpc.net/problem/2579)
	* [제곱수의 합](https://www.acmicpc.net/problem/1699)
	* [타일 채우기](https://www.acmicpc.net/problem/2133)
	* [파도반 수열](https://www.acmicpc.net/problem/9461)
	* [합분해](https://www.acmicpc.net/problem/2225)
	* [암호 코드](https://www.acmicpc.net/problem/2011)
	* [이동하기](https://www.acmicpc.net/problem/11048)
	* [점프](https://www.acmicpc.net/problem/1890)
	* [팰린드롬?](https://www.acmicpc.net/problem/10942)
	* [팰린드롬 분할](https://www.acmicpc.net/problem/1509)
	* [동전 1](https://www.acmicpc.net/problem/2293)
	* [동전 2](https://www.acmicpc.net/problem/2294)
	* [내리막 길](https://www.acmicpc.net/problem/1520)
	* [파일 합치기](https://www.acmicpc.net/problem/11066)
	* [행렬 곱셈 순서](https://www.acmicpc.net/problem/11049)
	* [구간 나누기](https://www.acmicpc.net/problem/2228)
	* [자두나무](https://www.acmicpc.net/problem/2240)
	* [고층 빌딩](https://www.acmicpc.net/problem/1328)
	* [타일 코드](https://www.acmicpc.net/problem/1720)
	* [기타리스트](https://www.acmicpc.net/problem/1495)
	* [1학년](https://www.acmicpc.net/problem/5557)
	* [올바른 괄호 문자열](https://www.acmicpc.net/problem/3012)
	* [같은 탑](https://www.acmicpc.net/problem/1126)
		
