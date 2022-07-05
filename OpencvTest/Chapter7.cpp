#include "myopencv.h"

void Chapter7::getContours(Mat imgDil, Mat img) {
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	for (int i = 0; i < contours.size(); i++) {
		// 计算图形面积，方便过滤较小的噪声图形（无用的图形）
		int area = contourArea(contours[i]);
		cout << area << endl;


		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size());
		string objectType;

		if (area > 1000) {
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);

			int objCor = (int)conPoly[i].size();

			if (objCor == 3)
				objectType = "Tri";
			else if (objCor == 4) {
				// 判断是不是正方形
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				if (aspRatio > 0.95 && aspRatio < 1.05) {
					objectType = "Square";
				}
				else
				{
					objectType = "Rect";
				}
			}
			else
				objectType = "Circle";


			// 其中i<0或是为FILLED，那么所有的图形都会被标记
			// drawContours(img, contours, i, Scalar(255, 0, 255), 2);
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 255), 2);
			putText(img, objectType, { boundRect[i].x, boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255), 1);
		}
	}
}


void Chapter7::ShapeDetection() {
	string path = "resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray;
	Mat imgBlur;
	Mat imgCanny;
	Mat imgDil;

	// 预处理
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(3,3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil, img);

	imshow("Image", img);
	/*imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDil);*/
	waitKey(0);
}