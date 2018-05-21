/*6 - 4. ���� Ŭ������ �ߺ��� �����ڸ� ����Ʈ �Ű� ������ ���� �ϳ��� �����ڷ� �ۼ��ϰ� �׽�Ʈ ���α׷��� �ۼ��϶�.
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

