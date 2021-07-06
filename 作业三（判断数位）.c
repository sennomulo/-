/*
程序功能：从键盘上输入一个整数，统计该整数的位数
开发人员：杨赖源2020300002043
开发时间：2021.7.2
修改时间：
*/

#include<stdio.h>
#include<stdlib.h>

int main(void){

	int num, count=1;

	printf("请输入一个整数\n");
	scanf("%d",&num);

	if (num < 0)//化负数为正数
	{
		num *= -1;
	}	
	while (num / 10 != 0)
	{
		num = num/10;
		count++;
	}
	printf("您输入的整数有%d位数\n",count);

	system("pause");
	return 0;
}