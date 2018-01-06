# Permutation

<br/>

* 순열의 의미
	* 1 ~ N 까지로 이루어진 수열
	* 길이는 항상 N이 되어야 하고, 겹치는 숫자가 존재하지 않음
	* 길이가 N인 순열은 총 N!개가 존재한다.

* C++의 STL에 algorithm에는 이미 next_permutation과 prev_permutation이 존재하기 떼문에 사용하면 된다(배열로 접근). 그렇지 않을 경우, 다음과 같은 절차를 따라 알고리즘을 구현한다.
  > 
  1. A[i - 1] < A[i]을 만족하는 가장 큰 i를 찾는다.
  2. j >= i 이면서 A[j] > A[i - 1]을 만족하는 가장 큰 j를 찾는다.
  3. A[i - 1]과 A[j]를 swap 한다.
  4. A[i]부터 순열을 뒤집는다.
```
bool next_permutation(int * a, int n)
{
	int i = n = 1;
	while(i > 0 && a[i - 1] >= a[i]) i -= 1;
	if(i <= 0) return false; // 마지막 순열
	int j = n - 1;
	while(a[j] <= a[i - 1]) j -= 1;
	swap(a[i - 1], a[j]);
	j = n - 1;
	while(i < j)
	{
		swap(a[i], a[j]);
		i += 1; j -= 1;
	}
	return true;
}
```

* 예제 1 [다음 순열](https://www.acmicpc.net/problem/10972)

* 예제 2 [이전 순열](https://www.acmicpc.net/problem/10973)

* 예제 3 [모든 순열](https://www.acmicpc.net/problem/10974)

* 예제 4 [순열의 순서](https://www.acmicpc.net/problem/1722)




