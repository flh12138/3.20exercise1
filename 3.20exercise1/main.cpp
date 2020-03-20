#include <opencv.hpp>
using namespace cv;
using namespace std;


int main() 
{ 
	cv::Mat src = imread("E:\\PIC\\coin.png",0);
	cv::Mat binaryMat;
	cv::Mat dst1;
	cv::Mat dst2;
	cv::Mat dst3;
	cv::Mat dst4;
	cv::Mat dst5;
	cv::Mat dst6;
	cv::threshold(src, binaryMat, 0, 255, THRESH_OTSU);
	Mat getStructuringElement(int shape, Size ksize, Point anchor = Point(-1, -1));

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	//∏Ø ¥
	erode(binaryMat, dst1, kernel);
	
	//≈Ú’Õ
	dilate(binaryMat, dst2, kernel);

	//ø™‘ÀÀ„£¨œ»∏Ø ¥∫Û≈Ú’Õ
	erode(binaryMat, dst3, kernel);
	dilate(dst3, dst4, kernel);
	//±’‘ÀÀ„£¨œ»≈Ú’Õ∫Û∏Ø ¥
	dilate(binaryMat, dst5, kernel);
	erode(dst5, dst6, kernel);
	


	imshow("src", src);
	imshow("src1", binaryMat);
	imshow("src2", dst1);
	imshow("src3", dst2);
	imshow("dst4", dst4);
	imshow("dst6", dst6);
	waitKey(0);

}