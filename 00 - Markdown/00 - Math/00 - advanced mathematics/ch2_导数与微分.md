# 1 导数的概念

## 1.1 导数的定义

> @Definition
>
> **定义1.1**	设函数$f(x)$在点$x=x_0$的某邻域$U^0(x_0,\delta)$内有定义，如果极限
> $$
> \lim_{\Delta x\to 0}\frac{\Delta y}{\Delta x}=\lim_{\Delta x}\frac{f(x_0+\Delta x)-f(x)}{\Delta x}
> $$
> 存在，则称函数$f(x)$在点$x=x_0$处的导数存在(或可导)，且称此极限为函数$y=f(x)$在点$x=x_0$处的==导数==，记为$f'(x)$或$\frac{dx}{dy}|_{x=x_0}$,即
> $$
> f'(x)=\lim_{\Delta x\to 0}\frac{\Delta y}{\Delta x}=\lim_{\Delta x\to 0}\frac{f(x_0+\Delta x)-f(x_0)}{\Delta x}
> $$
> 如果令$x=x_0+\Delta x$,则$\Delta x=x-x_0$,且当$\Delta x\to 0$时$x\to x_0$，于是导数$f'(x_0)$又可以定义写成如下形式：
> $$
> f'(x_0)=\lim_{x\to x_0}\frac{f(x)-f(x_0)}{x-x_0}
> $$

> @Theorem
>
> **定理1.1**	若函数$f(x)$在点$x=x_0$处可导，则$f(x)$在点$x=x_0$处连续

> @Theorem
>
> **定义1.2**	如果函数$f(x)$在开区间$(a,b)$内的每一点都可导，则称函数$f(x)$在$(a,b)$内可导。

# 1.2 导数的几何意义

### 1.2.1 切线的定义

设有曲线$C$及$C$上的一点$M$,在点$M$外取$C$上的一点$N$,并作割线$MN$,当点$N$沿曲线$C$趋于点$M$时，若割线$MN$绕点$M$旋转而趋于极限位置$MT$,则称直线$MT$为曲线$C$在点$M$处的==切线。==

### 1.2.2 切线的斜率

设$M(x_0,y_0)$是函数$y=f(x)$上的一个点，$N(x_0+\Delta x,y_0+\Delta y)$是$y=f(x)$上不同于$M$的另一个点，于是函数$y=f(x)$在$[x_0,x_0+\Delta x]$的增量为$\Delta y=f(x_0+\Delta x)$，割线$MN$的斜率为
$$
\bar k= \tan \varphi = \frac{\Delta y}{\Delta x}=\frac{f(x_0+\Delta x)-f(x_0)}{\Delta x}
$$
当$\Delta x$越小时，割线斜率越接近$M(x_0,y_0)$点切线斜$k$，要得到切线$MT$的斜率，需将上式在$\Delta x\to 0$时取极限即可，即
$$
k= \tan \alpha = \lim_{\Delta x\to 0}\frac{\Delta y}{\Delta x}=\lim_{\Delta x\to 0}\frac{f(x_0+\Delta x)-f(x_0)}{\Delta x}
$$

### 1.2.3 导数的几何意义

函数$y=f(x)$在点$x=x_0$处的导数$f'(x_0)$表示函数$y=f(x)$在点$(x_0, f(x_0))$处的切线斜率，因此曲线$y=f(x)$在点$(x_0, f(x_0))$处的切线方程为：
$$
y-f(x_0)=f'(x_0)(x-x_0)
$$
如果$f'(x)\neq 0$,则曲线$y=f(x)$在点$(x_0, f(x_0))$处的法线方程为
$$
y-f(x_0)=-\frac{1}{f'(x_0)}(x-x_0)
$$

## 1.3 单侧导数

> @Definition 
>
> **定义1.3**	如果单侧极限$\lim_{\Delta x\to 0^-}\frac{\Delta y}{\Delta x}$存在，则称此极限为函数$y=f(x)$在点$x=x_0$处的左导数，记作$f'_{-}(x_0)$;如果单侧极限$\lim_{\Delta x\to 0^+}\frac{\Delta y}{\Delta x}$存在，则称此极限为函数$y=f(x)$在点$x=x_0$处的右导数，记作$f'_{+}(x_0)$。

> @Theorem
>
> **定理1.2**	导数$f'(x_0)$存在的充分必要条件是$f'_-(x_0)=f'_+(x_0)$。

# 2 求导法则

## 2.1 导数的四则运算

> @Theorem
>
> **定理2.1**	设函数$u(x)$与$v(x)$在点$x$处可导，则$u(x)+v(x)$与$u(x)-v(x)$在点$x$处也可导，且
> $$
> [u(x)\pm v(x)]' = u(x)\pm v(x)
> $$

> @Theorem 
>
> **定理2.2**	设函数$u(x)$与$v(x)$在点$x$处可导，则$u(x)v(x)$在点$x$处也可导，且
> $$
> (uv)'=u'v+uv'
> $$

> @Theorem
>
> **定理2.3**	设函数$u(x)$与$v(x)$在$x$处可导，且$v(x)\neq 0$, 则$\frac{u(x)}{v(x)}$在点$x$处也可导，且
> $$
> (\frac{u}{v})'=\frac{u'v-uv'}{v^2}
> $$

## 2.2 反函数的求导法则

> @Theorem
>
> **定理2.4**	设函数$y=f(x)$在$(a,b)$内连续且单调递增(递减)，又在点$x_0\in (a,b)$处具有非零导数$f'(x_0)\neq 0$,则其反函数$x=\varphi(y)$在点$y_0=f(x_0)$处可导，且
> $$
> \varphi'(y_0)=\frac{1}{f'(x_0)} 或 f'(x_0)=\frac{1}{\varphi'(y_0)}
> $$

## 2.3 复合函数求导法则

> @Theorem
>
> **定理2.5**	设函数$u=\varphi(x)$在点$x$处可导，函数$y=f(u)$在$u=\varphi(x)$处可导，则复合函数$y=f[\varphi(x)]$在点$x$处也可导，且导数为
> $$
> \{f[\varphi(x)]\}' = f'[\varphi(x)]\varphi'(x) 或 \frac{dy}{dx}=\frac{dy}{du}\cdot\frac{du}{dx}
> $$

## 2.4 基本初等函数的导数公式

> @Table
>
> 1. $C'=0(C)为任意常数$
> 2. $(x^a)'=ax^{a-1}$
> 3. $(a^x)'=a^x\ln a(a>0, a\neq 1)$
> 4. $(e^x)'=e^x$
> 5. $(log_ax)'=\frac{1}{x\ln a}(a>0,a\neq 1)$
> 6. $(\ln|x|)'=\frac{1}{x}$
> 7. $(\sin x)'=\cos x$
> 8. $(\cos x)'=-\sin x$
> 9. $(\tan x)'=\sec ^2 x$
> 10. $(\cot x)'=-\csc ^2 x$
> 11. $(\sec x)'=\sec x\tan x$
> 12. $(\csc x)'=-\csc x\cot x$
> 13. $(\arcsin x)'=\frac{1}{\sqrt{1-x^2}}$
> 14. $(\arccos x)'=-\frac{1}{\sqrt{1-x^2}}$
> 15. $(\arctan x)'=\frac{1}{1+x^2}$
> 16. $(\arccot x)'=-\frac{1}{1+x^2}$

## 2.5 隐函数求导法则

一般的，如果变量$x$和$y$满足一个方程$F(x,y)=0$，在一定条件下，当$x$取某一区间内任一值时，相应地总有满足这个方程的唯一$y$值存在，那么就说方程$F(x,y)=0$在该区间内确定了一个==隐函数==。

要对隐函数$y=f(x)$求导，只需将方程$F(x,y)=0$中的$y$看成是$x$的函数，并在方程两端同时对$x$求导便可以求出$y'(x)$。

## 2.6 对数法求导

对数求导法先在函数$y=f(x)$的两边同时取对数，然后再把$y$看成是$x$的函数，根据复合函数的求导法则即可求出函数$y=f(x)$ 对$x$的导数。

## 2.7 参数方程求导

参数方程$\begin{cases}x=\varphi(t)\\ y=\psi (t) \end{cases}$ $(\alpha \le t\le \beta)$表示平面上的一条曲线，对于参数$t\in [\alpha, \beta]$的每一个值，当函数$x=\varphi(t)$的反函数$t=\varphi^{-1}(x)$存在且不为零时，有
$$
\frac{dy}{dx}=\frac{dy}{dt}\cdot\frac{dt}{dx}=\frac{dy}{dt}\cdot \frac{1}{\frac{dx}{dt}}=\frac{\psi'(t)}{\varphi'(t)}
$$

# 3 高阶导数

## 3.1 高阶导数的概念

如果$y=f(x)$的$n-1$阶导数$y^{(n-1)}$的导数还存在，则称$y^{(n-1)}$的导数为$y=f(x)$的$n$阶导数，记作$y^{(n)}=\frac{d^by}{dx^n}$。

## 3.2 莱布尼茨高阶导数求导公式

莱布尼茨公式如下：
$$
(uv)^{(n)}=\sum_{k=0}^{n}C_n^ku^{(n-k)}v^{(k)}=u^{(n)}v+nu^{(n-1)}v'+\frac{n(n-1)}{2}u^{(n-2)}v''+\dots+uv^{(n)}
$$

## 3.3 参数方程的高阶导数

设$y=y(x)$是由参数方程$\begin{cases}x=\phi(t) \\y=\psi(t)\end{cases}$所确定的函数，$y^{(n)}$可以看成是$y^{(n-1)}$先对中间变量$t$求导，再乘以中间变量$t$对自变量$x$的导数。

以求二阶导数为例：
$$
y'=\frac{dy}{dx}=\frac{\psi'(t)}{\phi'(t)} \\
y''=\frac{d^2y}{dx^2}=\frac{d}{dx}(\frac{dy}{dx})=\frac{dy'}{dx}=\frac{dy'}{dt}\cdot\frac{dt}{dx}\\
=\frac{\psi''(t)\phi'(x)-\psi'(t)\phi''(t)}{[\phi'(t)]^2}\cdot\frac{1}{\phi'(t)} \\
= \frac{\psi ''(t)\phi'(t)-\psi'(t)\phi''(t)}{[\phi'(t)]^3}
$$

# 4 函数的微分

## 4.1 微分的概念

> @Definition
>
> **定义4.1**	设函数$y=f(x)$在点$x=x_0$的某邻域内有定义，如果函数的改变了$\Delta y=f(x_0+\Delta x)-f(x_0)$可表示为
> $$
> \Delta y=A\Delta x+o(\Delta x)
> $$
> 其中，$A$是不依赖于$\Delta x$的常数，则称函数$y=f(x)$在点$x=x_0$处==可微==，并称$A\Delta x$为函数$y=f(x)$在点$x=x_0$处的微分，记作$dy$,即$dy=A\Delta x$。

## 4.2 可微与可导的关系

> @Theorem
>
> **定理4.1**	函数$y=f(x)$在点$x=x_0$处可微的充要条件是函数$y=f(x)$在点$x=x_0$处可导。

## 4.3 微分的几何意义

在平面直角坐标系中，函数$y=f(x)$的图形是一条曲线，假设曲线$y=f(x)$上有一个确定的点$M(x_0,y_0)$，则当自变量$x$有微小的增量$\Delta x$，就得到线上的另一点$N(X_0+\Delta x,y_0+$$\Delta y)$,如下图所示，可知：
$$
MQ=\Delta x\\QN=\Delta y
$$
过点$M$做曲线的切线$MT$,它与$x$轴的正向夹角为$\alpha$,则
$$
QP=MP\cdot \tan \alpha =\Delta x\cdot f'(x_0)
$$
于是$dy=QP$。则微分$dy=f'(x_0)\Delta x$在几何表示曲线$y=f(x)$在点$(x_0,f(x_0))$处的切线的纵坐标相应于$\Delta x$的近似改变量。

## 4.4 微分的运算

### 4.4.1 四则运算

微分的四则运算如下：
$$
\begin{align}
d[u(x)\pm v(x)]&=du(x)\pm dv(x) \\
d[u(x)v(x)]&=v(x)du(x)+u(x)dv(x) \\
d[\frac{u(x)}{v(x)}] &= \frac{v(x)du(x)-u(x)dv(x)}{v^2(x)}
\end{align}
$$

### 4.4.2 反函数

设函数$y=f(x)$在点$x$处可微，$y=f(x)$的反函数为$x=\phi(y)$,则$x=\phi(y)$在对应的点$y=f(x)$处也可微，$dx=\phi'(x)$,而$\phi'(y)=\frac{1}{f'(x)}$,于是可得反函数的微分公式
$$
dx=\frac{1}{f'(x)}dy
$$

### 4.4.3 基本初等函数与微分公式对照

|                    导数公式                    |              微分公式              |
| :--------------------------------------------: | :--------------------------------: |
|                    $(C)'=0$                    |               $dc=0$               |
|               $(x^a)'=ax^{a-1}$                |         $dx^a=ax^{a-1}dx$          |
|        $(a^x)'=a^x\ln a(a>0, a\neq 1)$         | $d(a^x)=a^x\ln a dx(a>0, a\neq 0)$ |
| $(\log_ax)'=\frac{1}{x \ln a}, (a>0, q\neq 1)$ |                $d(log_ax)=\frac{1}{x\ln a}dx (a>0,a\neq 1)$                  |
|$(\sin x )'=\cos x$                             | $d(\sin x)=\cos x dx$|
|$(\cos x)'=-\sin x$|$d(\cos x)=\sin x dx$|
|$(\tan x)'=\sec^2x$|$d(\tan x)=\sec^2xdx$|
|$(\cot x)'=-\csc^2x$|$d(\cot x)=-\csc ^2 x dx$|
|$(\sec x)'=\sec x\tan x$|$d(\sec x)'=\sec x\tan x dx$|
|$(\csc x)'=-\csc\cot x$|$-\csc x\cot xdx$|
|$(\arcsin x)'=\frac{1}{\sqrt{1-x^2}}$|$d(\arcsin x) = \frac{1}{\sqrt{1-x^2}}dx$|
|$(\arccos x)'=-\frac{1}{\sqrt{1-x^2}}$|$d(\arccos x)=-\frac{1}{\sqrt{1-x^2}}dx$|
|$(\arctan x)'=\frac{1}{1+x^2}$|$d(\arctan x)=\frac{1}{1+x^2}dx$|
|$(arccot \  x)'=-\frac{0}{1+x^2}$|$d(arccot\ x) =-\frac{1}{1+x^2}dx$|

## 4.5 复合函数的微分法则

> @ Theorem
> **定理4.2**   设函数$f(u)$与$u=\varphi(x)$ 都可微，则复合函数$y=f[\varphi(x)]$的可微分为
> $$
> dy=f'(u)dx
> $$