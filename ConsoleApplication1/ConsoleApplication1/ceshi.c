# include<stdio.h>							//std c���Ա�׼�����Կ�ƽ̨
# include<stdlib.h>
# include<windows.h>					//�������⺯��


//int num = 123;							//ȫ�ֱ���

int ceshi()								//main��������int��ʱ�����û�з���ֵ����������ĺ��������з���ֵ
{												//���������������ж��
												//�����������˺���������������ĵ�ַ
	char str[100];

	sprintf(str,"calc");				//sprintf��������ַ��������notepad��str  ��printf������ַ�������Ļ��

	system(str);											//system����ִ���ַ���ָ�ִ�е���һ������

	//printf("%i\n", 2434);							//%i���ʮ��������
	printf("for /l %%i in (1,1,5) do start notepad");		//%i����һ����������1��ʼ���μ�1��һֱ�ӵ�5

	//system("mspaint");									//���Դ򿪻��壬����ִ�е��ǳ���

	//Sleep(2000);							//�ȴ�2��֮���˳�

	MessageBoxA(0, "�����յ���", "���κ�����", 0);					//�����Ի�������ǰһ���������������ݣ���һ��������������Ŀ

	getchar();

	return 0;
}