/*
程序功能：将用户输入的十进制数转换成任意进制的数。
开发人员：杨赖源2020300002043
开发时间：2021.7.6
修改时间：
*/

#include <stdio.h>
#include <stdio.h>

int main(void) 
{
	int i = 0, base, num[32] = {0}, n;
	char c, ch;	//c用于输出最终的结果

	do 
	{
		printf("Input num:");
		scanf("%d", &n);

		printf("Input base:");
		scanf("%d", &base);
		/* 输入要转换的进制base */

		/* 进制转换 */
		for (i = 0; n != 0; i++)
		{
			num[i] =  n % base   ;
			n =   n / base    ;
		}

		/* 结果输出 */
		if (base > 61) 
		{
			//防止用户乱来
			printf("不会吧不会吧，不会有人真想要这么大的进制吧？\n");
		} 
		else 
		{
			printf("the result is:");
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
		}

		printf("\n(A-Z represent 10-35 respectively,\nwhile a-z represents 36-61 respectively)\n\n");

		printf("Do you want to continue?(y/n)\n");
		fflush(stdin);
		ch = getchar();
	} while (ch == 'y' || ch == 'Y');

	system("pause");
	return 0;
}
