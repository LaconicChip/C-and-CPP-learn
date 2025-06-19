#include"save.h"
#include"data.h"
#include "utils.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

// 格式化日期时间（统一使用 | 分隔符）
//string format_time(const DataTime& time)
//{
//	return to_string(time.year) + "|" +
//		to_string(time.month) + "|" +
//		to_string(time.day) + "|" +
//		to_string(time.hour) + "|" +
//		to_string(time.minute);
//}
string format_time(const DataTime& time)
{
    ostringstream oss;
    oss << setfill('0')
        << setw(4) << time.year << "-"
        << setw(2) << time.month << "-"
        << setw(2) << time.day << " "
        << setw(2) << time.hour << ":"
        << setw(2) << time.minute;
    return oss.str();
}

// 将格式化的时间字符串转换回 DataTime 结构体
// 修改解析函数以匹配新格式
DataTime string_to_DataTime(const string& timeStr) {
    DataTime dt;
    istringstream iss(timeStr);
    char dash1, dash2, colon;

    iss >> dt.year >> dash1 >> dt.month >> dash2 >> dt.day;
    iss >> dt.hour >> colon >> dt.minute;

    return dt;
}

// 保存管理员数据
void save_admins() {
    ofstream file("admins.dat", ios::trunc); // 清空并覆盖文件
    if (!file) {
        cout << "错误：无法保存管理员数据到 admins.dat" << endl;
        return;
    }
    Admin* current = admin_head;
    while (current != nullptr) {
        file << current->name << "|"
            << current->id << "|"
            << current->phone << "|"
            << current->password << "\n";
        current = current->next;
    }
    file.close();
}

// 保存用户数据
void save_users() {
    ofstream file("users.dat", ios::trunc);
    if (!file) {
        cout << "无法打开 users.dat 文件进行写入。" << endl;
        return;
    }
    User* current = user_head;
    while (current != nullptr) {
        file << current->name << "|"
            << current->id << "|"
            << current->phone << "|"
            << current->password << "|";
        // 保存订单数据
        for (const auto& order : current->orders) {
            file//<< "|ORDER|" 
                << order.train_number << "|"
                << order.dep << "|"
                << order.dest << "|"
                << format_time(order.dep_time) << "|"
                << format_time(order.dest_time) << "|"
                << order.seat_number << "|"
                << order.price << "|";
        }
        file << endl;
        current = current->next;
    }
    file.close();
}

// 保存车次数据
void save_trains() {
    ofstream file("trains.dat", ios::trunc);
    if (!file) {
        cout << "无法打开 trains.dat 文件进行写入。" << endl;
        return;
    }
    Train* current = train_head;
    while (current != nullptr) {
        file << current->number << "|"
            << current->dep << "|"
            << current->dest << "|"
            << format_time(current->dep_time) << "|"
            << format_time(current->dest_time) << "|"
            << current->price << "|"
            << current->total_seats << "|"
            << current->remain_seats << "\n";
        current = current->next;
    }
    file.close();
}

// 保存所有数据
void save_all_data() {
    save_admins(); // 保存管理员数据
    save_users();  // 保存用户数据
    save_trains(); // 保存车次数据
    cout << "所有数据已保存。" << endl;
}

// 加载管理员数据
void load_admins() {
    ifstream file("admins.dat");
    if (!file) {
        cout << "无法打开 admins.dat 文件进行读取。" << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string token;
        vector<string> tokens;
        while (getline(iss, token, '|')) {
            tokens.push_back(token);
        }
        if (tokens.size() < 4) continue; // 跳过无效行

        Admin* newAdmin = new Admin;
        newAdmin->name = tokens[0];
        newAdmin->id = tokens[1];
        newAdmin->phone = tokens[2];
        newAdmin->password = tokens[3];
        newAdmin->next = nullptr;

        if (admin_head == nullptr) {
            admin_head = newAdmin;
            admin_tail = newAdmin;
        }
        else {
            admin_tail->next = newAdmin;
            admin_tail = newAdmin;
        }
    }
    file.close();
}

// 加载用户数据
void load_users() {
    ifstream file("users.dat");
    if (!file) {
        cout << "无法打开 users.dat 文件进行读取。" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string token;
        vector<string> tokens;

        while (getline(iss, token, '|')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 4) continue;

        User* newUser = new User;
        newUser->name = tokens[0];
        newUser->id = tokens[1];
        newUser->phone = tokens[2];
        newUser->password = tokens[3];
        newUser->next = nullptr;

        // 加载订单数据
        for (size_t i = 4; i < tokens.size(); ) {
            if (i + 6 >= tokens.size()) break;

            Order newOrder;
            newOrder.train_number = tokens[i];
            newOrder.dep = tokens[i + 1];
            newOrder.dest = tokens[i + 2];
            newOrder.dep_time = string_to_DataTime(tokens[i + 3]);
            newOrder.dest_time = string_to_DataTime(tokens[i + 4]);
            newOrder.seat_number = stoi(tokens[i + 5]);
            newOrder.price = stoi(tokens[i + 6]);

            newUser->orders.push_back(newOrder);
            i += 7; // 每个订单占用7个字段
        }

        if (user_head == nullptr) {
            user_head = newUser;
            user_tail = newUser;
        }
        else {
            user_tail->next = newUser;
            user_tail = newUser;
        }
    }

    file.close();
}

// 加载车次数据
void load_trains() {
    ifstream file("trains.dat");
    if (!file) {
        cout << "无法打开 trains.dat 文件进行读取。" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string token;
        vector<string> tokens;
        while (getline(iss, token, '|')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 8) continue;

        Train* newTrain = new Train;
        newTrain->number = tokens[0];
        newTrain->dep = tokens[1];
        newTrain->dest = tokens[2];
        newTrain->dep_time = string_to_DataTime(tokens[3]);
        newTrain->dest_time = string_to_DataTime(tokens[4]);
        newTrain->price = stoi(tokens[5]);
        newTrain->total_seats = stoi(tokens[6]);
        newTrain->remain_seats = stoi(tokens[7]);
        newTrain->next = nullptr;

        if (train_head == nullptr) {
            train_head = newTrain;
            train_tail = newTrain;
        }
        else {
            train_tail->next = newTrain;
            train_tail = newTrain;
        }
    }

    file.close();
}

// 加载所有数据
void load_all_data() {
    load_admins();
    load_users();
    load_trains();
    //cout << "数据已加载。" << endl;
}













/*
//保存字符串（统一处理所有字符串字段）
void save_string(ofstream& file, const string& str)
{
	size_t len = str.size();//获取字符串长度
	file.write(reinterpret_cast<const char*>(&len), sizeof(size_t));//写入长度
	file.write(str.c_str(), len);//写入实际字符（无终止符）
}
//时间结构体处理
void save_datatime(ofstream& file, const DataTime& dt)
{
	file.write(reinterpret_cast<const char*>(&dt.year), sizeof(int));
	file.write(reinterpret_cast<const char*>(&dt.month), sizeof(int));
	file.write(reinterpret_cast<const char*>(&dt.day), sizeof(int));
	file.write(reinterpret_cast<const char*>(&dt.hour), sizeof(int));
	file.write(reinterpret_cast<const char*>(&dt.minute), sizeof(int));
}
//订单数据处理
void save_order(ofstream& file, const Order* orders)
{
	while (orders != NULL)
	{
		save_string(file, orders->train_number);//保存车次号
		save_string(file, orders->carriage_number);//保存车厢号
		save_string(file, orders->seat);//保存座位号
		save_datatime(file, orders->dep_time);//保存出发时间
		save_datatime(file, orders->dest_time);//保存到达时间
		orders = orders->next;
	}
	int endMark = -1;//写入订单结束标志
	file.write(reinterpret_cast<const char*>(&endMark), sizeof(int));
}
//用户数据处理
void save_user(ofstream& file, const User* user)
{
	save_string(file, user->name);//保存用户名
	save_string(file, user->id);//保存身份证号
	save_string(file, user->phone);//保存手机号
	save_string(file, user->password);//保存密码
	save_order(file, user->orders);//保存订单
}
//车厢数据处理
void save_carriage(ofstream& file, const Carriage* car)
{
	file.write(reinterpret_cast<const char*>(&car->num), sizeof(int));//写入车厢号
	file.write(reinterpret_cast<const char*>(&car->rows), sizeof(int));//写入座位行数
	file.write(reinterpret_cast<const char*>(&car->cols), sizeof(int));//写入座位列数
	//遍历每个座位
	for (int i = 0; i < car->rows; i++)
	{
		for (int j = 0; j < car->cols; j++)
		{
			bool hasUser = (car->seats[i][j] != NULL);//判断座位是否有人
			file.write(reinterpret_cast<const char*>(&hasUser), sizeof(bool));//写入标记
			if (hasUser)
			{
				save_user(file, car->seats[i][j]);

			}//如果有人，保存座位对应的用户数据
		}
	}
}
//车次数据处理
void save_train(ofstream& file, const Train* train)
{
	save_string(file, train->number);//保存车次号
	save_string(file, train->dep);//保存出发站
	save_string(file, train->dest);//保存到达站
	save_datatime(file, train->dep_time);//保存出发时间
	save_datatime(file, train->dest_time);//保存到达时间
	file.write(reinterpret_cast<const char*>(&train->total_seats), sizeof(int));//保存总座位数
	file.write(reinterpret_cast<const char*>(&train->remain_seats), sizeof(int));//保存剩余座位数

	//保存车厢链表
	Carriage* car = train->carriage;
	while (car != NULL)
	{
		save_carriage(file, car);
		car = car->next;
	}
	//写入车厢链表结束标志（-1）
	int endMark = -1;
	file.write(reinterpret_cast<const char*>(&endMark), sizeof(int));
}
//管理员数据处理
void save_admin(ofstream& file, const Admin* admin)
{
	save_string(file, admin->name);//保存管理员名
	save_string(file, admin->id);//保存身份证号
	save_string(file, admin->phone);//保存手机号
	save_string(file, admin-> password);//保存密码
}
//主保存函数
void save_all_data()
{   //保存车次
	ofstream trainFile("train.dat", ios::binary);
	if (!trainFile)
	{
		cout << "无法打开 train.dat 文件进行写入。" << endl;
		return;
	}
	Train* train_current = train_head;
	while (train_current != NULL)
	{
		save_train(trainFile, train_current);
		train_current = train_current->next;
	}
	trainFile.close();
	//保存用户
	ofstream userFile("user.dat", ios::binary);
	if (!userFile)
	{
		cout << "无法打开 user.dat 文件进行写入。" << endl;
		return;
	}
	User* user_curren = user_head;
	while (user_curren != NULL)
	{
		save_user(userFile, user_curren);
		user_curren = user_curren->next;
	}
	userFile.close();
	// 保存管理员
	ofstream adminFile("admin.dat", ios::binary);
	if (!adminFile) {
		cerr << "无法打开 admin.dat 文件进行写入。" << endl;
		return;
	}
	Admin* admin_current = admin_head;
	while (admin_current != NULL)
	{
		save_admin(adminFile, admin_current);
		admin_current = admin_current->next;
	}
	adminFile.close();
}
*/