#include "stdafx.h"
#include<iostream>
#include"Film.h"

using namespace std;

const int max = 100;

template <class Rere>
class Set
{
public:
	Rere* set;
	int length;
	friend bool operator>(Rere el, Set& s)//проверка на принадлежность
	{
		for (int i = 0; i < s.length; i++)
		{
			if (s.set[i] == el)
				return true;
		}
		return false;
	}
	friend void operator+(Set& s, Rere el)//добавление
	{
		if (!(el>s))
		{
			s.set[s.length] = el;
			s.length++;
		}
	}
	friend ostream& operator<<(ostream& ost, Set& s)//вывод
	{
		int i = 0;
		ost << "{";
		for (i = 0; i < (s.length - 1); i++)
		{
			ost << s.set[i] << " , ";
		}
		ost << s.set[i] << "}\n";
		return ost;
	}


    Set()
	{
		set = new Rere[max];
		length = 0;
	}
	~Set()
	{
		delete[]set;
	}

	Set* operator*(Set& tet)//пересечение множеств
	{
		Set* t = new Set;
		
			for (int i = 0; i < length; i++)
			{
				if (set[i]>tet)
				{
					*t + set[i];
				}
			}
		
		return t;
	}

	bool operator<(Set& re)//проверка на подмножество
	{
		if (length>re.length)
		{
			return false;
		}
		else
		for (int i = 0; i < length; i++)
		{
			if (!(set[i]>re))
				return false;
		}
		return true;
	}

	int operator()()//мощность
	{
		return length;
	}

	Rere operator[](int i)//проверка элемента
	{
		return set[i - 1];
	}

};
template  <class Vav>
void minimum(Set<Vav>& tete)
{
	Vav min = tete.set[0];
	for (int i = 0; i < tete.length; i++)
	{
		if (tete.set[i] < min)
		{
			min = tete.set[i];
		}
	}
	cout << "Minimum: " << min << endl;
}

template  <>

void minimum(Set<Film>& tete)
{
	int min=tete[1].god;
	for (int i = 1; i <= tete.length; i++)
	{
		if (tete[i].god < min)
		{
			min = tete[i].god;
		}
	}
	cout << min << endl;
}






template <class T> 
T min(T* t1, T t2, T t3){};
template <class T>
T min(T t1, int t2){};


template <class T> class vector  { virtual    void   insert(T*); };


class Rose {};

class A { public: typedef Rose rose; };

template<typename T> class B : public T { public: typedef typename T::rose foo; };

template<typename T> void smell(T) { std::cout << "Guty!" << std::endl; } void smell(Rose) { std::cout << "Prelesty!" << std::endl; }



//10,16,25
int _tmain(int argc, _TCHAR* argv[])
{
	Set<int> x;
	x + 1;
	x + 5;
	x + 1;
	x + 14;
	x + 6;
	cout <<"A1="<< x;
	Set<int> u;
	u + 2;
	u + 1;
	u + 5;
	u + 6;
	Set<int> r;
	r + 1;
	r + 5;
	r + 1;
	cout << "C1=" << r;
	cout <<"B1="<< u;
	cout<<"B1*A1="<< *(u*x);
	cout << "C1*B1=" << *(r*u);
	cout.setf(ios::boolalpha);
	cout << "B1<A1 " << (u < x) << endl;
	cout << "C1<A1 " << (r < x) << endl;
	cout << "C1<B1 " << (r < u) << endl;
	cout << "M|A1|=" << x()<<endl;
	cout << "M|B1|=" << u() << endl;
	cout << "M|C1|=" << r() << endl;
	cout << "A1[2]=" << x[2]<<endl;
	cout << "B1[3]=" << u[3] << endl;
	cout << "C1[1]=" << r[1] << endl;
	 minimum(x);
	 minimum(u);
	 minimum(r);
	cout << endl;


	cout << "***************************" << endl << endl;


	Set<double> p;
	p + 1.5;
	p + 5.5;
	p + 1.2;
	p + 14.8;
	p + 6.1;
	cout << "A2=" << p;
	Set<double> y;
	y + 2.1;
	y + 1.2;
	y + 5.2;
	y + 6.1;
	Set<double> w;
	w + 1.1;
	w + 5.89;
	w + 1.8;
	w + 6.1;
	cout << "C2=" << y;
	cout << "B2=" << w;
	cout << "B2*A2=" << *(y*w);
	cout << "C2*B2=" << *(p*w);
	cout << "B2<A2 " << (p < y) << endl;
	cout << "C2<A2 " << (w < y) << endl;
	cout << "C2<B2 " << (w < p) << endl;
	cout << "M|A2|=" << p() << endl;
	cout << "M|B2|=" << y() << endl;
	cout << "M|C2|=" << w() << endl;
	cout << "A2[2]=" << p[2] << endl;
	cout << "B2[3]=" << w[3] << endl;
	cout << "C2[1]=" << y[1] << endl;
	minimum(p);
	minimum(y);
	minimum(w);
	cout << endl;


	cout << "***************************" << endl<<endl;

	Set<Film> s;
	s + Film(1998,"Konik");
	s + Film(2002, "Slonik1");
	cout << "Film1=" << s;
	Set<Film> a;
	a + Film(2002, "Slonik1");
	a + Film(2004, "Slonic2");
	a + Film(1998, "Konic");
	Set<Film> j;
	j + Film(2008, "Kozlic1");
	j + Film(2010, "Kozlic2");
	j + Film(1998, "Konic");
	j + Film(2014, "Kozlic4");
	cout << "Film2=" << a;
	cout << "Film3=" << j;
	cout << "Film2*Film1=" << *(s*a);
	cout << "Film3*Film2=" << *(j*a);
	cout << "Film2<Film1 " << (a < s) << endl;
	cout << "Film3<Film1 " << (j < s) << endl;
	cout << "M|Film1|=" << s() << endl;
	cout << "M|Film2|=" << a() << endl;
	cout << "M|Film3|=" << j() << endl;
	cout << "Film1[2]=" << s[2] << endl;
	cout << "Film2[3]=" << a[3] << endl;
	cout << "Film3[1]=" << j[1] << endl;
	cout << "Minimalny god iz filmov1: ";
	minimum(s);
	cout << "Minimalny god iz filmov2: ";
	minimum(a);
	cout << "Minimalny god iz filmov3: ";
	minimum(j);
	cout << endl;


	cout << "*******************************" << endl;
	smell(A::rose());     smell(B<A>::foo());     return 0;
	return 0;
}

