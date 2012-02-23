// GPA.cpp : Defines the entry point for the console application.
//
// 
//11.З клавіатури ввести послідовність записів, які містять дані про результати сесії студентів групи: 
//<Прізвище>, <Ім’я>, <Список рейтингових оцінок>. Роздрукувати введені дані у вигляді таблиці, 
//відсортувавши їх за прізвищами студентів в абетковому порядку. Визначити двох студентів з найвищим середнім рейтинговим балом.
#include"stdafx.h"
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<iomanip>
#include<iostream>
#include<ios>
using namespace std;
// структура для збереження інформації про студентів групи
struct Student{
  char surname[20];
  char name[15];
  int mark[8];
  double GPA;
};

void sort_GPA(Student *p, int n); // сортує за прізвищами в абетковому порядку

int main()
{ 
int i, n, ns;
cout<<"Enter number of students: "; cin>>n;
Student *x=new Student[n];
cout<<"Enter number of semesters: "; cin>>ns;
printf("Enter an information about students:\n");
cout<<"Enter Last name, First name : \n";
for(i=0;i<n;i++)		// вводимо дані і заносимо в структуру
{ 
	cout<<i+1<<". ";
	cin>>x[i].surname>>x[i].name;
	int sum=0;
	cout<<"\tEnter the list of ratings : ";
	for(int j=0; j<ns; j++){
		cin>>x[i].mark[j];
		sum+=x[i].mark[j];
	}
	x[i].GPA=(double)sum/ns;
}
// знаходимо 2 студента з найвищим GPA
int imax=0, iprev=0;
for(int j=1; j<n; j++){
	if(x[j].GPA>x[imax].GPA) { 
		iprev=imax; 
		imax=j;
	}
	else iprev=x[j].GPA;
}

cout<<"\n2 students with the highest GPA:\n"<<x[imax].surname<<" "<<x[imax].name<<" "<<x[imax].GPA<<endl;
cout<<x[iprev].surname<<" "<<x[iprev].name<<" "<<x[iprev].GPA<<endl;
sort_GPA(x, n);
cout.setf(ios::left);
cout<<setw(10)<<"\n\nSurname      Name      List of ratings"<<endl;
for(i=0;i<n;i++){
	cout<<i+1<<". "<<setw(10)<<x[i].surname<<setw(10)<<x[i].name;
	for(int j=0; j<ns; j++)
		cout<<x[i].mark[j]<<" ";
	cout<<"\t"<<x[i].GPA<<endl;
}
delete[]x;
system("pause");
return 0;
}

void sort_GPA(Student *p, int n)		// сортує за прізвищами в абетковому порядку
{
int i,j;
Student y;
for(i=n-1;i>0;i--)
	for(j=0;j<i;j++)
		if(strcmp((p+j)->surname,(p+j+1)->surname)>0)
		{ 
			y=*(p+j);
			*(p+j)=*(p+j+1);
			*(p+j+1)=y;
		}
return;
}

