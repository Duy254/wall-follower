#ifndef CRICLE_DETECTOR_H
#define CRICLE_DETECTOR_H

#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

/**
 * @brief Define the Circle class which 
 * takes the coordinates of the points.
 * @
 * 
 */
class Circle{
public:
    /**
     *  x is the x coordinate of the point 
     *  relative to the laser range scanner
     *  y is the y coordinate of the point
     *  relative to the laser range scanner
     */
    float x, y;
};

/**
 * @brief Defines the CircleDetector class
 * which will help checking if a circle is found or not.
 * @details The results from the laser range scanner 
 * are used to check if the obstacle that is seen is 
 * in fact a circle.
 * Also, it returns information about the position of the circle
 * which is helpful in detecting it. 
 * 
 */
class CircleDetector {
private:
/**
 * @brief The class has as parameters the following:
 */
    /*
    @ brief The node that was created.
     */

    ros::NodeHandle node_;
    /*
     @ brief The laser_sub subscribes the node that is seen 
     to the laser range finder.
    */

    ros::Subscriber laser_sub_;
    /*
     * @brief The circle is the actual circle that the scanner
        has found.
     */

    Circle circle_;

    /*
     * @brief  The count_threshold takes care of the 
       thresholds that were encountered by the laser range
       scanner so far.
     */
    int count_threshold_;

public:

    CircleDetector();

    /**
    * Gets the data from the laser range finder, creates an
    * image out of it and runs openCV HoughLines on it
    * 
    * @param msg Raw data comming from the laser range finder
    */
    void LaserCallback(const sensor_msgs::LaserScan::ConstPtr& msg);

    /**
     * Returns the detected circle
     * @return -1, -1 if no circle is detected at the moment, the coordinates
     * of the circle otherwise
     */
    Circle get_circle();
};


#endif