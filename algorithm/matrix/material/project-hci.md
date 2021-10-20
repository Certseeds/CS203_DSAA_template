<!--
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-05-07 10:27:33
 * @LastEditTime: 2020-05-07 10:39:11
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->
## Controlling your computer remotely by hands
At present, the COVID-19 is wantonly propagated in the world, and it has a major negative impact on daily life in all countries. In particular, it is pointed out that the facilities that humans often use, including elevators, computers, mobile phones, medical instruments and screens, generally consist of plastics and stainless steels. The recent research clearly shows that the virus can survive for 2-3 days on these surfaces, which is a very worrying conclusion. When people use these devices, the current inevitable way is to directly touch the screen and buttons. There is no doubt that the chance of spreading coronavirus is greatly increased. Therefore, designing a new non-contact interactive system is particularly important and critical. To this end, this project is going to design a non-contact interactive system based on the OpenCV library. This system will use an ordinary camera to detect the movement trajectory of items (hands) in the field of view and simply recognize the meaning expressed by the trajectory, such as circle, rectangle or triangle etc.. These signals composed of trajectory and motion meaning can be transferred to control computers. An example can be found in the following website:
https://www.youtube.com/watch?v=_pM_jOOnHog&t=6s
1. It supports to read images from a camera and then store the image, using APIs provided by OpenCV.
2. It supports to locate an object (by default, the hand is selected as the object), which is specified by users in the image. The functions of object detection can be implemented by students (you) or can be invoked from APIs of OpenCV. The location in the image space is generally represented by four numbers for a  <font color=#ff0000>rectangle</font> (top-left corner and down-right corner), which contains the object.
3. 	It supports to track the target which detected in the above step. The trace of the object in the image space is represented by a set of points, which are the centers of the rectangles. The trace of moving objects should be recorded and analyzed.
4. 	It supports to identify some specific meaning of trajectory, such as circle, rectangle or triangle etc..
5.	Using the above-mentioned detected trajectories (sets of points) and the identified trajectory meaning, students are required to further implement simple controlling functions, such as cursor movement, click or double clicks, etc. to show the validation of the above implemented operations.
