# [Silver III] $\frac{1}{2}$(MatKor+ALPS)=AlKor - 32385 

[문제 링크](https://www.acmicpc.net/problem/32385) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2025년 10월 2일 17:24:02

### 문제 설명

<p>고려대학교의 알고리즘 동아리에는 정보대학의 <code>ALPS</code>, 정보보호학부의 <code>MatKor</code>, 사이버국방학과의 <code>AlKor</code>가 있다. <code>ALPS</code> 회장은 $23$학번, <code>MatKor</code> 회장은 $21$학번, <code>AlKor</code> 회장은 $22$학번이다.</p>

<p>재현이는 우연히 <code>Alkor</code> 회장의 학번이 <code>MatKor</code>와 <code>ALPS</code> 회장 학번들의 평균임을 알게 되었다.</p>

<p>이를 본 승환이는 일반화하여 $A_{N+1}$이 $A_i\left(1\leq i\leq N \right)$의 평균, 즉 $\frac{1}{N}\sum_{i=1}^NA_i=A_{N+1}$을 만족하는 길이가 $N+1$인 수열 $A$를 재현이에게 찾아오라고 시켰다.</p>

<p>재현이를 도와 $N$이 주어질 때, 위 조건을 만족하며 서로 다른 정수로 이루어진 수열 $A$를 찾아보자.</p>

### 입력 

 <p>첫 번째 줄에 정수 $N(2\leq N\leq 10^4)$이 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 다음 조건을 모두 만족하는 정수 $A_1,A_2,\cdots ,A_{N+1}$을 공백으로 구분하여 출력한다.</p>

<ul>
	<li>$\frac{1}{N}\sum_{i=1}^{N}A_i=A_{N+1}$</li>
	<li>$-10^9\leq A_i\leq 10^9$</li>
	<li>모든 $A_i(1\leq i \leq N+1)$는 서로 다르다.</li>
</ul>

<p>위 조건을 만족하는 수열 $A$가 항상 존재함이 보장된다.</p>

