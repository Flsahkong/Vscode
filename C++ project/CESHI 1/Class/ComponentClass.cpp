# include<iostream>
using namespace std;

class Clock {
private:
	int H, M, S;
public:
	void show()
	{
		cout << H<<":" << M << ":" << S << endl;
	}
	Clock(int h=0, int m=0, int s=0)
	{
		H = h;
		S = s;
		M = m;
	}
	void SetTime(int h = 0,int m=0,int s=0)
	{
		H = h;
		S = s;
		M = m;
	}
	int  GetH()
	{
		return H;
	}
	int GetM()
	{
		return M;
	}
	int GetS()
	{
		return S;
	}
};

class TrainTrip {
private:
	char* name;
	Clock StartTime;
	Clock EndTime;
public :
	TrainTrip(char*name, Clock S, Clock E)
	{
		this->name = name;
		StartTime = S;
		EndTime = E;
	}
	//此时是添加了一个函数，次函数的返回值类型是Clock，函数名字叫TripTime
	Clock TripTime(){
		int Th, Tm, Ts;
		int carry = 0;
		Clock temp;
		(Ts = EndTime.GetS() - StartTime.GetS()) > 0 ? carry = 0 : Ts += 60, carry = 1;
		(Tm = EndTime.GetM() - StartTime.GetM()-carry) > 0 ? carry = 0 : Tm += 60, carry = 1;
		(Th = EndTime.GetH() - StartTime.GetH()-carry) > 0 ? carry = 0 : Th += 24;
		temp.SetTime(Th, Tm, Ts);
		return temp;
	}
};

int ComponentClass()
{
	Clock C1(8, 10, 10), C2(6, 1, 2);
	Clock C3;
	TrainTrip T1("K112", C1, C2);
	C3 = T1.TripTime();
	C3.show();
	return 0;
}