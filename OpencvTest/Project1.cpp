#pragma once
#include "myopencv.h"

// int hmin = 0, smin = 0, vmin = 0;
// int hmax = 179, smax = 255, vmax = 255;

VideoCapture cap(0);
Mat img;
vector<vector<int>> newPoints;


vector<vector<int>> myColors{
	// {-1166, 106, 36, 179, 240, 161},// 红色
	// {-118, 162, 165, 23, 210, 215}  // 黄色
	{124,48,117,143,170,255}, // Purple
	{68,72,156,102,126,255}   // Green
};

vector<Scalar> myColorValues{
	// {0, 0, 255},     // 红色
	// {0, 255, 255}    // 黄色
	{255,0,255}, // Purple
	{0,255,0}    // Green
};

Point getContours(Mat image) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	Point myPoint(0, 0);

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl;

		string objectType;

		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);
			myPoint.x = boundRect[i].x + boundRect[i].width / 2;
			myPoint.y = boundRect[i].y;

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
		}
	}
	return myPoint;
}

vector<vector<int>> findColor(Mat image) {

	Mat imgHSV, Mask;

	cvtColor(image, imgHSV, COLOR_BGR2HSV);

	for (int i = 0; i < myColors.size(); i++) {
		Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
		Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
		inRange(imgHSV, lower, upper, Mask);

		// imshow(to_string(i), Mask);
		Point myPoint = getContours(Mask);
		if (myPoint.x != 0 && myPoint.y != 0) {
			newPoints.push_back({ myPoint.x, myPoint.y, i });
		}
	}
	return newPoints;
}

void drawOnCanvas(vector<vector<int>> newPoints, vector<Scalar> myColorValues) {
	for (int i = 0; i < newPoints.size(); i++) {
		circle(img, Point(newPoints[i][0], newPoints[i][1]), 10, myColorValues[newPoints[i][2]], FILLED);
	}
}


int main() {
	
	while (true) {
		cap.read(img);

		newPoints = findColor(img);

		drawOnCanvas(newPoints, myColorValues);


		imshow("Webcap", img);
		waitKey(1);
	}



	return 0;
}
