#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
void printv(const vector<T>& v) {
	if (v.empty()) return;
	for (const T& i : v) cout << i << " ";
	cout << endl;
}

void message(const char* s) { cout << s << endl; }
void message(const char* s, const int n) { cout << s << ": " << n << endl; }

int main() 
{
	cout << "vector from initializer list: " << endl;
	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printv(v1);

	message("size", v1.size());
	message("front", v1.front());
	message("back", v1.back());

	message("element at 5: ", v1[5]);
	message("element at 5: ", v1.at(5));

	message("insert 42 at begin + 5:");
	v1.insert(v1.begin() + 5, 42);
	printv(v1);

	message("erase at begin + 5: ");
	v1.erase(v1.begin() + 5);
	printv(v1);

	message("push back 47: ");
	v1.push_back(47);
	printv(v1);

	message("pop_back");
	v1.pop_back();
	printv(v1);

	message("empty: ");
	vector<int> vx = { 1, 2, 3 };
	while (!vx.empty()) {
		printv(vx);
		vx.pop_back();
	}

	message("clear:");
	vx.insert(vx.begin(), { 1, 2, 3, 4, 5 });
	printv(vx);
	message("vx size: ", vx.size());
	message("vx.clear()");
	vx.clear();
	message("vx size: ", vx.size());
	printv(vx);

	constexpr size_t size = 10;
	int ia[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	message("vector from C-array: ");
	vector<int> v2(ia, ia + size);
	printv(v2);

	message("vector filled with string: ");
	vector<string> v3(5, "string");
	printv(v3);

	message("vector coppied from vector: ");
	vector<string> v4(v3);
	printv(v4);

	message("vector (v5) moved from vector (v4): ");
	message("size of v4: ", v4.size());
	vector<string> v5(move(v4));
	printv(v5);
	message("size of v4: ", v4.size());

	return 0;

}