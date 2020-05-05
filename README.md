# SFND 2D Feature Tracking

<img src="images/keypoints.png" width="820" height="248" />

The idea of the camera course is to build a collision detection system - that's the overall goal for the Final Project. As a preparation for this, you will now build the feature tracking part and test various detector / descriptor combinations to see which ones perform best. This mid-term project consists of four parts:

* First, you will focus on loading images, setting up data structures and putting everything into a ring buffer to optimize memory load. 
* Then, you will integrate several keypoint detectors such as HARRIS, FAST, BRISK and SIFT and compare them with regard to number of keypoints and speed. 
* In the next part, you will then focus on descriptor extraction and matching using brute force and also the FLANN approach we discussed in the previous lesson. 
* In the last part, once the code framework is complete, you will test the various algorithms in different combinations and compare them with regard to some performance measures. 

See the classroom instruction and code comments for more details on each of these parts. Once you are finished with this project, the keypoint matching part will be set up and you can proceed to the next lesson, where the focus is on integrating Lidar points and on object detection using deep-learning. 

## Dependencies for Running Locally
* cmake >= 2.8
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* OpenCV >= 4.1
  * This must be compiled from source using the `-D OPENCV_ENABLE_NONFREE=ON` cmake flag for testing the SIFT and SURF detectors.
  * The OpenCV 4.1.0 source code can be found [here](https://github.com/opencv/opencv/tree/4.1.0)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./2D_feature_tracking`.

## Rubric

1. Data Buffer Optimization: Implement a vector for dataBuffer objects whose size does not exceed a limit (e.g. 2 elements). 
```shell
Implemented a ring buffer of size dataBufferSize = 2. 
Push new image to the buffer when the ring buffer size is less than dataBufferSize.
Erase the oldest image and push new iamge to the buffer when the ring buffer size is equal to or greater than dataBufferSize.

```

2. Keypoint Detection: Implement detectors HARRIS, FAST, BRISK, ORB, AKAZE, and SIFT and make them selectable by setting a string accordingly.
```shell
Implemented a string list for selectable key point detector type:
{ "SHITOMASI", "HARRIS", "FAST", "BRISK", "ORB", "AKAZE", "SIFT"}
 
Implemented 3 functions for keypoint detection:
* detKeypointsShiTomasi()  // selected by "SHITOMASI"
* detKeypointsHarris() // selected by "HARRIS"
* detKeypointsModern() // selected by "FAST", "BRISK", "ORB", "AKAZE", "SIFT"
```

3. Keypoint Removal: Remove all keypoints outside of a pre-defined rectangle and only use the keypoints within the rectangle for further processing.
```shell
Loop through all the keypoints and check each point against a pre-defined rectangle, then save the points with the rectangle to a new keypoints list kpts_roi.
```

4. Keypoint Descriptors: Implement descriptors BRIEF, ORB, FREAK, AKAZE and SIFT and make them selectable by setting a string accordingly.
```shell
Implemented a string list for selectable descriptors type:
{ "BRISK", "BRIEF", "ORB", "FREAK", "AKAZE", "SIFT"}

Implemented function descKeypoints() for descriptor extraction based on different types.
```

5. Descriptor Matching: Implement FLANN matching as well as k-nearest neighbor selection. Both methods must be selectable using the respective strings in the main function.
```shell
Implemented function matchDescriptors() to find the best matches for keypoints in two camera images based on several matching methods.

Inside function matchDescriptors(), implemented a FLANN matcher based on matcher type being "MAT_FLANN".

Inside function matchDescriptors(), implemented a knn matcher based on selector type being "SEL_KNN".
```

6. Descriptor Distance Ratio: Use the K-Nearest-Neighbor matching to implement the descriptor distance ratio test, which looks at the ratio of best vs. second-best match to decide whether to keep an associated pair of keypoints.
```shell
Inside function matchDescriptors(), implemented a knn matcher based on selector type being "SEL_KNN", also filtered out keypoints for matching based on descriptor distance ratio of 0.8.
```

7. Performance Evaluation 1: Count the number of keypoints on the preceding vehicle for all 10 images and take note of the distribution of their neighborhood size. Do this for all the detectors you have implemented.

| Detector | Total number KptsPerROI |
| --- | --- |
| **SHITOMASI** | 1179 |
| **HARRIS** | 248 |
| **FAST** | 1491 |
| **BRISK** | 2762 |
| **ORB** | 1161 |
| **AKAZE** | 1670 |
| **SIFT** | 1387|


8. Performance Evaluation 2: Count the number of matched keypoints for all 10 images using all possible combinations of detectors and descriptors. In the matching step, the BF approach is used with the descriptor distance ratio set to 0.8.

| Detector\Descriptor | BRISK | BRIEF | ORB | FREAK | AKAZE | SIFT |
| --- | --- | --- |--- |--- |--- |--- |
| **SHITOMASI** | 767 | 944 | 908 | 768 | N/A | N/A |
| **HARRIS** | 142 | 173 | 162 | 144 | N/A | N/A |
| **FAST** | 899 | 1099 | 1071 | 878 | N/A | N/A |
| **BRISK** | 1570 | 1704 | 1514 | 1524 | N/A | N/A |
| **ORB** | 751 | 545 | 763 | 420 | N/A | N/A |
| **AKAZE** | 1215 | 1266 | 1182 | 1187 | 1259 | N/A |
| **SIFT** | 594 | 704 | N/A | 595 | N/A | N/A |


9. Performance Evaluation 3: Log the time it takes for keypoint detection and descriptor extraction. The results must be entered into a spreadsheet and based on this data, the TOP3 detector / descriptor combinations must be recommended as the best choice for our purpose of detecting keypoints on vehicles.

Average processing time of detector and descriptor in ms on all 10 images
| Detector\Descriptor | BRISK | BRIEF | ORB | FREAK | AKAZE | SIFT |
| --- | --- | --- |--- |--- |--- |--- |
| **SHITOMASI** | 366.47 | 18.79 | 20.62 | 58.39 | N/A | N/A |
| **HARRIS** | 353.28 | 17.60 | 19.63 | 57.97 | N/A | N/A |
| **FAST** | 339.73 | 1.78 | 2.01 | 44.96 | N/A | N/A |
| **BRISK** | 721.36 | 379.70 | 382.57 | 423.75 | N/A| N/A|
| **ORB** | 347.59 | 9.84 | 12.59 | 51.20 | N/A | N/A |
| **AKAZE** | 413.98 | 81.53 | 82.01 | 122.15 | 148.84 | N/A |
| **SIFT** | 447.81 | 136.07 |N/A| 173.41 |N/A|N/A|

TOP3 detector / descriptor combinations are
* FAST + BRIEF : 1.78 ms
* FAST + ORB : 2.01 ms
* ORB + BRIEF : 9.84 ms


## Report reference



