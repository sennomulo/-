#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100	//最大容书量

struct Book     // 定义图书结构体类型
{
	char book_num[3];
	char book_name[30];
	char first_author[10];
	char publisher[20];
	int  publication_year;
	float book_price;
};

struct Book_System     // 定义图书系统结构体类型
{
	struct Book booklist[MAX];
	int size;
};

int menu(void);	//显示菜单
void add_book(struct Book_System *fp);	//新增书籍
void delete_book(struct Book_System *fp);	//删除书籍
void edit_book(struct Book_System *fp);	//修改书籍
void search_book(struct Book_System *fp);	//查找书籍
void display_book(struct Book_System *fp);	//显示书籍
void clear_book(struct Book_System *fp);	//清空书籍
void get_data(struct Book_System *fp);	//读取数据
void rewrite_data(struct Book_System *bs);	//重新写入数据
void delete_rewrite_book(struct Book_System *bs, int j);	//删除后重新写入数据

int input_check_year (void);	//年份的输入检查
float input_check_price (void);		//价格的输入检查
void input_check_string (char temp[], int n);		//字符串的输入检查
