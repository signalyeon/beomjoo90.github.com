
/*5 - 7. 다음과 같이 선언된 정수를 저장하는 스택 클래스 MyIntStack을 구현하라.MyIntStack 스택에 저장할 수 있는 정수의 최대 개수는 10이다.*/


#include <iostream>
using namespace std;

class MyInStack {
	int p[10]; // 최대 10개의 정수 저장 
	int tos; // 스택의 꼭대기를 가리키는 인덱스 

public:
	MyInStack();
	bool push(int n); // 정수 n 푸시, 꽉 차 있으면 false, 아니면 true 리턴 
	bool pop(int& n); // 팝하여 n에 저장, 스택이 비어 있으면 false, 아니면 true 리턴 
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
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;
		
}
/**/