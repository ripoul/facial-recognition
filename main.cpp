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
        return e;
    }
    return 0;
}