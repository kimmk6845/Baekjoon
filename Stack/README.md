# 스택(Stack)
한 쪽 끝에서만 자료를 넣고 뺄 수 있는 후입선출(LIFO, Last In First Out)방식의 자료구조

입출력이 최상위 원소만 다루기 때문에 스택의 중간이나 아래부분에서 데이터를 삽입, 삭제하는 것이 불가능함

출력의 순서가 입력의 역순으로 이루어져야 하는 경우에 사용하기 유용함

<div align="center">
  
  ![stack](https://user-images.githubusercontent.com/71704350/148687073-2906e90d-5580-4d77-b304-7afcfdcd42e2.PNG)
  
  https://dev.to/theoutlander/implementing-the-stack-data-structure-in-javascript-4164
  
</div>

* 메서드(C++)
  - push(x): x를 스택의 가장 윗 부분에 삽입
  - pop(): 스택의 가장 위에 있는 원소를 제거
  - top(): 스택의 가장 위에 있는 원소를 반환 (조회)
  - empty(): 스택이 비어있는지 확인, 비어있다면 true
  - size(): 스택의 크기 반환

<br>

* 사용 사례
  - 재귀 알고리즘
    + 재귀적으로 함수를 호출해야 하는 경우 임시 데이터를 스택에 넣음
    + 재귀 함수를 빠져나와 백트래킹을 할 때는 스택에 넣어 두었던 임시 데이터를 뺌
  - 웹 브라우저 방문기록(뒤로가기)
  - 실행 취소(undo)
  - 역순 문자열 만들기
  - 수식 괄호 검사
    + 올바른 괄호 문자열(VPS) 판단하기
  - 후위 표기법 
