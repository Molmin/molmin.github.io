## 【题目大意】

给定长度为 $n$ 的序列 $s$。

有 $t$ 次询问，每次询问给定 $l,\ r$，求出对于 $l\leq i\leq r$，存在一个 $l\leq k\leq r$，使得 $s_i\nmid s_k$ 的 $i$ 的个数。

$1\leq n,\ t\leq 10^5$，$1\leq s_i\leq 10^9$

## 【题目描述】

Mole is hungry again. He found one ant colony, consisting of $n$ ants, ordered in a row. Each ant $i$ ( $1<=i<=n$ ) has a strength $s_{i}$ .

In order to make his dinner more interesting, Mole organizes a version of `Hunger Games` for the ants. He chooses two numbers $l$ and $r$ ( $1<=l<=r<=n$ ) and each pair of ants with indices between $l$ and $r$ (inclusively) will fight. When two ants $i$ and $j$ fight, ant $i$ gets one battle point only if $s_{i}$ divides $s_{j}$ (also, ant $j$ gets one battle point only if $s_{j}$ divides $s_{i}$ ).

After all fights have been finished, Mole makes the ranking. An ant $i$ , with $v_{i}$ battle points obtained, is going to be freed only if $v_{i}=r-l$ , or in other words only if it took a point in every fight it participated. After that, Mole eats the rest of the ants. Note that there can be many ants freed or even none.

In order to choose the best sequence, Mole gives you $t$ segments $[l_{i},r_{i}]$ and asks for each of them how many ants is he going to eat if those ants fight.

## 【输入格式】

The first line contains one integer $n$ ($1 ≤ n ≤ 10^5$), the size of the ant colony.

The second line contains $n$ integers $s_1, s_2, \ldots, s_n$ ($1 ≤ s_i ≤ 10^9$), the strengths of the ants.

The third line contains one integer $t$ ($1 ≤ t ≤ 10^5$), the number of test cases.

Each of the next $t$ lines contains two integers $l_i$ and $r_i$ ($1 ≤ l_i ≤ r_i ≤ n$), describing one query.

## 【输出格式】

Print to the standard output $t$ lines. The $i$-th line contains number of ants that Mole eats from the segment $[l_i, r_i]$.

## 【样例输入输出】

### 样例输入 #1

```
5
1 3 2 4 2
4
1 5
2 5
3 5
4 5
```

### 样例输出 #1

```
4
4
1
1
```

## 【提示】

In the first test battle points for each ant are $v = [4, 0, 2, 0, 2]$, so ant number $1$ is freed. Mole eats the ants $2, 3, 4, 5$.

In the second test case battle points are $v = [0, 2, 0, 2]$, so no ant is freed and all of them are eaten by Mole.

In the third test case battle points are $v = [2, 0, 2]$, so ants number $3$ and $5$ are freed. Mole eats only the ant $4$.

In the fourth test case battle points are $v = [0, 1]$, so ant number $5$ is freed. Mole eats the ant $4$.
