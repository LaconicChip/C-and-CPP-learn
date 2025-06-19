#ifndef UTILS_H
#define UTILS_H
#include<iostream>
#include<cstdlib>//包含rand()和srand()函数
#include<windows.h>// 用于 Sleep 函数,_getch
#include<string>//to_string函数，stoi函数,pop_back函数
#include<sstream>
#include<cctype>//包含字符处理函数，如isspace,isalpah,isalnum和isdigit
#include <ctime>   // for time, localtime,包含time()函数
#include <conio.h>//_getch
#include"data.h"
#include<iomanip>
using namespace std;
void print_specific_char(int type);//输出特定数量的字符
void print_repeated_char(int type);//输出指定数量的重复字符
string formatTime(const DataTime& time);//将DataTime格式化为固定宽度的字符串
void print_centered(const string& text);//居中打印文本
void show_main_menu();//显示居中主菜单
void show_admin_menu();//显示系统管理员菜单
void show_user_menu();// 显示用户菜单
void menu_again(int);//重新显示界面初始菜单
string showstar();//输入密码显示星号
void register_initial_prompt(int, int,int,int, const string& username = "",const string& idNumber = "",const string& phone = "",const string& code = "", const string& password = "");//注册界面初始提示信息
string trim(const string& input);//注册步骤输入名字验证
bool is_username_same(int userType, const string& username);//检查用户名是否重复
bool get_vaild_name(int userType,const string& username);//获取用户输入的有效姓名（处理空格、空输入等情况）
string name_check(int userType);//注册步骤输入名字验证
bool isLeapYear(int);// 处理闰年2月，允许29天
bool get_vaild_id(int userType,const string& idNumber, const string& username);//验证身份证号码的有效性（18位）
string id_check(int userType, const string& username);//注册步骤输入身份证号验证
bool get_vaild_phone(int userType, const string& phone, const string& username, const string& idNumber);// 验证手机号是否符合规则
string phone_check(int userType, const string& username, const string& idNumber); //注册步骤输入手机号验证
string generateVerificationCode();// 生成6位随机数字验证码
string code_check(int userType, const string& username, const string& idNumber, const string& phone);//注册步骤输入手机短信发来验证码的验证
void clearCurrentLine();//清除已填密码和错误提示
bool isAllowedSpecialChar(char c);// 检查字符是否为允许的特殊字符
bool is_continuous_number(const string& password);//检查是否包含连续数字（如1234或8765）
bool is_repeated_chars(const string& password);//检查是否重复字符
string password_check(int userType,const string& username, const string& idNumber, const string& phone, const string& code);//验证密码是否符合规则
int get_vaild_int(int, int, int);//输入验证
int isConfirm(int& prompt);//确认目前操作
string getPassword();//登录时获取密码且支持切换显示状态
void login_initial_prompt(int userType,int step, int prompt, const string& username="");//登录界面初始提示信息
bool number_check(const string& number, int& prompt);//检查车次号是否符合规则
bool station_check(const string& name, int& prompt);//检查站名是否符合规则
bool dep_time_check(const string& time, int& prompt);//检查出发时间是否符合规则
bool isAllDigitals(const string& timeStr);// 检查时间字符串是全为数字
time_t  dataTime_to_timeT(const DataTime& dt);//转换成秒数（将DataTimeTemp结构体转换为time_t类型）
bool time_check(const string& time, int& prompt, DataTime& dt);//解析时间字符串并检查格式
//DataTime string_to_Datatime(const string& time);
DataTime string_to_DataTime(const string& timeStr);//将时间字符串转换为DataTime结构体
bool dest_time_check(const DataTime& dep_time, const string& desttime, int& prompt);//检查到达时间是否符合规则
string formatTime(const DataTime& time);
int inputnumbercheck(int choice);
#endif

