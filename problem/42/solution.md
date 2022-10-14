</p><div style="text-align: center;" class="mdui-typo"><p style='font-family: "font-copyright";'>本文作者为 <a href="//hydro.ac/user/8197">yaoyanfeng</a>，版权归其所有。</p><p style='font-family: "font-copyright-link";'>转载于：<a href="//hydro.ac/d/HLpSet/p/P0003/solution/63363e2a8bbd87384c5ae767">//hydro.ac/d/HLpSet/p/P0003/solution/63363e2a8bbd87384c5ae767</a></p></div><p>

这里介绍一种思路：枚举y转成b进制时的那个数（记为 $x$）。
  
首先考虑到 $x$ 不用枚举太多，因为当 $x$ 太大时，$b$ 会很小，那时只需要枚举 $b$ 就行了。

经过本人的多次测试：$x$ 只要枚举到 $1000$ ，剩下到靠枚举 $b$ 即可。
  
接下来我们考虑枚举 $x$ 怎么做：

① $x$ 是一个两位数，设它是 $a_1\times 10+b_1$，则我们可以解一个一元一次方程：$a_1\cdot b+a_2=x$，可以轻松解出 $b$。

② $x$ 是一个三位数，设它是 $a_1\times 10^2+a_2\times 10+a_3$，则我们可以解一个一元二次方程：$a_1b^2+a_2b+a_3=x$，即 $a_1b^2+a_2b+(a_3-x)=0$，利用求根公式 $b=\dfrac{-b\pm\sqrt{b^2-4\cdot a\cdot c}}{2\cdot a}$，可以快速求出根，但是注意要使用 `__int128` 或 `long double`。

这样枚举 $x$ 就完成了。

接下来考虑枚举 $b$ 怎么做。将 $b$ 从 `1e6` 开始往下枚举，每次都将 $y$ 转换成 $b$ 进制，然后判断是否有一位大于 $9$，最后再和 $l$ 比较一下即可。

</p><div style="text-align: center;" class="mdui-typo"><p style='font-family: "font-copyright";'>本文作者为 <a href="//hydro.ac/user/8197">yaoyanfeng</a>，版权归其所有。</p><p style='font-family: "font-copyright-link";'>转载于：<a href="//hydro.ac/d/HLpSet/p/P0003/solution/63363e2a8bbd87384c5ae767">//hydro.ac/d/HLpSet/p/P0003/solution/63363e2a8bbd87384c5ae767</a></p></div><p>
