#include "myopencv.h"

float w = 250;
float h = 350;
Mat matrix;
Mat imgWarp;

void Chapter5::WarpPerspective() {
	string path = "resources/cards.jpg";
	Mat img = imread(path);

	// 错误示范，顶点必须一一对应
	// Point2f src[4] = { {530,142},{407,394},{673,455},{770,196} };
	// Point2f dst[4] = { {0.0f,0.0f},{0.0f,h},{w,0.0f},{w,h} };

	Point2f src[4] = { {530,142},{407,394},{673,455},{770,196} };
	Point2f dst[4] = { {0.0f,0.0f},{0.0f,h},{w,h} , {w,0.0f} };


	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));
	
	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	cout << img.size() << endl;
	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	waitKey();

}