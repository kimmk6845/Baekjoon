# 우선순위 큐 (Priority Queue)
Queue는 먼저 들어온 데이터가 우선적으로 빠지는 FIFO(First In First Out)의 구조를 가진 자료구조임

Priority Queue는 우선순위가 높은 순서로 데이터가 빠지는 자료구조

*우선순위 큐는 일반적으로 Heap을 이용해 구현함

## 힙 (Heap)
우선순위 큐를 위해 고안된 완전이진트리 형태의 자료구조

여러 개의 값 중 최댓값 or 최솟값을 찾아내는 연산이 빠름

- 특징
  + 완전이진트리 형태로 이루어져 있음
  + 이진탐색트리(BST)와 달리 중복된 값이 허용

<br>

- 종류
  + 최대 힙(MAX Heap)
    * 부모 노드의 키 값이 자식 노드보다 크거나 같은 완전이진트리
    * [ Key(부모) >= Key(자식) ]
 
<div align = "center">
  
  ![최대힙](https://user-images.githubusercontent.com/71704350/152285160-f3d75fe0-45ab-4535-9002-1b4516cbc2a1.png)
  
</div>

  + 최소 힙<MIN Heap>
    * 부모 노드의 키 값이 자식 노드보다 작거나 같은 완전이진트리
    * [ Key(부모) <= Key(자식) ]
                         
<div align = "center">
  
  ![최소힙](https://user-images.githubusercontent.com/71704350/152285299-ff37cceb-11d0-4e8c-b7cc-f0bc1493b698.png)
  
</div>
