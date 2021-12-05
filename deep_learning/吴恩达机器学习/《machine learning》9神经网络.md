### 9.1 神经网络损失函数

神经网络数据集：${(x^{(1)},y^{(1)}),(x^{(2)},y^{(2)}),...,(x^{(m)},y^{(m)})}$

神经网络层数：$L$

第$l$层的神经元数（$l$层特征数）：$s_l$（不包括偏差特征）

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gtlxt6mznvj60yk0hgwh602.jpg" alt="截屏2020-10-24 下午10.15.45" style="zoom:50%;" />

cost function:

$\sum^m_{i=1}$: 样本从1到m的累加

$\sum_{k=1}^K$: 输出类别从1到K的累加

$\sum^{L-1}_{l=1}$: 神经网络从第1层到第L-1层的累加

$\sum_{i=1}^{s_l}$: 第$l$层神经网络中的神经元从1到$s_l$的累加

$\sum^{s_l+1}_{j=1}$: 第$l$层中第$i$个神经元的特征$\theta_{ij}$从$j=0$到$j=s_l+1$的特征累加

注意不要将$\Theta_{i0}$正则化

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gtlxw3z3avj60wm0hgwgg02.jpg" alt="截屏2020-10-24 下午10.44.45" style="zoom:50%;" />

### 9.2损失函数优化算法—反向传播

前向传播向量化，计算神经网络结构中每个神经元的激活值。

首先由$a^{(1)}=x$即输入层计算第二层的$z^{(2)}$函数

再带入sigma函数（并加入偏移项）计算出$a^{(2)}$层各神经元的激活值

> a类推算出每层神经网络的每个神经元的激活值最终输出得出假设函数



<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gtly10t62vj60tm0f4taf02.jpg" alt="截屏2020-10-25 下午2.45.43" style="zoom:50%;" />

反向传播算法（Backpropagation）

$\delta_j^{(l)}$: 第$l$层神经网络的第$j$个神经元的误差

$a_j^{(l)}$: 第$l$层神经网络的第$j$个神经元的激活值

==反向传播计算流程：==

* 通过最后一层神经网络即输出层的预测值减去样本标签得出第$L$层的误差

​      $$ \delta^{(4)}_j=a_j^{(4)}-labels_j=h_\Theta(x)_j-y_j=g(z^{(4)})-labels_j$$

​      向量化后：$\delta^{(4)}=a^{(4)}-labels$

* $\delta^{(3)}=(\Theta^{(3)})^T\delta^{(4)} .* g^{'}(z^{(3)})$ 其中$g^{'}(z^{(3)})$ 由$a^{(3)} .* (1-a^{(3)})$推出$g^{'}(z^{(3)})=g(z^{(3)})(1-g(z^{(3)}))$
* $\delta^{(2)}=(\Theta^{(2)})^T\delta^{(3)} .* g^{'}(z^{(2)})$ 其中$g^{'}(z^{(2)})$ 由$a^{(2)} .* (1-a^{(2)})$推出

* 没有$\delta^{(1)}$这一项，因为第一层神经网络为输入项，不存在误差。

  ==一定要注意.*是矩阵的点乘，两个形状一样的矩阵对应元素相乘==

  最终将推得：$${\partial\over \partial\Theta_ij^{(l)}}J(\Theta)=a_j^{(l)}\delta_j^{(l+1)}$$

  注意这里忽略了正则化。后续会改善

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gtly0vw8ilj60vm0ggwhb02.jpg" alt="截屏2020-10-25 下午11.14.16" style="zoom:50%;" />

==反向传播算法思路：==

1. 定义训练数据集${(x^{(1)},y^{(1)}),...,(x^{(m)},y^{(m)})}$

2. 初始化误差$\Delta_{ij}^{(l)}$值

3. 遍历所有样本的循环

   3.1 定义$$a^{(1)}=x^{(i)}$$即设置输入值为第一层神经元的激活值

   3.2 前向传播计算出接下来各层的激活值$a^{(l)}$

   3.3 利用已知的样本标签，用第$L$层的预测值减去实际标签值的出$L$

层的误差值$\delta^{(L)}$

​	   3.4 反向传播计算出各层的$\delta$值（除了第一层输入层没有误差）

​       3.5 计算$\Delta_{ij}^{(l)} := \Delta_{ij}^{(l)}+a_j^{(l)}\delta_i^{(l+1)}$向量化：$\Delta^{(l)} := \Delta^{(l)}+\delta^{(l+1)}(a^{(l)})^T$

4. 分开计算偏移项的偏导数和其他项的偏导数

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gtly1a94vbj60us0gi40v02.jpg" alt="截屏2020-10-25 下午11.36.38" style="zoom:50%;" />

### 9.3 理解反向传播算法

前向传播图解：

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gtly1cemszj60u60fm0v202.jpg" alt="截屏2020-10-25 下午11.57.51" style="zoom:50%;" />

只有一个输出类别的举例：

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gtlxvriz69j60su0fc76e02.jpg" alt="截屏2020-10-26 上午12.00.21" style="zoom:50%;" />

反向传播理解：

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gtlxvx9ap3j60w80ie41e02.jpg" alt="截屏2020-10-26 上午12.05.53" style="zoom:50%;" />

### 9.4 矩阵展开为向量

### 9.5 梯度检验检查梯度传播bug

当$\theta$是实数R的情况下，双侧差分计算该点的近似导数

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gtly1hkr16j60xe0h0wgc02.jpg" alt="截屏2020-10-26 上午12.21.49" style="zoom:50%;" />

当$\theta$为向量参数的情况下，即为n维向量，计算导数近似值

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gtly1l82b9j60tw0fy40402.jpg" alt="截屏2020-10-26 上午12.24.14" style="zoom:50%;" />

计算过程：

<img src="/Users/zhouweijie/Library/Application Support/typora-user-images/截屏2020-10-26 上午12.27.27.png" alt="截屏2020-10-26 上午12.27.27" style="zoom:50%;" />

执行笔记：

1. 通过反向传播计算偏导数值DVec
2. 实现数值上的梯度检验，通过计算gradApprox
3. 确保DCvec和gradApprox取值近似
4. 通过检验后代码实现的时候关闭梯度检验提升计算效率

### 9.6 随机初始化权重参数

在神经网络中将权重参数$\theta$全部初始化为0是没有任何作用的

全部初始化为0的话会导致各向量值都一样，没有任何意义，相当于只有一个特征，形成了高度冗余。

因此参数需要进行随机初始化为$[-\epsilon,\epsilon]$

### 9.7 总体回顾

训练一个神经网络

1. 选取合适的神经网络结构：隐藏层数、神经元数

   通过输出特征和输出类别数确定神经网络的第一层和最后一层的神经元个数。注意输出类别y的向量表示。

   默认使用一层隐藏层，如果使用多个隐藏层默认每个隐藏层的神经元个数一致。隐藏单元一般为输入特征数的一倍或几倍

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gtly1r7t1nj60uq0gmq6202.jpg" alt="截屏2020-10-26 上午12.47.25" style="zoom:50%;" />

==实现训练一个神经网络的步骤：==

1. 确定神经网络结构并随机初始化权重参数（很小，接近0）
2. 执行前向传播算法，对输入特征x计算出相应的输出
3. 计算损失函数$J(\Theta)$
4. 执行反向传播计算偏导数项${\partial\over \partial\Theta_ij^{(l)}}J(\Theta)$
5. 使用梯度检验比较偏导数值，确保值接近最后关闭梯度检验
6. 使用一个优化算法，例如梯度下降或更先进的算法和反向传播结合去最小话损失函数$J(\Theta)$(注意是非凸函数，可能优化至局部最优化处，但也很不错了，可以改变初始权重参数)

### 9.8 反向传播实例——无人驾驶









