#include "ComplexNumbers.h"
#include <vector>


//constructor 1
ComplexNumbers::ComplexNumbers(double real_number, double virtual_number) 
{
	v.resize(2);
	v[0] = real_number;
	v[1] = virtual_number;
}

// default constructor
ComplexNumbers::ComplexNumbers() {}


//conversion constructor
ComplexNumbers::ComplexNumbers(double number) 
{
	v.resize(2);
	v[0] = number;
	v[1] = 0;
}

 //yeni sayı ekler
void ComplexNumbers::addNewItem(double val)
{
	v.push_back(val);
}

//karmaşık sayı + karmaşık sayı
const ComplexNumbers operator +(const ComplexNumbers& cn1, const ComplexNumbers& cn2) 
{
	
	return ComplexNumbers(cn1.v[0] + cn2.v[0], cn1.v[1] + cn2.v[1]);
	
}

//tam sayı + karmaşık sayı
const ComplexNumbers operator +(const int& val, const ComplexNumbers& cn1)
{
	return ComplexNumbers(cn1.v[0] + val, cn1.v[1]);
}

//karmaşık sayı + tam sayı
const ComplexNumbers operator +(const ComplexNumbers& cn1, const int& val)
{
	return ComplexNumbers(cn1.v[0] + val, cn1.v[1]);
}

//karmaşık sayı - karmaşık sayı
const ComplexNumbers operator -(const ComplexNumbers& cn1, const ComplexNumbers& cn2)
{
	return ComplexNumbers(cn1.v[0] - cn2.v[0], cn1.v[1] - cn2.v[1]);
}
//reel sayi - karmaşık sayi
const ComplexNumbers operator -(const double& val, const ComplexNumbers& cn1)
{
	return ComplexNumbers(val - cn1.v[0], cn1.v[1]);
}
//karmaşık sayi - reel sayi
const ComplexNumbers operator -(const ComplexNumbers& cn1, const double& val)
{
	return ComplexNumbers(cn1.v[0] - val, cn1.v[1]);
}

//-1 le çarpar
const ComplexNumbers operator -(const ComplexNumbers& cn1)
{
	return ComplexNumbers(cn1.v[0] * (-1), cn1.v[1] * (-1));
}


//karmaşık sayi * karmaşık sayi
const ComplexNumbers operator *(const ComplexNumbers& cn1, const ComplexNumbers& cn2)
{
	double real = cn1.v[0] * cn2.v[0] + (-1)*(cn1.v[1] * cn2.v[1]);
	double unreal = cn1.v[0] * cn2.v[1] + cn1.v[1] * cn2.v[0]; 
	return ComplexNumbers(real, unreal);
}

// atama 
ComplexNumbers ComplexNumbers::operator =(const ComplexNumbers& cn1)
{
	v.resize(2);
	v[0] = cn1.v[0];
	v[1] = cn1.v[1];
	return *this;
}
//toplama atama
ComplexNumbers ComplexNumbers::operator +=(ComplexNumbers& cn1)
{
	v.resize(2);
	v[0] += cn1.v[0];
	v[1] += cn1.v[1];
	return *this;
}

//cıkarma atama
ComplexNumbers ComplexNumbers::operator -=(ComplexNumbers& cn1)
{
	v.resize(2);
	v[0] -= cn1.v[0];
	v[1] -= cn1.v[1];
	return *this;
}

//bölme atama !!!!
ComplexNumbers ComplexNumbers::operator /=(ComplexNumbers& cn1)
{
	v.resize(2);
	v[0] /= cn1.v[0];
	v[1] /= cn1.v[1];
	return *this;
}
//karmasık sayi * reel sayi
const ComplexNumbers operator *(const ComplexNumbers& cn1, const double& val)
{
	return ComplexNumbers(cn1.v[0] * val, cn1.v[1] * val);
}

const ComplexNumbers operator *(const double& val, const ComplexNumbers& cn1)
{
	return ComplexNumbers(cn1.v[0] * val, cn1.v[1] * val);
}

//eşlenik
ComplexNumbers ComplexNumbers::operator !()
{
	v.resize(2);
	v[1] = -v[1];
	return *this;
}

//eşitlik
bool operator ==(const ComplexNumbers& cn1, const ComplexNumbers& cn2)
{
	return cn1.v[0] == cn2.v[0] && cn1.v[1] == cn2.v[1];
}

bool operator !=(const ComplexNumbers& cn1, const ComplexNumbers& cn2)
{
	return cn1.v[0] != cn2.v[0] || cn1.v[1] != cn2.v[1];
}

//yazdırma
ostream& operator <<(ostream& outputStream, const ComplexNumbers& cn1)
{
	if(cn1.v[1] > 0)
	{
		outputStream << cn1.v.at(0) << " ";
		outputStream << "+" << " ";
		outputStream << cn1.v.at(1) << "i" << endl;
	}
	if(cn1.v[1] == 0)
	{
		outputStream << cn1.v.at(0) << " + 0i" << endl;
	}
	if(cn1.v[1] < 0)
	{
		outputStream << cn1.v.at(0) << " ";
		outputStream << cn1.v.at(1) << "i" << endl;
	}
	return outputStream;
}

//okuma
istream& operator >>(istream& is, ComplexNumbers& cn1)
{
	double real;
	double unreal;
	cout << "Lutfen karmasik sayinizin real kismini giriniz" << endl;
    is >> real;
    cout << "Lutfen karmasik sayinizin virtual kismini giriniz" << endl;
    is >> unreal;
    cn1.v.push_back(real);
    cn1.v.push_back(unreal);
    return is;
}

//++
const ComplexNumbers operator ++(ComplexNumbers& cn1)
{
	cn1.v[0] = cn1.v[0] + 1;
	return cn1;
}

//--
const ComplexNumbers operator --(ComplexNumbers& cn1)
{
	cn1.v[0] = cn1.v[0] - 1;
	return cn1;
}

//üs alma
const ComplexNumbers operator ^(const ComplexNumbers& cn1, const int& val)
{
	ComplexNumbers sonuc(1,0);
	for(int i = 0; i < val; ++i)
	{	
		sonuc = sonuc * cn1;
	}
	return sonuc;
}

//bölme
const ComplexNumbers operator /(ComplexNumbers& cn1, ComplexNumbers& cn2)
{
	ComplexNumbers temp;
	temp = !cn2;
	cn1 = cn1 * temp;
	cn2 = cn2 * temp;
	return ComplexNumbers(cn1.v[0] / b, cn2.v[1] / b);

ComplexNumbers ComplexNumbers::average(vector <ComplexNumbers> numbers)
{
	int a = numbers.size();
	ComplexNumbers sum(0,0);
	for(int i = 0; i < a; ++i)
	{
		sum += numbers[i];
	}
	return sum ;
}
