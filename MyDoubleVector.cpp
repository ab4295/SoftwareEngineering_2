#include"MyDoubleVector.h"
#include<iostream>
#include<algorithm>

using namespace std;
/* Constructor */
MyDoubleVector::MyDoubleVector(size_t init_capacity)
{
	v_capacity = init_capacity;
	data = new double[v_capacity];
	used = 0;
}
/* Copy Constructor */
MyDoubleVector::MyDoubleVector(const MyDoubleVector& v)
{
	v_capacity = v.v_capacity;
	used = v.used;
	data = new double[v_capacity];
	copy(v.data,v.data + v.used,data);
}
/* Destructor */
MyDoubleVector::~MyDoubleVector()
{
	delete[] data;
	used = 0;
	v_capacity = 0;
}
/* Assignment Operator */
MyDoubleVector MyDoubleVector::operator=(const MyDoubleVector& v)
{
	if(this == &v)
		return *this;
	v_capacity = v.v_capacity;
	used = v.used;
	delete[] data;
	data = new double[v_capacity];
	copy(v.data,v.data + v.used,data);
	return *this;
}
/* (Binary)operator+= */
MyDoubleVector MyDoubleVector::operator+=(const MyDoubleVector& v)
{
	reserve(v_capacity + v.v_capacity);
	copy(v.data,v.data+v.used,data+used);
	used = used + v.used;
	return *this;
}
/* (Unary)operator[] */
double& MyDoubleVector::operator[](int i)
{
	if(i > used)
	{
		cout << "the position is out of range" << endl;
		cout << "Terminate the Program" << endl;
		exit(0);
	}
	else
		return data[i];
}
/* (Binary)operator+ */
MyDoubleVector MyDoubleVector::operator+(const MyDoubleVector& v)
{
	MyDoubleVector sum;
	sum.v_capacity = v_capacity;
	sum.used = used;
	if(used != v.used)
	{
		cout << "size is not same." << endl;
		return *this;
	}
	else
	{
		for(int i = 0;i<used;i++)
		{
			sum.data[i] = data[i] + v.data[i];
		}
	}
	return sum;	
}
/* (Binary)operator- */
MyDoubleVector MyDoubleVector::operator-(const MyDoubleVector& v)
{
	MyDoubleVector diff;
	diff.v_capacity = v_capacity;
	diff.used = used;
	if(used != v.used)
	{
		cout << "size is not same." << endl;
		return *this;
	}
	else
	{
		for(int i = 0;i<used;i++)
		{
			diff.data[i] = data[i] - v.data[i];
		}
	}
	return diff;
}
/* (Binary)operator* */
double MyDoubleVector::operator*(const MyDoubleVector& v)
{
	MyDoubleVector multiply;
	double sum = 0.0;
	multiply.v_capacity = v_capacity;
	multiply.used = used;
	if(used != v.used)
	{
		cout << "size is not same." << endl;
		return 0;
	}
	else
	{
		for(int i = 0;i<used;i++)
		{
			multiply.data[i] = data[i] * v.data[i];
			sum += multiply.data[i];
		}
	}
	return sum;
}
/* (Unary)operator- */
MyDoubleVector MyDoubleVector::operator-()
{
	for(int i = 0;i<used;i++)
	{
		data[i] = -data[i];
	}
	return *this;
}
/* (Binary)operator== */
bool MyDoubleVector::operator==(const MyDoubleVector& v)
{
	int flag = 0;
	if(used == v.used)
	{
		for(int i = 0;i<used;i++)
		{
			if(data[i] == v.data[i])
			{
				flag++;
			}
		}
	}
	if(flag == used)
		return true;
	else
		return false;
}
/* (Unary)operator() */
MyDoubleVector MyDoubleVector::operator()(double x)
{
	for(int i = 0;i<used;i++)
		data[i] = x;
	return *this;
}

/*PreCondition : used 가 0이 아니어야 한다.(used = 0이면 제거 할 값이 x)*/
/*PostCondition : vector의 맨 마지막 값을 제거하고, used와 capacity를 하나씩 감소시킨다 */
void MyDoubleVector::pop_back()
{
	if(used == 0)
	{
		cout << "The Vector is empty!!! can not pop!!!" << endl;
		return ;
	}
	else
	{
		if(used == v_capacity)
		{
			--used;
			reserve(v_capacity-1);
		}
		else
		{
			--used;
			data[used] = 0;
			reserve(v_capacity-1);
		}
	}
}

/*PreCondition : double형 x값을 인자로 받는다.*/
/*PostCondition : 벡터의 맨 마지막에 값을 넣고, 만약, 벡터가 가득 찼다면, capacity를 하나 늘린다.*/
void MyDoubleVector::push_back(double x)
{
	if(used == v_capacity)
		reserve(v_capacity + 1);
	data[used] = x;
	++used;
}

/*PreCondition : capacity를 받는다. */
/*PostCondition : capacity 값을 return. */
size_t MyDoubleVector::capacity() const
{
	return v_capacity;
}

/*PreCondition : used를 받는다. */
/*PostCondition : used 값을 리턴 */
size_t MyDoubleVector::size() const
{
	return used;
}

/*PreCondition : 벡터의 사이즈를 조절할 정수 n을 받는다. */
/*PostCondition : 벡터의 capacity를 n으로 조절한다. */
void MyDoubleVector::reserve(size_t n)
{
	double* reserved_data;
	if(n < used)
		return;

	v_capacity = n;	
	reserved_data = new double[v_capacity];
	copy(data,data+used,reserved_data);
	for(int i = 0;i<used;i++)
	{
		data[i] = 0;
	}
	data = reserved_data;
}

/*PreCondition : used값을 받는다. */
/*PostCondition : 0이라면 true를 리턴, 0이 아니라면 false를 리턴, */
bool MyDoubleVector::empty() const
{
	if(used == 0)
		return true;
	else
		return false;
}

/*PreCondition : x */
/*PostCondition : 벡터 내부의 값을 전부 0으로 바꾸고, used와 capacity값도 0으로 바꾼다.*/
void MyDoubleVector::clear()
{
	for(int i = 0;i<used;i++)
	{
		data[i] = 0;
	}
	used = 0;
	v_capacity = 0;
}
/* main함수에서 벡터의 상태를 보기 위한 print()함수 (임의 제작) */
void MyDoubleVector::print()
{
	for(int i = 0;i<used;i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
	cout << v_capacity << endl;
	cout << used << endl;
	cout << "---------------------------" << endl;
}