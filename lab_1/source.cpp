#include <opencv2/opencv.hpp>
using namespace cv;

int main() {

    int w = 786;
    int h =60;

    Mat image(Mat::zeros(h, w, CV_8U));
    Mat resultedImage(Size(w, 2 * h), CV_8U);
    for (int col = 0; col < w; ++col) {
        for (int row = 0; row < h; ++row) {
            image.at<uchar>(Point(col, row)) = col / 3;
        }
    }

    image.copyTo(resultedImage(Rect(0, 0, w, h)));
    image.convertTo(image, CV_64F, 1.0 / 256);
    cv::pow(image, 2.2, image);
    image.convertTo(image, CV_8U, 256);
    image.copyTo(resultedImage(Rect(0, h, w, h)));

    imshow("result1", resultedImage);

    //SECOND
    Mat image_2(Mat::zeros(h, w, CV_8U));
    Mat resultedImage_2(Size(w, 2 * h), CV_8U);
    for (int col = 0; col < w; ++col) {
        for (int row = 0; row < h; ++row) {
            image_2.at<uchar>(Point(col, row)) = 5 + col / 30*10;
        }
    }

    image_2.copyTo(resultedImage_2(Rect(0, 0, w, h)));
    image_2.convertTo(image_2, CV_64F, 1.0 / 256);
    cv::pow(image_2, 2.3, image_2);
    image_2.convertTo(image_2, CV_8U, 256);
    image_2.copyTo(resultedImage_2(Rect(0, h, w, h)));


    imshow("result2", resultedImage_2);

    Mat sm[2] = { resultedImage, resultedImage_2 };
    Mat saveResult;
    vconcat(sm, 2, save);
    imwrite("rlt.png", saveResult);
}


