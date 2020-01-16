#include <vector>
#include <iostream>
using namespace std;
class ComplexNumbers
{
public:
	ComplexNumbers(double real_number, double virtual_number);
	ComplexNumbers();
	ComplexNumbers(double number);
	ComplexNumbers average(vector <ComplexNumbers> numbers);
	void addNewItem(double val);
	friend const ComplexNumbers operator +(const ComplexNumbers& cn1, const ComplexNumbers& cn2);
	friend const ComplexNumbers operator +(const ComplexNumbers& cn1, const int& val);
	friend const ComplexNumbers operator +(const int& val, const ComplexNumbers& cn1);
	friend const ComplexNumbers operator -(const ComplexNumbers& cn1, const ComplexNumbers& cn2);
	friend const ComplexNumbers operator -(const double& val, const ComplexNumbers& cn1);
	friend const ComplexNumbers operator -(const ComplexNumbers& cn1, const double& val);
	friend const ComplexNumbers operator -(const ComplexNumbers& cn1);
	friend const ComplexNumbers operator *(const ComplexNumbers& cn1, const ComplexNumbers& cn2);
	ComplexNumbers operator =(const ComplexNumbers& cn1);
	ComplexNumbers operator +=(ComplexNumbers& cn1);
	ComplexNumbers operator -=(ComplexNumbers& cn1);
	friend const ComplexNumbers operator /(ComplexNumbers& cn1, ComplexNumbers& cn2);
	friend const ComplexNumbers operator *(const ComplexNumbers& cn1, const double& val);
	friend const ComplexNumbers operator *(const double& val, const ComplexNumbers& cn1);
	ComplexNumbers operator !();
	friend bool operator ==(const ComplexNumbers& cn1, const ComplexNumbers& cn2);
	friend bool operator !=(const ComplexNumbers& cn1, const ComplexNumbers& cn2);
	friend ostream& operator <<(ostream& outputStream, const ComplexNumbers& cn1);
	friend istream& operator >>(istream& is, ComplexNumbers& cn1);
	friend const ComplexNumbers operator ++(ComplexNumbers& cn1);
	friend const ComplexNumbers operator --(ComplexNumbers& cn1);
	friend const ComplexNumbers operator ^(const ComplexNumbers& cn1, const int& val);
private:
	vector <double> v; // X = a + bi , v[0] = a v[1] = b 
};

