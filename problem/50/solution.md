设取第 $i_1,\ i_2,\ \cdots,\ i_k$ 组，则质量分数为

$$
S=\frac{a_{i_1}+a_{i_2}+\cdots+a_{i_k}}{b_{i_1}+b_{i_2}+\cdots+b_{i_k}}.
$$

则

$$
b_{i_1}S+b_{i_2}S+\cdots+b_{i_k}S=a_{i_1}+a_{i_2}+\cdots+a_{i_k}.
$$

移项得

$$
a_{i_1}-b_{i_1}S+a_{i_2}-b_{i_2}S+\cdots+a_{i_k}-b_{i_k}S=0.
$$

考虑二分答案，每次对 $a_i-b_i\cdot ans$ 排序取前 $k$ 大求和检验是否为正数即可。
