#include "myopencv.h"

/*   显示图片   */
void Chapter1::ShowImage() {
	// 设置图片路径
	string path = "resources/test.png";
	// 将图像读进来，数据类型为Mat（矩阵的缩写）
	Mat img = imread(path);
	// 显示图片
	imshow("Image", img);

	// 设置延迟，否则的话会显示图像后立即退出(0代表无限，单位是毫秒)
	waitKey(0);
}

/*   显示视频   */
void Chapter1::ShowVideo() {

	string path = "resources/test_video.mp4";

	// 获取视频帧
	VideoCapture cap(path);
	Mat img;

	// 图像的显示需要对每一帧图像捕获并显示
	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(20);
	}
}

/*   显示摄像头视频   */
void Chapter1::ShowWebcam() {

	// 获取视频帧
	VideoCapture cap(0);
	Mat img;

	// 图像的显示需要对每一帧图像捕获并显示
	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(1);
	}
}
