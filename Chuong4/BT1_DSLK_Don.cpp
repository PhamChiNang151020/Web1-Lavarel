// Ho ten: Nguyen Bui Duy Tung
// Chuong 4 - BT1: Quan ly phan tu bang DSLK don (so nguyen duong)
// Them dau/cuoi, xuat, sap xep tang/giam (doi cho info).

#include <iostream>
using namespace std;

// Khai bao cau truc danh sach lien ket don
struct Node_1_Tung
{
	int info_1_Tung;
	Node_1_Tung* link_1_Tung;
};

Node_1_Tung* first_1_Tung;

void init_1_Tung()
{
	first_1_Tung = NULL;
}

void xuat_1_Tung()
{
	Node_1_Tung* p_1_Tung = first_1_Tung;
	if (p_1_Tung == NULL)
	{
		cout << "Danh sach rong!" << endl;
		return;
	}
	cout << "DS: ";
	while (p_1_Tung != NULL)
	{
		cout << p_1_Tung->info_1_Tung << "  ";
		p_1_Tung = p_1_Tung->link_1_Tung;
	}
	cout << endl;
}

// Them phan tu vao dau: nut moi tro toi first cu
void themDau_1_Tung(int x_1_Tung)
{
	Node_1_Tung* p_1_Tung = new Node_1_Tung;
	p_1_Tung->info_1_Tung = x_1_Tung;
	p_1_Tung->link_1_Tung = first_1_Tung;
	first_1_Tung = p_1_Tung;
}

// Them phan tu vao cuoi: duyet den nut cuoi roi noi
void themCuoi_1_Tung(int x_1_Tung)
{
	Node_1_Tung* p_1_Tung = new Node_1_Tung;
	p_1_Tung->info_1_Tung = x_1_Tung;
	p_1_Tung->link_1_Tung = NULL;
	if (first_1_Tung == NULL)
		first_1_Tung = p_1_Tung;
	else
	{
		Node_1_Tung* q_1_Tung = first_1_Tung;
		while (q_1_Tung->link_1_Tung != NULL)
			q_1_Tung = q_1_Tung->link_1_Tung;
		q_1_Tung->link_1_Tung = p_1_Tung;
	}
}

// Nhap so luong + day so
void nhapDS_1_Tung()
{
	int n_1_Tung, x_1_Tung;
	cout << "Nhap so luong phan tu: ";
	cin >> n_1_Tung;
	init_1_Tung();
	cout << "Nhap day so nguyen duong: ";
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
	{
		cin >> x_1_Tung;
		themCuoi_1_Tung(x_1_Tung);
	}
}

void hoanVi_1_Tung(int& a_1_Tung, int& b_1_Tung)
{
	int t_1_Tung = a_1_Tung;
	a_1_Tung = b_1_Tung;
	b_1_Tung = t_1_Tung;
}

// Sap xep tang dan (doi cho info)
void sapTang_1_Tung()
{
	for (Node_1_Tung* p_1_Tung = first_1_Tung; p_1_Tung != NULL; p_1_Tung = p_1_Tung->link_1_Tung)
	{
		for (Node_1_Tung* q_1_Tung = p_1_Tung->link_1_Tung; q_1_Tung != NULL; q_1_Tung = q_1_Tung->link_1_Tung)
		{
			if (p_1_Tung->info_1_Tung > q_1_Tung->info_1_Tung)
				hoanVi_1_Tung(p_1_Tung->info_1_Tung, q_1_Tung->info_1_Tung);
		}
	}
}

// Sap xep giam dan
void sapGiam_1_Tung()
{
	for (Node_1_Tung* p_1_Tung = first_1_Tung; p_1_Tung != NULL; p_1_Tung = p_1_Tung->link_1_Tung)
	{
		for (Node_1_Tung* q_1_Tung = p_1_Tung->link_1_Tung; q_1_Tung != NULL; q_1_Tung = q_1_Tung->link_1_Tung)
		{
			if (p_1_Tung->info_1_Tung < q_1_Tung->info_1_Tung)
				hoanVi_1_Tung(p_1_Tung->info_1_Tung, q_1_Tung->info_1_Tung);
		}
	}
}

void menu_1_Tung()
{
	cout << "======= BT1: DSLK DON =======" << endl;
	cout << "1. Nhap danh sach" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Them vao dau" << endl;
	cout << "4. Them vao cuoi" << endl;
	cout << "5. Sap xep tang dan" << endl;
	cout << "6. Sap xep giam dan" << endl;
	cout << "0. Thoat" << endl;
	cout << "Nhap lua chon: ";
}

int main()
{
	init_1_Tung();
	int chon_1_Tung, x_1_Tung;
	do
	{
		menu_1_Tung();
		cin >> chon_1_Tung;
		switch (chon_1_Tung)
		{
		case 1:
			nhapDS_1_Tung();
			xuat_1_Tung();
			break;
		case 2:
			xuat_1_Tung();
			break;
		case 3:
			cout << "Nhap x them dau: ";
			cin >> x_1_Tung;
			themDau_1_Tung(x_1_Tung);
			xuat_1_Tung();
			break;
		case 4:
			cout << "Nhap x them cuoi: ";
			cin >> x_1_Tung;
			themCuoi_1_Tung(x_1_Tung);
			xuat_1_Tung();
			break;
		case 5:
			sapTang_1_Tung();
			cout << "Sau khi sap tang:" << endl;
			xuat_1_Tung();
			break;
		case 6:
			sapGiam_1_Tung();
			cout << "Sau khi sap giam:" << endl;
			xuat_1_Tung();
			break;
		case 0:
			cout << "Thoat!" << endl;
			break;
		default:
			cout << "Sai lua chon!" << endl;
		}
	} while (chon_1_Tung != 0);
	return 0;
}
