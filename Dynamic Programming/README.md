# 동적계획법(Dynamic Programming, DP)
전체 문제를 작은 문제로 단순화한 다음 점화식으로 만들어 재귀적인 구조를 활용해 전체 문제를 해결하는 방식

1. 전체 문제를 작은 문제로 단순화 --> 부분 문제 정의
2. 재귀적인 구조를 활용할 수 있는 점화식 이용
3. 작은 문제를 해결한 방법으로 전체 문제를 해결

<br>

모든 방법을 검토해 최적해를 찾아내는 방식의 알고리즘이기 때문에 효율적인 탐색을 하기 위해 메모이제이션을 활용해야 한다.

* 메모이제이션(Memoization) = 동일한 계산을 반복해야 할 때 함수의 값을 배열에 저장하고 필요할 때마다 함수를 호출하지 않고 
배열의 값을 빠르게 가져옴으로써 중복 계산을 줄이는 것을 의미함.