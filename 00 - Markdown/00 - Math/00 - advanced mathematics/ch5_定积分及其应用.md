# 1. 定积分的概念
## 1.1 定积分的定义
> @Definition
> **定义1.1**   设函数$f(x)$在$[a,b]$上有界，在$[a,b]$上任意插入$n-1$个分点，$a=x_0<x_1<x_2<\dots <x_n<b$,把$[a,b]$分成$n$个小区间$[x_{i-1},x_{i}]$,记$\Delta x_i=x_i-x_{i-1}$,$i=1,2,\dots,n$,做和式$S=\sum_{i=1}^{n}f(\xi_i)\Delta x_i$,设$\lambda=\max{\Delta x_1, \Delta x_2, \dots, \Delta n}$,若极限
> $$
> \lim_{\lambda\to 0}S=\lim_{\lambda \to 0}\sum_{i=1}^{n}f(\xi_i){\Delta x_i}
> $$
> 存在，且与小区间的分法以及$\xi_i$的选取无关，则称函数$f(x)$在$[a,b]$上可积，并称此极限值为函数$f(x)$在$[a,b]$上的定积分，记作
> $$
> \int_a^bf(x)dx=\lim_{\lambda \to 0}\sum_{i=1}^{n}f(\xi_i){\Delta x_i}
> $$
> 其中，$a$与$b$分别称为积分的下限与上限，$[a,b]$称为积分区间，函数$f(x)$称为被积函数，$f(x)dx$称为被积表达式，$x$称为积分变量，$S$称为函数$f(x)$在$[a,b]$上的积分和，若$\lim_{\lambda \to 0}\sum_{i=1}^{n}f(\xi_i){\Delta x_i}
$不存在，则称函数在$[a,b]$上不可积。

> @Theorem
> **定理1.1**   若$f(x)$是区间$[a,b]$上的连续函数，则函数$f(x)$在$[a,b]$上可积。

> @Theorem
> **定理1.2** 若$f(x)$是区间$[a,b]$上只有有限个间断点的有界函数，则函数$f(x)$在区间$[a,b]$上可积。


> @Theorem
> **定理1.3** 若$f(x)$是区间$[a,b]$上的单调函数，则函数$f(x)$在区间$[a,b]$上可积。


## 1.2 定积分的几何意义
1. 在区间$[a,b]$上，当$f(x)\ge 0$时，定积分$\int_a^bf(x)dx$的几何意义就是由连续曲线$y=f(x)\ge 0$及直线$x=a$，$x=b$,$y=0$所围成的曲边梯形的面积;
2. 在区间$[a,b]$上，当$f(x)\le 0$时，定积分$\int_a^bf(x)dx$的几何意义就是由连续曲线$y=f(x)\le 0$及直线$x=a$，$x=b$,$y=0$所围成的曲边梯形的面积的负值;
3. 在区间$[a,b]$上，当$f(x) $既可以取正值，又可以取负值时，定积分$\int_a^bf(x)dx$的几何意义就是$x$轴上方的面积减去$x$轴下方的面积所得之差。


# 2 定积分的性质
> @Property
> **性质2.1(线性性质)** 若函数$f_1(x)$,$f_2(x)$在$[a,b]$上可积，则对$\forall k_1,k_2\in R$,函数$k_1f_1(x)+k_2f_2(x)$在$[a,b]$上可积，且
> $$
>\int_a^b[ k_1f_1(x)+k_2f_2(x) ] = k_1\int_a^bf_1(x)dx+k_2\int_a^bf_2(x)dx
> $$


> @Property
> **性质2.2(区间的可加性)** 设$I$为一个有限的闭区间，$a,b,c\in I$,若函数在区间$I$上可积，则$f(x)$在$[a,b]$,$[b,c]$,$[c,b]$上均可积，且
> $$
> \int_a^bf(x)dx = \int_a^cf(x)dx + \int_c^bf(x)dx
> $$

> @Property
> **性质2.3** 若函数$f_1(x)$,$f_2(x)$在$[a,b]$上可积，则乘积函数$f_1(x)f_2(x)$在$[a,b]$上可积


> @Property
> **性质2.4(积分不等式)**   若函数$f(x)$在$[a,b]$上可积，且$f(x)\ge 0(\le 0)$,$x\in [a,b]$,则$\int_a^bf(x)\ge0(\le 0)$。



> @Property
> **性质2.5**   若函数$f(x)$在$[a,b]$上可积,则函数$|f(x)|$在$[a,b]$上可积,且
> $$
> |\int_a^bf(x)dx| \le \int_a^b|f(x)|dx
> $$


> @Property
> **性质2.6(第一积分中值定理)** 若函数$f(x)$在区间$[a,b]$上连续，函数$g(x)$在区间$[a,b]$上可积且不变号，则在$[a,b]$上至少存在一点$\xi$,使得
> $$
> \int_a^bf(x)g(x)dx=f(\xi)\int_a^bg(x)dx
> $$


# 3. 定积分的计算
## 3.1 变限积分与原函数的存在性
假设函数$f(x)$在区间$[a,b]$上连续，则$\forall x\in [a,b]$,函数在子区间$[a,x]$上也可积，于是有唯一的积分值$\int_a^xf(t)dt$与$x$对应，这个积分确定了一个定义在$[a,b]$上的函数，记作
$$
F(x)=\int_a^xf(t)dt
$$
并称之为函数$f(x)$的变上限积分

> @Theorem
> **定理3.1(原函数存在定理)**   如果函数$f(x)$在区间$[a,b]$上连续，则变上限积分函数
> $$
> \int_a^bf(x)g(x)dx=f(\xi)\int_a^bg(x)dx
> $$
> 在区间$[a,b]$上可导，且$F'(x)=f(x)$


> @Theorem
> **定理3.2(牛顿-莱布尼茨公式)**    如果函数$F(x)$ 是连续函数$f(x)$在$[a,b]$上的一个原函数，则
> $$
> \int_a^bf(x)dx=F(b)-F(a)
> $$

## 3.2 定积分的换元积分法
> @Theorem
> **定理3.3**   若函数$f(x)$在区间$[a,b]$上连续,函数$x=\varphi(t)$满足下列条件
> - $\varphi(t)$在$[\alpha, \beta]$上具有连续导数
> - $\varphi(\alpha)=a$,$\varphi(\beta)=b$,且当$t$在$[\alpha, \beta](或[\beta, \alpha])$上变化时，$x=\varphi(t)$的值在区间$[a,b]$上变化，则
> $$
> \int_a^bf(x)dx = \int_\alpha^\beta f[\varphi(t)]\varphi'(t)dt
> $$
> 称为定积分的换元积分公式


以下是定积分的换元公式的应用
1. 设函数$f(x)$在区间$[-a,a]$上连续，则
    - 当$f(x)$为偶函数时，$\int_{-a}^{a}f(x) dx = 2\int_{0}^{a}f(x)dx$
    - 当$f(x)$为奇函数时，$\int_{-a}^{a}f(x) dx= 0$

2. 设函数$f(x)$是以$T$为周期的连续函数，$a,b$为任意实数，则
   - $\int_{a+T}^{b+T}f(x) dx = \int_{a}^{b}f(x) dx$ 
   - $\int_{a}^{a+T}f(x) dx = \int_{0}^{T}f(x) dx$


## 3.3 定积分的分部积分法
设函数$u=u(x)$,$v=v(x)$在区间$[a,b]$上具有连续的导数，则
$$
\int_a^buv'dx=[uv]_a^b-\int_a^bu'vdx
$$
或
$$
\int_a^budv=[uv]_a^b-\int_a^bvdu
$$
就是定积分的分部积分公式

# 4. 反常积分
## 4.1 无穷区间上的反常积分
    
> @Definition
> **定义4.1**   
> 1. 设函数$f(x)$的定义区间是$[a,+\infty)$,且对任意的$A>a$,函数$f(x)$在区间$[a,A]$上可积。如果极限$\lim_{A\to +\infty}\int_a^Af(x)dx$存在，则称函数$f(x)$在无穷区间$[a,+\infty)$上的反常积分$\int_a^{+\infty}f(x)dx$收敛，并把此极限称为该反常积分的值，即
> $$
> \int_a^{+\infty}f(x)dx = \lim_{A\to +\infty}\int_a^Af(x)dx 
> $$
> 如果上述极限不存在，则称反常积分$\int_a^{+\infty}f(x)dx$发散。
> 2. 设函数$f(x)$的定义区间是$(-\infty, b]$,且对任意的$B>b$,函数$f(x)$在区间$[B,b]$上可积。如果极限$\lim_{B\to -\infty}\int_B^bf(x)dx$存在，则称函数$f(x)$在无穷区间$(-\infty, b]$上的反常积分$\int_{-\infty}^bf(x)dx$收敛，并把此极限称为该反常积分的值，即
> $$
> \int_{-\infty}^bf(x)dx = \lim_{B\to -\infty}\int_B^bf(x)dx 
> $$
> 如果上述极限不存在，则称反常积分$\int_{-\infty}^bf(x)dx$发散。
> 3. 设函数$f(x)$的定义区间是$(-\infty, +\infty)$,$c$为任意实数。如果反常积分$\int_{-\infty}^cf(x)dx$和$\int_{c}^{+\infty}f(x)dx$同时收敛，则称函数$f(x)$在无穷区间$(-\infty, +\infty)$上的反常积分$\int_{-\infty}^{+\infty}f(x)dx$收敛，且定义其值为:
> $$
> \int_{-\infty}^{+\infty}f(x)dxlk=\int_c^{+\infty}f(x)dx +  \int_{-\infty}^cf(x)dx = \lim_{B\to -\infty}\int_B^cf(x)dx + \lim_{A\to +\infty}\int_c^Af(x)dx 
> $$

## 4.2 无界函数的反常积分
一般的，如果函数$f(x)$在点$x_0$的任一邻域内都无界，则称点$x_0$为函数$f(x)$的瑕点，无界函数的反常积分也称为瑕积分。
> @Definition
> **定义4.2**   
> 1. 设函数$f(x)$的定义区间是$(a,b]$,点$x=a$为函数的瑕点，且对任意的$\varepsilon>0$,函数$f(x)$在区间$[a+\varepsilon, b]$上可积。如果极限$\lim_{\varepsilon\to 0^+}\int_{a+\varepsilon}^bf(x)dx$存在，则称函数$f(x)$在区间$[a,b]$上的反常积分$\int_a^{b}f(x)dx$收敛，并把此极限称为该反常积分的值，即
> $$
> \int_a^{b}f(x)dx = \lim_{\varepsilon\to 0^+}\int_{a+\varepsilon}^bf(x)dx 
> $$
> 如果上述极限不存在，则称反常积分$\int_a^{b}f(x)dx$发散。
> 2. 设函数$f(x)$的定义区间是$[a, b)$,点$x=b$为函数的瑕点，且对任意的$\varepsilon>0$,函数$f(x)$在区间$[a,b-\varepsilon]$上可积。如果极限$\lim_{\varepsilon\to 0^+}\int_a^{b-\varepsilon}f(x)dx$存在，则称函数$f(x)$在区间$[a, b)$上的反常积分$\int_{a}^bf(x)dx$收敛，并把此极限称为该反常积分的值，即
> $$
> \int_{a}^bf(x)dx = \lim_{\varepsilon\to 0^+}\int_a^{b-\varepsilon}f(x)dx 
> $$
> 如果上述极限不存在，则称反常积分$\int_{-\infty}^bf(x)dx$发散。
> 3. 设函数$f(x)$的定义区间是$[a,c)\cup(c,b]$,点$x=c$为函数的瑕点。如果反常积分$\int_{a}^cf(x)dx$和$\int_{c}^{b}f(x)dx$同时收敛，则称函数$f(x)$在区间$[a,b]$上的反常积分$\int_{a}^{b}f(x)dx$收敛，且定义其值为:
> $$
> \int_{a}^{b}f(x)dxlk=\int_a^{c}f(x)dx +  \int_{c}^bf(x)dx = \lim_{\varepsilon\to 0^+}\int_a^{c-\varepsilon}f(x)dx + \lim_{\eta\to 0^+}\int_{c-\eta}^bf(x)dx 
> $$
