#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void drHist(Mat gray_image, int hist_size, string filename) {
    //
    array<int, 256> hist{ 0 };
    for (int j_row = 0; j_row < gray_image.rows; j_row++) {
        for (int i_col = 0; i_col < gray_image.cols; i_col++) {
            hist[gray_image.at<uint8_t>(j_row, i_col)] += 1; // -
        }
    }

    //     Y
    int max = 0;
    for (int i = 0; i < 256; i++)
    {
        if (max < hist[i])
        {
            max = hist[i];
        }
    }

    float y_scale = (1.0 * hist_size / max); //
    Mat histogram(hist_size, 256, CV_8UC1, Scalar(255, 0, 0));
    for (int x = 0; x < 256; x++) {
        line(histogram, Point(x, 0), Point(x, hist_size - y_scale * hist[x]), Scalar(10, 255, 255), 1); //,
    }

    imwrite(filename, histogram);
}

int brightless(int x){
    if (x <= 50) {
        return(5 * x);
    }
    if ((x > 50) && (x < 100)){
        return(-5 * (x - 50) + 250);
    }
    if (x >= 100){
        return(x - 100);
    }
}

int main()
{
    String path = "";
    Mat initialImage = imread(path + "source.jpg");
    Mat gray_image;
    cvtColor(initialImage, gray_image, COLOR_BGR2GRAY);

    Mat binary_mask;
    double alpha = 0.7; double beta = (1.0 - alpha);
    addWeighted(global_binarization_image, alpha, gray_image, beta, 0.0, binary_mask);
    imwrite(path + "localbin.png", binary_mask);

    waitKey(0);
    return 0;
}