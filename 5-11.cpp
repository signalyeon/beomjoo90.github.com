/*5 - 11. å�� �̸��� ������ �����ϴ� Book Ŭ������ ���� ������ ���Ͽ���.*/
#include <iostream>
using namespace std;
#include <string>
#pragma warning (disable:4996)

class Book {
	char *title;
	int price;
public:
	Book(const char* title, int price);
	Book(Book& book);
	~Book();
	void set(const char* title, int price);
	void show();
};

Book::Book(const char* title, int price) {
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
	this->price = price;
}
Book::Book(Book& book) {
	int len = strlen(book.title);
	this->title = new char[len + 1];
	strcpy(this->title, book.title);
	this->price = book.price;
}
Book::~Book(){
	delete[] title;
}
void Book::set(const char* title, int price) {
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
	this->price = price;
}
void Book::show() {
	cout << title << ' ' << price << "��" << endl;
}
/*(1) Book Ŭ������ ������, �Ҹ���, set() �Լ��� �ۼ��϶�.set()�Լ��� ��� ���� title�� �Ҵ�� �޸𸮰� ������ ���� ��ȯ�Ѵ�.
�׸��� ���� ���ο� �޸𸮸� �Ҵ�ް� �̰��� �Ű� ������ ���޹��� å�̸��� �����Ѵ�.
(2) �����Ϸ��� �����ϴ� ����Ʈ ���� ������ �ڵ�� �����ΰ� ?
/*Book::Book(Book& book) {
	int len = strlen(book.title);
	this->title = new char[len + 1];
	strcpy(this->title, book.title);
	this->price = book.price;
}/*
(3) ����Ʈ ���� �����ڸ� ���� �� �Ʒ� main() �Լ��� ���� ������ �߻��Ѵ�.*/
int main() {
	Book cpp("��ǰC++", 10000);
	Book java = cpp; // ���� ������ ȣ�� 
	java.set("��ǰ�ڹ�", 120000);
	cpp.show();
	java.show();
	return 0;
}
/*���� ������ �߻����� �ʵ��� ���� ���� �����ڸ� �ۼ��϶�.

(4) ���ڿ��� string Ŭ������ ����Ͽ� ����(3)�� ���� ������ �߻����� �ʵ��� Book Ŭ������ �����϶�.*/
/*class Book {
	string title;
	int price;
public:
	Book(string title, int price);
	Book(Book& book);
	~Book();
	void set(string title, int price);
	void show();
};

Book::Book(string title, int price) {
	this->title = title;
	this->price = price;
}
Book::Book(Book& book) {
	this->title = book.title;
	this->price = book.price;
}
Book::~Book() {
}
void Book::set(string title, int price) {
	this->title = title;
	this->price = price;
}
void Book::show() {
	cout << title << ' ' << price << "��" << endl;

}*/
