#include "user.h"
#include "utils.h"
#include"save.h"
#include <iostream>

// ȫ�ֱ��������ڴ洢��ǰ��¼���û�
User* current_logged_user = nullptr;

// �û���¼
void user_log_in()
{
    login_initial_prompt(2, 1, 0);//��¼�����ʼ��ʾ��Ϣ
    while (true)
    {
        string username, password;
        getline(cin, username);
        username = trim(username);// ȥ���ַ���ǰ��ո�
        if (username == "0")//������0�򷵻���һ��
        {
            system("cls");// ����
            return;
        }
        login_initial_prompt(2, 2, 0, username);//��¼�����ʼ��ʾ��Ϣ
        password = getPassword();//��¼ʱ��ȡ������֧���л���ʾ״̬
        if (password == "0")//������0�򷵻���һ��
        {
            system("cls");// ����
            return;
        }
        //�ж�������û����������Ƿ���ƥ�����е�ע����Ϣ
        bool success = false;//���費ƥ�䣬Ҳ���ǵ�¼ʧ��
        User* current = user_head;
        while (current != nullptr)
        {
            if (current->name == username && current->password == password)
            {   //�ɹ�ƥ�䵽���е�ע����Ϣ����¼�ɹ�
                success = true;
                current_logged_user = current; // ��¼��ǰ��¼�û�
                break;
            }
            current = current->next;
        }
        if (success)
        {
            system("cls");// ����
            user_services(); // �û�������
            return ;
        }
        login_initial_prompt(2, 1, 1);//��¼�����ʼ��ʾ��Ϣ
    }
}

// �û�ע��
void user_register()
{
    // ����1�������û���
    register_initial_prompt(2, 0, 1, 0); // 2��ʾ�û�ע��
    string username = name_check(2);
    if (username == "0") // ע�������ȡ��ע��
    {
        system("cls"); // ����
        return;
    }

    // ����2���������֤��
    register_initial_prompt(2, 1, 2, 0, username);
    string idNumber = id_check(2,username);
    if (idNumber == "0")
    {
        system("cls");
        return;
    }

    // ����3�������ֻ���
    register_initial_prompt(2, 1, 3, 0, username, idNumber);
    string phone = phone_check(2, username, idNumber);
    if (phone == "0")
    {
        system("cls");
        return;
    }

    // ����4�������ֻ���֤��
    string code = code_check(2,username, idNumber, phone);
    if (code == "0")
    {
        system("cls");
        return;
    }
    if (code == "-1") // ��֤�������������
    {
        for (int i = 3; i > 0; i--)
        {
            cout << "\r�����������������֤�룬" << i << "������ע����Ϣ������";
            cout.flush();
            Sleep(1000);
        }
        system("cls");
        return;
    }
    // ����5�����벢ȷ������
    register_initial_prompt(2, 1, 5, 0, username, idNumber, phone, code);
    string password = password_check(2,username, idNumber, phone, code);
    if (password == "0")
    {
        system("cls");
        return;
    }
    // �������û��ڵ�
    User* newUser = new User;
    newUser->name = username;
    newUser->id = idNumber;
    newUser->phone = phone;
    newUser->password = password;
    //newUser->orders = nullptr;
    newUser->next = nullptr;
    // ��ӵ��û�����ĩβ
    if (user_head == nullptr)
    {
        user_head = newUser;
        user_tail = newUser;// ��ʼ��ͷβָ��
    }
    else
    {
        user_tail->next = newUser;//βָ��ֱ�������½ڵ�
        user_tail = newUser;// ����βָ��
    }
    cout << "ע��ɹ���" << endl;
    for (int i = 3; i > 0; i--)
    {
        cout << "\r������" << i << "��󷵻���һ����";
        cout.flush();//�������������е��������������̨����֤�����ܼ�ʱ��ʾ
        Sleep(1000);//��ͣ1��
    }
    system("cls");// ����
}
// �û�����
void user_interface() 
{
    while (true)
    {
        show_user_menu();// ��ʾ�û��˵�
        int user_menu_choice = get_vaild_int(1, 3, 3);//�û��˵�������֤
        switch (user_menu_choice)
        {
        case 1:
        {
            system("cls");// ����
            user_register();
            break;
        }
        case 2:
        {
            system("cls");// ����
            user_log_in();
            break;
        }
        case 3:
        {
            system("cls");// ����
            return;
        }
        }
    }
}

//��ʾ��¼���û����ܲ˵�
void login_user_menu()
{
    system("cls");// ����
    cout << "��Ʊ����ϵͳ->��Ʊ�û�����->��¼->�û��������" << endl;
    cout << "��������������������������������" << endl;
    cout << "��1.��Ʊ        ��" << endl;
    cout << "��������������������������������" << endl;
    cout << "��2.��Ʊ        ��" << endl;
    cout << "��������������������������������" << endl;
    cout << "��3.��ǩ        ��" << endl;
    cout << "��������������������������������" << endl;
    cout << "��4.��ѯ��Ϣ    ��" << endl;
    cout << "��������������������������������" << endl;
    cout << "��5.�˳���¼    ��" << endl;
    cout << "��������������������������������" << endl;
}

//�û�������
void user_services()
{
    // ȷ����ǰ��¼�û�ָ����Ч
    if (current_logged_user == nullptr) {
        cout << "�û��Ự�쳣�������µ�¼��" << endl;
        Sleep(2000);
        system("cls");
        return;
    }
    while (true)
    {
        login_user_menu();//��ʾ��¼�����Ա���������ܲ˵�
        int login_user_menu_choice = get_vaild_int(1, 5, 5);// ��¼���û��˵�������֤
        // ÿ�β�������֤�û�״̬
        if (current_logged_user == nullptr) {
            cout << "�û��Ự��ʧЧ�������µ�¼��" << endl;
            Sleep(2000);
            system("cls");
            return;
        }
        switch (login_user_menu_choice)
        {

        case 1:
        {
            system("cls");// ����
            purchase_ticket(current_logged_user);//��Ʊ
            break;
        }

        case 2:
        {
            system("cls");// ����
            refund_ticket(current_logged_user);//��Ʊ
            break;
        }

        case 3:
        {
            system("cls");// ����
            change_ticket(current_logged_user);//��ǩ
            break;
        }

        case 4:
        {
            system("cls");// ����
            query_user_tickets(current_logged_user);//��ѯ��Ϣ
            break;
        }

        case 5:
        {
            system("cls");// ����
            current_logged_user = nullptr;
            save_all_data();
            return;//�˳���¼
            break;
        }
        }
    }
}

// ��Ʊ
// user.cpp
void purchase_ticket(User* currentUser) {
    if (currentUser == nullptr) {
        cout << "��ǰû���û���¼��" << endl;
        return;
    }
    Train* current = train_head;
    system("cls");
    cout << "��Ʊ����ϵͳ->��Ʊ�û�����->��¼->�û��������->��Ʊ" << endl;
    cout << "��ѡ�����ĳ��Σ�" << endl;
    int index = 1;
    while (current != nullptr) {
        cout << index << "." << current->number << " " << current->dep << " "<< current->dest << " "
            <<formatTime(current->dep_time)
            << "����"
            << formatTime(current->dest_time)<< endl;
        current = current->next;
        index++;
    }
    cout << "0.������һ��" << endl;
    cout << "����������ѡ��";
    int choice;
    while (1)
    {
        int temp;
        temp = scanf_s("%d", &choice);
        if (choice == 0) {
            system("cls");
            return;
        }
        if (temp != 1) //scanf��ȡ����ȡʧ�ܷ���0��������ȡ����1
        {
            cout << "��������������ѡ��" << endl;
            while (getchar() != '\n'); // ��ջ�����
            continue;
        }
        break;
    }
    current = train_head;
    index = 1;
    while (current != nullptr) {
        if (index == choice) {
        //�����Ʊ
            if (current->remain_seats <= 0) {
                cout << "�ó���������Ʊ����Ʊʧ�ܣ�" << endl;
                for (int i = 3; i > 0; i--) {
                    cout << "\r������" << i << "��󷵻���һ����";
                    cout.flush();
                    Sleep(1000);
                }
                system("cls");
                return;
            }
            system("cls");
            cout << "��Ʊ����ϵͳ->��Ʊ�û�����->��¼->�û��������->��Ʊ->" << current->number << endl;
            cout << "��ѡ��֧����ʽ��" << endl;
            cout << "1.΢��֧��" << endl;
            cout << "2.֧����֧��" << endl;
            cout << "3.����" << endl;
            cout << "0.������һ��" << endl;
            cout << "����������ѡ��";
            int payChoice;
            while (1)
            {
                int temp;
                temp = scanf_s("%d", &payChoice);
                if (payChoice == 0) {
                    system("cls");
                    return;
                }
                if (temp != 1) //scanf��ȡ����ȡʧ�ܷ���0��������ȡ����1
                {
                    cout << "��������������ѡ��" << endl;
                    while (getchar() != '\n'); // ��ջ�����
                    continue;
                }
                break;
            }
            // �����¶���
            Order newOrder;
            newOrder.train_number = current->number;
            newOrder.dep = current->dep;
            newOrder.dest = current->dest;
            newOrder.seat_number = 1; // Ĭ����λ���Ϊ1
            newOrder.dep_time = current->dep_time;
            newOrder.dest_time = current->dest_time;
            newOrder.price = current->price;

            current->remain_seats--;

            // ��ӵ��û������б�
            currentUser->orders.push_back(newOrder);

            cout << "��Ʊ�ɹ���" << endl;
            save_all_data(); // ��������
            for (int i = 3; i > 0; i--) {
                cout << "\r������" << i << "��󷵻���һ����";
                cout.flush();
                Sleep(1000);
            }
            system("cls");
            return;
        }
        current = current->next;
        index++;
    }
    cout << "��Ʊʧ�ܣ���Ч��ѡ��" << endl;
    for (int i = 3; i > 0; i--) {
        cout << "\r������" << i << "��󷵻���һ����";
        cout.flush();
        Sleep(1000);
    }
    system("cls");
}
// ��Ʊ
void refund_ticket(User* currentUser) {
    if (currentUser == nullptr) {
        cout << "��ǰû���û���¼��" << endl;
        return;
    }
    //Order* currentOrder = currentUser->orders;
    if (currentUser->orders.empty()) {
        cout << "����ǰû�ж�����" << endl;
        for (int i = 3; i > 0; i--) {
            cout << "\r������" << i << "��󷵻���һ����";
            cout.flush();
            Sleep(1000);
        }
        system("cls");
        return;
    }
    system("cls");
    cout << "��Ʊ����ϵͳ->��Ʊ�û�����->��¼->�û��������->��Ʊ" << endl;
    int index = 1;
    for (const auto& order : currentUser->orders) {
        cout << index << "." << order.train_number << " "<<order.dep<< " " << order.dest << " "
            << formatTime(order.dep_time)
            << "����"
            << formatTime(order.dest_time) << endl;
        index++;
    }
    cout << "0.������һ��" << endl;
    cout << "����������ѡ��";
    int choice;
    while (1)
    {
        int temp;
        temp = scanf_s("%d", &choice);
        if (choice == 0) {
            system("cls");
            return;
        }
        if (temp != 1) //scanf��ȡ����ȡʧ�ܷ���0��������ȡ����1
        {
            cout << "��������������ѡ��" << endl;
            while (getchar() != '\n'); // ��ջ�����
            continue;
        }
        break;
    }
    if (choice > 0 && choice <= static_cast<int>(currentUser->orders.size())) {
        const Order& selectedOrder = currentUser->orders[choice - 1];

        // ������Ʊ�����ݶ����еĳ��κ��ҵ���Ӧ�ĳ���
        Train* train = train_head;
        while (train != nullptr) {
            if (train->number == selectedOrder.train_number) {
                train->remain_seats++; // ��Ʊ����
                break;
            }
            train = train->next;
        }
        currentUser->orders.erase(currentUser->orders.begin() + choice - 1);
        cout << "��Ʊ�ɹ���" << endl;
        save_all_data(); // ��������
        for (int i = 3; i > 0; i--) {
            cout << "\r������" << i << "��󷵻���һ����";
            cout.flush();
            Sleep(1000);
        }
        system("cls");
    }
    else {
        cout << "��Ʊʧ�ܣ���Ч��ѡ��" << endl;
        for (int i = 3; i > 0; i--) {
            cout << "\r������" << i << "��󷵻���һ����";
            cout.flush();
            Sleep(1000);
        }
        system("cls");
    }
}

// ��ǩ
void change_ticket(User* currentUser) {
    if (currentUser == nullptr) {
        cout << "��ǰû���û���¼��" << endl;
        return;
    }
    //Order* currentOrder = currentUser->orders;
    if (currentUser->orders.empty()) {
        cout << "����ǰû�ж�����" << endl;
        for (int i = 3; i > 0; i--) {
            cout << "\r������" << i << "��󷵻���һ����";
            cout.flush();
            Sleep(1000);
        }
        system("cls");
        return;
    }
    system("cls");
    cout << "��Ʊ����ϵͳ->��Ʊ�û�����->��¼->�û��������->��ǩ" << endl;
    int index = 1;
    for (const auto& order : currentUser->orders) {
        cout << index << "." << order.train_number << " " << order.dep << " " << order.dest<<" "
            << formatTime(order.dep_time)
            << "����"
            << formatTime(order.dest_time) << endl;
        //currentOrder = currentOrder->next;
        index++;
    }
    cout << "0.������һ��" << endl;
    cout << "����������ѡ��";
    int choice;
    while (1)
    {
        int temp;
        temp = scanf_s("%d", &choice);
        if (choice == 0) {
            system("cls");
            return;
        }
        if (temp != 1) //scanf��ȡ����ȡʧ�ܷ���0��������ȡ����1
        {
            cout << "��������������ѡ��" << endl;
            while (getchar() != '\n'); // ��ջ�����
            continue;
        }
        break;
    }
    //currentOrder = currentUser->orders;
    //index = 1;
    //while (currentOrder != nullptr) {
    //   if (index == choice) {
    //       // ����Ʊ
    //        refund_ticket(currentUser);
    //        // �����¹�Ʊ
    //       purchase_ticket(currentUser);
    //        return;
    //    }
    //    currentOrder = currentOrder->next;
    //    index++;
    //}
        // �����û�ѡ���ҵ�����
    if (choice > 0 && choice <= static_cast<int>(currentUser->orders.size())) {
        // ��Ʊ�����Ӿɳ�����Ʊ��
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

        // �ٴι�Ʊ
        purchase_ticket(currentUser);
        return;
    }
    cout << "��ǩʧ�ܣ���Ч��ѡ��" << endl;
    for (int i = 3; i > 0; i--) {
        cout << "\r������" << i << "��󷵻���һ����";
        cout.flush();
        Sleep(1000);
    }
    system("cls");
}

// ��ѯ����
void query_user_tickets(User* currentUser) {
    if (currentUser == nullptr) {
        cout << "��ǰû���û���¼��" << endl;
        return;
    }
    //Order* currentOrder = currentUser->orders;
    if (currentUser->orders.empty()) {
        cout << "����ǰû�ж�����" << endl;
        for (int i = 3; i > 0; i--) {
            cout << "\r������" << i << "��󷵻���һ����";
            cout.flush();
            Sleep(1000);
        }
        system("cls");
        return;
    }
    system("cls");
    cout << "��Ʊ����ϵͳ->��Ʊ�û�����->��¼->�û��������->��ѯ��Ϣ" << endl;
    int index = 1;
    for (const auto& order : currentUser->orders) {
        cout << index << "." << order.train_number << " " << order.dep << " " << order.dest << " "
            << formatTime(order.dep_time)
            << "����"
            << formatTime(order.dest_time) << endl;
        //currentOrder = currentOrder->next;
        index++;
    }
    cout << "0.������һ��" << endl;
    cout << "����������ѡ��";
    int choice;
    while (1)
    {
        int temp;
        temp = scanf_s("%d", &choice);
        if (choice == 0) {
            system("cls");
            return;
        }
        if (temp != 1) //scanf��ȡ����ȡʧ�ܷ���0��������ȡ����1
        {
            cout << "��������������ѡ��" << endl;
            while (getchar() != '\n'); // ��ջ�����
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
                cout << "���Σ�" << selectedOrder.train_number << endl;
                cout << "Ʊ�ۣ�" << selectedOrder.price << endl;
                cout << "����վ��" << selectedOrder.dep << endl;
                cout << "�յ�վ��" << selectedOrder.dest << endl;
                cout << "����ʱ�䣺" << formatTime(selectedOrder.dep_time) << endl;
                cout << "����ʱ�䣺" << formatTime(selectedOrder.dest_time) << endl;
                cout << "��Ʊ��" << train->remain_seats << "/" << train->total_seats << endl;
                cout << "�û���" << currentUser->name << endl;
                cout << "----------------------------------------" << endl;
                break;
            }
            train = train->next;
        }
    }
    cout << "�������������һ����...";
    cin.get();
    cin.get();
    system("cls");
}