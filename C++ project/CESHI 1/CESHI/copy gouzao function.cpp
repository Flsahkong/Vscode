# include<iostream>
using namespace std;
class Clock {
private:
	int H, S, M;
public:
	Clock(int h = 0, int s = 0, int m = 0)
	{
		H = h;
		S = s;
		M = m;
	}
	~Clock()
	{
		cout << "deroctor" << H << ":" << M << ":" << S << ":"<<endl;
	}
	Clock(Clock &ph)
	{
		H = ph.H;
		S = ph.S;
		M = ph.M;
		cout << "copy,constructor:" << H << ":" << M << ":" << S << ":"<<endl;
	}


};
Clock function(Clock C)
{
	//�˺����������ο������캯����������������
	return C;
}
int copy()
{
	Clock C1(5, 3, 2);
	Clock myclok(18, 34, 2);
	myclok = C1;
	//Clock C2(6, 4, 3);
	cout << endl;
	//Clock C4  = function(C2);			//��һ�����е��ำֵ������һ�����е����ʱ�򽫲����ÿ������캯��
	//Clock C3(C1);
	return 0;
}