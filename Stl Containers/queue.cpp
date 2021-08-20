#include <iostream>
#include <list>
#include <deque>
#include <queue>
#include <string>
using namespace std;

// report queue
template <typename T>
void report_queue(T& q) {
	size_t sz = q.size();
	cout << "size: " << sz;
	if (sz) cout << " front: " << q.front() << " back: " << q.back();
	cout << endl;
}

// print simple message
void message(const char* s) { cout << s << endl; }

int main() {
	// queue from list
	message("initialize queue from list");
	list<int> l1 = { 1, 2, 3, 4, 5 };
	queue<int, list<int>> q1(l1); // constructer copies to new list
	report_queue(q1);

	message("pop all from q1");
	while (!q1.empty())
	{
		cout << q1.front() << " ";
		q1.pop();
	}
	cout << endl;
	report_queue(q1);

	return 0;
}