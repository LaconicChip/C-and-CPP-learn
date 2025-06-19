//data.h
#ifndef DATA_H
#define DATA_H
#include<string>
#include <vector>
#include <unordered_set>
using namespace std;
//时间结构体（精确到年月日时分）
typedef struct DataTime
{
    int year=0;
    int month=0;
    int day=0;
    int hour=0;
    int minute=0;
}DataTime;

// 订单结构体（用户可购买多张票）
typedef struct Order
{
    string train_number;//车次号
    string seat;//座位号（如1A）
    string dep;         // 出发站
    string dest;        // 到达站
    DataTime dep_time;//出发时间
    DataTime dest_time;//到达时间
    int price;//票价
    int seat_number;//座位编号（从1到800）
    struct Order* next;// 下一个订单
}Order;
//用户结构体
typedef struct User
{
    string name;//用户名
    string id;//身份证号
    string phone;//手机号（账号）
    string password;//密码
    //Order* orders;
    vector<Order> orders;// 订单链表（支持多票）
    struct User* next;//链表指针，下一个用户
}Users;

//vector是一个动态数组，它允许我们在运行时动态地调整数组的大小，而不需要手动管理内存。

/*//车厢结构体
typedef struct Carriage
{
    int num;//车厢号
    int rows;//座位行数
    int cols;//座位列数
    User*** seats;//三维指针：seat[row][col]指向用户
    struct Carriage* next;//链表指针，下一个车厢
}Carriage;
*/
//车次结构体
typedef struct Train
{
    string number;//车次号（如G101）
    string dep;//出发站（如北京）
    string dest;//终点站（如上海）
    int price;//票价
    DataTime dep_time;//出发时间
    DataTime dest_time;//到达时间
    int total_seats;//总座位数
    int remain_seats;//剩余座位数
    //unordered_set<int> sold_seats; //已售出座位编号集合（快速查询）
    struct Train* next;//链表指针
    //Carriage* carriage;//车厢链表
}Train;
//管理员结构体
typedef struct Admin
{
    string name;//用户名
    string id;//身份证号
    string phone;//手机号（账号）
    string password;//密码
    struct Admin* next;////链表指针，下一个管理员
}Admin;
//全局变量声明
extern Train* train_head;
extern Train* train_tail;
extern Admin* admin_head;
extern Admin* admin_tail;
extern User* user_head;
extern User* user_tail;

extern const int total_seats ;//火车总座位
extern const int  total_carriages ;//火车车厢总数
extern const int seats_in_carriage ;//每节车厢80个座位
extern const int rows_in_carriage ;//每节车厢排数 16排
extern const int cols_in_row ;//每排座位数 5个座位（ABCDF）

//设置固定列宽
extern const int number_width ;//车次号宽度：train->number|
extern const int station_width ;//出发站或终点站宽度：train->dep|或train->dest|
extern const int time_width ;//出发时间或到达时间宽度：train->dep_time|或train->dest_time|
extern const int seat_width ;//座位数宽度：train->dtotal_seats/train->remain_seats|
//总宽度，除了┌ ┐└ ┘
extern const int total_width;
#endif //data.h

