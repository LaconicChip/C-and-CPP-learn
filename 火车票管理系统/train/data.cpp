#include"data.h"
//ȫ�ֱ�������
Train* train_head = nullptr;
Train* train_tail = nullptr;
Admin* admin_head = nullptr;
Admin* admin_tail = nullptr;
User* user_head = nullptr;
User* user_tail = nullptr;
const int total_seats = 800;//������λ
const int  total_carriages = 10;//�𳵳�������
const int seats_in_carriage = 80;//ÿ�ڳ���80����λ
const int rows_in_carriage = 16;//ÿ�ڳ���16��
const int cols_in_row = 5;//ÿ��5����λ��ABCDF��
//���ù̶��п�
const int number_width = 6;//���κſ�ȣ�train->number|
const int station_width = 10;//����վ���յ�վ��ȣ�train->dep|��train->dest|
const int time_width = 16;//����ʱ��򵽴�ʱ���ȣ�train->dep_time|��train->dest_time|
const int seat_width = 7;//��λ����ȣ�train->dtotal_seats/train->remain_seats|
//�ܿ�ȣ����˩� ���� ��
const int total_width = number_width + 1 + (station_width + 1) * 2 + (time_width + 1) * 2 + seat_width;

// ��DataTime�ṹ�嶨�����ӳ���
const int DATE_PART_LENGTH = 10; // "YYYY-MM-DD"
const int TIME_PART_LENGTH = 5;  // "HH:MM"
const int FULL_TIME_LENGTH = DATE_PART_LENGTH + 1 + TIME_PART_LENGTH; // +1 for space