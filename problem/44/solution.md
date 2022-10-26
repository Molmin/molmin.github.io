易知**极长的亮灯区间的**数量等于**亮着的灯**的数量减去**两盏亮着的灯相邻**数量。而亮着的灯的数量容易维护，只需考虑两盏亮着的灯相邻的数量。

**【定义】** 称颜色 $c$ 的路灯的数量大于 $m$ 则为大颜色，小于等于 $m$ 则为小颜色。其中 $m$ 的推荐值为 $\sqrt{n}$。

根据定义，易知大颜色的数量不超过 $\dfrac nm$。

对操作颜色的种类分类处理。（以下时间复杂度等计算时，$m$ 按照推荐值计算；为了不超出时间限制，每次操作的时间复杂度应在 $\Theta(\sqrt{n})$ 数量级及以内）

若操作的颜色是小颜色，由于数量不超过 $m=\sqrt{n}$，所以就可以枚举该种颜色所有的出现位置，判断相邻的灯的亮灭情况并更新答案。

```cpp
/* p[i]: 颜色 i 的亮灭情况
 * id[i]: 颜色 i 的灯的编号列表
 * l[i]: 第 i 盏灯的颜色
 */
if(p[x])for(int i:(id[x])){
	if(l[i+1]==x)answer--;
	else answer-=p[l[i+1]]<<1;
	if(l[i-1]==x)answer--;
	else answer-=p[l[i-1]]<<1;
}
else for(int i:(id[x])){
	if(l[i+1]==x)answer++;
	else answer+=p[l[i+1]]<<1;
	if(l[i-1]==x)answer++;
	else answer+=p[l[i-1]]<<1;
}
```

若操作的颜色时大颜色，那么其相邻的灯的颜色可能是小颜色，也可能是大颜色。我们将这两部分分开考虑。

**一、相邻大颜色对答案的贡献。**只需预处理每两种大颜色相邻次数（时间复杂度 $\Theta\left[\left(\sqrt{n}\right)^2\right]=\Theta(n)$）。操作时枚举相邻大颜色根据亮灭情况作出相应处理即可。时间复杂度 $\Theta(\sqrt{n})$。

```cpp
/* inbigid[i]: 预处理好的大颜色对应的新编号（详见完整代码）
 * l[i]: 第 i 盏灯的颜色
 * adjoin[i][j]: 要求的两个大颜色相邻次数
 */
for(int i=1;i<n;i++)
    if(inbigid[l[i]]&&inbigid[l[i+1]])
        adjoin[inbigid[l[i]]][inbigid[l[i+1]]]++,
        adjoin[inbigid[l[i+1]]][inbigid[l[i]]]++;
```

```cpp
/* p[i]: 颜色 i 的亮灭情况
 * bigcnt: 大颜色数量
 * inmainid[i]: 预处理好的新编号对应的大颜色编号（详见完整代码）
 * inbigid[i]: 预处理好的大颜色对应的新编号（详见完整代码）
 * l[i]: 第 i 盏灯的颜色
 * adjoin[i][j]: 要求的两个大颜色相邻次数
 */
if(p[x]){
    for(int i=1;i<=bigcnt;i++)
        if(p[inmainid[i]]&&inmainid[i]!=x)
            answer-=adjoin[inbigid[x]][i]<<1;
    answer-=adjoin[inbigid[x]][inbigid[x]];
}
else{
    for(int i=1;i<=bigcnt;i++)
        if(p[inmainid[i]]&&inmainid[i]!=x)
            answer+=adjoin[inbigid[x]][i]<<1;
    answer+=adjoin[inbigid[x]][inbigid[x]];
}
```

**二、大颜色与小颜色对答案的贡献。**考虑维护一个大颜色变化时对答案的贡献。在改变一个小颜色时，枚举相邻的大颜色更新维护量。

```cpp
/* p[i]: 颜色 i 的亮灭情况
 * id[i]: 颜色 i 的灯的编号列表
 * inbigid[i]: 预处理好的大颜色对应的新编号（详见完整代码）
 * l[i]: 第 i 盏灯的颜色
 * changeinfluence[i]: 修改大颜色对答案的影响
 */
if(p[x]){
    for(int i:(id[x])){
        if(i<n&&inbigid[l[i+1]])
            changeinfluence[inbigid[l[i+1]]]++;
        if(i>1&&inbigid[l[i-1]])
            changeinfluence[inbigid[l[i-1]]]++;
    }
}
else{
    for(int i:(id[x])){
        if(i<n&&inbigid[l[i+1]])
            changeinfluence[inbigid[l[i+1]]]--;
        if(i>1&&inbigid[l[i-1]])
            changeinfluence[inbigid[l[i-1]]]--;
    }
}
```
