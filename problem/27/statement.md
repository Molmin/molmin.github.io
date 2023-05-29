## 题目大意

有 $N+M$ 个问题，其中有 $N$ 个问题的答案是 `YES`，$M$ 个问题的答案是 `NO`。当你回答一个问题之后，会知道这个问题的答案，求最优策略下期望对多少。

答案对 $998244353$ 取模。

## 题目描述

You are participating in a quiz with $N+M$ questions and Yes/No answers.

It's known in advance that there are $N$ questions with answer Yes and $M$ questions with answer No, but the questions are given to you in random order.

You have no idea about correct answers to any of the questions. You answer questions one by one, and for each question you answer, you get to know the correct answer immediately after answering.

Suppose you follow a strategy maximizing the expected number of correct answers you give.

Let this expected number be $P/Q$ , an irreducible fraction. Let $M=998244353$ . It can be proven that a unique integer $R$ between $0$ and $M-1$ exists such that $P=Q\times R$ modulo $M$ , and it is equal to $P\times Q^{-1}$ modulo $M$ , where $Q^{-1}$ is the modular inverse of $Q$ . Find $R$ .

## 输入格式

Input is given from Standard Input in the following format: $N\quad M$ 

## 输出格式

Let $P/Q$ be the expected number of correct answers you give if you follow an optimal strategy, represented as an irreducible fraction. Print $P\times Q^{-1}$ modulo $998244353$ .

## 样例输入输出

```input1
1 1
```

```output1
499122178
```

## 样例解释 1

There are two questions. You may answer randomly to the first question, and you'll succeed with 50% probability. Then, since you know the second answer is different from the first one, you'll succeed with 100% probability.

The expected number of your correct answers is $\dfrac 32$ . Thus, $P=3$ , $Q=2$ , $Q^{-1}=499122177$ (modulo $998244353$ ), and $P\times Q^{-1}=499122178$ (again, modulo $998244353$ ).

```input2
2 2
```

```output2
831870297
```

## 样例解释 2

The expected number of your correct answers is $\dfrac{17}{6}$ .

```input3
3 4
```

```output3
770074220
```

## 样例解释 3

The expected number of your correct answers is $\dfrac{169}{35}$ .

```input4
10 10
```

```output4
208827570
```

```input5
42 23
```

```output5
362936761
```

## 数据范围

- $1\leq N,\ M\leq 500,000$
- Both $N$ and $M$ are integers.

## Partial Score

- $1500$ points will be awarded for passing the testset satisfying $N=M$ and $1\leq N, M\leq 10^5$ .
