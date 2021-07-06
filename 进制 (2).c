/*
�����ܣ����û������ʮ������ת����2-61����������Ƶ�����
������Ա������Դ2020300002043
����ʱ�䣺2021.7.6
�޸�ʱ�䣺2021.7.6
*/

#include <stdio.h>
#include <stdio.h>

int main(void) 
{
	int i = 0, base, num[32] = {0}, n;
	float n0, base0;//n0, base0���ڼ�������ĺϷ���
	char c, ch;	//c����������յĽ��
	
	printf("This program can convert a positive number in decimal system into any other system of numeretion (2-61).\n");

	do 
	{
		printf("Input num:");//���뱻ת��������n
		scanf("%f", &n0);
		while(n0 <= 0 || (int)n0 * 1.0 != n0){
			printf("The input is invalid. Please input an integer > 0.\n");
			fflush(stdin);
			scanf("%f", &n0);//��ֹ�û�����Ƿ�����
		}
		n = (int)n0;

		printf("Input base:");/* ����Ҫת���Ľ���base */
		scanf("%f", &base0);
		while(base0 <=1 || base0 > 61 || (int)base0 * 1.0 != base0){
			printf("The input is invalid. Please input an integer > 1 and <= 61.\n");
			fflush(stdin);
			scanf("%f", &base0);//��ֹ�û�����Ƿ�����
		}
		base = (int)base0;

		/* ����ת�� */
		for (i = 0; n != 0; i++)
		{
			num[i] =  n % base   ;
			n =   n / base    ;
		}

		/* ������ */
		printf("the result is:");
		if(base <= 10)
		{//ʮ���ڵĽ��Ʋ���Ҫ�������ĸ
			for (--i; i >= 0; i--) 
			{				
				c = num[i];
				printf("%d", c);		
			}
			printf("\n\n");			
		}
		else if (base <= 36)
		{//11-36���ƣ�ʹ��A-Z���ֱ����10-35
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
					}
			printf("\n(A-Z represent 10-35 respectively.)\n\n");
		}
		else
		{//37-62���ƣ�ʹ��a-z���ֱ��ʾ36-61
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
			printf("\n(A-Z represent 10-35 respectively,\nwhile a-z represents 36-61 respectively)\n\n");
		}

		printf("Do you want to continue?(y/n)\n");
		fflush(stdin);
		ch = getchar();
	} while (ch == 'y' || ch == 'Y');

	system("pause");
	return 0;
}
