// Ho ten: Nguyen Bui Duy Tung
// Chuong 3 - BT3: Quan ly Stack (so nguyen) - cai dat bang mang
//
// Stack (LIFO): them/lay deu o dinh (top).
// Mang a[0..MAX-1], top = chi so ptu dinh. top = -1 => rong.

#include <iostream>
using namespace std;

#define MAX_1_Tung 100

// 1. Khai bao cau truc Stack
int a_1_Tung[MAX_1_Tung];
int top_1_Tung; // -1: rong; 0..MAX-1: chi so dinh

// 2. Khoi tao Stack rong
void init_1_Tung()
{
	top_1_Tung = -1;
}

// 3. Kiem tra Stack rong
int isEmpty_1_Tung()
{
	if (top_1_Tung == -1)
		return 1;
	return 0;
}

// 4. Kiem tra Stack day (cai dat bang mang)
int isFull_1_Tung()
{
	if (top_1_Tung == MAX_1_Tung - 1)
		return 1;
	return 0;
}

// 5. Them 1 ptu vao Stack (Push) - tang top roi gan
int Push_1_Tung(int x_1_Tung)
{
	if (isFull_1_Tung() == 1)
		return 0;
	a_1_Tung[++top_1_Tung] = x_1_Tung;
	return 1;
}

// 6. Lay 1 ptu ra khoi Stack (Pop) - lay a[top] roi giam top
int Pop_1_Tung(int& x_1_Tung)
{
	if (isEmpty_1_Tung() == 1)
		return 0;
	x_1_Tung = a_1_Tung[top_1_Tung--];
	return 1;
}

// 7. Duyet Stack (hien thi tu dinh xuong day)
void xuat_1_Tung()
{
	if (isEmpty_1_Tung() == 1)
	{
		cout << "Stack rong!" << endl;
		return;
	}
	cout << "Cac ptu trong Stack (dinh -> day): ";
	for (int i_1_Tung = top_1_Tung; i_1_Tung >= 0; i_1_Tung--)
		cout << a_1_Tung[i_1_Tung] << "  ";
	cout << endl;
}

int main()
{
	int chon_1_Tung;
	int x_1_Tung;
	init_1_Tung();
	do
	{
		cout << "Menu Stack (mang)" << endl;
		cout << "1. Khoi tao Stack" << endl;
		cout << "2. Them 1 ptu vao Stack (Push)" << endl;
		cout << "3. Lay 1 ptu ra khoi Stack (Pop)" << endl;
		cout << "4. Kiem tra Stack rong" << endl;
		cout << "5. Kiem tra Stack day" << endl;
		cout << "6. Xuat cac ptu trong Stack" << endl;
		cout << "7. Thoat" << endl;
		cout << "Nhap vao chon lua cua ban(1-7): ";
		cin >> chon_1_Tung;
		switch (chon_1_Tung)
		{
		case 1:
			init_1_Tung();
			cout << "Da khoi tao Stack rong!" << endl;
			break;
		case 2:
			cout << "Nhap gia tri can them vao Stack: ";
			cin >> x_1_Tung;
			if (Push_1_Tung(x_1_Tung) == 1)
				cout << "them thanh cong" << endl;
			else
				cout << "Stack day, khong them duoc!" << endl;
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
			if (isFull_1_Tung() == 1)
				cout << "Stack day" << endl;
			else
				cout << "Stack chua day" << endl;
			break;
		case 6:
			xuat_1_Tung();
			break;
		case 7:
			cout << "Thoat!" << endl;
			break;
		default:
			cout << "Sai lua chon!" << endl;
		}
	} while (chon_1_Tung != 7);
	return 0;
}
