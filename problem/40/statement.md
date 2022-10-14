## 【题目大意】

有一个 $1\sim n$ 的排列 $a_1,\ a_2,\ \cdots,\ a_n$，每次操作可以删去其中的一个数，并选择一个当前与这个数相邻的数记录到一个初始为空的序列 $b$ 的末尾，删去之后剩下的部分按顺序拼接在一起成为一个新的序列，这样进行 $k$ 次操作可以得到一个长度为 $k$ 的序列 $b_1,\ b_2,\ \cdots,\ b_k$。比如排列 $3,\ 1,\ 2$ 上，可以删除 $1$ 记录 $2$，得到 $a$ 序列 $3,\ 2$，再删除 $2$ 记录 $3$；两次操作后 $b$ 序列为 $2,\ 3$。

给定一个元素互不相同的序列 $b$，求有多少种可能的操作序列，两个操作序列不同，当且仅当某一步删除的元素不同，输出总方案数模 $998244353$ 的结果。

## 【题目描述】

We start with a permutation $ a_1, a_2, \ldots, a_n $ and with an empty array $ b $ . We apply the following operation $ k $ times.

On the $ i $ -th iteration, we select an index $ t_i $ ( $ 1 \le t_i \le n-i+1 $ ), remove $ a_{t_i} $ from the array, and append one of the numbers $ a_{t_i-1} $ or $ a_{t_i+1} $ (if $ t_i-1 $ or $ t_i+1 $ are within the array bounds) to the right end of the array $ b $ . Then we move elements $ a_{t_i+1}, \ldots, a_n $ to the left in order to fill in the empty space.

You are given the initial permutation $ a_1, a_2, \ldots, a_n $ and the resulting array $ b_1, b_2, \ldots, b_k $ . All elements of an array $ b $ are distinct. Calculate the number of possible sequences of indices $ t_1, t_2, \ldots, t_k $ modulo $ 998\,244\,353 $ .

## 【输入格式】

Each test contains multiple test cases. The first line contains an integer $ t $ ( $ 1 \le t \le 100\,000 $ ), denoting the number of test cases, followed by a description of the test cases.

The first line of each test case contains two integers $ n, k $ ( $ 1 \le k < n \le 200\,000 $ ): sizes of arrays $ a $ and $ b $ .

The second line of each test case contains $ n $ integers $ a_1, a_2, \ldots, a_n $ ( $ 1 \le a_i \le n $ ): elements of $ a $ . All elements of $ a $ are distinct.

The third line of each test case contains $ k $ integers $ b_1, b_2, \ldots, b_k $ ( $ 1 \le b_i \le n $ ): elements of $ b $ . All elements of $ b $ are distinct.

The sum of all $ n $ among all test cases is guaranteed to not exceed $ 200\,000 $ .

## 【输出格式】

For each test case print one integer: the number of possible sequences modulo $ 998\,244\,353 $ .

## 【样例输入输出】

### 样例输入 #1

```
3
5 3
1 2 3 4 5
3 2 5
4 3
4 3 2 1
4 3 1
7 4
1 4 7 3 6 2 5
3 2 4 5
```

### 样例输出 #1

```
2
0
4
```

### 样例解释 #1 

Let's denote as $ a_1 a_2 \ldots \not{a_i} \underline{a_{i+1}} \ldots a_n \rightarrow a_1 a_2 \ldots a_{i-1} a_{i+1} \ldots a_{n-1} $ an operation over an element with index $ i $ : removal of element $ a_i $ from array $ a $ and appending element $ a_{i+1} $ to array $ b $ .

In the first example test, the following two options can be used to produce the given array $ b $ :

$ 1 2 \underline{3} \not{4} 5 \rightarrow 1 \underline{2} \not{3} 5 \rightarrow 1 \not{2} \underline{5} \rightarrow 1 2 $ ; $ (t_1, t_2, t_3) = (4, 3, 2) $ ;

$ 1 2 \underline{3} \not{4} 5 \rightarrow \not{1} \underline{2} 3 5 \rightarrow 2 \not{3} \underline{5} \rightarrow 1 5 $ ; $ (t_1, t_2, t_3) = (4, 1, 2) $ .

In the second example test, it is impossible to achieve the given array no matter the operations used. That's because, on the first application, we removed the element next to $ 4 $ , namely number $ 3 $ , which means that it couldn't be added to array $ b $ on the second step.

In the third example test, there are four options to achieve the given array $ b $ :

$ 1 4 \not{7} \underline{3} 6 2 5 \rightarrow 1 4 3 \not{6} \underline{2} 5 \rightarrow \not{1} \underline{4} 3 2 5 \rightarrow 4 3 \not{2} \underline{5} \rightarrow 4 3 5 $ ;

$ 1 4 \not{7} \underline{3} 6 2 5 \rightarrow 1 4 3 \not{6} \underline{2} 5 \rightarrow 1 \underline{4} \not{3} 2 5 \rightarrow 1 4 \not{2} \underline{5} \rightarrow 1 4 5 $ ;

$ 1 4 7 \underline{3} \not{6} 2 5 \rightarrow 1 4 7 \not{3} \underline{2} 5 \rightarrow \not{1} \underline{4} 7 2 5 \rightarrow 4 7 \not{2} \underline{5} \rightarrow 4 7 5 $ ;

$ 1 4 7 \underline{3} \not{6} 2 5 \rightarrow 1 4 7 \not{3} \underline{2} 5 \rightarrow 1 \underline{4} \not{7} 2 5 \rightarrow 1 4 \not{2} \underline{5} \rightarrow 1 4 5 $ ;
