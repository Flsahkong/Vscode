# include<stdio.h>
# include<stdlib.h>

int union1()
{
	struct byte {
		unsigned char low, high;
	};

	union body
	{
		struct byte bytee;
		unsigned int word;
	}a;

	scanf("%x", &a.word);

	printf("%c  %c", a.bytee.high,a.bytee.low);

	return 0;
}