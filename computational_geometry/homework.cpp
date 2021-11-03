#include"homework.h"

using namespace std;

int main()
{

    cout << "test enviroment success" <<endl;
    cout<<"1. 测试 operator ==\t\t2. 测试 operator +\t\t3.测试 operator -"<<endl;
    cout<<"4. 求两个向量的点积\t\t5.  求向量长度\t\t\t6.求两线段的夹角"<<endl;
    cout<<"7. 求两个向量的叉乘\t\t8.  判断两线段的方向\t\t9.求两个点的距离"<<endl;
    cout<<"10. 求一点到直线的距离\t\t11.  判断点在矩形内部\t\t12.判断点在线段上"<<endl;
    cout<<"13. 判断线段是否平行\t\t14.  判断线段是否相交\t\t15.判断点是否在平面内"<<endl;
    cout<<"请输入您要测试的方法序号："<<endl;
     
    int x = 0;
    cin>>x;
   
    switch (x)
    {
    case 1:{
         // test operator ==
        cout<<"请输入您要测试的两个点，该点会分别以（0，0）为起始点构造两个向量，并检测这两点是否相等："<<endl;
        double x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        Point p1(x1,y1),p2(x2,y2);
        if( p1 == p2){
            cout<<"该两个向量相等"<<endl;
        }else cout<<"该两个向量不相等"<<endl;
        break;
    }
    case 2:{
         // test operator +
        cout<<"请输入您要测试的两个点，该点会分别以（0，0）为起始点构造两个向量，并返回两点相加后的向量："<<endl;
        double x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        Point p1(x1,y1),p2(x2,y2);
        // if( (p1+p2).point_x(p1+p2) == 0 && (p1+p2).point_y(p1+p2) == 0 ){
        //     cout << "使用共线向量测试意义不大哦.."<<endl;
        //     break;
        // }else 
        cout <<"向量和为（ "<< Show_x(p1+p2)<<" , "<<Show_y(p1+p2)<<" )"<<endl;
        break;
    }
    case 3:{
         // test operator -
        cout<<"请输入您要测试的两个点，该点会分别以（0，0）为起始点构造两个向量，并返回两点相减后的向量："<<endl;
        double x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        Point p1(x1,y1),p2(x2,y2);
        cout <<"向量差为（ "<< Show_x(p1-p2)<<" , "<<Show_y(p1-p2)<<" )"<<endl;
        break;
    }

    case 4:{
        cout<<"请输入您要测试的两个点，该点会分别以（0，0）为起始点构造两个向量，并返回两向量的点积值："<<endl;
        double x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        Point p1(x1,y1),p2(x2,y2);
        cout <<"点积值为: "<< Dot(p1,p2) <<endl;
        break;
    }

    case 5:{
        cout<<"请输入您要测试的点，默认构造以（0，0）为起点的向量，并返回该向量长度："<<endl;
        double x1,y1;
        cin>>x1>>y1;
        Point p1(x1,y1);
        cout <<"该向量长度为: "<< Length(p1) <<endl;
        break;
    }

    case 6:{
        cout<<"请输入您要测试的三个点p0,p1,p2,可求出向量p0p1,p0p2的夹角(默认以逆时针方向为正角度）："<<endl;
        double x1,x2,y1,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Point p1(x1,y1),p2(x2,y2),p3(x3,y3);
        cout <<"p0p1和p0p2夹角为: "<< Angle(p1,p2,p3) << " 度 "<<endl;
        break;
    }
    
     case 7:{
        cout<<"请输入您要测试的两个点，该点会分别以（0，0）为起始点构造两个向量，并返回两向量的叉乘值(注意：在0附近未做截断处理）："<<endl;
        double x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        Point p1(x1,y1),p2(x2,y2);
        cout <<"叉乘值为: "<< Det(p1,p2) <<endl;
        break;
    }

     case 8:{
        cout<<"请输入您要测试的三个点，该点会分别以p0为起始点构造两个向量，向量角度大于90度即为逆向（用1表示逆向，0 表示同向："<<endl;
        double x1,x2,y1,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Point p1(x1,y1),p2(x2,y2),p3(x3,y3);
        cout <<"是否逆向: "<< Direction(p1,p2,p3) <<endl;
        break;
    }

     case 9:{
        cout<<"请依次输入您要测试的两个点的坐标："<<endl;
        double x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        Point p1(x1,y1),p2(x2,y2);
        cout <<"两点相距： "<< Distance(p1,p2) <<endl;
        break;
    }

     case 10:{
        cout<<"请依次输入您要测试的p0,p1,p2三个点的坐标，求p0到p1p2线的距离："<<endl;
        double x1,x2,y1,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Point p1(x1,y1),p2(x2,y2),p3(x3,y3);
        cout <<"测试点(p0)到直线p1p2的距离为： "<< DistPtoSegment(p1,p2,p3) <<endl;
        break;
    }

     case 11:{
        cout<<"请输入您要测试的三个点的坐标："<<endl;
        double x1,x2,y1,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Point p1(x1,y1),p2(x2,y2),p3(x3,y3);
        cout <<"判断p0是否在p1p2形成的平行四边形(p1 和 p2会以（0，0）点作为起点坐标形成两个向量组成平行四边形）内： "<< InRectAngle(p1,p2,p3) <<endl;
        break;
    }
     case 12:{
        cout<<"请输入您要测试的三个点的坐标，判断p0是否在p1p2线段上："<<endl;
        double x1,x2,y1,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Point p1(x1,y1),p2(x2,y2),p3(x3,y3);
        cout <<" 点p0是否在p1p2线段上："<< OnSegment(p1,p2,p3) <<endl;
        break;
    }
     case 13:{
        cout<<"请输入您要测试的四个点的坐标，会判断p1p2线段是否和p3p4平行："<<endl;
        double x1,x2,y1,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        Point p1(x1,y1),p2(x2,y2),p3(x3,y3),p4(x4,y4);
        cout <<"线段p1p2是否和线段p3p4平行： "<< Parallel(p1,p2,p3,p4) <<endl;
        break;
    }
     case 14:{
        cout<<"请输入您要测试的四个点的坐标，会判断p1p2线段是否和p3p4相交："<<endl;
        double x1,x2,y1,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        Point p1(x1,y1),p2(x2,y2),p3(x3,y3),p4(x4,y4);
        cout <<"线段p1p2是否和p3p4相交： "<< Parallel(p1,p2,p3,p4) <<endl;
        break;
    }
     case 15:{
        cout<<"不好意思老师，这部分实现在交作业之前还有问题..."<<endl;
        cout<<"后续更多实现和优化会放在： https://github.com/Viaxiz/VariesDemo  "<<endl;
        cout<<"老师如果可以的话，欢迎点击访问最新版"<<endl;
        cout<<"谢谢老师：）"<<endl;
        break;
    }
    
    default:
        cout<<"sorry , 请注意方法序号 , 建议选择1到15的整数..."<<endl;
        break;
    }
    
    return 0;

}