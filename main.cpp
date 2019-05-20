#include <opencv2/opencv.hpp>

int main(){
    try
    {
        cv::VideoCapture videoOpenCv;
        bool test=videoOpenCv.open(0);
        if(test==false){
            throw -101;
        }
    }
    catch(int e)
    {
        fprintf(stderr, "There was an error in camera opening");
        return e;
    }
    return 0;
}