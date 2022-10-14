## 【题目大意】

给定一个有 $m$ 条无向边，至多有 $10^4$ 个点，可能有重边，不保证联通的图，请在这个图上找出两条路径，使得这两条路径覆盖了图中每一条边仅一次。

$1\leq m\leq 10^4$

## 【题目描述】

Once archaeologists found $ m $ mysterious papers, each of which had a pair of integers written on them. Ancient people were known to like writing down the indexes of the roads they walked along, as « $ a $ $ b $ » or « $ b $ $ a $ », where $ a,b $ are the indexes of two different cities joint by the road . It is also known that the mysterious papers are pages of two travel journals (those days a new journal was written for every new journey).

During one journey the traveler could walk along one and the same road several times in one or several directions but in that case he wrote a new entry for each time in his journal. Besides, the archaeologists think that the direction the traveler took on a road had no effect upon the entry: the entry that looks like « $ a $ $ b $ » could refer to the road from $ a $ to $ b $ as well as to the road from $ b $ to $ a $ .

The archaeologists want to put the pages in the right order and reconstruct the two travel paths but unfortunately, they are bad at programming. That’s where you come in. Go help them!

## 【输入格式】

The first input line contains integer $ m $ ( $ 1<=m<=10000 $ ). Each of the following $ m $ lines describes one paper. Each description consists of two integers $ a,b $ ( $ 1<=a,b<=10000 $ , $ a≠b $ ).

## 【输出格式】

In the first line output the number $ L_{1} $ . That is the length of the first path, i.e. the amount of papers in its description. In the following line output $ L_{1} $ space-separated numbers — the indexes of the papers that describe the first path. In the third and fourth lines output similarly the length of the second path $ L_{2} $ and the path itself. Both paths must contain at least one road, i.e. condition $ L_{1}&gt;0 $ and $ L_{2}&gt;0 $ must be met. The papers are numbered from $ 1 $ to $ m $ according to the order of their appearance in the input file. The numbers should be output in the order in which the traveler passed the corresponding roads. If the answer is not unique, output any.

If it’s impossible to find such two paths, output «-1».

Don’t forget that each paper should be used exactly once, i.e $ L_{1}+L_{2}=m $ .

## 【样例输入输出】

### 样例输入 #1

```
2
4 5
4 3
```

### 样例输出 #1

```
1
2 
1
1
```

### 样例输入 #2

```
1
1 2
```

### 样例输出 #2

```
-1
```
