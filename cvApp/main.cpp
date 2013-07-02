#include <iostream>
#include <stdio.h>
#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\features2d\features2d.hpp>
#include <opencv2\nonfree\nonfree.hpp>
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

void featureDetectionSimpleMatching(string img, string img2) {
	Mat image1 = imread(img, CV_LOAD_IMAGE_GRAYSCALE);
	Mat image2 = imread(img2, CV_LOAD_IMAGE_GRAYSCALE);
	if (image1.empty() || image2.empty()) {
		cout << "Could not open or find one of the image files." << endl;
		return;
	}

	//detecting keypoints
	SurfFeatureDetector detector(1500);
	vector<KeyPoint> keypt1, keypt2;
	detector.detect(image1, keypt1);
	detector.detect(image2, keypt2);

	//compute descriptors
	SurfDescriptorExtractor extractor;
	Mat descriptor1, descriptor2;
	extractor.compute(image1, keypt1, descriptor1);
	extractor.compute(image2, keypt2, descriptor2);

	//matching descriptors
	BFMatcher matcher(NORM_L2);
	vector<DMatch> matches;
	matcher.match(descriptor1, descriptor2, matches);

	//drawing the results
	string window = "Matching Results";
	namedWindow(window, 1);
	Mat img_matches;
	drawMatches(image1, keypt1, image2, keypt2, matches, img_matches);
	imshow(window, img_matches);
}

void featureDetectionORB(string img, string img2) {
	Mat image1 = imread(img, CV_LOAD_IMAGE_GRAYSCALE);
	Mat image2 = imread(img2, CV_LOAD_IMAGE_GRAYSCALE);
	if (image1.empty() || image2.empty()) {
		cout << "Could not open or find one of the image files." << endl;
		return;
	}

	//detecting keypoints
	OrbFeatureDetector detector(40);
	vector<KeyPoint> keypt1, keypt2;
	detector.detect(image1, keypt1);
	detector.detect(image2, keypt2);

	//compute descriptors
	OrbDescriptorExtractor extractor;
	Mat descriptor1, descriptor2;
	extractor.compute(image1, keypt1, descriptor1);
	extractor.compute(image2, keypt2, descriptor2);

	//matching descriptors
	BFMatcher matcher(NORM_L2);
	vector<DMatch> matches;
	matcher.match(descriptor1, descriptor2, matches);

	//drawing the results
	string window = "Matching Results";
	namedWindow(window, 1);
	Mat img_matches;
	drawMatches(image1, keypt1, image2, keypt2, matches, img_matches);
	imshow(window, img_matches);
	imwrite("featureDetectionORB.jpg", img_matches);
}

void featureDetectionBRIEF(string img, string img2) {
	Mat image1 = imread(img, CV_LOAD_IMAGE_GRAYSCALE);
	Mat image2 = imread(img2, CV_LOAD_IMAGE_GRAYSCALE);
	if (image1.empty() || image2.empty()) {
		cout << "Could not open or find one of the image files." << endl;
		return;
	}

	//detecting keypoints
	OrbFeatureDetector detector(40);
	vector<KeyPoint> keypt1, keypt2;
	detector.detect(image1, keypt1);
	detector.detect(image2, keypt2);

	//compute descriptors
	BriefDescriptorExtractor extractor;
	Mat descriptor1, descriptor2;
	extractor.compute(image1, keypt1, descriptor1);
	extractor.compute(image2, keypt2, descriptor2);

	//matching descriptors
	BFMatcher matcher(NORM_L2);
	vector<DMatch> matches;
	matcher.match(descriptor1, descriptor2, matches);

	//drawing the results
	string window = "Matching Results";
	namedWindow(window, 1);
	Mat img_matches;
	drawMatches(image1, keypt1, image2, keypt2, matches, img_matches);
	imshow(window, img_matches);
	imwrite("featureDetectionBRIEF.jpg", img_matches);
}

int main(int argc, char* argv[]) 
{
	string sample = argv[1];
	int option = atoi(sample.c_str());
	string img = argv[2];
	string img2;
	switch (option)
	{
		case 1:
			img2 = argv[3];
			featureDetectionSimpleMatching(img, img2);
			break;
		case 2:
			img2 = argv[3];
			featureDetectionORB(img, img2);
			break;
		case 3:
			img2 = argv[3];
			featureDetectionBRIEF(img, img2);
			break;
		default:
			loadImage(img);
			break;
	}

	waitKey(0);
	return 0;
}