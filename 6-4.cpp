/*6 - 4. 다음 클래스에 중복된 생성자를 디폴트 매개 변수를 가진 하나의 생성자로 작성하고 테스트 프로그램을 작성하라.
*/
#include <iostream>
using namespace std;

class MyVector {
	int* mem;
	int size;
public:
	/*MyVector() : mem(new int[100]), size(100) {}
	MyVector() : mem(int n, int val) : mem(new int[n]), size(n) {
		for (int i = 0; i< size; i++) mem[i] = val;
	}*/
	MyVector(int n = 100, int val = 0);
	~MyVector() { delete[] mem; }
	void show();
};

MyVector::MyVector(int n, int val) {
	mem = new int[n];
	size = n;
	for (int i = 0; i < size; i++)
		mem[i] = val;
}
void MyVector::show() {
	for (int i = 0; i < size; i++)
		cout << "mem[" << i << "] = " << mem[i] << endl;
	cout << endl;
}
int main() {
	MyVector v1;
	MyVector v2(10,20);
	v1.show();
	v2.show();
}

