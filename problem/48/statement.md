## 【题目描述】

鑫冠来到了费客霞所居住的城市。

城市中有 $n$ 个小区，其中第 $i$ 个小区有 $a_i$ 个人。

每一天早上,智慧的鑫冠都会**等概率随机选中一个尚未建交的人**，然后乘坐丙独航空的飞机去与其建交。由于获得了地缘优势，在这一天的剩余时间，鑫冠会通过其强大的外交能力与**该人所在小区的所有居民**的免疫政府建立外交关系。（这些居民和一开始被选中的人都被认为是在“当天”建交）

费客霞居住在 $1$ 号小区，他的免疫政府希望与鑫冠建立外交以获得它的技术。请你帮忙算一算，费客霞免疫政府与鑫冠建交的期望时间是多少天。

## 【输入格式】

第一行一个整数 $n$ 表示小区个数。

第二行 $n$ 个空格隔开的整数 $a_1,\ a_2,\ \cdots,\ a_n$，表示每个小区的人数。

## 【输出格式】

输出一个浮点数表示答案，保留到 $3$ 位小数。

## 【样例输入输出】

### 样例输入 #1

```
2
1 1
```

### 样例输出 #1

```
1.500
```

### 样例输入 #2

见选手目录下的 `ill/ex_ill2.in`。

### 样例输出 #2

见选手目录下的 `ill/ex_ill2.ans`。

### 样例输入 #3

见选手目录下的 `ill/ex_ill3.in`。

### 样例输出 #3

见选手目录下的 `ill/ex_ill3.ans`。

## 【数据范围】

对于 $20\%$ 的数据，$n\leq 20$；

对于另外 $20\%$ 的数据，$n\leq 1000$；

对于另外 $20\%$ 的数据，$a_i=1$；

对于所有数据，$1\leq n\leq 10^5$，$1\leq a_i\leq 10^9$。