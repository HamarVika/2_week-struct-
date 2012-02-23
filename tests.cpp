// tests.cpp : Defines the entry point for the console application.
//
//14.	З клавіатури ввести послідовність записів, які містять дані для комп’ютерного тестування школярів: 
//<Питання>, <4 варіанти відповідей>, <Номер правильної відповіді>. Очистити екран. 
//Випадковим чином вибирати з масиву тестових даних 5 питань (серед них не повинно бути повторень),
//до кожного з яких школяр повинен ввести відповідь. Вказати правильність кожної відповіді – у випадку помилки назвати вірний варіант. 
#include"stdafx.h"
#include<iomanip>
#include<iostream>
#include <string>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
using namespace std;

struct test   //для збереження інформації про тести
{
	string que;
	string ans[4];
	int right;
};

int main()
{ 
int n;
cout<<" Enter a number of  questions: ";
cin>>n;
test *x=new test[n];

for(int i=0;i<n;i++)
{ 
	cout<<"Enter your question:  \n";
	cout<<i+1<<". ";
	cin>>x[i].que;
	cout<<"Enter 4 possible answers:  \n";
	for(int j=0; j<4; j++){
		cout<<"\t"<<j+1<<")";
		cin>>x[i].ans[j];}
	cout<<"Enter the right answer(1/2): ";
	cin>>x[i].right;
}
//system("cls");
// генерує 5 псевдовипадкових числа, які не повторюються(діапазон - від 0 до к-сті запитань)
srand(time(NULL));
int temp[5], k, i, j;
bool present;
for (i = 0; i < 5; i++ ) {
 temp[i] = -1;
 do {
 present = 0;
 k = rand() % n;
 for ( j = 0; j < i; j++ ) {
 if ( temp[j] == k ) present = 1;
 }
 } while ( present );
 temp[i] = k;
 //cout<<temp[i]+1<<" ";
}
// тестуємо користувача
int a;
for(i=0; i<5; i++){
	int t=temp[i];
	cout<<"\n"<<i+1<<". "<<x[t].que<<endl;
	for(int j=0; j<4; j++){
		cout<<"\t"<<j+1<<")"<<x[t].ans[j];
	}
	cout<<"\nYour answer is: ";
	cin>>a;
	if(a==x[t].right) cout<<"Ok! You're right!";
	else cout<<"Not good. The right answer is "<<x[t].right;
}
delete[]x;
system("pause");
return 0;
}

