# include<iostream>
# include<iomanip>
# include<string>
using namespace std;

int cincout()
{
	/*double z;
	char intfs[34];
	double a = 1.23456789012345;
	cout << setprecision(4) << a << endl;
	cout << setprecision(7) << a << endl;
	cout << setprecision(9);
	cout << a << endl;
	cin >> a >> z;
	cin >> intfs;
	cout << intfs << endl;*/

	char ch;
	char s[6];
	ch = cin.get();			//�����ȥ��һ���ַ�����ȡ��һ���������ո�
	cout << ch << endl;
	cin.get(s, 6);			//����������ȡ5���ַ�������s�У������������������5������ȫ��ȡ����
	cout << s << endl;
	/*char str[5];
	cin.get(str, 8);
	cout << str << endl;*/		//���������������


	char st[23];
	cin.getline(st, 23, 'fa');			//��cin.getlineһ����ֻ������fa�Ļ���ֹͣ�����û�У����൱��get���������û�С�fa��������getһ��
	cout << st << endl;	


	//getchar()		��Ҫ��ͷ�ļ�string,������c������һ��

	//gets()			��Ҫ��ͷ�ļ�string�������÷���c������ͬ

	/*gets�����ӱ�׼�������һ���ַ�������'\n'ʱ��������������'\n'���� '\n'�������뻺�������ѽ��յ�һ���ַ��洢����ʽ����ָ��ָ��Ŀռ䣬��������Զ����  һ��'\0'��
	getchar�����ӱ�׼�������һ���ַ����أ�������ַ�ȫ���������뻺������
	fgets�������ļ����׼�������һ���ַ�������'\n'ʱ��������'\n'Ҳ��Ϊһ���ַ����գ��ѽ��յ�һ���ַ��洢����ʽ����ָ��ָ��Ŀռ䣬����'\n'�����Զ����  һ��'\0'��*/

	/*char *Name = "nihoa";
	cout << Name << endl;
	���ü�*ֱ�ӾͿ�������ַ�*/
	
	return 0;
}