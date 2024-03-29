考虑令一个数一定选择，那么我们枚举它的因数，对每个是因数倍数的数进行统计，判断是否存在一个数量 $\geq\dfrac n2$ 即可。

时间复杂度：找出所有因数 $\Theta(n)$，排序 $\Theta(n\log n)$，统计 $\Theta(n+d^2(n))$，总时间复杂度 $\Theta(n\log n+d^2(n))$。

那么随机选取 $x$ 个数如上计算，由于每个数不被选中的概率是 $\dfrac 12$，故这样的随机化算法有 $\dfrac 1{2^x}$ 的概率出错。那么 $x$ 取到 $12$ 左右即可 AC。

由于这里 $n$ 最大到 $10^6$，直接使用 `rand()` 容易挂，改为 `((long long)rand()<<31)|rand()` 较为保险。
