因为 $m=n-1$ 或 $m=n$，所以本题的构成的图为一棵基环树或普通树。

**【定义】** 基环树中，对于环上结点，称相邻的环上的结点为父亲结点，其余向另结点为儿子结点。

考虑动态规划。

记 $\text{fa}_ u$ 表示结点 $u$ 的父亲结点个数；$\text{son}_ u$ 表示结点 $u$ 的儿子结点个数；$w_{u-v}$ 表示结点 $u$ 和 $v$  。

记状态 $\text{up}_ u$ 表示以结点 $u$ 为起点，第一步向父亲结点走，最终的期望路径长度；状态 $\text{down}_ u$ 表示以结点 $u$ 为起点，第一步向儿子结点走，最终的期望路径长度。

下面先考虑普通树的做法。

### down 的求法

对于一个结点 $u$，若是叶子结点，为方便处理，令 $\text{down}_ u=0$。

若是非叶子结点，则第一步必须向其儿子结点走，若向儿子结点 $v$ 走，那么此时贡献的路径长度期望为

$$
\text{down}_v+w_{u-v}.
$$

那么易知

$$
\text{down}_u=\frac{\sum\limits_{(u,\ v)\in E}\text{down}_v+w_{u-v}}{\text{son}_u}.
$$

### $\text{up}$ 的求法

记 $u$ 的父亲结点为 $v$，则第一步必须向其父亲结点走，故贡献长度 $w_{u-v}$。

接着会向 $v$ 的相邻结点走。各个情况的期望和（注意不能走回结点 $u$）为

$$
\text{up}_v\times\text{fa}_v+\text{down}_v\times\text{son}_v-(w_{u-v}+\text{down}_u).
$$

那么易得

$$
\text{up}_u=w_{u-v}+\frac{\text{up}_v\times\text{fa}_v+\text{down}_v\times\text{son}_v-(w_{u-v}+\text{down}_u)}{\text{fa}_v+\text{son}_v-1}.
$$

容易发现 $\text{up}_u$ 的值依赖于其父亲结点的有关信息，那么只需从上到下依次处理即可。

特别地，根结点的 $\text{up}$ 值为 $0$（显然）。

### 基环树做法

对于基环树的情况，容易发现 $\text{down}$ 值的处理是类似的。而 $\text{up}$ 值的边界处理略有不同。

考虑环上结点的 $\text{up}$ 值求法。这里环上结点数量 $\leq 20$，故考虑枚举环上的结点 $u$ 分别求出 $\text{up}$ 值。

那么第一步必须向环上 $u$ 的相邻结点走。

首先按一定方向从结点 $u$ 开始遍历一遍环。设 $\text{mul}$ 表示走到当前这个点的概率。那么由结点 $u$ 走到第一个遇到的结点，概率为 $\dfrac 12$，故初始化 $\text{mul}\gets\dfrac 12$。

遇到一个新点 $v$ 时，设前一个点为 $t$。首先要加上之间连接的这条边的贡献即 $w_{v-t}$，然后由于有 $\dfrac{\text{son}_v}{\text{son}_v+1}$ 的概率进入这棵子树，故应更新值：

$$
\text{up}_u\gets\text{up}_u+\left(\frac{\text{son}_v}{\text{son}_v+1}\cdot\text{down}_v+w_{v-t}\right)\times\text{mul}.
$$

因为有 $\dfrac{\text{son}_v}{\text{son}_v+1}$ 的概率进入以 $v$ 为根的这棵树，故应更新 $\text{mul}$ 的值：

$$
\text{mul}\gets\frac{\text{mul}}{\text{son}_v+1}.
$$

考虑一种特殊情况：绕完一圈后到了 $u$ 的前一格，只能进入所在树内，故此时应更新：

$$
\text{up}_u\gets\text{up}_u+(\text{down}_v+w_{u-v})\times\text{mul}.
$$

最后，易知答案为

$$
\sum_{u=1}^n\frac{\text{up}_u\cdot\text{fa}_u+\text{down}_u\cdot\text{son}_u}{\text{fa}_u+\text{son}_u}.
$$
