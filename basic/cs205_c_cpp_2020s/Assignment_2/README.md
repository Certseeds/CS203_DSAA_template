<!--
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-06-07 09:55:44
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-06-21 20:23:44
 * @License: CC-BY-NC-SA_V4_0 or any later version
 -->

# CS205 – Lab Assignment 2

You will in this lab build on what was done in Lab 1 (computation of distances) and write a program that is easier to
use. This program isn't very simple if written well and you'll have several weeks to write it.

此assignment基于assignment-1,要写完善需要不少时间.

As entering latitude and longitude is boring, you are provided with a text file that contains this information for many
cities in the world (You can add your hometown if you wish). This file is named world_cities.csv and contains one line
per city with the following information:

直接输入纬度和经度很无聊,所以会提供一个`world_cities.csv`，包含许多城市，每个城市占一行，其中包含以下信息：

+ City name
+ Province or state (may be absent)
+ Country
+ Latitude
+ Longitude

Example:

`Acapulco,Guerrero,Mexico,16.867,-99.883` =>

| City Name |  State   | Country | Latitude | Longitude |
| :-------: | :------: | :-----: | :------: | :-------: |
| Acapulco  | Guerrero | Mexico  |  16.867  |  -99.883  |

These values are separated by commas (.csv means "Comma Separated Values", it's a commonly used format for exchanging
data). When a piece of data is missing (province or state), you get two commas in succession, for instance (first row in
the file):

这些值由逗号分隔. 当丢失一条数据(省或州)时，您连续获取两次逗号，例如文件中的第一行：

`Aarhus,,Denmark,56.150,10.217`

The cities are in alphabetical order. 城市按字母顺序排列

## Part 1

> All constant values must be set as #define so that they can be easily changed.
> 常量应该被#define

We aren't in this lab interested in the "province or state" information. You are asked to define a structure to hold
city and country name, latitude and longitude.

我们不在本实验室对"省或州"信息感兴趣. 您被要求定义一个`struct`，以持有城市和国家/地区名称，纬度和经度.

You must create an array containing structures as you have defined them, read the file, and load data into the array.

您必须在定义它们时创建一个包含结构的数组，读取文件并将数据加载到数组中.

1. Initially set the maximum length for names (city and country name) to 25, and the array size to 800. Your program
   should issue a warning when data is truncated or not loaded, but it mustn't crash.

2. Set the maximum length for names to 35, and the array size to 1000. Check that your program runs without any problem.

3. Rename the file to world_cities.tmp. Run your program. It mustn't crash and should display a warning about the
   missing file. 4. Rename the file to world_cities.csv and continue with part 2.

1. 最初将名称(城市和国家/地区名称)的最大长度设置为25，数组大小为800.您的程序应在截断或未加载数据时发出警告，但不能崩溃.

2. 将名称的最大长度设置为35，数组大小为1000.检查您的程序是否运行而没有任何问题.

3. 将文件重命名为`world_cities.tmp` 运行您的程序. 它不能崩溃，应该显示有关丢失文件的警告.

4. 将文件重命名为world_cities.csv并继续第2部分.

## Part 2

Once all data is loaded, your program should enter a loop from which it will exit when the user types "bye" (
case-insensitive). For each iteration, it will prompt for the names of two cities.

The program must search the cities in the table by their names and retrieve the latitudes and longitudes. If the city
isn't found or if the length of the name is shorter than three letters, a message must be displayed and the user must be
prompted for another name. The city names should be case-insensitive.

Please note that in the file New York appears as "New York City". If people type "New York", then "New York City" must
be retrieved. However, if users only type "New" (minimum acceptable length), it can match several cities. The list of
the matched cities must be displayed, and the user prompted for the right one.

Finally, the names of the cities (as stored in the memory) and the distance between them must be displayed.

As before, your program should ignore all whitespaces on both ends of user inputs.

加载所有数据后，您的程序应进入循环，当用户输入"BYE"不区分大小写时，退出。对于每次迭代，它将提示两个城市的名称。

通过输入的名称搜索表中的城市并检索纬度和纵向。如果找不到城市或者名称的长度短于三个字母，则显示一条消息，并且提示用户输入另一个名称。城市名称应该是大小写不敏感的。

请注意，在文件中，纽约出现为"纽约市"。如果人们键入"纽约"，那么必须检索"纽约市"。但是，如果用户只键入"新"（最小可接受的长度），则可以匹配几个城市。必须显示匹配的城市列表，用户提示正确的城市。

最后，必须显示城市的名称（存储在存储器中）和它们之间的距离。

如前所述，您的程序应忽略用户输入两端的所有空格。