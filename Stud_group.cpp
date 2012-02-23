// Stud_group.cpp : Defines the entry point for the console application.
//21.	З клавіатури ввести послідовність записів, які містять інформацію про студентські 
//групи інституту: <Група>, <Загальна кількість студентів>, <Кількість відмінників>, 
//<Кількість студентів, що навчаються без “3”>, <Кількість невстигаючих студентів>.
//Роздрукувати введені дані у вигляді таблиці, просумувавши інформацію для кожного курсу. 
//Визначити групу, в якій найвищий відсоток студентів,  що навчаються без “3”.  
#include"stdafx.h"
#include<iomanip>
#include<iostream>
#include<ctype.h>
using namespace std;
struct Stud_group 
{
	char group[10];
	unsigned int numb_of_stud;  //загальна кількість студентів в групі
	unsigned int excellent_stud;  // кількість відмінників
	unsigned int without3_stud;   //кількість студентів, що навчаються без 3
	unsigned int unsuc_stud;   //невстигаючі студенти
};

void sort_stud(Stud_group *p, int n);  // сортуємо по курсах(в порядку зростання)

int main()
{ 
int n, nmax=0;
double max=0;
cout<<"\n Enter information about student group";
cout<<" \n How many groups? :";
cin>>n;
Stud_group *x=new Stud_group[n];
cout<<"Enter the group, total number of students, number of excellent, \n number of students studying without 3,"
	"number of unsucceding students: \n";
for(int i=0;i<n;i++)
{ 
	cout<<i+1<<". ";
	cin>>x[i].group>>x[i].numb_of_stud>>x[i].excellent_stud>>x[i].without3_stud>>x[i].unsuc_stud;
	double temp=((double)x[i].without3_stud) / x[i].numb_of_stud ; // студенти без 3 до загальної кількості студентів
	if( temp>max) 
	{		max=temp; //макс значення
			nmax=i;  //індекс групи з макс значенням в масиві структур
	}
}
cout<<" \nGroup, where the highest percent of students \nstudying without '3':  "<<x[nmax].group<<" - "<<max*100<<"% of students "<<endl;
sort_stud(x,n);
int i=0;
Stud_group temp;
cout<<setw(10)<<"\n\n Year(kyrs)    Total numb     Excellent    Without3    Unsucceding"<<endl;
while(i<n)
{
	temp=x[i];   //структура типу Stud_group для зберігання сумарних значень в межах одного курсу
	int k=0, h=0;
	while(!(isdigit(x[i].group[k]))) k++;   //знаходимо позицію першої цифри в назві групи
	while(!(isdigit(x[i+1].group[h]))) h++;  //те ж саме для (і+1)-го елемента
	while((i<n-1)&&(x[i].group[k]==x[i+1].group[h])) //
	{
		temp.excellent_stud+=x[i+1].excellent_stud; //якщо поруч 2 групи з одного курсу - сумуємо в temp
		temp.numb_of_stud+=x[i+1].numb_of_stud;
		temp.unsuc_stud+=x[i+1].unsuc_stud;
		temp.without3_stud+=x[i+1].without3_stud;
		i++;
	}
	cout<<temp.group[k]-'0'<<". "<<setw(15)<<temp.numb_of_stud<<setw(15)<<temp.excellent_stud<<setw(15)<<temp.without3_stud<<setw(10)<<temp.unsuc_stud<<endl;
	i++;
}
delete[]x;
system("pause");
return 0;
}

void sort_stud(Stud_group *p, int n)
{
Stud_group y;
for(int i=n-1;i>0;i--)
	for(int j=0;j<i;j++)
	{
		int k=0, h=0;
		while(!(isdigit(p[j].group[k]))) k++;
		while(!(isdigit(p[j+1].group[h]))) h++;
		if((p+j)->group[k]+'0'>(p+j+1)->group[h]+'0')
		{ 
			y=*(p+j);
			*(p+j)=*(p+j+1);
			*(p+j+1)=y;
		}
	}
return;
}

