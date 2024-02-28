#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat img = imread("joker.png", IMREAD_COLOR);
    
    if (img.empty()) {
        std:cerr << "failed to load image" << endl;
        return 1;
    }

    int inverse = 0;
    // width and height of the desired ascii text length
    int width = 40;
    int height = (img.rows * width) / img.cols;
    
    const char *charMap = "N@#W$9876543210?!abc;:+=-,._                  ";
    int charMapLen = strlen(charMap);
    
    Mat img2;
    resize(img, img2, Size(width, height), 0, 0, INTER_AREA);

    uchar *data = (uchar *)img2.ptr();
    int bytepp = img2.channels();
    for (int i=0; i<img2.rows; i++) {
        for (int j=0; j<img2.cols; j++) {
            int avg = 0;
            for (int k=0; k<bytepp; k++) {
                avg += data[i*img2.cols*bytepp + j*bytepp +k];
            }
            avg /= bytepp;
            int inx;
            if (inverse == 1) {
                inx = (avg * charMapLen) / 256;
            } else {
                inx = charMapLen - 1 - (avg * charMapLen)/256; 
            }
            cout << charMap[inx] << " ";
        }
        cout << endl;
    }

    // cout << img.type() << endl;
    // imshow("aaa", img2);

    // waitKey(0);
    return 0;
}