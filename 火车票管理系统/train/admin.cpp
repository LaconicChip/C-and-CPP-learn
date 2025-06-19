#include "admin.h"
#include "utils.h"
#include"save.h"
#include <iostream>
//����Ա��ӳ�Ʊ��Ϣ�ĳ�ʼ��ʾ
void admin_functions_initial_prompt(int function, int step, int prompt, const TrainInfo& info)//����Ա��ӳ�Ʊ��Ϣ�ĳ�ʼ��ʾ
{
    system("cls");// ����
    cout << "��Ʊ����ϵͳ->ϵͳ����Ա����->��¼->����Ա����������->";
    switch (function)
    {
    case 1:cout << "��ӳ�Ʊ��Ϣ" << endl; break;
    case 2:cout << "ɾ����Ʊ��Ϣ" << endl; break;
    case 3:cout << "�޸ĳ�Ʊ��Ϣ" << endl; break;
    case 4:cout << "��ѯ��Ʊ��Ϣ" << endl; break;
    }
    cout << "�����롰0��,�򷵻���һ��" << endl<<endl;
    //�������� �� ��  �� �� ��  ��������������������������������
    Train* current = train_head;
    if (current == nullptr)
    {
        cout << "���޳�����Ϣ��" << endl << endl;
        
    }
    else
    {   //�����ͷ
        cout << "��";
        print_repeated_char(1);
        cout << "��" << endl;
        cout << "��" << left << setw(number_width) << "���κ�"
            << "��" << left << setw(station_width) << "����վ"
            << "��" << left << setw(station_width) << "�յ�վ"
            << "��" << left << setw(time_width) << "����ʱ��"
            << "��" << left << setw(time_width) << "����ʱ��"
            << "��" << left << setw(seat_width) << "��Ʊ"
            << "��" << endl;
        cout << "��";
        print_repeated_char(2);
        cout << "��" << endl;
        //���������
        while (current != nullptr)
        {
            cout << "��" << left << setw(number_width) << current->number
                << "��" << left << setw(station_width) << current->dep
                << "��" << left << setw(station_width) << current->dest
                << "��" << left << setw(time_width) << formatTime(current->dep_time)
                << "��" << left << setw(time_width) << formatTime(current->dest_time)
                << "��" << current->remain_seats << "/" << current->total_seats << "��" << endl;
            if (current->next != nullptr)
            {
                cout << "��";
                print_repeated_char(2);
                cout << "��" << endl;
            }
            current = current->next;
        }
        cout << "��";
        print_repeated_char(3);
        cout << "��" << endl;
    }
    //��ʾ��������ȷ����ӳ�Ʊ��Ϣ
    cout << "��������ȷ����Ϣ��" << endl;
    if ((!info.number.empty())&&(step >= 2)) cout << "���κţ�" << info.number << endl;
    if ((!info.dep.empty()) && (step >= 3)) cout << "����վ��" << info.dep << endl;
    if ((!info.dest.empty()) && (step >= 4)) cout << "�յ�վ��" << info.dest << endl;
    if (info.dep_time.year != 0&&step>=5)
    {
        cout << "����ʱ�䣺" << info.dep_time.year << "��";
        cout << right<<setfill('0') << setw(2) << info.dep_time.month << "��";
        cout << right << setfill('0') << setw(2) << info.dep_time.day << "��";
        cout << right << setfill('0') << setw(2) << info.dep_time.hour << ":";
        cout << right << setfill('0') << setw(2) << info.dep_time.minute << endl;
        cout << setfill(' '); //��������ַ�
    }
    if (info.dest_time.year != 0 && step >= 6)
    {
        cout << "����ʱ�䣺" << info.dest_time.year << "��";
        cout << right << setfill('0') << setw(2) << info.dest_time.month << "��";
        cout << right << setfill('0') << setw(2) << info.dest_time.day << "��";
        cout << right << setfill('0') << setw(2) << info.dest_time.hour << ":";
        cout << right << setfill('0') << setw(2) << info.dest_time.minute << endl;
        cout << setfill(' '); //��������ַ�
    }
    if (info.total_seats != 0) cout << "����λ����" << info.total_seats <<"(��λĬ��800��)"<<endl << endl;
    switch (function)
    {
    case 1:
    { //���ݲ�����ʾ��ͬ����ʾ��Ϣ
        switch (step)
        {
        case 1:
        {   //��ʾ���κŹ���ʼ����ʾ�ڶ�����
            cout << "================================== ���κŹ��� ==================================" << endl;
            cout << "1. ���κű�����������ĸ��ͷ��G����������D����������C���Ǽʣ���Z��ֱ���T���ؿ죩��K�����٣�" << endl;
            cout << "2. ��ĸ��������1-4λ���֣���G101��D3215��K218��" << std::endl;
            cout << "3.  ���κŲ���Ϊ���ұ���Ψһ���������Ѵ��ڵĳ����ظ�" << std::endl;
            cout << "================================================================================" << endl << endl;
            switch (prompt)
            {
            case 1:cout << "���󣺳��κŲ���Ϊ�գ�" << endl; break;
            case 2:cout << "���󣺳��κŲ������Ѵ��ڵĳ����ظ���" << endl; break;
            case 3:cout << "���󣺳��κų��ȱ���Ϊ2-5���ַ��ַ���" << endl; break;
            case 4:cout << "���󣺳��κű��������G/D/C/Z/T/K��ͷ��" << endl; break;
            case 5:cout << "���󣺳��κų����ַ����������ַ�����ȫΪ����" << endl; break;
            }
            cout << "��������ӻ𳵵ĳ��κţ�" << endl;
        }
        break;
        case 2:
        case 3:
        {   //��ʾվ������
            cout << "=== ����վ��֤���� ===" << endl;
            cout << "վ�����ƹ���" << endl;
            cout << "1. ���԰������ĺ�Ӣ����ĸ" << endl;
            cout << "2. ��ʾ���Ϊ1-11��Ӣ���ַ���ȣ�Լ1-5�����֣�" << endl;
            cout << "3. ������ʹ�ó�Ӣ����ĸ���ASCII�ַ���������š������ַ��ȣ�" <<endl;
            cout << "4. ʾ��������(2����)��Beijing(7Ӣ��)���Ϻ�����(4����)" <<endl<<endl;
            switch (prompt)
            {
            case 1:cout << "����:" << (step == 2 ? "����" : "�յ�") << "վ��" <<"����Ϊ�գ�" << endl; break;
            case 2:cout << "����վ��������4-10��Ӣ�Ļ�2-5�����ģ�" << endl; break;
            }
            cout << "��������ӻ𳵵�" << (step == 2 ? "����" : "�յ�") << "վ��" << endl;
        }
        break;
        case 4:
        case 5:
        {   //����ʱ��͵���ʱ�����
            cout << "========== ʱ��������� ==========" << endl;
            cout << "1. ʱ���ʽ����Ϊ: YYYY-MM-DD HH:MM���ǵ�DD��HH�м���һ���ո�" << endl;
            cout << "2. ����ʱ������ڵ�ǰʱ��֮��" << endl;
            cout << "3. ����ʱ������ڳ���ʱ��֮��" << endl;
            cout << "4. ����ʱ���뵽��ʱ��������30����" << endl;
            cout << "5. ����ʱ���뵽��ʱ�������72Сʱ" << endl;
            cout << "==================================" << endl << endl;
            switch (prompt)
            {
            case 1:cout << "����" << (step == 4 ? "����" : "����") << "ʱ�䲻��Ϊ��" << endl; break;
            case 2:cout << "����ʱ���ʽû����ȫд�ɡ�YYYY-MM-DD HH:MM�����ǵ�DD��HH�м���һ���ո�"<< endl; break;
            case 3:cout << "�����·ݱ�����1-12��" << endl; break;
            case 4:cout << "���󣺸�������û�д�����" << endl; break;
            case 5:cout << "����Сʱ���߷��Ӳ���" << endl; break;
            case 6:cout << "���󣺳���ʱ������ڵ�ǰʱ��֮��" << endl; break;
            case 7:cout << "���� ����ʱ���뵽��ʱ��������30����,���72Сʱ" << endl; break;
            }
            cout << "��������ӻ𳵵�" << (step == 4 ? "����" : "����") << "ʱ�䣺" << endl;
        }
        break;
        case 6:
        {   switch(prompt)
            {   //ȷ����ӳ�Ʊ����������ʾ
            case 1:cout << "���󣺲���ֱ������س�����" << endl; break;
            case 2:cout << "��������ֻ������1��0��" << endl; break;
            case 3:cout << "����ֻ�����봿���֣�" << endl; break;
            }
            cout << "��ȷ�����²��������ֱ�ţ�" << endl;
            cout << "1.ȷ��" << endl;
            cout << "0.������һ����" << endl;
        }
        break;
        }
     }
    break;
    }
   
   
}


//��ʾ��¼�����Ա���������ܲ˵�
void login_admin_menu()
{
    system("cls");// ����
    cout << "��Ʊ����ϵͳ->ϵͳ����Ա����->��¼->����Ա����������"<<endl;
    cout << "��������������������������������" << endl;
    cout << "��1.��ӳ�Ʊ��Ϣ��" << endl;
    cout << "��������������������������������" << endl;
    cout << "��2.ɾ����Ʊ��Ϣ��" << endl;
    cout << "��������������������������������" << endl;
    cout << "��3.�޸ĳ�Ʊ��Ϣ��" << endl;
    cout << "��������������������������������" << endl;
    cout << "��4.��ѯ��Ʊ��Ϣ��" << endl;
    cout << "��������������������������������" << endl;
    cout << "��5.����û���Ϣ��" << endl;
    cout << "��������������������������������" << endl;
    cout << "��6.������һ���橦" << endl;
    cout << "��������������������������������" << endl;

}
//����Ա����������
void admin_functions()
{
    while (true)
    {
        login_admin_menu();//��ʾ��¼�����Ա���������ܲ˵�
        int login_admin_menu_choice = get_vaild_int(1, 6, 4);// ��¼�����Ա���������ܲ˵�������֤
        switch (login_admin_menu_choice)
        {
        case 1:
        {
            system("cls");// ����
            add_train_ticket();//��ӳ�Ʊ��Ϣ
            break;
        }
        case 2:
        {
            system("cls");// ����
            delete_train_ticket();//ɾ����Ʊ��Ϣ
            break;
        }
        case 3:
        {
            system("cls");// ����
            modify_train_ticket();//�޸ĳ�Ʊ��Ϣ
            break;
        }
        case 4:
        {
            system("cls");// ����
            search_train_ticket();//��ѯ��Ʊ��Ϣ
            break;
        }
        case 5:
        {
            system("cls");// ����
            add_user_info();//����û���Ϣ
            break;
        }
        case 6:
        {
            save_all_data();
            system("cls");// ����
            return;//������һ����
        }
        }
    }
}
// ϵͳ����Ա��¼
void admin_log_in() 
{
    login_initial_prompt(1, 1, 0);//��¼�����ʼ��ʾ��Ϣ
    while (true)
    {
        string username,password;
        getline(cin, username);
        username= trim(username);// ȥ���ַ���ǰ��ո�
        if (username == "0")//������0�򷵻���һ��
        {
            system("cls");// ����
            return;
        }
        login_initial_prompt(1,2,0,username);//��¼�����ʼ��ʾ��Ϣ
        password = getPassword();//��¼ʱ��ȡ������֧���л���ʾ״̬
        if (password == "0")//������0�򷵻���һ��
        {
            system("cls");// ����
            return;
        }
        //�ж�������û����������Ƿ���ƥ�����е�ע����Ϣ
        bool success = false;//���費ƥ�䣬Ҳ���ǵ�¼ʧ��
        Admin* current = admin_head;
        while (current != nullptr)
        {
            if (current->name == username && current->password == password)
            {   //�ɹ�ƥ�䵽���е�ע����Ϣ����¼�ɹ�
                success = true;
                break;
            }
            current = current->next;
        }
        if (success)
        {   
            system("cls");// ����
            admin_functions();//����Ա����������
            //��������
            return;
        }
        login_initial_prompt(1, 1, 1);//��¼�����ʼ��ʾ��Ϣ
    }
}

// ϵͳ����Աע��
void admin_register() 
{
    // ����1�������û���
    register_initial_prompt(1,0,1,0);//ע������ʼ��ʾ��Ϣ
    string username= name_check(1);
    if (username == "0")//ע�Ჽ������������֤(������0�򷵻���һ��)
    {
        system("cls");// ����
        return;
    }
    // ����2���������֤�ţ�����username��
    register_initial_prompt(1, 1, 2, 0,username);//ע������ʼ��ʾ��Ϣ
    string idNumber = id_check(1,username);
    if (idNumber == "0")//ע�Ჽ���������֤����֤(������0�򷵻���һ��)
    {
        system("cls");// ����
        return;
    }
    // ����3�������ֻ��ţ�����username��idNumber��
    register_initial_prompt(1, 1, 3, 0, username,idNumber);//ע������ʼ��ʾ��Ϣ
    string phone = phone_check(1, username,idNumber);
    if (phone == "0")//ע�Ჽ���������֤����֤(������0�򷵻���һ��)
    {
        system("cls");// ����
        return;
    }
    // ����4�������ֻ����ŷ�������֤�루����username��idNumber��phone��
    string code = code_check(1,username, idNumber, phone);
    if (code == "0")//ע�Ჽ���������֤����֤(������0�򷵻���һ��)
    {
        system("cls");// ����
        return;
    }
    if (code == "-1")//��ʱ��������������֤���Ǵ������֮ǰ��д��ע����Ϣ����ǿ�Ʒ�����һ����
    {
        for (int i = 3; i > 0; i--)
        {
            cout << "\r��һ���������������֤�룬" << i << "������֮ǰ��д��ע����Ϣ����ǿ�Ʒ�����һ����";
            cout.flush();//�������������е��������������̨����֤�����ܼ�ʱ��ʾ
            Sleep(1000);//��ͣ1��
        }
        system("cls");// ����
        return;
    }
    // ����5���������벢���ٴ�ȷ���������루����username��idNumber��phone��code��
    register_initial_prompt(1, 1, 5, 0, username, idNumber,phone,code);//ע������ʼ��ʾ��Ϣ
    string password = password_check(1,username, idNumber, phone,code);
    if (password == "0")//ע�Ჽ���������֤����֤(������0�򷵻���һ��)
    {
        system("cls");// ����
        return;
    }
    // �����µĹ���Ա�ڵ�
    Admin* newAdmin = new Admin;
    newAdmin->name = username;
    newAdmin->id = idNumber;
    newAdmin->phone = phone;
    newAdmin->password = password;
    newAdmin->next = nullptr;
    // ���¹���Ա��ӵ�����Ա�����ĩβ
    if (admin_head == nullptr) 
    {
        admin_head = newAdmin;
        admin_tail = newAdmin;// ��ʼ��ͷβָ��
    }
    else 
    {
        admin_tail->next = newAdmin;//βָ��ֱ�������½ڵ�
        admin_tail = newAdmin;// ����βָ��
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
// ϵͳ����Ա����
void admin_interface() {
    while (true)
    {
        show_admin_menu();// ��ʾϵͳ����Ա�˵�
        int admin_menu_choice = get_vaild_int(1,3,2);// ϵͳ����Ա�˵�������֤
        switch (admin_menu_choice)
        {
           case 1:
           {
               system("cls");// ����
               admin_register();
               break;
           }
           case 2:
           {
               system("cls");// ����
               admin_log_in();
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

// ����û���Ϣ
void add_user_info() {
    User* newUser = new User;
    cout << "�������û�����";
    getline(cin, newUser->name);
    cout << "���������֤���룺";
    getline(cin, newUser->id);
    cout << "�������ֻ��ţ�";
    getline(cin, newUser->phone);
    cout << "���������룺";
    getline(cin, newUser->password);
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
    cout << "�û���Ϣ��ӳɹ���" << endl;
    for (int i = 3; i > 0; i--)
    {
        cout << "\r������" << i << "��󷵻���һ����";
        cout.flush();//�������������е��������������̨����֤�����ܼ�ʱ��ʾ
        Sleep(1000);//��ͣ1��
    }
    system("cls");// ����
}

//��ӳ�Ʊ��Ϣ
void add_train_ticket()
{
    TrainInfo info;//ʹ�ýṹ�崢����ʱ��Ϣ
    // ����1�����복�κ�
    admin_functions_initial_prompt(1, 1, 0, info);//����Ա��ӳ�Ʊ��Ϣ�ĳ�ʼ��ʾ
    int prompt = 0;
    while (true)
    {
        getline(cin, info.number);//����Ա��ӳ�Ʊ��Ϣ�ĳ�ʼ��ʾ
        info.number = trim(info.number);//ȥ���ַ���ǰ��ո�
        if (info.number == "0")// ����0�򷵻���һ�� 
        {
            system("cls"); // ����
            return;
        }
        //��鳵�κ��Ƿ���Ϲ���
        if (number_check(info.number, prompt)) break;
        admin_functions_initial_prompt(1, 1, prompt, info);
    }
    //����2���������վ
    admin_functions_initial_prompt(1, 2, 0, info);//����Ա��ӳ�Ʊ��Ϣ�ĳ�ʼ��ʾ
    while (true)
    {
        getline(cin, info.dep);
        info.dep = trim(info.dep);//ȥ���ַ���ǰ��ո�
        if (info.dep == "0")// ����0�򷵻���һ�� 
        {
            system("cls"); // ����
            return;
        }
        //���վ���Ƿ���Ϲ���
        if (station_check(info.dep, prompt)) break;
        admin_functions_initial_prompt(1, 2, prompt, info);
    }
    //����3�������յ�վ
    admin_functions_initial_prompt(1, 3, 0, info);//����Ա��ӳ�Ʊ��Ϣ�ĳ�ʼ��ʾ
    while (true)
    {
        getline(cin, info.dest);
        info.dest = trim(info.dest);//ȥ���ַ���ǰ��ո�
        if (info.dest == "0")// ����0�򷵻���һ�� 
        {
            system("cls"); // ����
            return;
        }
        //���վ���Ƿ���Ϲ���
        if (station_check(info.dest, prompt)) break;
        admin_functions_initial_prompt(1, 3, prompt, info);
    }
    //����4���������ʱ��
    admin_functions_initial_prompt(1, 4, 0, info);//����Ա��ӳ�Ʊ��Ϣ�ĳ�ʼ��ʾ
    while (true)
    {
        getline(cin, info.deptime);
        info.deptime = trim(info.deptime);//ȥ���ַ���ǰ��ո�
        if (info.deptime == "0")// ����0�򷵻���һ�� 
        {
            system("cls"); // ����
            return;

        }
        //������ʱ���Ƿ���Ϲ���
        if (dep_time_check(info.deptime, prompt))
        {   //��ʱ���ַ���ת��ΪDataTime�ṹ��
            info.dep_time = string_to_DataTime(info.deptime);
            break;
        }
        admin_functions_initial_prompt(1, 4, prompt, info);
    }

    //����5�����뵽��ʱ��
    admin_functions_initial_prompt(1, 5, 0, info);//����Ա��ӳ�Ʊ��Ϣ�ĳ�ʼ��ʾ
    while (true)
    {
        getline(cin, info.desttime);
        info.desttime = trim(info.desttime);//ȥ���ַ���ǰ��ո�
        if (info.desttime == "0")// ����0�򷵻���һ�� 
        {
            system("cls"); // ����
            return;
        }
        //��鵽��ʱ���Ƿ���Ϲ���
        if (dest_time_check(info.dep_time, info.desttime, prompt))
        {   //��ʱ���ַ���ת��ΪDataTime�ṹ��
            info.dest_time = string_to_DataTime(info.desttime);
            break;
        }
        admin_functions_initial_prompt(1, 5, prompt, info);
    }
    info.total_seats = total_seats;//������λ���̶�800��

    //��ӳ�Ʊ�����ʾ���������ȷ��Ϣ
    admin_functions_initial_prompt(1, 6, 0, info);
    while (true)
    {
        int confirm = isConfirm(prompt);//ȷ��Ŀǰ����
        if (confirm == 1) break;//ȷ����ӳ�Ʊ�����ɹ�
        if (confirm == 0)//������һ����
        {
            system("cls"); // ����
            return;
        }
        admin_functions_initial_prompt(1, 6, prompt, info);
    }
    // �����³���
    Train* newTrain = new Train;
    newTrain->number = info.number;
    newTrain->dep = info.dep;
    newTrain->dest = info.dest;
    newTrain->dep_time = info.dep_time;
    newTrain->dest_time = info.dest_time;
    newTrain->total_seats = info.total_seats;
    newTrain->remain_seats = info.total_seats;
    newTrain->price = 100;//Ĭ�ϼ۸�
    newTrain->next = nullptr;
    // ��ӵ���������
    if (train_head == nullptr) {
        train_head = train_tail = newTrain;
    }
    else {
        train_tail->next = newTrain;
        train_tail = newTrain;
    }
}

      
// ɾ����Ʊ��Ϣ
void delete_train_ticket() {
    Train* current = train_head;
    Train* prev = nullptr;
    int choice;
    system("cls");
    cout << "��Ʊ����ϵͳ->ϵͳ����Ա����->��¼->����Ա�������->ɾ����Ʊ��Ϣ" << endl;
    cout << "��ѡ������Ҫɾ���ĳ��Σ�" << endl;
    // ��ʾ���г�����Ϣ
    int index = 1;
    while (current != nullptr) {
        cout << index << "." << current->number << " " << current->dep << " " << current->dest
            << formatTime(current->dep_time)
            << "����"
            << formatTime(current->dest_time) << endl;
        current = current->next;
        index++;
    }
    cout << "0.������һ��" << endl;
    cout << "����������ѡ��";
    while (1)
    {
        int temp;
        temp = scanf_s("%d", &choice);
        if (choice == 0) {
            system("cls");
            return;
        }
        if (temp!= 1) //scanf��ȡ����ȡʧ�ܷ���0��������ȡ����1
        {
            cout<<"��������������ѡ��"<<endl;
            while (getchar() != '\n'); // ��ջ�����
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
            cout << "ɾ���ɹ���" << endl;
            for (int i = 3; i > 0; i--) {
                cout << "\r������" << i << "��󷵻���һ����";
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
    cout << "ɾ��ʧ�ܣ���Ч��ѡ��" << endl;
    for (int i = 3; i > 0; i--) {
        cout << "\r������" << i << "��󷵻���һ����";
        cout.flush();
        Sleep(1000);
    }
    system("cls");
}

// �޸ĳ�Ʊ��Ϣ
void modify_train_ticket() {
    Train* current = train_head;
    int choice=0;
    system("cls");
    cout << "��Ʊ����ϵͳ->ϵͳ����Ա����->��¼->����Ա�������->�޸ĳ�Ʊ��Ϣ" << endl;
    cout << "��ѡ������Ҫ�޸ĵĳ��Σ�" << endl;
    // ��ʾ���г�����Ϣ
    int index = 1;
    while (current != nullptr) {
        cout << index << "." << current->number << " " << current->dep << " " << current->dest
            << formatTime(current->dep_time)
            << "����"
            << formatTime(current->dest_time) << endl;
        current = current->next;
        index++;
    }
    cout << "0.������һ��" << endl;
    cout << "����������ѡ��";
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
            system("cls");
            cout << "��ǰ������Ϣ��" << endl;
            cout << "���κţ�" << current->number << endl;
            cout << "��ʼվ��" << current->dep << endl;
            cout << "�յ�վ��" << current->dest << endl;
            cout << "����ʱ�䣺" << formatTime(current->dep_time) << endl;
            cout << "����ʱ�䣺" << formatTime(current->dest_time) << endl;
            cout << "Ʊ�ۣ�" << current->price << endl;
            //cout << "����λ����" << current->total_seats << endl;
            //cout << "ʣ����λ����" << current->remain_seats << endl;
            cout << "�������µĳ��κţ�ֱ�ӻس������޸ģ���";
            string input;
            cin.ignore(); // ������뻺����
            getline(cin, input);
            if (!input.empty()) {
                current->number = input;
            }
            cout << "�������µ���ʼվ��ֱ�ӻس������޸ģ���";
            getline(cin, input);
            if (!input.empty()) {
                current->dep = input;
            }
            cout << "�������µ��յ�վ��ֱ�ӻس������޸ģ���";
            getline(cin, input);
            if (!input.empty()) {
                current->dest = input;
            }
            cout << "�������µĳ���ʱ�䣨��ʽ��YYYY-MM-DD HH:MM��ֱ�ӻس������޸ģ���";
            getline(cin, input);
            if (!input.empty()) {
                current->dep_time = string_to_DataTime(input);
            }
            cout << "�������µĵ���ʱ�䣨��ʽ��YYYY-MM-DD HH:MM��ֱ�ӻس������޸ģ���";
            getline(cin, input);
            if (!input.empty()) {
                current->dest_time = string_to_DataTime(input);
            }
            cout << "�������µ�Ʊ�ۣ�ֱ�ӻس������޸ģ���";
            getline(cin, input);
            if (!input.empty()) {
                current->price = stoi(input);
            }
            cout << "�޸ĳɹ���" << endl;
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
    cout << "�޸�ʧ�ܣ���Ч��ѡ��" << endl;
    for (int i = 3; i > 0; i--) {
        cout << "\r������" << i << "��󷵻���һ����";
        cout.flush();
        Sleep(1000);
    }
    system("cls");
}


// ��ѯ��Ʊ��Ϣ
void search_train_ticket() {
    Train* current = train_head;
    system("cls");
    cout << "��Ʊ����ϵͳ->ϵͳ����Ա����->��¼->����Ա�������->��ѯ��Ϣ" << endl;
    cout << "�������ѯ���������κ�/��ʼվ/�յ�վ������1��ѯ���У���";
    string keyword;
    cin >> keyword;
    if (keyword=="1") {
        // ��ʾ���г�����Ϣ
        while (current != nullptr) {
            cout << "���κţ�" << current->number << endl;
            cout << "��ʼվ��" << current->dep << endl;
            cout << "�յ�վ��" << current->dest << endl;
            cout << "����ʱ�䣺" << formatTime(current->dep_time) << endl;
            cout << "����ʱ�䣺" << formatTime(current->dest_time) << endl;
            cout << "Ʊ�ۣ�" << current->price << endl;
            cout << "��Ʊ��" << current->remain_seats << "/" << current->total_seats << endl;
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
                cout << "���κţ�" << current->number << endl;
                cout << "��ʼվ��" << current->dep << endl;
                cout << "�յ�վ��" << current->dest << endl;
                cout << "����ʱ�䣺" << formatTime(current->dep_time) << endl;
                cout << "����ʱ�䣺" << formatTime(current->dest_time) << endl;
                cout << "Ʊ�ۣ�" << current->price << endl;
                cout << "��Ʊ��" << current->remain_seats << "/" << current->total_seats << endl;
                cout << "----------------------------------------" << endl;
            }
            current = current->next;
        }
        if (!found) {
            cout << "δ�ҵ�ƥ��ĳ�����Ϣ��" << endl;
        }
    }
    cout << "�������������һ����...";
    cin.get();
    cin.get();
    system("cls");
}


