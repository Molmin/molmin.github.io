本题中要求求出相同起点，不同终点的结果。不妨将起点和终点连一条边，这样就变成了求一条欧拉回路。

为了存在欧拉回路，图中必须全为偶点。我们考虑将奇点两两配对连边。由于此题边权设置的特殊性，可以优先考虑将相邻的奇点连边。即按编号从小到大，第 $1$ 个奇点与第 $2$ 个奇点配对，第 $3$ 个奇点与第 $4$ 个奇点配对，以此类推。考虑到欧拉回路的另一个存在条件为图是连通图，尽可能在连边的时候多连通几个点，所以可以在为 $u$ 和 $v$ 连边时转化成编号相邻的点连边（不妨设 $u<v$，即 $u$ 与 $u+1$ 连边，$u+1$ 与 $u+2$ 连边，以此类推直到 $v-1$ 与 $v$ 连边。

下面处理依然未被连通的块。不妨将每个连通块视为一个点，两个连通块之间的边权为连通这两个连通块所需的最小边权，接着需要求出一种连边方式，使得图连通且边权总和尽可能小，也就转化成了求最小生成树的问题。

事实上，整个计算过程中都无需使用给定的 $m$ 条边的具体数据，于是我们可以不记录边的信息，只记录每个点的度数，再用并查集维护连通块的情况。

算法中为奇点配对时间复杂度 $\Theta(n)$，连边时虽然要一个一个点连，但是至多连 $n-1$ 条边，时间复杂度也为 $\Theta(n)$；连通块之间连至多 $n$ 条边，按边权从小到大排序时间复杂度 $\Theta(n\log n)$，求最小生成树时间复杂度也为 $\Theta(n)$。上述过程要对每个终点都求一遍，时间复杂度为 $\Theta(n^2\log n)$。在输入 $m$ 条边统计信息时还有 $\Theta(m)$ 的时间复杂度。综上，总时间复杂度为 $\Theta(n^2\log n+m)$。
