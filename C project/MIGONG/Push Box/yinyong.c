/*

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int x = 0, y = 0;

int map[8][8] = { 0 };
// 定义的游戏界面模型
int map_1[8][8] = {
	{ 0,0,1,1,1,0,0,0 },
	{ 0,0,1,4,1,0,0,0 },
	{ 0,0,1,2,1,1,1,1 },
	{ 1,1,1,0,0,2,4,1 },
	{ 1,4,0,2,3,1,1,1 },
	{ 1,1,1,1,2,1,0,0 },
	{ 0,0,0,1,4,1,0,0 },
	{ 0,0,0,1,1,1,0,0 }
};

int count1();
int count2();

int up();
int down();
int left();
int right();
int shuchu();
int find();
int zhujiemian();

int main()
{
	int n, m;
	system("title 推箱子游戏~");

	memcpy(map, map_1, sizeof(map_1));

	zhujiemian();

	_getch();

	system("cls");

	n = count1();

	while (1)
	{
		system("cls");
		shuchu();
		m = count2();
		find();

		switch (_getch())
		{
		case 'w':up(); break;
		case 's':down(); break;
		case 'a':left(); break;
		case 'd':right(); break;
		case 'r':memcpy(map, map_1, sizeof(map_1)); break;
		}

		if (n == m)
		{
			system("cls");
			printf("游戏胜利~\n");
			_getch();
			return 0;
		}
	}
}
// 按w的时候的输出结果
int up()
{
	if (map[x][y] == 3) //找到自己的位置
	{
		if (map[x - 1][y] == 0) //判断下一格子是不是空
		{
			map[x - 1][y] = 3;
			map[x][y] = 0;
		}
		if (map[x - 1][y] == 2 && map[x - 2][y] == 4) //判断下一格子是不是箱子,下下个格子是不是箱子要到的地方
		{
			map[x][y] = 0;
			map[x - 1][y] = 3;
			map[x - 2][y] = 5;
		}
	}
	return 0;
}
//按d的时候的输出结果
int down()
{
	if (map[x][y] == 3)
	{
		if (map[x + 1][y] == 0)
		{
			map[x + 1][y] = 3;
			map[x][y] = 0;
		}
		if (map[x + 1][y] == 2 && map[x + 2][y] == 4)
		{
			map[x][y] = 0;
			map[x + 1][y] = 3;
			map[x + 2][y] = 5;
		}
	}
	return 0;
}
//按a的时候的输出结果
int left()
{
	if (map[x][y] == 3)
	{
		if (map[x][y - 1] == 0)
		{
			map[x][y - 1] = 3;
			map[x][y] = 0;
		}
		if (map[x][y - 1] == 2 && map[x][y - 2] == 4)
		{
			map[x][y] = 0;
			map[x][y - 1] = 3;
			map[x][y - 2] = 5;
		}
		if (map[x][y - 2] == 0 && map[x][y - 1] == 2)
		{
			map[x][y] = 0;
			map[x][y - 1] = 3;
			map[x][y - 2] = 2;
		}
	}
	return 0;
}
//按d的时候的输出结果
int right()
{
	if (map[x][y] == 3)
	{
		if (map[x][y + 1] == 0)
		{
			map[x][y + 1] = 3;
			map[x][y] = 0;
		}
		if (map[x][y + 1] == 2 && map[x][y + 2] == 4)
		{
			map[x][y] = 0;
			map[x][y + 1] = 3;
			map[x][y + 2] = 5;
		}
	}
	return 0;
}

int shuchu()
{
	for (x = 0; x<8; x++)
	{
		for (y = 0; y<8; y++)
		{
			if (map[x][y] == 1)
				printf("■"); //输出砖块的样子
			if (map[x][y] == 3)
				printf("⊙"); //输出自己的位置
			if (map[x][y] == 2)
				printf("□"); //输出箱子
			if (map[x][y] == 4)
				printf("☆"); //输出箱子要到的位置
			if (map[x][y] == 0)
				printf("  "); //输出空白
			if (map[x][y] == 5)
				printf("★"); //输出箱子到了该到的位置
		}
		printf("\n");
	}
	return 0;
}
//找到自己的位置
int find()
{
	for (x = 0; x<8; x++)
		for (y = 0; y<8; y++)
		{
			if (map[x][y] == 3)
				return 0;
		}
	return 0;
}
//箱子要到的位置的个数
int count1()
{
	int n = 0;
	for (x = 0; x<8; x++)
		for (y = 0; y<8; y++)
		{
			if (map[x][y] == 4)
				n++;
		}
	return n;
}
//箱子到了位置的个数
int count2()
{
	int m = 0;
	for (x = 0; x<8; x++)
		for (y = 0; y<8; y++)
		{
			if (map[x][y] == 5)
				m++;
		}
	return m;
}
//制作主界面
int zhujiemian()
{
	printf("*************************\n"
		"***请按任意键游戏开始~***\n"
		"*********制作:小菜*******\n"
		"**请按wasd 控制上下左右**\n"
		"**请按r重新开始游戏******\n"
		"*************************\n");
}



*/


# include<stdio.h>
# include<stdlib.h>
# include<conio.h>

int main()
{
	int nowx = 0, nowy = 0;
	int  c = _getch();

	switch (c)
	{
	case 72:
		nowy -= 1;		printf("up");//上
		break;
	case 75:				//左
		nowx -= 1;
		break;
	case 80:				//下
		nowy += 1;
		break;
	case 77:				//右
		nowx += 1;
		break;
	}
	printf("%d  %d\n", nowx, nowy);
	system("pause");
	return 0;
}