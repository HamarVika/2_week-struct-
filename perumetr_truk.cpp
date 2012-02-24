// perumetr_truk.cpp : Defines the entry point for the console application.
//15.	З клавіатури ввести послідовність даних, які містять координати вершин трикутників.  
//Роздрукувати введені дані у вигляді таблиці, відсортувавши їх у порядку спадання величин 
//	периметрів цих трикутників. Визначити відсоток трикутників, периметр яких перевищує
//	мінімальний  периметр більше, ніж у 2 рази. 
#include"stdafx.h"
#include<iomanip>
#include<iostream>
#include<cmath>
using namespace std;
struct Point{		//для зберігання координат точок
	double x, y;
};
struct Triangle   //для збереження параметрів трикутника
{
	Point a,b,c;
	double perim;
};
double len(Point p1, Point p2)	// знаходить довжину відрізка(відстань від точки p1 до p2)
{
	double y,z;
	y=(p2.x-p1.x);
	z=(p2.y-p1.y);
	return sqrt(pow(y,2)+pow(z,2));
}

void sort_Per(Triangle *p, int n);		// сортує трикутники по спаданню значень їх периметрів

int main()
{ 
int n, k=0;
double min=0;
cout<<" Enter number of triangle : ";
cin>>n;
Triangle *x=new Triangle[n];
cout<<"Enter coordinates of 3 points:  \n";
for(int i=0;i<n;i++)  //ввід
{ 
	cout<<i+1<<". ";
	cout<<" Enter first point: "; cin>>x[i].a.x>>x[i].a.y;
	cout<<"   Enter second point: "; cin>>x[i].b.x>>x[i].b.y;
	cout<<"   Enter third point: "; cin>>x[i].c.x>>x[i].c.y;
	x[i].perim=len(x[i].a, x[i].b)+len(x[i].b, x[i].c)+len(x[i].c, x[i].a);
}
min=x[0].perim;
for(int i=1;i<n;i++)		// знаходимо трикутник з мінімальним периметром
	min=(x[i].perim<min)? x[i].perim:min;
for(int i=0;i<n;i++)	//шукаємо кількість трикутників, периметр яких перевищує мінімальний більше, ніж в 2р
	if (x[i].perim>2*min) k++;
sort_Per(x, n);
cout.setf(ios::left, ios::fixed);
cout<<setw(10)<<"\n\n           Points               Perimetr"<<endl;
for(int i=0;i<n;i++)
	cout<<"\n ("<<x[i].a.x<<","<<x[i].a.y<<") , "<<"("<<x[i].b.x<<","<<x[i].b.y<<") , "<<"("<<x[i].c.x<<","<<x[i].c.y<<")  "<<setw(15)<<x[i].perim<<endl;
cout<<" Min perimetr: "<<min<<"\n percentage of triangles, perimeter greater than the minimum perimeter of more than 2 times: "<<((double)k/n)*100<<"%";
delete[]x;
system("pause");
return 0;
}
//функція сортування методом бульбашки
void sort_Per(Triangle *p, int n)
{
int i,j;
Triangle y;
for(i=n-1;i>0;i--)
	for(j=0;j<i;j++)
		if((p+j)->perim<(p+j+1)->perim)
		{ 
			y=*(p+j);
			*(p+j)=*(p+j+1);
			*(p+j+1)=y;
		}
return;
}

