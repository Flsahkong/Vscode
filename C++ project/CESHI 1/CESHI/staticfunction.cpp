//# include<iostream>
//# include<string>
//using namespace std;
//
//class Student {
//private:
//	char*Name;
//	int No;
//	static int countS;
//public:
//	Student(char* = "", int = 0);
//	Student(Student &);
//	static int count()
//	{
//		return countS;
//	}
//	~Student();
//};
//
//int countS = 0;
//
//Student::Student(char *Name , int No)
//{
//	
//	this->Name = new char[strlen(Name) + 1];
//	strcpy(this->Name, Name);
//	this->No = No;
//	++countS;
//	cout << "constrcting:" << Name << endl;
//}
//Student::Student(Student &S)
//{
//	
//	Name = new char[strlen(S.Name) + 1];
//	strcpy(Name, S.Name);
//	No = S.No;
//	++countS;
//	cout << "copy constrcting:" << Name << endl;
//}
//Student ::~Student()
//{
//	cout << "destructing:"<<Name<< endl;
//	delete[] Name;
//	--countS;
//}


//
//int staticfunction()
//{
//	cout << Student::count() << endl;
//	Student S1("lishuaifeng");
//	cout << S1.count() << endl;
//	Student S2(S1);
//	cout << S1.count() << endl;
//	Student S3[2];
//	cout << Student::count() << endl;
//	Student *p = new Student [3];
//	cout << Student::count() << endl;
//	delete[] p;
//	cout << Student::count() << endl;
//
//	return 0;
//}