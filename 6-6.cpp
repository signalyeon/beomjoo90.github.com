

/*6 - 6 ������ ũ���� �迭�� ��ȯ�ϴ� ���� 2���� static �Լ��� ���� Array Utility2 Ŭ������ �����, 
�� Ŭ������ �̿��Ͽ� ������ 316�� ���� ����� ����ϵ��� ���α׷��� �ϼ��϶�.
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
/* s1�� s2�� ������ ���ο� �迭�� ���� �����ϰ� �����͸� ����
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

/* s1���� s2�� �ִ� ���ڸ� ��� ������ ���ο� �迭�� ���� �����Ͽ� ����, �����ϴ� �迭�� ũ��� retSize�� �����ϸ�
retSize�� 0�� ���, NULL ����
static int* remove(int s1[], int s2[], int size, int& retSize);*/

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	for (int i = 0; i < size; i++) { //s1���� s2�� ���� ���ڰ� �ִ��� ���غ��� ������ s[i]�� NULL���� ����
		for (int j = 0; j < size; j++)
			if (s1[i] == s2[j])
				s1[i] = NULL;
	}

	for (int i = 0; i < size; i++) { // NULL���� �ƴ� ������ s2�� ���� �����̹Ƿ� retSize++�� ����
		if (s1[i] != NULL)
			retSize++;
	}

	int* q = new int[retSize]; // retSize�� �����Ҵ�����
	int count = 0;

	for (int j = 0; j < size; j++) {
		if (s1[j] != NULL) { // s1[j]���� NULL���� �ƴϸ� q[count]�� s1[j]���� �־���
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

	cout << "������ 5���Է��϶�. �迭x�� �����Ѵ�>> ";
	for (int i = 0; i < 5; i++)
		cin >> x[i];
	cout << "������ 5���Է��϶�. �迭y�� �����Ѵ�>> ";
	for (int i = 0; i < 5; i++)
		cin >> y[i];

	cout << "��ģ ���� �迭�� ����Ѵ�. " << endl;
	for (int i = 0; i < 10; i++) {
		cout << ArrayUtility2::concat(x, y, 5)[i] << ' ';
	}
	cout << endl;
	cout << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ 2" << endl;
	for (int i = 0; i < retSize; i++) {
		cout << ArrayUtility2::remove(x, y, 5, retSize)[i] << ' ';
	}
	return 0;
}