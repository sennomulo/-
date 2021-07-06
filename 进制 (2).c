/*
程序功能：将用户输入的十进制数转换成2-61以内任意进制的数。
开发人员：杨赖源2020300002043
开发时间：2021.7.6
修改时间：2021.7.6
*/

#include <stdio.h>
#include <stdio.h>

int main(void) 
{
	int i = 0, base, num[32] = {0}, n;
	float n0, base0;//n0, base0用于检验输入的合法性
	char c, ch;	//c用于输出最终的结果
	
	printf("This program can convert a positive number in decimal system into any other system of numeretion (2-61).\n");

	do 
	{
		printf("Input num:");//输入被转化的数字n
		scanf("%f", &n0);
		while(n0 <= 0 || (int)n0 * 1.0 != n0){
			printf("The input is invalid. Please input an integer > 0.\n");
			fflush(stdin);
			scanf("%f", &n0);//防止用户输入非法数据
		}
		n = (int)n0;

		printf("Input base:");/* 输入要转换的进制base */
		scanf("%f", &base0);
		while(base0 <=1 || base0 > 61 || (int)base0 * 1.0 != base0){
			printf("The input is invalid. Please input an integer > 1 and <= 61.\n");
			fflush(stdin);
			scanf("%f", &base0);//防止用户输入非法数据
		}
		base = (int)base0;

		/* 进制转换 */
		for (i = 0; n != 0; i++)
		{
			num[i] =  n % base   ;
			n =   n / base    ;
		}

		/* 结果输出 */
		printf("the result is:");
		if(base <= 10)
		{//十以内的进制不需要额外的字母
			for (--i; i >= 0; i--) 
			{				
				c = num[i];
				printf("%d", c);		
			}
			printf("\n\n");			
		}
		else if (base <= 36)
		{//11-36进制，使用A-Z来分别代替10-35
			for (--i; i >= 0; i--) 
					{
						if (num[i] >= 0 && num[i] <= 9) 
						{
							//数字在0-9之间的，原样输出
							c = num[i];
							printf("%d", c);
						} 
						else if (num[i] >= 10 && num[i] <= 35) 
						{
							//数字大于9而小于36的，转化为大写英文字母输出（用ASCII码）
							c = num[i] + 55;
							printf("%c", c);
						} 					
					}
			printf("\n(A-Z represent 10-35 respectively.)\n\n");
		}
		else
		{//37-62进制，使用a-z来分别表示36-61
			for (--i; i >= 0; i--) 
				{
					if (num[i] >= 0 && num[i] <= 9) 
					{
						//数字在0-9之间的，原样输出
						c = num[i];
						printf("%d", c);
					} 
					else if (num[i] >= 10 && num[i] <= 35) 
					{
						//数字大于9而小于36的，转化为大写英文字母输出（用ASCII码）
						c = num[i] + 55;
						printf("%c", c);
					} 
					else if (num[i] > 35 && num[i] <= 61) 
					{
						//数字大于35而小于62的，转化为小写英文字母输出（用ASCII码）
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
