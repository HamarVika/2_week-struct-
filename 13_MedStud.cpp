// 13_MedStud.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<iomanip>
#include<iostream>
#include<ios>
using namespace std;

struct MedStud 
{
char PIB[20];
char stat;
int vik;
int zrist;
int vaga;
};

void sort_PIB(MedStud *p, int n);

int main()
{ 
int i, n;
int mh=0, wh=0, mw=0, ww=0, m=0;
cout<<"Enter number of students: "; cin>>n;
MedStud *x=new MedStud[n];
printf("Enter an information about students:\n");
cout<<"Enter First name and initials, sex(w/m), age, height, weight : \n";
for(i=0;i<n;i++)
{ 
	cout<<i+1<<". ";
	cin>>(x+i)->PIB>>(x+i)->stat>>(x+i)->vik>>(x+i)->zrist>>(x+i)->vaga;
	switch((x+i)->stat){
	case 'w': wh+=x[i].zrist;  ww+=x[i].vaga;  m++; break;
	case 'm': mh+=x[i].zrist;  mw+=x[i].vaga; break;
	default: cout<<"Error!"; return 0;
	}
}
sort_PIB(x, n);
cout.setf(ios::left);
cout<<setw(10)<<"\n\nInitials    Sex   Age    Height     Weight"<<endl;
for(i=0;i<n;i++)
	cout<<i+1<<". "<<setw(10)<<x[i].PIB<<setw(5)<<x[i].stat<<setw(10)<<x[i].vik<<setw(10)<<x[i].zrist<<setw(10)<< x[i].vaga<<endl;
delete[]x;
cout<<"Men: \n average height: "<<mh/(n-m)<<"  average weight: "<<mw/(n-m);
cout<<"\nWomen: \n average height: "<<wh/m<<"  average weight: "<<ww/m<<endl;
system("pause");
return 0;
}

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
