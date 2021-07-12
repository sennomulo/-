/*
�����ܣ�����һ��ɼ���ƽ���� ��ʵ�ְ�������
������Ա������Դ2020300002043
����ʱ�䣺2021.7.12
�޸�ʱ�䣺*/

#include<stdio.h>
#include<stdlib.h>
float output(float s[],int n);//�������
float* create(int size); //����һ����СΪsize��int�Ͷ�̬���鶯̬����
void input(float s[], int n); //����n������Ԫ�ص�ֵ
float average(float s[], int n); //����ƽ����
void sort(float s[], int n, int order); // orderΪ0ʱ����orderΪ��0ʱ����

int main(void)
{
	float *s;
	int n, order;

	printf("�������ͳ�Ƶĳɼ�����\n");
	scanf("%d",&n);
	s = create(n);

	input(s,n);

	printf("ƽ�����ǣ�%.2f\n",average(s,n));
	printf("����������ѡ�0�����򣬷����ǽ��򣩣�\n");
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
		printf("��������ʧ��");
		exit(1);
	}

	return p;
}

void input(float s[], int n)
{
	int i;

	printf("������%d����ͳ�Ƶĳɼ�\n", n);
	for(i=0;i < n; i++)
	{
		scanf("%f",&s[i]);
		while(s[i] < 0 || s[i] > 100)//��ֹ�û�����Ƿ��ַ�
		{
			fflush(stdin);
			printf("����������ݷǷ���������һ��0-100���ڵĳɼ���\n");			
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
	if(order)//orderΪ����ʱ��������
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
	else//orderΪ��ʱ��������
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

	printf("�����ĳɼ�Ϊ��\n");
	for(i = 0; i < n; i++)
	{
		printf("%.2f\t",s[i]);
	}
	printf("\n");
	return;
}