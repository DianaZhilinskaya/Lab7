#include "stdafx.h"
#include "Film.h"
#include<string>

ostream& operator<<(ostream& ost, Film& s)//вывод
{
	ost << s.god << "  " << s.name;
	return ost;
}

Film::Film(int h, string f)
{
	name = f;
	god = h;
}
Film::Film()
{

}
bool Film::operator==(Film& re)
{
	return (god==re.god && name==re.name);
}
