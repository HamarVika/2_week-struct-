// shkola_klass.cpp : Defines the entry point for the console application.
//
//16.	З клавіатури ввести послідовність даних про школярів
//– учасників спортивних змагань: <Прізвище>, <Ім’я>, <Школа>, <Клас>. 
//Роздрукувати введені дані у вигляді таблиці, згрупувавши їх за номерами шкіл 
//у зростаючому порядку, а в межах школи – за класами. Визначити школу, з якої 
//в змаганнях приймає участь найбільше дев’ятикласників.
// 13_MedStud.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
#include <string.h>
#include<iomanip>
#include<iostream>
#include<ios>
using namespace std;

struct Sport_comp 
{
char surname[10];
char name[10];
unsigned numb_of_school;
char klas[5];
};
void sort_school(Sport_comp *p, int n);
int main()
{ 
int i, n, max=0, h, num=0, maxnum=0;
cout<<"Enter number of competitor: "; cin>>n; 
Sport_comp *x=new Sport_comp[n];		// динамчно створюємо масив типу Sport_comp
printf("Enter an information about competitor \n");
cout<<"Enter surname and name, number of school and class : \n";
for(i=0;i<n;i++)
{ 
	cout<<i+1<<". ";
	cin>>x[i].surname>>x[i].name>>x[i].numb_of_school>>x[i].klas; //заносимо дані в масив
}
sort_school(x, n);
cout.setf(ios::left);
cout<<setw(10)<<"\n\  Surname    Name    School     Class"<<endl;
for(i=0;i<n;i++)
	cout<<i+1<<". "<<setw(10)<<x[i].surname<<setw(10)<<x[i].name<<setw(10)<<x[i].numb_of_school<<setw(10)<<x[i].klas<<endl;
i=0;
while(i<n-1)
{
	h=0;
	while(x[i].numb_of_school==x[i+1].numb_of_school) 
	{
		if (x[i].klas[0]=='9')   {h++; num=i;} // якщо це 9 клас - збільшуємо лічильник і запам;ятовуємо індекс
		i++;
	}
	if(x[i].klas[0]=='9')   {h++; num=i;} // номер школи не дорівнює наступному, але це 9 клас
	i++;
	if(h>max) { max=h; maxnum=num;}
}
cout<<"maximum 9 ("<<max<<") in school number "<<x[maxnum].numb_of_school;
delete[]x;
system("pause");
return 0;
}

void sort_school(Sport_comp *p, int n)
{
char str1[10],str2[10],s1[5],s2[5];
Sport_comp y;
for(int i=n-1;i>0;i--)
	for(int j=0;j<i;j++)
	{
		itoa((p+j)->numb_of_school,str1,10);
		itoa((p+j+1)->numb_of_school,str2,10);
		strcpy(s1,(p+j)->klas);
		strcpy(s2,(p+j+1)->klas);
		if(strcmp(strcat(str1,s1),strcat(str2,s2))>0)
		{ 
			y=*(p+j);
			*(p+j)=*(p+j+1);
			*(p+j+1)=y;
		}
	}
return;
}


