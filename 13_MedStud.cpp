// 13_MedStud.cpp : Defines the entry point for the console application.
//13.	З клавіатури ввести послідовність записів, які містять дані медичного обстеження студенів: <Прізвище, ініціали>, 
//Вік>, <Стать>, <Зріст>, <Вага>. Роздрукувати введені дані у вигляді таблиці, відсортувавши їх за прізвищами студенів в 
//абетковому порядку. Визначити середній зріст і вагу студентів жіночої і чоловічої статі.
#include"stdafx.h"
#include<iomanip>
#include<iostream>
using namespace std;
//структура з даними медичного обстеження
struct MedStud 
{
char PIB[20];
char stat;
int vik;
int zrist;
int vaga;
};
//функція сортування введених даних в абетковому порядку(методом бульбашки)
void sort_PIB(MedStud *p, int n);

int main()
{ 
int i, n;
int mh=0, wh=0, mw=0, ww=0, m=0;
cout<<"Enter number of students: "; cin>>n;
MedStud *x=new MedStud[n];      //виділяємо память на введені дані
printf("Enter an information about students:\n");
cout<<"Enter First name and initials, sex(w/m), age, height, weight : \n";
for(i=0;i<n;i++)
{ 
	cout<<i+1<<". ";
	cin>>(x+i)->PIB>>(x+i)->stat>>(x+i)->vik>>(x+i)->zrist>>(x+i)->vaga;
	switch((x+i)->stat){      //відразу рахуємо середню вагу та зріст для чоловіків та жінок
	case 'w': wh+=x[i].zrist;  ww+=x[i].vaga;  m++; break;  // якщо жінка 
	case 'm': mh+=x[i].zrist;  mw+=x[i].vaga; break;            //якщо чоловік
	default: cout<<"Error!"; return 0;             //якщо введені дані не відповідають вимогам
	}
}
sort_PIB(x, n);
cout.setf(ios::left);
cout<<setw(10)<<"\n\nInitials    Sex   Age    Height     Weight"<<endl;
for(i=0;i<n;i++)
	cout<<i+1<<". "<<setw(10)<<x[i].PIB<<setw(5)<<x[i].stat<<setw(10)<<x[i].vik<<setw(10)<<x[i].zrist<<setw(10)<< x[i].vaga<<endl;
delete[]x;
cout<<"Men: \n average height: "<<mh/(n-m)<<"  average weight: "<<mw/(n-m);      //рахуємо середнє значення для чоловіків
cout<<"\nWomen: \n average height: "<<wh/m<<"  average weight: "<<ww/m<<endl;       //та жінок і виводимо його на екран
system("pause");
return 0;
}
//сортуємо введені дані методом бульбашки
void sort_PIB(MedStud *p, int n)
{
int i,j;
MedStud y;
for(i=n-1;i>0;i--)
	for(j=0;j<i;j++)
		if(strcmp((p+j)->PIB,(p+j+1)->PIB)>0)
		{ 
			y=*(p+j);
			*(p+j)=*(p+j+1);
			*(p+j+1)=y;
		}
return;
}
