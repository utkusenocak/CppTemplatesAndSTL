#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

template <typename lT, typename rT>
auto tf(const lT& lhs, const rT& rhs) {
	return lhs + rhs;
}

int main()
{
	int i = 47;
	const char* cstr = "this is a c-string";
	const string sclass = string("this is a string class string");

	auto x = "this is a c-string";
	decltype(x) y;

	cout << "type of i is " << typeid(i).name() << endl;
	cout << "type of cstr is " << typeid(cstr).name() << endl;
	cout << "type of sclass is " << typeid(sclass).name() << endl;
	cout << "type of x is " << typeid(x).name() << endl;
	cout << "type of y is " << typeid(y).name() << endl;

	for (auto it = sclass.begin(); it != sclass.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	for (auto c : sclass) {
		cout << c << " ";
	}
	cout << endl;

	auto z = tf<string, const char*>(sclass, cstr);
	cout << "z is " << z << endl;
	cout << "type of z is " << typeid(z).name() << endl;

	return 0;
}