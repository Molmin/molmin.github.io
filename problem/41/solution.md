</p><div style="text-align: center;" class="mdui-typo"><p style='font-family: "font-copyright";'>本文作者为 <a href="//hydro.ac/user/8169">Ben'sGift</a>，版权归其所有。</p><p style='font-family: "font-copyright-link";'>转载于：<a href="//hydro.ac/d/HLpSet/p/P0001/solution/63358d228bbd87384c5a6d9a">//hydro.ac/d/HLpSet/p/P0001/solution/63358d228bbd87384c5a6d9a</a></p></div><p>

## 【题目大意】

若串联两个阻值分别为 $a$ 和 $b$ 的电阻，将会得到阻值为 $a+b$ 的电阻；若并联两个阻值分别为 $a$ 和 $b$ 的电阻，将会得到阻值为 $\Large\frac{1}{\frac{1}{a}+\frac{1}{b}}=\frac{1}{\frac{a+b}{ab}}=\frac{ab}{a+b}$ 的电阻。

现给定 $a$ 与 $b$，求最少需要多少个阻值为 $1$ 的电阻才能得到阻值为 $\Large\frac{a}{b}$ 的电阻。

## 【考场思路】

方便起见，阻值为 $x$ 的电阻称为 $R(x)$，$R(a)$ 与 $R(b)$ 串联，记为 $R(a)\oplus R(b)$，涉及的所有未知数均为正整数。

不妨设 $(a,b)=1$。

显然的，当 $a\geqslant b$ 时，可以用若干个 $ R(1)$ 进行串联，将其转化为 $a< b$ 的情况。

若将 $R(\frac{a_1}{b_1}),R(\frac{a_2}{b_2}),\cdots,R(\frac{a_n}{b_n})$ 并联，可以得到 $R\Large(\frac{\Pi_{i=1}^{n}a_i}{b_1a_2\cdots a_n+a_1b_2\cdots a_n+\cdots+a_1a_2\cdots b_n})$，提取公因式得 $R\Large(\frac{\Pi_{i=1}^{n}a_i}{\Pi_{i=1}^{n}a_i\cdot(\frac{b_1}{a_1}+\frac{b_2}{a_2}+\cdots+\frac{b_n}{a_n})})$，约分后为 $R\Large (\frac{1}{\frac{b_1}{a_1}+\frac{b_2}{a_2}+\cdots+\frac{b_n}{a_n}})$。特殊的，当 $a_i=1$ 时，也就是说，将若干个 $R(\frac{1}{b_i})$ 并联在一起，就可以得到 $R\Large(\frac{1}{\Sigma_{i=1}^{n}b_i})$。

利用这条性质，就可以解决所有 $a=1$ 的问题。因为加法结合律，所以 $R(\frac{1}{x})$ 只能由 $x$ 个 $R(1)$ 组成。

突然发现还没有考虑 $b_i=1$ 的情况，即 $R(x),x\in N^+$ 的情况。现在已经可以用 $x$ 个 $R(1)$ 拼凑出 $R(\frac{1}{x})$ 了。$R(\frac{1}{a})\oplus R(b)=R(\frac{b}{ab+1})$，$R(1)\oplus R(b)=R(\frac{b}{b+1})$。这样我们还能解决 $b \bmod a=1$ 的情况，并且需要 $R(\frac{1}{\frac{b-1}{a}})$ 和 $R(a)$，共计 $a+\frac{b-1}{a}$ 个 $R(1)$。

怎么说呢，现在已经会这些东西了：

$R(\frac{a}{b})$ 需要的 $R(1)$ 的个数 $f(R(\frac{a}{b})) =\begin{cases}f(\frac{a\bmod b}{b})+[\frac{a}{b}]&a\geqslant b\\0&a=0\\b&a=1\\a+\frac{b-1}{a}&b\bmod a=1\\?&otherwise\end{cases}$.

首先，我们要明白我们没有考虑到哪些。要不再去发现一些规律吧。$R(1)\oplus R(\frac{a}{b})=R(\frac{a}{a+b})$，说明对于任意的 $R(\frac{a}{b})$，都能将它转化为 $R(\frac{a}{b-a})$。

$$
f(R(\frac{a}{b})) =
\begin{cases}
f(R(\frac{a\bmod b}{b}))+[\frac{a}{b}]&a\geqslant b\\0&a=0\\b&a=1\\a+\frac{b-1}{a}&b\bmod a=1\\f(R(\frac{a}{b-a}))+1&a < b\\?&otherwise
\end{cases}
$$

感觉这道题貌似做完了？总觉得没有啊。。。尝试着把 $f(\frac{a}{b})$ 简化一下。

$$
f(R(\frac{a}{b})) =\begin{cases}f(R(\frac{a\bmod b}{b}))+[\frac{a}{b}]&a\geqslant b&1st\\0&a=0&2nd\\b&a=1&3rd\\a+\frac{b-1}{a}&b\bmod a=1&4th\\f(R(\frac{a}{b\bmod a}))+[\frac{b}{a}]&otherwise&5th\\\end{cases}
$$

试一下样例，$f(R(\frac{2}{3}))=2+\frac{2}{2}[4th]=3$，成立。$f(R(\frac{5}{2}))=f(R(\frac{1}{2}))+[\frac{5}{2}][1st]=2+2=4$，成立。我的妈呀……不过一开始的时候要先约分，因为题目给的数据不一定是最简分数。
  
</p><div style="text-align: center;" class="mdui-typo"><p style='font-family: "font-copyright";'>本文作者为 <a href="//hydro.ac/user/8169">Ben'sGift</a>，版权归其所有。</p><p style='font-family: "font-copyright-link";'>转载于：<a href="//hydro.ac/d/HLpSet/p/P0001/solution/63358d228bbd87384c5a6d9a">//hydro.ac/d/HLpSet/p/P0001/solution/63358d228bbd87384c5a6d9a</a></p></div><p>
