[TOC]

# Ubuntu16.04+ROS kinetic +Basler_camera环境配置以及相机标定

感谢：`https://blog.csdn.net/weixin_42469289/article/details/100566476`

## 安装ros 







## 安装pylon6 软件套装

下载对应版本的.deb安装包

```C++
$ sudo wget https://www.baslerweb.com/cn/sales-support/downloads/software-downloads/software-pylon-6-2-0-linux-x86-64bit-debian/
```

添加环境变量

```C++
$ echo “export PYLON_ROOT=/opt/pylon” >> ~/.bashrc
$ sudo sh -c 'echo "yaml https://raw.githubusercontent.com/magazino/pylon_camera/indigo-devel/rosdep/pylon_sdk.yaml " > /etc/ros/rosdep/sources.list.d/15-plyon_camera.list'
$ rosdep update
```

安装pylon-ROS-camera 驱动包

```C++
$ cd ~/catkin_ws/src/ && git clone https://github.com/basler/pylon-ros-camera
$ git clone https://github.com/dragandbot/dragandbot_common.git
// 安装依赖
rosdep install --from-paths . --ignore-src --rosdistro=$ROS_DISTRO -y
// 如果安装依赖失败，将命令修改为：
rosdep install --from-paths ~/catkin_ws/src/xxxxxxxx --ignore-src -r
// 编译
$ cd ~/catkin_ws && catkin_make
$ echo “source ~/catkin_ws/devel/setup.bash” >> ~/.bashrc
$ roslaunch pylon_camera pylon_camera_node.launch
```

https://github.com/basler/pylon-ros-camera

