// Ho ten: Nguyen Bui Duy Tung
// Chuong 3 - BT3: Quan ly Stack (so nguyen) - cai dat bang DSLK
//
// Stack LIFO bang DSLK don: top tro toi nut dinh.
// Push = them dau, Pop = xoa dau. Khong can kiem tra day.

#include <iostream>
using namespace std;

// 1. Khai bao cau truc Stack (DSLK don)
struct Node_1_Tung
{
	int info_1_Tung;
	Node_1_Tung* link_1_Tung; // tro xuong nut phia duoi trong stack
};

Node_1_Tung* top_1_Tung; // nut dinh (NULL = rong)

// 2. Khoi tao Stack rong
void init_1_Tung()
{
	top_1_Tung = NULL;
}

// 3. Kiem tra Stack rong
int isEmpty_1_Tung()
{
	if (top_1_Tung == NULL)
		return 1;
	return 0;
}

// 5. Them 1 ptu vao Stack (Push) - chen vao dau danh sach
void Push_1_Tung(int x_1_Tung)
{
	Node_1_Tung* p_1_Tung = new Node_1_Tung;
	p_1_Tung->info_1_Tung = x_1_Tung;
	p_1_Tung->link_1_Tung = top_1_Tung; // nut moi tro toi dinh cu
	top_1_Tung = p_1_Tung;              // top nhay len nut moi
}

// 6. Lay 1 ptu ra khoi Stack (Pop) - xoa nut dinh
int Pop_1_Tung(int& x_1_Tung)
{
	if (top_1_Tung == NULL)
		return 0;
	Node_1_Tung* p_1_Tung = top_1_Tung;
	x_1_Tung = p_1_Tung->info_1_Tung;
	top_1_Tung = top_1_Tung->link_1_Tung; // dinh moi la nut phia duoi
	delete p_1_Tung;
	return 1;
}

// Giai phong toan bo nut
void xoaHet_1_Tung()
{
	int x_1_Tung;
	while (Pop_1_Tung(x_1_Tung) == 1)
		;
}

// 7. Duyet Stack: di tu top theo link xuong day
void xuat_1_Tung()
{
	if (top_1_Tung == NULL)
	{
		cout << "Stack rong!" << endl;
		return;
	}
	cout << "Cac ptu trong Stack (dinh -> day): ";
	Node_1_Tung* p_1_Tung = top_1_Tung;
	while (p_1_Tung != NULL)
	{
		cout << p_1_Tung->info_1_Tung << "  ";
		p_1_Tung = p_1_Tung->link_1_Tung;
	}
	cout << endl;
}

int main()
{
	int chon_1_Tung;
	int x_1_Tung;
	init_1_Tung();
	do
	{
		cout << "Menu Stack (DSLK)" << endl;
		cout << "1. Khoi tao Stack" << endl;
		cout << "2. Them 1 ptu vao Stack (Push)" << endl;
		cout << "3. Lay 1 ptu ra khoi Stack (Pop)" << endl;
		cout << "4. Kiem tra Stack rong" << endl;
		cout << "5. Xuat cac ptu trong Stack" << endl;
		cout << "6. Xoa toan bo Stack" << endl;
		cout << "7. Thoat" << endl;
		cout << "Nhap vao chon lua cua ban(1-7): ";
		cin >> chon_1_Tung;
		switch (chon_1_Tung)
		{
		case 1:
			xoaHet_1_Tung();
			init_1_Tung();
			cout << "Da khoi tao Stack rong!" << endl;
			break;
		case 2:
			cout << "Nhap gia tri can them vao Stack: ";
			cin >> x_1_Tung;
			Push_1_Tung(x_1_Tung);
			cout << "them thanh cong" << endl;
			break;
		case 3:
			if (Pop_1_Tung(x_1_Tung) == 1)
				cout << "Gia tri vua lay la:" << x_1_Tung << endl;
			else
				cout << "Stack rong, khong lay duoc!" << endl;
			break;
		case 4:
			if (isEmpty_1_Tung() == 1)
				cout << "Stack rong" << endl;
			else
				cout << "Stack khong rong" << endl;
			break;
		case 5:
			xuat_1_Tung();
			break;
		case 6:
			xoaHet_1_Tung();
			cout << "Da xoa toan bo Stack!" << endl;
			break;
		case 7:
			xoaHet_1_Tung();
			cout << "Thoat!" << endl;
			break;
		default:
			cout << "Sai lua chon!" << endl;
		}
	} while (chon_1_Tung != 7);
	return 0;
}
