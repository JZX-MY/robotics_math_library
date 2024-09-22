#include "rob_math.h"

using namespace MuYuRobotics;
using namespace std;

int main() {


    // 二维测试
    cout << "二维测试: "<<endl;

    // 给定已知的原坐标系下的坐标 （如 世界坐标系下的坐标）
    Point2D P1_w = { -2.11988, 6.8836 };  // 假设点 p1 为机器人中心点
    Point2D P2_w = { -2.39382, 7.2443 };  // 假设点 p2 为机器人上某个传感器的中心点

    // 给定已知的旋转角度（弧度）和平移向量
    double theta = 2.22033;
    Point2D translation = { -2.11988, 6.8836 };

    Point2D P1_r = RoboticsMath::getAfterRotation(P1_w, translation, theta);
    Point2D P2_r = RoboticsMath::getAfterRotation(P2_w, translation, theta);

    // 输出求转换后 P1 和 P2 坐标
    cout << "P1 在新坐标系（机器人坐标系）下的坐标: (" << P1_r.x << ", " << P1_r.y << ")" << endl;
    cout << "P2 在新坐标系（机器人坐标系）下的坐标: (" << P2_r.x << ", " << P2_r.y << ")" << endl;

    Point2D P1_w2 = RoboticsMath::getBeforeRotation(P1_r, translation, theta);
    Point2D P2_w2 = RoboticsMath::getBeforeRotation(P2_r, translation, theta);

    // 输出求转换前 P1 和 P2 坐标
    cout << "P1 在原坐标系（世界坐标系）下的坐标: (" << P1_w2.x << ", " << P1_w2.y << ")" << endl;
    cout << "P2 在原坐标系（世界坐标系）下的坐标: (" << P2_w2.x << ", " << P2_w2.y << ")" << endl;


    // 三维测试
    cout << "三维测试: "<<endl;


    // 给定已知的原坐标系下的坐标 （如 世界坐标系下的坐标）
    Point3D P1_w = { -2.11988, 6.8836 ,0.3};  // 假设点 p1 为机器人中心点
    Point3D P2_w = { -2.39382, 7.2443 ,1.1};    // 假设点 p2 为机器人上某个传感器的中心点

    // 给定已知的旋转角度（弧度）和平移向量,以及旋转轴
    double theta = 2.22033;
    Point3D translation = { -2.11988, 6.8836 ,0.3};
    string axis = "Z";

    Point3D P1_r = RoboticsMath::getAfterRotation(P1_w, translation, theta, axis);
    Point3D P2_r = RoboticsMath::getAfterRotation(P2_w, translation, theta, axis);

    // 输出求转换后 P1 和 P2 坐标
    cout << "P1 在新坐标系（机器人坐标系）下的坐标: (" << P1_r.x << ", " << P1_r.y << ", " << P1_r.z << ")" << endl;
    cout << "P2 在新坐标系（机器人坐标系）下的坐标: (" << P2_r.x << ", " << P2_r.y << ", " << P2_r.z << ")" << endl;

    Point3D P1_w2 = RoboticsMath::getBeforeRotation(P1_r, translation, theta, axis);
    Point3D P2_w2 = RoboticsMath::getBeforeRotation(P2_r, translation, theta, axis);

    // 输出求转换前 P1 和 P2 坐标
    cout << "P1 在原坐标系（世界坐标系）下的坐标: (" << P1_w2.x << ", " << P1_w2.y << ", " << P1_w2.z << ")" << endl;
    cout << "P2 在原坐标系（世界坐标系）下的坐标: (" << P2_w2.x << ", " << P2_w2.y << ", " << P2_w2.z << ")" << endl;



    return 0;
}