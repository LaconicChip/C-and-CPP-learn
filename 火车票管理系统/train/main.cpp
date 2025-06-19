#include"data.h"
#include"utils.h"
#include"admin.h"
#include"user.h"
#include"save.h"
int main()
{   
    cout.flush();
    load_all_data(); // 加载数据
    while(true)
    {   show_main_menu();//显示居中主菜单
        int choice = get_vaild_int(1,3,1);//主菜单输入验证
        switch (choice)
        {   case 1:
            {
               system("cls");// 清屏
               admin_interface();
               break;
            }
            case 2:
            {
                system("cls");// 清屏
                user_interface();
                break;
            }
            case 3:
            {
                save_all_data();//保存所有数据
                return 0;
            }
        }
    }
}