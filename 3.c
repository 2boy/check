/*
 *显示空棋盘
 用循环描述整个下棋过程
 每次循环获得一个位置但不保证放置棋子
 获得行号（行号有可能无效）
 检查位置是否可用
 放置棋子
 显示棋盘
 判断输赢
 */
#include <stdio.h>

int main()
{
	char map[3][3] = {};
	int i, j;
	int row, col;
	int state, n;
	int menu;

	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			map[i][j] = '.';
		}
	}

	state = 0;
	do {
		for (i=0; i<3; i++)
		{
			for (j=0; j<3; j++)
			{
				printf("%c ", map[i][j]);
			}
			printf("\n");
		}


		n=0;
		for (i=0; i<3; ++i)
		{
			for (j=0; j<3; ++j)
			{
				if (map[i][j] != '.')
				{
					++n;
				}
			}
		}
		if (n == 9)
		{
			printf("平局！\n");
			for (i=0; i<3; i++)
			{
				for (j=0; j<3; j++)
				{
					map[i][j] = '.';
				}
			}
			state = 0;
			printf("输入1继续玩，输入0结束游戏：");
			while (!(scanf("%d", &menu)))
			{
				scanf("%*[^\n]");
				scanf("%*c");
				if (menu == 1 || menu == 0)
				{
					break;
				}
			}
			continue;
		}


		++state;
		printf("请输入行号：");
		scanf("%d", &row);
		if (row<1 || row>3)
		{
			printf("超出范围!\n");
			printf("这步棋不算，重来！\n");
			scanf("%*[^\n]");
			scanf("%*c");
			state -= 1;
			continue;
		}
		printf("请输入列号：");
		scanf("%d", &col);
		if (col<1 || col>3)
		{
			printf("超出范围!\n");
			printf("这步棋不算，重来！\n");
			scanf("%*[^\n]");
			scanf("%*c");
			state -= 1;
			continue;
		}
		if (map[row-1][col-1] == '0' || map[row-1][col-1] == '*')
		{
			printf("位置已经有棋子了！\n");
			printf("这步棋不算，重来！\n");
			state -= 1;
			continue;
		}
		if (state % 2)
		{
			map[row-1][col-1] = '0';
			if ((map[0][2] == map[1][1] && map[0][2] == map[2][0] == '0') ||
					(map[0][0] == map[1][1] && map[0][0] == map[2][2] && map[0][0] == '0') ||
					(map[0][2] == map[1][2] && map[0][2] == map[2][2] && map[0][2] == '0') ||
					(map[0][1] == map[1][1] && map[0][1] == map[2][1] && map[0][1] == '0') ||
					(map[0][0] == map[1][0] && map[0][0] == map[2][0] && map[0][0] == '0') ||
					(map[2][0] == map[2][1] && map[2][0] == map[2][2] && map[2][0] == '0') ||
					(map[1][0] == map[1][1] && map[1][0] == map[1][2] && map[1][0] == '0') ||
					(map[0][0] == map[0][1] && map[0][0] == map[0][2] && map[0][0] == '0'))
			{
				//state = -1;
				for (i=0; i<3; i++)
				{
					for (j=0; j<3; j++)
					{
						printf("%c ", map[i][j]);
					}
					printf("\n");
				}
				printf("0 WIN!\n");
				for (i=0; i<3; i++)
				{
					for (j=0; j<3; j++)
					{
						map[i][j] = '.';
					}
				}
				state = 0;
				printf("输入1继续玩，输入0结束游戏：");
				while (!(scanf("%d", &menu)))
				{
					scanf("%*[^\n]");
					scanf("%*c");
					if (menu == 1 || menu == 0)
					{
						break;
					}
				}
			}
		}
		else {
			map[row-1][col-1] = '*';
			if ((map[0][2] == map[1][1] && map[0][2] == map[2][0] == '*') ||
					(map[0][0] == map[1][1] && map[0][0] == map[2][2] && map[0][2] == '*') ||
					(map[0][2] == map[1][2] && map[0][2] == map[2][2] && map[0][2] == '*') ||
					(map[0][1] == map[1][1] && map[0][1] == map[2][1] && map[0][1] == '*') ||
					(map[0][0] == map[1][0] && map[0][0] == map[2][0] && map[0][0] == '*') ||
					(map[2][0] == map[2][1] && map[2][0] == map[2][2] && map[2][0] == '*') ||
					(map[1][0] == map[1][1] && map[1][0] == map[1][2] && map[1][0] == '*') ||
					(map[0][0] == map[0][1] && map[0][0] == map[0][2] && map[0][0] == '*'))
			{
				//state = -1;
				for (i=0; i<3; i++)
				{
					for (j=0; j<3; j++)
					{
						printf("%c ", map[i][j]);
					}
					printf("\n");
				}
				printf("* WIN!\n");
				for (i=0; i<3; i++)
				{
					for (j=0; j<3; j++)
					{
						map[i][j] = '.';
					}
				}
				state = 0;
				printf("输入1继续玩，输入0结束游戏：");
				while (!(scanf("%d", &menu)))
				{
					scanf("%*[^\n]");
					scanf("%*c");
					if (menu == 1 || menu == 0)
					{
						break;
					}
				}
			}
		}
	} while (menu);

	return 0;
}
