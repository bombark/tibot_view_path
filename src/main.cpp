#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <tiobj.hpp>
#include <unistd.h>
#include <tiobj-cv.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;



int main(){
	TiObj params( getenv("params") );
	Mat map;
	map.create (512,512,CV_8UC3);
	map.setTo(255);

	string name = params.atStr("name");

	string buffer;
	while( cin.good() ){
		TiObj odom(true, "odom");

		int x = round( odom.atDbl("x")/10.0 + map.cols/2 );
		int y = round( map.rows/2 - odom.atDbl("y")/10.0 );
		map.at<Vec3b>(y,x) = Vec3b(255,0,0);

		imshow(name, map);
		waitKey(100);
	}


	return 0;
}
