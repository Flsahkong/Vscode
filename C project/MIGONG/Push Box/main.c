# include<stdio.h>
# include<stdlib.h>
#include <conio.h>
# define SIZE 8

int cnt;
int MAP[SIZE][SIZE] = {
	{ 0,0,1,1,1,0,0,0 },
	{ 0,0,1,4,1,0,0,0 },
	{ 0,0,1,2,1,1,1,1 },
	{ 1,1,1,0,0,2,4,1 },
	{ 1,4,0,2,3,1,1,1 },
	{ 1,1,1,1,2,1,0,0 },
	{ 0,0,0,1,4,1,0,0 },
	{ 0,0,0,1,1,1,0,0 }
};

int init()
{
	printf("This is a small push boxes game,\nPlease enter any key to continue...\n");
	for (int i = 0; i < 30; i++) {
		printf("please waiting for a second...\n");
		system("cls");
	}
}
int show_map()
{
	system("cls");
	int  i, j;
	for ( i = 0; i < SIZE ; i++) {
		for (j = 0; j < SIZE ; j++) {
			switch (MAP[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("%c%c", 0xa8, 0x80);			//����ǽ��
				break;
			case 2:
				printf("��");											//��������
				break;
			case 3:
				printf("��");										//�����Լ�
				break;
			case 4:
				printf("��");											//����Ҫ�����ĵص�
				break;
			case 5:
				printf("��");											//�����Ѿ��Ƶ�������
				break;
			case 6:
				printf("��");											//��ʾ�˺͵ص�����һ���ط�
				break;
			}
			if (j == SIZE - 1)	printf("\n");
		}
	}
}

int mod_map(int *nowx,int *nowy,int *lastx,int *lasty)
{
	if (MAP[*nowy][*nowx] == 2) {
		//�������һλ�ǿյ�
		if (MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] == 0) {
			MAP[*nowy][*nowx] = 3;
			MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] = 2;
			MAP[*lasty][*lastx] = 0;
		}
		//�������һ����Ŀ�ĵ�
		else if (MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] == 4) {
			MAP[*nowy][*nowx] = 3; 
			MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] = 5;
			MAP[*lasty][*lastx] = 0; cnt++;
		}
		//�������һ����ǽ
		else if (MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] == 1) {
			*nowx = *lastx;  *nowy = *lasty;
		}
	}
	else if(MAP[*nowy][*nowx] == 0){					//���ʲô��û�У��ͻ�λ
		MAP[*nowy][*nowx] = 3; 
		MAP[*lasty][*lastx] = 0;
	}
	//�����ײ��ǽ�ˣ��޸�nowx��nowy��ֵ
	else if (MAP[*nowy][*nowx] == 1) {
		*nowx = *lastx;  
		*nowy = *lasty;
	}				
	//�����һ��λ����Ŀ�ĵ�
	else if (MAP[*nowy][*nowx] == 4) {
		MAP[*nowy][*nowx] = 6; 
		MAP[*lasty][*lastx] = 0;
	}
	//�����һ���ط����Ѿ�����Ŀ�ĵص�����
	else if (MAP[*nowy][*nowx] == 5) {
			//������ӵ���һ��λ���ǿյ�
			if (MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] == 0) {
				MAP[*nowy][*nowx] = 6;
				MAP[*lasty][*lastx] = 0; 
				MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] = 2;
				cnt--;
			}
			//�������һ����Ŀ�ĵ�
			else if (MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] == 4) {
				MAP[*nowy][*nowx] = 6; 
				MAP[*lasty][*lastx] = 0;
				MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] = 5;
			}
			//�������һ����ǽ
			else if (MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] == 1) {
				*nowx = *lastx;  
				*nowy = *lasty;
			}
	}
	
	show_map();
	return;
}

int main()
{
	init();
	show_map();

	int nowx=4, nowy=4;
	int lastx, lasty;
	while (1) {
		lastx = nowx, lasty = nowy;
		char c = _getch();

		switch (c)
		{
		case 72:
			nowy -= 1;
			break;
		case 75:
			nowx -= 1;
			break;
		case 80:
			nowy += 1;
			break;
		case 77:
			nowx += 1;
			break;
		}
		mod_map(&nowx, &nowy, &lastx, &lasty);
		if (cnt == 4)	break;
	}
	printf("Congratulations!You win!");
	
	system("pause");

	return 0;
}