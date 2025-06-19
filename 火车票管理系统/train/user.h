//user.h
#ifndef USER_H
#define USER_H
#include"data.h"
void user_interface();//用户界面
void user_log_in();//用户登录
void user_register();// 用户注册
void login_user_menu();
void user_services();
void query_user_tickets(User* currentUser);//查询信息
void change_ticket(User* currentUser);//改签
void refund_ticket(User* currentUser);//退票
void purchase_ticket(User* currentUser);//购票
#endif
