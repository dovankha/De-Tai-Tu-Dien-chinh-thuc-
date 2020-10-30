#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

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
		cout << setw(7) << left << Tu << "\t";
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
	T_M_E(string, string, string);
	T_M_E(int, string, string, string, string);
	void xuatfullTu()
	{
		// cout << "Type: "<< loaiTu << endl << "Mean: "<< Nghia << endl << "Example: "<< viDu << endl;
		SetConsoleTextAttribute(console, 12);
		cout << setw(7) << left << "Word"
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

struct node
{
	T_M_E data;
	node *pNext;
};
typedef struct node NODE; //thay the struct node thanh NODE

struct list
{
	NODE *pHead;
};
typedef struct list LIST;

void KhoiTao(LIST &l)
{
	l.pHead = NULL;
}

bool isEmpty(LIST &l)
{
	if (l.pHead == NULL)
		return true;

	return false;
}

NODE *KhoiTaoNODE(const T_M_E &x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "Khong du bo nho cap phat !";
		return NULL;
	}

	p->data.setfullTu(x);
	p->pNext = NULL;
	return p;
}

void themVaoDau(LIST &l, NODE *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

NODE *findTail(LIST &l)
{
	if (isEmpty(l))
		return NULL;
	NODE *p = l.pHead;
	while (p->pNext != NULL)
	{
		p = p->pNext;
	}

	return p;
}

void themVaoCuoi(LIST &l, NODE *p)
{
	if (l.pHead == NULL)
	{
		themVaoDau(l, p);
	}
	else
	{
		findTail(l)->pNext = p;
	}
}

void xuatDanhSach(LIST l)
{
	if (l.pHead == NULL)
		return;
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		k->data.xuatfullTu();
		cout << endl;
	}
}

int main()
{
	SetConsoleTitle(TEXT("Tu Dien Anh-Viet"));

	LIST l;
	KhoiTao(l);
	ifstream fw, ft, fm, fe;
	string tu, loai, nghia, vd;
	int count = 0;
	fw.open("word.txt", ios::in);
	ft.open("type.txt", ios::in);
	fm.open("mean.txt", ios::in);
	fe.open("example.txt", ios::in);
	while (!fw.eof())
	{
		count++;
		getline(fw, tu, ' ');
		getline(ft, loai, ' ');
		getline(fm, nghia, '@');
		getline(fe, vd, '@');
		T_M_E tuVung(count, tu, loai, nghia, vd);
		NODE *p = KhoiTaoNODE(tuVung);
		themVaoCuoi(l, p);
	}
	/*cout << "Danh sach lien ket don co:" << endl;
	xuatDanhSach(l);*/
	int luaChon;
	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(console, 9);
		cout << "\t\t\t\t==================================" << endl
			 << "\t\t\t\t||         ****MENU****         ||" << endl
			 << "\t\t\t\t||   1. Tim kiem                ||" << endl
			 << "\t\t\t\t||   2. Them tu                 ||" << endl
			 << "\t\t\t\t||   3. Chinh sua tu            ||" << endl
			 << "\t\t\t\t||   4. Xoa tu                  ||" << endl
			 << "\t\t\t\t||   0. Thoat khoi tu dien      ||" << endl
			 << "\t\t\t\t==================================" << endl;

		SetConsoleTextAttribute(console, 7);
		cout << "\n\n\tMoi ban nhap lua chon: ";
		cin >> luaChon;

		if (luaChon < 0 || luaChon > 4)
		{
			SetConsoleTextAttribute(console, 12);
			cout << "\n\tLua chon cua ban khong dung!";
			getch();
		}

		else if (luaChon == 1)
		{
			system("cls");
			bool timKiem = false;
			string search;
			cout << "\n\t\tNhap tu can tim kiem: ";
			cin >> search;
			cout << "\t\t----------------------\n"
				 << endl;
			for (NODE *k = l.pHead; k != NULL; k = k->pNext)
				if (search == k->data.getTu())
				{
					timKiem = true;
					k->data.xuatfullTu();
					cout << endl;
					getch();
				}
			if (!timKiem)
			{
				cout << "Tu '" << search << "' chua co trong tu dien!" << endl
					 << "Nhan phim bat ki de quay lai!" << endl;
				getch();
			}
		}
		else if (luaChon == 3)
		{
			system("cls");
			bool timKiem = false;
			string search;
			cout << "\n\n\t\tNhap tu can chinh sua: ";
			cin >> search;
			for (NODE *k = l.pHead; k != NULL; k = k->pNext)
				if (search == k->data.getTu())
				{
					timKiem = true;
					while (true)
					{
						system("cls");
						SetConsoleTextAttribute(console, 11);
						cout << "\n\n";
						cout << "\t\t\t\t============================" << endl
							 << "\t\t\t\t||    1. Sua loai tu      ||" << endl
							 << "\t\t\t\t||    2. Sua nghia        ||" << endl
							 << "\t\t\t\t||    3. Sua vi du        ||" << endl
							 << "\t\t\t\t||    4. Sua tat ca       ||" << endl
							 << "\t\t\t\t||    0. Cancel           ||" << endl
							 << "\t\t\t\t============================" << endl;

						SetConsoleTextAttribute(console, 7);
						int luachon1;
						cout << "\n\tNhap lua chon cua ban: ";
						cin >> luachon1;
						if (luachon1 < 0 || luachon1 > 4)
						{
							SetConsoleTextAttribute(console, 12);
							cout << "\n\tLua chon cua ban khong dung! Vui long nhap lai!" << endl;
							getch();
						}
						else if (luachon1 == 1)
						{
							string loaitu1;
							cout << "\tNhap loai tu ban muon sua thanh: ";
							cin.ignore();
							getline(cin, loaitu1);
							k->data.setLoaiTu(loaitu1);
						}
						else if (luachon1 == 2)
						{
							string nghia1;
							cout << "\tNhap nghia ban muon sua thanh: ";
							cin.ignore();
							getline(cin, nghia1);
							k->data.setNghia(nghia1);
						}
						else if (luachon1 == 3)
						{
							string vidu1;
							cout << "\tNhap nghia ban muon sua thanh: ";
							cin.ignore();
							getline(cin, vidu1);
							k->data.setViDu(vidu1);
						}
						else if (luachon1 == 4)
						{
							string tu1;
							cout << "\tNhap tu ban muon thay the: ";
							cin.ignore();
							getline(cin, tu1);
							k->data.setTu(tu1);

							string loaitu1;
							cout << "\tNhap loai tu: ";
							getline(cin, loaitu1);
							k->data.setLoaiTu(loaitu1);

							string nghia1;
							cout << "\tNhap nghia: ";
							getline(cin, nghia1);
							k->data.setNghia(nghia1);

							string vidu1;
							cout << "\tNhap vi du: ";
							getline(cin, vidu1);
							k->data.setViDu(vidu1);
						}
						else
							break;
					}
				}
		}
		else if (luaChon == 4)
		{
		}
		else // luaChon == 0;
			break;
	}

	fw.close();
	ft.close();
	fm.close();
	fe.close();
	return 0;
}