/*
�����ܣ��Ӽ���������һ��������ͳ�Ƹ�������λ��
������Ա������Դ2020300002043
����ʱ�䣺2021.7.2
�޸�ʱ�䣺
*/

#include<stdio.h>
#include<stdlib.h>

int main(void){

	int num, count=1;

	printf("������һ������\n");
	scanf("%d",&num);

	if (num < 0)//������Ϊ����
	{
		num *= -1;
	}	
	while (num / 10 != 0)
	{
		num = num/10;
		count++;
	}
	printf("�������������%dλ��\n",count);

	system("pause");
	return 0;
}