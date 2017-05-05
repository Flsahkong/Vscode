# include<iostream>
# include<queue>
using namespace std;

int queueue()
{
	queue<int> que;
	
	for (int i = 0; i < 100; i++) {
		que.push(i);
	}
	for (int j = 0; j < 100; j++) {
		if (!que.empty()) {
			cout << "the queue is not empty!" << endl;
			cout << "the size of queue is :" << que.size() << endl;
			cout << "the first num is :" << que.front() << endl;
		}
		que.pop();
	}

	return 0;
}