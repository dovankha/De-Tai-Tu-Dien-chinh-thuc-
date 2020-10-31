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
	void setId(int new_id)
	{
		Id = new_id;
	}
	void setTu(string new_tu)
	{
		Tu = new_tu;
	}
	void printTu()
	{
		cout << setw(10) << left << Tu;
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