#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
    try
    {
        int cpt = 0;
        cv::VideoCapture videoOpenCv;
        bool test=videoOpenCv.open(0);
        if(test==false){
            throw -101;
        }
        cv::Mat img;
        cv::Mat greyIMG;
        cv::namedWindow("window2", cv::WINDOW_AUTOSIZE);
        while(true){
            
            videoOpenCv.read(img);
            cvtColor(img,greyIMG,CV_BGR2GRAY);
            cv::imshow("window2", greyIMG);
            int key = cv::waitKey(1000/25);
            if(key==(int)'q'){
                string name = "p"+std::to_string(cpt)+".png";
                cv::imwrite(name, greyIMG);
                cpt++;
            }
            if (cpt==10){
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
//https://answers.opencv.org/question/87261/extract-parts-from-image/