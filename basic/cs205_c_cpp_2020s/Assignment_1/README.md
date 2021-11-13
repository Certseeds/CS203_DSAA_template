<!--
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-06-07 10:00:06
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-06-20 11:24:49
 * @License: CC-BY-NC-SA_V4_0 or any later version 
 -->

# CS205 C/ C++ Programming - Assignment 1

You are asked to write a simple program that, as you will see, may not be as simple to write in C as it looks if you
want to write robust programs. It will allow you to learn about basic input/output.

This program must prompt the user for the name of a first city, then its latitude and longitude, then for the name of a
second city with its latitude and longitude, then compute the flying distance between the two and display. For example,
> The first city: Shenzhen
> The latitude and longitude of first city: 22.55 114.1
> The second city: Beijing
> The latitude and longitude of second city: 39.9139 116.3917
> The distance between Shenzhen and Beijing is \<result\> km

"The first city:" , "The latitude and longitude of second city",The second city:" and "The latitude and longitude of
second city:" are prompt information.

Your program should print prompt information to tell user enter the information of city. User will enter city name
first (in the first line). Then user enters two floating numbers : latitude and longitude of city(in the second line).If
user's input format is not correct. Your program should not crash and tell user the format is incorrect and exit.
\<result\> is the distance calculated by your program.

Here is the formula for computing the distance (adapted from mathforum.org, provided by Doctor Rob):

Assume the Earth is a perfect sphere. Let all angles be measured in signed degrees (negative latitude means South;
negative longitude means West).

$$phi = 90 - latitude$$

The North Pole has phi = 0, the South Pole has phi = 180, and 0 <= phi <= 180.

$$theta = longitude$$

Greenwich, England, has theta = 0, and -180 <= theta <= 180. Let the angles for the two points be (phi1, theta1) and (
phi2, theta2). Then compute

$$c = sin(phi1) * sin(phi2) * cos(theta1-theta2) +cos(phi1) * cos(phi2)$$ $$Note: phi and theta should be in radians.$$

Then the shortest great circle distance between the two points is $$d = R*arccos(c)$$

where R is the radius of the earth in kilometers, and the arccosine is taken between 0 and 180 degrees, inclusive. Earth
radius: 6,371 km Some cities for testing:

|          city          | latitude | longitude  |
| :--------------------: | :------: | :--------: |
|        Shenzhen        |  22.55   |   114.1    |
|        Beijing         | 39.9139  |  116.3917  |
|     New York, USA      | 40.7127  |  -74.0059  |
|   San Francisco, USA   | 37.7833  | -122.4167  |
|       London, UK       | 51.5072  |  -0.1275   |
|     Paris, France      | 48.8567  |   2.3508   |
|     Kolkata, India     |  22.567  |   88.367   |
|     Moscow, Russia     | 55.7500  |  37.6167   |
| Rio de Janeiro, Brazil | -22.9083 |  -43.1964  |
|   Sydney, Australia    | -33.865  | 151.209444 |

For checking out if your results are roughly correct:

http://www.webflyer.com/travel/mileage_calculator/

**Note: you must input the city name in English, and the city name should not appear unreasonable symbols, such as @, ￥,
%, etc**