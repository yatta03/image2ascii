#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat img = imread("joker.png", IMREAD_COLOR);
    Mat img2 = img.clone();
    
    for (int i=0; i<img.rows; i++) {
        uchar *data = img.ptr(i);
        for (int j=0; j<img.cols; j++) {

        }
    }

    imshow("aaa", img2);

    waitKey(0);
    return 0;
}