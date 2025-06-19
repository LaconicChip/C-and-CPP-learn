//data.h
#ifndef DATA_H
#define DATA_H
#include<string>
#include <vector>
#include <unordered_set>
using namespace std;
//ʱ��ṹ�壨��ȷ��������ʱ�֣�
typedef struct DataTime
{
    int year=0;
    int month=0;
    int day=0;
    int hour=0;
    int minute=0;
}DataTime;

// �����ṹ�壨�û��ɹ������Ʊ��
typedef struct Order
{
    string train_number;//���κ�
    string seat;//��λ�ţ���1A��
    string dep;         // ����վ
    string dest;        // ����վ
    DataTime dep_time;//����ʱ��
    DataTime dest_time;//����ʱ��
    int price;//Ʊ��
    int seat_number;//��λ��ţ���1��800��
    struct Order* next;// ��һ������
}Order;
//�û��ṹ��
typedef struct User
{
    string name;//�û���
    string id;//���֤��
    string phone;//�ֻ��ţ��˺ţ�
    string password;//����
    //Order* orders;
    vector<Order> orders;// ��������֧�ֶ�Ʊ��
    struct User* next;//����ָ�룬��һ���û�
}Users;

//vector��һ����̬���飬����������������ʱ��̬�ص�������Ĵ�С��������Ҫ�ֶ������ڴ档

/*//����ṹ��
typedef struct Carriage
{
    int num;//�����
    int rows;//��λ����
    int cols;//��λ����
    User*** seats;//��άָ�룺seat[row][col]ָ���û�
    struct Carriage* next;//����ָ�룬��һ������
}Carriage;
*/
//���νṹ��
typedef struct Train
{
    string number;//���κţ���G101��
    string dep;//����վ���籱����
    string dest;//�յ�վ�����Ϻ���
    int price;//Ʊ��
    DataTime dep_time;//����ʱ��
    DataTime dest_time;//����ʱ��
    int total_seats;//����λ��
    int remain_seats;//ʣ����λ��
    //unordered_set<int> sold_seats; //���۳���λ��ż��ϣ����ٲ�ѯ��
    struct Train* next;//����ָ��
    //Carriage* carriage;//��������
}Train;
//����Ա�ṹ��
typedef struct Admin
{
    string name;//�û���
    string id;//���֤��
    string phone;//�ֻ��ţ��˺ţ�
    string password;//����
    struct Admin* next;////����ָ�룬��һ������Ա
}Admin;
//ȫ�ֱ�������
extern Train* train_head;
extern Train* train_tail;
extern Admin* admin_head;
extern Admin* admin_tail;
extern User* user_head;
extern User* user_tail;

extern const int total_seats ;//������λ
extern const int  total_carriages ;//�𳵳�������
extern const int seats_in_carriage ;//ÿ�ڳ���80����λ
extern const int rows_in_carriage ;//ÿ�ڳ������� 16��
extern const int cols_in_row ;//ÿ����λ�� 5����λ��ABCDF��

//���ù̶��п�
extern const int number_width ;//���κſ�ȣ�train->number|
extern const int station_width ;//����վ���յ�վ��ȣ�train->dep|��train->dest|
extern const int time_width ;//����ʱ��򵽴�ʱ���ȣ�train->dep_time|��train->dest_time|
extern const int seat_width ;//��λ����ȣ�train->dtotal_seats/train->remain_seats|
//�ܿ�ȣ����˩� ���� ��
extern const int total_width;
#endif //data.h

