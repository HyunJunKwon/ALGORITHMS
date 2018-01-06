# ALGORITHMS

<br/>

### Algorithm
* In mathematics and computer science, an algorithm is a self-contained step-by-step set of operations to be performed. (알고리즘이란 어떠한 문제를 해결하기 위한 여러 동작들의 모임.)

<br/>

### 문제해결을 위한 기본
* [A + B - 4](https://www.acmicpc.net/problem/10951)
  
  * 이 문제처럼 입력이 몇 개인지 주어지지 않은 경우, 입력을 EOF까지 받는다. (scanf의 리턴값은 성공적으로 입력받은 변수의 개수)
  * ```while(scanf("%d %d", &a, &b) == 2) or while(cin >> a >> b) ```

* 한 줄 입력받기

  * ```scanf("%s", s);```
  * ```cin >> s;```
  * 위의 두 방법은 한 줄을 입력받을 수 없다.
  * ```fgets(s, 100, stdin);```
  * ```scanf("%[^\n]\n", s);```
  * ```getline(cin, s);```
  * 위의 세 방법은 모두 한 줄을 전체로 입력받을 수 있다.
  * fgets는 줄 바꿈까지 입력 받기 때문에, 조심해야 한다.
  * 다만, ```scanf("%[^\n]\n", s);``` 방식은 줄바꿈을 입력받기 않기 때문에 편리한 방법이지만, 각 줄의 앞 뒤에 있는 공백은 무시하고 입력을 받게 된다. 따라서 빈 줄을 입력받을 수 없다. 공백을 받지 않는 문제일 경우, [그대로 출력하기](https://www.acmicpc.net/problem/11718), 다음과 같이 ```	while (scanf("%[^\n]\n", s) == 1) 
	{
		printf("%s\n", s);
	}``` 코딩하면 되지만, 공백을 받는 문제일 경우, [그대로 출력하기2](https://www.acmicpc.net/problem/11719), ```   while ((c = getchar()) && c != EOF) {
        printf("%c",c);
    }```로 코딩해야한다.
    
* 숫자의 합 [숫자의 합](https://www.acmicpc.net/problem/11720)
  * scanf("%1d", &x);
  * %d 사이에 수를 넣으면, 그 길이 만큼 입력을 받게 된다. (1234 입력일 때, 1, 2, 3, 4 가능)
  * %s의 경우도 개수를 지정해서 입력받을 수 있다. 다만 입력받을 수 있는 것의 개수가 지정한 개수 보다 적으면 그만큼만 입력을 받게 된다.

* 그 이외의 언어적 기초 [Confused C Concepts](https://github.com/HyunJunKwon/StudyingLanguages/blob/master/C/ConfusedConcepts.pdf)








