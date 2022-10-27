考虑动态规划。记状态 $f_{i,\ j}$ 表示进行了 $i$ 次抽卡，最后共有连续的 $j$ 次抽卡没有成功的概率。$ans_i$ 表示进行了 $i$ 次抽卡，抽卡成功的期望次数（故答案为 $ans_n$）。

对于 $f_{i,\ 0}$，若之前连续 $j$ 次失败，则这次有 $p_j$ 的概率成功，故

$$
f_{i,\ 0}=\sum_{j=0}^kp_jf_{i-1,\ j}.
$$

对于 $f_{i,\ j}$（$j > 0$），之前必须有连续 $j-1$ 次失败，且这次有 $p_{j-1}$ 的概率成功，故

$$
f_{i,\ j}=p_{j-1}\cdot f_{i-1,\ j-1}.
$$

下面讨论如何求答案。对于第 $i$ 次抽卡，若之前共有连续 $j$ 次失败，则第 $i$ 次抽卡有 $f_{i-1,\ j}\cdot p_j$ 的概率成功。故

$$
ans_t=\sum_{i=1}^t\sum_{j=0}^k f_{i-1,\ j}\cdot p_j.
$$

又易得

$$
ans_i=ans_{i-1}+\sum_{j=0}^k f_{i-1,\ j}\cdot p_j.
$$

对第 $i$ 次抽卡的数据进行打包，记

$$
M_{i}=\begin{bmatrix}
\color{blue}f_{i,\ 0} & f_{i,\ 1} & \cdots & f_{i,\ k} & \color{green}ans_{i}
\end{bmatrix}.
$$

观察发现 $M_i$ 的求法只依赖于 $f_{i-1,\ j}$ 和 $ans_{i-1}$ 以及常量 $p_j$，故可以列出矩阵乘法等式：记

$$
S=\begin{bmatrix}
\color{blue}p_0 & \color{orange}1-p_0 & \color{#bbb}0 & \color{#bbb}\cdots & \color{#bbb}0 & \color{green}p_0 \\
\color{blue}p_1 & \color{#bbb}0 & \color{orange}1-p_1 & \color{#bbb}\cdots & \color{#bbb}0 & \color{green}p_1 \\
\color{blue}\vdots & \color{#bbb}\vdots & \color{#bbb}\vdots & \color{#bbb}\ddots & \color{#bbb}\vdots & \color{green}\vdots \\
\color{blue}p_{k-1} & \color{#bbb}0 & \color{#bbb}0 & \color{#bbb}\cdots & \color{orange}1-p_{k-1} & \color{green}p_{k-1} \\
\color{blue}p_k=1 & \color{#bbb}0 & \color{#bbb}0 & \color{#bbb}\cdots & \color{#bbb}0 & \color{green}p_k=1 \\
\color{#bbb}0 & \color{#bbb}0 & \color{#bbb}0 & \color{#bbb}\cdots & \color{#bbb}0 & \color{green}1 \\
\end{bmatrix},
$$

则 $M_{i-1}\cdot S=M_i$。

故 $M_n=M_0\cdot S^n$，而显然有

$$
M_0=\begin{bmatrix}
\color{blue}1 & 0 & 0 & \cdots & 0 & \color{green}0
\end{bmatrix}.
$$

于是使用矩阵快速幂即可求得答案。
