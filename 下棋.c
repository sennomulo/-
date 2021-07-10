/*
�����ܣ��˻������岩��
������Ա������Դ2020300002043
����ʱ�䣺2021.7.9
�޸�ʱ�䣺2021.7.9
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* ��������״̬ */
char g_matrix[3][3];

/* ������ʽ */
#define CHESSPIECE_BLANK  ' '
#define CHESSPIECE_PLAYER 'X'
#define CHESSPIECE_COMPUTER 'O'

/* ��ʼ������ */
void init_matrix(void);
/* �����һ�� */
void get_player_move(void);
/* �������һ�� */
void get_computer_move(void);
/* ��ʾ���� */
void disp_matrix(void);
/* �ж���Ϸ�Ƿ���� */
char check(void);

//�Ʒ�
int Human = 0, Computer = 0;
//��¼����
char Done;

int main(void)
{
	char done, ch; //done�����ж���Ϸ����

	printf("XXXXXXXXXXXXXXXXXXXX\n");
	printf("��������Ϸ\n");
	printf("����X�����ͼ������O�����ġ�\n");
	printf("XXXXXXXXXXXXXXXXXXXX\n\n");

	do
	{
		Done = '0';
		printf("��ǰ�˻��ȷ�\t%d:%d\n", Human, Computer);

		done = CHESSPIECE_BLANK;
		init_matrix();

		do
		{
			disp_matrix();

			get_player_move();
			done = check();
			if (done != CHESSPIECE_BLANK) break;

			get_computer_move();
			done = check();
			if (done != CHESSPIECE_BLANK || Done == '!') break;
		}
		while (done == CHESSPIECE_BLANK);

		disp_matrix();

		if (done == CHESSPIECE_PLAYER)
		{
			printf("��ʤ�ˣ�\n");
			Human++;
		}
		else if (done == CHESSPIECE_COMPUTER)
		{
			printf("�����ʤ�ˣ�\n");
			Computer++;
		}
		else if (Done == '!') printf("ƽ�֣�\n");

		printf("��������Ҫ����һ����(y/n)\n");
		fflush(stdin);
		ch = getchar();
	}
	while (ch == 'y' || ch == 'Y');

	system("pause");
	return 0;
}

void init_matrix(void)
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			g_matrix[i][j] = CHESSPIECE_BLANK;
}

/*
	��ȡ�û�����������ӵ�λ�ã��������Ч�ԣ�
	���������Ч���������������롣
*/
void get_player_move(void)
{
	int x, y;

	while (1)
	{
		printf("������Ҫ�������ӵ�λ�õ��кź��кţ�");
		scanf("%d%*c%d", &x, &y);

		x--;
		y--;

		if (g_matrix[x][y] == CHESSPIECE_BLANK)
		{
			g_matrix[x][y] = CHESSPIECE_PLAYER;
			break;
		}

		printf("��Чλ�á�����һ�Ρ�\n");
	}
}

/*
	���������������������������ӣ�
	����1���ж����ĳλ�����ӿɻ�ʤ����ѡ���λ�á�
	����2��ĳ��λ�������һ�����ӿɻ�ʤ����ѡ���λ�á�
	����3�������ġ��ǡ���˳��ѡ��յ�λ�á�
*/
void get_computer_move(void)
{
	int i = 1, j = 1, signal = 0;//signal����ά�����ġ��ǡ�������˳��
	char done;

	//�����Ѱ�Ҽ���ʤ������
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			if (g_matrix[i][j] == CHESSPIECE_BLANK)
			{
				g_matrix[i][j] = CHESSPIECE_COMPUTER;
				done = check();
				if (done == CHESSPIECE_COMPUTER)
				{
					return;
				}
				g_matrix[i][j] = CHESSPIECE_BLANK;
			}
	}

	//������ض¶Է���ʤ������
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			if (g_matrix[i][j] == CHESSPIECE_BLANK)
			{
				g_matrix[i][j] = CHESSPIECE_PLAYER;
				done = check();
				if (done == CHESSPIECE_PLAYER)
				{
					g_matrix[i][j] = CHESSPIECE_COMPUTER;
					return;
				}
				else g_matrix[i][j] = CHESSPIECE_BLANK;
			}
	}

	//�����ģ����Ľǣ����ı�
	if (g_matrix[1][1] == CHESSPIECE_BLANK)
	{
		g_matrix[1][1] = CHESSPIECE_COMPUTER;
		signal = 1;
	}
	else
	{
		for (i = 0; i < 4; i += 2)
		{
			for (j = 0; j < 3; j += 2)
			{
				if (g_matrix[i][j] == CHESSPIECE_BLANK)
				{
					g_matrix[i][j] = CHESSPIECE_COMPUTER;
					return;
				}
			}
		}
	}

	if (signal == 0)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
				if (g_matrix[i][j] == CHESSPIECE_BLANK)
					break;

			if (g_matrix[i][j] == CHESSPIECE_BLANK)
				break;
			/*
			�����һ�������ڣ���ô������һ���for�޷�ֱ��������
			�������������for����i=3������Ȼ����������ķ�Χ
			*/
		}

		if (i * j >= 9)
		{
			Done = '!';
			return;
			/*
			exit()(����stdlib.h)�ر������ļ�����ֹ����ִ�еĽ��̡�
			exit(0)��ʾ�����˳�
			*/
		}
		else g_matrix[i][j] = CHESSPIECE_COMPUTER;
	}

}

void disp_matrix(void)
{
	int t;

	printf("\n");
	for (t = 0; t < 3; t++)
	{
		printf(" %c | %c | %c", g_matrix[t][0], g_matrix[t][1], g_matrix[t][2]);
		if (t != 2) printf("\n---|---|---\n");
	}
	printf("\n\n");
}

/*
	�ֱ������е��С��кͶԽ��ߣ�
	�����ͬһ������ռ�ݣ��򷵻ظ������ӵ���ʽ����ʾʤ���ѷ֣�
	���򷵻ؿհף���ʾδ��ʤ������Ϸû������
*/
char check(void)
{
	int i;

	for (i = 0; i < 3; i++)
		if (g_matrix[i][0] == g_matrix[i][1] &&
		        g_matrix[i][0] == g_matrix[i][2] && g_matrix[i][0] != CHESSPIECE_BLANK)
			return g_matrix[i][0];

	for (i = 0; i < 3; i++)
		if (g_matrix[0][i] == g_matrix[1][i] &&
		        g_matrix[0][i] == g_matrix[2][i] && g_matrix[0][i] != CHESSPIECE_BLANK)
			return g_matrix[0][i];

	if (g_matrix[0][0] == g_matrix[1][1] &&
	        g_matrix[1][1] == g_matrix[2][2] && g_matrix[0][0] != CHESSPIECE_BLANK)
		return g_matrix[0][0];

	if (g_matrix[0][2] == g_matrix[1][1] &&
	        g_matrix[1][1] == g_matrix[2][0] && g_matrix[2][0] != CHESSPIECE_BLANK)
		return g_matrix[0][2];

	return CHESSPIECE_BLANK;
}
