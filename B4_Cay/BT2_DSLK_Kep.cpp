// Ho ten: Tung
// BT2: Quan ly phan tu bang DSLK kep (so nguyen duong)
// Bien khai bao theo dang x_1_Tung

#include <iostream>
using namespace std;

struct Node_1_Tung
{
	int info_1_Tung;
	Node_1_Tung* next_1_Tung;
	Node_1_Tung* prev_1_Tung;
};

Node_1_Tung* first_1_Tung;
Node_1_Tung* last_1_Tung;

void init_1_Tung()
{
	first_1_Tung = NULL;
	last_1_Tung = NULL;
}

void xuat_1_Tung(Node_1_Tung* f_1_Tung)
{
	if (f_1_Tung == NULL)
	{
		cout << "Danh sach rong!" << endl;
		return;
	}
	cout << "DS: ";
	Node_1_Tung* p_1_Tung = f_1_Tung;
	while (p_1_Tung != NULL)
	{
		cout << p_1_Tung->info_1_Tung << "  ";
		p_1_Tung = p_1_Tung->next_1_Tung;
	}
	cout << endl;
}

void themCuoi_1_Tung(Node_1_Tung*& f_1_Tung, Node_1_Tung*& l_1_Tung, int x_1_Tung)
{
	Node_1_Tung* p_1_Tung = new Node_1_Tung;
	p_1_Tung->info_1_Tung = x_1_Tung;
	p_1_Tung->next_1_Tung = NULL;
	p_1_Tung->prev_1_Tung = l_1_Tung;
	if (f_1_Tung == NULL)
	{
		f_1_Tung = p_1_Tung;
		l_1_Tung = p_1_Tung;
	}
	else
	{
		l_1_Tung->next_1_Tung = p_1_Tung;
		l_1_Tung = p_1_Tung;
	}
}

int dem_1_Tung(Node_1_Tung* f_1_Tung)
{
	int d_1_Tung = 0;
	Node_1_Tung* p_1_Tung = f_1_Tung;
	while (p_1_Tung != NULL)
	{
		d_1_Tung++;
		p_1_Tung = p_1_Tung->next_1_Tung;
	}
	return d_1_Tung;
}

// Ket hop 2 DSLK kep thanh 1 (noi list2 vao sau list1)
void noiDS_1_Tung(Node_1_Tung*& f1_1_Tung, Node_1_Tung*& l1_1_Tung,
	Node_1_Tung*& f2_1_Tung, Node_1_Tung*& l2_1_Tung)
{
	if (f2_1_Tung == NULL)
		return;
	if (f1_1_Tung == NULL)
	{
		f1_1_Tung = f2_1_Tung;
		l1_1_Tung = l2_1_Tung;
	}
	else
	{
		l1_1_Tung->next_1_Tung = f2_1_Tung;
		f2_1_Tung->prev_1_Tung = l1_1_Tung;
		l1_1_Tung = l2_1_Tung;
	}
	f2_1_Tung = NULL;
	l2_1_Tung = NULL;
}

void xoaHet_1_Tung(Node_1_Tung*& f_1_Tung, Node_1_Tung*& l_1_Tung)
{
	Node_1_Tung* p_1_Tung;
	while (f_1_Tung != NULL)
	{
		p_1_Tung = f_1_Tung;
		f_1_Tung = f_1_Tung->next_1_Tung;
		delete p_1_Tung;
	}
	l_1_Tung = NULL;
}

void nhapDS_1_Tung()
{
	int n_1_Tung, x_1_Tung;
	cout << "Nhap so luong phan tu: ";
	cin >> n_1_Tung;
	xoaHet_1_Tung(first_1_Tung, last_1_Tung);
	init_1_Tung();
	cout << "Nhap day so (vd: 20 22 15 16 18 29): ";
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
	{
		cin >> x_1_Tung;
		themCuoi_1_Tung(first_1_Tung, last_1_Tung, x_1_Tung);
	}
}

void menu_1_Tung()
{
	cout << "======= BT2: DSLK KEP =======" << endl;
	cout << "1. Nhap danh sach 1" << endl;
	cout << "2. Xuat danh sach 1" << endl;
	cout << "3. Them vao cuoi ds 1" << endl;
	cout << "4. Dem so phan tu ds 1" << endl;
	cout << "5. Nhap danh sach 2 roi noi vao ds 1" << endl;
	cout << "6. Xoa toan bo ds 1" << endl;
	cout << "0. Thoat" << endl;
	cout << "Nhap lua chon: ";
}

int main()
{
	init_1_Tung();
	Node_1_Tung* first2_1_Tung = NULL;
	Node_1_Tung* last2_1_Tung = NULL;
	int chon_1_Tung, x_1_Tung, n_1_Tung;
	do
	{
		menu_1_Tung();
		cin >> chon_1_Tung;
		switch (chon_1_Tung)
		{
		case 1:
			nhapDS_1_Tung();
			xuat_1_Tung(first_1_Tung);
			break;
		case 2:
			xuat_1_Tung(first_1_Tung);
			break;
		case 3:
			cout << "Nhap x them cuoi: ";
			cin >> x_1_Tung;
			themCuoi_1_Tung(first_1_Tung, last_1_Tung, x_1_Tung);
			xuat_1_Tung(first_1_Tung);
			break;
		case 4:
			cout << "So phan tu: " << dem_1_Tung(first_1_Tung) << endl;
			break;
		case 5:
			cout << "Nhap so luong ds 2: ";
			cin >> n_1_Tung;
			xoaHet_1_Tung(first2_1_Tung, last2_1_Tung);
			cout << "Nhap day so ds 2: ";
			for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
			{
				cin >> x_1_Tung;
				themCuoi_1_Tung(first2_1_Tung, last2_1_Tung, x_1_Tung);
			}
			cout << "DS 2: ";
			xuat_1_Tung(first2_1_Tung);
			noiDS_1_Tung(first_1_Tung, last_1_Tung, first2_1_Tung, last2_1_Tung);
			cout << "Sau khi noi:" << endl;
			xuat_1_Tung(first_1_Tung);
			break;
		case 6:
			xoaHet_1_Tung(first_1_Tung, last_1_Tung);
			cout << "Da xoa toan bo danh sach!" << endl;
			break;
		case 0:
			xoaHet_1_Tung(first_1_Tung, last_1_Tung);
			xoaHet_1_Tung(first2_1_Tung, last2_1_Tung);
			cout << "Thoat!" << endl;
			break;
		default:
			cout << "Sai lua chon!" << endl;
		}
	} while (chon_1_Tung != 0);
	return 0;
}
