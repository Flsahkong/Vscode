# include<iostream>
using namespace std;
class Student {
private:
	char * Name;
	char * Number;
	int Score;
public:
	Student(char *name = NULL, char *number = NULL, int score = 0)
	{
		Name = name;
		Number = number;
		Score = score;
	}
	void show()
	{
		
	}
};

Student * addmessage()
{
	char *na = NULL;
	char * num = NULL;
	int score = 0;
	cout << "Please input the student's name :";
	cin >> na;
	cout << "Please input the student's number :";
	cin >> num;
	cout << "Please input the student's score :";
	cin >> score;
	Student* pst = new Student(na,num,score);
	
}
int main()
{
	while (1) {
		cout << "Do you want to add students' message?" << endl;
		cout << "Plesase input 'y' to add,'n' to exit " << endl;
		char input;
		cin >> input;
		if (input == 'y') {

		}
		else if(input == 'n'){
			break;
		}
		else {
			cout << "wrong input! Please input again!"<<endl;
		}
		system("cls");
	}
	system("pause");
	return 0;
}