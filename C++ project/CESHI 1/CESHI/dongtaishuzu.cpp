# include<iostream>
using namespace std;

int dongtaishuzu()
{
	int i, j, k;
	float(*p)[3][4];
	p = new float[2][3][4];

	for (i = 0; i < 2; i++) 
		for (j = 0; j < 3; j++) 
			for (k = 0; k< 4; k++) 
				*(*(*(p + i) + j) + k) = i * 100 + j * 10 + k * 1;
	
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 4; k++) {
				cout << p[i ] [j][k]<<"    ";
			}
			cout << endl;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}