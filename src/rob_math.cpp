#include "rob_math.h"


namespace MuYuRobotics 
{

// 二维变换实现
Point2D RoboticsMath::getAfterRotation2D(Point2D p0, Point2D T, double theta) {
    Point2D p_;
    double cosTheta = cos(theta);
    double sinTheta = sin(theta);
    p_.x = cosTheta * (p0.x - T.x) + sinTheta * (p0.y - T.y);
    p_.y = -sinTheta * (p0.x - T.x) + cosTheta * (p0.y - T.y);
    return p_;
}

Point2D RoboticsMath::getBeforeRotation2D(Point2D p_, Point2D T, double theta) {
    Point2D p0;
    double cosTheta = cos(theta);
    double sinTheta = sin(theta);
    p0.x = cosTheta * p_.x - sinTheta * p_.y + T.x;
    p0.y = sinTheta * p_.x + cosTheta * p_.y + T.y;
    return p0;
}

// 三维变换实现
Point3D RoboticsMath::getAfterRotation3D(Point3D p0, Point3D T, double theta, string axis) {
    Point3D p_ = {0, 0, 0};
    double R[3][3];
    double cosTheta = cos(theta);
    double sinTheta = sin(theta);

    if (axis == "X") {
        R[0][0] = 1;       R[0][1] = 0;         R[0][2] = 0;
        R[1][0] = 0;       R[1][1] = cosTheta;  R[1][2] = sinTheta;
        R[2][0] = 0;       R[2][1] = -sinTheta; R[2][2] = cosTheta;
    } else if (axis == "Y") {
        R[0][0] = cosTheta; R[0][1] = 0; R[0][2] = -sinTheta;
        R[1][0] = 0;        R[1][1] = 1; R[1][2] = 0;
        R[2][0] = sinTheta; R[2][1] = 0; R[2][2] = cosTheta;
    } else if (axis == "Z") {
        R[0][0] = cosTheta;  R[0][1] = sinTheta;  R[0][2] = 0;
        R[1][0] = -sinTheta; R[1][1] = cosTheta;  R[1][2] = 0;
        R[2][0] = 0;         R[2][1] = 0;         R[2][2] = 1;
    } else {
        std::cerr << "Invalid rotation axis" << std::endl;
        return p_;
    }

    p_.x = R[0][0] * (p0.x - T.x) + R[0][1] * (p0.y - T.y) + R[0][2] * (p0.z - T.z);
    p_.y = R[1][0] * (p0.x - T.x) + R[1][1] * (p0.y - T.y) + R[1][2] * (p0.z - T.z);
    p_.z = R[2][0] * (p0.x - T.x) + R[2][1] * (p0.y - T.y) + R[2][2] * (p0.z - T.z);
    return p_;
}

Point3D RoboticsMath::getBeforeRotation3D(Point3D p_, Point3D T, double theta, string axis) {
    Point3D p0 = {0, 0, 0};
    double R_[3][3];
    double cosTheta = cos(theta);
    double sinTheta = sin(theta);

    if (axis == "X") {
        R_[0][0] = 1;       R_[0][1] = 0;        R_[0][2] = 0;
        R_[1][0] = 0;       R_[1][1] = cosTheta; R_[1][2] = -sinTheta;
        R_[2][0] = 0;       R_[2][1] = sinTheta; R_[2][2] = cosTheta;
    } else if (axis == "Y") {
        R_[0][0] = cosTheta;  R_[0][1] = 0; R_[0][2] = sinTheta;
        R_[1][0] = 0;         R_[1][1] = 1; R_[1][2] = 0;
        R_[2][0] = -sinTheta; R_[2][1] = 0; R_[2][2] = cosTheta;
    } else if (axis == "Z") {
        R_[0][0] = cosTheta; R_[0][1] = -sinTheta; R_[0][2] = 0;
        R_[1][0] = sinTheta; R_[1][1] = cosTheta;  R_[1][2] = 0;
        R_[2][0] = 0;        R_[2][1] = 0;         R_[2][2] = 1;
    } else {
        std::cerr << "Invalid rotation axis" << std::endl;
        return p0;
    }

    p0.x = R_[0][0] * p_.x + R_[0][1] * p_.y + R_[0][2] * p_.z + T.x;
    p0.y = R_[1][0] * p_.x + R_[1][1] * p_.y + R_[1][2] * p_.z + T.y;
    p0.z = R_[2][0] * p_.x + R_[2][1] * p_.y + R_[2][2] * p_.z + T.z;

    return p0;
}

} // namespace MuYuRobotics