# include<iostream>
using namespace std;

class Clock {
private:
	int H, M;
public:
	void setTime(int h, int m)
	{
		H = (h >= 0 && h < 24) ? h : 0;
		M = (m >= 0 && m < 60) ? m : 0;
	}
	void disTime()
	{
		H = 0;
		M = 0;
	}
};
class AlarmClock :public Clock {
public:
	void setAlarm(int h, int m)
	{

	}
	void checkAlarm()
	{

	}
	void stopAlarm()
	{

	}
	void disAlarm()
	{

	}
};

int main()
{
	//AlarmClock.setAlarm(10, 25);
	
	return 0;
}