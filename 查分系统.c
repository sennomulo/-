/*
�����ܣ���1��¼�뿼�Գɼ������Ӷ���������������ֵ���Ĵ���
		��2������ܷ���ߺ���͵�ѧ����ѧ�ţ�
		��3�����������ѧ��ѧ�ţ�����������ο��Գɼ���ƽ���ɼ���
		��4����������Ŀ��Դ���������ôο�����ÿ��ѧ���ĳɼ�����ο��Ե�ƽ���ɼ���
������Ա������Դ2020300002043
����ʱ�䣺2021.7.7
�޸�ʱ�䣺
*/

#include <stdio.h>
#include <stdlib.h>
#define M 4   // ѧ������
#define N 6   // �γ�����

int main(void)
{
	float score[M][N], sum[M] = {0}, aver[M] = {0}, sum_score, aver_score, sh, sl;
	int i, j, high, low;//sh,high�ֱ��ʾ����ֺܷͶ�Ӧ��ѧ��ѧ�ţ�sl,low�ֱ��ʾ����ֺܷͶ�Ӧ��ѧ��ѧ��
	char ch;
	int opt;

	for (i = 0; i < M; i++)
	{
		printf("������ѧ��Ϊ%d��ѧ���ĳɼ�\n", i + 1);
		for (j = 0; j < N; j++)
		{
			scanf("%f", &score[i][j]);
			while (score[i][j] < 0 || score[i][j] > 100)
			{
				printf("���������������������һ��0-100�ĳɼ�\n");
				scanf("%f", &score[i][j]);
			}
			/* ���������ݵĹ������ж������Ƿ�����0~100������ */
			sum[i] += score[i][j];
		}
		aver[i] = sum[i] / N;
		/* ����ÿ��ѧ�����ֺܷ�ƽ���֣���һά����sum��aver�е���ӦԪ�طֱ�洢ѧ�����ֺܷ�ƽ���� */
	}

	/* ��һά����sum���ҵ���߷ֺ���ͷֵ�Ԫ���±� */
	sh = sl = sum[0];
	high = low = 0;
	for (i = 1; i < M; i++)
	{
		if (sh < sum[i])
		{
			sh = sum[i];
			high = i;
		}
		if (sl > sum[i])
		{
			sl = sum[i];
			low = i;
		}
	}

	printf("\n%d��ѧ���ܷ����,%d��ѧ���ܷ����\n\n", high + 1, low + 1);

	do
	{
		printf("��ѡ�����Ĳ�ѯ��Ŀ����ѯ����ѧ���ɼ���������1����ѯ���ο��Գɼ���������2��\n");
		scanf("%d", &opt);
		while (opt != 1 && opt != 2)
		{
			printf("�������������1����2��\n");
			scanf("%d", &opt);
		}
		switch (opt)
		{
			case 1:
			{
				printf("������ѧ��ѧ�ţ�");
				scanf("%d", &i);
				while ((i < 1) || (i > 4))
				{
					printf("�������ѧ�Ų���ϵͳ��Χ�ڣ����������룺\n");
					scanf("%d", &i);
				}
				i--;
				/* �����ά����score��һά����aver�ж�Ӧ��ѧ�����ο��Գɼ���ƽ���ɼ� */
				printf("�����ĸ��ο��Գɼ��ֱ�Ϊ��\n");
				for (j = 0; j < N; j++)
				{
					printf("%-7.2f", score[i][j]);
				}
				printf("\n������ƽ���ɼ�Ϊ��%.2f\n\n", aver[i]);
				break;
			}

			case 2:
			{
				printf("�����뿼�Դ���:");
				scanf("%d", &j);
				while ((j < 1) || (j > 6))
				{
					printf("������Ŀ��Դ�������ϵͳ��Χ�ڣ����������룺\n");
					scanf("%d", &j);
				}
				j--;
				sum_score = 0;
				/* �����ά����score�ж�Ӧ�Ŀ�����ÿ��ѧ���ĳɼ�����������ο��Ե�ƽ���ɼ� */
				printf("�ڱ��ο����У�ѧ��Ϊ1��%d��ͬѧ�ĳɼ��ֱ�Ϊ��\n", M);
				for (i = 0; i < M; i++)
				{
					printf("%-7.2f", score[i][j]);
					sum_score += score[i][j];
				}
				aver_score = sum_score / M;
				printf("ƽ���ɼ�:%.2f\n\n", aver_score);
				break;
			}
		}

		printf("�������Ƿ�Ҫ������ѯ����y/n��");
		fflush(stdin);
		ch = getchar();
	}
	while (ch == 'y' || ch == 'Y');

	system("pause");
	return 0;
}
