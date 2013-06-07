#include <iostream>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include "ImageLoader.h"

using namespace std;
using namespace cv;

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
	//string imageName = argv[1];
	//ImageLoader::showImage(imageName);

	waitKey(0);
	return 0;
}