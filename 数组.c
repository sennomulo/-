/*
�����ܣ��������������н������򣬲��ҽ�����Ԫ�ش�ӡ���
������Ա������Դ2020300002043
����ʱ�䣺2021.7.8
�޸�ʱ�䣺
*/

#include<stdio.h>
#include<stdlib.h>
#define N 5		//NΪһά�����С������ȡ5
void arrange(float a[], int n);//������Ԫ�ؽ��н�������
void print(float a[], int n);//��ӡ�������Ԫ��

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

	printf("��������������Ԫ��\n");
	for(i = 0; i<N; i++)
	{
		scanf("%f",&a[i]);
	}
	//��������Ԫ��

	arrange(a, N);//��������н�������

	printf("����������н��������õ��Ľ��Ϊ��\n");
	print(a, N);
	printf("\n");//�������Ԫ��

	system("pause");
	return 0;
}