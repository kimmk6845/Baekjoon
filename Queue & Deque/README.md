# 큐 (Queue)
스택과 반대로 먼저 들어간 자료가 더 빨리 나오는 선입선출(FIFO, First In First Out)방식의 자료 구조

데이터의 삽입은 뒤쪽에서 enqueue, 삭제는 앞쪽에서 dequeue연산을 하게 됨

양 끝의 원소에만 접근할 수 있기 때문에 스택과 마찬가지로 중간 원소에 접근할 수 없음

<div align = "center">
  
  ![큐](https://user-images.githubusercontent.com/71704350/148779460-88696dd0-e1cc-4151-8777-5c35cc16c2e0.PNG)
  
  https://velog.io/@gillog/%ED%81%90Que

</div>

<br>

- 메서드
  + push(x): x를 큐의 맨 뒤에 삽입
  + pop(): 큐의 가장 앞에 있는 데이터를 삭제
  + front(): 큐의 가장 앞에 있는 데이터를 반환
  + back(): 큐의 가장 뒤에 있는 데이터를 반환
  + size(): 현재 사이즈를 반환
  + empty(): 큐가 비어있는지 확인

<br>

- 사용 사례
  + 은행 업무
  + 대기열 순서와 같은 우선순위의 작업 예약
  + 서비스 센터의 대기시간
  + 프린터의 출력 처리
  + 윈도 시스템의 메시지 처리기
  + 프로세스 관리

<br>

# 덱 (Deque)
양쪽 끝에서 삽입과 삭제를 할 수 있는 자료구조로 스택과 큐를 합친 형태라고 볼 수 있음

하지만 스택, 큐와 마찬가지로 중간 원소에는 접근할 수 없음

<div align = "center">
  
  ![덱](https://user-images.githubusercontent.com/71704350/148779492-6dfc07b6-5812-45b6-b530-169d59dc8c62.PNG)
  
  https://codingexplore.tistory.com/42
  
</div>

<br>

- 메서드
  + push_front(x): x를 덱의 맨 앞에 삽입
  + push_back(x): x를 맨 뒤에 삽입
  + pop_front(): 맨 앞의 데이터 삭제
  + pop_back(): 맨 뒤의 데이터 삭제
  + front(): 덱의 가장 앞에 있는 데이터를 반환
  + back(): 덱의 가장 뒤에 있는 데이터를 반환
  + size()
  + empty()
