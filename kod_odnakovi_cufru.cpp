// kod_odnakovi_cufru.cpp : Defines the entry point for the console application.
//
//19. З клавіатури ввести послідовність структур з даними у формі  <Числовий код>, <Повідомлення>.
//Відсортувати введені записи в порядку спадання кодів і роздрукувати відсортований масив. 
//Визначити кількість повідомлень, в кодах яких є поруч дві однакові цифри.
#include"stdafx.h"
#include<iomanip>
#include<iostream>
#include<string>
using namespace std;
struct kod_str 
{
	unsigned long kod;
	string message;
};

void sort_kod(kod_str *p, int n);      // сортування в порядку спадання кодів
bool is_similar_dig(unsigned long ch); // функція, яка чи в числі є поруч 2 однакові цифри

int main()
{ 
int n, k=0;
cout<<"Enter quantity : "; cin>>n;
kod_str *x=new kod_str[n];            //масив структур в динамічній пам;яті
cout<<" Enter kod and message:\n";
for(int i=0;i<n;i++)
{ 
	cout<<i+1<<". ";
	cin>>x[i].kod>>x[i].message;
	if (is_similar_dig(x[i].kod)) k++;  // якщо у введеному коді є поруч однакові цифри - збільшуємо лічильник
}
sort_kod(x, n);
cout<<setw(10)<<"\n\n    Kod      Message"<<endl;
for(int i=0;i<n;i++)
{
	cout.setf(ios::left);
	cout<<i+1<<". "<<setw(10)<<x[i].kod<<setw(15)<<x[i].message<<endl;
}
cout<<"\n Number of messages with a similar digit in kod: "<<k<<endl;
delete[]x;                 //звільнення пам;яті
system("pause");
return 0;
}

void sort_kod(kod_str *p, int n)   // сортування кодів методом бульбашки
{
int i,j;
kod_str temp;
for(i=n-1;i>0;i--)
	for(j=0;j<i;j++)
		if((p+j)->kod<(p+j+1)->kod)
		{ 
			temp=*(p+j);
			*(p+j)=*(p+j+1);
			*(p+j+1)=temp;
		}
return;
}

bool is_similar_dig(unsigned long uli)
{
	char str[10];
	itoa(uli,str,10);
	for(int i=0; i<strlen(str)-1; i++)
		if(str[i]==str[i+1])         //якщо поруч є одинакові цифри - поертаємо true
			return true;
	return false;				// всі цифри в коді є різними
}