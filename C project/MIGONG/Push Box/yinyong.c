/*

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int x = 0, y = 0;

int map[8][8] = { 0 };
// �������Ϸ����ģ��
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
	system("title ��������Ϸ~");

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
			printf("��Ϸʤ��~\n");
			_getch();
			return 0;
		}
	}
}
// ��w��ʱ���������
int up()
{
	if (map[x][y] == 3) //�ҵ��Լ���λ��
	{
		if (map[x - 1][y] == 0) //�ж���һ�����ǲ��ǿ�
		{
			map[x - 1][y] = 3;
			map[x][y] = 0;
		}
		if (map[x - 1][y] == 2 && map[x - 2][y] == 4) //�ж���һ�����ǲ�������,���¸������ǲ�������Ҫ���ĵط�
		{
			map[x][y] = 0;
			map[x - 1][y] = 3;
			map[x - 2][y] = 5;
		}
	}
	return 0;
}
//��d��ʱ���������
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
//��a��ʱ���������
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
//��d��ʱ���������
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
				printf("��"); //���ש�������
			if (map[x][y] == 3)
				printf("��"); //����Լ���λ��
			if (map[x][y] == 2)
				printf("��"); //�������
			if (map[x][y] == 4)
				printf("��"); //�������Ҫ����λ��
			if (map[x][y] == 0)
				printf("  "); //����հ�
			if (map[x][y] == 5)
				printf("��"); //������ӵ��˸õ���λ��
		}
		printf("\n");
	}
	return 0;
}
//�ҵ��Լ���λ��
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
//����Ҫ����λ�õĸ���
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
//���ӵ���λ�õĸ���
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
//����������
int zhujiemian()
{
	printf("*************************\n"
		"***�밴�������Ϸ��ʼ~***\n"
		"*********����:С��*******\n"
		"**�밴wasd ������������**\n"
		"**�밴r���¿�ʼ��Ϸ******\n"
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
		nowy -= 1;		printf("up");//��
		break;
	case 75:				//��
		nowx -= 1;
		break;
	case 80:				//��
		nowy += 1;
		break;
	case 77:				//��
		nowx += 1;
		break;
	}
	printf("%d  %d\n", nowx, nowy);
	system("pause");
	return 0;
}