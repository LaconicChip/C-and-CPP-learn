//user.h
#ifndef USER_H
#define USER_H
#include"data.h"
void user_interface();//�û�����
void user_log_in();//�û���¼
void user_register();// �û�ע��
void login_user_menu();
void user_services();
void query_user_tickets(User* currentUser);//��ѯ��Ϣ
void change_ticket(User* currentUser);//��ǩ
void refund_ticket(User* currentUser);//��Ʊ
void purchase_ticket(User* currentUser);//��Ʊ
#endif
