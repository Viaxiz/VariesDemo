#include<iostream>
#include<vector>
#include<math.h>

using std::vector;

class Point
{
private:
    /* data */
    double x; //x坐标
    double y; //y坐标
public:
    Point(int x,int y);

    friend double Show_x(Point p) {return p.x;}
    friend double Show_y(Point p) {return p.y;}

    //TODO
    friend bool operator ==(Point &p1,Point &p2);               //重载==运算符 
    friend Point operator +(Point &p1,Point &p2);               //重载+运算符 
    friend Point operator -(Point &p1,Point &p2);               //重载-运算符 
    friend double Dot(Point p1,Point p2);                       //两个向量的点积 
    friend double Length(Point &p);                             //求向量长度
    friend int Angle(Point p0,Point p1,Point p2);               //求两线段p0p1和p0p2的夹角
    friend double Det(Point p1,Point p2);                       //两个向量的叉积 
    friend int Direction(Point p0,Point p1,Point p2);           //判断两线段p0p1和p0p2的方向
    friend double Distance(Point p1,Point p2);                  //求两个点的距离 
    friend double DistPtoSegment(Point p0,Point p1,Point p2);   //求p0到p1p2线段的距离
    friend bool InRectAngle(Point p0,Point p1,Point p2);        //判断点p0是否在p1和p2表示的矩形内
    friend bool OnSegment(Point p0,Point p1,Point p2);          //判断点p0是否在p1p2线段上
    friend bool Parallel(Point p1,Point p2,Point p3,Point p4);  //判断p1p2和p3p4线段是否平行
    friend bool SegIntersect(Point p1,Point p2,Point p3,Point p4);//判断p1p2和p3p4两线段是否相交
    friend bool PointInPolygon(Point p0,vector<Point> a);       //判断点p0是否在点集a所形成的多边形内

    ~Point();
};

Point::Point(int x,int y)
{
    this->x = x;
    this->y = y;
}

Point::~Point()
{
}

bool operator ==(Point &p1,Point &p2){
    if(p1.x == p2.x && p1.y == p2.y){
        return true;
    }else return false;
}

Point operator +(Point &p1,Point &p2){
    // Point p(0,0);
    // if( !Angle(p,p1,p2) ){
    //     return p;
    // }else 
    return Point(p1.x + p2.x,p1.y+p2.y);
}

Point operator -(Point &p1,Point &p2){
    return Point(p1.x - p2.x , p1.y - p2.y);
}

double Dot(Point p1,Point p2){ //点乘
    return p1.x * p2.x + p1.y * p2.y;
}

double Length(Point &p){
    return sqrt(p.x * p.x + p.y * p.y);
}

int Angle(Point p0,Point p1,Point p2){
    //使用向量的公式计算：
    // 向量A = p1 - p0
    // 向量B = p2 - p0
    // cos theta = AxB / |A| * |B| 
    // Point point1 ((p1-p0).x,(p1-p0).y);
    // Point point2 ((p2-p0).x,(p2-p0).y);  //没体现出方向，不能这样做
    // return acos(Dot(point1,point2)/(Length(point1)*Length(point2)));  
    double theta = atan2(p1.x-p0.x, p1.y-p0.y) - atan2(p2.x-p0.x, p2.y-p0.y);
	// theta = abs(theta * 180.0 / M_PI);
	return (int)(theta * 180.0 / M_PI);
}

double Det(Point p1,Point p2){
    //求两个向量的叉乘
    //叉乘的结果应该是一个向量，这里给出的返回值是double那就默认返回的是该向量的长度了，也是这两向量所围成的平行四边形的面积
    //正负号表示方向
    //这里 p1，p2 没体现出方向，所以默认还是以（0，0）为起点吧
    // return p1.x * p2.y -  p2.x * p1.y ; //这里是以p1 为右手定则的初方向
    Point p0(0,0);
    if(Angle(p0,p1,p2)<0){
            return -Length(p1)*Length(p2)*cos(Angle(p0,p1,p2)*M_PI/180); 
    }
    return Length(p1)*Length(p2)*cos(Angle(p0,p1,p2)*M_PI/180); 
}

int Direction(Point p0,Point p1,Point p2){
    //判断两线段的方向
    //假设钝角度即逆向
    if(Angle(p0,p1,p2) > 90 || Angle(p0,p1,p2) <-90){
        return 1; //表示逆向
    }else return 0;
}

double Distance(Point p1,Point p2){
    // 求两点距离
   return sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
}

double DistPtoSegment(Point p0,Point p1,Point p2){
    //计算解释：点(x0,y0)到(x1,y1),(x2,y2)的距离
    //利用公式 d =｜Ax+By+C|/sqrt(A*A+B*B)
    //其中A = y2-y1;  B = x1-x2 ; C = x2y1-x1y2 ;
    return fabs((p2.y-p1.y)*p0.x + (p1.x-p2.x)*p0.y + (p2.x*p1.y - p1.x*p2.y)) / sqrt(pow(p2.y-p1.y,2)+pow(p1.x-p2.x,2));
}

bool InRectAngle(Point p0,Point p1,Point p2){
    //判断点p0是否在p1和p2表示的矩形内
    //思路：通过判断向量和矩形的边的方向关系，refer from：https://blog.csdn.net/weixin_43619346/article/details/107513919
    /***example:
     *                      p0
     *            p1
     *            *************** p4 
     *          *             *
     *        *             *
     *      *             *
     *    *             *
     * ***************p2
     ***/
    Point p4((p1+p2).x,(p1+p2).y);
    return  Det(p1,p0-p1)*Det(p2-p4,p2-p0) >= 0 && Det(p2,p0)*Det(p4-p1,p0-p4) >= 0 ;
    // if( Det(p1,p0-p1)*Det(p2-p4,p2-p0) >= 0 && Det(p2,p0)*Det(p4-p1,p0-p4) >= 0 ){
    //     return true;
    // }else return false;
}

bool OnSegment(Point p0,Point p1,Point p2){
    return !acos(Angle(p0,p1,p2)); //共线了返回true
}

bool Parallel(Point p1,Point p2,Point p3,Point p4){
    //判断p1p2和p3p4线段是否平行
    Point p_parallel_1(p1.y,p2.x); // 与p1的y等高的点，为了方便计算p1p2的斜率角
    Point p_parallel_2(p3.y,p4.x); // 与p3的y等高的点
    if(OnSegment(p1,p2,p3) || OnSegment(p1,p2,p4) || OnSegment(p2,p3,p4)){
        return false;
    }else if(Angle(p1,p_parallel_1,p2) == Angle(p3,p_parallel_2,p4)){  //二者斜率角相等又不共线的话必然平行
        return true;
    }else return false;
}    

bool SegIntersect(Point p1,Point p2,Point p3,Point p4){
    //判断p1p2和p3p4两线段是否相交
    //判断p3,p4是否在p1p2这条线段不同侧即可
    if(OnSegment(p1,p2,p3) || OnSegment(p1,p2,p4) || OnSegment(p2,p3,p4)){
        return false;
    }else if(Det(p2-p1,p3-p1)*Det(p4-p1,p2-p1) > 0){
        return true;
    }else return false;
}


bool PointInPolygon(Point p0,vector<Point> a){
    //判断点p0是否在点集a所形成的多边形内
    return false;
}    



