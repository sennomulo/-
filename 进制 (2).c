/*
�����ܣ����û������ʮ������ת����������Ƶ�����
������Ա������Դ2020300002043
����ʱ�䣺2021.7.6
�޸�ʱ�䣺
*/

#include <stdio.h>
#include <stdio.h>

int main(void) 
{
	int i = 0, base, num[32] = {0}, n;
	char c, ch;	//c����������յĽ��

	do 
	{
		printf("Input num:");
		scanf("%d", &n);

		printf("Input base:");
		scanf("%d", &base);
		/* ����Ҫת���Ľ���base */

		/* ����ת�� */
		for (i = 0; n != 0; i++)
		{
			num[i] =  n % base   ;
			n =   n / base    ;
		}

		/* ������ */
		if (base > 61) 
		{
			//��ֹ�û�����
			printf("����ɲ���ɣ�������������Ҫ��ô��Ľ��ưɣ�\n");
		} 
		else 
		{
			printf("the result is:");
			for (--i; i >= 0; i--) 
			{
				if (num[i] >= 0 && num[i] <= 9) 
				{
					//������0-9֮��ģ�ԭ�����
					c = num[i];
					printf("%d", c);
				} 
				else if (num[i] >= 10 && num[i] <= 35) 
				{
					//���ִ���9��С��36�ģ�ת��Ϊ��дӢ����ĸ�������ASCII�룩
					c = num[i] + 55;
					printf("%c", c);
				} 
				else if (num[i] > 35 && num[i] <= 61) 
				{
					//���ִ���35��С��62�ģ�ת��ΪСдӢ����ĸ�������ASCII�룩
					c = num[i] + 61;
					printf("%c", c);
				}
			}
		}

		printf("\n(A-Z represent 10-35 respectively,\nwhile a-z represents 36-61 respectively)\n\n");

		printf("Do you want to continue?(y/n)\n");
		fflush(stdin);
		ch = getchar();
	} while (ch == 'y' || ch == 'Y');

	system("pause");
	return 0;
}
