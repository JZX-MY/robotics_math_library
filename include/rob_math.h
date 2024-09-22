#ifndef ROB_MATH_H
#define ROB_MATH_H

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

namespace MuYuRobotics {

// 定义二维点类型
struct Point2D { double x, y;};

// 定义三维点类型
struct Point3D { double x, y, z;};

// 类定义
class RoboticsMath {
public:
    // 二维坐标变换函数
    static Point2D getAfterRotation2D(Point2D p0, Point2D T, double theta);
    static Point2D getBeforeRotation2D(Point2D p_, Point2D T, double theta);

    // 三维坐标变换函数
    static Point3D getAfterRotation3D(Point3D p0, Point3D T, double theta, string axis);
    static Point3D getBeforeRotation3D(Point3D p_, Point3D T, double theta, string axis);
};

} // namespace MuYuRobotics

#endif
