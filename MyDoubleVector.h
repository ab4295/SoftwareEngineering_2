#ifndef MyDoubleVector_h
#define MyDoubleVector_h

#include<cstdlib>

class MyDoubleVector
{
private:
	double* data;
	size_t v_capacity;
	size_t used;
public:
	MyDoubleVector(size_t init_capacity = 100);
	MyDoubleVector(const MyDoubleVector& v);
	~MyDoubleVector();
	MyDoubleVector operator=(const MyDoubleVector& v);
	MyDoubleVector operator+=(const MyDoubleVector& v);
	double& operator[](int i);
	MyDoubleVector operator+(const MyDoubleVector& v);
	MyDoubleVector operator-(const MyDoubleVector& v);
	double operator*(const MyDoubleVector& v);
	MyDoubleVector operator-();
	bool operator==(const MyDoubleVector& v);
	MyDoubleVector operator()(double x);

	void pop_back();
	void push_back(double x);
	size_t capacity() const;
	size_t size() const;
	void reserve(size_t n);
	bool empty() const;
	void clear();
	void print();
}; 
#endif /* MyDoubleVector_h */