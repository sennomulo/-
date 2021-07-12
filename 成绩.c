/*
程序功能：计算一组成绩的平均分 并实现按需排序
开发人员：杨赖源2020300002043
开发时间：2021.7.12
修改时间：*/

#include<stdio.h>
#include<stdlib.h>
float output(float s[],int n);//用于输出
float* create(int size); //创建一个大小为size的int型动态数组动态数组
void input(float s[], int n); //输入n个数组元素的值
float average(float s[], int n); //计算平均分
void sort(float s[], int n, int order); // order为0时升序、order为非0时降序

int main(void)
{
	float *s;
	int n, order;

	printf("请输入待统计的成绩个数\n");
	scanf("%d",&n);
	s = create(n);

	input(s,n);

	printf("平均分是：%.2f\n",average(s,n));
	printf("请输入排序选项（0是升序，非零是降序）：\n");
	scanf("%d",&order);
	sort(s,n,order);
	output(s,n);
	
	system("pause");
	return 0;
}

float* create(float size)
{
	float *p;

	p = (float *)malloc(sizeof(int) * size);
	if(p == NULL)
	{
		printf("创建数组失败");
		exit(1);
	}

	return p;
}

void input(float s[], int n)
{
	int i;

	printf("请输入%d个待统计的成绩\n", n);
	for(i=0;i < n; i++)
	{
		scanf("%f",&s[i]);
		while(s[i] < 0 || s[i] > 100)//防止用户输入非法字符
		{
			fflush(stdin);
			printf("您输入的数据非法。请输入一个0-100以内的成绩。\n");			
			scanf("%f",&s[i]);
		}
	}
	
	return;
}

float average(float s[], int n)
{
	int i;
	float sum = 0;
	for(i = 0; i < n; i++)
	{
		sum += s[i];
	}
	return (sum / n);
}

void sort(float s[], int n, int order)
{
	int i, j;
	float t;
	if(order)//order为非零时降序排列
	{
		for(i = 0; i < n; i++)
		{
			for(j = i + 1; j < n; j++)
			{
				if(s[i] < s[j])
				{
					t = s[i];
					s[i] = s[j];
					s[j] = t;
				}
			}
		}
	}
	else//order为零时升序排列
	{
		for(i = 0; i < n; i++)
		{
			for(j = i + 1; j < n; j++)
			{
				if(s[i] > s[j])
				{
					t = s[i];
					s[i] = s[j];
					s[j] = t;
				}
			}
		}
	}
	return;
}

float output(float s[],int n)
{
	int i;

	printf("排序后的成绩为：\n");
	for(i = 0; i < n; i++)
	{
		printf("%.2f\t",s[i]);
	}
	printf("\n");
	return;
}