#include"data.h"
#include"utils.h"
#include"admin.h"
#include"user.h"
#include"save.h"
int main()
{   
    cout.flush();
    load_all_data(); // ��������
    while(true)
    {   show_main_menu();//��ʾ�������˵�
        int choice = get_vaild_int(1,3,1);//���˵�������֤
        switch (choice)
        {   case 1:
            {
               system("cls");// ����
               admin_interface();
               break;
            }
            case 2:
            {
                system("cls");// ����
                user_interface();
                break;
            }
            case 3:
            {
                save_all_data();//������������
                return 0;
            }
        }
    }
}