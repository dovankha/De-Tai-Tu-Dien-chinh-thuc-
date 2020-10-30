#include <iostream> 
using namespace std;
#include <fstream> 
#include<string>
#include<conio.h>
#include<stdio.h>
#include<Windows.h> 
#include <iomanip>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
class dictionary
{
	int Id;
	string Tu;
public:
	dictionary();
	dictionary(int id, string tu);
	int getId();
	string getTu() { return Tu; }
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
		cout<<setw(5)<<left<<Tu<<"\t";
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


class T_M_E :public dictionary
{
	string loaiTu;
	string Nghia;
	string viDu;
public:
	T_M_E() {
		loaiTu = "";
		Nghia = "";
		viDu = "";
	}
	T_M_E(string, string, string);
	T_M_E(int, string, string, string, string);
	void xuatfullTu() {
		SetConsoleTextAttribute(console, 116);
		cout << setw(5)<<left<<"Word"<<"\t"<<setw(20) << left << "Type" << "\t" <<setw(40) << left << "Mean" <<"\t"<<setw(40) << left << "Example" <<"\t"<<endl;
		SetConsoleTextAttribute(console, 7);
		this->printTu();
		cout <<setw(20) << left << loaiTu <<"\t";
		cout <<setw(40) << left << Nghia <<"\t";
		cout <<setw(40) << left << viDu <<"\t";
	}
	void setfullTu(T_M_E p) {
		loaiTu = p.loaiTu;
		Nghia = p.Nghia;
		viDu = p.viDu;
		this->setId(p.getId());
		this->setTu(p.getTu());
	}
};

T_M_E::T_M_E(int id, string tu, string Ty, string Me, string Ex) :dictionary(id, tu)
{
	this->loaiTu = Ty;
	this->Nghia = Me;
	this->viDu = Ex;
}

struct node
{
	T_M_E data;
	node* pNext;
};
typedef struct node NODE; //thay the struct node thành NODE
struct list
{
	NODE* pHead;
};
typedef struct list LIST;

void KhoiTao(LIST& l)
{
	l.pHead = NULL;
}

bool isEmpty(LIST& l) {
	if (l.pHead == NULL) return true;

	return false;
}
NODE* KhoiTaoNODE(const T_M_E& x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "Khong du bo nho cap phat !";
		return NULL; 
	}

	p->data.setfullTu(x);
	p->pNext = NULL;
	return p;
}

void themVaoDau(LIST& l, NODE* p)
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

NODE* findTail(LIST& l) {
	if (isEmpty(l)) return NULL;
	NODE* p = l.pHead;
	while (p->pNext != NULL) {
		p = p->pNext;
	}

	return p;
}

void themVaoCuoi(LIST& l, NODE* p)
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
	if (l.pHead == NULL) return;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext) {
		k->data.xuatfullTu();
		cout << endl;
	}
}
int main()
{
	SetConsoleTitle(TEXT("Tu Dien Anh-Viet"));
	LIST l; KhoiTao(l);
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
		NODE* p = KhoiTaoNODE(tuVung);
		themVaoCuoi(l, p);
	}
	/*cout << "Danh sach lien ket don co:" << endl;
	xuatDanhSach(l);*/
	int luaChon; 
	while (true) 
	{
		system("cls"); 
		cout<<"Tu Dien Anh - Viet"<<endl<<"Cac chuc nang: "<<endl
			<<"1. Tim kiem."<<endl
			<<"2. Them tu."<<endl
			<<"3. Chinh sua tu."<<endl
			<<"4. Xoa tu."<<endl
			<<"5. Thoat khoi tu dien."<<endl;
		cout<<"Nhap lua chon: "; 
		cin>>luaChon; 
		if (luaChon==1) 
		{
			system("cls");
			bool timKiem=false; 
			string search;
			cout << "Nhap tu can tim kiem: ";
			cin >> search;
			for (NODE* k = l.pHead; k != NULL; k = k->pNext) 
				if (search == k->data.getTu())
				{
					timKiem=true; 
					k->data.xuatfullTu();
					cout<<endl;
					getch();
				}
			if (!timKiem) 
			{
				cout<<"Tu '"<<search<<"' chua co trong tu dien!"<<endl
					<<"Nhan Enter de quay lai menu chuc nang" << endl;
				getch();
			}
		}
		else if (luaChon == 2)
		{
			system("cls");
			bool timKiem=false; 
			string search;
			cout << "Nhap tu can them: ";
			cin >> search;
			for (NODE* k = l.pHead; k != NULL; k = k->pNext) 
				if (search == k->data.getTu())
					timKiem=true; 
			if (timKiem) 
			{
				cout<<"Tu '"<<search<<"' da ton tai trong tu dien!"<<endl
					<<"Nhan Enter de quay lai menu chuc nang" << endl;
				getch();
			} else 
				{
					string Sloai=" ", Snghia=" ", Svd=" ";
					ofstream fw, ft, fm, fe;
					count++;
					cout<<"An phim ESC de quay lai menu."<<endl
						<<"An phim Enter de tiep tuc."<<endl
						<<"NOTE: Neu tu co nhieu nghia va vi du thi ngan cach nhau boi dau ';'."<<endl;
					while (true)
					{ 
						char key=getch();
						if (key==27)
							break; 
						string loai, nghia, vd;
						fflush(stdin);
						cout<<"Nhap loai tu: "; getline(cin, loai);
						Sloai=Sloai+loai+';'; 
						cout<<"Nhap nghia cua tu: "; getline(cin, nghia);
						Snghia=Snghia+nghia+'/'; 
						cout<<"Nhap vi du: "; getline(cin, vd);	
						Svd=Svd+vd+'/';
						cout<<endl;         
					}
					loai=Sloai.substr (0,Sloai.length()-1);
					nghia=Snghia.substr (0,Snghia.length()-1);
					vd=Svd.substr (0,Svd.length()-1);
					T_M_E tuVung(count, search, loai, nghia, vd);
					search=TU+' '+search;
					loai=LOAI+' '+loai;
					nghia=NGHIA+'@'+nghia;
					vd=VD+'@'+vd; 
					NODE* p = KhoiTaoNODE(tuVung);
					themVaoCuoi(l, p);
					ofstream fow ("word.txt"), fot ("type.txt"), fom ("mean.txt"), foe ("example.txt");
					fow<<search; fot<<loai; fom<<nghia; foe<<vd;
					fow.close(); fot.close(); fom.close(); foe.close();
				}
		}
		else if (luaChon == 5)
			break;
	}
	fw.close(); ft.close(); fm.close(); fe.close();
	fiw.close(); fit.close(); fim.close(); fie.close();
	return 0;
}

