#include "ImageLoader.h"
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;

ImageLoader::ImageLoader(void)
{
}


ImageLoader::~ImageLoader(void)
{
}

void ImageLoader::showImage(string imageName) {
	Mat image = imread(imageName);
	if (!image.data) {
		cout << "Could not open or find the image file." << endl;
	}

	namedWindow(imageName, CV_LOAD_IMAGE_COLOR);
	imshow(imageName, image);

	return;
}
