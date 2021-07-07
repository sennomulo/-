/*
程序功能：（1）录入考试成绩，增加对输入错误参数（负值）的处理；
		（2）输出总分最高和最低的学生的学号；
		（3）根据输入的学生学号，输出该生各次考试成绩和平均成绩；
		（4）根据输入的考试次数，输出该次考试中每个学生的成绩和这次考试的平均成绩；
开发人员：杨赖源2020300002043
开发时间：2021.7.7
修改时间：
*/

#include <stdio.h>
#include <stdlib.h>
#define M 4   // 学生人数
#define N 6   // 课程门数

int main(void)
{
	float score[M][N], sum[M] = {0}, aver[M] = {0}, sum_score, aver_score, sh, sl;
	int i, j, high, low;//sh,high分别表示最高总分和对应的学生学号；sl,low分别表示最低总分和对应的学生学号
	char ch;
	int opt;

	for (i = 0; i < M; i++)
	{
		printf("请输入学号为%d的学生的成绩\n", i + 1);
		for (j = 0; j < N; j++)
		{
			scanf("%f", &score[i][j]);
			while (score[i][j] < 0 || score[i][j] > 100)
			{
				printf("您输入的数据有误。请输入一个0-100的成绩\n");
				scanf("%f", &score[i][j]);
			}
			/* 在输入数据的过程中判断数据是否满足0~100的条件 */
			sum[i] += score[i][j];
		}
		aver[i] = sum[i] / N;
		/* 计算每个学生的总分和平均分，用一维数组sum和aver中的相应元素分别存储学生的总分和平均分 */
	}

	/* 在一维数组sum中找到最高分和最低分的元素下标 */
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

	printf("\n%d号学生总分最高,%d号学生总分最低\n\n", high + 1, low + 1);

	do
	{
		printf("请选择您的查询项目（查询单个学生成绩，请输入1，查询单次考试成绩，请输入2）\n");
		scanf("%d", &opt);
		while (opt != 1 && opt != 2)
		{
			printf("输入错误。请输入1或者2。\n");
			scanf("%d", &opt);
		}
		switch (opt)
		{
			case 1:
			{
				printf("请输入学生学号：");
				scanf("%d", &i);
				while ((i < 1) || (i > 4))
				{
					printf("您输入的学号不在系统范围内，请重新输入：\n");
					scanf("%d", &i);
				}
				i--;
				/* 输出二维数组score和一维数组aver中对应的学生各次考试成绩和平均成绩 */
				printf("该生的各次考试成绩分别为：\n");
				for (j = 0; j < N; j++)
				{
					printf("%-7.2f", score[i][j]);
				}
				printf("\n该生的平均成绩为：%.2f\n\n", aver[i]);
				break;
			}

			case 2:
			{
				printf("请输入考试次数:");
				scanf("%d", &j);
				while ((j < 1) || (j > 6))
				{
					printf("您输入的考试次数不在系统范围内，请重新输入：\n");
					scanf("%d", &j);
				}
				j--;
				sum_score = 0;
				/* 输出二维数组score中对应的考试中每个学生的成绩，并计算这次考试的平均成绩 */
				printf("在本次考试中，学号为1到%d的同学的成绩分别为：\n", M);
				for (i = 0; i < M; i++)
				{
					printf("%-7.2f", score[i][j]);
					sum_score += score[i][j];
				}
				aver_score = sum_score / M;
				printf("平均成绩:%.2f\n\n", aver_score);
				break;
			}
		}

		printf("请问您是否要继续查询？（y/n）");
		fflush(stdin);
		ch = getchar();
	}
	while (ch == 'y' || ch == 'Y');

	system("pause");
	return 0;
}
