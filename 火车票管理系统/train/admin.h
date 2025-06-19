//admin.h
#ifndef ADMIN_H
#define ADMIN_H
#include"data.h"
//��ʱ�Ļ���Ϣ�ṹ��
typedef struct TrainInfo
{
    string number;//���κţ���G101��
    string dep;//����վ���籱����
    string dest;//�յ�վ�����Ϻ���
    string deptime;
    string desttime;
    DataTime dep_time = { 0 };//����ʱ��
    DataTime dest_time = { 0 };//����ʱ��
    int total_seats = 0;//����λ��
}TrainInfo;
void admin_interface();//ϵͳ����Ա����
void admin_log_in();//ϵͳ����Ա��¼
void admin_register();// ϵͳ����Աע��
void admin_functions_initial_prompt(int function, int step, int prompt, const TrainInfo & info);//����Ա��ӳ�Ʊ��Ϣ�ĳ�ʼ��ʾ
void add_train_ticket();//��ӳ�Ʊ��Ϣ
void delete_train_ticket();//ɾ����Ʊ��Ϣ
void modify_train_ticket();//�޸ĳ�Ʊ��Ϣ
void search_train_ticket();//��ѯ��Ʊ��Ϣ
void login_admin_menu();//��ʾ��¼�����Ա���������ܲ˵�
void admin_functions();//����Ա����������
void add_user_info();//����û�

#endif //admin.h

