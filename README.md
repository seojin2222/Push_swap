# Push_swap
Description

push_swap는 두 개의 스택 a, b와 제한된 명령어만 사용해서 주어진 정수들을 오름차순으로 정렬하는 42 프로젝트입니다. 프로그램은 정렬 과정 자체를 수행하는 것이 아니라, 정렬에 필요한 명령어들을 표준 출력으로 출력합니다.

이 프로젝트의 핵심 목표는 다음과 같습니다.

올바른 파싱과 에러 처리
중복 없는 정수 입력 검증
제한된 명령어만으로 정렬 수행
가능한 적은 연산 수로 정렬하기
시간복잡도와 정렬 전략 이해

Allowed operations
sa : stack a의 top 두 개를 swap
sb : stack b의 top 두 개를 swap
ss : sa + sb
pa : b의 top을 a로 push
pb : a의 top을 b로 push
ra : a를 rotate
rb : b를 rotate
rr : ra + rb
rra : a를 reverse rotate
rrb : b를 reverse rotate
rrr : rra + rrb

Sorting strategy
이 구현은 입력 크기에 따라 정렬 방식을 나눕니다.
2개: 필요한 경우 sa
3개: sort_three
5개 이하: 가장 작은 값을 위로 보낸 뒤 pb, 이후 3개 정렬, 다시 pa

그 이상:
값을 압축하여 0 ~ n - 1 범위의 rank로 변환
chunk 단위로 a -> b 이동
b에서 가장 큰 값을 다시 a로 복원
즉, 작은 입력은 작은 정렬 전용 로직을 사용하고, 큰 입력은 coordinate compression + chunk sort 방식으로 처리합니다.

├── Makefile

├── push_swap.h

├── main.c

├── init_ps.c

├── count_total_numbers.c

├── parse_utils.c

├── ft_split.c

├── is_sorted.c

├── sort_stack.c

├── sort_chunk.c

├── stack_ops.c

├── stack_ops2.c

└── stack_ops3.c

Instructions
Compile
```bash
make
```
Run
```bash
./push_swap 2 1 3 6 5 8
```
또는
```bash
./push_swap "3 2 1 6 5 4"
```
```bash
$ ./push_swap 2 1 3
sa
```
Error cases
다음과 같은 경우 Error를 출력해야 합니다.
정수가 아닌 인자
int 범위를 넘는 값
중복 값
잘못된 형식의 입력

```bash
$ ./push_swap 0 one 2 3
Error
```

Benchmark
이 프로젝트는 단순히 정렬만 하는 것이 아니라, 연산 수를 줄이는 것도 중요합니다.
작은 입력은 최소 동작 위주로 처리하고, 큰 입력은 chunk 정렬을 통해 연산 수를 줄이는 방향으로 구현했습니다.

Notes
전역 변수는 사용하지 않습니다.
입력이 없으면 아무것도 출력하지 않고 종료합니다.
모든 동적 할당 메모리는 적절히 해제해야 합니다.
프로젝트는 Norm을 준수해야 합니다.

Resources
42 push_swap subject PDF
Coordinate Compression 개념
Stack-based sorting 전략
Big-O 및 정렬 알고리즘 복잡도 기초 자료

AI usage
AI는 아래 작업에만 보조적으로 사용했습니다.
README 구조 초안 정리
코드 스타일 / Norm 점검 보조
정렬 전략 설명 문장 정리

AI가 제안한 내용은 그대로 복사하지 않고, 직접 코드와 과제 명세를 확인하며 수정했습니다.