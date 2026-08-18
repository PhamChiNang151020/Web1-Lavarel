// Ho ten: Nguyen Bui Duy Tung
// B5 - Bai 3: Queue dung DSLK

#include <iostream>
using namespace std;

// 1. khai bao cau truc queue
struct Node_1_Tung
{
	int info_1_Tung;
	Node_1_Tung* link_1_Tung;
};

Node_1_Tung* front_1_Tung;
Node_1_Tung* rear_1_Tung;

// 2. Thu tuc khoi tao queue rong
void init_1_Tung()
{
	front_1_Tung = NULL;
	rear_1_Tung = NULL;
}

// 3. viet thu tuc ktra queue rong
int isEmpty_1_Tung()
{
	if (front_1_Tung == NULL)
		return 1;
	return 0;
}

// 4. Viet thu tuc them 1 ptu vao queue
void Push_1_Tung(int x_1_Tung)
{
	Node_1_Tung* p_1_Tung = new Node_1_Tung;
	p_1_Tung->info_1_Tung = x_1_Tung;
	p_1_Tung->link_1_Tung = NULL;
	if (rear_1_Tung == NULL)
	{
		front_1_Tung = p_1_Tung;
		rear_1_Tung = p_1_Tung;
	}
	else
	{
		rear_1_Tung->link_1_Tung = p_1_Tung;
		rear_1_Tung = p_1_Tung;
	}
}

// 5. Viet thu tuc xoa 1 ptu trong queue
int Pop_1_Tung(int& x_1_Tung)
{
	if (front_1_Tung != NULL)
	{
		Node_1_Tung* p_1_Tung = front_1_Tung;
		x_1_Tung = p_1_Tung->info_1_Tung;
		front_1_Tung = front_1_Tung->link_1_Tung;
		if (front_1_Tung == NULL)
			rear_1_Tung = NULL;
		delete p_1_Tung;
		return 1;
	}
	return 0;
}

// 6. Xoa het all hang doi khi ket thuc
void xoaHet_1_Tung()
{
	int x_1_Tung;
	while (Pop_1_Tung(x_1_Tung) == 1)
		;
}

void xuat_1_Tung()
{
	if (front_1_Tung == NULL)
	{
		cout << "Hang doi rong!" << endl;
		return;
	}
	cout << "Cac ptu trong hang doi: ";
	Node_1_Tung* p_1_Tung = front_1_Tung;
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
		cout << "Menu hang doi" << endl;
		cout << "1. Khoi tao hang doi" << endl;
		cout << "2. Them 1 ptu vao hang doi" << endl;
		cout << "3. Lay 1 Ptu ra khoi hang doi" << endl;
		cout << "4. Xoa toan bo hang doi" << endl;
		cout << "5. Ktra hang doi rong" << endl;
		cout << "6. Xuat cac ptu trong hang doi" << endl;
		cout << "7. Thoat" << endl;
		cout << "Nhap vao chon lua cua ban(1-6): ";
		cin >> chon_1_Tung;
		switch (chon_1_Tung)
		{
		case 1:
			xoaHet_1_Tung();
			init_1_Tung();
			cout << "Da khoi tao hang doi rong!" << endl;
			break;
		case 2:
			cout << "Nhap gia tri can them: ";
			cin >> x_1_Tung;
			Push_1_Tung(x_1_Tung);
			cout << "them thanh cong" << endl;
			break;
		case 3:
			if (Pop_1_Tung(x_1_Tung) == 1)
				cout << "Gia tri vua lay la:" << x_1_Tung << endl;
			else
				cout << "Hang doi rong!" << endl;
			break;
		case 4:
			xoaHet_1_Tung();
			cout << "Da xoa toan bo hang doi!" << endl;
			break;
		case 5:
			if (isEmpty_1_Tung() == 1)
				cout << "Hang doi rong" << endl;
			else
				cout << "Hang doi khong rong" << endl;
			break;
		case 6:
			xuat_1_Tung();
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
