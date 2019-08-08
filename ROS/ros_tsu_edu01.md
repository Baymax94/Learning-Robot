## 乐聚教育开发版机器人及ROS系统学习
### node列表 
`rosnode list`   
/ImgSubscriber  
/SensorAqu  
/SensorHub  
/SensorPubDemo  
/img_compressed_publisher_node  
/rosout  
## 查看node信息  
```
rosnode info +列表
eg. 
rosnode info /ImgSubscriber
```
```
--------------------------------------------------------------------------------
Node [/ImgSubscriber]
Publications: 
 * /cv_bridge_image [sensor_msgs/Image]
 * /rosout [rosgraph_msgs/Log]

Subscriptions: 
 * /out_image_base_topic/compressed [sensor_msgs/CompressedImage]

Services: 
 * /ImgSubscriber/get_loggers
 * /ImgSubscriber/set_logger_level


contacting node http://Baymax:38943/ ...
Pid: 6372
Connections:
 * topic: /cv_bridge_image
    * to: /SensorPubDemo
    * direction: outbound
    * transport: TCPROS
 * topic: /out_image_base_topic/compressed
    * to: /img_compressed_publisher_node (http://raspberrypi:42197/)
    * direction: inbound
    * transport: TCPROS
```
## 运行node
rosrun
