#include"data.h"
//全局变量定义
Train* train_head = nullptr;
Train* train_tail = nullptr;
Admin* admin_head = nullptr;
Admin* admin_tail = nullptr;
User* user_head = nullptr;
User* user_tail = nullptr;
const int total_seats = 800;//火车总座位
const int  total_carriages = 10;//火车车厢总数
const int seats_in_carriage = 80;//每节车厢80个座位
const int rows_in_carriage = 16;//每节车厢16排
const int cols_in_row = 5;//每排5个座位（ABCDF）
//设置固定列宽
const int number_width = 6;//车次号宽度：train->number|
const int station_width = 10;//出发站或终点站宽度：train->dep|或train->dest|
const int time_width = 16;//出发时间或到达时间宽度：train->dep_time|或train->dest_time|
const int seat_width = 7;//座位数宽度：train->dtotal_seats/train->remain_seats|
//总宽度，除了┌ ┐└ ┘
const int total_width = number_width + 1 + (station_width + 1) * 2 + (time_width + 1) * 2 + seat_width;

// 在DataTime结构体定义后添加常量
const int DATE_PART_LENGTH = 10; // "YYYY-MM-DD"
const int TIME_PART_LENGTH = 5;  // "HH:MM"
const int FULL_TIME_LENGTH = DATE_PART_LENGTH + 1 + TIME_PART_LENGTH; // +1 for space