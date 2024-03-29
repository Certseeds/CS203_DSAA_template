<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-06-09 08:56:52
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-06-09 09:03:02
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

## CS205_C_CPP_Lab13

1. Design a stereo graphics class ( `CStereoShape` class), and meet the following requirements:

+ A virtual function `GetArea` , which can get the surface area of the stereo graphic, Here we let it print
  out `CStereoShape::GetArea()` and return a value of 0.0, which means that CStereoShape 's GetArea is called.
+ A virtual function `GetVolume` , which can get the volume of the stereo graphic, Here we let it print
  out `CStereoShape::GetVolume()` and return a value of 0.0, which means that CStereoShape 's GetVolume is called.
+ A virtual function`Show`, which print out the description of the stereo graphics. But here we let it print
  out `CStereoShape::Show()` , which means that Show of CStereoShape is invoked.;
+ A static private integer variable named `numberOfObject` , whose initial value is 0, which denotes the number of
  Stereo graphics generated by our program.
+ A method named `GetNumOfObject()` that returns the value of numberOfObject.
+ Add constructor functions based on requirement

2. Design a cube class ( `CCube` class), which inherits the CStereoShape class and meets the following requirements:

+ A no-arg constructor that creates a default Cube.
+ A constructor with parameters whose parameters correspond to the length, width, and height of the cube, respectively.
+ A copy constructor that creates a Cube object with the specified object of Cube .
+ Override `GetArea` 、`GetVolume` of the `CStereoShape` class to complete the calculation of the surface area and volume
  of the cube, respectively.
+ Override `Show()` of the `CStereoShape` class to print out the description (includes length, width, height, the
  surface area and volume )for the Cude object.

3. Design a sphere class ( `CSphere` ), which inherits from the StereoShape class and meets the following requirements:

+ A no-arg constructor that creates a default Sphere.
+ A constructor with parameters whose parameters correspond to the radius of thesphere.
+ A copy constructor that creates a `Sphere` object with the specified object of Sphere.
+ Override the GetArea and GetVolume of the CStereoShape class to complete thecalculation of the surface area and volume
  of the sphere, respectively.
+ Override `Show()` of the CStereoShape class to print out the description (includesradius, the surface area and
  volume )for the Sphere object.

4. Write a test program and complete at least the following tasks in the main functions:

+ Create a CCube object named **a_cube**, which the **length**, **width** and **height** are 4.0, 5.0, 6.0 respectively.
+ Create a CSphere object named **c_sphere**, which radius is 7.9.
+ Define the CStereoShape pointer **p**, point p to **a_cube**, and then print the information of **a_cube** to the
  terminal by **p**;
+ Point **p** to **c_sphere**, then print the information of **c_sphere** to the terminal by **p**.
+ Prints out the **number** of Stereo graphics created by the test program

+ Note that You may need to use the `setf ()` and `precision ()` formatting methods to set the output mode.
