#include <iostream>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // win32
#include <time.h>

#define BLACK CV_RGB(0,0,0)

#include <opencv2/opencv.hpp>
void sleepcp(int milliseconds) // cross-platform sleep function
{
#ifdef WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif // win32
}

int calculationFPS(time_t *start, int count)
{
    int ret = count;
    if(count==100)
    {
        double seconds = 1;
        double fps = 0;
        time_t end;

        time(&end);
        seconds = difftime(end,*start);
        fps = count/seconds;
        std::cout << "\033[031;1mFrames per seconds : " << fps << "\033[0m" << std::endl;
        sleepcp(300);

        time(start);

        ret = 0;
    }
    return ret;
}

int main()
{
        try
        {
            //reconnaissance des visages

            cv::VideoCapture videoOpenCv;
            bool test = videoOpenCv.open(0);
            if(test==false)
            {
                throw -101;
            }

            cv::CascadeClassifier face_cascade;

            if(!face_cascade.load("/usr/share/opencv/haarcascades/haarcascade_frontalface_alt2.xml"))
            {
                throw -103;
            }
            cv::Mat img;


            videoOpenCv.read(img);

            std::vector<cv::Rect> faces;
            std::vector<cv::Scalar> colors;
            std::vector<std::string> names;

            cv::Size sizeRect(40, 40);

            face_cascade.detectMultiScale(img, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, sizeRect);
            for( size_t i = 0; i < faces.size(); i++ )
            {
                colors.push_back(BLACK);
                names.push_back("Human being");
            }

            for( size_t i = 0; i < faces.size(); i++ )
            {
                CvRect r = faces.at(i);
                rectangle(img, cvPoint( r.x, r.y ), cvPoint( r.x + r.width, r.y + r.height ), colors.at(i), 1, 8, 0);
                putText(img,names.at(i), cvPoint(r.x + r.width + 10, r.y + r.height + 10), cv::FONT_HERSHEY_PLAIN, 1.0, colors.at(i), 2.0);
            }

            cv::namedWindow("Window3", cv::WINDOW_AUTOSIZE);

            while(true)
            {
                cv::imshow("Window3", img);
                int key = cv::waitKey(1000/25);
                if(key==(int)'q')
                {
                    break;
                }
            }
        }
        catch(int e)
        {
                return e;
        }

        return 0;
}

