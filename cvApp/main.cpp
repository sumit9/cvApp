#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include "ImageLoader.h"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) 
{
	string imageName = argv[1];
	ImageLoader::showImage(imageName);

	waitKey(0);
	return 0;
}