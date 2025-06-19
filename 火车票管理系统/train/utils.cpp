#include"utils.h"
#include"user.h"
#include"admin.h"
#include<iomanip>
//全局变量定义
// 身份证前17位权值数组（GB 11643-1999标准）
//权值用于计算校验码（即身份证号第18位），每位数字乘以对应权值后求和
const int weights[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
// 国家标准规定的权值，用于校验码计算，顺序不可改变

// 校验码映射表：余数0-10对应字符
// 余数 = (加权和) % 11，例如余数2对应'X'（罗马数字10）
const char CheckCodes[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
// 余数0对应CHECK_CODES[0]='1'，余数2对应'X'（罗马数字10）

// 每月天数数组（索引0无效，1-12对应月份）
// 平年2月默认28天，闰年2月在验证时单独处理
int days_in_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//输出特定数量的字符
void print_specific_char(int type)
{
	switch (type)
	{
	case 1:cout << "┬"; break;
	case 2:cout << "┼"; break;
	case 3:cout << "┴"; break;
	}
}
//输出指定数量的重复字符
void print_repeated_char(int type)
{    //┌──┐ │ ├  ┬ ┤ ┼   ┴  └──────────────┘
	//车次号宽度
	for (int i = 0; i < number_width; i++)
		cout <<"─";
	print_specific_char(type);
	//出发站或终点站宽度
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < station_width; j++)
			cout << "─";
		print_specific_char(type);
	}
	//出发时间或到达时间宽度
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < time_width; j++)
			cout << "─";
		print_specific_char(type);
	}
	//座位数宽度
	for (int i = 0; i < seat_width; i++)
		cout << "─";
}
//将DataTime格式化为固定宽度的字符串
//string formatTime(const DataTime& time)
//{
//	ostringstream oss;
//	oss << setfill('0') //设置填充字符为0
//		<< setw(4) << time.year << "-"
//		<< setw(2) << time.month << "-"
//		<< setw(2) << time.day << " "
//		<< setw(2) << time.hour << ":"
//		<< setw(2) << time.minute;
//	oss << setfill(' ');//重置填充字符为空格
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
//显示主菜单
void show_main_menu()
{
	// 强制刷新输出缓冲区
	cout.flush();
	cout << "===火车票管理系统===" << endl;
	cout << "1.管理员登录或注册" << endl;
	cout << "2.用户登录或注册" << endl;
	cout << "3.退出系统" << endl;
	cout.flush();  // 再次刷新
}
//显示系统管理员菜单
void show_admin_menu()
{
	cout << "火车票管理系统->系统管理员界面" << endl;
	cout << "请选择您的操作：" << endl;
	cout << "1.注册" << endl;
	cout << "2.登录" << endl;
	cout << "3.返回上一层" << endl;
}
// 显示用户菜单
void show_user_menu()
{
	cout << "火车票管理系统->购票用户界面" << endl;
	cout << "请选择您的操作：" << endl;
	cout << "1.注册" << endl;
	cout << "2.登录" << endl;
	cout << "3.返回上一层" << endl;
}
//重新显示界面初始菜单
void menu_again(int menu_again_choice)
{
	system("cls");// 清屏
	switch (menu_again_choice)
	{
	   case 1:show_main_menu(); break;//显示主菜单
	   case 2:show_admin_menu(); break;//显示系统管理员菜单
	   case 3:show_user_menu(); break;//显示购票用户菜单
	   case 4: login_admin_menu(); break;//显示登录后管理员服务器功能菜单    
	   case 5: login_user_menu(); break;//显示登录后用户功能菜单
	}
}
//输入密码显示星号
string showstar()
{
	string str;
	char ch;
	//奇数1代表初始输入密码会隐藏密码显示星号
	int isHidden = 1;
	while ((ch = _getch()) != '\r')//循环读取字符直到按Enter键
	{   // 隐藏密码输入并显示为星号
		if (ch == '\b')//处理退格键
		{
			if (!str.empty()) // 密码非空时才能删除
			{
				str.pop_back();// 删除最后一个字符
				cout << "\b \b";// 光标回退，覆盖字符，再回退
			}
		}
		//输入空格代表切换密码显示状态（隐藏密码显示星号或者不隐藏显示真实密码字符）
		else if (ch == ' ')
		{   //isHidden自加从而变为奇数或者偶数切换密码显示状态
			isHidden++;
			if (isHidden % 2 == 0)
			{   //isHidden是偶数时表示不隐藏密码直接显示密码
				cout << "\r" << str;
			}
			else
			{   //isHidden是奇数时表示隐藏密码显示星号
				cout << "\r" << string(str.length(), '*');
			}
		}
		else
		{   //显示确认密码的星号
			str += ch;
			if (isHidden % 2 == 0) cout << ch;
			else cout << "*";
		}
	}
	return str;
 }
//注册界面初始提示信息
void register_initial_prompt(int userType, int cls, int step, int prompt, const string& username, const string& idNumber, const string& phone, const string& code, const string& password)
{
	if (cls == 1) system("cls");// 清屏
	cout << "火车票管理系统->" << (userType == 1 ? "系统管理员" : "购票用户") << "界面->注册" << endl;
	cout << "若输入“0”,则返回上一层" << endl;
	switch (step)
	{
		//注册界面第一个步骤输入用户名提示信息
	case 1:
	{
		cout << "=== 用户名验证规则 ===" << endl;
		cout << "验证规则：" << endl;
		cout << "1. 每个用户名段长度为5-30个字符" << endl;
		cout << "2. 每个段必须以字母开头" << endl;
		cout << "3. 只能包含字母、数字和下划线" << endl << endl;
		switch (prompt)
		{
		case 1:cout << "错误：用户名不能为空" << endl; break;
		case 2:cout << "错误：用户名长度必须为6-30个字符" << endl; break;
		case 3:cout << "错误：用户名必须以字母开头" << endl; break;
		case 4:cout << "错误：包含非法字符" << endl; break;
		case 5:cout << "错误：您填写的用户名已被其他用户使用" << endl; break;
		}
		cout << "请输入您的用户名：" << endl;
	}
	break;
	case 2:
	{
		cout << "=== 身份证号码输入规则 ===" << endl;
		cout << "【基本格式要求】" << endl;
		cout << "  1. 必须为18位字符（仅支持新版18位身份证，不支持15位旧版）" << endl;
		cout << "  2. 前17位必须全为数字，第18位为数字或大写‘X’（小写x会自动转为大写）" << endl;

		cout << "\n【出生日期规则】" << endl;
		cout << "  3. 年份范围：1900年至当前年份" << endl; // 需提前获取当前年份
		cout << "  4. 月份范围：01-12（如01表示1月，不足两位补0）" << endl;
		cout << "  5. 日期需符合月份规则：" << endl;
		cout << "     - 4/6/9/11月最多30天，1/3/5/7/8/10/12月最多31天" << endl;
		cout << "     - 平年2月最多28天，闰年2月最多29天" << endl;

		cout << "\n【输入处理规则】" << endl;
		cout << "  6. 自动去除前后空格，但中间不可有空格（如输入“ 110...X ”会自动处理为“110...X”）" << endl;
		cout << "  7. 示例：11010120000101123X（出生日期：2000年1月1日，校验码X）" << endl << endl;
		switch (prompt)
		{
		case 1:cout << "错误：身份证号不能为空" << endl; break;
		case 2:cout << "错误：身份证号码必须为18位" << endl; break;
		case 3:cout << "错误：前17位必须全为数字" << endl; break;
		case 4:cout << "错误：第18位必须为数字或X" << endl; break;
		case 5:cout << "错误：错误：校验码(即身份证号第18位)错误（应为" << idNumber << "）" << endl; break;
		case 6:cout << "错误：年份必须在1900-" << idNumber << "之间" << endl; break;
		case 7:cout << "错误：月份必须在1-12月之间" << endl; break;
		case 8:cout << "错误：" << idNumber << "月的天数范围必须在1-" << phone << "天之间" << endl; break;
		case 9:cout << "错误：不能输入未来日期" << endl; break;
		}
		cout << "用户名：" << username << endl;
		cout << "请输入您的身份证号：" << endl;
	}
	break;
	case 3:
	{
		cout << "=== 手机号码输入规则 ===" << endl;
		cout << " 格式要求：" << endl;
		cout << "1.需为11位数字，以1开头（如13800138000）" << endl;
		cout << "2.自动去除前后空格，但中间不可有空格" << endl;
		cout << "3.需通过短信验证码验证" << endl;
		cout << "示例：18612345678（输入0返回上一步）" << endl << endl;
		switch (prompt)
		{
		case 1:cout << "错误：手机号不能为空" << endl; break;
		case 2:cout << "错误：手机号必须为11位数字并且以1开头" << endl; break;
		case 3:cout << "错误：手机号必须全为数字" << endl; break;
		}
		cout << "用户名：" << username << endl;
		cout << "身份证号：" << idNumber << endl;
		cout << "请输入您的手机号：" << endl;
	}
	break;
	case 4:
	{
		cout << endl << "输入手机验证码的限制次数，如果连续输错3次则清空之前填写的注册信息并且强制返回上一界面" << endl;
		switch (prompt)
		{
		case 1:cout << "错误：验证码不能为空" << endl; break;
		case 2:cout << "错误：验证码必须为6位数字" << endl; break;
		case 3:cout << "错误：验证码必须全为数字" << endl; break;
		case 4:cout << "错误：输入验证码不匹配" << endl; break;
		}
		if (prompt >= 1) cout << endl << "已重新发送新的验证码" << endl;
		cout << "【铁路客服】您的验证码是：" << code << endl;
		cout << "用户名：" << username << endl;
		cout << "身份证号：" << idNumber << endl;
		cout << "手机号：" << phone << endl;
		cout << "请输入您的验证码：" << endl;
	}
	break;
	case 5:
	{
		cout << "\n===== 密码设置规则 =====" << endl;
		cout << "1. 长度为8-30个字符" << std::endl;
		cout << "2. 必须包含字母（至少1个大写或小写）" << endl;
		cout << "3. 必须包含数字（至少1个）" << endl;
		cout << "4. 可以包含特殊字符: !@#$%^&*_-+=" << endl;
		cout << "5. 不能包含空格或中文字符" << endl;
		cout << "6. 不能与用户名相同" << endl;
		cout << "7. 不能包含连续数字（如1234）或重复字符（如aaaa）" << endl;
		cout << "======================\n" << endl;
		switch (prompt)
		{
		case 1:cout << "错误：密码不能为空" << endl; break;
		case 2:cout << "错误：密码长度必须为8-30个字符" << endl; break;
		case 3:cout << "错误：密码不能与用户名相同" << endl; break;
		case 4:cout << "错误：密码必须包含至少一个字母" << endl; break;
		case 5:cout << "错误：密码必须包含至少一个数字" << endl; break;
		case 6:cout << "错误：密码强度较弱，不能包含连续的数字序列（如1234或8765）" << endl; break;
		case 7:cout << "错误：密码强度较弱，不能包含过长的重复字符（如aaaa或1111）" << endl; break;
		}
		cout << "用户名：" << username << endl;
		cout << "身份证号：" << idNumber << endl;
		cout << "手机号：" << phone << endl;
		cout << "验证码：" <<code<< endl;
		cout << "请输入您的密码（输入空格切换是否隐藏密码状态）：" << endl;
	}
	break;
	case 6:
	{
		cout << "\n===== 密码设置规则 =====" << endl;
		cout << "1. 长度为8-30个字符" << std::endl;
		cout << "2. 必须包含字母（至少1个大写或小写）" << endl;
		cout << "3. 必须包含数字（至少1个）" << endl;
		cout << "4. 可以包含特殊字符: !@#$%^&*_-+=" << endl;
		cout << "5. 不能包含空格或中文字符" << endl;
		cout << "6. 不能与用户名相同" << endl;
		cout << "7. 不能包含连续数字（如1234）或重复字符（如aaaa）" << endl;
		cout << "======================\n" << endl;
		cout << "用户名：" << username << endl;
		cout << "身份证号：" << idNumber << endl;
		cout << "手机号：" << phone << endl;
		cout << "验证码：" << code << endl;
		cout << "密码：" << string(password.length(), '*') << endl << endl;
		cout << "错误：两次输入的密码不一致！请重新输入（输入空格切换是否隐藏密码状态）" << endl;
	}
	break;
	}
}
// 去除字符串前后空格
string trim(const string& input) 
{   //auto的作用：自动推导变量类型为 string::size_type（等价于 unsigned long），避免手动书写复杂类型
	//\t\n\r 含空格（）、制表符（\t）、换行符（\n）、回车符（\r）
	
	// 找到第一个非空格字符的位置
	auto first = input.find_first_not_of(" \t\n\r");
	//若字符串全为空白或为空，返回 string::npos（值为 -1，但类型为无符号整数，实际为最大值）
	if (first == string::npos) return "";
	// 找到最后一个非空格字符的位置
	auto last = input.find_last_not_of(" \t\n\r");
	//返回有效字符字串
	return input.substr(first, last - first + 1);
}
//检查用户名是否重复
bool is_username_same(int userType, const string& username)
{
	if (userType == 1)
	{   //管理员
		Admin* current = admin_head;
		while (current != nullptr)
		{
			if (current->name == username) return true;
			current = current->next;
		}
	} 
	else
	{   //用户
		User* current = user_head;
		while (current != nullptr)
		{
			if (current->name == username) return true;
			current = current->next;
		}
	}
	return false;
}
//获取用户输入的有效姓名（处理空格、空输入等情况）
bool get_vaild_name(int userType, const string& username)
{   //1.检查是否为空
	if (username.empty())
	{
		register_initial_prompt(userType,1,1,1);//重新显示注册界面初始提示信息
		return false;
	}
	//2.检查长度是否在5-30字符之间
	if (username.length() < 5 || username.length() > 30)
	{
		register_initial_prompt(userType,1,1,2);//重新显示注册界面初始提示信息
		return false;
	}
	//3.检查是否以字母开头
	if (!isalpha(username[0]))
	{
		register_initial_prompt(userType, 1, 1, 3);//重新显示注册界面初始提示信息
		return false;
	}
	//4.检查是否包含非法字符（包括空格）
	for (size_t i = 0; i < username.length(); i++)
	{
		char c = username[i];
		//isalnum检查字符是否字母（大写或小写）或数字，并且增加检查下划线
		if ((!isalnum(c)) && (c != '_'))
		{   
			register_initial_prompt(userType, 1, 1, 4);//重新显示注册界面初始提示信息
			return false;
		}
	}
	//5.检查用户名是否重复
	if (is_username_same(userType, username))
	{
		register_initial_prompt(userType, 1, 1, 5);//重新显示注册界面初始提示信息
		return false;
	}
	return true;
}

//注册步骤输入名字验证
string name_check(int userType)
{
	string input,username;
	while (true)
	{
		getline(cin, input);
		username = trim(input);// 去除字符串前后空格
		if (username == "0") return username;//输入“0”返回“0”回上一级函数
		if (get_vaild_name(userType,username))// 验证用户名是否符合铁路12306规则
			return username;//符合则返回有效用户名
	}
}
// 处理闰年2月，允许29天
bool isLeapYear(int year)
{ // 闰年条件：能被4整除但不能被100整除，或能被400整除
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
 }
//验证身份证号码的有效性（18位）
bool get_vaild_id(int userType, const string& idNumber, const string& username)
{   //1.处理空输入（全空格或仅回车）
	if (idNumber.empty())
	{
		register_initial_prompt(userType, 1, 2, 1,username);//重新显示注册界面初始提示信息
		return false;
	}
	//2.长度校验：必须为18位
	if (idNumber.length() != 18)
	{
		register_initial_prompt(userType, 1, 2, 2, username);//重新显示注册界面初始提示信息
		return false;
	}
	//3.格式校验：前17位必须为数字，第18位为数字或X
	for (int i = 0; i < 17; i++)
	{   //isdigit判断字符是否为数字（'0'-'9'）
		if (!isdigit(idNumber[i]))
		{
			register_initial_prompt(userType, 1, 2, 3, username);//重新显示注册界面初始提示信息
			return false;	
		}
	}
	//4.转换第18位为大写（处理小写x输入）
	char lastChar = toupper(idNumber[17]);
	// toupper将第18位字符转换为对应的大写字母
	if (!(isdigit(lastChar) || lastChar == 'X'))
	{
		register_initial_prompt(userType, 1, 2, 4, username);//重新显示注册界面初始提示信息
		return false;
	}
	//5.校验码计算
	int sum= 0;
	for (int i = 0; i < 17; i++)
		// '0'的ASCII码为48，id[i]-'0'将字符转为数字（如'1'→1）
		sum +=(idNumber[i]-'0') * weights[i];//加权求和
	//计算余数（0-10），也就是校验位
	int remainder = sum % 11;//实际上输入的校验码
	char actual = CheckCodes[remainder];//理论上计算的校验码
	if (lastChar != actual)
	{  //第一个参数是字符串的长度（即字符c重复的次数），第二个参数是要填充的字符c
		string actualStr(1, actual);//创建一个长度为1的字符串，每个字符都是c（即actual）
		register_initial_prompt(userType, 1, 2, 5, username, actualStr);//重新显示注册界面初始提示信息
		return false;
	}
	//验证身份证中的出生日期部分
	//提取出生日期字符串（第7-14位），stoi函数将字符串转化为十进制
	int year = stoi(idNumber.substr(6, 4));// 第7-10位为年份（如"2000"）
	int month = stoi(idNumber.substr(10, 2));// 第11-12位为月份（如"01"）
    int day = stoi(idNumber.substr(12, 2));// 第13-14位为日期（如"01"）
	// 获取当前系统日期（用于年份和未来日期校验）
	time_t now = time(nullptr); // 获取自1970年1月1日以来的秒数（时间戳）
	tm localTime;//tm结构体存储分解后的本地时间
	localtime_s(&localTime, &now);// 将时间戳转换为本地时间（如北京时间）
	int currentYear = localTime.tm_year + 1900; // tm_year是1900年起的偏移量，需+1900
	int currentMonth = localTime.tm_mon + 1;// tm_mon范围0-11，需+1转为1-12
	int currentDay = localTime.tm_mday;// 日期（1-31）
	//6.年份范围检查（1900年至今）
	if (year<1900 || year>currentYear)
	{    //to_string函数将数值转换为字符串
		register_initial_prompt(userType, 1, 2, 6, username, to_string(currentYear));//重新显示注册界面初始提示信息
		return false;
	}
	//7.月份范围检查（1-12）
	if (month < 1 || month>12)
	{
		register_initial_prompt(userType, 1, 2, 7, username);//重新显示注册界面初始提示信息
		return false;
	}
	// 如果是闰年且月份为2月，将2月天数设为29天
	if (month == 2 && isLeapYear(year)) {
		days_in_month[2] = 29;
	}
	//8.日期范围检查（如4月不能超过30天)
	int maxday = days_in_month[month];//该月最多天数
	if (day<1 || day>maxday)
	{
		register_initial_prompt(userType, 1, 2, 8, username, to_string(month), to_string(maxday));//重新显示注册界面初始提示信息
		return false;
	}
	//9.防止输入未来日期（同年同月同日不能超过当前日期）
	if (year == currentYear)
	{
		if((month > currentMonth)||(month == currentMonth && day>currentDay))
		{
			register_initial_prompt(userType, 1, 2, 9, username);//重新显示注册界面初始提示信息
			return false;
		}
	}
}
//注册步骤输入身份证号验证
string id_check(int userType, const string& username)
{
	string input, idNumber;
	while (true)
	{
		getline(cin, input);
		idNumber = trim(input);// 去除字符串前后空格
		if (idNumber == "0") return idNumber;//输入“0”返回“0”回上一级函数
		if (get_vaild_id(userType,idNumber, username))//验证身份证号码的有效性（18位）
			return idNumber;//符合则返回有效用户名
	}
}
// 验证手机号是否符合规则
bool get_vaild_phone(int userType, const string& phone, const string& username, const string& idNumber)
{  //1.检查输入手机号是否为空
	if (phone.empty())
	{
		register_initial_prompt(userType, 1, 3, 1, username,idNumber);//重新显示注册界面初始提示信息
		return false;
	}
	//2.检查手机号是否为11位并且以1开头
	if (phone.length() != 11||phone[0]!='1')
	{
		register_initial_prompt(userType, 1, 3, 2, username,idNumber);//重新显示注册界面初始提示信息
		return false;
	}
	//3.检查手机号是否全是数字
	for (int i = 0; i < 11; i++)
	{   //isdigit判断字符是否为数字（'0'-'9'）
		if (!isdigit(phone[i]))
		{
			register_initial_prompt(userType, 1, 3, 3, username,idNumber);//重新显示注册界面初始提示信息
			return false;
		}
	}
}
//注册步骤输入手机号验证
string phone_check(int userType, const string & username, const string & idNumber)
{
	string input,phone;
	while (true)
	{
		getline(cin, input);
		phone = trim(input);// 去除字符串前后空格
		if (phone == "0") return phone;//输入“0”返回“0”回上一级函数
		if (get_vaild_phone(userType,phone, username, idNumber))// 验证手机号是否符合规则
			return phone;//符合则返回有效用户名
	}
}
// 生成6位随机数字验证码
string generateVerificationCode()
{
	string code;
	srand(time(0));// srand()函数以当前时间产生随机种子
	for (int i = 0; i < 6; i++)
		code += char('0' + rand() % 10);//产生6个0-9的随机数并且转换成字符
	return code;
}
//注册步骤输入手机短信发来验证码的验证
string code_check(int userType, const string& username, const string& idNumber, const string& phone)
{
	string input, inputcode, code;
	//输入手机验证码的限制次数，如果连续输错3次则清空之前填写的注册信息返回上一界面
	int maxAttempts = 3;
	for (int attempt = 1; attempt <= maxAttempts; attempt++)
	{
		if (attempt == 1)//第一次输入验证码提示信息与后面输错验证码提示信息有所不同
		{   // 生成6位随机数字验证码
			code = generateVerificationCode();
			register_initial_prompt(userType, 1, 4, 0, username, idNumber, phone, code);//注册界面初始提示信息
		}
		else //输错验证码后提示还有多少次输入机会
			cout << "(还剩下" << maxAttempts - attempt + 1 << "次机会）";
		getline(cin, input);
		inputcode = trim(input);// 去除字符串前后空格
		if (inputcode == "0") return inputcode;//输入“0”返回“0”回上一级函数
		//1.检查输入验证码是否为空
		if (inputcode.empty())
		{
			code = generateVerificationCode();//再次生成6位随机数字验证码
			register_initial_prompt(userType, 1, 4, 1, username, idNumber, phone, code);//重新显示注册界面初始提示信息 }
			continue;
		}
		//2.检查输入验证码是否为6位
		if (inputcode.length() != 6)
		{
			code = generateVerificationCode();//再次生成6位随机数字验证码
			register_initial_prompt(userType, 1, 4, 2, username, idNumber, phone, code);//重新显示注册界面初始提示信息 }
			continue;
		}
		//3.检查输入验证码是否全为数字
		int i;
		for (i = 0; i < 6; i++)
		{
			if (!isdigit(inputcode[i]))
			{
				code = generateVerificationCode();//再次生成6位随机数字验证码
				register_initial_prompt(userType, 1, 4, 3, username, idNumber, phone, code);//重新显示注册界面初始提示信息 
				break;
			}
		}
		if (i < 6) continue;
		//4.检查验证码是否匹配
		if (inputcode != code)
		{
			code = generateVerificationCode();//再次生成6位随机数字验证码
			register_initial_prompt(userType, 1, 4, 4, username, idNumber, phone, code);//重新显示注册界面初始提示信息 
			continue;
		}
		return inputcode;
	}
	return "-1";//此时连续输入三次验证码都是错误，返回-1，清空之前填写的注册信息并且强制返回上一界面
	
}
//清除已填密码和错误提示
void clearCurrentLine()
{
	cout << "\r";  // 回到行首
	for (int i = 0; i < 80; i++) cout << " ";  // 用空格覆盖
	cout << "\r";  // 再次回到行首
}
// 检查字符是否为允许的特殊字符
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
// 检查是否包含连续数字（如1234或8765）
bool is_continuous_number(const string& password)
{
	const int MIN_LENGTH = 4;  // 最小连续长度
	const int len = password.length();

	if (len < MIN_LENGTH) return false;  // 长度不足直接返回false

	for (int i = 0; i <= len - MIN_LENGTH; i++) {  // 遍历所有可能的起始位置
		bool increasing = true;  // 假设递增
		bool decreasing = true;  // 假设递减
		for (int j = 0; j < MIN_LENGTH - 1; j++) 
		{  // 检查连续的4个字符
			 char current = password[i + j];
			char next = password[i + j + 1];
			if (!isdigit(current) || !isdigit(next)) 
			{
				increasing = false;//非数字，不是递增序列
				decreasing = false;//非数字，不是递减序列
				break;
			}
			if (next != current + 1) increasing = false;//不满足递增条件
			if (next != current - 1) decreasing = false;//不满足递减条件
		}
		if (increasing || decreasing) return true;  // 是递增或递减序列
	}
	return false;  // 未找到连续数字序列
}
//检查是否重复字符
bool is_repeated_chars(const string& password)
{   const int len = password.length();
    const int minRepeat = 4;//最多重复字符为3不能超过3
	if (len < minRepeat) return false;//长度不足直接返回false
	for (int i = 0; i <= len - minRepeat; i++)
	{  // 遍历所有可能的起始位置
		char first = password[i];
		bool allSame = true;  // 假设所有字符相同
		for (int j = 1; j < minRepeat; j++) {  // 检查后续字符
			if (password[i + j] != first) 
			{
				allSame = false; // 发现不同字符
				break;
			}
		}
		if (allSame) return true;  // 找到重复序列
	}
	return false;  // 未找到重复序列
}

//验证密码是否符合规则
string password_check(int userType,const string& username, const string& idNumber, const string& phone, const string& code)
{
	while (true)
	{
		string password;
		char ch;
		//奇数1代表初始输入密码会隐藏密码显示星号
		int isHidden = 1;
		while ((ch = _getch()) != '\r')//循环读取字符直到按Enter键
		{   // 隐藏密码输入并显示为星号
			if (ch == '\b')//处理退格键
			{
				if (!password.empty()) // 密码非空时才能删除
				{
					password.pop_back();// 删除最后一个字符
					cout << "\b \b";// 光标回退，覆盖字符，再回退
				}
			}
			//输入空格代表切换密码显示状态（隐藏密码显示星号或者不隐藏显示真实密码字符）
			else if (ch == ' ')
			{   //isHidden自加从而变为奇数或者偶数切换密码显示状态
				isHidden++;
				if(isHidden%2==0)
				{   //isHidden是偶数时表示不隐藏密码直接显示密码
					cout << "\r" << password;
				}
				else
				{   //isHidden是奇数时表示隐藏密码显示星号
					cout << "\r" << string(password.length(), '*');
				}
			}
			else if (isalnum(ch) || isAllowedSpecialChar(ch))
			{   // 合法字符：添加到密码并显示星号
				password += ch;
				if (isHidden % 2 == 0) cout << ch;
				else cout << "*";
			}
			else
			{   //非法字符，输出错误提示信息
				password.clear(); // 清空密码
				cout << "  错误，含有非法字符，将于1秒后清空撤回已经输入的密码并且重新输入";
				Sleep(1000);//// 暂停程序1秒，让用户有时间阅读提示
				clearCurrentLine();//再次清除提示
			}
		}
		//1.处理单纯输入换行符
		if (password.empty())
		{
			register_initial_prompt(userType, 1, 5, 1, username, idNumber, phone, code);//重新显示注册界面初始提示信息 }
			continue;
		}
		if (password == "0") return password;//返回上一界面
		//2.长度检查
		if (password.length() < 8 || password.length() > 30)
		{
			register_initial_prompt(userType, 1, 5, 2, username, idNumber, phone, code);//重新显示注册界面初始提示信息 }
			continue;
		}
		//3.不能与用户名相同
		if (password == username)
		{
			register_initial_prompt(userType, 1, 5, 3, username, idNumber, phone, code);//重新显示注册界面初始提示信息 }
			continue;
		}
		// 字符组合检查
		bool hasLetter = false;
		bool hasDigit = false;
		for (int i = 0; i < password.length(); i++) {
			if (isalpha(password[i])) hasLetter = true;// 检查是否有字母
			if (isdigit(password[i])) hasDigit = true;// 检查是否有数字
		}
		//4.检查密码是否包含至少一个字母
		if (!hasLetter)
		{
			register_initial_prompt(userType, 1, 5, 4, username, idNumber, phone, code);//重新显示注册界面初始提示信息 }
			continue;
		}
		//5.检查密码是否包含至少一个数字
		if (!hasDigit) {
			register_initial_prompt(userType, 1, 5, 5, username, idNumber, phone, code);//重新显示注册界面初始提示信息 }
			continue;
		}
		//6.检查是否连续数字（如1234或8765）
		if (is_continuous_number(password))
		{
			register_initial_prompt(userType, 1, 5, 6, username, idNumber, phone, code);//重新显示注册界面初始提示信息 }
			continue;
		}
		//7.检查是否重复字符
		if (is_repeated_chars(password))
		{
			register_initial_prompt(userType, 1, 5, 7, username, idNumber, phone, code);//重新显示注册界面初始提示信息 }
			continue;
		}
		cout << endl;
		while (true)
		{
			cout << "请再次输入密码以确认(输入空格切换是否隐藏密码状态)："<<endl;
			string confirmPassword = showstar();//输入密码显示星号;
			if (confirmPassword == "0") return "0"; // 处理返回上一界面
			if (confirmPassword != password)
			{
				register_initial_prompt(userType, 1, 6, 0, username, idNumber, phone, code,password);//重新显示注册界面初始提示信息 }
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
//输入验证
int get_vaild_int(int min, int max,int menu_again_choice)
{
	string input;
	int num;
	while (true)
	{
		cout << "请输入数字（" << min << "-" << max << ")：";
		getline(cin, input);//读取输入
		if (input.empty())//检查空输入
		{
			menu_again(menu_again_choice);
			cout<< "输入错误，不能直接输入回车键！\n";
			continue;
		}
		//格式验证
		istringstream ss(input);
		if (ss >> num && (ss >> ws).eof())//尝试提取整数并且跳过输入多余的所有空白检查是否到流末尾
		{
			if (num >= min && num <= max)//范围验证
			{
				return num;
			}
			menu_again(menu_again_choice);
			cout << "输入错误，数值需在" << min << "到" << max << "之间！\n";
		}
		else
		{
			menu_again(menu_again_choice);
			cout << "输入格式无效，必须为纯数字！\n";

		}
	}
}
//确认目前操作
int isConfirm(int& prompt)
{
	string confirm;
	int num;
	getline(cin, confirm);
	if (confirm.empty())//检查空输入
	{
		prompt = 1;
		return -1;
	}
	//格式验证
	istringstream ss(confirm);
	if (ss >> num && (ss >> ws).eof())//尝试提取整数并且跳过输入多余的所有空白检查是否到流末尾
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
//登录时获取密码且支持切换显示状态
string getPassword()
{
	string password;
	char ch;
	//奇数1代表初始输入密码会隐藏密码显示星号
	int isHidden = 1;
	while ((ch = _getch()) != '\r')//循环读取字符直到按Enter键
	{   // 隐藏密码输入并显示为星号
		if (ch == '\b')//处理退格键
		{
			if (!password.empty()) // 密码非空时才能删除
			{
				password.pop_back();// 删除最后一个字符
				cout << "\b \b";// 光标回退，覆盖字符，再回退
			}
		}
		//输入空格代表切换密码显示状态（隐藏密码显示星号或者不隐藏显示真实密码字符）
		else if (ch == ' ')
		{   //isHidden自加从而变为奇数或者偶数切换密码显示状态
			isHidden++;
			if (isHidden % 2 == 0)
			{   //isHidden是偶数时表示不隐藏密码直接显示密码
				cout << "\r" << password;
			}
			else
			{   //isHidden是奇数时表示隐藏密码显示星号
				cout << "\r" << string(password.length(), '*');
			}
		}
		else
		{   // 合法字符：添加到密码并显示星号
			password += ch;
			if (isHidden % 2 == 0) cout << ch;
			else cout << "*";
		}
	}
	return password;
}
//登录界面初始提示信息
void login_initial_prompt(int userType, int step, int prompt, const string& username)
{
	system("cls");// 清屏
	cout << "火车票管理系统->" << (userType == 1 ? "系统管理员" : "购票用户") << "界面->登录" << endl;
	cout << "若输入“0”,则返回上一层" << endl<<endl;
	if (prompt == 1) cout << "用户名或密码错误！" << endl;
	if (step == 1)
	{
        cout << "请输入您的用户名：" << endl;
	}
	else
	{
		cout << "用户名：" << username << endl;
		cout << "请输入您的密码（输入空格切换是否隐藏密码状态）" << endl;
	}
}
//检查车次号是否符合规则
bool number_check(const string& number, int& prompt)
{   //1.检查车次号是否为空
	if (number.empty())
	{
		prompt = 1;
		return false;
	}
	//2.检查车次号是否已存在
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
	//3.检查车次号长度是否为2-5位
	if (number.length() < 2 || number.length() > 5)
	{
		prompt = 3;
		return false;
	}
	//4.检查车次号首字符是否为指定字母
	char firstChar = toupper(number[0]);//若是小写转换成大写
	if (firstChar != 'G' && firstChar != 'D' && firstChar != 'C'
		&& firstChar != 'Z' && firstChar != 'T' && firstChar != 'K')
	{
		prompt = 4;
		return false;
	}
	//5.检查车次号剩余字符是否为数字
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
//检查站名是否符合规则		
bool station_check(const string& name, int& prompt)
{   //1.检查站名是否为空
	if (name.empty())
	{
		prompt = 1;
		return false;
	}
	//2.计算显示宽度并检查是否包含非法字符
	int width = 0;
	bool isVaild = true;//假设站名合理
	//计算站名的显示宽度（中文字符宽度=2个英文字符）
	//并检查是否包含非英文字母的ASCII字符
	/*只能大概控制字符的宽度从而不超过框框，不能完全判断中文字符
	 Unicode 范围	       UTF-8编码形式	           占用字节数
     U+0000-U+007F	  0xxxxxxx                              1
     U+0080-U+07FF	  110xxxxx 10xxxxxx	                    2
     U+0800-U+FFFF	  1110xxxx 10xxxxxx 10xxxxxx	        3
     U+10000-U+10FFFF 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx	4*/
	for (size_t i = 0; i < name.length();)
	{   //ASCII字符（十进制0-127）
		if ((name[i] & 0x80) == 0)
		{   //检查是不是英文字母的ASCII字符
			if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z')))
			{
				isVaild = false;
				break;
			}
			width++;//英文一个显示宽度
			i++;//英文一个字节
		}
		//中文字符，宽度为2
		else if ((name[i] & 0xE0) == 0xC0)
		{   //2字节UTF-8字符
			width += 2;
			i += 2;
		}
		else if ((name[i] & 0xF0) == 0xE0)
		{   //3字节UTF-8字符
			width += 2;
			i += 3;
		}
		else if ((name[i] & 0xF8) == 0xF0)
		{   //4字节UTF-8字符
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
//检查时间字符串是全为数字
bool isAllDigitals(const string& timeStr)
{
	for (size_t i = 0; i < timeStr.length(); i++)
	{
		if (!isdigit(timeStr[i])) return false;
	}
	return true;
}
//解析时间字符串并检查格式
bool time_check(const string& time, int& prompt, DataTime& dt)
{   //1.检查时间是否为空
	if (time.empty())
	{
		prompt = 1;
		return false;
	}
	//2.检查时间字符串长度是否为16个和分隔符位置
	if(time.length()!=16||time[4]!='-' || time[7] != '-' || 
	   time[10] != ' ' || time[13] != ':')
	{
		prompt = 2;
		return false;
	}
	//提取年月日时分
	string yearStr = time.substr(0,4);
	string monthStr = time.substr(5,2);
	string dayStr = time.substr(8,2);
	string hourStr = time.substr(11,2);
	string minuteStr = time.substr(14,2);
	//检查时间字符串是全为数字
	if (!isAllDigitals(yearStr) || !isAllDigitals(monthStr)
		|| !isAllDigitals(dayStr) || !isAllDigitals(hourStr) || !isAllDigitals(minuteStr))
	{
		prompt = 2;
		return false;
	}
	//转换成整数
	dt.year = stoi(yearStr);
	dt.month = stoi(monthStr);
	dt.day = stoi(dayStr);
	dt.hour = stoi(hourStr);
	dt.minute = stoi(minuteStr);
	//检查日期是否有效
	//闰年判断
	if (isLeapYear(dt.year)) days_in_month[2] = 29;
	else days_in_month[2] = 28;
	//检查月份
	if (dt.month < 1 || dt.month>12)
	{
		prompt = 3;
		return false;
	}
	//检查日期范围
	if (dt.day < 1 || dt.day>days_in_month[dt.month])
	{
		prompt = 4;
		return false;
	}
    //检查时间
	if (dt.hour<0 || dt.hour>24||dt.minute<0||dt.minute>60)
	{
		prompt = 5;
		return false;
	}
	return true;
}
//转换成秒数（将DataTimeTemp结构体转换为time_t类型）
time_t  dataTime_to_timeT(const DataTime& dt)
{   //创建并初始化tm结构体
	tm timeStruct = {};
	//设置年月日时分秒
	timeStruct.tm_year = dt.year - 1900;// tm_year从1900年开始计数
	timeStruct.tm_mon = dt.month - 1;// tm_mon范围是0-11
	timeStruct.tm_mday = dt.day;
	timeStruct.tm_hour = dt.hour;
	timeStruct.tm_min = dt.minute;
	timeStruct.tm_sec = 0;
	//调用mktime函数装欢为time_t
	return mktime(&timeStruct);
	/*自动处理时区和夏令时
      验证日期是否有效（例如，自动修正 2 月 30 日这种非法日期）
      将 tm 结构体转换为从 1970-01-01 开始的秒数（time_t 类型）*/
}
//检查出发时间是否符合规则
bool dep_time_check(const string& deptime, int& prompt)
{   //解析时间字符串并检查格式
	DataTime dt = { 0 };
	if (!time_check(deptime, prompt,dt)) return false;
	//检查出发时间是否在有效范围之类（当前时间之后且不超过14天）
	time_t now = time(nullptr);//获取系统当前时间
	//转换成秒数（将DataTime结构体转换为time_t类型）
	time_t dep_time = dataTime_to_timeT(dt);
	//计算14天后的时间
	time_t max_dep_time= now + 14 * 24 * 60 * 60;
	//检查出发时间是不是在当时间之后    //////////并且不超过当前时间后的14天
	if (dep_time <= now)                // || dep_time > max_dep_time
	{
		prompt = 6;
		return false;
	}
	return true;
}
////将时间字符串转换为DataTime结构体
//DataTime string_to_Datatime(const string& time)
//{
//	DataTime dt = { 0 };
//	istringstream iss(time);
//	string str;
//	//分割字符串并转换为整数
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

// 将DataTime格式化为固定宽度的字符串
string formatTime(const DataTime& time) {
	ostringstream oss;
	oss << setfill('0') // 设置填充字符为0
		<< setw(4) << time.year << "-"
		<< setw(2) << time.month << "-"
		<< setw(2) << time.day << " "
		<< setw(2) << time.hour << ":"
		<< setw(2) << time.minute;
	return oss.str();
}

//检查到达时间是否符合规则
bool dest_time_check(const DataTime& deptime, const string& desttime, int& prompt)
{   //将出发时间转换成秒数（将DataTime结构体转换为time_t类型）
	time_t dep_time = dataTime_to_timeT(deptime);
	DataTime dt = { 0 };
	if (!time_check(desttime, prompt, dt)) return false;
	//将到达时间转换成秒数（将DataTime结构体转换为time_t类型）
	time_t dest_time = dataTime_to_timeT(dt);
	//计算出发时间和到达时间间隔
	const int minIntervalSeconds = 30 * 60;//最小时间间隔30分钟
	const int maxIntervalSeconds = 72 * 60 * 60;//最大时间间隔72小时
	const long long interval = dest_time - dep_time;//出发时间和到达时间间隔
	//检查到达时间是否在出发时间之后，并且时间间隔在有效范围内
	if (interval<minIntervalSeconds || interval>maxIntervalSeconds)
	{
		prompt = 7;
		return false;

	}
	return true;
}

		/*
cout << "┌─────────────────────────────────────────────────────────┐" << endl;
cout << "│  b                     车次查询结果                                                                              │" << endl;
cout << "├─────────┬───────────┬───────────┬─────────────┬─────────┤" << endl;
cout << "│ 车次             │ 出发站               │ 到达站               │ 时间                     │ 余票             │" << endl;
cout << "├─────────┼───────────┼───────────┼─────────────┼─────────┤" << endl;
*/       
