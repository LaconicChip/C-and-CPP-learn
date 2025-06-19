#include"save.h"
#include"data.h"
#include "utils.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

// ��ʽ������ʱ�䣨ͳһʹ�� | �ָ�����
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

// ����ʽ����ʱ���ַ���ת���� DataTime �ṹ��
// �޸Ľ���������ƥ���¸�ʽ
DataTime string_to_DataTime(const string& timeStr) {
    DataTime dt;
    istringstream iss(timeStr);
    char dash1, dash2, colon;

    iss >> dt.year >> dash1 >> dt.month >> dash2 >> dt.day;
    iss >> dt.hour >> colon >> dt.minute;

    return dt;
}

// �������Ա����
void save_admins() {
    ofstream file("admins.dat", ios::trunc); // ��ղ������ļ�
    if (!file) {
        cout << "�����޷��������Ա���ݵ� admins.dat" << endl;
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

// �����û�����
void save_users() {
    ofstream file("users.dat", ios::trunc);
    if (!file) {
        cout << "�޷��� users.dat �ļ�����д�롣" << endl;
        return;
    }
    User* current = user_head;
    while (current != nullptr) {
        file << current->name << "|"
            << current->id << "|"
            << current->phone << "|"
            << current->password << "|";
        // ���涩������
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

// ���泵������
void save_trains() {
    ofstream file("trains.dat", ios::trunc);
    if (!file) {
        cout << "�޷��� trains.dat �ļ�����д�롣" << endl;
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

// ������������
void save_all_data() {
    save_admins(); // �������Ա����
    save_users();  // �����û�����
    save_trains(); // ���泵������
    cout << "���������ѱ��档" << endl;
}

// ���ع���Ա����
void load_admins() {
    ifstream file("admins.dat");
    if (!file) {
        cout << "�޷��� admins.dat �ļ����ж�ȡ��" << endl;
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
        if (tokens.size() < 4) continue; // ������Ч��

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

// �����û�����
void load_users() {
    ifstream file("users.dat");
    if (!file) {
        cout << "�޷��� users.dat �ļ����ж�ȡ��" << endl;
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

        // ���ض�������
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
            i += 7; // ÿ������ռ��7���ֶ�
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

// ���س�������
void load_trains() {
    ifstream file("trains.dat");
    if (!file) {
        cout << "�޷��� trains.dat �ļ����ж�ȡ��" << endl;
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

// ������������
void load_all_data() {
    load_admins();
    load_users();
    load_trains();
    //cout << "�����Ѽ��ء�" << endl;
}













/*
//�����ַ�����ͳһ���������ַ����ֶΣ�
void save_string(ofstream& file, const string& str)
{
	size_t len = str.size();//��ȡ�ַ�������
	file.write(reinterpret_cast<const char*>(&len), sizeof(size_t));//д�볤��
	file.write(str.c_str(), len);//д��ʵ���ַ�������ֹ����
}
//ʱ��ṹ�崦��
void save_datatime(ofstream& file, const DataTime& dt)
{
	file.write(reinterpret_cast<const char*>(&dt.year), sizeof(int));
	file.write(reinterpret_cast<const char*>(&dt.month), sizeof(int));
	file.write(reinterpret_cast<const char*>(&dt.day), sizeof(int));
	file.write(reinterpret_cast<const char*>(&dt.hour), sizeof(int));
	file.write(reinterpret_cast<const char*>(&dt.minute), sizeof(int));
}
//�������ݴ���
void save_order(ofstream& file, const Order* orders)
{
	while (orders != NULL)
	{
		save_string(file, orders->train_number);//���泵�κ�
		save_string(file, orders->carriage_number);//���泵���
		save_string(file, orders->seat);//������λ��
		save_datatime(file, orders->dep_time);//�������ʱ��
		save_datatime(file, orders->dest_time);//���浽��ʱ��
		orders = orders->next;
	}
	int endMark = -1;//д�붩��������־
	file.write(reinterpret_cast<const char*>(&endMark), sizeof(int));
}
//�û����ݴ���
void save_user(ofstream& file, const User* user)
{
	save_string(file, user->name);//�����û���
	save_string(file, user->id);//�������֤��
	save_string(file, user->phone);//�����ֻ���
	save_string(file, user->password);//��������
	save_order(file, user->orders);//���涩��
}
//�������ݴ���
void save_carriage(ofstream& file, const Carriage* car)
{
	file.write(reinterpret_cast<const char*>(&car->num), sizeof(int));//д�복���
	file.write(reinterpret_cast<const char*>(&car->rows), sizeof(int));//д����λ����
	file.write(reinterpret_cast<const char*>(&car->cols), sizeof(int));//д����λ����
	//����ÿ����λ
	for (int i = 0; i < car->rows; i++)
	{
		for (int j = 0; j < car->cols; j++)
		{
			bool hasUser = (car->seats[i][j] != NULL);//�ж���λ�Ƿ�����
			file.write(reinterpret_cast<const char*>(&hasUser), sizeof(bool));//д����
			if (hasUser)
			{
				save_user(file, car->seats[i][j]);

			}//������ˣ�������λ��Ӧ���û�����
		}
	}
}
//�������ݴ���
void save_train(ofstream& file, const Train* train)
{
	save_string(file, train->number);//���泵�κ�
	save_string(file, train->dep);//�������վ
	save_string(file, train->dest);//���浽��վ
	save_datatime(file, train->dep_time);//�������ʱ��
	save_datatime(file, train->dest_time);//���浽��ʱ��
	file.write(reinterpret_cast<const char*>(&train->total_seats), sizeof(int));//��������λ��
	file.write(reinterpret_cast<const char*>(&train->remain_seats), sizeof(int));//����ʣ����λ��

	//���泵������
	Carriage* car = train->carriage;
	while (car != NULL)
	{
		save_carriage(file, car);
		car = car->next;
	}
	//д�복�����������־��-1��
	int endMark = -1;
	file.write(reinterpret_cast<const char*>(&endMark), sizeof(int));
}
//����Ա���ݴ���
void save_admin(ofstream& file, const Admin* admin)
{
	save_string(file, admin->name);//�������Ա��
	save_string(file, admin->id);//�������֤��
	save_string(file, admin->phone);//�����ֻ���
	save_string(file, admin-> password);//��������
}
//�����溯��
void save_all_data()
{   //���泵��
	ofstream trainFile("train.dat", ios::binary);
	if (!trainFile)
	{
		cout << "�޷��� train.dat �ļ�����д�롣" << endl;
		return;
	}
	Train* train_current = train_head;
	while (train_current != NULL)
	{
		save_train(trainFile, train_current);
		train_current = train_current->next;
	}
	trainFile.close();
	//�����û�
	ofstream userFile("user.dat", ios::binary);
	if (!userFile)
	{
		cout << "�޷��� user.dat �ļ�����д�롣" << endl;
		return;
	}
	User* user_curren = user_head;
	while (user_curren != NULL)
	{
		save_user(userFile, user_curren);
		user_curren = user_curren->next;
	}
	userFile.close();
	// �������Ա
	ofstream adminFile("admin.dat", ios::binary);
	if (!adminFile) {
		cerr << "�޷��� admin.dat �ļ�����д�롣" << endl;
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