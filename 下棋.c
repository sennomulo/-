/*
程序功能：人机井字棋博弈
开发人员：杨赖源2020300002043
开发时间：2021.7.9
修改时间：2021.7.9
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

//计分
int Human = 0, Computer = 0;
//记录局面
char Done;

int main(void)
{
	char done, ch; //done用于判断游戏局面

	printf("XXXXXXXXXXXXXXXXXXXX\n");
	printf("井字棋游戏\n");
	printf("您（X）将和计算机（O）对弈。\n");
	printf("XXXXXXXXXXXXXXXXXXXX\n\n");

	do
	{
		Done = '0';
		printf("当前人机比分\t%d:%d\n", Human, Computer);

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
			printf("你胜了！\n");
			Human++;
		}
		else if (done == CHESSPIECE_COMPUTER)
		{
			printf("计算机胜了！\n");
			Computer++;
		}
		else if (Done == '!') printf("平局！\n");

		printf("请问您还要再来一局吗？(y/n)\n");
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

		x--;
		y--;

		if (g_matrix[x][y] == CHESSPIECE_BLANK)
		{
			g_matrix[x][y] = CHESSPIECE_PLAYER;
			break;
		}

		printf("无效位置。再试一次。\n");
	}
}

/*
	计算机按照以下三个规则进行落子：
	规则1：判断如果某位置落子可获胜，则选择该位置。
	规则2：某个位置玩家下一步落子可获胜，则选择该位置。
	规则3：按中心、角、边顺序选择空的位置。
*/
void get_computer_move(void)
{
	int i = 1, j = 1, signal = 0;//signal用于维护中心·角·边落子顺序
	char done;

	//计算机寻找己方胜利机会
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

	//计算机截堵对方获胜可能性
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

	//先中心，再四角，再四边
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
			如果这一步不存在，那么外面那一层的for无法直接跳出，
			导致最后结束外层for语句后i=3，这显然超出了数组的范围
			*/
		}

		if (i * j >= 9)
		{
			Done = '!';
			return;
			/*
			exit()(来自stdlib.h)关闭所有文件，终止正在执行的进程。
			exit(0)表示正常退出
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
	分别检查所有的行、列和对角线，
	如果被同一种棋子占据，则返回该类棋子的样式，表示胜负已分；
	否则返回空白，表示未分胜负，游戏没结束。
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
