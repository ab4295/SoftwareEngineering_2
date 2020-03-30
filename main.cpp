#include<iostream>
#include"MyDoubleVector.h"

using namespace std;

int main()
{
	MyDoubleVector chayo1(10);
	MyDoubleVector chayo2(10);
	MyDoubleVector chayo3(20);

	cout << "-------------1-------------" << endl;
	for(int i = 0;i<10;i++)
	{
		chayo1.push_back(i);
		chayo2.push_back(i);
		chayo3.push_back(i);
	}
	chayo1.print();
	chayo2.print();
	chayo3.print();
	for(int i = 0;i<5;i++)
	{
		chayo1.pop_back();
		chayo2.pop_back();
		chayo3.pop_back();
	}

	chayo1.print();
	chayo2.print();
	chayo3.print();

	chayo3.push_back(5);
	chayo3.print();

	chayo1 += chayo2;
	chayo1.print();

	cout << "-------------2-------------" << endl;

	MyDoubleVector chayo4(10);
	MyDoubleVector chayo5(10);
	MyDoubleVector chayo6(10);
	double a;

	for(int i = 0;i<10;i++)
	{
		chayo4.push_back(i);
		chayo5.push_back(i);
	}

	chayo6 = chayo5 + chayo4;
	chayo6.print();

	a = chayo5 * chayo4;
	cout << a << endl;

	chayo6 = chayo5 - chayo4;
	chayo6.print();

	chayo6 = -chayo5;
	chayo6.print();
	chayo6(5);

	a = chayo6[4];
	cout << a << endl;
	cout << "--------------------------" << endl;

	chayo6.clear();
	chayo6.print();

	cout << "-------------3-------------" << endl;

	MyDoubleVector chayo7(10);
	MyDoubleVector chayo8(10);
	MyDoubleVector chayo9;

	for(int i = 0;i<10;i++)
	{
		chayo7.push_back(i);
		chayo8.push_back(i);
	}

	if(chayo7 == chayo8)
	{
		cout << "The Vector is same!!!" << endl;
		cout << "--------------------------" << endl;
	}
	cout << "Result: " << chayo7.capacity() << "," << chayo7.size() << endl;
	cout << "--------------------------" << endl;
	if(chayo9.empty())
	{
		cout << "The Vector is Empty!!!" << endl;
		cout << "--------------------------" << endl;
	}

	chayo9.print();
	chayo9.reserve(10);
	chayo9.print();

	
	cout << "Result: " << chayo9.capacity() << "," << chayo9.size() << endl;
	cout << "--------------------------" << endl;
	chayo9.pop_back();
	
	for(int i = 0;i<3;i++)
	{
		chayo9.push_back(i);
	}
	
	chayo9.print();
	return 0;
}
