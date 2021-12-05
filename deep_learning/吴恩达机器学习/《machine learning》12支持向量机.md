# 支持向量机SVM

## 12.1 优化目标

逻辑回归回顾：<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gkdcty1pdkj31100ig459.jpg" alt="截屏2020-11-04 下午7.15.27" style="zoom:50%;" />

当$y=1$时，想要误差接近0，$\Theta^Tx$需要远远大于0。

支持向量机的损失函数类似于逻辑回归的损失函数，只是右边变成平的。

当$y=0$时，想要误差接近0，$\Theta^Tx$需要远远小于0

支持向量机的损失函数类似于逻辑回归的损失函数，只是左边变成平的。

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gkdd21b21aj30y60k2n9s.jpg" alt="截屏2020-11-04 下午7.23.16" style="zoom:50%;" />

对逻辑回归的损失函数进行修改就成了支持向量机的损失函数

1. 去掉常数项不影响损失函数最小化时$\theta$的取值
2. 不使用$\lambda$控制正则化项的大小。由控制正则化项变为控制第一项

Cost function:

$minC\sum^m_{i=1}[y^{(i)}cost_1(\theta^Tx^{(i)})+(1-y^{(i)})cost_0(\theta^Tx^{(i)})]+{1\over 2}\sum^n_{i=2}\theta_j^2$

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gkddcrvzf4j31180jah1a.jpg" alt="截屏2020-11-04 下午7.33.31" style="zoom:50%;" />

支持向量机不会输出概率，是进行直接的预测$y=0或y=1$

如果 $\Theta^Tx>= 0$那么$h_\theta(x)=1$

反之为0

## 12.2 SVM大间距分类器Large Margin Intuition

在逻辑回归中判断界限是$\Theta^Tx=0$而支持向量机的判断界限为$\Theta^Tx>1$和$\Theta^Tx<-1$

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gkddkj31r4j30zi0h6qbr.jpg" alt="截屏2020-11-04 下午7.41.05" style="zoom: 50%;" />

当控制常数C的取值很大时：需要想办法让第一项几乎为0

支持向量机会保证决策边界距离最近的样本的间距morgin最大

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gkddqz0lxxj30vm0iednt.jpg" alt="截屏2020-11-04 下午7.47.14" style="zoom:50%;" />

同时如下图，如果C很大，支持向量机会对特殊样本很敏感，他会尽可能去分开每个不同的样本

如果C不是很大，会得到紫色的分割线，会忽略异常点。

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gkddure1rdj310u0gkagt.jpg" alt="截屏2020-11-04 下午7.50.53" style="zoom:50%;" />

## 12.3 SVM大间隔分类器的数学原理The mathematics behind large margin classification(optional)

假设$\theta_0=0	$——决策边界通过原点

向量的范数

$u^Tv=p.||u||$

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gkdff5fja9j31000jek3c.jpg" alt="截屏2020-11-04 下午8.45.04" style="zoom:50%;" />

判定边界可以使用投影✖️范数表示：

![截屏2020-11-04 下午8.50.53](https://tva1.sinaimg.cn/large/0081Kckwly1gkdfl5jogpj310g0kidub.jpg)

$min{1\over2}\sum^n_{j=1}\theta_j^2={1\over2}||\theta||^2$

优化目标：使$\theta$的范数最小

对于正样本，加入样本投影距离p很小，要使判定边界$z=p^{(i)}.||\theta||>1$，这时候范数$||\theta||$值需要很大，与目标相反。

所以支持向量机会尽可能将投影距离p增大，以达到减小范数$||\theta||$的目的。

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gkdfyr0t6dj31140jk4dv.jpg" alt="截屏2020-11-04 下午9.03.58" style="zoom:50%;" />

## 12.4 核函数1 Kernels 1

如果有一个复杂的判定边界的话，按照之前的假设函数定义需要有高次多项式的特征项，这里重新对假设函数进行描述

$h_\theta(x)=\theta_0+\theta_1f_1+\theta_2f_2+\theta_3xf_3+...$

其中$f_1=x_1,f_2=x_2,f_3=x_1x_2,f_4=x_1^2,f_5=x_2^2...$

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gkfa9b19r4j30xo0ikwqp.jpg" alt="截屏2020-11-06 上午11.17.34" style="zoom:50%;" />

首先在特征变量空间随便选取几个点$l^{(1)},l^{(2)},l^{(3)}$

然后用相似函数将$f_1,f_2,f_3$表示出来，注意这里的$x,l^{(i)}$都是向量，计算出来的$f_i$是具体的值

$f_1=Similarity(x,l^{(1)})=exp(-{||x-l^{(1)}||\over 2\sigma^2})$

这里采用的相似函数Similarity称为核函数kernel，选用了exp()高斯和函数Gassion kernels。

但是核函数通常不用similarity()表示，通常使用$k(x,l^{(i)})$

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gkfa9ogmsvj30we0iigvy.jpg" alt="截屏2020-11-06 上午11.17.58" style="zoom:50%;" />

核函数和相似函数的理解：

特征向量$x$和在$x$向量空间中随机取的$l^{i}$向量的距离决定$f_i$的取值为1-0

距离很近为1，很远为0

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gkfaux864ej30x20fwdn1.jpg" alt="截屏2020-11-06 上午11.38.23" style="zoom:50%;" />

举例：假设特征向量$x={\begin {bmatrix}3\\5 \end {bmatrix}}$，再在二维向量空间选取几个二维向量$l^{(i)}$











