#include "dictionary.h"
#include <Windows.h>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

struct TU:public dictionary
{
	string showTu(string s)
	{
		this->printTu(s); 
		return ""; 
	} 	
};

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
		SetConsoleTextAttribute(console, 91);
		cout << "\t\t\t" << setw(13) << left << "Word" << setw(20) << left << "Type" << setw(40) << left << "Mean" << setw(40) << left << "Example" << endl;
		SetConsoleTextAttribute(console, 7);

		dictionary *ptr2 = new TU;
		string s=this->getTu();
		cout<<ptr2->showTu(s); 

		string loaiTuMoi, nghiaMoi, viDuMoi, loaiTuCopy = loaiTu + ';', nghiaCopy = Nghia + '/', viDuCopy = viDu + '/';
		string MloaiTuMoi[100], MnghiaMoi[100], MviDuMoi[100], temp1 = "", temp2 = "";
		bool KT[100];
		int lenloaiTu = 0, lenNghia = 0, lenViDu = 0;
		for (int i = 0; i < loaiTuCopy.length(); i++)
			if (loaiTuCopy[i] == ';')
				lenloaiTu++;

		for (int i = 0; i < nghiaCopy.length(); i++)
			if (nghiaCopy[i] == ';' || nghiaCopy[i] == '/')
			{
				lenNghia++;
				temp1 += nghiaCopy[i];
			}

		for (int i = 0; i < viDuCopy.length(); i++)
			if (viDuCopy[i] == ';' || viDuCopy[i] == '/')
			{
				lenViDu++;
				temp2 += viDuCopy[i];
			}

		int GTLN = max(lenloaiTu, max(lenNghia, lenViDu));
		for (int i = 0; i < GTLN; i++)
		{
			MloaiTuMoi[i] = "";
			MnghiaMoi[i] = "";
			MviDuMoi[i] = "";
		}
		for (int i = 0; i < GTLN;)
		{
			for (int j = 0; j < loaiTuCopy.length(); j++)
				if (loaiTuCopy[j] != ';')
					loaiTuMoi += loaiTuCopy[j];
				else
				{
					MloaiTuMoi[i] = loaiTuMoi;
					loaiTuCopy = loaiTuCopy.erase(0, j + 1);
					loaiTuMoi = loaiTuMoi.erase(0, loaiTuMoi.length());
					break;
				}
			int z = 0, nho1 = i, nho2 = i;
			for (int j = 0; j < nghiaCopy.length(); j++)
			{
				if (nghiaCopy[j] != ';' && nghiaCopy[j] != '/')
				{
					nghiaMoi += nghiaCopy[j];
				}
				else
				{
					MnghiaMoi[nho1] = nghiaMoi;
					nho1++;
					nghiaMoi = nghiaMoi.erase(0, nghiaMoi.length());
					if (nghiaCopy[j] == '/')
					{
						z = j;
						break;
					}
				}
			}
			nghiaCopy = nghiaCopy.erase(0, z + 1);
			for (int j = 0; j < viDuCopy.length(); j++)
			{
				if (viDuCopy[j] != ';' && viDuCopy[j] != '/')
				{
					viDuMoi += viDuCopy[j];
				}
				else
				{
					MviDuMoi[nho2] = viDuMoi;
					nho2++;
					viDuMoi = viDuMoi.erase(0, viDuMoi.length());
					if (viDuCopy[j] == '/')
					{
						z = j;
						break;
					}
				}
			}
			viDuCopy = viDuCopy.erase(0, z + 1);
			if (nho1 > nho2)
				i = nho1;
			else
				i = nho2;
		}
		for (int i = 0; i < GTLN; i++)
		{
			if (i == 0)
				cout << setw(20) << left << MloaiTuMoi[i]
					 << setw(40) << left << MnghiaMoi[i]
					 << setw(40) << left << MviDuMoi[i] << endl;
			else
				cout << "\t\t\t" << setw(13) << left << " "
					 << setw(20) << left << MloaiTuMoi[i]
					 << setw(40) << left << MnghiaMoi[i]
					 << setw(40) << left << MviDuMoi[i] << endl;
		}
		SetConsoleTextAttribute(console, 12);
		cout << "\t\t\t\t***NOTE: An phim bat ky de quay lai menu chuc nang";
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