/*
�����ܣ��˻������岩��
������Ա������Դ2020300002043
����ʱ�䣺2021.7.9
�޸�ʱ�䣺
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
//�����Ѱ�Ҽ�����������.���ˣ��в�ͨ��QAQ
void computer_favor(void);

//�ж��ò���
int I, J;
char Done;

int main(void) 
{
	char done;

	printf("XXXXXXXXXXXXXXXXXXXX\n");
	printf("��������Ϸ\n");
	printf("�㽫�ͼ�������ġ�\n");
	printf("XXXXXXXXXXXXXXXXXXXX\n\n");

	done = CHESSPIECE_BLANK;
	init_matrix();

	do
	{
		disp_matrix();

		get_player_move();
		Done = check();
		if (Done != CHESSPIECE_BLANK) break;

		/*get_computer_move();
		Done = check();*/
		computer_favor();
		if (Done != CHESSPIECE_BLANK) break;
	} while (Done == CHESSPIECE_BLANK);
	//computer_favor();

	disp_matrix();

	if (Done == CHESSPIECE_PLAYER)
		printf("��ʤ�ˣ�\n");
	else
		printf("�����ʤ�ˣ�\n");

	system("pause");
	return 0;
}

void init_matrix(void)
{
	int i, j;

	for (i=0; i<3; i++)
		for (j=0; j<3; j++)
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

		x--; y--;

		if (g_matrix[x][y] == CHESSPIECE_BLANK)
		{
			g_matrix[x][y] = CHESSPIECE_PLAYER;
			break;
		}

		printf("��Чλ�á�����һ�Ρ�\n");
	}
}

/*
	������������¡���������˳�������հ�λ�ã�
	�ڵ�һ���հ�λ�÷������ӡ�
	���û�пհ�λ���ˣ�����ƽ�֣�����������Ϸ��
*/
void get_computer_move(void)//�����ֻ�Ҳ���
{
	int i, j;

	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
			if (g_matrix[i][j] == CHESSPIECE_BLANK)
				break;

		if (g_matrix[i][j] == CHESSPIECE_BLANK)
			break;
		/*
		�����һ�������ڣ���ô������һ���for�޷�ֱ��������
		�������������for����i=3������Ȼ����������ķ�Χ
		*/
	}
	I = i;
	J = j;

	if (i*j == 9)
	{
		printf("ƽ�֣�\n");
		system("pause");
		exit(0);
		/*
		exist()(����stdlib.h)�ر������ļ�����ֹ����ִ�еĽ��̡�
		exit(0)��ʾ�����˳�
		*/
	}
	//else g_matrix[I][J] = CHESSPIECE_COMPUTER;
}

void computer_favor(void)
{
	do
	{
		get_computer_move();
		g_matrix[I][J] = CHESSPIECE_COMPUTER;
		Done = check();
		if(Done == CHESSPIECE_COMPUTER)
		{
			disp_matrix();
			printf("�����ʤ�ˣ�\n");
			system("pause");
			exit(0);
		}
		else g_matrix[I][J] = CHESSPIECE_BLANK;
		get_computer_move();
	}while(I * J != 9);

	get_computer_move();
	g_matrix[I][J] = CHESSPIECE_COMPUTER;
}

void disp_matrix(void)
{
	int t;

	printf("\n");
	for (t=0; t<3; t++)
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

	for (i=0; i<3; i++)
		if (g_matrix[i][0] == g_matrix[i][1] &&
			g_matrix[i][0] == g_matrix[i][2])
			return g_matrix[i][0];

	for (i=0; i<3; i++)
		if (g_matrix[0][i] == g_matrix[1][i] &&
			g_matrix[0][i] == g_matrix[2][i])
			return g_matrix[0][i];

	if (g_matrix[0][0] == g_matrix[1][1] &&
		g_matrix[1][1] == g_matrix[2][2])
		return g_matrix[0][0];

	if (g_matrix[0][2] == g_matrix[1][1] &&
		g_matrix[1][1] == g_matrix[2][0])
		return g_matrix[0][2];

	return CHESSPIECE_BLANK;
}
