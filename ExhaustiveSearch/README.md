# Exhaustive Search (완전 탐색)

<br/>

* 가능한 모든 경우의 수를 만들어보고 탐색하는 방법.

* 가능한 모든 경우의 수를 알아야 한다.
  * Brute Force
  * BFS
  * DFS
  * BitMask
  * Permutation
  * Back Tracking
  * 탐욕법
  * 조합탐색
  * 최적화 문제 결정 문제로 바꿔풀기
  
* 그냥 다 해보기
  * 가능한 모든 경우의 수를 만들어보고 탐색하는 방법.
  * 가능한 모든 경우의 수를 알아야 한다.
  * [날짜 계산](https://www.acmicpc.net/problem/1476)
  * [리모컨](https://www.acmicpc.net/problem/1107)


* N중 for문
  * N개 중에 일부를 선택해야 하는 겨우에 많이 사용한다.
  * 재귀 호출이나 비트마스크를 사용하면 더 간결하고 보기 쉬운 코드를 작성할 수 있기 때문에, 사용할 일이 거의 없다.
  * [1, 2, 3 더하기](https://www.acmicpc.net/problem/9095)

* 순열 사용하기
  * 팩토리얼
  * [차이를 최대로](https://www.acmicpc.net/problem/10819)
  * [외판원 순회 2](https://www.acmicpc.net/problem/10971)
  * [로또](https://www.acmicpc.net/problem/6603)

* 큐 사용하기
  * 자세한 것은 [그래프_BFS]() 참조.
  * [숨바꼭질](https://www.acmicpc.net/problem/1697)
  * [소수 경로](https://www.acmicpc.net/problem/1963)
  * [DSLR](https://www.acmicpc.net/problem/9019)
  * [퍼즐](https://www.acmicpc.net/problem/1525)
  * [물통](https://www.acmicpc.net/problem/2251)
  * [스타트링크](https://www.acmicpc.net/problem/5014)

* 재귀호출 사용하기
  * 자세한 것은 [그래프_DFS](https://github.com/HyunJunKwon/ALGORITHMS/tree/master/Graph/2_DepthFirstSearch) 참조.
  * [1, 2, 3 더하기](https://www.acmicpc.net/problem/9095)
  * [암호 만들기](https://www.acmicpc.net/problem/1759)
  * [N-Queen](https://www.acmicpc.net/problem/9663)
  * [스도쿠](https://www.acmicpc.net/problem/2580)
  * [알파벳](https://www.acmicpc.net/problem/1987)
  * [로또](https://www.acmicpc.net/problem/6603)
  * [부분집합의 합](https://www.acmicpc.net/problem/1182)

* 비트마스크 사용하기
  * 자세한 것은 [BitMask](https://github.com/HyunJunKwon/ALGORITHMS/tree/master/BitMask) 참조.
  * [부분집합의 합](https://www.acmicpc.net/problem/1182)

* 일부 경우만 해보기 (Two Pointer Algorithm)
  * 모든 경우 다해보기와 다르게 절대 정답이 될 수 없는 경우는 확인하지도 않을 수 있다.
  * [수들의 합 2](https://www.acmicpc.net/problem/2003)
  * [부분합](https://www.acmicpc.net/problem/1806)
  * [소수의 연속합](https://www.acmicpc.net/problem/1644)

* 덱 사용하기
  * [알고스팟](https://www.acmicpc.net/problem/1261)

* 중간에서 만나기
	* 문제를 절반으로 나눠서
	* 양쪽 절반에서 모든 경우를 다 해보는 방법이다.
	* 탐색의 크기가 많이 줄어든다.
	* 문제의 크기가 N인 경우에 2^N에서
	* M = N / 2라고 했을 때, 2^M + 2^M으로 줄어들게 된다.
  * [부분집합의 합2](https://www.acmicpc.net/problem/1208)
  * [합이 0인 네 정수](https://www.acmicpc.net/problem/7453)
  * [피자 판매](https://www.acmicpc.net/problem/2632)
  * [두 배열의 합](https://www.acmicpc.net/problem/2143)
















