#include "user.h"
#include "utils.h"
#include"save.h"
#include <iostream>

// 全局变量，用于存储当前登录的用户
User* current_logged_user = nullptr;

// 用户登录
void user_log_in()
{
    login_initial_prompt(2, 1, 0);//登录界面初始提示信息
    while (true)
    {
        string username, password;
        getline(cin, username);
        username = trim(username);// 去除字符串前后空格
        if (username == "0")//若输入0则返回上一步
        {
            system("cls");// 清屏
            return;
        }
        login_initial_prompt(2, 2, 0, username);//登录界面初始提示信息
        password = getPassword();//登录时获取密码且支持切换显示状态
        if (password == "0")//若输入0则返回上一步
        {
            system("cls");// 清屏
            return;
        }
        //判断输入的用户名和密码是否能匹配已有的注册信息
        bool success = false;//假设不匹配，也就是登录失败
        User* current = user_head;
        while (current != nullptr)
        {
            if (current->name == username && current->password == password)
            {   //成功匹配到已有的注册信息，登录成功
                success = true;
                current_logged_user = current; // 记录当前登录用户
                break;
            }
            current = current->next;
        }
        if (success)
        {
            system("cls");// 清屏
            user_services(); // 用户服务功能
            return ;
        }
        login_initial_prompt(2, 1, 1);//登录界面初始提示信息
    }
}

// 用户注册
void user_register()
{
    // 步骤1：输入用户名
    register_initial_prompt(2, 0, 1, 0); // 2表示用户注册
    string username = name_check(2);
    if (username == "0") // 注册过程中取消注册
    {
        system("cls"); // 清屏
        return;
    }

    // 步骤2：输入身份证号
    register_initial_prompt(2, 1, 2, 0, username);
    string idNumber = id_check(2,username);
    if (idNumber == "0")
    {
        system("cls");
        return;
    }

    // 步骤3：输入手机号
    register_initial_prompt(2, 1, 3, 0, username, idNumber);
    string phone = phone_check(2, username, idNumber);
    if (phone == "0")
    {
        system("cls");
        return;
    }

    // 步骤4：输入手机验证码
    string code = code_check(2,username, idNumber, phone);
    if (code == "0")
    {
        system("cls");
        return;
    }
    if (code == "-1") // 验证码连续输错三次
    {
        for (int i = 3; i > 0; i--)
        {
            cout << "\r您已连续输错三次验证码，" << i << "秒后将清空注册信息并返回";
            cout.flush();
            Sleep(1000);
        }
        system("cls");
        return;
    }
    // 步骤5：输入并确认密码
    register_initial_prompt(2, 1, 5, 0, username, idNumber, phone, code);
    string password = password_check(2,username, idNumber, phone, code);
    if (password == "0")
    {
        system("cls");
        return;
    }
    // 创建新用户节点
    User* newUser = new User;
    newUser->name = username;
    newUser->id = idNumber;
    newUser->phone = phone;
    newUser->password = password;
    //newUser->orders = nullptr;
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
    cout << "注册成功！" << endl;
    for (int i = 3; i > 0; i--)
    {
        cout << "\r即将在" << i << "秒后返回上一界面";
        cout.flush();//立即将缓冲区中的数据输出到控制台，保证数字能及时显示
        Sleep(1000);//暂停1秒
    }
    system("cls");// 清屏
}
// 用户界面
void user_interface() 
{
    while (true)
    {
        show_user_menu();// 显示用户菜单
        int user_menu_choice = get_vaild_int(1, 3, 3);//用户菜单输入验证
        switch (user_menu_choice)
        {
        case 1:
        {
            system("cls");// 清屏
            user_register();
            break;
        }
        case 2:
        {
            system("cls");// 清屏
            user_log_in();
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

//显示登录后用户功能菜单
void login_user_menu()
{
    system("cls");// 清屏
    cout << "火车票管理系统->购票用户界面->登录->用户服务界面" << endl;
    cout << "┌──────────────┐" << endl;
    cout << "│1.购票        │" << endl;
    cout << "├──────────────┤" << endl;
    cout << "│2.退票        │" << endl;
    cout << "├──────────────┤" << endl;
    cout << "│3.改签        │" << endl;
    cout << "├──────────────┤" << endl;
    cout << "│4.查询信息    │" << endl;
    cout << "├──────────────┤" << endl;
    cout << "│5.退出登录    │" << endl;
    cout << "└──────────────┘" << endl;
}

//用户服务功能
void user_services()
{
    // 确保当前登录用户指针有效
    if (current_logged_user == nullptr) {
        cout << "用户会话异常，请重新登录！" << endl;
        Sleep(2000);
        system("cls");
        return;
    }
    while (true)
    {
        login_user_menu();//显示登录后管理员服务器功能菜单
        int login_user_menu_choice = get_vaild_int(1, 5, 5);// 登录后用户菜单输入验证
        // 每次操作后都验证用户状态
        if (current_logged_user == nullptr) {
            cout << "用户会话已失效，请重新登录！" << endl;
            Sleep(2000);
            system("cls");
            return;
        }
        switch (login_user_menu_choice)
        {

        case 1:
        {
            system("cls");// 清屏
            purchase_ticket(current_logged_user);//购票
            break;
        }

        case 2:
        {
            system("cls");// 清屏
            refund_ticket(current_logged_user);//退票
            break;
        }

        case 3:
        {
            system("cls");// 清屏
            change_ticket(current_logged_user);//改签
            break;
        }

        case 4:
        {
            system("cls");// 清屏
            query_user_tickets(current_logged_user);//查询信息
            break;
        }

        case 5:
        {
            system("cls");// 清屏
            current_logged_user = nullptr;
            save_all_data();
            return;//退出登录
            break;
        }
        }
    }
}

// 购票
// user.cpp
void purchase_ticket(User* currentUser) {
    if (currentUser == nullptr) {
        cout << "当前没有用户登录！" << endl;
        return;
    }
    Train* current = train_head;
    system("cls");
    cout << "火车票管理系统->购票用户界面->登录->用户服务界面->购票" << endl;
    cout << "请选择您的车次：" << endl;
    int index = 1;
    while (current != nullptr) {
        cout << index << "." << current->number << " " << current->dep << " "<< current->dest << " "
            <<formatTime(current->dep_time)
            << "——"
            << formatTime(current->dest_time)<< endl;
        current = current->next;
        index++;
    }
    cout << "0.返回上一步" << endl;
    cout << "请输入您的选择：";
    int choice;
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
        //检查余票
            if (current->remain_seats <= 0) {
                cout << "该车次已无余票，购票失败！" << endl;
                for (int i = 3; i > 0; i--) {
                    cout << "\r即将在" << i << "秒后返回上一界面";
                    cout.flush();
                    Sleep(1000);
                }
                system("cls");
                return;
            }
            system("cls");
            cout << "火车票管理系统->购票用户界面->登录->用户服务界面->购票->" << current->number << endl;
            cout << "请选择支付方式：" << endl;
            cout << "1.微信支付" << endl;
            cout << "2.支付宝支付" << endl;
            cout << "3.银联" << endl;
            cout << "0.返回上一步" << endl;
            cout << "请输入您的选择：";
            int payChoice;
            while (1)
            {
                int temp;
                temp = scanf_s("%d", &payChoice);
                if (payChoice == 0) {
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
            // 创建新订单
            Order newOrder;
            newOrder.train_number = current->number;
            newOrder.dep = current->dep;
            newOrder.dest = current->dest;
            newOrder.seat_number = 1; // 默认座位编号为1
            newOrder.dep_time = current->dep_time;
            newOrder.dest_time = current->dest_time;
            newOrder.price = current->price;

            current->remain_seats--;

            // 添加到用户订单列表
            currentUser->orders.push_back(newOrder);

            cout << "购票成功！" << endl;
            save_all_data(); // 保存数据
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
    cout << "购票失败，无效的选择！" << endl;
    for (int i = 3; i > 0; i--) {
        cout << "\r即将在" << i << "秒后返回上一界面";
        cout.flush();
        Sleep(1000);
    }
    system("cls");
}
// 退票
void refund_ticket(User* currentUser) {
    if (currentUser == nullptr) {
        cout << "当前没有用户登录！" << endl;
        return;
    }
    //Order* currentOrder = currentUser->orders;
    if (currentUser->orders.empty()) {
        cout << "您当前没有订单！" << endl;
        for (int i = 3; i > 0; i--) {
            cout << "\r即将在" << i << "秒后返回上一界面";
            cout.flush();
            Sleep(1000);
        }
        system("cls");
        return;
    }
    system("cls");
    cout << "火车票管理系统->购票用户界面->登录->用户服务界面->退票" << endl;
    int index = 1;
    for (const auto& order : currentUser->orders) {
        cout << index << "." << order.train_number << " "<<order.dep<< " " << order.dest << " "
            << formatTime(order.dep_time)
            << "——"
            << formatTime(order.dest_time) << endl;
        index++;
    }
    cout << "0.返回上一步" << endl;
    cout << "请输入您的选择：";
    int choice;
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
    if (choice > 0 && choice <= static_cast<int>(currentUser->orders.size())) {
        const Order& selectedOrder = currentUser->orders[choice - 1];

        // 增加余票：根据订单中的车次号找到对应的车次
        Train* train = train_head;
        while (train != nullptr) {
            if (train->number == selectedOrder.train_number) {
                train->remain_seats++; // 余票增加
                break;
            }
            train = train->next;
        }
        currentUser->orders.erase(currentUser->orders.begin() + choice - 1);
        cout << "退票成功！" << endl;
        save_all_data(); // 保存数据
        for (int i = 3; i > 0; i--) {
            cout << "\r即将在" << i << "秒后返回上一界面";
            cout.flush();
            Sleep(1000);
        }
        system("cls");
    }
    else {
        cout << "退票失败，无效的选择！" << endl;
        for (int i = 3; i > 0; i--) {
            cout << "\r即将在" << i << "秒后返回上一界面";
            cout.flush();
            Sleep(1000);
        }
        system("cls");
    }
}

// 改签
void change_ticket(User* currentUser) {
    if (currentUser == nullptr) {
        cout << "当前没有用户登录！" << endl;
        return;
    }
    //Order* currentOrder = currentUser->orders;
    if (currentUser->orders.empty()) {
        cout << "您当前没有订单！" << endl;
        for (int i = 3; i > 0; i--) {
            cout << "\r即将在" << i << "秒后返回上一界面";
            cout.flush();
            Sleep(1000);
        }
        system("cls");
        return;
    }
    system("cls");
    cout << "火车票管理系统->购票用户界面->登录->用户服务界面->改签" << endl;
    int index = 1;
    for (const auto& order : currentUser->orders) {
        cout << index << "." << order.train_number << " " << order.dep << " " << order.dest<<" "
            << formatTime(order.dep_time)
            << "——"
            << formatTime(order.dest_time) << endl;
        //currentOrder = currentOrder->next;
        index++;
    }
    cout << "0.返回上一步" << endl;
    cout << "请输入您的选择：";
    int choice;
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
    //currentOrder = currentUser->orders;
    //index = 1;
    //while (currentOrder != nullptr) {
    //   if (index == choice) {
    //       // 先退票
    //        refund_ticket(currentUser);
    //        // 再重新购票
    //       purchase_ticket(currentUser);
    //        return;
    //    }
    //    currentOrder = currentOrder->next;
    //    index++;
    //}
        // 根据用户选择找到订单
    if (choice > 0 && choice <= static_cast<int>(currentUser->orders.size())) {
        // 退票（增加旧车次余票）
        const Order& oldOrder = currentUser->orders[choice - 1];
        Train* oldTrain = train_head;
        while (oldTrain != nullptr) {
            if (oldTrain->number == oldOrder.train_number) {
                oldTrain->remain_seats++;
                break;
            }
            oldTrain = oldTrain->next;
        }
        currentUser->orders.erase(currentUser->orders.begin() + choice - 1);

        // 再次购票
        purchase_ticket(currentUser);
        return;
    }
    cout << "改签失败，无效的选择！" << endl;
    for (int i = 3; i > 0; i--) {
        cout << "\r即将在" << i << "秒后返回上一界面";
        cout.flush();
        Sleep(1000);
    }
    system("cls");
}

// 查询订单
void query_user_tickets(User* currentUser) {
    if (currentUser == nullptr) {
        cout << "当前没有用户登录！" << endl;
        return;
    }
    //Order* currentOrder = currentUser->orders;
    if (currentUser->orders.empty()) {
        cout << "您当前没有订单！" << endl;
        for (int i = 3; i > 0; i--) {
            cout << "\r即将在" << i << "秒后返回上一界面";
            cout.flush();
            Sleep(1000);
        }
        system("cls");
        return;
    }
    system("cls");
    cout << "火车票管理系统->购票用户界面->登录->用户服务界面->查询信息" << endl;
    int index = 1;
    for (const auto& order : currentUser->orders) {
        cout << index << "." << order.train_number << " " << order.dep << " " << order.dest << " "
            << formatTime(order.dep_time)
            << "——"
            << formatTime(order.dest_time) << endl;
        //currentOrder = currentOrder->next;
        index++;
    }
    cout << "0.返回上一步" << endl;
    cout << "请输入您的选择：";
    int choice;
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
    //currentOrder = currentUser->orders;
    if (choice > 0 && choice <= static_cast<int>(currentUser->orders.size())) {
        const Order& selectedOrder = currentUser->orders[choice - 1];
        Train* train = train_head;
        while (train != nullptr) {
            if (train->number == selectedOrder.train_number) {
                cout << "车次：" << selectedOrder.train_number << endl;
                cout << "票价：" << selectedOrder.price << endl;
                cout << "出发站：" << selectedOrder.dep << endl;
                cout << "终点站：" << selectedOrder.dest << endl;
                cout << "出发时间：" << formatTime(selectedOrder.dep_time) << endl;
                cout << "到达时间：" << formatTime(selectedOrder.dest_time) << endl;
                cout << "余票：" << train->remain_seats << "/" << train->total_seats << endl;
                cout << "用户：" << currentUser->name << endl;
                cout << "----------------------------------------" << endl;
                break;
            }
            train = train->next;
        }
    }
    cout << "按任意键返回上一界面...";
    cin.get();
    cin.get();
    system("cls");
}