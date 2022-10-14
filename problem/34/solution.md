由于题目要求各个集合内的人最终位置相同，而不同集合的人最终位置不同，容易想到容斥。

记 $A,\ B,\ C$ 分别表示三个集合内的人，$f(S)$ 为集合 $S$ 内的人走 $m$ 步到同一个点的方案数，则易得答案为

$$
f(A)f(B)f(C)-\sum_{\text{cyc}}f(A\cup B)f(C)+2f(A\cup B\cup C).
$$

首先考虑从一个点到另一个点的走法有多少种。

特判两种特殊情况：一是坐标奇偶性与步数不符，二是距离过远无法到达。

我们将从原点 $(0,\ 0)$ 开始，走 $m$ 步到达某个坐标的方案数列出来，这可以用手动递推解决，为了描述方便，我们把坐标系旋转 $45^\circ$。

当 $m=3$ 时，结果为

$$
\begin{matrix}
1 & 3 & 3 & 1 \\
3 & 9 & 9 & 3 \\
3 & 9 & 9 & 3 \\
1 & 3 & 3 & 1
\end{matrix}
$$

但是这样似乎并没有什么规律，那么当 $m=4$ 时，结果为

$$
\begin{matrix}
1 & 4 & 6 & 4 & 1 \\
4 & 16 & 24 & 16 & 4 \\
6 & 24 & 36 & 24 & 6 \\
4 & 16 & 24 & 16 & 4 \\
1 & 4 & 6 & 4 & 1
\end{matrix}
$$

这里有个明显的特征就是矩阵四条边是组合数，仔细观察也可以发现中间每个数都是所在行第一个数与所在列第一个数的乘积。

下面使用数学归纳法证明这个结论。

当 $m=1$ 时，结论显然成立。

若 $m=t-1\geq 1$ 时结论成立，则矩阵为

$$
\begin{matrix}
C_{t-1}^0 & C_{t-1}^1 & C_{t-1}^2 & \cdots & C_{t-1}^{i-2} & C_{t-1}^{i-1} \\
C_{t-1}^1 & C_{t-1}^1\cdot C_{t-1}^1 & C_{t-1}^1\cdot C_{t-1}^2 & \cdots & C_{t-1}^1\cdot C_{t-1}^{i-2} & C_{t-1}^{i-2} \\
C_{t-1}^2 & C_{t-1}^2\cdot C_{t-1}^1 & C_{t-1}^2\cdot C_{t-1}^2 & \cdots & C_{t-1}^2\cdot C_{t-1}^{i-2} & C_{t-1}^{i-3} \\
\vdots & \vdots & \vdots & \ddots & \vdots & \vdots \\
C_{t-1}^{i-2} & C_{t-1}^{i-2}\cdot C_{t-1}^1 & C_{t-1}^{i-2}\cdot C_{t-1}^2 & \cdots & C_{t-1}^{i-2}\cdot C_{t-1}^{i-2} & C_{t-1}^1 \\
C_{t-1}^{i-1} & C_{t-1}^{i-2} & C_{t-1}^{i-3} & \cdots & C_{t-1}^1 & C_{t-1}^0
\end{matrix}
$$

设上面矩阵的行与列从 $1$ 开始编号，且第 $i$ 行第 $j$ 列的数为 $a_{i,\ j}$，那么有

$$
a_{i,\ j}=\binom{t-1}{i-1}\cdot \binom{t-1}{j-1}.
$$

则当 $m=t$ 时，设其矩阵的行与列从 $0$ 开始编号，且第 $i$ 行第 $j$ 列的数为 $b_{i,\ j}$，则易得

$$
\begin{aligned}
b_{i,\ j} & = a_{i,\ j}+a_{i+1,\ j}+a_{i,\ j+1}+a_{i+1,\ j+1} \\
& = \binom{t-1}{i-1}\cdot \binom{t-1}{j-1}+\binom{t-1}i\cdot \binom{t-1}{j-1}+\binom{t-1}{i-1}\cdot \binom{t-1}j+\binom{t-1}i\cdot \binom{t-1}j \\
& = \left[\binom{t-1}{i-1}+\binom{t-1}i\right]\cdot\left[\binom{t-1}{j-1}+\binom{t-1}j\right] \\
& = \binom ti\cdot\binom tj.
\end{aligned}
$$

结论成立，**证毕**。

我们枚举该集合 $S$ 中的人最终到达的坐标（这里指的是旋转后的坐标）。则方法数为

$$
\begin{aligned}
T & = \sum_{x_0}\sum_{y_0}\prod_{P\in S}\binom m{|x_P-x_0|}\binom m{|y_P-y_0|} \\
& = \sum_{x_0}\sum_{y_0}\left[\prod_{P\in S}\binom m{|x_P-x_0|}\prod_{P\in S}\binom m{|y_P-y_0|}\right] \\
& = \sum_{x_0}\left[\prod_{P\in S}\binom m{|x_P-x_0|}\sum_{y_0}\prod_{P\in S}\binom m{|y_P-y_0|}\right] \\
\end{aligned}
$$

我们发现 $\prod\limits_{P\in S}\dbinom m{|y_P-y_0|}$ 与 $x_0$ 无关，那么只需预处理这个式子，在枚举时就可以做到 $\Theta(n^2)$。

代码与最终式子稍有不同，因为写题解的时候是重新推的 ……
