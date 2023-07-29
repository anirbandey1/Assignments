#include <iostream>
#include <stdlib.h>

using namespace std;

class Book{
	char *isbn;
	char *title;
	int authors_size;
	char **authors;
	int price;

public:

Book(){
	isbn=new char[20];
	title=new char [20];
	authors_size=0;
	authors=NULL;
	price=0;	
}
	
Book(const Book &ob){
	
	authors_size=ob.authors_size;
	price=ob.price;
}
void input()
{
	char garbage; //to handle IO faults

	cout<<"Enter ISBN : ";
	cin>>garbage; //to handle extra whitespace
	cin.getline(isbn,20);
	cout<<"Enter Title : ";
	cin.getline(title,20);
	cout<<"Enter No. of Authors : ";
	cin>>authors_size;

	authors = (char**)malloc(authors_size*sizeof(char*));
	for(int i=0;i<authors_size;i++)
	{
		authors[i]=(char*)calloc(20,sizeof(char));
		cout<<"Enter name of Author no. "<< (i+1) <<" : ";
		if(i==0)cin>>garbage; //to handle extra whitespace
		cin.getline(authors[i],20);
	}
	cout<<"Enter Price : ";
	cin>>price;
}


void print()
{
	cout<<"Book :- "<<endl;
	cout<<"ISBN : "<<isbn<<endl;
	cout<<"Title : "<<title<<endl;
	cout<<"No. of Authors : "<<authors_size<<endl;
	
	for(int i=0;i<authors_size;i++)
	{
		cout<<"Author no. "<<i+1<<" : "<<"Author's name"<<endl;
	}
}

};

	
class BookStore{
	int books_size;
	Book *books;

public:
BookStore(){
	books_size=0;
	books=NULL;
}

void input(){

	cout<<"Enter number of books in Bookstore : ";
	cin>>books_size;
	books=(Book*)malloc(books_size*sizeof(Book));
	for(int i=0;i<books_size;i++)
	{
		cout<<"Enter details of Book no. "<<(i+1)<<endl;
		books[i]=Book();
		books[i].input();
	}

}

void print(){
	cout<<"BookStore has "<<books_size<<" books"<<endl;

	for(int i=0;i<books_size;i++)
	{		
		books[i].print();
	}
}

int totalPrice(){

	int total_price=0;
	for(int i=0;i<books_size;i++)
	{	
		total_price+=books[i].price;

	}
	return total_price;
}


int noOfCopies(int given_isbn){
	int cnt=0;

	for(int i=0;i<books_size;i++)
	{
		if(given_isbn==books[i].isbn){
			cnt++;

		}
	}

	return cnt;
}

int uniqueISBN(){

	int cnt=0;
	for(int i=0;i<books_size;i++)
	{
		int flag=false;
		for(int j=0;j<books_size;j++)
		{
			if(books[i].isbn==books[j].isbn)
			{
				flag=true;
			}
		}

		if(!flag) cnt++;
	}
	return cnt;
}

Book* uniqueBooks(int &size)
{
	size=uniqueISBN();
	Books *unique_books=new Book[size];
	int k=0;

	for(int i=0;i<books_size;i++)
	{
		int flag=false;
		for(int j=i+1;j<books_size;j++)
		{
			if(books[i].isbn==books[j].isbn){
				flag=true;
			}
		}

		if(!flag){
			unique_books[k]=Book(books[i]);
			k++;
		}
	}

	return unique_books;
}

};

int main(){

	BookStore ob;
	ob.input();

	BookStore ob2;

	return 0;
}
