

/*6 - 6 동일한 크기의 배열을 변환하는 다음 2개의 static 함수를 가진 Array Utility2 클래스를 만들고, 
이 클래스를 이용하여 페이지 316과 같이 결과를 출력하도록 프로그램을 완성하라.
*/
#include <iostream>
using namespace std;

class ArrayUtility2 {
public:
	/*~ArrayUtility2();*/
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
private:

};

/*ArrayUtility2::~ArrayUtility2() {
	
}*/
/* s1과 s2를 연결한 새로운 배열을 동적 생성하고 포인터를 리턴
static int* concat(int s1[], int s2[], int size);*/

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int* p = new int[size * 2];
	for (int i = 0; i < size; i++) {
		p[i] = s1[i];
	}
	for (int i = size + 1; i < size * 2; i++) {
		p[i] = s2[i];
	}

	return p;
} 

/* s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하여 리턴, 리턴하는 배열의 크기는 retSize에 전달하며
retSize가 0인 경우, NULL 리턴
static int* remove(int s1[], int s2[], int size, int& retSize);*/

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	for (int i = 0; i < size; i++) { //s1에서 s2와 같은 숫자가 있는지 비교해보고 있을시 s[i]에 NULL값을 넣음
		for (int j = 0; j < size; j++)
			if (s1[i] == s2[j])
				s1[i] = NULL;
	}

	for (int i = 0; i < size; i++) { // NULL값이 아닌 값들은 s2에 없는 숫자이므로 retSize++을 해줌
		if (s1[i] != NULL)
			retSize++;
	}

	int* q = new int[retSize]; // retSize로 동적할당해줌
	int count = 0;

	for (int j = 0; j < size; j++) {
		if (s1[j] != NULL) { // s1[j]값이 NULL값이 아니면 q[count]에 s1[j]값을 넣어줌
			q[count] = s1[j];
			count++;
		}
	}

	if (retSize == 0)
		return NULL;
	else
		return q;
}

int main() {
	int x[5];
	int y[5];
	int retSize;

	cout << "정수를 5개입력하라. 배열x에 삽입한다>> ";
	for (int i = 0; i < 5; i++)
		cin >> x[i];
	cout << "정수를 5개입력하라. 배열y에 삽입한다>> ";
	for (int i = 0; i < 5; i++)
		cin >> y[i];

	cout << "합친 정수 배열을 출력한다. " << endl;
	for (int i = 0; i < 10; i++) {
		cout << ArrayUtility2::concat(x, y, 5)[i] << ' ';
	}
	cout << endl;
	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 2" << endl;
	for (int i = 0; i < retSize; i++) {
		cout << ArrayUtility2::remove(x, y, 5, retSize)[i] << ' ';
	}
	return 0;
}