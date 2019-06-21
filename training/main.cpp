#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string>
using namespace std;

int main(int argc, const char *argv[]){
    if (argc<2){
        cout << "usage: " << argv[0] << " <path/to/folder>" << endl;
        cout << "\t <path/to/folder> -- Path to the folder where to store the img" << endl;
        exit(1);
    }
    
    try{
        int cpt = 0;
        cv::VideoCapture videoOpenCv;
        bool test = videoOpenCv.open(0);
        if (test == false){
            throw - 101;
        }

        cv::CascadeClassifier face_cascade;
        if (!face_cascade.load("/usr/share/opencv/haarcascades/haarcascade_frontalface_alt2.xml")){
            throw - 103;
        }

        cv::Mat img;
        cv::Mat greyIMG;
        std::vector<cv::Rect> faces;
        cv::namedWindow("window2", cv::WINDOW_AUTOSIZE);
        while (true){

            videoOpenCv.read(img);
            cvtColor(img, greyIMG, CV_BGR2GRAY);
            cv::Size sizeRect(40, 40);
            face_cascade.detectMultiScale(greyIMG, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, sizeRect);

            try{
                CvRect r = faces.at(0);

                cv::Mat sub = cv::Mat(greyIMG, r);

                cv::imshow("window2", sub);
                int key = cv::waitKey(1000 / 25);
                if (key == (int)'q'){
                    string name = string(argv[1]) + "p" + std::to_string(cpt) + ".png";
                    cv::imwrite(name, sub);
                    cpt++;
                }
            }
            catch (const std::exception &e){
                //ne rien faire
            }
            if (cpt == 10){
                break;
            }
        }
    }
    catch (int e){
        fprintf(stderr, "There was an error in camera opening");
        return e;
    }
    return 0;
}
//https://answers.opencv.org/question/87261/extract-parts-from-image/