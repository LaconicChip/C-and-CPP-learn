//admin.h
#ifndef ADMIN_H
#define ADMIN_H
#include"data.h"
//临时的火车信息结构体
typedef struct TrainInfo
{
    string number;//车次号（如G101）
    string dep;//出发站（如北京）
    string dest;//终点站（如上海）
    string deptime;
    string desttime;
    DataTime dep_time = { 0 };//出发时间
    DataTime dest_time = { 0 };//到达时间
    int total_seats = 0;//总座位数
}TrainInfo;
void admin_interface();//系统管理员界面
void admin_log_in();//系统管理员登录
void admin_register();// 系统管理员注册
void admin_functions_initial_prompt(int function, int step, int prompt, const TrainInfo & info);//管理员添加车票信息的初始提示
void add_train_ticket();//添加车票信息
void delete_train_ticket();//删除车票信息
void modify_train_ticket();//修改车票信息
void search_train_ticket();//查询车票信息
void login_admin_menu();//显示登录后管理员服务器功能菜单
void admin_functions();//管理员服务器功能
void add_user_info();//添加用户

#endif //admin.h

