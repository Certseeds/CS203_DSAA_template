<!--
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-05-07 10:37:43
 * @LastEditTime: 2020-05-07 10:39:28
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->
## Recognizing faces using stm32 development board
I think you may have seen some wonderful movies in your childhood, which shows that machines are often used to recognize faces. Today, surprisingly, face recognition technology is mature enough to meet our daily needs. Now, you also have the opportunity to implement this machine yourself. In this project, programmers are required to design a face recognition security system based on the stm32 development board (provided by us) and OpenCV. You need to use a camera on the stm32 development board to capture faces. Then, you need to transfer the picture to a server and recognize the image. Finally, you need to make the machine react to the recognition results. The implementation details are as follows: 
1.  Use infrared sensors of stm32 to trigger the camera of stm32 to take pictures.
2.  Use WIFI module of stm32 to transmit the picture to a server.
3.  In server, a program implemented by yourself is used to receive the picture and a matching algorithm from API in OpenCV is used to match it to the pictures in a dataset containing more than 10 photos.
4.  If the face picture matches any photos in the dataset, you should transmit ‘success’ message to stm32 develop board and brighten up LED module of stm32 with a green light.
5.  If the face picture cannot match anyone in the dataset, you should transmit ‘fail’ message to stm32 develop board and brighten up LED module of stm32 with a red light.
