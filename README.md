# tesseract_ocr_demo
一个识别中英、数字tesseract_ocr识别demo，加入了计时器便于统计   

## 文件结构说明  
　  
-chi_sim.traineddata         [中英文识别]　　  
-eng.traineddata　　　　[英文识别]　　  
-image                                      [待识别图片]　　  
-demo　　  

## 测试情况　  　　
识别时间非常快、　  
测了一个十位的数字，背景是白色的，时长0.06ｓ，准确率100％　　  
测试的英文较为准确　　  
测试的中文很不准确　　  

## demo使用方法　  　
１、安装tesseract  
２、安装opencv  
３、在tesseract目录下：　g++ ocr.cpp -o ocr `pkg-config --cflags --libs opencv` -llept -ltesseract   
４、将需要识别的图片放到tesseract目录下，命名为image替换掉当前图片  
５、shell 　执行：　./ocr  

