//先找出名词，名词代表类		名词也可能是属性
//动词代表行为，即为函数
//看类之间的关系，画出关系图
//斜体表示抽象的类
#include<iostream>
using namespace std;

//Circuit类中包含添加，控制开关on off
class Circuit {
private:
	int fans[10];
	int lams[10];
public:
	void add(Circuit &fans)
	{
		
	}
	Circuit()
	{
		for (int i = 0; i < 10; i++) {
			fans[i] = 0;
			lams[i] = 0;
		}
	}
	void  show()
	{
		cout << fans[3] << fans[4] << fans[5] << endl;
		cout << lams[1] << lams[4] << lams[7] << endl;
	}
};
int main()
{
	Circuit cirs;
	
	cirs.show();
	/*Fan fans;
	Lamp lams;
	cirs.add(fans);
	cirs.add(lams);

	cirs.on(fans);
	cirs.on(lams);
	
	cirs.off(L);
	cirs.off(F);*/
	system("pause");
	return 0;
}