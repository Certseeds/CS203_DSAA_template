#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	complex temp(1, 2);
	cout << temp.real() << endl;
	cout << temp.imag() << endl;
	Mat mat1 = Mat(3, 4, CV_8U);
	for (int i = 0; i < mat1.rows; ++i) {
		for (int j = 0; j < mat1.cols; ++j) {
			mat1.at<uchar>(i, j) = (i + 1)*(j + 1);
		}
	}
	cout << mat1 << endl;
	auto temp_10 = mat1.data;
	auto temp_11 = *mat1.data;
	vector<uchar> temp_vec(mat1.rows*mat1.cols);
	int count = 0;
	for (auto &i : temp_vec) {
		i = mat1.data[count];
		count++;
	}
	cout << static_cast<uchar *>(mat1.data) << endl;
	cout << *mat1.data << endl;
	Mat mat2 = Mat(3, 4, CV_8U);
	Mat mat3 = Mat::zeros(3, 4, CV_8U);
	Mat mat4 = Mat::ones(3, 4, CV_8U);
	Mat mat5 = Mat::ones(3, 5, CV_8UC2);
	for (int i = 0; i < mat5.rows; ++i) {
		for (int j = 0; j < mat5.cols; ++j) {
			mat5.at<cv::Vec2b>(i, j) = {99, 81};
		}
	}
	cout << " mat 5 " << mat5 << endl;
	cout << mat1 << endl;
	cout << mat2 << endl;
	cout << mat3 << endl;
	cout << mat4 << endl;
	cout << mat4.rows;
	cout << mat4.cols;
	cout << mat5.cols << " " << mat5.rows << "\n";
	double temp3 = 3.0f;
	cout << std::complex<double>(2.0f, 3.0f)/temp3 << "\n";
	cout << std::complex<int32_t>(2, 3)*3 << "\n";
	cout << mat1.type() << "\n";
	cout << mat5.type() << "\n";
	cout << mat5.depth();
	return 0;
}