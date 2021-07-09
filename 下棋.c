/*
程序功能：人机井字棋博弈
开发人员：杨赖源2020300002043
开发时间：2021.7.9
修改时间：
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* 保存棋盘状态 */
char g_matrix[3][3];

/* 棋子样式 */
#define CHESSPIECE_BLANK  ' '
#define CHESSPIECE_PLAYER 'X'
#define CHESSPIECE_COMPUTER 'O'

/* 初始化棋盘 */
void init_matrix(void);
/* 玩家走一步 */
void get_player_move(void);
/* 计算机走一步 */
void get_computer_move(void);
/* 显示棋盘 */
void disp_matrix(void);
/* 判断游戏是否结束 */
char check(void);
//计算机寻找己方升级机会.别看了，行不通。QAQ
void computer_favor(void);

//判断用参数
int I, J;
char Done;

int main(void) 
{
	char done;

	printf("XXXXXXXXXXXXXXXXXXXX\n");
	printf("井字棋游戏\n");
	printf("你将和计算机对弈。\n");
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
		printf("你胜了！\n");
	else
		printf("计算机胜了！\n");

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
	读取用户输入放置棋子的位置，检查其有效性，
	如果输入无效，则让其重新输入。
*/
void get_player_move(void)
{
	int x, y;

	while (1)
	{
		printf("输入你要放置棋子的位置的行号和列号：");
		scanf("%d%*c%d", &x, &y);

		x--; y--;

		if (g_matrix[x][y] == CHESSPIECE_BLANK)
		{
			g_matrix[x][y] = CHESSPIECE_PLAYER;
			break;
		}

		printf("无效位置。再试一次。\n");
	}
}

/*
	计算机从上往下、从左往右顺序搜索空白位置，
	在第一个空白位置放置棋子。
	如果没有空白位置了，则是平局，立即结束游戏。
*/
void get_computer_move(void)//计算机只找不下
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
		如果这一步不存在，那么外面那一层的for无法直接跳出，
		导致最后结束外层for语句后i=3，这显然超出了数组的范围
		*/
	}
	I = i;
	J = j;

	if (i*j == 9)
	{
		printf("平局！\n");
		system("pause");
		exit(0);
		/*
		exist()(来自stdlib.h)关闭所有文件，终止正在执行的进程。
		exit(0)表示正常退出
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
			printf("计算机胜了！\n");
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
	分别检查所有的行、列和对角线，
	如果被同一种棋子占据，则返回该类棋子的样式，表示胜负已分；
	否则返回空白，表示未分胜负，游戏没结束。
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
