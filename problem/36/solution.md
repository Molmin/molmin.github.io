对原式进行转换，得

$$
\begin{aligned}
  & \sum_{i=1}^N\sum_{j=1}^N\min\{|x_i-x_j|,\ |y_i-y_j|\} \\
= & \sum_{i=1}^N\sum_{j=1}^N\left(|x_i-x_j|+|y_i-y_j|-\max\{|x_i-x_j|,\ |y_i-y_j|\}\right) \\
= & \sum_{i=1}^N\sum_{j=1}^N\left(|x_i-x_j|+|y_i-y_j|\right)-\sum_{i=1}^N\sum_{j=1}^N\max\{|x_i-x_j|,\ |y_i-y_j|\}.
\end{aligned}
$$

讨论上式的右半部分。若将 $(x_i,\ y_i)$ 视为一个点的坐标，那么右侧即求任意两点间切比雪夫距离。

将切比雪夫距离转换为曼哈顿距离：逆时针旋转 $45^\circ$ 整个坐标系（即一个点 $(x_i,\ y_i)$ 变为 $(\dfrac{x_i-y_i}{\sqrt 2},\ \dfrac{x_i+y_i}{\sqrt 2})$），此时对于任意的两个点，转换前两点之间的切比雪夫距离是现在两点之间曼哈顿距离的 $\dfrac{\sqrt 2}2$ 倍。那么有

$$
\begin{aligned}
  & \sum_{i=1}^N\sum_{j=1}^N\max\{|x_i-x_j|,\ |y_i-y_j|\} \\
= & \sum_{i=1}^N\sum_{j=1}^N\dfrac{\sqrt 2}2\left(\left|\dfrac{x_i-y_i}{\sqrt 2}-\dfrac{x_j-y_j}{\sqrt 2}\right|+\left|\dfrac{x_i+y_i}{\sqrt 2}-\dfrac{x_j+y_j}{\sqrt 2}\right|\right) \\
= & \frac 12\sum_{i=1}^N\sum_{j=1}^N[|(x_i-y_i)-(x_j-y_j)|+|(x_i+y_i)-(x_j+y_j)|].
\end{aligned}
$$
观察发现这个结果与左半部分较为相似。有

$$
\begin{aligned}
  & \sum_{i=1}^N\sum_{j=1}^N\left(|x_i-x_j|+|y_i-y_j|\right) \\
= & \sum_{i=1}^N\sum_{j=1}^N|x_i-x_j|+\sum_{i=1}^N\sum_{j=1}^N|y_i-y_j| \\
\end{aligned}
$$

容易发现对于 $x$ 和 $y$ 是相对独立的，那么只需要考虑计算 $\sum\limits_{i=1}^N\sum\limits_{j=1}^N|x_i-x_j|$ 即可。

首先将 $x$ 数组排序。那么上式等于 $2\times \sum\limits_{i=1}^N\sum\limits_{j=1}^{i-1}(x_i-x_j)$。

从先往后遍历整个序列。遇到一个新的数 $x_i$，只需将答案加上 $\sum\limits_{j=1}^{i-1}(x_i-x_j)=(i-1)x_i-\sum\limits_{j=1}^{i-1}x_j$ 即可。
