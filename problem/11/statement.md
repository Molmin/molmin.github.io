## 【题目大意】 

定义：设一个单调不降的序列 $a$ 的所有数的平均数为 $x$，则 $a$ 是**糟糕的** $\Leftrightarrow a$ 中大于 $x$ 的数的个数 $>a$ 中小于 $x$ 的数的个数。

定义：一个单调不降的序列不存在它的一个子序列是糟糕的，则称这个子序列是**好的**；否则，称这个子序列是**坏的**。

给定长度为 $n$ 的单调不降的序列 $a$，求 $a$ 的好的子序列的最大长度。

测试数据组数 $T\leq 10^4$，$2\leq n\leq 2\times 10^5$，$2\leq\sum n\leq 2\times 10^5$，$1\leq a_i\leq 10^9$

## 【题目描述】 

Let's call an array of $ k $ integers $ c_1, c_2, \ldots, c_k $ terrible, if the following condition holds:

- Let $ AVG $ be the $ \frac{c_1 + c_2 + \ldots + c_k}{k} $ (the average of all the elements of the array, it doesn't have to be integer). Then the number of elements of the array which are bigger than $ AVG $ should be strictly larger than the number of elements of the array which are smaller than $ AVG $ . Note that elements equal to $ AVG $ don't count.
  
  For example $ c = \{1, 4, 4, 5, 6\} $ is terrible because $ AVG = 4.0 $ and $ 5 $ -th and $ 4 $ -th elements are greater than $ AVG $ and $ 1 $ -st element is smaller than $ AVG $ .

Let's call an array of $ m $ integers $ b_1, b_2, \ldots, b_m $ bad, if at least one of its non-empty subsequences is terrible, and good otherwise.

You are given an array of $ n $ integers $ a_1, a_2, \ldots, a_n $ . Find the minimum number of elements that you have to delete from it to obtain a good array.

An array is a subsequence of another array if it can be obtained from it by deletion of several (possibly, zero or all) elements.

## 【输入格式】 

The first line contains an integer $ t $ ( $ 1 \le t \le 10^4 $ ) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $ n $ ( $ 2 \le n \le 2 \cdot 10^5 $ ) — the size of $ a $ .

The second line of each testcase contains $ n $ integers $ a_1, a_2, \ldots, a_n $ ( $ 1 \le a_i \le 10^9 $ ) — elements of array $ a $ .

In each testcase for any $ 1 \le i \lt n $ it is guaranteed that $ a_i \le a_{i+1} $ .

It is guaranteed that the sum of $ n $ over all testcases doesn't exceed $ 2 \cdot 10^5 $ .

## 【输出格式】 

For each testcase, print the minimum number of elements that you have to delete from it to obtain a good array.

## 【样例输入输出】 

### 样例输入 #1

```
4
3
1 2 3
5
1 4 4 5 6
6
7 8 197860736 212611869 360417095 837913434
8
6 10 56026534 405137099 550504063 784959015 802926648 967281024
```

### 样例输出 #1

```
0
1
2
3
```

## 【提示】 

In the first sample, the array $ a $ is already good.

In the second sample, it's enough to delete $ 1 $ , obtaining array $ [4, 4, 5, 6] $ , which is good.
