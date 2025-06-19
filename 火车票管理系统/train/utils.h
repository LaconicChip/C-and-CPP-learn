#ifndef UTILS_H
#define UTILS_H
#include<iostream>
#include<cstdlib>//����rand()��srand()����
#include<windows.h>// ���� Sleep ����,_getch
#include<string>//to_string������stoi����,pop_back����
#include<sstream>
#include<cctype>//�����ַ�����������isspace,isalpah,isalnum��isdigit
#include <ctime>   // for time, localtime,����time()����
#include <conio.h>//_getch
#include"data.h"
#include<iomanip>
using namespace std;
void print_specific_char(int type);//����ض��������ַ�
void print_repeated_char(int type);//���ָ���������ظ��ַ�
string formatTime(const DataTime& time);//��DataTime��ʽ��Ϊ�̶���ȵ��ַ���
void print_centered(const string& text);//���д�ӡ�ı�
void show_main_menu();//��ʾ�������˵�
void show_admin_menu();//��ʾϵͳ����Ա�˵�
void show_user_menu();// ��ʾ�û��˵�
void menu_again(int);//������ʾ�����ʼ�˵�
string showstar();//����������ʾ�Ǻ�
void register_initial_prompt(int, int,int,int, const string& username = "",const string& idNumber = "",const string& phone = "",const string& code = "", const string& password = "");//ע������ʼ��ʾ��Ϣ
string trim(const string& input);//ע�Ჽ������������֤
bool is_username_same(int userType, const string& username);//����û����Ƿ��ظ�
bool get_vaild_name(int userType,const string& username);//��ȡ�û��������Ч����������ո񡢿�����������
string name_check(int userType);//ע�Ჽ������������֤
bool isLeapYear(int);// ��������2�£�����29��
bool get_vaild_id(int userType,const string& idNumber, const string& username);//��֤���֤�������Ч�ԣ�18λ��
string id_check(int userType, const string& username);//ע�Ჽ���������֤����֤
bool get_vaild_phone(int userType, const string& phone, const string& username, const string& idNumber);// ��֤�ֻ����Ƿ���Ϲ���
string phone_check(int userType, const string& username, const string& idNumber); //ע�Ჽ�������ֻ�����֤
string generateVerificationCode();// ����6λ���������֤��
string code_check(int userType, const string& username, const string& idNumber, const string& phone);//ע�Ჽ�������ֻ����ŷ�����֤�����֤
void clearCurrentLine();//�����������ʹ�����ʾ
bool isAllowedSpecialChar(char c);// ����ַ��Ƿ�Ϊ����������ַ�
bool is_continuous_number(const string& password);//����Ƿ�����������֣���1234��8765��
bool is_repeated_chars(const string& password);//����Ƿ��ظ��ַ�
string password_check(int userType,const string& username, const string& idNumber, const string& phone, const string& code);//��֤�����Ƿ���Ϲ���
int get_vaild_int(int, int, int);//������֤
int isConfirm(int& prompt);//ȷ��Ŀǰ����
string getPassword();//��¼ʱ��ȡ������֧���л���ʾ״̬
void login_initial_prompt(int userType,int step, int prompt, const string& username="");//��¼�����ʼ��ʾ��Ϣ
bool number_check(const string& number, int& prompt);//��鳵�κ��Ƿ���Ϲ���
bool station_check(const string& name, int& prompt);//���վ���Ƿ���Ϲ���
bool dep_time_check(const string& time, int& prompt);//������ʱ���Ƿ���Ϲ���
bool isAllDigitals(const string& timeStr);// ���ʱ���ַ�����ȫΪ����
time_t  dataTime_to_timeT(const DataTime& dt);//ת������������DataTimeTemp�ṹ��ת��Ϊtime_t���ͣ�
bool time_check(const string& time, int& prompt, DataTime& dt);//����ʱ���ַ���������ʽ
//DataTime string_to_Datatime(const string& time);
DataTime string_to_DataTime(const string& timeStr);//��ʱ���ַ���ת��ΪDataTime�ṹ��
bool dest_time_check(const DataTime& dep_time, const string& desttime, int& prompt);//��鵽��ʱ���Ƿ���Ϲ���
string formatTime(const DataTime& time);
int inputnumbercheck(int choice);
#endif

