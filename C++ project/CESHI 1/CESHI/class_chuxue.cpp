# include<iostream>
using namespace std;

class Clock {
private:
	int H, M, S;
public:
	Clock (int h ,int m ,int s)
	{
		H = (h >= 0 && h < 24) ? h : 0;
		M = (m >= 0 && m < 60) ? m : 0;
		S = (s >= 0 && s < 60) ? s : 0;
	}
		void settime(int h, int m, int s)
	{
		H = (h >= 0 && h < 24) ? h : 0;
		M = (m >= 0 && m < 60) ? m : 0;
		S = (s >= 0 && s < 60) ? s : 0;
	}
	void show()
	{
		cout << H << ":" << M << ":" << S <<  endl;
	}

};

int classChuxue()
{
	Clock myclock(0,0,0);
	myclock.settime(10, 25, 46);
	myclock.show();
	return 0;
}