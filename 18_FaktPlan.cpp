// 18_FaktPlan.cpp : Defines the entry point for the console application.
//
// 13_MedStud.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<iomanip>
#include<iostream>
#include<ios>
#include<string>
using namespace std;
struct Brigada 
{
	char days[10];
	double plan;
	double fact;
};
const int n=3;
void sort_Plan(Brigada *p);

int main()
{ 

Brigada *x=new Brigada[n];
cout<<"Enter day, planned output, actual output : \n";
for(int i=0;i<n;i++)
{ 
	cout<<i+1<<". ";
	cin>>x[i].days>>x[i].plan>>x[i].fact;
}
sort_Plan(x);
int nmax=0, nmin=0;
double max=(x[0].fact/x[0].plan)*100, min=max;
for(int i=1;i<n;i++)
{ 
	double temp=(x[i].fact/x[i].plan)*100;
	if(temp>max) {max=temp; nmax=i;}
	if(temp<min) {min=temp; nmin=i;}
}
cout.setf(ios::left, ios::fixed);
cout<<setw(10)<<"\n\n          Day     Planned      Actual"<<endl;
for(int i=0;i<n;i++)
	cout<<i+1<<". "<<setw(10)<<x[i].days<<setw(10)<<x[i].plan<<setw(10)<<x[i].fact<<endl;
cout<<" \n Max % plan execution:  "<<x[nmax].days<<"  "<<x[nmax].plan<<"  "<<x[nmax].fact<<endl;
cout<<" \n Min % plan execution: "<<x[nmin].days<<"  "<<x[nmin].plan<<"  "<<x[nmin].fact<<endl;
delete[]x;
system("pause");
return 0;
}

void sort_Plan(Brigada *p)
{
int i,j;
Brigada y;
for(i=n-1;i>0;i--)
	for(j=0;j<i;j++)
		if((p+j)->plan>(p+j+1)->plan)
		{ 
			y=*(p+j);
			*(p+j)=*(p+j+1);
			*(p+j+1)=y;
		}
return;
}

