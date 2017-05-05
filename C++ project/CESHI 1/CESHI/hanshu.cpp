# include<iostream>
using namespace std;
int add(int x = 13, int y = 46);

int hanshu()
{
	int i(2);
	cout << i << endl;
	cout << add() << endl;
	getchar();
	return 0;
}
int add(int x, int y)
{
	return x + y;
}