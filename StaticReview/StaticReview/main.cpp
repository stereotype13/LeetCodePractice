#include <iostream>

using namespace std;

void func1() {
	static int x = 0;
	cout << x << endl;
	++x;
}

int main() {

	for (int i = 0; i < 10; ++i)
		func1();

	cin.get();
	return 0;
}