### 10.1 正确选择

如果预测出现很大偏差，需要尝试去：

1. 收集更多的训练样本
2. 尝试使用更少的特征
3. 尝试使用更多的特征
4. 增加特征的多项式，例如增加$x^2_1,x^2_2,x_1x_2,etc.$
5. 尝试增大或减小正则化参数$\lambda$值

==诊断法：==

是一种测试方法，通过测试可以了解算法问题所在，如何改进

### 10.2 评估假设函数

将样本分为训练集$m$和测试集$m_{test}$   7:3（样本需随机分布） 

线性回归算法举例：

1. 从训练集中学习出模型参数$\theta$（最小化损失函数$J(\theta)$）
2. 将得到的$\theta$带入测试集计算出测试误差$J_{test}(\theta)={1\over 2m_{test}}\sum_{i=1}^{m_{test}}(h_\theta(x_{test}^{(i)})-y_{test}^{(i)})^2$

逻辑回归算法举例：

1. 从训练集中学习出模型参数$\theta$（最小化损失函数$J(\theta)$）

2. 将得到的$\theta$带入测试集计算出测试误差$J_{test}(\theta)={1\over 2m_{test}}\sum_{i=1}^{m_{test}}[y_{test}^{(i)}logh_\theta(x_{test}^{(i)})+(1-y_{test}^{(i)})logh_\theta(x_{test}^{(i)})]$

3. 或者使用错误分类误差（0/1错误分类误差）

   <img src="https://tva1.sinaimg.cn/large/0081Kckwly1gk5hsp0ysuj30za0gkwh9.jpg" alt="截屏2020-10-26 下午12.22.44" style="zoom:50%;" />

### 10.3 训练集、验证集、测试集

训练集误差不能体现模型对样本拟合情况的好坏

到底选择几次多项式的假设函数呢？设$d$为最高次数

1. 使用算法求不不同的多项式，得出不同的$\Theta$参数矩阵
2. 引入最高次$d$这一参数使用验证集对不同的参数矩阵的假设函数进行评估
3. 再使用测试集验证泛化能力。

训练集$m$、交叉验证集$m_{cv}$、测试集$m_{test}$：6:2:2

训练误差training error：

$$J_{train}(\theta)={1\over 2m}\sum_{i-1}^m(h_\theta)(x^{(i)}-y^{(i)})^2$$

交叉验证误差cross validation error:

$$J_{cv}(\theta)={1\over 2m}\sum^{m_{cv}}_{i=1}(h_\theta(x_{cv}^{(i)})-y_{cv}^{(i)})^2$$

测试误差test error:

$$J_{test}(\theta)={1\over 2m_{test}}\sum_{i=1}^{m_{test}}(h_\theta(x_{test}^{(i)})-y_{test}^{(i)})^2$$

### 10.4 诊断偏差（欠拟合）方差（过拟合）

高偏差问题——欠拟合——训练误差和交叉验证误差（比训练误差大点）都很大

高方差问题——过拟合——训练误差极小，交叉验证误差很大

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gk5hsoids2j30vk0fk0vm.jpg" alt="截屏2020-10-27 下午10.47.56" style="zoom:50%;" />

### 10.5 正则化参数对偏差和方差的影响

* 选择不同的正则化参数$\lambda$
* 首先$\lambda$从0开始到0.01再以两倍递增，算出不同$\lambda$值下的误差函数$J(\theta)$
* 再通过最小误差函数值$minJ(\theta)$得出某个参数向量$\Theta^{(i)}$
* 再使用交叉验证评估不同$\lambda$值在交叉验证集下的误差平方和
* 选择这些$\lambda$值不同的模型中交叉验证集误差最小的
* 最后验证所选出来$\lambda$值对应的参数向量$\Theta^{(i)}$在测试集中的表现

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gk5hsqfjotj30vi0gwacl.jpg" alt="截屏2020-10-27 下午11.22.22" style="zoom:50%;" />

当正则化参数$\lambda$过大时，训练误差会很大，当$\lambda$值很小时，训练误差很小

当正则化参数$\lambda$过大时，交叉验证误差会很大（欠拟合高偏差），当$\lambda$值很小时，交叉验证误差也会很大（过拟合高方差）

注意：这里误差函数有正则化项，训练误差函数和交叉验证函数没设正则化项。

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gk5hsnvw04j30y80goq56.jpg" alt="截屏2020-10-27 下午11.30.16" style="zoom:50%;" />

### 10.6 学习曲线（诊断）

在假设函数次数一定时，随着训练样本集数量的增多，训练平均误差会逐渐增大。交叉验证平均误差会随着训练样本数量增多而逐渐减小。

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gk5hsc8149j30vw0ggdno.jpg" alt="截屏2020-10-27 下午11.55.54" style="zoom:50%;" />

当模型过于简单时平均误差曲线：（高偏差问题）

模型过于简单处于高偏差问题时，增加训练样本也没用

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gk6fw8kog7j30t20h63zr.jpg" alt="截屏2020-10-28 下午10.12.29" style="zoom:50%;" />

当模型过于复杂时的平均误差曲线：（高方差问题）

训练误差和交叉验证误差有很大一段距离

当模型过于复杂处于高方差问题时，增加训练数据集会使训练误差和验证误差接近，对改进算法有帮助。

<img src="https://tva1.sinaimg.cn/large/0081Kckwly1gk6fw350l5j30ts0gemyl.jpg" alt="截屏2020-10-29 下午6.42.39" style="zoom:50%;" />

### 10.7 判断改进方法

1. 收集更多的训练样本数量——解决高方差问题
2. 尝试使用更少的特征数量——解决高方差问题
3. 尝试使用更多的特征数量——解决高偏差问题
4. 增加特征的多项式，例如增加$x^2_1,x^2_2,x_1x_2,etc.$——解决高偏差问题
5. 尝试增大正则化参数$\lambda$值——解决高方差问题
6. 尝试减小正则化参数$\lambda$值——解决高偏差问题

使用大型神经网络更精准，如果出现了过拟合可以通过增大$\lambda$值改善