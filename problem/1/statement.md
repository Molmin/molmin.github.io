## 【题目大意】

设 $u(n)$ 为不超过 $n$ 的最大素数，$v(n)$ 为超过 $n$ 的最小素数。

给定 $n$，求 $\sum\limits_{i=2}^{n}\dfrac 1{u(i)v(i)}$。

$1\leq T\leq 500$，$1\leq n\leq 10^9$

## 【题目描述】

Let's assume that

- $v(n)$ is the largest prime number, that does not exceed $n$;
- $u(n)$ is the smallest prime number strictly greater than $n$.

Find $\sum\limits_{i=2}^n\dfrac 1{u(n)v(n)}$.

## 【输入格式】

The first line contains integer $t(1\leq t\leq 500)$ — the number of testscases.

Each of the following $t$ lines of the input contains integer $n$ ($2\leq n\leq 10^9$).

## 【输出格式】

Print $t$ lines: the $i$-th of them must contain the answer to the $i$ -th test as an irreducible fraction "$p\texttt{/}q$", where $p,\ q$ are integers, $q>0$.

## 【样例输入输出】

### 样例输入 #1

```
2
2
3
```

### 样例输出 #1

```
1/6
7/30
```
