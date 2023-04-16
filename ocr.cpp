#include <string>
#include <fstream>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/opencv.hpp>
 #include<ctime>
using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
    string outText;
    string imPath = "image.png";

    clock_t startTime,endTime;
    startTime = clock();//计时开始

    // Create Tesseract object
    tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();

    // 中英文识别
    // ocr->Init("./tessdata", "chi_sim", tesseract::OEM_LSTM_ONLY);

   // 英文识别
    ocr->Init("./tessdata", "eng", tesseract::OEM_LSTM_ONLY);

    // 设置页面分割模式为PSM_AUTO (3)
    ocr->SetPageSegMode(tesseract::PSM_AUTO);

    // 用OpenCV打开输入图像
    Mat im = cv::imread(imPath, IMREAD_COLOR);

    //将图像转换为灰度
    cvtColor(im, im, COLOR_BGR2GRAY);

    //应用高斯模糊法来减少噪点
    GaussianBlur(im, im, Size(3, 3), 0);

    // 对图像进行阈值处理以提高对比度
    threshold(im, im, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // 设置图像数据
    ocr->SetImage(im.data, im.cols, im.rows, 1, im.step);

    // 在图像上运行Tesseract OCR
    outText = string(ocr->GetUTF8Text());

    endTime = clock();//计时结束

    std::ofstream fout("result.txt", std::ios::out);
    fout << outText;
    fout.close();
    cout << "The run time is:" <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    // Destroy used object and release memory
    ocr->End();

    return EXIT_SUCCESS;
}