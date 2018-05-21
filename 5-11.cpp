/*5 - 11. 책의 이름과 가격을 저장하는 Book 클래스에 대해 물음에 답하여라.*/
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
	cout << title << ' ' << price << "원" << endl;
}
/*(1) Book 클래스의 생성자, 소멸자, set() 함수를 작성하라.set()함수는 멤버 변수 title에 할당된 메모리가 있으면 먼저 반환한다.
그리고 나서 새로운 메모리를 할당받고 이곳에 매개 변수로 전달받은 책이름을 저장한다.
(2) 컴파일러가 삽입하는 디폴트 복사 생성자 코드는 무엇인가 ?
/*Book::Book(Book& book) {
	int len = strlen(book.title);
	this->title = new char[len + 1];
	strcpy(this->title, book.title);
	this->price = book.price;
}/*
(3) 디폴트 복사 생성자만 있을 때 아래 main() 함수는 실행 오류를 발생한다.*/
int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp; // 복사 생성자 호출 
	java.set("명품자바", 120000);
	cpp.show();
	java.show();
	return 0;
}
/*실행 오류가 발생하지 않도록 깊은 복사 생성자를 작성하라.

(4) 문자열을 string 클래스를 사용하여 문자(3)의 실행 오류가 발생하지 않도록 Book 클래스를 수정하라.*/
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
	cout << title << ' ' << price << "원" << endl;

}*/
