// Ho ten: Tung
// B5 - Bai 1: Queue mang - phuong phap TINH TIEN
// Bien khai bao theo dang x_1_Tung

#include <iostream>
using namespace std;

#define MAX_1_Tung 100

int a_1_Tung[MAX_1_Tung];
int front_1_Tung;
int rear_1_Tung;

// 1. Khai bao cau truc queue: mang a, front, rear

// 2. Khoi tao queue rong
void init_1_Tung(int a_1_Tung[], int& front_1_Tung, int& rear_1_Tung)
{
	front_1_Tung = -1; // ngoai kha nang luu tru cua mang
	rear_1_Tung = -1;
}

// 3. Kiem tra queue rong
int isEmpty_1_Tung(int front_1_Tung)
{
	if (front_1_Tung == -1)
		return 1;
	return 0;
}

// 4. Kiem tra queue day
int isFull_1_Tung(int front_1_Tung, int rear_1_Tung)
{
	if (rear_1_Tung - front_1_Tung == MAX_1_Tung - 1)
		return 1;
	return 0;
}

// 5. Them 1 ptu vao queue (tinh tien neu can)
int Push_1_Tung(int a_1_Tung[], int& front_1_Tung, int& rear_1_Tung, int x_1_Tung)
{
	if (rear_1_Tung - front_1_Tung == MAX_1_Tung - 1) // day that
		return 0;
	else
	{
		if (front_1_Tung == -1) // hang doi rong
			front_1_Tung = 0;
		if (rear_1_Tung == MAX_1_Tung - 1) // bi tran gia -> tinh tien
		{
			for (int i_1_Tung = front_1_Tung; i_1_Tung <= rear_1_Tung; i_1_Tung++)
				a_1_Tung[i_1_Tung - front_1_Tung] = a_1_Tung[i_1_Tung];
			rear_1_Tung = MAX_1_Tung - 1 - front_1_Tung;
			front_1_Tung = 0;
		}
		a_1_Tung[++rear_1_Tung] = x_1_Tung;
		return 1;
	}
}

// 6. Xoa 1 ptu trong queue
int Pop_1_Tung(int a_1_Tung[], int& front_1_Tung, int& rear_1_Tung, int& x_1_Tung)
{
	if (front_1_Tung == -1) // hang doi rong
		return 0; // ko lay ra dc ptu
	else
	{
		x_1_Tung = a_1_Tung[front_1_Tung++]; // front co len tren
		if (front_1_Tung > rear_1_Tung)
		{
			// truong hop hang doi co 1 ptu, sau khi xoa thi rong
			front_1_Tung = -1;
			rear_1_Tung = -1;
		}
		return 1; // Lay thanh cong
	}
}

void xuat_1_Tung(int a_1_Tung[], int front_1_Tung, int rear_1_Tung)
{
	if (front_1_Tung == -1)
	{
		cout << "Hang doi rong!" << endl;
		return;
	}
	cout << "Hang doi: ";
	for (int i_1_Tung = front_1_Tung; i_1_Tung <= rear_1_Tung; i_1_Tung++)
		cout << a_1_Tung[i_1_Tung] << "  ";
	cout << endl;
}

int main()
{
	int chon_1_Tung;
	int x_1_Tung;
	init_1_Tung(a_1_Tung, front_1_Tung, rear_1_Tung);
	do
	{
		cout << "Menu hang doi" << endl;
		cout << "1. Khoi tao hang doi" << endl;
		cout << "2. Them 1 ptu vao hang doi" << endl;
		cout << "3. Lay 1 Ptu ra khoi hang doi" << endl;
		cout << "4. Thoat" << endl;
		cout << "Nhap vao chon lua cua ban(1-4): ";
		cin >> chon_1_Tung;
		switch (chon_1_Tung)
		{
		case 1:
			init_1_Tung(a_1_Tung, front_1_Tung, rear_1_Tung);
			cout << "Da khoi tao hang doi rong!" << endl;
			break;
		case 2:
			cout << "Nhap gia tri can them vao hang doi: ";
			cin >> x_1_Tung;
			if (Push_1_Tung(a_1_Tung, front_1_Tung, rear_1_Tung, x_1_Tung) == 1)
			{
				cout << "them thanh cong" << endl;
				xuat_1_Tung(a_1_Tung, front_1_Tung, rear_1_Tung);
			}
			else
				cout << "Hang doi day, khong them duoc!" << endl;
			break;
		case 3:
			if (Pop_1_Tung(a_1_Tung, front_1_Tung, rear_1_Tung, x_1_Tung) == 1)
			{
				cout << "Gia tri vua lay la:" << x_1_Tung << endl;
				xuat_1_Tung(a_1_Tung, front_1_Tung, rear_1_Tung);
			}
			else
				cout << "Hang doi rong, khong lay duoc!" << endl;
			break;
		case 4:
			cout << "Thoat!" << endl;
			break;
		default:
			cout << "Sai lua chon!" << endl;
		}
	} while (chon_1_Tung != 4);
	return 0;
}
