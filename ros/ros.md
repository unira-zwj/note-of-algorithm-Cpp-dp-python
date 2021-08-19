[TOC]



![截屏2021-08-10 下午2.25.54](https://tva1.sinaimg.cn/large/008i3skNgy1gtbocyf4z2j31bs0h6di9.jpg)

# ROS命令行工具

**<u>常用命令：</u>**

- rostopic
- rosservice
- rosnode
- rosparam
- rosmsg
- rossrv
- Rosbag

```C++
$ roscore // 启动ros master
$ rosrun turtlesim turtlesim_node// 运行节点 rosrun + 功能包名 + 节点 
$ rosrun turtlesim turtle_teleop_key
$ rqt_graph // 显示计算图
$ rosnode // 显示节点信息 + ping, list, info, machine, kill, cleanup
$ rostopic // 显示话题信息 + bw, delay, echo, find, hz, info, list, pub, type
    
// exp: 发布数据让海龟动
$ rostopic pub /turtle1/cmd_vel geometry_msgs/Twist " ......" // 话题名 + 数据结构“内容”
// pub指令默认只发送一次，可以加频率/s -r 
$ rostopic pub -r 10 /turtle1/cmd_vel geometry_msgs/Twist " ......"
  
// 查看Twist消息结构是啥样：
$ rosmsg show geometry_msgs/Twist
    
$ rosservice // 显示服务信息
// 搞两只海龟
$ rosservice call /spawn "......"
    
// 话题记录，复现。 例如无人机不可能每次都飞起来调试，去外面飞一圈记录话题数据，回实验室复现数据进行实验
$ rosbag record -a -o cmd_record // 名字cmd_record
$ rosbag play cmd_record.bag // 
    

```

**<u>工作空间：</u>**

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gt5vatf2k9j30xb0u0di2.jpg" alt="截屏2021-08-05 下午1.52.56" style="zoom:50%;" />

```C++
// 创建工作空间
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ catkin_init_workspace
// 编译工作空间
$ cd ~/catkin_ws/
$ catkin_make
$ catkin_make install
// 设置环境变量
$ source devel/setup.bash
// 检查环境变量
$ echo $ROS_PACKAGE_PATH
// 创建功能包
$ cd ~/catkin_ws/src
$ catkin_create_pkg test_pkg std_msgs rospy roscpp // <pakage_name> [depend]
// 编译功能包
$ cd ~/catkin_ws
$ catkin_make
$ source ~/catkin_ws/devel/setup.bash
```

# 话题模型Topic

![IMG_29AFD65396F5-1](https://tva1.sinaimg.cn/large/008i3skNgy1gt5x5xfb8fj31ph0rjgnp.jpg)

- Publisher 发布节点
- Subscriber 接受节点
- massage 数据结构，数据内容
- Topic 管道

## 发布者publisher

```C++
// 创建功能包
$ cd ~/catkin_ws/src
$ catkin_create_pkg learning_topic roscpp rospy std_msgs geometry_msgs turtlesim
    
$ cd ~/catkin_ws/src/learning_topic/src
$ vi velocity_publisher.cpp
    
```

```C++
/**
 * topic: chatter
 * msg_type: geometry_msgs::Twist
 */

/** 
 * 如何实现一个发布者
 * 初始化ros节点
 * 向ros master注册节点信息，包括发布的话题名和话题中的消息类型
 * 创建消息数据
 * 按照一定频率循环发布消息
 */

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

/**
 * 通过海龟发送消息的简单示例的ros方法
 */
int main(int argc, char **argv) 
{
	/**
	 * ros::init()函数需要argc和argv，因此它能提供任何ROS的理由,并且可以在命令行将名字重映射.
	 * 对于程序化的重映射，可以使用不同版本的init()，这让重映射变得很直接.
	 * 但是对于大多数命令行的重映射来说，直接通过argc和argv加名字事更简单的一种方式
	 *
	 * 必须在使用其他任何ROS方法前声明一个ros::init()的版本
	 */
	ros::init(argc, argv, "talker"); // node_name

	/**
	 * NodeHandle是传递ROS方法的一个主要入口点
	 * 第一个NodeHandle的构造将完全吃实话这个节点句柄node
	 * 并且在最后NodeHandle的销毁将关闭这个节点句柄node
	 */
	ros::NodeHandle n;
    
	/**
	 * advertise()函数是你怎么样去告诉ROS你想通过一个指定的话题topic名字，创建一个发布publish
	 * 这会在ROS master node中唤起一个声明，注册一个发布者publisher和订阅者subscriber
	 * 在advertise()声明之后，master node将会通知任何一个想订阅subscribe这个话题topic name
	 * 并且他们将依次协商去点对点连接这些节点
	 * advertise()函数返回一个发布者，它允许你通过一个声明去publish()发布这个消息
	 * 当返回的Publisher发布者和它的副本都被销毁，这个话题topic会终结
	 * 
	 * advertise()的第二个参数是用于发布的消息的消息队列长度
	 * 如果消息被发布的速度超过了我们能发送他们的能力，就是消息太多了
	 * 这个参数就说明了多少的消息会进入缓冲，剩下的会丢弃
	 */
	ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/pose", 10);

	/**
	 * 设置循环频率
	 */
	ros::Rate loop_rate(10);
	
    /**
     * 计数，发送了多少次消息
     * 被用于为每个消息创建唯一字符串
     */
	int count = 0;
    
    /**
     * 默认情况下，roscpp将安装一个SIGINT处理程序，
     * 它能够处理Ctrl+C操作，让ros::ok()返回false。
	 * ros::ok()在以下情况会返回false：
	 *	 	收到SIGINT信号（Ctrl+C）
	 * 		被另一个同名的节点踢出了网络
	 * 		ros::shutdown()被程序的另一部分调用
	 *		所有的ros::NodeHandles都已被销毁
	 * 一旦ros::ok()返回false, 所有的ROS调用都会失败。
     */
	while (ros::ok())
	{
		/**
		 * 这是一个消息对象，用数据填满这个消息对象，并且发布它
		 * 这已经广播给了任何已经连接的节点
		 * 注意对象的类型必须和advertise<>()中<中的类型保持一致>
		 */
		geometry_msgs::Twist vel_msg;
        
		vel_msg.linear.x = 0.5;
		vel_msg.angular.z = 0.2;
		
        /**
         * 相当于printf/cout
         */
        ROS_INFO("Pulish turtle velocity command[%0.2f m/s, %0.2f rad/s]", 
				vel_msg.linear.x, vel_msg.angular.z);
        
		/**
		 * pulish()函数为发送消息，参数是消息对象
		 * 注意对象的类型必须和advertise<>()中<>中的类型保持一致
		 */
		turtle_vel_pub.publish(vel_msg);
		
        /**
         *此处调用ros::spinOnce()对于这个简单程序来说没啥必要，因为我们没有接收任何回调。
         * 然而，如果要在这个程序中添加订阅，但此处没有ros::spinOnce()的话，
         * 回调函数将永远不会被调用。所以还是加上吧。
         */
        ros::spinOnce();
		
        /**
         * 现在我们使用ros::Rate在剩下的时间内睡眠，以让我们达到10Hz的发布速率。
         */
		loop_rate.sleep();
        ++count;
	}
    
	return 0;
}
```

配置CMakeLists.txt的编译规则

- 设置需要编译的代码和生成可执行文件
- 设置链接库

```cmake
add_executable(velocity_publisher src/velocity_publisher.cpp)
target_link_libraries(velocity_publisher ${carkin_LIBRARIES})
```

编译：

```C++
$ cd ~/catkin_ws
$ catkin_make
$ source devel/setup.bash  // 注意这里设置环境变量和下面的run在同一个终端使用
$ roscore
$ rosrun turtlesim turtlesim_node
$ rosrun learning_topic velocity_publisher // 先在同一个终端设置环境变量
```

python版本：(package/scripts文件夹下)

```python
#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String

def talker():
    pub = rospy.Publisher('/turtle1/pose', String, queque_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) 
    while not rospy.is_shutdown():
		vel_msg.linear.x = 0.5
		vel_msg.angular.z = 0.2    
        ros
```





## 订阅者: subscriber

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gt61md7bamj31340imgml.jpg" alt="截屏2021-08-05 下午5.31.41" style="zoom:50%;" />

```C++
$ cd ~/catkin_ws/src/learning_topic/src
$ vi pose_subscriber.cpp
```

```C++
/**
 * 订阅话题：turtle1/pose，消息类型turtlesim::Pose
 */

/**
 * 初始化ROS系统
 * 订阅/turtle1/pose话题
 * 开始spin自循环，等待消息到达
 * 当消息达到后，调用回调函数
 */

#include <ros/ros.h>
#include "turtlesim/Pose.h"

/**
 * 这是一个回调函数，当有新消息到达chatter话题时它就会被调用。
 * 该消息是用boost shared_ptr智能指针传递的，这意味着你可以根据需要存储它，
 * 即不用担心它在下面被删除，又不必复制底层（underlying）数据。
 */
void poseCallback(const turtlesim::Pose::ConstPtr& msg) {

    ROS_INFO("Turtle pose: x:%0.6f , y:%0.6f", msg->x, msg->y);
}

int main(int argc, char **argv) {
    
    ros::init(argc, argv, "pose_subscriber");
    
    ros::NodeHandle n;
    
    /**
     * 通过主节点订阅chatter话题。每当有新消息到达时，ROS将调用chatterCallback()函数。
     * 第二个参数是队列大小，以防我们处理消息的速度不够快。
     * 在本例中，如果队列达到10条，再有新消息到达时旧消息会被丢弃。
     * 
     * NodeHandle::subscribe()返回一个ros::Subscriber对象，你必须保持它，除非想取消订阅。
     * 当Subscriber对象被析构，它将自动从chatter话题取消订阅。
     *
     * 还有另一些版本的NodeHandle::subscribe()函数，
     * 可以让你指定为类的成员函数，甚至是可以被Boost.Function对象调用的任何函数。
     * 请参见roscpp概览。
     */
    ros::Subscriber pose_sub = n.subscribe("/turtle1/pose", 10, poseCallback);
    
    /**
     * ros::spin()启动了一个自循环，它会尽可能快地调用消息回调函数。
     * 不过不要担心，如果没有什么事情，它就不会占用太多CPU。
     * 另外，一旦ros::ok()返回false，ros::spin()就会退出，
     * 这意味着ros::shutdown()被调用了，主节点让我们关闭（或是因为按下Ctrl+C，它被手动调用）。
     */
    ros::spin();
    return 0;
}
```

配置CMakeLists.txt的编译规则

- 设置需要编译的代码和生成可执行文件
- 设置链接库

```cmake
add_executable(pose_subscriber src/pose_subscriber.cpp)
target_link_libraries(pose_subscriber ${carkin_LIBRARIES})
```

编译：

```C++
$ cd ~/catkin_ws
$ catkin_make
$ source devel/setup.bash  // 注意这里设置环境变量和下面的run在同一个终端使用
$ roscore
$ rosrun turtlesim turtlesim_node
$ rosrun learning_topic pose_subscriber // 先在同一个终端设置环境变量
```

## 自定义话题消息msg

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gt710hzzxzj30ys0cyt9e.jpg" alt="截屏2021-08-06 下午1.56.14" style="zoom:50%;" />

- 定义 .msg 文件
- 在package.xml中添加功能包依赖
  - `<build_depend>message_generation</build_depend>`
  - `<exec_depend>message_runtime</exec_depend>`
- 在CMakeList.txt添加编译选项
  - `find_package(... message_generation)`
  - `add_message_file(FILES Person.msg)`
  - `generate_messages(DEPENDENCIES std_msgs)`
  - `catkin_package(... message_runtime)`
- 编译生成语言相关文件

```C++
$ sudo mkdir -p ~/catkin_ws/src/learning_topic/msg
$ cd ~/catkin_ws/src/learning_topic/msg
$ sudo vi Person.msg
```

```C++
// Person.msg
string name
uint8 sex
uint8 age
uint8 unknown = 0
uint8 male = 1
uint8 female = 2
```

```C++
// package.xml
// 动态生成程序的依赖
<build_depend>message_generation</build_depend> // 编译依赖，动态产生msg的功能包
<exec_depend>message_runtime</exec_depend> // 执行依赖，依赖动态msg的依赖
```

```C++
// CMakeList.txt
// 在find_package中添加功能包message_generation
find_package(... message_generation)

// 添加把.msg编译为不同程序文件的配置项
add_message_files(FILES Person.msg) // 定义接口
generate_messages(DEPENDENCIES std_msgs) // 定义依赖的ros包
    
// 在catkin_package()中创建运行依赖,去掉DEPEND的注释
catkin_package(... message_runtime)
```

**<u>传输自定义话题消息的发布者创建person_publisher</u>**

```C++
// person_publisher.cpp

/**
 * 发布/person_info话题，自定义消息类型learning_topic::Person
 */
#include <ros/ros.h>
#include "learning_topic/Person.h"

int main(int argc, char **argv) {
    // 节点初始化
    ros::init(argc, argv, "person_publisher");
    
    // 创建节点句柄
    ros::NodeHandle n;
    
    // 创建一个Publisher,发布名为/person_info的topic，消息类型为learning_topic::Person，队列长度为10
    ros::Publisher person_info_pub = n.advertise<learning_topic::Person>("/person_info", 10);
    
    // 设置循环频率
    ros::Rate loop_rate(1);
    
    int count = 0;
    while (ros::ok()) {
        // 初始化learning_topic::Preson类型的消息
        learning_topic::Person person_msg;
        person_msg.name = "Elon Zhou";
        person_msg.age = 22;
        person_msg.sex = learning_topic::Person::male;
        
        // 发布消息
        person_info_pub.publish(person_msg);
        
        ROS_INFO("Publish Person INFO: name:%s age:%d sex:%d", 
                 person_msg.name.c_str(), person_msg.age, person_msg.sex);
        
        loop_rate.sleep();
    }
    return 0;
}
```

**<u>传输自定义话题消息的订阅者创建person_subscriber</u>**

```C++
/**
 * 订阅/person_info话题，自定义消息类型learning_topic::Person
 */
#include <ros/ros.h>
#include "learning_topic/Person.h"

// 接收到订阅消息后的回调函数
void personInfoCallback(const learning_topic::Person::ConstPtr& msg) {
    // 打印
    ROS_INFO("Subscribe Person Info: name:%s age:%d sex:%d", msg->name.c_str(), msg->age, msg->sex);
}

int main(int argc, char **argv) {
    // 初始化节点
    ros::init(argc, argv, "person_subscriber");
    
    // 创建节点句柄
    ros::NodeHandle n;
    
    //创建一个Subscriber,订阅名为/person_info的topic，注册回调函数personInfoCallback
    ros::Subscriber person_info_sub = n.subscribe("/person_info", 10, personInfoCallback);
    
    // 循环等待回调函数
    ros::spin();
    
    return 0;
    
}
```

查看Person消息是否定义成功`rosmsg show Person`



CMakeList.txt

```cmake
add_executable(person_publisher src/person_publisher.cpp)
target_link_libraries(person_publisher ${catkin_LIBRARIES})
// 将可执行文件和动态头文件形成依赖关系
add_dependencies(person_publisher ${PROJECT_NAME}_generate_messages_cpp)

add_executable(person_subscriber src/person_subscriber.cpp)
target_link_libraries(person_subscriber ${catkin_LIBRARIES})
add_dependencies(person_subscriber ${PROJECT_NAME}_generate_messages_cpp)
```

==ros master作用是给节点创建连接，建立连接后关闭master之前建立的连接仍在==

# 服务模型service

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gt7389yov8j31080hewff.jpg" alt="截屏2021-08-06 下午3.12.57" style="zoom:50%;" />

客户端Client发送请求数据Request给服务端Server（小海龟窗口）

服务端反馈Response给客户端数据

中间服务service的名字为/spawn

/spawn中的消息为在turtlesim功能包中自定义的Spawn的数据结构

```C++
// 创建功能包
$ cd ~/catkin_ws/src
$ catkin_create_pkg learning_service roscpp rospy std_msgs geometry_msgs turtlesim
```



1. 创建一个启动此service/client的cpp文件的节点

2. 创建一个service/client的服务，注意service/client中的服务名字要一样

3. 服务端创建回调函数add，并阻塞线程等待请求

   ```CPP
   ros::ServiceServer service = n.advertiseService("learn_srvs", add);
   ros::ServiceClient client = n.serviceClient<learn_srvs::learn>("learn_srvs");
   ```

   

4. 客户端根据定义的消息类型结构，更改消息内容创建请求数据

   ```CPP
     learn_srvs::learn srv; // 创建learn_srvs消息类型的learn的消息结构（自定义）的对象srv
     srv.request.x = atoll(argv[1]);
     srv.request.y = atoll(argv[2]);
   ```

5. 服务端接收到请求，自动进入回调函数













# NOTIC

1. rosdep update 实在运行不了也不影响，这是个依赖包的下载

2. rospack find package_name 查找包路径

3. 安装vns远程桌面

   1. sudo apt-get install x11vnc
   2. x11vnc -storepasswd
   3. x11vnc -forever -shared -rfbauth ~/.vnc/passwd
   4. vnc4server -geometry 1920x1080 :1

4. Jetson nano功率设置

   1.  sudo /usr/sbin/nvpmodel -m 0/1
   2. sudo /usr/bin/jetson_clocks

5. sudo nmcli dev wifi connect wifiname password 123 连接wifi 

6. catkin_make -DCATKIN_WHITELIST_PACKAGES="package1;package2"

7. 自定义消息包编译出错，注意.msg是否粗心

8. 添加自定义头文件

   1.在.cpp文件中只要添加#include "包名/定义的头文件名"，例如我现在建立一个包名是path,在include文件下建立头文件是example.h,(打开include文件夹，里面还有一个文件夹，在这个文件夹下建立的头文件),那么在源文件中的写法是#include "path/example.h"

   2.在cmakelists.txt中只需要将catkin_package中的#include改成include ,即去掉前面的#就可以了

9. 报错RuntimeError: No DTB found for NVIDIA Jetson Nano Developer Kit!

   1. sudo mkdir /boot/dtb
   2. sudo cp -v /boot/tegra210-p3448-0000-p3449-0000-[ab]0[012].dtb /boot/dtb/

10. ros中使用cv

    1. find_package( OpenCV REQUIRED )
    2. target_link_libraries(xxxxxx ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

11. Rqt

    1. 显示节点关系`rosrun rqt_graph rqt_graph`
    2. 显示数据流`rosrun rqt_plot rqt_plot`
    3. 显示节点的输出`rosrun rqt_console rqt_console`,`r`
    4. `osrun rqt_logger_level rqt_logger_level`

12. 换源失败——jetson 需要换arm架构的源和x86的不一样

13. `151.101.84.133  raw.githubusercontent.com `

    1. 别再乱搞了行吗，就这个地址

14. ROS下的OpenCV配置：https://blog.csdn.net/weixin_43436587/article/details/107622477
15. Jetson nano安装性能检测
    1. sudo -H pip install jtop
    2. sudo jtop
16. 更改风扇策略/etc/rc.local
17. TCP通信，一定要释放缓存
