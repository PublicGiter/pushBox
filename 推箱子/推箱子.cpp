#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>//getch();可以屏蔽回文

int map[7][8] =
{
	{ 1,1,1,1,1,1,1,1 },	//0-空地
	{ 1,0,0,1,0,0,0,1 },	//1-墙
	{ 1,5,4,7,7,0,0,1 },	//3-目的地
	{ 1,0,0,3,3,0,1,1 },	//4-箱子
	{ 1,0,4,7,7,0,0,1 },	//5-人物
	{ 1,0,0,1,0,0,0,1 },	//7-（3 + 4）箱子到达目的地
	{ 1,1,1,1,1,1,1,1 },	//8-（3 + 5）人物到达目的地
};

void DrawMap()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			switch (map[i][j])
			{
			case 0:printf("  "); break;
			case 1:printf("■"); break;
			case 3:printf("☆"); break;
			case 4:printf("□"); break;
			case 5:printf("♀"); break;
			case 7:printf("★"); break;
			case 8:printf("♀"); break;
			default:
				break;
			}
		}
		printf("\n");
	}
}

void PlayGame()
{
	char ch;

	int r, c;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[i][j] == 5 || map[i][j] == 8)
			{
				r = i;
				c = j;
			}
		}
	}


	ch = _getch();
	switch (ch)
	{
	case 'w': case 72:
		//1、人的前面是空地或者目的地
		if (map[r-1][c] == 0 || map[r - 1][c] == 3)
		{
			map[r - 1][c] += 5;
			map[r][c] -= 5;
		}
		//2、人前面是箱子
		else if (map[r - 1][c] == 4 || map[r - 1][c] == 7)
		{
			if (map[r - 2][c] == 0 || map[r - 2][c] == 3)
			{
				map[r - 2][c] += 4;
				map[r - 1][c] += 1;
				map[r][c] -= 5;
			}
		}
		break;
	case 's': case 80: 
		//1、人的前面是空地或者目的地
		if (map[r + 1][c] == 0 || map[r + 1][c] == 3)
		{
			map[r + 1][c] += 5;
			map[r][c] -= 5;
		}
		//2、人前面是箱子
		else if (map[r + 1][c] == 4 || map[r + 1][c] == 7)
		{
			if (map[r + 2][c] == 0 || map[r + 2][c] == 3)
			{
				map[r + 2][c] += 4;
				map[r + 1][c] += 1;
				map[r][c] -= 5;
			}
		}
		break;
	case 'a': case 75:
		//1、人的前面是空地或者目的地
		if (map[r][c - 1] == 0 || map[r][c - 1] == 3)
		{
			map[r][c - 1] += 5;
			map[r][c] -= 5;
		}
		//2、人前面是箱子
		else if (map[r][c - 1] == 4 || map[r][c - 1] == 7)
		{
			if (map[r][c - 2] == 0 || map[r][c - 2] == 3)
			{
				map[r][c - 2] += 4;
				map[r][c - 1] += 1;
				map[r][c] -= 5;
			}
		}
		break;
	case 'd': case 77: 
		//1、人的前面是空地或者目的地
		if (map[r][c + 1] == 0 || map[r][c + 1] == 3)
		{
			map[r][c + 1] += 5;
			map[r][c] -= 5;
		}
		//2、人前面是箱子
		else if (map[r][c + 1] == 4 || map[r][c + 1] == 7)
		{
			if (map[r][c + 2] == 0 || map[r][c + 2] == 3)
			{
				map[r][c + 2] += 4;
				map[r][c + 1] += 1;
				map[r][c] -= 5;
			}
		}
		break;
	default:
		break;
	}

}



int main()
{
	while (1)
	{
		system("cls");
		DrawMap();
		PlayGame();
	}

	printf("hello world\n");
	system("pause");
	return 0;
}