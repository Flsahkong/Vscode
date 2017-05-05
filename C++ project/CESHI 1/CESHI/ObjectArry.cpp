# include<iostream>
using namespace std;

int rate = 0.6;

class Score {
private :
	long long  Number;
	char* Name;
	int Usual;
	int Final;
	int Total;
public:
	void count();
	void showscore();
	Score(long long = 0, char * = NULL, int = 0, int = 0 , int =0);
};

Score::Score(long long number, char *name, int usual, int final, int total)
{
	Number = number;
	Name = name;
	Usual = usual;
	Final = final;
	Total = total;
}
void Score::count()
{
	Total = Usual*rate + Final*(1 - rate);
}
void Score::showscore()
{
	cout << Number << "\t" << Name << "\t" << Usual << "\t" << Final << "\t" << Total << endl;
}

int ObjectArry()
{
	int n;
	cin >> n;
	Score *p;
	p = new Score[n];
	delete[] p;
	Score ClassScore[2]{
		Score (2016060102008,"lishuaifeng",88,79),
		Score (2016060102020,"fankehu",98,75)
	};
	for (int i = 0; i < 2; i++) {
		ClassScore[i].count();
	}
	for (int j = 0; j < 2; j++) {
		ClassScore[j].showscore();
	}
	return 0;
}