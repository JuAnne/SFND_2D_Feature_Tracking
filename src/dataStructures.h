#ifndef dataStructures_h
#define dataStructures_h

#include <vector>
#include <opencv2/core.hpp>


struct DataFrame { // represents the available sensor information at the same time instance
    
    cv::Mat cameraImg; // camera image
    
    std::vector<cv::KeyPoint> keypoints; // 2D keypoints within camera image
    cv::Mat descriptors; // keypoint descriptors
    std::vector<cv::DMatch> kptMatches; // keypoint matches between previous and current frame
};

struct PerfEval { // performance evaluation for different combination
    std::string detectorType;           // SHITOMASI, HARRIS, FAST, BRISK, ORB, AKAZE, SIFT
    std::string descriptorType;         // BRISK, BRIEF, ORB, FREAK, AKAZE, SIFT
    std::string matcherType;            // MAT_BF, MAT_FLANN
    std::string selectorType;           // SEL_NN, SEL_KNN
    int numKeyPointsPerFrame[10];       // Count the number of keypoints for all 10 images
    int numKeyPointsPerROI[10];         // Count the number of keypoints on the preceding vehicle for all 10 images 
    int numKeyPointsMatched[10];        // Count the number of keypoints matched for all 10 images
    double timeKeyPointsDetection[10];  // Log the time it takes for keypoint detection
    double timeDescriptorExtraction[10];// Log the time it takes for descriptor extraction
    double timeMatching[10];            // Log the time it takes for matching
};

struct ReturnVal {
    int numPoints;
    double deltaTime;
};


#endif /* dataStructures_h */
