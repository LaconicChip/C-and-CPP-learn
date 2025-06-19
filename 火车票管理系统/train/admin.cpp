#include "admin.h"
#include "utils.h"
#include"save.h"
#include <iostream>
//管理员添加车票信息的初始提示
void admin_functions_initial_prompt(int function, int step, int prompt, const TrainInfo& info)//管理员添加车票信息的初始提示
{
    system("cls");// 清屏
    cout << "火车票管理系统->系统管理员界面->登录->管理员服务器功能->";
    switch (function)
    {
    case 1:cout << "添加车票信息" << endl; break;
    case 2:cout << "删除车票信息" << endl; break;
    case 3:cout << "修改车票信息" << endl; break;
    case 4:cout << "查询车票信息" << endl; break;
    }
    cout << "若输入“0”,则返回上一层" << endl<<endl;
    //┌──┐ │ ├  ┬ ┤ ┼  └──────────────┘
    Train* current = train_head;
    if (current == nullptr)
    {
        cout << "暂无车次信息！" << endl << endl;
        
    }
    else
    {   //输出表头
        cout << "┌";
        print_repeated_char(1);
        cout << "┐" << endl;
        cout << "│" << left << setw(number_width) << "车次号"
            << "│" << left << setw(station_width) << "出发站"
            << "│" << left << setw(station_width) << "终点站"
            << "│" << left << setw(time_width) << "出发时间"
            << "│" << left << setw(time_width) << "到达时间"
            << "│" << left << setw(seat_width) << "余票"
            << "│" << endl;
        cout << "├";
        print_repeated_char(2);
        cout << "┤" << endl;
        //输出数据行
        while (current != nullptr)
        {
            cout << "│" << left << setw(number_width) << current->number
                << "│" << left << setw(station_width) << current->dep
                << "│" << left << setw(station_width) << current->dest
                << "│" << left << setw(time_width) << formatTime(current->dep_time)
                << "│" << left << setw(time_width) << formatTime(current->dest_time)
                << "│" << current->remain_seats << "/" << current->total_seats << "│" << endl;
            if (current->next != nullptr)
            {
                cout << "├";
                print_repeated_char(2);
                cout << "┤" << endl;
            }
            current = current->next;
        }
        cout << "└";
        print_repeated_char(3);
        cout << "┘" << endl;
    }
    //显示已输入正确的添加车票信息
    cout << "已输入正确的信息：" << endl;
    if ((!info.number.empty())&&(step >= 2)) cout << "车次号：" << info.number << endl;
    if ((!info.dep.empty()) && (step >= 3)) cout << "出发站：" << info.dep << endl;
    if ((!info.dest.empty()) && (step >= 4)) cout << "终点站：" << info.dest << endl;
    if (info.dep_time.year != 0&&step>=5)
    {
        cout << "出发时间：" << info.dep_time.year << "年";
        cout << right<<setfill('0') << setw(2) << info.dep_time.month << "月";
        cout << right << setfill('0') << setw(2) << info.dep_time.day << "日";
        cout << right << setfill('0') << setw(2) << info.dep_time.hour << ":";
        cout << right << setfill('0') << setw(2) << info.dep_time.minute << endl;
        cout << setfill(' '); //重置填充字符
    }
    if (info.dest_time.year != 0 && step >= 6)
    {
        cout << "到达时间：" << info.dest_time.year << "年";
        cout << right << setfill('0') << setw(2) << info.dest_time.month << "月";
        cout << right << setfill('0') << setw(2) << info.dest_time.day << "日";
        cout << right << setfill('0') << setw(2) << info.dest_time.hour << ":";
        cout << right << setfill('0') << setw(2) << info.dest_time.minute << endl;
        cout << setfill(' '); //重置填充字符
    }
    if (info.total_seats != 0) cout << "总座位数：" << info.total_seats <<"(座位默认800个)"<<endl << endl;
    switch (function)
    {
    case 1:
    { //根据步骤显示不同的提示信息
        switch (step)
        {
        case 1:
        {   //显示车次号规则（始终显示在顶部）
            cout << "================================== 车次号规则 ==================================" << endl;
            cout << "1. 车次号必须以以下字母开头：G（高铁）、D（动车）、C（城际）、Z（直达）、T（特快）、K（快速）" << endl;
            cout << "2. 字母后必须跟随1-4位数字（如G101、D3215、K218）" << std::endl;
            cout << "3.  车次号不能为空且必须唯一，不能与已存在的车次重复" << std::endl;
            cout << "================================================================================" << endl << endl;
            switch (prompt)
            {
            case 1:cout << "错误：车次号不能为空！" << endl; break;
            case 2:cout << "错误：车次号不能与已存在的车次重复！" << endl; break;
            case 3:cout << "错误：车次号长度必须为2-5个字符字符！" << endl; break;
            case 4:cout << "错误：车次号必须必须以G/D/C/Z/T/K开头！" << endl; break;
            case 5:cout << "错误：车次号除首字符以外其它字符必须全为数字" << endl; break;
            }
            cout << "请输入添加火车的车次号：" << endl;
        }
        break;
        case 2:
        case 3:
        {   //显示站名规则
            cout << "=== 出发站验证环节 ===" << endl;
            cout << "站点名称规则：" << endl;
            cout << "1. 可以包含中文和英文字母" << endl;
            cout << "2. 显示宽度为1-11个英文字符宽度（约1-5个汉字）" << endl;
            cout << "3. 不允许使用除英文字母外的ASCII字符（如标点符号、特殊字符等）" <<endl;
            cout << "4. 示例：北京(2汉字)、Beijing(7英文)、上海虹桥(4汉字)" <<endl<<endl;
            switch (prompt)
            {
            case 1:cout << "错误:" << (step == 2 ? "出发" : "终点") << "站：" <<"不能为空！" << endl; break;
            case 2:cout << "错误：站名必须是4-10个英文或2-5个中文！" << endl; break;
            }
            cout << "请输入添加火车的" << (step == 2 ? "出发" : "终点") << "站：" << endl;
        }
        break;
        case 4:
        case 5:
        {   //出发时间和到达时间规则
            cout << "========== 时间输入规则 ==========" << endl;
            cout << "1. 时间格式必须为: YYYY-MM-DD HH:MM（记得DD和HH中间是一个空格）" << endl;
            cout << "2. 出发时间必须在当前时间之后" << endl;
            cout << "3. 到达时间必须在出发时间之后" << endl;
            cout << "4. 出发时间与到达时间间隔至少30分钟" << endl;
            cout << "5. 出发时间与到达时间间隔最多72小时" << endl;
            cout << "==================================" << endl << endl;
            switch (prompt)
            {
            case 1:cout << "错误：" << (step == 4 ? "出发" : "到达") << "时间不能为空" << endl; break;
            case 2:cout << "错误：时间格式没有完全写成“YYYY-MM-DD HH:MM”（记得DD和HH中间是一个空格）"<< endl; break;
            case 3:cout << "错误：月份必须是1-12月" << endl; break;
            case 4:cout << "错误：该月日期没有此天数" << endl; break;
            case 5:cout << "错误：小时或者分钟不对" << endl; break;
            case 6:cout << "错误：出发时间必须在当前时间之后" << endl; break;
            case 7:cout << "错误： 出发时间与到达时间间隔至少30分钟,最多72小时" << endl; break;
            }
            cout << "请输入添加火车的" << (step == 4 ? "出发" : "到达") << "时间：" << endl;
        }
        break;
        case 6:
        {   switch(prompt)
            {   //确认添加车票操作错误提示
            case 1:cout << "错误：不能直接输入回车键！" << endl; break;
            case 2:cout << "错误：数字只能输入1或0！" << endl; break;
            case 3:cout << "错误：只能输入纯数字！" << endl; break;
            }
            cout << "请确认以下操作的数字编号：" << endl;
            cout << "1.确认" << endl;
            cout << "0.返回上一界面" << endl;
        }
        break;
        }
     }
    break;
    }
   
   
}


//显示登录后管理员服务器功能菜单
void login_admin_menu()
{
    system("cls");// 清屏
    cout << "火车票管理系统->系统管理员界面->登录->管理员服务器功能"<<endl;
    cout << "┌──────────────┐" << endl;
    cout << "│1.添加车票信息│" << endl;
    cout << "├──────────────┤" << endl;
    cout << "│2.删除车票信息│" << endl;
    cout << "├──────────────┤" << endl;
    cout << "│3.修改车票信息│" << endl;
    cout << "├──────────────┤" << endl;
    cout << "│4.查询车票信息│" << endl;
    cout << "├──────────────┤" << endl;
    cout << "│5.添加用户信息│" << endl;
    cout << "├──────────────┤" << endl;
    cout << "│6.返回上一界面│" << endl;
    cout << "└──────────────┘" << endl;

}
//管理员服务器功能
void admin_functions()
{
    while (true)
    {
        login_admin_menu();//显示登录后管理员服务器功能菜单
        int login_admin_menu_choice = get_vaild_int(1, 6, 4);// 登录后管理员服务器功能菜单输入验证
        switch (login_admin_menu_choice)
        {
        case 1:
        {
            system("cls");// 清屏
            add_train_ticket();//添加车票信息
            break;
        }
        case 2:
        {
            system("cls");// 清屏
            delete_train_ticket();//删除车票信息
            break;
        }
        case 3:
        {
            system("cls");// 清屏
            modify_train_ticket();//修改车票信息
            break;
        }
        case 4:
        {
            system("cls");// 清屏
            search_train_ticket();//查询车票信息
            break;
        }
        case 5:
        {
            system("cls");// 清屏
            add_user_info();//添加用户信息
            break;
        }
        case 6:
        {
            save_all_data();
            system("cls");// 清屏
            return;//返回上一界面
        }
        }
    }
}
// 系统管理员登录
void admin_log_in() 
{
    login_initial_prompt(1, 1, 0);//登录界面初始提示信息
    while (true)
    {
        string username,password;
        getline(cin, username);
        username= trim(username);// 去除字符串前后空格
        if (username == "0")//若输入0则返回上一步
        {
            system("cls");// 清屏
            return;
        }
        login_initial_prompt(1,2,0,username);//登录界面初始提示信息
        password = getPassword();//登录时获取密码且支持切换显示状态
        if (password == "0")//若输入0则返回上一步
        {
            system("cls");// 清屏
            return;
        }
        //判断输入的用户名和密码是否能匹配已有的注册信息
        bool success = false;//假设不匹配，也就是登录失败
        Admin* current = admin_head;
        while (current != nullptr)
        {
            if (current->name == username && current->password == password)
            {   //成功匹配到已有的注册信息，登录成功
                success = true;
                break;
            }
            current = current->next;
        }
        if (success)
        {   
            system("cls");// 清屏
            admin_functions();//管理员服务器功能
            //函数增加
            return;
        }
        login_initial_prompt(1, 1, 1);//登录界面初始提示信息
    }
}

// 系统管理员注册
void admin_register() 
{
    // 步骤1：输入用户名
    register_initial_prompt(1,0,1,0);//注册界面初始提示信息
    string username= name_check(1);
    if (username == "0")//注册步骤输入名字验证(若输入0则返回上一步)
    {
        system("cls");// 清屏
        return;
    }
    // 步骤2：输入身份证号（传递username）
    register_initial_prompt(1, 1, 2, 0,username);//注册界面初始提示信息
    string idNumber = id_check(1,username);
    if (idNumber == "0")//注册步骤输入身份证号验证(若输入0则返回上一步)
    {
        system("cls");// 清屏
        return;
    }
    // 步骤3：输入手机号（传递username，idNumber）
    register_initial_prompt(1, 1, 3, 0, username,idNumber);//注册界面初始提示信息
    string phone = phone_check(1, username,idNumber);
    if (phone == "0")//注册步骤输入身份证号验证(若输入0则返回上一步)
    {
        system("cls");// 清屏
        return;
    }
    // 步骤4：输入手机短信发来的验证码（传递username，idNumber，phone）
    string code = code_check(1,username, idNumber, phone);
    if (code == "0")//注册步骤输入身份证号验证(若输入0则返回上一步)
    {
        system("cls");// 清屏
        return;
    }
    if (code == "-1")//此时连续输入三次验证吗都是错误，清空之前填写的注册信息并且强制返回上一界面
    {
        for (int i = 3; i > 0; i--)
        {
            cout << "\r您一共连续输错三次验证码，" << i << "秒后将清空之前填写的注册信息并且强制返回上一界面";
            cout.flush();//立即将缓冲区中的数据输出到控制台，保证数字能及时显示
            Sleep(1000);//暂停1秒
        }
        system("cls");// 清屏
        return;
    }
    // 步骤5：输入密码并且再次确认输入密码（传递username，idNumber，phone，code）
    register_initial_prompt(1, 1, 5, 0, username, idNumber,phone,code);//注册界面初始提示信息
    string password = password_check(1,username, idNumber, phone,code);
    if (password == "0")//注册步骤输入身份证号验证(若输入0则返回上一步)
    {
        system("cls");// 清屏
        return;
    }
    // 创建新的管理员节点
    Admin* newAdmin = new Admin;
    newAdmin->name = username;
    newAdmin->id = idNumber;
    newAdmin->phone = phone;
    newAdmin->password = password;
    newAdmin->next = nullptr;
    // 将新管理员添加到管理员链表的末尾
    if (admin_head == nullptr) 
    {
        admin_head = newAdmin;
        admin_tail = newAdmin;// 初始化头尾指针
    }
    else 
    {
        admin_tail->next = newAdmin;//尾指针直接连接新节点
        admin_tail = newAdmin;// 更新尾指针
    }
   cout << "注册成功！" << endl;
   for (int i = 3; i > 0; i--)
   {
       cout << "\r即将在" << i << "秒后返回上一界面";
       cout.flush();//立即将缓冲区中的数据输出到控制台，保证数字能及时显示
       Sleep(1000);//暂停1秒
   }
   system("cls");// 清屏
}
// 系统管理员界面
void admin_interface() {
    while (true)
    {
        show_admin_menu();// 显示系统管理员菜单
        int admin_menu_choice = get_vaild_int(1,3,2);// 系统管理员菜单输入验证
        switch (admin_menu_choice)
        {
           case 1:
           {
               system("cls");// 清屏
               admin_register();
               break;
           }
           case 2:
           {
               system("cls");// 清屏
               admin_log_in();
               break;
           }
            case 3:
            {
                system("cls");// 清屏
                return;
            }
         }
    }
}

// 添加用户信息
void add_user_info() {
    User* newUser = new User;
    cout << "请输入用户名：";
    getline(cin, newUser->name);
    cout << "请输入身份证号码：";
    getline(cin, newUser->id);
    cout << "请输入手机号：";
    getline(cin, newUser->phone);
    cout << "请输入密码：";
    getline(cin, newUser->password);
    newUser->next = nullptr;

    // 添加到用户链表末尾
    if (user_head == nullptr)
    {
        user_head = newUser;
        user_tail = newUser;// 初始化头尾指针
    }
    else
    {
        user_tail->next = newUser;//尾指针直接连接新节点
        user_tail = newUser;// 更新尾指针
    }
    cout << "用户信息添加成功！" << endl;
    for (int i = 3; i > 0; i--)
    {
        cout << "\r即将在" << i << "秒后返回上一界面";
        cout.flush();//立即将缓冲区中的数据输出到控制台，保证数字能及时显示
        Sleep(1000);//暂停1秒
    }
    system("cls");// 清屏
}

//添加车票信息
void add_train_ticket()
{
    TrainInfo info;//使用结构体储存临时信息
    // 步骤1：输入车次号
    admin_functions_initial_prompt(1, 1, 0, info);//管理员添加车票信息的初始提示
    int prompt = 0;
    while (true)
    {
        getline(cin, info.number);//管理员添加车票信息的初始提示
        info.number = trim(info.number);//去除字符串前后空格
        if (info.number == "0")// 输入0则返回上一级 
        {
            system("cls"); // 清屏
            return;
        }
        //检查车次号是否符合规则
        if (number_check(info.number, prompt)) break;
        admin_functions_initial_prompt(1, 1, prompt, info);
    }
    //步骤2：输入出发站
    admin_functions_initial_prompt(1, 2, 0, info);//管理员添加车票信息的初始提示
    while (true)
    {
        getline(cin, info.dep);
        info.dep = trim(info.dep);//去除字符串前后空格
        if (info.dep == "0")// 输入0则返回上一级 
        {
            system("cls"); // 清屏
            return;
        }
        //检查站名是否符合规则
        if (station_check(info.dep, prompt)) break;
        admin_functions_initial_prompt(1, 2, prompt, info);
    }
    //步骤3：输入终点站
    admin_functions_initial_prompt(1, 3, 0, info);//管理员添加车票信息的初始提示
    while (true)
    {
        getline(cin, info.dest);
        info.dest = trim(info.dest);//去除字符串前后空格
        if (info.dest == "0")// 输入0则返回上一级 
        {
            system("cls"); // 清屏
            return;
        }
        //检查站名是否符合规则
        if (station_check(info.dest, prompt)) break;
        admin_functions_initial_prompt(1, 3, prompt, info);
    }
    //步骤4：输入出发时间
    admin_functions_initial_prompt(1, 4, 0, info);//管理员添加车票信息的初始提示
    while (true)
    {
        getline(cin, info.deptime);
        info.deptime = trim(info.deptime);//去除字符串前后空格
        if (info.deptime == "0")// 输入0则返回上一级 
        {
            system("cls"); // 清屏
            return;

        }
        //检查出发时间是否符合规则
        if (dep_time_check(info.deptime, prompt))
        {   //将时间字符串转换为DataTime结构体
            info.dep_time = string_to_DataTime(info.deptime);
            break;
        }
        admin_functions_initial_prompt(1, 4, prompt, info);
    }

    //步骤5：输入到达时间
    admin_functions_initial_prompt(1, 5, 0, info);//管理员添加车票信息的初始提示
    while (true)
    {
        getline(cin, info.desttime);
        info.desttime = trim(info.desttime);//去除字符串前后空格
        if (info.desttime == "0")// 输入0则返回上一级 
        {
            system("cls"); // 清屏
            return;
        }
        //检查到达时间是否符合规则
        if (dest_time_check(info.dep_time, info.desttime, prompt))
        {   //将时间字符串转换为DataTime结构体
            info.dest_time = string_to_DataTime(info.desttime);
            break;
        }
        admin_functions_initial_prompt(1, 5, prompt, info);
    }
    info.total_seats = total_seats;//火车总座位数固定800个

    //添加车票完毕显示已输入的正确信息
    admin_functions_initial_prompt(1, 6, 0, info);
    while (true)
    {
        int confirm = isConfirm(prompt);//确认目前操作
        if (confirm == 1) break;//确认添加车票操作成功
        if (confirm == 0)//返回上一界面
        {
            system("cls"); // 清屏
            return;
        }
        admin_functions_initial_prompt(1, 6, prompt, info);
    }
    // 创建新车次
    Train* newTrain = new Train;
    newTrain->number = info.number;
    newTrain->dep = info.dep;
    newTrain->dest = info.dest;
    newTrain->dep_time = info.dep_time;
    newTrain->dest_time = info.dest_time;
    newTrain->total_seats = info.total_seats;
    newTrain->remain_seats = info.total_seats;
    newTrain->price = 100;//默认价格
    newTrain->next = nullptr;
    // 添加到车次链表
    if (train_head == nullptr) {
        train_head = train_tail = newTrain;
    }
    else {
        train_tail->next = newTrain;
        train_tail = newTrain;
    }
}

      
// 删除车票信息
void delete_train_ticket() {
    Train* current = train_head;
    Train* prev = nullptr;
    int choice;
    system("cls");
    cout << "火车票管理系统->系统管理员界面->登录->管理员服务界面->删除车票信息" << endl;
    cout << "请选择您需要删除的车次：" << endl;
    // 显示所有车次信息
    int index = 1;
    while (current != nullptr) {
        cout << index << "." << current->number << " " << current->dep << " " << current->dest
            << formatTime(current->dep_time)
            << "——"
            << formatTime(current->dest_time) << endl;
        current = current->next;
        index++;
    }
    cout << "0.返回上一步" << endl;
    cout << "请输入您的选择：";
    while (1)
    {
        int temp;
        temp = scanf_s("%d", &choice);
        if (choice == 0) {
            system("cls");
            return;
        }
        if (temp!= 1) //scanf获取到获取失败返回0，正常获取返回1
        {
            cout<<"输入有误，请重新选择！"<<endl;
            while (getchar() != '\n'); // 清空缓冲区
            continue;
        }
        break;
    }
    current = train_head;
    index = 1;
    while (current != nullptr) {
        if (index == choice) {
            if (prev == nullptr) {
                train_head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            cout << "删除成功！" << endl;
            for (int i = 3; i > 0; i--) {
                cout << "\r即将在" << i << "秒后返回上一界面";
                cout.flush();
                Sleep(1000);
            }
            system("cls");
            return;
        }
        prev = current;
        current = current->next;
        index++;
    }
    cout << "删除失败，无效的选择！" << endl;
    for (int i = 3; i > 0; i--) {
        cout << "\r即将在" << i << "秒后返回上一界面";
        cout.flush();
        Sleep(1000);
    }
    system("cls");
}

// 修改车票信息
void modify_train_ticket() {
    Train* current = train_head;
    int choice=0;
    system("cls");
    cout << "火车票管理系统->系统管理员界面->登录->管理员服务界面->修改车票信息" << endl;
    cout << "请选择您需要修改的车次：" << endl;
    // 显示所有车次信息
    int index = 1;
    while (current != nullptr) {
        cout << index << "." << current->number << " " << current->dep << " " << current->dest
            << formatTime(current->dep_time)
            << "——"
            << formatTime(current->dest_time) << endl;
        current = current->next;
        index++;
    }
    cout << "0.返回上一步" << endl;
    cout << "请输入您的选择：";
    while (1)
    {
        int temp;
        temp = scanf_s("%d", &choice);
        if (choice == 0) {
            system("cls");
            return;
        }
        if (temp != 1) //scanf获取到获取失败返回0，正常获取返回1
        {
            cout << "输入有误，请重新选择！" << endl;
            while (getchar() != '\n'); // 清空缓冲区
            continue;
        }
        break;
    }

    current = train_head;
    index = 1;
    while (current != nullptr) {
        if (index == choice) {
            system("cls");
            cout << "当前车次信息：" << endl;
            cout << "车次号：" << current->number << endl;
            cout << "起始站：" << current->dep << endl;
            cout << "终点站：" << current->dest << endl;
            cout << "出发时间：" << formatTime(current->dep_time) << endl;
            cout << "到达时间：" << formatTime(current->dest_time) << endl;
            cout << "票价：" << current->price << endl;
            //cout << "总座位数：" << current->total_seats << endl;
            //cout << "剩余座位数：" << current->remain_seats << endl;
            cout << "请输入新的车次号（直接回车跳过修改）：";
            string input;
            cin.ignore(); // 清空输入缓冲区
            getline(cin, input);
            if (!input.empty()) {
                current->number = input;
            }
            cout << "请输入新的起始站（直接回车跳过修改）：";
            getline(cin, input);
            if (!input.empty()) {
                current->dep = input;
            }
            cout << "请输入新的终点站（直接回车跳过修改）：";
            getline(cin, input);
            if (!input.empty()) {
                current->dest = input;
            }
            cout << "请输入新的出发时间（格式：YYYY-MM-DD HH:MM，直接回车跳过修改）：";
            getline(cin, input);
            if (!input.empty()) {
                current->dep_time = string_to_DataTime(input);
            }
            cout << "请输入新的到达时间（格式：YYYY-MM-DD HH:MM，直接回车跳过修改）：";
            getline(cin, input);
            if (!input.empty()) {
                current->dest_time = string_to_DataTime(input);
            }
            cout << "请输入新的票价（直接回车跳过修改）：";
            getline(cin, input);
            if (!input.empty()) {
                current->price = stoi(input);
            }
            cout << "修改成功！" << endl;
            for (int i = 3; i > 0; i--) {
                cout << "\r即将在" << i << "秒后返回上一界面";
                cout.flush();
                Sleep(1000);
            }
            system("cls");
            return;
        }
        current = current->next;
        index++;
    }
    cout << "修改失败，无效的选择！" << endl;
    for (int i = 3; i > 0; i--) {
        cout << "\r即将在" << i << "秒后返回上一界面";
        cout.flush();
        Sleep(1000);
    }
    system("cls");
}


// 查询车票信息
void search_train_ticket() {
    Train* current = train_head;
    system("cls");
    cout << "火车票管理系统->系统管理员界面->登录->管理员服务界面->查询信息" << endl;
    cout << "请输入查询条件（车次号/起始站/终点站，输入1查询所有）：";
    string keyword;
    cin >> keyword;
    if (keyword=="1") {
        // 显示所有车次信息
        while (current != nullptr) {
            cout << "车次号：" << current->number << endl;
            cout << "起始站：" << current->dep << endl;
            cout << "终点站：" << current->dest << endl;
            cout << "出发时间：" << formatTime(current->dep_time) << endl;
            cout << "到达时间：" << formatTime(current->dest_time) << endl;
            cout << "票价：" << current->price << endl;
            cout << "余票：" << current->remain_seats << "/" << current->total_seats << endl;
            cout << "----------------------------------------" << endl;
            current = current->next;
        }
    }
    else {
        bool found = false;
        while (current != nullptr) {
            if (current->number.find(keyword) != string::npos ||
                current->dep.find(keyword) != string::npos ||
                current->dest.find(keyword) != string::npos) {
                found = true;
                cout << "车次号：" << current->number << endl;
                cout << "起始站：" << current->dep << endl;
                cout << "终点站：" << current->dest << endl;
                cout << "出发时间：" << formatTime(current->dep_time) << endl;
                cout << "到达时间：" << formatTime(current->dest_time) << endl;
                cout << "票价：" << current->price << endl;
                cout << "余票：" << current->remain_seats << "/" << current->total_seats << endl;
                cout << "----------------------------------------" << endl;
            }
            current = current->next;
        }
        if (!found) {
            cout << "未找到匹配的车次信息！" << endl;
        }
    }
    cout << "按任意键返回上一界面...";
    cin.get();
    cin.get();
    system("cls");
}


