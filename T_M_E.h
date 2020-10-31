#include "dictionary.h"
#include <Windows.h>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

// T_M_E : type-mean-example
class T_M_E : public dictionary
{
	string loaiTu;
	string Nghia;
	string viDu;

public:
	T_M_E()
	{
		loaiTu = "";
		Nghia = "";
		viDu = "";
	}
	void setNghia(string new_nghia)
	{
		Nghia = new_nghia;
	}
	void setLoaiTu(string new_loaitu)
	{
		loaiTu = new_loaitu;
	}
	void setViDu(string new_vidu)
	{
		viDu = new_vidu;
	}
	string getViDu()
	{
		return viDu;
	}
	string getNghia()
	{
		return Nghia;
	}
	string getloaiTu()
	{ 
		return loaiTu;
	}
	
	T_M_E(string, string, string);
	T_M_E(int, string, string, string, string);

	void xuatfullTu()
	{
		SetConsoleTextAttribute(console, 12);
		cout << setw(9) << left << "Word"
			 << "\t" << setw(10) << left << "Type"
			 << "\t" << setw(40) << left << "Mean"
			 << "\t" << setw(10) << left << "Example"
			 << "\t" << endl;
		SetConsoleTextAttribute(console, 7);
		this->printTu();
		cout << setw(10) << left << loaiTu << "\t";
		cout << setw(40) << left << Nghia << "\t";
		cout << setw(10) << left << viDu << "\t";
	}
	void setfullTu(T_M_E p)
	{
		loaiTu = p.loaiTu;
		Nghia = p.Nghia;
		viDu = p.viDu;
		this->setId(p.getId());
		this->setTu(p.getTu());
	}
};

T_M_E::T_M_E(int id, string tu, string Ty, string Me, string Ex) : dictionary(id, tu)
{
	this->loaiTu = Ty;
	this->Nghia = Me;
	this->viDu = Ex;
}