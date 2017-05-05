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
	//此函数调用两次拷贝构造函数，两次析构函数
	return C;
}
int copy()
{
	Clock C1(5, 3, 2);
	Clock myclok(18, 34, 2);
	myclok = C1;
	//Clock C2(6, 4, 3);
	cout << endl;
	//Clock C4  = function(C2);			//将一个已有的类赋值给另外一个已有的类的时候将不调用拷贝构造函数
	//Clock C3(C1);
	return 0;
}