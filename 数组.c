/*
程序功能：将输入的数组进行降序排序，并且将数组元素打印输出
开发人员：杨赖源2020300002043
开发时间：2021.7.8
修改时间：
*/

#include<stdio.h>
#include<stdlib.h>
#define N 5		//N为一维数组大小，这里取5
void arrange(float a[], int n);//将数组元素进行降序排列
void print(float a[], int n);//打印输出数组元素

void arrange(float a[], int n)
{
	int i, j, k;
	for (i=0; i<n-1; i++)
	{
		for (j= i; j<n;j++)
		{
			if(a[i]<a[j])
			{
				k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}
}

void print(float a[], int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%-7.2f",a[i]);
	}
}

int main(void)
{
	float a[N];
	int i;

	printf("请依次输入数组元素\n");
	for(i = 0; i<N; i++)
	{
		scanf("%f",&a[i]);
	}
	//输入数组元素

	arrange(a, N);//对数组进行降序排序

	printf("将该数组进行降序排序后得到的结果为：\n");
	print(a, N);
	printf("\n");//输出数组元素

	system("pause");
	return 0;
}