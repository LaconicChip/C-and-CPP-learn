//save.h
#ifndef SAVE_H
#define SAVE_H
#include"data.h"
#include<fstream>
// ��ʽ������ʱ�䣨ͳһʹ�� | �ָ�����
string format_time(const DataTime& time);
DataTime string_to_DataTime(const string& timeStr);
// ���溯������
void save_users(); // �����û�����
void save_admins(); // �������Ա����
void save_trains(); // ���泵������
void save_all_data(); // ������������

// ���ع�������
void load_admins(); // ���ع���Ա����
void load_users();  // �����û�����
void load_trains(); // ���س�������
void load_all_data(); // ������������

/*
void save_string(ofstream& file, const string& str);//�����ַ�����ͳһ���������ַ����ֶΣ�
void save_datatime(ofstream& file, const DataTime& dt);//ʱ��ṹ�崦��
void save_order(ofstream& file, const Order* orders);//�������ݴ���
void save_user(ofstream& file, const User* user);//�û����ݴ���
void save_carriage(ofstream& file, const Carriage* car);//�������ݴ���
void save_train(ofstream& file, const Train* train);//�������ݴ���
void save_admin(ofstream& file, const Admin* admin);//����Ա���ݴ���
void save_all_data();//�����溯��
*/
#endif //save.h


