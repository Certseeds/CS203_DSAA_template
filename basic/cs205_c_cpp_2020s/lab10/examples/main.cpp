/*
 * @Github: https://github.com/Certseeds

 * @Author: nanoseeds
 * @Date: 2021-06-22 23:37:32
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-06-22 23:48:18
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using cv::Mat;
using cv::imread;
using cv::imshow;
using cv::waitKey;
using std::cout;
using std::endl;

int main() {
    cout << "OpenCV Version: " << CV_VERSION << endl;
    //Mat img = imread("./../Pokemon02.png");
    Mat img = imread("./../../../lab10/examples/pictures/Pokemon02.png");
    if (img.empty()) {
        std::cout << "can not load image " << endl;
        return -1;
    }
    imshow("Pokemon", img);
    waitKey(0);
    return 0;
}
