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
	ch = cin.get();			//从输进去的一串字符当中取第一个，包括空格
	cout << ch << endl;
	cin.get(s, 6);			//从输入流中取5个字符，存入s中，（如果输入流中少于5个，则全部取出）
	cout << s << endl;
	/*char str[5];
	cin.get(str, 8);
	cout << str << endl;*/		//这种情况下则会出错


	char st[23];
	cin.getline(st, 23, 'fa');			//和cin.getline一样，只是遇到fa的话就停止，如果没有，则相当于get。如果这里没有‘fa’，则与get一样
	cout << st << endl;	


	//getchar()		需要加头文件string,其余与c语言中一样

	//gets()			需要加头文件string，其余用法和c语言相同

	/*gets——从标准输入接收一串字符，遇到'\n'时结束，但不接收'\n'，把 '\n'留存输入缓冲区；把接收的一串字符存储在形式参数指针指向的空间，并在最后自动添加  一个'\0'。
	getchar——从标准输入接收一个字符返回，多余的字符全部留在输入缓冲区。
	fgets——从文件或标准输入接收一串字符，遇到'\n'时结束，把'\n'也作为一个字符接收；把接收的一串字符存储在形式参数指针指向的空间，并在'\n'后再自动添加  一个'\0'。*/

	/*char *Name = "nihoa";
	cout << Name << endl;
	不用加*直接就可以输出字符*/
	
	return 0;
}