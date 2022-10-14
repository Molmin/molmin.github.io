## 【题目大意】

给定一个 $n$ 个点，$m$ 条边的无向图，每个点都至少连 $k$ 条边。求图中的任意一个长度至少为 $k+1$ 的简单环。

$3\leq n,\ m\leq 10^5$ ， $2\leq k < n$ 

## 【题目描述】

You've got a undirected graph $G$ , consisting of $n$ nodes. We will consider the nodes of the graph indexed by integers from 1 to $ n $ . We know that each node of graph $ G$ is connected by edges with at least $k$ other nodes of this graph. Your task is to find in the given graph a simple cycle of length of at least $ k+1 $ .

A simple cycle of length $d$ $(d>1)$ in graph $ G $ is a sequence of distinct graph nodes $v_{1},v_{2},...,v_{d}$ such, that nodes $ v_{1} $ and $ v_{d} $ are connected by an edge of the graph, also for any integer $ i $ $ (1<=i&lt;d) $ nodes $ v_{i} $ and $ v_{i+1} $ are connected by an edge of the graph.

## 【输入格式】

The first line contains three integers $ n $ , $ m $ , $ k $ $ (3<=n,m<=10^{5}; 2<=k<=n-1) $ — the number of the nodes of the graph, the number of the graph's edges and the lower limit on the degree of the graph node. Next $ m $ lines contain pairs of integers. The $ i $ -th line contains integers $ a_{i} $ , $ b_{i} $ $ (1<=a_{i},b_{i}<=n; a_{i}≠b_{i}) $ — the indexes of the graph nodes that are connected by the $ i $ -th edge.

It is guaranteed that the given graph doesn't contain any multiple edges or self-loops. It is guaranteed that each node of the graph is connected by the edges with at least $ k $ other nodes of the graph.

## 【输出格式】

In the first line print integer $r(r>=k+1)$ — the length of the found cycle. In the next line print $r$ distinct integers $ v_{1},v_{2},...,v_{r} $ $ (1<=v_{i}<=n) $ — the found simple cycle.

It is guaranteed that the answer exists. If there are multiple correct answers, you are allowed to print any of them.

## 【样例输入输出】

### 样例输入 #1

```
3 3 2
1 2
2 3
3 1
```

### 样例输出 #1

```
3
1 2 3
```

### 样例输入 #2

```
4 6 3
4 3
1 2
1 3
1 4
2 3
2 4
```

### 样例输出 #2

```
4
3 4 1 2
```
