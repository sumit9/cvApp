#include <iostream>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include "ImageLoader.h"

using namespace std;
using namespace cv;

void loadImage(string imageName) {
	ImageLoader::showImage(imageName);
}

int captureImageFromWebcam() {
	VideoCapture cap(0);
	if (!cap.isOpened()) {
		return -1;
	}

	Mat image;
	namedWindow("Edges", 1);
	while(1) {
		cap >> image;
		imshow("Frames", image);
		waitKey(33);
	}
}

int main(int argc, char* argv[]) 
{
	string sample = argv[1];
	int option = atoi(sample.c_str());
	switch (option)
	{
		case 1: 
			break;
		default:
			string imageName = argv[2];
			loadImage(imageName);
			break;
	}

	waitKey(0);
	return 0;
}