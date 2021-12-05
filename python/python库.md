[TOC]

# 科学计算基础软件包NumPy

## ndarray对象、数据类型

***ndarray对象***

**ndarray = n 维数组**

ndarray 与数组不同，它不仅仅包含数据信息，还包括其他描述信息。ndarray 内部由以下内容组成：

- 数据指针：一个指向实际数据的指针。
- 数据类型（dtype）：描述了每个元素所占字节数。
- 维度（shape）：一个表示数组形状的元组。
- 跨度（strides）：一个表示从当前维度前进道下一维度的当前位置所需要“跨过”的字节数。

NumPy 中，数据存储在一个均匀连续的内存块中，可以这么理解，NumPy 将多维数组在内部以一维数组的方式存储，我们只要知道了每个元素所占的字节数（dtype）以及每个维度中元素的个数（shape），就可以快速定位到任意维度的任意一个元素。

```python
numpy.array(object, dtype = None, copy = True, order = None, subok = False, ndmin = 0)
```

**参数说明：**

| 名称   | 描述                                                      |
| :----- | :-------------------------------------------------------- |
| object | 数组或嵌套的数列                                          |
| dtype  | 数组元素的数据类型，可选                                  |
| copy   | 对象是否需要复制，可选                                    |
| order  | 创建数组的样式，C为行方向，F为列方向，A为任意方向（默认） |
| subok  | 默认返回一个与基类类型一致的数组                          |
| ndmin  | 指定生成数组的最小维度                                    |



***NumPy数据类型***

numpy 支持的数据类型比 Python 内置的类型要多很多，基本上可以和 C 语言的数据类型对应上，其中部分类型对应为 Python 内置的类型。下表列举了常用 NumPy 基本类型。

| 名称       | 描述                                                         |
| :--------- | :----------------------------------------------------------- |
| bool_      | 布尔型数据类型（True 或者 False）                            |
| int_       | 默认的整数类型（类似于 C 语言中的 long，int32 或 int64）     |
| intc       | 与 C 的 int 类型一样，一般是 int32 或 int 64                 |
| intp       | 用于索引的整数类型（类似于 C 的 ssize_t，一般情况下仍然是 int32 或 int64） |
| int8       | 字节（-128 to 127）                                          |
| int16      | 整数（-32768 to 32767）                                      |
| int32      | 整数（-2147483648 to 2147483647）                            |
| int64      | 整数（-9223372036854775808 to 9223372036854775807）          |
| uint8      | 无符号整数（0 to 255）                                       |
| uint16     | 无符号整数（0 to 65535）                                     |
| uint32     | 无符号整数（0 to 4294967295）                                |
| uint64     | 无符号整数（0 to 18446744073709551615）                      |
| float_     | float64 类型的简写                                           |
| float16    | 半精度浮点数，包括：1 个符号位，5 个指数位，10 个尾数位      |
| float32    | 单精度浮点数，包括：1 个符号位，8 个指数位，23 个尾数位      |
| float64    | 双精度浮点数，包括：1 个符号位，11 个指数位，52 个尾数位     |
| complex_   | complex128 类型的简写，即 128 位复数                         |
| complex64  | 复数，表示双 32 位浮点数（实数部分和虚数部分）               |
| complex128 | 复数，表示双 64 位浮点数（实数部分和虚数部分）               |

numpy 的数值类型实际上是 dtype 对象的实例，并对应唯一的字符，包括 np.bool_，np.int32，np.float32，等等。

**数据类型对象 (dtype)**

数据类型对象（numpy.dtype 类的实例）用来描述与数组对应的内存区域是如何使用，它描述了数据的以下几个方面：

* 数据的类型（整数，浮点数或者 Python 对象）
* 数据的大小（例如， 整数使用多少个字节存储）
* 数据的字节顺序（小端法或大端法）
* 在结构化类型的情况下，字段的名称、每个字段的数据类型和每个字段所取的内存块的部分
* 如果数据类型是子数组，那么它的形状和数据类型是什么。

字节顺序是通过对数据类型预先设定 **<** 或 **>** 来决定的。 **<** 意味着小端法(最小值存储在最小的地址，即低位组放在最前面)。**>** 意味着大端法(最重要的字节存储在最小的地址，即高位组放在最前面)。

dtype 对象是使用以下语法构造的：

```
numpy.dtype(object, align, copy)
```

* object - 要转换为的数据类型对象
* align - 如果为 true，填充字段使其类似 C 的结构体。
* copy - 复制 dtype 对象 ，如果为 false，则是对内置数据类型对象的引用



## NumPy数组属性及创建

***NumPy数组属性***

NumPy 数组的维数称为秩（rank），秩就是轴的数量，即数组的维度

很多时候可以声明 `axis`。`axis=0`，表示沿着第 0 轴进行操作，即对每一列进行操作；axis=1，表示沿着第1轴进行操作，即对每一行进行操作。

NumPy一维数组默认为向量，而向量就是一列，所以`axis = 0`代表第0轴

NumPy 的数组中比较重要 ndarray 对象属性有：

| 属性             | 说明                                        |
| :--------------- | :------------------------------------------ |
| ndarray.ndim     | 秩，即轴的数量或维度的数量                  |
| ndarray.shape    | 数组的维度，对于矩阵，n 行 m 列             |
| ndarray.size     | 数组元素的总个数，相当于 .shape 中 n*m 的值 |
| ndarray.dtype    | ndarray 对象的元素类型                      |
| ndarray.itemsize | ndarray 对象中每个元素的大小，以字节为单位  |
| ndarray.flags    | ndarray 对象的内存信息                      |
| ndarray.real     | ndarray元素的实部                           |
| ndarray.imag     | ndarray 元素的虚部                          |
| ndarray.data     |                                             |



***创建数组***









# 结构化数据分析工具Pandas





# 绘图库Matplotlib





# 科学计算工具包SciPy



# 图像数据增强 (augmentation) 库imgaug

[imgaug.doc](https://imgaug.readthedocs.io/en/latest/index.html)

`imgaug` 是一个机器学习图像增强库，可以随标注一起变换。

![重型增强](https://tva1.sinaimg.cn/large/008i3skNgy1gx1xa2xi9aj30eh0790tj.jpg)

## 安装

支持 `Python2.7 - 3.8` 

***Anaconda 安装***

```
conda config --add channels conda-forge
conda install imgaug
```

***pip 安装***

```
pip install imagecorruptions
pip install imgaug
```

如果报错 `Shapely` ，尝试下面的方法：

```
pip install six numpy scipy Pillow matplotlib scikit-image opencv-python imageio
pip install --no-dependencies imgaug
```

`git` 安装最新版

```
pip install imagecorruptions
pip install git+https://github.com/aleju/imgaug.git
```

***卸载***

```
conda remove imgaug
pip uninstall imgaug
```

## 基本使用

定义变换序列 -> 将图像batch传入

```python
from imgaug import augmenters as iaa

seq = iaa.Sequential([
    # 每条边随机裁剪0-16个像素
    iaa.Crop(px=(0, 16)),
    # 50%的几率水平翻转图像
    iaa.Fliplr(0.5), 
    # 高斯模糊，sigma为0-3
    iaa.GaussianBlur(sigma=(0, 3.0)) 
])

for batch_idx in range(1000):
    # 输入图像必须是四维数组(N, height, width, channels)
    # 或者3维数组的一个list列表(height, width, channels)
    # 灰度图像也必须是1通道的三维数组， (height, width, 1)
    # 所有图像必须是 numpy 的 uint8 数据结构。值的区间在0-255
    images = load_batch(batch_idx)
    images_aug = seq.augment_images(images)
    train_on_images(images_aug)
```

## Augmenters常用函数

**`iaa.Sequential()`** 

产生图像增强序列

```python
iaa.Sequential(children=None,
               random_order=False,
               name=None,
               deterministic=False,
               random_state=None)
```

参数：

- `children`: 想要应用在图像上的 Augmenter 或者 Augmenter 集合。默认 None
- `random_order`: `bool`类型, 默认`False`。是否对每个 batch 的图片应用不同顺序
- `Augmenter list`。当设置为`True`时，不同 batch 之间图片的处理顺序都会不一样，但是同一个 batch 内顺序相同。
- `deterministic`: `bool`类型, 默认`False`。



**`iaa.SomeOf()`**

将Augmenter中的部分变换应用在图片处理上，而不是应用所有的Augmenter。例如：可以定义20种变换，但每次只选择其中的5个。但是不支持固定选择某一个Augmenter。

```python
iaa.SomeOf(n=None,
           children=None,
           random_order=False,
           name=None,
           deterministic=False,
           random_state=None)
```

参数:

* n: 从总的Augmenters中选择多少个。可以是一个int, tuple, list或者随机值。
* random_order: 是否每次顺序不一样。

例子：

```python
# 每次使用1~3个Augmenter来处理图片,每个batch中的Augmenters顺序一样。
# 每次一个就是(1, [])
# 每次1-多 ((1, None), [])
seq = iaa.SomeOf((1, 3), [
     iaa.Fliplr(1.0),
     iaa.Flipud(1.0),
     iaa.GaussianBlur(1.0)
 ])
imgs_aug = seq.augment_images(imgs)
```

**`iaa.OneOf()`**

每次选一个augmenter

```python
iaa.OneOf(children,
         name=None
         deterministic=False
         random_state=None)
```

**`iaa.Sometimes()`**

对batch中的一部分图片应用一部分Augmenters,剩下的图片应用另外的Augmenters。

```python
iaa.Sometimes(p=0.5,
              then_list=None,
              else_list=None,
              name=None,
              deterministic=False,
              random_state=None)
```

- `p`: float。多大比例的图片会被Augmente。
- `then_list`: Augmenter集合。p概率的图片进行变换的Augmenters。
- `else_list`: 1-p概率的图片会被进行变换的Augmenters。注意变换的图片应用Augmenter只能是then_list或者else_list中的一个。

**`iaa.WithColarspace()`**

在某个特定的颜色空间对图像进行变换。即：先将图片从一个颜色空间变换到另一个颜色空间,然后在另一个颜色空间中对图像进行变换,最后再变换回原来的颜色空间。

```python
iaa.WithColorspace(to_colorspace,
                   from_colorspace='RGB',
                   children=None,
                   name=None,
                   deterministic=False,
                   random_state=None)
```

* `to_colorspace`: 要变换的颜色空间。有以下选择:RGB, BGR, GRAY, CIE, YCrCb, HSV, HLS, Lab, Luv
* `from_colorspace`: 原来的颜色空间, 默认RGB。
* `children`: 要执行的变换。

例子：

```python
# 先将图片从RGB变换到HSV,然后将H值增加10,然后再变换回RGB。
aug = iaa.WithColorspace(to_colorspace="HSV",
                         from_colorspace="RGB",
                         children=iaa.WithChannels(0, iaa.Add(10)))
```

**`iaa.WithChannels()`**

选择图像通道变换

```python
iaa.WithChannels(channels=None,
                 children=None,
                 name=None,
                 deterministic=False,
                 random_state=None)
```

* `channels`: int或者int list。哪些channel要被用来变换。
* `children`: channel被选出来之后要进行哪些变换。

**`iaa.Noop()`**

不进行任何变换。某些情况下只想使用一个Augmenter作为占位符,这样可以继续调用augment_image()函数,但实际不作变换。例如进行测试的时候可以使用这个。

**`iaa.Lambda()`**

自定义变换函数

```python
iaa.Lambda(func_images,
           func_keypoints,
           name=None,
           deterministic=False,
           random_state=None)
```

* `func_images`: 对每一个image调用此函数。该函数的形式为：

```python
function(images, random_state, parents, hooks)
# 该函数必须返回变换后的图片。
```

- `func_keypoints`: 对每个图像的关键点进行变换的函数。该函数形式为:

```python
function(keypoints_on_images, random_state, parents, hooks)
# 改函数返回变换后的keypoint
```

例子：

```python
def func_images(images, random_state, parents, hooks):
    images[:, ::2, :, :] = 0
    return images

def func_keypoints(keypoints_on_images, random_state, parents, hooks):
    return keypoints_on_images

aug = iaa.Lambda(
    func_images=func_images,
    func_keypoints=func_keypoints
)
```

将每张图片没隔两行的像素点变成黑色的条带,关键点保留。

![这里写图片描述](https://tva1.sinaimg.cn/large/008i3skNgy1gx206pb6pqj30ed077js1.jpg)

**`iaa.AssertShape()`**

输入图像形状检测和关键点检测，不满足要求抛出异常

```python
iaa.AssertShape(shape,
                check_images=True,
                check_keypoints=True,
                name=None,
                deterministic=False,
                random_state=None)
```

- shape: 元组，通常形式为(N, H, W, C)。元组中每个元素的值可以为：None, int, 两个int类型的tuple或者一个int类型的list。如果是None,表示所有值都可以接受。如果是int,则只有对应的位置是该值才会被接受。如果是int类型的tuple,例如(a,b),则对应位置的值必须是a<=x

例子：

```python
# 检查输入的每张图片是否是32×32×3的,如果是则执行水平翻转,否则报错
seq = iaa.Sequential([
    iaa.AssertShape((None, 32, 32, 3)),
    iaa.Fliplr(0.5)
])

# 先检查图片的高度是否是32<=H<64, 宽度是否是32, channel是否是1或者3。如果都满足则执行水平翻转,否则报错。
seq = iaa.Sequential([
    iaa.AssertShape((None, (32, 64), 32, [1, 3])),
    iaa.Fliplr(0.5)
])
```

**`iaa.Scale()`**

缩放至固定大小

```python
iaa.Scale(size,
          interpolation='cubic',
          name=None,
          deterministic=False,
          random_state=None)
```

- `size`: 字符串”keep”,此时保持图像原大小不坐缩放。如果是一个整数n,则缩放成(n, n)。如果是一个float v,则每张图片会被缩放成(H*v, W*v),此时每张图像大小仍然不一样。如果是一个tuple类型(a, b), 如果a、b中至少有一个小数,则从[a,b]中挑选一个数作为缩放比例。如果a、b都是整数,则从[a,b]中挑选一个整数作为缩放后的大小。如果是1个list,则list中的数要么全是整数,要么全是小数(不能混用)。如果是一个dict类型,则该dict必须有两个key: height和width。每个key的值仍然可以按照上面的方法选取。此外, key的值还可以是”keep-aspect-ratio”, 表示按照比例缩放。
- `interpolation`: 缩放方法。如果是All, 则会随机从下面挑选一个: nearest、linear、area、cubic,注意每张图片可能不一样。如果是int,则应该是下面的一种：cv2.INTER_NEAREST, cv2.INTER_LINEAR, cv2.INTER_AREA,cv2.INTER_CUBIC。如果是string,则该种方法会被一直使用,必须是下面的一种： nearest, linear, area, cubic。如果是int list或者string list, 则每张图片会从中随机选取一个。

**`iaa.CropAndPad()`**

截取(crop)或者填充(pad),填充时,被填充区域为黑色。

```python
iaa.CropAndPad(px=None,
               percent=None,
               pad_mode='constant',
               pad_cval=0,
               keep_size=True,
               sample_independently=True,
               name=None,
               deterministic=False,
               random_state=None)
```

- px: 想要crop(negative values)的或者pad(positive values)的像素点。注意与percent不能同时存在。如果是None, pixel级别的crop不会被使用。int或者int list与上面相同。如果是一个4个元素的tuple,那么4个元素分别代表(top, right, bottom, left),每个元素可以是int或者int tuple或者int list。
- percent：按比例来crop或者pad, 与px相同。但是两者不能同时存在。
- pad_mode: 填充方式。可以是All, string, string list。可选的填充方式有: constant, edge, linear_ramp, maximum, median, minimum, reflect, symmetric, wrap。具体含义可查numpy文档。
- pad_cval: float、int、float tuple、int tuple、float list、int list。当pad_mode=constant的时候选择填充的值。
- keep_size: bool类型。经过crop后,图像大小会改变。如果该值设置为1,则在crop或者pad后再缩放成原来的大小。
- sample_independently : bool类型。如果设置为False,则每次从px或者percent中选出来的值会作用在四个方位。

**`iaa.Pad()`**

与iaa.CropAndPad()相同,只接受positive values。

**`iaa.Crop()`**

与iaa.CropAndPad()相同,只接受negative values。

**`iaa.Fliplr()`**

水平镜面翻转。

```python
iaa.Fliplr(p=0, name=None, deterministic=False, random_state=None)
```

- `p`: int或者float,每张图片呗翻转的概率

**`iaa.Flipud()`**

上下翻转

**`iaa.ChangeColorspace()`**

改变图像空间

```python
iaa.ChangeColorspace(to_colorspace, from_colorspace='RGB', alpha=1.0, name=None, deterministic=False, random_state=None)
```

* to_colorspace: 见上。
* from_colorspace: 见上。
* alpha: 覆盖旧的颜色空间时，新颜色空间的Alpha值。为`int, float, int tuple, float tuple`。

**`iaa.Grayscale()`**

变成灰度图

```python
iaa.Grayscale(alpha=0, from_colorspace='RGB', name=None, deterministic=False, random_state=None)
```

* alpha: 覆盖旧的颜色空间时，新颜色空间的Alpha值。

**`iaa.GaussianBlur()`**

高斯扰动

```python
iaa.GaussianBlur(sigma=0, name=None, deterministic=False, random_state=None)
```

* sigma: 高斯变换的标准差。可为`float, float tuple`。常见的有0,不扰动。3,强扰动。

**`iaa.AverageBlur()`**

均值扰动

```python
iaa.AverageBlur(k=1, name=None, deterministic=False, random_state=None)
```

* k:窗口大小。可为`int, int tuple`。当为`int tuple`时,如果每个元素也是`tuple`,每个元素分别作为height和width,窗口大小不一致。

**`iaa.MedianBlur()`**

中值扰动

```python
iaa.MedianBlur(k=1, name=None, deterministic=False, random_state=None)
```

**`iaa.Convolve()`**

对图像进行卷积

```python
iaa.Convolve(matrix=None, name=None, deterministic=False, random_state=None)
```

* matrix: 卷积矩阵。

**`iaa.Sharpen()`**

锐化

```python
iaa.Sharpen(alpha=0, lightness=1, name=None, deterministic=False, random_state=None)
```

**`iaa.EdgeDetect()`**

边缘检测

```python
iaa.EdgeDetect(alpha=0, name=None, deterministic=False, random_state=None)
```

**`iaa.Emboss()`**

浮雕效果

```python
iaa.Emboss(alpha=0, strength=1, name=None, deterministic=False, random_state=None)
```

**`iaa.DirectedEdgeDetect()`**

特定方向的边缘检测

```python
iaa.DirectedEdgeDetect(alpha=0, direction=(0.0, 1.0), name=None, deterministic=False, random_state=None)
```

**`iaa.Add()`**

随机增加一个值

```python
iaa.Add(value=0, per_channel=False, name=None, deterministic=False, random_state=None)
```

**`iaa.AddElementwise()`**

按像素增加

```python
iaa.AddElementwise(value=0, per_channel=False, name=None, deterministic=False, random_state=None)
```

**`iaa.AdditiveGaussianNoise()`**

添加高斯噪声。

```python
iaa.AdditiveGaussianNoise(loc=0, scale=0, per_channel=False, name=None, deterministic=False, random_state=None)
```

**`iaa.Multiply()`**

给图像中的每个像素点乘一个值使得图片更亮或者更暗。

```python
iaa.Multiply(mul=1.0, per_channel=False, name=None, deterministic=False, random_state=None)
```

**` iaa.MultiplyElementwise()`**

按像素值乘。

```python
iaa.MultiplyElementwise(self, mul=1.0, per_channel=False, name=None, deterministic=False, random_state=None)
```

**`iaa.Dropout()`**

随机去掉一些像素点, 即把这些像素点变成0。

```python
iaa.Dropout(p=0, per_channel=False, name=None, deterministic=False, random_state=None)
```

**`iaa.CoarseDropout()`**

将矩形框的值设置为0。

```python
iaa.CoarseDropout(p=0, size_px=None, size_percent=None, per_channel=False, min_size=4, name=None, deterministic=False, random_state=None)
```

**`iaa.Invert()`**

将每个像素值p变成255-p。

```python
iaa.Invert(p=0, per_channel=False, min_value=0, max_value=255, name=None, deterministic=False, random_state=None)
```

**`iaa.ContrastNormalization()`**

改变图像的对比度。

```python
iaa.ContrastNormalization(alpha=1.0, per_channel=False, name=None, deterministic=False, random_state=None)
```

**`iaa.Affine()`**

仿射变换。包含：平移(Translation)、旋转(Rotation)、放缩(zoom)、错切(shear)。仿设变换通常会产生一些新的像素点,我们需要指定这些新的像素点的生成方法,这种指定通过设置`cval`和`mode`两个参数来实现。参数`order`用来设置插值方法。

```python
iaa.Affine(scale=1.0,
           translate_percent=None,
           translate_px=None,
           rotate=0.0,
           shear=0.0,
           order=1,
           cval=0,
           mode='constant',
           name=None, deterministic=False, random_state=None)
```

- scale: 图像缩放因子。1表示不缩放,0.5表示缩小到原来的50%。此参数可以是float, float tuple, dict。如果是float, 则所有图片按照这种比例缩放。如果是float tuple, 则随机选取一个值来进行缩放,此时x-axis和y-axis的缩放比例相同。如果是一个dict,则应该有两个key:x, y,每个x或y的值都可以是float, float tuple,此时x-axis和y-axis的缩放比例不一样。
- translate_percent: 平移比例,0表示不平移,0.5表示平移50%。可以是float, float tuple, dict,具体含义与scale相同。用正负来表示平移方向。
- translate_px: 按照像素来进行平移。可以是int, int tuple, dict,具体含义与translate_percent相同。
- rotate: 平移角度,0~360度之间,正负也可以表示方向。可以为float, float tuple。
- shear: 错切的程度,0~360度之间,正负表示方向。可以为float, int, float tuple, int tuple。
- order: 插值顺序,与skimage中定义相同。下面0和1方法快,3比较慢,4、5特别慢。可以是int, int list, ia.ALL。如果是ia.ALL,则每次从所有的插值方法中随机选取。

  - 0：最邻近插值。

  - 1: 双线性插值(默认)。

  - 2: 双二次插值(不推荐)。

  - 3：双三次插值。

  - 4: Bi-quartic。

  - 5：Bi-quintic。
- cval: 当平移后使用常量填充的时候指定填充的常量值,只有在mode=constant的时候才会生效。可以是int, float, tuple, ia.ALL。如果是ia.ALL,则会从[0,255]之间随机选取一个值填充。
- mode: 采用何种方式填充经过变换后空白的像素点。可以是string, string list, ia.ALL。基本用法与上面相同。其中字符串的选取范围是:
    - constant: 采用一个常量填充。
    - edge: 边缘填充。
    - symmetric: 镜面对称填充。
    - reflect: Pads with the reflection of the vector mirrored on the first and last values of the vector along each axis.
    - wrap: Pads with the wrap of the vector along the axis. The first values are used to pad the end and the end values are used to pad the beginning.


**`iaa.PiecewiseAffine()`**

随机放置一些规则的网格点然后移动这些点的周围的像素。这回导致局部的扭曲。

```python
iaa.PiecewiseAffine(scale=0,
                    nb_rows=4,
                    nb_cols=4,
                    order=1,
                    cval=0,
                    mode='constant',
                    name=None, deterministic=False, random_state=None)
```

**`iaa.ElasticTransformation()`**

通过移动局部像素来变换。

```python
iaa.ElasticTransformation(alpha=0,
                          sigma=0,
                          name=None,
                          deterministic=False,
                          random_state=None)
```

## keypoint变换

imgaug支持在图像变换的同时变换图像中的关键点。例子如下:

```python
import imgaug as ia
from imgaug import augmenters as iaa

iaa.seed(1)

image=ia.quokka(size=(256,256))

# 定义4个关键点
keypoints=ia.KeypointsOnImage([
    ia.Keypoint(x=65, y=100),
    ia.Keypoint(x=75, y=200),
    ia.Keypoint(x=100, y=100),
    ia.Keypoint(x=200, y=80)
], shape=image.shape)

# 定义一个变换序列
seq = iaa.Sequential([
    iaa.Multiply((1.2, 1.5)), # 改变亮度,不影响关键点
    iaa.Affine(
        rotate=10,
        scale=(0.5, 0.7)
    ) # 旋转10度然后缩放,会影响关键点
])

# 固定变换序列,之后就可以先变换图像然后变换关键点,这样可以保证两次的变换完全相同。
# 如果调用次函数,需要在每次batch的时候都调用一次,否则不同的batch执行相同的变换。
seq_det = seq.to_deterministic()

# 转换成list或者batch来变换。由于只有一张图片, 因此用[0]来取出该图和关键点。
image_aug = seq_det.augment_images([image])[0]
keypoints_aug = seq_det.augment_keypoints([keypoints])[0]

# print coordinates before/after augmentation (see below)
# use after.x_int and after.y_int to get rounded integer coordinates
for i in range(len(keypoints.keypoints)):
    before = keypoints.keypoints[i]
    after = keypoints_aug.keypoints[i]
    print("Keypoint %d: (%.8f, %.8f) -> (%.8f, %.8f)" % (
        i, before.x, before.y, after.x, after.y)
    )

# 将关键点画在图片上。
# image with keypoints before/after augmentation (shown below)
image_before = keypoints.draw_on_image(image, size=7)
image_after = keypoints_aug.draw_on_image(image_aug, size=7)

fig, axes = plt.subplots(2, 1, figsize=(20, 15))
plt.subplots_adjust(left=0.2, bottom=0.2, right=0.8, top=0.8, hspace=0.3, wspace=0.0)
axes[0].set_title("image before")
axes[0].imshow(image_before)
axes[1].set_title("image after augmentation")
axes[1].imshow(image_after)

plt.show()
```

## Bounding Boxes变换

imgaug在图像变换的同时变换图像中的bound box。bounding的支持包括:

- 将bounding box封装成对象
- 对bounding box进行变换
- 将bounding box画在图像上
- 移动bounding box的位置,将变换后的bounding box映射到图像上,计算bounding box的IoU。

**基本变换**

```python
import imgaug as ia
from imgaug import augmenters as iaa

ia.seed(1)

image = ia.quokka(size=(256, 256))

# 定义2个bounding box
bbs = ia.BoundingBoxesOnImage([
    ia.BoundingBox(x1=65, y1=100, x2=200, y2=150),
    ia.BoundingBox(x1=150, y1=80, x2=200, y2=130)
], shape=image.shape)

seq = iaa.Sequential([
    iaa.Multiply((1.2, 1.5)), # 改变亮度, 不影响bounding box
    iaa.Affine(
        translate_px={"x": 40, "y": 60},
        scale=(0.5, 0.7)
    ) # 平移后缩放,会影响bounding box
])

# 固定变换
seq_det = seq.to_deterministic()

# 变换图像和bounding box
image_aug = seq_det.augment_images([image])[0]
bbs_aug = seq_det.augment_bounding_boxes([bbs])[0]

# 打印坐标
# use .x1_int, .y_int, ... to get integer coordinates
for i in range(len(bbs.bounding_boxes)):
    before = bbs.bounding_boxes[i]
    after = bbs_aug.bounding_boxes[i]
    print("BB %d: (%.4f, %.4f, %.4f, %.4f) -> (%.4f, %.4f, %.4f, %.4f)" % (
        i,
        before.x1, before.y1, before.x2, before.y2,
        after.x1, after.y1, after.x2, after.y2)
    )
# 输出
# BB 0: (65.0000, 100.0000, 200.0000, 150.0000) -> (130.7524, 171.3311, 210.1272, 200.7291)
# BB 1: (150.0000, 80.0000, 200.0000, 130.0000) -> (180.7291, 159.5718, 210.1272, 188.9699)

# image with BBs before/after augmentation (shown below)
image_before = bbs.draw_on_image(image, thickness=2)
image_after = bbs_aug.draw_on_image(image_aug, thickness=2, color=[0, 0, 255])

fig, axes = plt.subplots(2, 1, figsize=(20, 15))
plt.subplots_adjust(left=0.2, bottom=0.2, right=0.8, top=0.8, hspace=0.3, wspace=0.0)
axes[0].set_title("image before")
axes[0].imshow(image_before)
axes[1].set_title("image after augmentation")
axes[1].imshow(image_after)

plt.show()
```

**平移bounding box**

调用  `shift `函数

```python
import imgaug as ia
from imgaug import augmenters as iaa

ia.seed(1)

# Define image and two bounding boxes
image = ia.quokka(size=(256, 256))
bbs = ia.BoundingBoxesOnImage([
    ia.BoundingBox(x1=25, x2=75, y1=25, y2=75),
    ia.BoundingBox(x1=100, x2=150, y1=25, y2=75)
], shape=image.shape)

# 两个box先右移动25像素,然后第2个box再向下移动25像素
bbs_shifted = bbs.shift(left=25)
bbs_shifted.bounding_boxes[1] = bbs_shifted.bounding_boxes[1].shift(top=25)

# Draw images before/after moving BBs
image = bbs.draw_on_image(image, color=[0, 255, 0], thickness=2, alpha=0.75)
image = bbs_shifted.draw_on_image(image, color=[0, 0, 255], thickness=2, alpha=0.75)
```

**图像有缩放时 bounding box 的映射**

调用 `on` 函数

```python
import imgaug as ia
from imgaug import augmenters as iaa

ia.seed(1)

# Define image with two bounding boxes
image = ia.quokka(size=(256, 256))
bbs = ia.BoundingBoxesOnImage([
    ia.BoundingBox(x1=25, x2=75, y1=25, y2=75),
    ia.BoundingBox(x1=100, x2=150, y1=25, y2=75)
], shape=image.shape)

# Rescale image and bounding boxes
image_rescaled = ia.imresize_single_image(image, (512, 512))
bbs_rescaled = bbs.on(image_rescaled)

# Draw image before/after rescaling and with rescaled bounding boxes
image_bbs = bbs.draw_on_image(image, thickness=2)
image_rescaled_bbs = bbs_rescaled.draw_on_image(image_rescaled, thickness=2)
```

![这里写图片描述](https://tva1.sinaimg.cn/large/008i3skNgy1gx2x5c5wc9j3076076dfu.jpg)

**计算Intersections, Unions和IoU**

```python
import imgaug as ia
from imgaug import augmenters as iaa
import numpy as np

ia.seed(1)

# Define image with two bounding boxes.
image = ia.quokka(size=(256, 256))
bb1 = ia.BoundingBox(x1=50, x2=100, y1=25, y2=75)
bb2 = ia.BoundingBox(x1=75, x2=125, y1=50, y2=100)

# Compute intersection, union and IoU value
# Intersection and union are both bounding boxes. They are here
# decreased/increased in size purely for better visualization.
bb_inters = bb1.intersection(bb2).extend(all_sides=-1)
bb_union = bb1.union(bb2).extend(all_sides=2)
iou = bb1.iou(bb2)

# Draw bounding boxes, intersection, union and IoU value on image.
image_bbs = np.copy(image)
image_bbs = bb1.draw_on_image(image_bbs, thickness=2, color=[0, 255, 0])
image_bbs = bb2.draw_on_image(image_bbs, thickness=2, color=[0, 255, 0])
image_bbs = bb_inters.draw_on_image(image_bbs, thickness=2, color=[255, 0, 0])
image_bbs = bb_union.draw_on_image(image_bbs, thickness=2, color=[0, 0, 255])
image_bbs = ia.draw_text(
    image_bbs, text="IoU=%.2f" % (iou,),
    x=bb_union.x2+10, y=bb_union.y1+bb_union.height//2,
    color=[255, 255, 255], size=13
)
```

![这里写图片描述](https://tva1.sinaimg.cn/large/008i3skNgy1gx2x59jfbnj3076076mx6.jpg)



## Stochastic Parameter

在做变换的时候,我们希望每张图片的变换都不一样,通过参数随机化选取可以实现。但是想要复现之前的变换,需要通过`determinism`来实现,比较繁琐。为了避免这种情况,使用`Stochastic Parameters`来实现。这个变量通常是一个抽象的概率分布,例如正太分布、均匀分布等等。通常所有的`augmenter`都能接受这个参数,这样就很方便控制变量范围。他们都可以和`determinism`结合。
例子：

```python
from imgaug import augmenters as iaa
from imgaug import parameters as iap

seq = iaa.Sequential([
    iaa.GaussianBlur(
        sigma=iap.Uniform(0.0, 1.0)
    ),
    iaa.ContrastNormalization(
        iap.Choice(
            [1.0, 1.5, 3.0],
            p=[0.5, 0.3, 0.2]
        )
    ),
    iaa.Affine(
        rotate=iap.Normal(0.0, 30),
        translate_px=iap.RandomSign(iap.Poisson(3))
    ),
    iaa.AddElementwise(
        iap.Discretize(
            (iap.Beta(0.5, 0.5) * 2 - 1.0) * 64
        )
    ),
    iaa.Multiply(
        iap.Positive(iap.Normal(0.0, 0.1)) + 1.0
    )
])
```

所有可用的概率分布有:

**正态分布**

Normal(loc, scale): 均值为loc,标准差scale。

```python
from imgaug import parameters as iap
params = [
    iap.Normal(0, 1),
    iap.Normal(5, 3),
    iap.Normal(iap.Choice([-3, 3]), 1),
    iap.Normal(iap.Uniform(-3, 3), 1)
]
iap.show_distributions_grid(params)
```

**拉普拉斯分布**

Laplace(loc, scale): 峰值loc, 宽度scale:

```python
from imgaug import parameters as iap
params = [
    iap.Laplace(0, 1),
    iap.Laplace(5, 3),
    iap.Laplace(iap.Choice([-3, 3]), 1),
    iap.Laplace(iap.Uniform(-3, 3), 1)
]
iap.show_distributions_grid(params)
```

**其他连续概率分布还有:****

* 卡方分布(ChiSquare)
* 韦伯分布(Weibull)
* 均匀分布(Uniform )
* Beta分布

**离散概率分布**

* 二项分布(Binomial)
* 离散均匀分布(DiscreteUniform)
* 泊松分布(Poisson distribution)

**对分布的数学运算**

imgaug支持随机参数的算术运算。 允许修改从分布中抽取的值或者将几个分布相互组合。支持的操作有:

* Add
* Subtract
* Multiply
* Divide
* Power

**特殊参数**

支持的操作有：

* Deterministic
* Choice
* Clip
* Discretize
* Absolute
* RandomSign
* ForceSign
* Positive
* Negative
* FromLowerResolution

## Blending/Overlaying images

augment会直接改变图片而把原图舍弃掉了。有时我们需要改变图像的局部,或者将原来的图片跟新变换的图片结合起来。这可以通过给变换前后的图片配上一定的权重(αα参数)或者使用一个pixel-wise的mask。
一个例子如下：

```python
# First row
iaa.Alpha(
    (0.0, 1.0),
    first=iaa.MedianBlur(11),
    per_channel=True
)

# Second row
iaa.SimplexNoiseAlpha(
    first=iaa.EdgeDetect(1.0),
    per_channel=False
)

# Third row
iaa.SimplexNoiseAlpha(
    first=iaa.EdgeDetect(1.0),
    second=iaa.ContrastNormalization((0.5, 2.0)),
    per_channel=0.5
)

# Forth row
iaa.FrequencyNoiseAlpha(
    first=iaa.Affine(
        rotate=(-10, 10),
        translate_px={"x": (-4, 4), "y": (-4, 4)}
    ),
    second=iaa.AddToHueAndSaturation((-40, 40)),
    per_channel=0.5
)

# Fifth row
iaa.SimplexNoiseAlpha(
    first=iaa.SimplexNoiseAlpha(
        first=iaa.EdgeDetect(1.0),
        second=iaa.ContrastNormalization((0.5, 2.0)),
        per_channel=True
    ),
    second=iaa.FrequencyNoiseAlpha(
        exponent=(-2.5, -1.0),
        first=iaa.Affine(
            rotate=(-10, 10),
            translate_px={"x": (-4, 4), "y": (-4, 4)}
        ),
        second=iaa.AddToHueAndSaturation((-40, 40)),
        per_channel=True
    ),
    per_channel=True,
    aggregation_method="max",
    sigmoid=False
)
```

![这里写图片描述](https://tva1.sinaimg.cn/large/008i3skNgy1gx2x8oct63j30u50ngtfi.jpg)
