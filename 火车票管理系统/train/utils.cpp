#include"utils.h"
#include"user.h"
#include"admin.h"
#include<iomanip>
//ȫ�ֱ�������
// ���֤ǰ17λȨֵ���飨GB 11643-1999��׼��
//Ȩֵ���ڼ���У���루�����֤�ŵ�18λ����ÿλ���ֳ��Զ�ӦȨֵ�����
const int weights[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
// ���ұ�׼�涨��Ȩֵ������У������㣬˳�򲻿ɸı�

// У����ӳ�������0-10��Ӧ�ַ�
// ���� = (��Ȩ��) % 11����������2��Ӧ'X'����������10��
const char CheckCodes[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
// ����0��ӦCHECK_CODES[0]='1'������2��Ӧ'X'����������10��

// ÿ���������飨����0��Ч��1-12��Ӧ�·ݣ�
// ƽ��2��Ĭ��28�죬����2������֤ʱ��������
int days_in_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//����ض��������ַ�
void print_specific_char(int type)
{
	switch (type)
	{
	case 1:cout << "��"; break;
	case 2:cout << "��"; break;
	case 3:cout << "��"; break;
	}
}
//���ָ���������ظ��ַ�
void print_repeated_char(int type)
{    //�������� �� ��  �� �� ��   ��  ��������������������������������
	//���κſ��
	for (int i = 0; i < number_width; i++)
		cout <<"��";
	print_specific_char(type);
	//����վ���յ�վ���
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < station_width; j++)
			cout << "��";
		print_specific_char(type);
	}
	//����ʱ��򵽴�ʱ����
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < time_width; j++)
			cout << "��";
		print_specific_char(type);
	}
	//��λ�����
	for (int i = 0; i < seat_width; i++)
		cout << "��";
}
//��DataTime��ʽ��Ϊ�̶���ȵ��ַ���
//string formatTime(const DataTime& time)
//{
//	ostringstream oss;
//	oss << setfill('0') //��������ַ�Ϊ0
//		<< setw(4) << time.year << "-"
//		<< setw(2) << time.month << "-"
//		<< setw(2) << time.day << " "
//		<< setw(2) << time.hour << ":"
//		<< setw(2) << time.minute;
//	oss << setfill(' ');//��������ַ�Ϊ�ո�
//	return oss.str();
//}
//string formatTime(const DataTime& time) {
//	ostringstream oss;
//	oss << setfill('0')
//		<< time.year << "-"
//		<< setw(2) << time.month << "-"
//		<< setw(2) << time.day << " "
//		<< setw(2) << time.hour << ":"
//		<< setw(2) << time.minute;
//	return oss.str();
//}
//��ʾ���˵�
void show_main_menu()
{
	// ǿ��ˢ�����������
	cout.flush();
	cout << "===��Ʊ����ϵͳ===" << endl;
	cout << "1.����Ա��¼��ע��" << endl;
	cout << "2.�û���¼��ע��" << endl;
	cout << "3.�˳�ϵͳ" << endl;
	cout.flush();  // �ٴ�ˢ��
}
//��ʾϵͳ����Ա�˵�
void show_admin_menu()
{
	cout << "��Ʊ����ϵͳ->ϵͳ����Ա����" << endl;
	cout << "��ѡ�����Ĳ�����" << endl;
	cout << "1.ע��" << endl;
	cout << "2.��¼" << endl;
	cout << "3.������һ��" << endl;
}
// ��ʾ�û��˵�
void show_user_menu()
{
	cout << "��Ʊ����ϵͳ->��Ʊ�û�����" << endl;
	cout << "��ѡ�����Ĳ�����" << endl;
	cout << "1.ע��" << endl;
	cout << "2.��¼" << endl;
	cout << "3.������һ��" << endl;
}
//������ʾ�����ʼ�˵�
void menu_again(int menu_again_choice)
{
	system("cls");// ����
	switch (menu_again_choice)
	{
	   case 1:show_main_menu(); break;//��ʾ���˵�
	   case 2:show_admin_menu(); break;//��ʾϵͳ����Ա�˵�
	   case 3:show_user_menu(); break;//��ʾ��Ʊ�û��˵�
	   case 4: login_admin_menu(); break;//��ʾ��¼�����Ա���������ܲ˵�    
	   case 5: login_user_menu(); break;//��ʾ��¼���û����ܲ˵�
	}
}
//����������ʾ�Ǻ�
string showstar()
{
	string str;
	char ch;
	//����1�����ʼ�������������������ʾ�Ǻ�
	int isHidden = 1;
	while ((ch = _getch()) != '\r')//ѭ����ȡ�ַ�ֱ����Enter��
	{   // �����������벢��ʾΪ�Ǻ�
		if (ch == '\b')//�����˸��
		{
			if (!str.empty()) // ����ǿ�ʱ����ɾ��
			{
				str.pop_back();// ɾ�����һ���ַ�
				cout << "\b \b";// �����ˣ������ַ����ٻ���
			}
		}
		//����ո�����л�������ʾ״̬������������ʾ�ǺŻ��߲�������ʾ��ʵ�����ַ���
		else if (ch == ' ')
		{   //isHidden�ԼӴӶ���Ϊ��������ż���л�������ʾ״̬
			isHidden++;
			if (isHidden % 2 == 0)
			{   //isHidden��ż��ʱ��ʾ����������ֱ����ʾ����
				cout << "\r" << str;
			}
			else
			{   //isHidden������ʱ��ʾ����������ʾ�Ǻ�
				cout << "\r" << string(str.length(), '*');
			}
		}
		else
		{   //��ʾȷ��������Ǻ�
			str += ch;
			if (isHidden % 2 == 0) cout << ch;
			else cout << "*";
		}
	}
	return str;
 }
//ע������ʼ��ʾ��Ϣ
void register_initial_prompt(int userType, int cls, int step, int prompt, const string& username, const string& idNumber, const string& phone, const string& code, const string& password)
{
	if (cls == 1) system("cls");// ����
	cout << "��Ʊ����ϵͳ->" << (userType == 1 ? "ϵͳ����Ա" : "��Ʊ�û�") << "����->ע��" << endl;
	cout << "�����롰0��,�򷵻���һ��" << endl;
	switch (step)
	{
		//ע������һ�����������û�����ʾ��Ϣ
	case 1:
	{
		cout << "=== �û�����֤���� ===" << endl;
		cout << "��֤����" << endl;
		cout << "1. ÿ���û����γ���Ϊ5-30���ַ�" << endl;
		cout << "2. ÿ���α�������ĸ��ͷ" << endl;
		cout << "3. ֻ�ܰ�����ĸ�����ֺ��»���" << endl << endl;
		switch (prompt)
		{
		case 1:cout << "�����û�������Ϊ��" << endl; break;
		case 2:cout << "�����û������ȱ���Ϊ6-30���ַ�" << endl; break;
		case 3:cout << "�����û�����������ĸ��ͷ" << endl; break;
		case 4:cout << "���󣺰����Ƿ��ַ�" << endl; break;
		case 5:cout << "��������д���û����ѱ������û�ʹ��" << endl; break;
		}
		cout << "�����������û�����" << endl;
	}
	break;
	case 2:
	{
		cout << "=== ���֤����������� ===" << endl;
		cout << "��������ʽҪ��" << endl;
		cout << "  1. ����Ϊ18λ�ַ�����֧���°�18λ���֤����֧��15λ�ɰ棩" << endl;
		cout << "  2. ǰ17λ����ȫΪ���֣���18λΪ���ֻ��д��X����Сдx���Զ�תΪ��д��" << endl;

		cout << "\n���������ڹ���" << endl;
		cout << "  3. ��ݷ�Χ��1900������ǰ���" << endl; // ����ǰ��ȡ��ǰ���
		cout << "  4. �·ݷ�Χ��01-12����01��ʾ1�£�������λ��0��" << endl;
		cout << "  5. ����������·ݹ���" << endl;
		cout << "     - 4/6/9/11�����30�죬1/3/5/7/8/10/12�����31��" << endl;
		cout << "     - ƽ��2�����28�죬����2�����29��" << endl;

		cout << "\n�����봦�����" << endl;
		cout << "  6. �Զ�ȥ��ǰ��ո񣬵��м䲻���пո������롰 110...X �����Զ�����Ϊ��110...X����" << endl;
		cout << "  7. ʾ����11010120000101123X���������ڣ�2000��1��1�գ�У����X��" << endl << endl;
		switch (prompt)
		{
		case 1:cout << "�������֤�Ų���Ϊ��" << endl; break;
		case 2:cout << "�������֤�������Ϊ18λ" << endl; break;
		case 3:cout << "����ǰ17λ����ȫΪ����" << endl; break;
		case 4:cout << "���󣺵�18λ����Ϊ���ֻ�X" << endl; break;
		case 5:cout << "���󣺴���У����(�����֤�ŵ�18λ)����ӦΪ" << idNumber << "��" << endl; break;
		case 6:cout << "������ݱ�����1900-" << idNumber << "֮��" << endl; break;
		case 7:cout << "�����·ݱ�����1-12��֮��" << endl; break;
		case 8:cout << "����" << idNumber << "�µ�������Χ������1-" << phone << "��֮��" << endl; break;
		case 9:cout << "���󣺲�������δ������" << endl; break;
		}
		cout << "�û�����" << username << endl;
		cout << "�������������֤�ţ�" << endl;
	}
	break;
	case 3:
	{
		cout << "=== �ֻ������������ ===" << endl;
		cout << " ��ʽҪ��" << endl;
		cout << "1.��Ϊ11λ���֣���1��ͷ����13800138000��" << endl;
		cout << "2.�Զ�ȥ��ǰ��ո񣬵��м䲻���пո�" << endl;
		cout << "3.��ͨ��������֤����֤" << endl;
		cout << "ʾ����18612345678������0������һ����" << endl << endl;
		switch (prompt)
		{
		case 1:cout << "�����ֻ��Ų���Ϊ��" << endl; break;
		case 2:cout << "�����ֻ��ű���Ϊ11λ���ֲ�����1��ͷ" << endl; break;
		case 3:cout << "�����ֻ��ű���ȫΪ����" << endl; break;
		}
		cout << "�û�����" << username << endl;
		cout << "���֤�ţ�" << idNumber << endl;
		cout << "�����������ֻ��ţ�" << endl;
	}
	break;
	case 4:
	{
		cout << endl << "�����ֻ���֤������ƴ���������������3�������֮ǰ��д��ע����Ϣ����ǿ�Ʒ�����һ����" << endl;
		switch (prompt)
		{
		case 1:cout << "������֤�벻��Ϊ��" << endl; break;
		case 2:cout << "������֤�����Ϊ6λ����" << endl; break;
		case 3:cout << "������֤�����ȫΪ����" << endl; break;
		case 4:cout << "����������֤�벻ƥ��" << endl; break;
		}
		if (prompt >= 1) cout << endl << "�����·����µ���֤��" << endl;
		cout << "����·�ͷ���������֤���ǣ�" << code << endl;
		cout << "�û�����" << username << endl;
		cout << "���֤�ţ�" << idNumber << endl;
		cout << "�ֻ��ţ�" << phone << endl;
		cout << "������������֤�룺" << endl;
	}
	break;
	case 5:
	{
		cout << "\n===== �������ù��� =====" << endl;
		cout << "1. ����Ϊ8-30���ַ�" << std::endl;
		cout << "2. ���������ĸ������1����д��Сд��" << endl;
		cout << "3. ����������֣�����1����" << endl;
		cout << "4. ���԰��������ַ�: !@#$%^&*_-+=" << endl;
		cout << "5. ���ܰ����ո�������ַ�" << endl;
		cout << "6. �������û�����ͬ" << endl;
		cout << "7. ���ܰ����������֣���1234�����ظ��ַ�����aaaa��" << endl;
		cout << "======================\n" << endl;
		switch (prompt)
		{
		case 1:cout << "�������벻��Ϊ��" << endl; break;
		case 2:cout << "�������볤�ȱ���Ϊ8-30���ַ�" << endl; break;
		case 3:cout << "�������벻�����û�����ͬ" << endl; break;
		case 4:cout << "������������������һ����ĸ" << endl; break;
		case 5:cout << "������������������һ������" << endl; break;
		case 6:cout << "��������ǿ�Ƚ��������ܰ����������������У���1234��8765��" << endl; break;
		case 7:cout << "��������ǿ�Ƚ��������ܰ����������ظ��ַ�����aaaa��1111��" << endl; break;
		}
		cout << "�û�����" << username << endl;
		cout << "���֤�ţ�" << idNumber << endl;
		cout << "�ֻ��ţ�" << phone << endl;
		cout << "��֤�룺" <<code<< endl;
		cout << "�������������루����ո��л��Ƿ���������״̬����" << endl;
	}
	break;
	case 6:
	{
		cout << "\n===== �������ù��� =====" << endl;
		cout << "1. ����Ϊ8-30���ַ�" << std::endl;
		cout << "2. ���������ĸ������1����д��Сд��" << endl;
		cout << "3. ����������֣�����1����" << endl;
		cout << "4. ���԰��������ַ�: !@#$%^&*_-+=" << endl;
		cout << "5. ���ܰ����ո�������ַ�" << endl;
		cout << "6. �������û�����ͬ" << endl;
		cout << "7. ���ܰ����������֣���1234�����ظ��ַ�����aaaa��" << endl;
		cout << "======================\n" << endl;
		cout << "�û�����" << username << endl;
		cout << "���֤�ţ�" << idNumber << endl;
		cout << "�ֻ��ţ�" << phone << endl;
		cout << "��֤�룺" << code << endl;
		cout << "���룺" << string(password.length(), '*') << endl << endl;
		cout << "����������������벻һ�£����������루����ո��л��Ƿ���������״̬��" << endl;
	}
	break;
	}
}
// ȥ���ַ���ǰ��ո�
string trim(const string& input) 
{   //auto�����ã��Զ��Ƶ���������Ϊ string::size_type���ȼ��� unsigned long���������ֶ���д��������
	//\t\n\r ���ո񣨣����Ʊ����\t�������з���\n�����س�����\r��
	
	// �ҵ���һ���ǿո��ַ���λ��
	auto first = input.find_first_not_of(" \t\n\r");
	//���ַ���ȫΪ�հ׻�Ϊ�գ����� string::npos��ֵΪ -1��������Ϊ�޷���������ʵ��Ϊ���ֵ��
	if (first == string::npos) return "";
	// �ҵ����һ���ǿո��ַ���λ��
	auto last = input.find_last_not_of(" \t\n\r");
	//������Ч�ַ��ִ�
	return input.substr(first, last - first + 1);
}
//����û����Ƿ��ظ�
bool is_username_same(int userType, const string& username)
{
	if (userType == 1)
	{   //����Ա
		Admin* current = admin_head;
		while (current != nullptr)
		{
			if (current->name == username) return true;
			current = current->next;
		}
	} 
	else
	{   //�û�
		User* current = user_head;
		while (current != nullptr)
		{
			if (current->name == username) return true;
			current = current->next;
		}
	}
	return false;
}
//��ȡ�û��������Ч����������ո񡢿�����������
bool get_vaild_name(int userType, const string& username)
{   //1.����Ƿ�Ϊ��
	if (username.empty())
	{
		register_initial_prompt(userType,1,1,1);//������ʾע������ʼ��ʾ��Ϣ
		return false;
	}
	//2.��鳤���Ƿ���5-30�ַ�֮��
	if (username.length() < 5 || username.length() > 30)
	{
		register_initial_prompt(userType,1,1,2);//������ʾע������ʼ��ʾ��Ϣ
		return false;
	}
	//3.����Ƿ�����ĸ��ͷ
	if (!isalpha(username[0]))
	{
		register_initial_prompt(userType, 1, 1, 3);//������ʾע������ʼ��ʾ��Ϣ
		return false;
	}
	//4.����Ƿ�����Ƿ��ַ��������ո�
	for (size_t i = 0; i < username.length(); i++)
	{
		char c = username[i];
		//isalnum����ַ��Ƿ���ĸ����д��Сд�������֣��������Ӽ���»���
		if ((!isalnum(c)) && (c != '_'))
		{   
			register_initial_prompt(userType, 1, 1, 4);//������ʾע������ʼ��ʾ��Ϣ
			return false;
		}
	}
	//5.����û����Ƿ��ظ�
	if (is_username_same(userType, username))
	{
		register_initial_prompt(userType, 1, 1, 5);//������ʾע������ʼ��ʾ��Ϣ
		return false;
	}
	return true;
}

//ע�Ჽ������������֤
string name_check(int userType)
{
	string input,username;
	while (true)
	{
		getline(cin, input);
		username = trim(input);// ȥ���ַ���ǰ��ո�
		if (username == "0") return username;//���롰0�����ء�0������һ������
		if (get_vaild_name(userType,username))// ��֤�û����Ƿ������·12306����
			return username;//�����򷵻���Ч�û���
	}
}
// ��������2�£�����29��
bool isLeapYear(int year)
{ // �����������ܱ�4���������ܱ�100���������ܱ�400����
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
 }
//��֤���֤�������Ч�ԣ�18λ��
bool get_vaild_id(int userType, const string& idNumber, const string& username)
{   //1.��������루ȫ�ո����س���
	if (idNumber.empty())
	{
		register_initial_prompt(userType, 1, 2, 1,username);//������ʾע������ʼ��ʾ��Ϣ
		return false;
	}
	//2.����У�飺����Ϊ18λ
	if (idNumber.length() != 18)
	{
		register_initial_prompt(userType, 1, 2, 2, username);//������ʾע������ʼ��ʾ��Ϣ
		return false;
	}
	//3.��ʽУ�飺ǰ17λ����Ϊ���֣���18λΪ���ֻ�X
	for (int i = 0; i < 17; i++)
	{   //isdigit�ж��ַ��Ƿ�Ϊ���֣�'0'-'9'��
		if (!isdigit(idNumber[i]))
		{
			register_initial_prompt(userType, 1, 2, 3, username);//������ʾע������ʼ��ʾ��Ϣ
			return false;	
		}
	}
	//4.ת����18λΪ��д������Сдx���룩
	char lastChar = toupper(idNumber[17]);
	// toupper����18λ�ַ�ת��Ϊ��Ӧ�Ĵ�д��ĸ
	if (!(isdigit(lastChar) || lastChar == 'X'))
	{
		register_initial_prompt(userType, 1, 2, 4, username);//������ʾע������ʼ��ʾ��Ϣ
		return false;
	}
	//5.У�������
	int sum= 0;
	for (int i = 0; i < 17; i++)
		// '0'��ASCII��Ϊ48��id[i]-'0'���ַ�תΪ���֣���'1'��1��
		sum +=(idNumber[i]-'0') * weights[i];//��Ȩ���
	//����������0-10����Ҳ����У��λ
	int remainder = sum % 11;//ʵ���������У����
	char actual = CheckCodes[remainder];//�����ϼ����У����
	if (lastChar != actual)
	{  //��һ���������ַ����ĳ��ȣ����ַ�c�ظ��Ĵ��������ڶ���������Ҫ�����ַ�c
		string actualStr(1, actual);//����һ������Ϊ1���ַ�����ÿ���ַ�����c����actual��
		register_initial_prompt(userType, 1, 2, 5, username, actualStr);//������ʾע������ʼ��ʾ��Ϣ
		return false;
	}
	//��֤���֤�еĳ������ڲ���
	//��ȡ���������ַ�������7-14λ����stoi�������ַ���ת��Ϊʮ����
	int year = stoi(idNumber.substr(6, 4));// ��7-10λΪ��ݣ���"2000"��
	int month = stoi(idNumber.substr(10, 2));// ��11-12λΪ�·ݣ���"01"��
    int day = stoi(idNumber.substr(12, 2));// ��13-14λΪ���ڣ���"01"��
	// ��ȡ��ǰϵͳ���ڣ�������ݺ�δ������У�飩
	time_t now = time(nullptr); // ��ȡ��1970��1��1��������������ʱ�����
	tm localTime;//tm�ṹ��洢�ֽ��ı���ʱ��
	localtime_s(&localTime, &now);// ��ʱ���ת��Ϊ����ʱ�䣨�籱��ʱ�䣩
	int currentYear = localTime.tm_year + 1900; // tm_year��1900�����ƫ��������+1900
	int currentMonth = localTime.tm_mon + 1;// tm_mon��Χ0-11����+1תΪ1-12
	int currentDay = localTime.tm_mday;// ���ڣ�1-31��
	//6.��ݷ�Χ��飨1900������
	if (year<1900 || year>currentYear)
	{    //to_string��������ֵת��Ϊ�ַ���
		register_initial_prompt(userType, 1, 2, 6, username, to_string(currentYear));//������ʾע������ʼ��ʾ��Ϣ
		return false;
	}
	//7.�·ݷ�Χ��飨1-12��
	if (month < 1 || month>12)
	{
		register_initial_prompt(userType, 1, 2, 7, username);//������ʾע������ʼ��ʾ��Ϣ
		return false;
	}
	// ������������·�Ϊ2�£���2��������Ϊ29��
	if (month == 2 && isLeapYear(year)) {
		days_in_month[2] = 29;
	}
	//8.���ڷ�Χ��飨��4�²��ܳ���30��)
	int maxday = days_in_month[month];//�����������
	if (day<1 || day>maxday)
	{
		register_initial_prompt(userType, 1, 2, 8, username, to_string(month), to_string(maxday));//������ʾע������ʼ��ʾ��Ϣ
		return false;
	}
	//9.��ֹ����δ�����ڣ�ͬ��ͬ��ͬ�ղ��ܳ�����ǰ���ڣ�
	if (year == currentYear)
	{
		if((month > currentMonth)||(month == currentMonth && day>currentDay))
		{
			register_initial_prompt(userType, 1, 2, 9, username);//������ʾע������ʼ��ʾ��Ϣ
			return false;
		}
	}
}
//ע�Ჽ���������֤����֤
string id_check(int userType, const string& username)
{
	string input, idNumber;
	while (true)
	{
		getline(cin, input);
		idNumber = trim(input);// ȥ���ַ���ǰ��ո�
		if (idNumber == "0") return idNumber;//���롰0�����ء�0������һ������
		if (get_vaild_id(userType,idNumber, username))//��֤���֤�������Ч�ԣ�18λ��
			return idNumber;//�����򷵻���Ч�û���
	}
}
// ��֤�ֻ����Ƿ���Ϲ���
bool get_vaild_phone(int userType, const string& phone, const string& username, const string& idNumber)
{  //1.��������ֻ����Ƿ�Ϊ��
	if (phone.empty())
	{
		register_initial_prompt(userType, 1, 3, 1, username,idNumber);//������ʾע������ʼ��ʾ��Ϣ
		return false;
	}
	//2.����ֻ����Ƿ�Ϊ11λ������1��ͷ
	if (phone.length() != 11||phone[0]!='1')
	{
		register_initial_prompt(userType, 1, 3, 2, username,idNumber);//������ʾע������ʼ��ʾ��Ϣ
		return false;
	}
	//3.����ֻ����Ƿ�ȫ������
	for (int i = 0; i < 11; i++)
	{   //isdigit�ж��ַ��Ƿ�Ϊ���֣�'0'-'9'��
		if (!isdigit(phone[i]))
		{
			register_initial_prompt(userType, 1, 3, 3, username,idNumber);//������ʾע������ʼ��ʾ��Ϣ
			return false;
		}
	}
}
//ע�Ჽ�������ֻ�����֤
string phone_check(int userType, const string & username, const string & idNumber)
{
	string input,phone;
	while (true)
	{
		getline(cin, input);
		phone = trim(input);// ȥ���ַ���ǰ��ո�
		if (phone == "0") return phone;//���롰0�����ء�0������һ������
		if (get_vaild_phone(userType,phone, username, idNumber))// ��֤�ֻ����Ƿ���Ϲ���
			return phone;//�����򷵻���Ч�û���
	}
}
// ����6λ���������֤��
string generateVerificationCode()
{
	string code;
	srand(time(0));// srand()�����Ե�ǰʱ������������
	for (int i = 0; i < 6; i++)
		code += char('0' + rand() % 10);//����6��0-9�����������ת�����ַ�
	return code;
}
//ע�Ჽ�������ֻ����ŷ�����֤�����֤
string code_check(int userType, const string& username, const string& idNumber, const string& phone)
{
	string input, inputcode, code;
	//�����ֻ���֤������ƴ���������������3�������֮ǰ��д��ע����Ϣ������һ����
	int maxAttempts = 3;
	for (int attempt = 1; attempt <= maxAttempts; attempt++)
	{
		if (attempt == 1)//��һ��������֤����ʾ��Ϣ����������֤����ʾ��Ϣ������ͬ
		{   // ����6λ���������֤��
			code = generateVerificationCode();
			register_initial_prompt(userType, 1, 4, 0, username, idNumber, phone, code);//ע������ʼ��ʾ��Ϣ
		}
		else //�����֤�����ʾ���ж��ٴ��������
			cout << "(��ʣ��" << maxAttempts - attempt + 1 << "�λ��ᣩ";
		getline(cin, input);
		inputcode = trim(input);// ȥ���ַ���ǰ��ո�
		if (inputcode == "0") return inputcode;//���롰0�����ء�0������һ������
		//1.���������֤���Ƿ�Ϊ��
		if (inputcode.empty())
		{
			code = generateVerificationCode();//�ٴ�����6λ���������֤��
			register_initial_prompt(userType, 1, 4, 1, username, idNumber, phone, code);//������ʾע������ʼ��ʾ��Ϣ }
			continue;
		}
		//2.���������֤���Ƿ�Ϊ6λ
		if (inputcode.length() != 6)
		{
			code = generateVerificationCode();//�ٴ�����6λ���������֤��
			register_initial_prompt(userType, 1, 4, 2, username, idNumber, phone, code);//������ʾע������ʼ��ʾ��Ϣ }
			continue;
		}
		//3.���������֤���Ƿ�ȫΪ����
		int i;
		for (i = 0; i < 6; i++)
		{
			if (!isdigit(inputcode[i]))
			{
				code = generateVerificationCode();//�ٴ�����6λ���������֤��
				register_initial_prompt(userType, 1, 4, 3, username, idNumber, phone, code);//������ʾע������ʼ��ʾ��Ϣ 
				break;
			}
		}
		if (i < 6) continue;
		//4.�����֤���Ƿ�ƥ��
		if (inputcode != code)
		{
			code = generateVerificationCode();//�ٴ�����6λ���������֤��
			register_initial_prompt(userType, 1, 4, 4, username, idNumber, phone, code);//������ʾע������ʼ��ʾ��Ϣ 
			continue;
		}
		return inputcode;
	}
	return "-1";//��ʱ��������������֤�붼�Ǵ��󣬷���-1�����֮ǰ��д��ע����Ϣ����ǿ�Ʒ�����һ����
	
}
//�����������ʹ�����ʾ
void clearCurrentLine()
{
	cout << "\r";  // �ص�����
	for (int i = 0; i < 80; i++) cout << " ";  // �ÿո񸲸�
	cout << "\r";  // �ٴλص�����
}
// ����ַ��Ƿ�Ϊ����������ַ�
bool isAllowedSpecialChar(char c) 
{
	const char* allowedChars = "!@#$%^&*_-+=";
	for (int i = 0; allowedChars[i] != '\0'; i++)
	{
		if (c == allowedChars[i]) 
			return true;
	}
	return false;
}
// ����Ƿ�����������֣���1234��8765��
bool is_continuous_number(const string& password)
{
	const int MIN_LENGTH = 4;  // ��С��������
	const int len = password.length();

	if (len < MIN_LENGTH) return false;  // ���Ȳ���ֱ�ӷ���false

	for (int i = 0; i <= len - MIN_LENGTH; i++) {  // �������п��ܵ���ʼλ��
		bool increasing = true;  // �������
		bool decreasing = true;  // ����ݼ�
		for (int j = 0; j < MIN_LENGTH - 1; j++) 
		{  // ���������4���ַ�
			 char current = password[i + j];
			char next = password[i + j + 1];
			if (!isdigit(current) || !isdigit(next)) 
			{
				increasing = false;//�����֣����ǵ�������
				decreasing = false;//�����֣����ǵݼ�����
				break;
			}
			if (next != current + 1) increasing = false;//�������������
			if (next != current - 1) decreasing = false;//������ݼ�����
		}
		if (increasing || decreasing) return true;  // �ǵ�����ݼ�����
	}
	return false;  // δ�ҵ�������������
}
//����Ƿ��ظ��ַ�
bool is_repeated_chars(const string& password)
{   const int len = password.length();
    const int minRepeat = 4;//����ظ��ַ�Ϊ3���ܳ���3
	if (len < minRepeat) return false;//���Ȳ���ֱ�ӷ���false
	for (int i = 0; i <= len - minRepeat; i++)
	{  // �������п��ܵ���ʼλ��
		char first = password[i];
		bool allSame = true;  // ���������ַ���ͬ
		for (int j = 1; j < minRepeat; j++) {  // �������ַ�
			if (password[i + j] != first) 
			{
				allSame = false; // ���ֲ�ͬ�ַ�
				break;
			}
		}
		if (allSame) return true;  // �ҵ��ظ�����
	}
	return false;  // δ�ҵ��ظ�����
}

//��֤�����Ƿ���Ϲ���
string password_check(int userType,const string& username, const string& idNumber, const string& phone, const string& code)
{
	while (true)
	{
		string password;
		char ch;
		//����1�����ʼ�������������������ʾ�Ǻ�
		int isHidden = 1;
		while ((ch = _getch()) != '\r')//ѭ����ȡ�ַ�ֱ����Enter��
		{   // �����������벢��ʾΪ�Ǻ�
			if (ch == '\b')//�����˸��
			{
				if (!password.empty()) // ����ǿ�ʱ����ɾ��
				{
					password.pop_back();// ɾ�����һ���ַ�
					cout << "\b \b";// �����ˣ������ַ����ٻ���
				}
			}
			//����ո�����л�������ʾ״̬������������ʾ�ǺŻ��߲�������ʾ��ʵ�����ַ���
			else if (ch == ' ')
			{   //isHidden�ԼӴӶ���Ϊ��������ż���л�������ʾ״̬
				isHidden++;
				if(isHidden%2==0)
				{   //isHidden��ż��ʱ��ʾ����������ֱ����ʾ����
					cout << "\r" << password;
				}
				else
				{   //isHidden������ʱ��ʾ����������ʾ�Ǻ�
					cout << "\r" << string(password.length(), '*');
				}
			}
			else if (isalnum(ch) || isAllowedSpecialChar(ch))
			{   // �Ϸ��ַ�����ӵ����벢��ʾ�Ǻ�
				password += ch;
				if (isHidden % 2 == 0) cout << ch;
				else cout << "*";
			}
			else
			{   //�Ƿ��ַ������������ʾ��Ϣ
				password.clear(); // �������
				cout << "  ���󣬺��зǷ��ַ�������1�����ճ����Ѿ���������벢����������";
				Sleep(1000);//// ��ͣ����1�룬���û���ʱ���Ķ���ʾ
				clearCurrentLine();//�ٴ������ʾ
			}
		}
		//1.���������뻻�з�
		if (password.empty())
		{
			register_initial_prompt(userType, 1, 5, 1, username, idNumber, phone, code);//������ʾע������ʼ��ʾ��Ϣ }
			continue;
		}
		if (password == "0") return password;//������һ����
		//2.���ȼ��
		if (password.length() < 8 || password.length() > 30)
		{
			register_initial_prompt(userType, 1, 5, 2, username, idNumber, phone, code);//������ʾע������ʼ��ʾ��Ϣ }
			continue;
		}
		//3.�������û�����ͬ
		if (password == username)
		{
			register_initial_prompt(userType, 1, 5, 3, username, idNumber, phone, code);//������ʾע������ʼ��ʾ��Ϣ }
			continue;
		}
		// �ַ���ϼ��
		bool hasLetter = false;
		bool hasDigit = false;
		for (int i = 0; i < password.length(); i++) {
			if (isalpha(password[i])) hasLetter = true;// ����Ƿ�����ĸ
			if (isdigit(password[i])) hasDigit = true;// ����Ƿ�������
		}
		//4.��������Ƿ��������һ����ĸ
		if (!hasLetter)
		{
			register_initial_prompt(userType, 1, 5, 4, username, idNumber, phone, code);//������ʾע������ʼ��ʾ��Ϣ }
			continue;
		}
		//5.��������Ƿ��������һ������
		if (!hasDigit) {
			register_initial_prompt(userType, 1, 5, 5, username, idNumber, phone, code);//������ʾע������ʼ��ʾ��Ϣ }
			continue;
		}
		//6.����Ƿ��������֣���1234��8765��
		if (is_continuous_number(password))
		{
			register_initial_prompt(userType, 1, 5, 6, username, idNumber, phone, code);//������ʾע������ʼ��ʾ��Ϣ }
			continue;
		}
		//7.����Ƿ��ظ��ַ�
		if (is_repeated_chars(password))
		{
			register_initial_prompt(userType, 1, 5, 7, username, idNumber, phone, code);//������ʾע������ʼ��ʾ��Ϣ }
			continue;
		}
		cout << endl;
		while (true)
		{
			cout << "���ٴ�����������ȷ��(����ո��л��Ƿ���������״̬)��"<<endl;
			string confirmPassword = showstar();//����������ʾ�Ǻ�;
			if (confirmPassword == "0") return "0"; // ��������һ����
			if (confirmPassword != password)
			{
				register_initial_prompt(userType, 1, 6, 0, username, idNumber, phone, code,password);//������ʾע������ʼ��ʾ��Ϣ }
			}
			else
			{
				cout << endl;
				break;
			}
		}
		return password;
	}
}
//������֤
int get_vaild_int(int min, int max,int menu_again_choice)
{
	string input;
	int num;
	while (true)
	{
		cout << "���������֣�" << min << "-" << max << ")��";
		getline(cin, input);//��ȡ����
		if (input.empty())//��������
		{
			menu_again(menu_again_choice);
			cout<< "������󣬲���ֱ������س�����\n";
			continue;
		}
		//��ʽ��֤
		istringstream ss(input);
		if (ss >> num && (ss >> ws).eof())//������ȡ�����������������������пհ׼���Ƿ���ĩβ
		{
			if (num >= min && num <= max)//��Χ��֤
			{
				return num;
			}
			menu_again(menu_again_choice);
			cout << "���������ֵ����" << min << "��" << max << "֮�䣡\n";
		}
		else
		{
			menu_again(menu_again_choice);
			cout << "�����ʽ��Ч������Ϊ�����֣�\n";

		}
	}
}
//ȷ��Ŀǰ����
int isConfirm(int& prompt)
{
	string confirm;
	int num;
	getline(cin, confirm);
	if (confirm.empty())//��������
	{
		prompt = 1;
		return -1;
	}
	//��ʽ��֤
	istringstream ss(confirm);
	if (ss >> num && (ss >> ws).eof())//������ȡ�����������������������пհ׼���Ƿ���ĩβ
	{
		if (num >= 0 && num <= 1) return num;
		else
		{
			prompt = 2;
			return -1;
		}
	}
	else
	{
		prompt = 3;
		return -1;
	}
}
//��¼ʱ��ȡ������֧���л���ʾ״̬
string getPassword()
{
	string password;
	char ch;
	//����1�����ʼ�������������������ʾ�Ǻ�
	int isHidden = 1;
	while ((ch = _getch()) != '\r')//ѭ����ȡ�ַ�ֱ����Enter��
	{   // �����������벢��ʾΪ�Ǻ�
		if (ch == '\b')//�����˸��
		{
			if (!password.empty()) // ����ǿ�ʱ����ɾ��
			{
				password.pop_back();// ɾ�����һ���ַ�
				cout << "\b \b";// �����ˣ������ַ����ٻ���
			}
		}
		//����ո�����л�������ʾ״̬������������ʾ�ǺŻ��߲�������ʾ��ʵ�����ַ���
		else if (ch == ' ')
		{   //isHidden�ԼӴӶ���Ϊ��������ż���л�������ʾ״̬
			isHidden++;
			if (isHidden % 2 == 0)
			{   //isHidden��ż��ʱ��ʾ����������ֱ����ʾ����
				cout << "\r" << password;
			}
			else
			{   //isHidden������ʱ��ʾ����������ʾ�Ǻ�
				cout << "\r" << string(password.length(), '*');
			}
		}
		else
		{   // �Ϸ��ַ�����ӵ����벢��ʾ�Ǻ�
			password += ch;
			if (isHidden % 2 == 0) cout << ch;
			else cout << "*";
		}
	}
	return password;
}
//��¼�����ʼ��ʾ��Ϣ
void login_initial_prompt(int userType, int step, int prompt, const string& username)
{
	system("cls");// ����
	cout << "��Ʊ����ϵͳ->" << (userType == 1 ? "ϵͳ����Ա" : "��Ʊ�û�") << "����->��¼" << endl;
	cout << "�����롰0��,�򷵻���һ��" << endl<<endl;
	if (prompt == 1) cout << "�û������������" << endl;
	if (step == 1)
	{
        cout << "�����������û�����" << endl;
	}
	else
	{
		cout << "�û�����" << username << endl;
		cout << "�������������루����ո��л��Ƿ���������״̬��" << endl;
	}
}
//��鳵�κ��Ƿ���Ϲ���
bool number_check(const string& number, int& prompt)
{   //1.��鳵�κ��Ƿ�Ϊ��
	if (number.empty())
	{
		prompt = 1;
		return false;
	}
	//2.��鳵�κ��Ƿ��Ѵ���
	Train* current = train_head;
	while (current != nullptr)
	{
		if (current->number == number)
		{
			prompt = 2;
			return false;
		}
		current = current->next;
	}
	//3.��鳵�κų����Ƿ�Ϊ2-5λ
	if (number.length() < 2 || number.length() > 5)
	{
		prompt = 3;
		return false;
	}
	//4.��鳵�κ����ַ��Ƿ�Ϊָ����ĸ
	char firstChar = toupper(number[0]);//����Сдת���ɴ�д
	if (firstChar != 'G' && firstChar != 'D' && firstChar != 'C'
		&& firstChar != 'Z' && firstChar != 'T' && firstChar != 'K')
	{
		prompt = 4;
		return false;
	}
	//5.��鳵�κ�ʣ���ַ��Ƿ�Ϊ����
	for (size_t i = 1; i < number.length(); i++)
	{
		if (!isdigit(number[i]))
		{
			prompt = 5;
			return false;
		}
	}
	return true;
}
//���վ���Ƿ���Ϲ���		
bool station_check(const string& name, int& prompt)
{   //1.���վ���Ƿ�Ϊ��
	if (name.empty())
	{
		prompt = 1;
		return false;
	}
	//2.������ʾ��Ȳ�����Ƿ�����Ƿ��ַ�
	int width = 0;
	bool isVaild = true;//����վ������
	//����վ������ʾ��ȣ������ַ����=2��Ӣ���ַ���
	//������Ƿ������Ӣ����ĸ��ASCII�ַ�
	/*ֻ�ܴ�ſ����ַ��Ŀ�ȴӶ���������򣬲�����ȫ�ж������ַ�
	 Unicode ��Χ	       UTF-8������ʽ	           ռ���ֽ���
     U+0000-U+007F	  0xxxxxxx                              1
     U+0080-U+07FF	  110xxxxx 10xxxxxx	                    2
     U+0800-U+FFFF	  1110xxxx 10xxxxxx 10xxxxxx	        3
     U+10000-U+10FFFF 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx	4*/
	for (size_t i = 0; i < name.length();)
	{   //ASCII�ַ���ʮ����0-127��
		if ((name[i] & 0x80) == 0)
		{   //����ǲ���Ӣ����ĸ��ASCII�ַ�
			if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z')))
			{
				isVaild = false;
				break;
			}
			width++;//Ӣ��һ����ʾ���
			i++;//Ӣ��һ���ֽ�
		}
		//�����ַ������Ϊ2
		else if ((name[i] & 0xE0) == 0xC0)
		{   //2�ֽ�UTF-8�ַ�
			width += 2;
			i += 2;
		}
		else if ((name[i] & 0xF0) == 0xE0)
		{   //3�ֽ�UTF-8�ַ�
			width += 2;
			i += 3;
		}
		else if ((name[i] & 0xF8) == 0xF0)
		{   //4�ֽ�UTF-8�ַ�
			width += 2;
			i += 4;
		}
		else
		{
			width++;
			i++;
		}
	}
	if(width<1||width>11)
	{
		prompt = 2;
		return false;
	}
	return true;
}
//���ʱ���ַ�����ȫΪ����
bool isAllDigitals(const string& timeStr)
{
	for (size_t i = 0; i < timeStr.length(); i++)
	{
		if (!isdigit(timeStr[i])) return false;
	}
	return true;
}
//����ʱ���ַ���������ʽ
bool time_check(const string& time, int& prompt, DataTime& dt)
{   //1.���ʱ���Ƿ�Ϊ��
	if (time.empty())
	{
		prompt = 1;
		return false;
	}
	//2.���ʱ���ַ��������Ƿ�Ϊ16���ͷָ���λ��
	if(time.length()!=16||time[4]!='-' || time[7] != '-' || 
	   time[10] != ' ' || time[13] != ':')
	{
		prompt = 2;
		return false;
	}
	//��ȡ������ʱ��
	string yearStr = time.substr(0,4);
	string monthStr = time.substr(5,2);
	string dayStr = time.substr(8,2);
	string hourStr = time.substr(11,2);
	string minuteStr = time.substr(14,2);
	//���ʱ���ַ�����ȫΪ����
	if (!isAllDigitals(yearStr) || !isAllDigitals(monthStr)
		|| !isAllDigitals(dayStr) || !isAllDigitals(hourStr) || !isAllDigitals(minuteStr))
	{
		prompt = 2;
		return false;
	}
	//ת��������
	dt.year = stoi(yearStr);
	dt.month = stoi(monthStr);
	dt.day = stoi(dayStr);
	dt.hour = stoi(hourStr);
	dt.minute = stoi(minuteStr);
	//��������Ƿ���Ч
	//�����ж�
	if (isLeapYear(dt.year)) days_in_month[2] = 29;
	else days_in_month[2] = 28;
	//����·�
	if (dt.month < 1 || dt.month>12)
	{
		prompt = 3;
		return false;
	}
	//������ڷ�Χ
	if (dt.day < 1 || dt.day>days_in_month[dt.month])
	{
		prompt = 4;
		return false;
	}
    //���ʱ��
	if (dt.hour<0 || dt.hour>24||dt.minute<0||dt.minute>60)
	{
		prompt = 5;
		return false;
	}
	return true;
}
//ת������������DataTimeTemp�ṹ��ת��Ϊtime_t���ͣ�
time_t  dataTime_to_timeT(const DataTime& dt)
{   //��������ʼ��tm�ṹ��
	tm timeStruct = {};
	//����������ʱ����
	timeStruct.tm_year = dt.year - 1900;// tm_year��1900�꿪ʼ����
	timeStruct.tm_mon = dt.month - 1;// tm_mon��Χ��0-11
	timeStruct.tm_mday = dt.day;
	timeStruct.tm_hour = dt.hour;
	timeStruct.tm_min = dt.minute;
	timeStruct.tm_sec = 0;
	//����mktime����װ��Ϊtime_t
	return mktime(&timeStruct);
	/*�Զ�����ʱ��������ʱ
      ��֤�����Ƿ���Ч�����磬�Զ����� 2 �� 30 �����ַǷ����ڣ�
      �� tm �ṹ��ת��Ϊ�� 1970-01-01 ��ʼ��������time_t ���ͣ�*/
}
//������ʱ���Ƿ���Ϲ���
bool dep_time_check(const string& deptime, int& prompt)
{   //����ʱ���ַ���������ʽ
	DataTime dt = { 0 };
	if (!time_check(deptime, prompt,dt)) return false;
	//������ʱ���Ƿ�����Ч��Χ֮�ࣨ��ǰʱ��֮���Ҳ�����14�죩
	time_t now = time(nullptr);//��ȡϵͳ��ǰʱ��
	//ת������������DataTime�ṹ��ת��Ϊtime_t���ͣ�
	time_t dep_time = dataTime_to_timeT(dt);
	//����14����ʱ��
	time_t max_dep_time= now + 14 * 24 * 60 * 60;
	//������ʱ���ǲ����ڵ�ʱ��֮��    //////////���Ҳ�������ǰʱ����14��
	if (dep_time <= now)                // || dep_time > max_dep_time
	{
		prompt = 6;
		return false;
	}
	return true;
}
////��ʱ���ַ���ת��ΪDataTime�ṹ��
//DataTime string_to_Datatime(const string& time)
//{
//	DataTime dt = { 0 };
//	istringstream iss(time);
//	string str;
//	//�ָ��ַ�����ת��Ϊ����
//	getline(iss, str, '-');
//	dt.year = stoi(str);
//	getline(iss, str, '-');
//	dt.month = stoi(str);
//	getline(iss, str, ' ');
//	dt.day = stoi(str);
//	getline(iss, str, ':');
//	dt.hour = stoi(str);
//	getline(iss, str);
//	dt.minute = stoi(str);
//	return dt;
//}

// ��DataTime��ʽ��Ϊ�̶���ȵ��ַ���
string formatTime(const DataTime& time) {
	ostringstream oss;
	oss << setfill('0') // ��������ַ�Ϊ0
		<< setw(4) << time.year << "-"
		<< setw(2) << time.month << "-"
		<< setw(2) << time.day << " "
		<< setw(2) << time.hour << ":"
		<< setw(2) << time.minute;
	return oss.str();
}

//��鵽��ʱ���Ƿ���Ϲ���
bool dest_time_check(const DataTime& deptime, const string& desttime, int& prompt)
{   //������ʱ��ת������������DataTime�ṹ��ת��Ϊtime_t���ͣ�
	time_t dep_time = dataTime_to_timeT(deptime);
	DataTime dt = { 0 };
	if (!time_check(desttime, prompt, dt)) return false;
	//������ʱ��ת������������DataTime�ṹ��ת��Ϊtime_t���ͣ�
	time_t dest_time = dataTime_to_timeT(dt);
	//�������ʱ��͵���ʱ����
	const int minIntervalSeconds = 30 * 60;//��Сʱ����30����
	const int maxIntervalSeconds = 72 * 60 * 60;//���ʱ����72Сʱ
	const long long interval = dest_time - dep_time;//����ʱ��͵���ʱ����
	//��鵽��ʱ���Ƿ��ڳ���ʱ��֮�󣬲���ʱ��������Ч��Χ��
	if (interval<minIntervalSeconds || interval>maxIntervalSeconds)
	{
		prompt = 7;
		return false;

	}
	return true;
}

		/*
cout << "����������������������������������������������������������������������������������������������������������������������" << endl;
cout << "��  b                     ���β�ѯ���                                                                              ��" << endl;
cout << "���������������������Щ����������������������Щ����������������������Щ��������������������������Щ�������������������" << endl;
cout << "�� ����             �� ����վ               �� ����վ               �� ʱ��                     �� ��Ʊ             ��" << endl;
cout << "���������������������੤���������������������੤���������������������੤�������������������������੤������������������" << endl;
*/       
