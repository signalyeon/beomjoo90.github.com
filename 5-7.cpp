
/*5 - 7. ������ ���� ����� ������ �����ϴ� ���� Ŭ���� MyIntStack�� �����϶�.MyIntStack ���ÿ� ������ �� �ִ� ������ �ִ� ������ 10�̴�.*/


#include <iostream>
using namespace std;

class MyInStack {
	int p[10]; // �ִ� 10���� ���� ���� 
	int tos; // ������ ����⸦ ����Ű�� �ε��� 

public:
	MyInStack();
	bool push(int n); // ���� n Ǫ��, �� �� ������ false, �ƴϸ� true ���� 
	bool pop(int& n); // ���Ͽ� n�� ����, ������ ��� ������ false, �ƴϸ� true ���� 
};

MyInStack::MyInStack() {
	tos = 0; 
}
bool MyInStack::push(int n) {
	if (tos == 10)
		return false;
	p[tos] = n;
	tos++;
	return true;

}
bool MyInStack::pop(int &n) {
	if (tos == 0)
		return false;
	tos--;
	n = p[tos];
	return true;
}



int main() {
	MyInStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << ' ';
		else cout << endl << i + 1 << " ��° stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << " ��° stack empty";
	}
	cout << endl;
		
}
/**/