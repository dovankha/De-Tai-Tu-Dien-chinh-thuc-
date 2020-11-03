#include <fstream>
#include <conio.h>
#include <stdio.h>
#include "T_M_E.h"

string search; // bien toan cuc

struct node
{
	T_M_E data;
	node *pNext;
};
typedef struct node NODE;

struct list
{
	NODE *pHead;
};
typedef struct list LIST;

void khoiTao(LIST &l)
{
	l.pHead = NULL;
}

bool isEmpty(LIST &l)
{
	if (l.pHead == NULL)
		return true;

	return false;
}

NODE *khoiTaoNODE(const T_M_E &x)
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

void themVaoDau(LIST &l, NODE *p);
void XoaDau(LIST &l);
void xuatDanhSach(LIST l);
void themVaoCuoi(LIST &l, NODE *p);
void XoaCuoi(LIST &l);
void XoaNodeCoKhoaBatKy(LIST &l, string tu);
void chinhSuTu(LIST &l);
void menu();

int main()
{
	SetConsoleTitle(TEXT("Tu Dien Anh-Viet"));
	menu();
	return 0;
}

void menu()
{
	LIST l;
	khoiTao(l);
	ifstream fw, ft, fm, fe, fiw, fit, fim, fie;
	string tu, loai, nghia, vd, TU, LOAI, NGHIA, VD;
	int count = 0;
	fw.open("word.txt", ios::in);
	ft.open("type.txt", ios::in);
	fm.open("mean.txt", ios::in);
	fe.open("example.txt", ios::in);
	fiw.open("word.txt", ios::in);
	fit.open("type.txt", ios::in);
	fim.open("mean.txt", ios::in);
	fie.open("example.txt", ios::in);

	while (!fiw.eof())
	{
		getline(fiw, TU);
		getline(fit, LOAI);
		getline(fim, NGHIA);
		getline(fie, VD);
	}
	while (!fw.eof())
	{
		count++;
		getline(fw, tu, ' ');
		getline(ft, loai, ' ');
		getline(fm, nghia, '@');
		getline(fe, vd, '@');
		T_M_E tuVung(count, tu, loai, nghia, vd);
		NODE *p = khoiTaoNODE(tuVung);
		themVaoCuoi(l, p);
	}

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
			 << "\t\t\t\t==================================" << endl << endl << endl;

		
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
			cout << "\n\t\tNhap tu can tim kiem: ";
			cin >> search;
			cout << "\t\t------------------------\n"
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
				SetConsoleTextAttribute(console, 12);
				cout << "\n\t\tERROR: Tu '" << search << "' chua co trong tu dien!" << endl
					 << "\t\tNhan phim bat ki de quay lai!" << endl;
				getch();
			}
		}
		else if (luaChon == 2)
		{
			system("cls");
			bool timKiem = false;
			cout << "\t\t\nNhap tu can THEM: ";
			cin >> search;
			for (NODE *k = l.pHead; k != NULL; k = k->pNext)
				if (search == k->data.getTu())
					timKiem = true;
			if (timKiem)
			{
				SetConsoleTextAttribute(console, 12);
				cout << "\n\t\tERROR: Tu '" << search << "' da ton tai trong tu dien!" << endl
					 << "\t\tNhan Enter de quay lai menu chuc nang" << endl;
				getch();
			}
			else
			{
				string saveLoai = " ", saveNghia = " ", saveViDu = " ";
				ofstream fw, ft, fm, fe;
				count++;
				SetConsoleTextAttribute(console, 14);
				cout << "\t\t\t\t===================================" << endl
					 << "\t\t\t\t||" << char(254) << " ESC   :  Quay lai MENU       ||" << endl
					 << "\t\t\t\t||" << char(254) << " Enter :  Tiep tuc them       ||" << endl
					 << "\t\t\t\t===================================" << endl
					 << endl;
				SetConsoleTextAttribute(console, 12);
				cout << "\t\t\t***NOTE: Hay ngan cach cac nghia & vi du boi dau ';' " << endl;
				SetConsoleTextAttribute(console, 7);
				while (true)
				{
					char key = getch();
					if (key == 27)
						break;
					string loai, nghia, vd;
					fflush(stdin);
					cout << "Nhap loai tu: ";
					getline(cin, loai);
					saveLoai = saveLoai + loai + ';';
					cout << "Nhap nghia cua tu: ";
					getline(cin, nghia);
					saveNghia = saveNghia + nghia + '/'; // save nghia
					cout << "Nhap vi du: ";
					getline(cin, vd);
					saveViDu = saveViDu + vd + '/'; // save vi du
					cout << endl;
				}
				loai = saveLoai.substr(0, saveLoai.length() - 1);
				nghia = saveNghia.substr(0, saveNghia.length() - 1);
				vd = saveViDu.substr(0, saveViDu.length() - 1);
				T_M_E tuVung(count, search, loai, nghia, vd);
				search = TU + ' ' + search;
				loai = LOAI + ' ' + loai;
				nghia = NGHIA + '@' + nghia;
				vd = VD + '@' + vd;
				NODE *p = khoiTaoNODE(tuVung);
				themVaoCuoi(l, p);
				ofstream fow("word.txt"), fot("type.txt"), fom("mean.txt"), foe("example.txt");
				fow << search;
				fot << loai;
				fom << nghia;
				foe << vd;
				fow.close();
				fot.close();
				fom.close();
				foe.close();
			}
		}
		else if (luaChon == 3)
		{
			system("cls");
			SetConsoleTextAttribute(console, 12);
			cout << "\n\n\t\tNhap tu can CHINH SUA: ";
			SetConsoleTextAttribute(console, 7);
			cin >> search;
			chinhSuTu(l); // menu chuc nang sua tu.
		}
		else if (luaChon == 4)
		{
			system("cls");
			bool timKiem = false;
			SetConsoleTextAttribute(console, 12);
			cout << "\t\t\nNhap tu can XOA: ";
			SetConsoleTextAttribute(console, 7);
			cin >> search;
			ofstream fow1("word.txt"), fot1("type.txt"), fom1("mean.txt"), foe1("example.txt");
			for (NODE *k = l.pHead; k != NULL; k = k->pNext)
				if (k->data.getTu() == search)
				{
					timKiem = true;
					XoaNodeCoKhoaBatKy(l, search);
					break;
				}

			if (timKiem == true)
			{
				for (NODE *k = l.pHead; k != NULL; k = k->pNext)
				{
					if (k->pNext == NULL)
					{
						fow1 << k->data.getTu();
						fot1 << k->data.getloaiTu();
						fom1 << k->data.getNghia();
						foe1 << k->data.getViDu();
					}
					else
					{
						fow1 << k->data.getTu() << ' ';
						fot1 << k->data.getloaiTu() << ' ';
						fom1 << k->data.getNghia() << '@';
						foe1 << k->data.getViDu() << '@';
					}
				}
			}
			fow1.close();
			fot1.close();
			fom1.close();
			foe1.close();

			if (!timKiem)
			{
				SetConsoleTextAttribute(console, 12);
				cout << "\t\t\nERROR: Tu '" << search << "' chua co trong tu dien!" << endl
					 << "\t\t\nNhan Enter de quay lai menu chuc nang" << endl;
				getch();
			}
		}
		else // luaChon == 0;
			break;
	}

	fw.close();
	ft.close();
	fm.close();
	fe.close();
	fiw.close();
	fit.close();
	fim.close();
	fie.close();
}

void chinhSuTu(LIST &l)
{
	bool timKiem = false;
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

				int luaChon1;
				cout << "\n\tNhap lua chon cua ban: ";
				cin >> luaChon1;
				if (luaChon1 < 0 || luaChon1 > 4)
				{
					SetConsoleTextAttribute(console, 12);
					cout << "\n\tLua chon cua ban khong dung! Vui long nhap lai!" << endl;
					getch();
				}
				else if (luaChon1 == 1)
				{
					string loaitu1;
					cout << "\tNhap LOAI TU: ";
					cin.ignore();
					getline(cin, loaitu1);
					k->data.setLoaiTu(loaitu1);
				}
				else if (luaChon1 == 2)
				{
					string nghia1;
					cout << "\tNhap NGHIA: ";
					cin.ignore();
					getline(cin, nghia1);
					k->data.setNghia(nghia1);
				}
				else if (luaChon1 == 3)
				{
					string viDu1;
					cout << "\tNhap VI DU: ";
					cin.ignore();
					getline(cin, viDu1);
					k->data.setViDu(viDu1);
				}
				else if (luaChon1 == 4)
				{
					string tu1;
					SetConsoleTextAttribute(console, 12);
					cout << "\t\tNhap tu ban muon THAY THE: ";
					SetConsoleTextAttribute(console, 7);
					cin.ignore();
					getline(cin, tu1);
					k->data.setTu(tu1);

					string loaitu1;
					cout << "\t\tNhap LOAI TU: ";
					getline(cin, loaitu1);
					k->data.setLoaiTu(loaitu1);

					string nghia1;
					cout << "\t\tNhap NGHIA: ";
					getline(cin, nghia1);
					k->data.setNghia(nghia1);

					string viDu1;
					cout << "\t\tNhap VI DU: ";
					getline(cin, viDu1);
					k->data.setViDu(viDu1);
				}
				else
					break;
			}
		}
}

void XoaNodeCoKhoaBatKy(LIST &l, string tu)
{

	if (l.pHead == NULL)
	{
		return;
	}

	if (l.pHead->data.getTu() == tu)
	{
		XoaDau(l);
		return;
	}

	if (findTail(l)->data.getTu() == tu)
	{
		XoaCuoi(l);
		return;
	}

	NODE *g = new NODE;
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.getTu() == tu)
		{
			g->pNext = k->pNext;
			delete k;
			return;
		}
		g = k;
	}
}

void XoaCuoi(LIST &l)
{
	if (l.pHead == NULL)
	{
		return;
	}
	if (l.pHead->pNext == NULL)
	{
		XoaDau(l);
		return;
	}

	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->pNext == findTail(l))
		{
			delete findTail(l);
			k->pNext = NULL;
			findTail(l)->data = k->data;
			return;
		}
	}
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

void XoaDau(LIST &l)
{
	if (l.pHead == NULL)
	{
		return;
	}
	NODE *p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
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