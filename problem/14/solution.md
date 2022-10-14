镜像问题只需要把程序正反运行两遍即可。

考虑将一个无色项链染成小 Y 项链上对应的颜色的最小步数。动态规划：设在一个无色项链上将珠子区间 $[i,\ j]$ 染为小 Y 项链上对应颜色的最小步数为 $f_{i,\ j}$。

易得 $f_{i,\ i}=1$。

对于珠子区间 $[i,\ j]$，若 $b_i=b_j$ 即两端珠子目标颜色相同，那么此时情况等价于区间 $[i,\ j-1]$ 或者区间 $[i+1,\ j]$ 的情况；

若两端珠子目标颜色不同，就取一个中间节点 $k$（$i\leq k < j$），则 $f_{i,\ j}\leq f_{i,\ k}+f_{k+1,\ j}$。

于是我们就得到了 $\forall 1\leq i < j\leq n$，都有

$$
f_{i,\ j}=
\begin{cases} 
f_{i+1,\ j}, & \text{if }b_i=b_j \\
\min_{i\leq k < j}f_{i,\ k}+f_{k+1,\ j}, & \text{if }b_i\not=b_j
\end{cases}.
$$

再设 $g_i$ 为小 F 将项链上前 $i$ 个珠子染成和小 Y 一样的最小次数。

若 $a_i=b_i$，则无需考虑第 $i$ 个珠子，易得 $g_i=g_{i-1}$；

否则，可以任意选取 $1\leq j\leq i$，染前 $j-1$ 个珠子需要 $g_{j-1}$ 次，染区间 $[j,\ i]$ 的珠子需要 $f_{j,\ i}$ 次。

于是，$\forall 1\leq i\leq n$，

$$
g_i=
\begin{cases} 
g_{i-1}, & \text{if }a_i=b_i \\
\min_{i\leq j\leq i}g_{j-1}+f_{j,\ i}, & \text{if }a_i\not=b_i
\end{cases}.
$$

时间复杂度 $\Theta(n^3)$。
