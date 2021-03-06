#include <opencv2/opencv.hpp>
#include <stdio.h>

int main(){
    try
    {
        cv::VideoCapture videoOpenCv;
        bool test=videoOpenCv.open(0);
        if(test==false){
            throw -101;
        }
        cv::Mat img;
        cv::namedWindow("window2", cv::WINDOW_AUTOSIZE);
        while(true){
            videoOpenCv.read(img);
            cv::imshow("window2", img);
            int key = cv::waitKey(1000/25);
            if(key==(int)'q'){
                cv::imwrite("test.png", img);
                break;
            }
        }
    }
    catch(int e)
    {
        fprintf(stderr, "There was an error in camera opening");
        return e;
    }
    return 0;
}