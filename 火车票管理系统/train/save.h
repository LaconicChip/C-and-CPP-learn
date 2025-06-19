//save.h
#ifndef SAVE_H
#define SAVE_H
#include"data.h"
#include<fstream>
// 格式化日期时间（统一使用 | 分隔符）
string format_time(const DataTime& time);
DataTime string_to_DataTime(const string& timeStr);
// 保存函数声明
void save_users(); // 保存用户数据
void save_admins(); // 保存管理员数据
void save_trains(); // 保存车次数据
void save_all_data(); // 保存所有数据

// 加载功能声明
void load_admins(); // 加载管理员数据
void load_users();  // 加载用户数据
void load_trains(); // 加载车次数据
void load_all_data(); // 加载所有数据

/*
void save_string(ofstream& file, const string& str);//保存字符串（统一处理所有字符串字段）
void save_datatime(ofstream& file, const DataTime& dt);//时间结构体处理
void save_order(ofstream& file, const Order* orders);//订单数据处理
void save_user(ofstream& file, const User* user);//用户数据处理
void save_carriage(ofstream& file, const Carriage* car);//车厢数据处理
void save_train(ofstream& file, const Train* train);//车次数据处理
void save_admin(ofstream& file, const Admin* admin);//管理员数据处理
void save_all_data();//主保存函数
*/
#endif //save.h


