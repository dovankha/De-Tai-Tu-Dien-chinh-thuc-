#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class dictionary
{
	int Id;
	string Tu;

public:
	dictionary();
	dictionary(int id, string tu);
	int getId();
	string getTu()
	{
		return Tu;
	}
	void setId(int newId)
	{
		Id = newId;
	}
	void setTu(string newTu)
	{
		Tu = newTu;
	}
	void printTu(string s)
	{
		cout << "\t\t\t" << setw(13) << left << s;
	}
	virtual string showTu(string s)
	{
		return s;
	}
};

dictionary::dictionary()
{
	Id = -1;
	Tu = "";
}

dictionary::dictionary(int id, string tu)
{
	this->Id = id;
	this->Tu = tu;
}

int dictionary::getId()
{
	return Id;
}