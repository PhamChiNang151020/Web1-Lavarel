// Ho ten: Nguyen Bui Duy Tung
// B5 - Bai 2: Queue mang - phuong phap VONG

#include <iostream>
using namespace std;

#define MAX_1_Tung 100

int a_1_Tung[MAX_1_Tung];
int front_1_Tung;
int rear_1_Tung;

void init_1_Tung(int a_1_Tung[], int& front_1_Tung, int& rear_1_Tung)
{
	front_1_Tung = -1; // ngoai kha nang luu tru cua mang
	rear_1_Tung = -1;
}

int isEmpty_1_Tung(int front_1_Tung)
{
	if (front_1_Tung == -1)
		return 1;
	return 0;
}

int isFull_1_Tung(int front_1_Tung, int rear_1_Tung)
{
	if ((rear_1_Tung - front_1_Tung == MAX_1_Tung - 1) || (rear_1_Tung - front_1_Tung == -1))
		return 1;
	return 0;
}

int Push_1_Tung(int a_1_Tung[], int& front_1_Tung, int& rear_1_Tung, int x_1_Tung)
{
	if ((rear_1_Tung - front_1_Tung == MAX_1_Tung - 1) || (rear_1_Tung - front_1_Tung == -1))
		return 0;
	else
	{
		if (front_1_Tung == -1)
			front_1_Tung = 0;
		if (rear_1_Tung == MAX_1_Tung - 1)
			rear_1_Tung = -1;
		a_1_Tung[++rear_1_Tung] = x_1_Tung;
		return 1;
	}
}

int Pop_1_Tung(int a_1_Tung[], int& front_1_Tung, int& rear_1_Tung, int& x_1_Tung)
{
	if (front_1_Tung != -1)
	{
		x_1_Tung = a_1_Tung[front_1_Tung];
		if (front_1_Tung == rear_1_Tung) // con 1 ptu
		{
			front_1_Tung = -1;
			rear_1_Tung = -1;
		}
		else
		{
			front_1_Tung++;
			if (front_1_Tung == MAX_1_Tung)
				front_1_Tung = 0;
		}
		return 1;
	}
	return 0;
}

void xuat_1_Tung(int a_1_Tung[], int front_1_Tung, int rear_1_Tung)
{
	if (front_1_Tung == -1)
	{
		cout << "Hang doi rong!" << endl;
		return;
	}
	cout << "Hang doi: ";
	int i_1_Tung = front_1_Tung;
	while (true)
	{
		cout << a_1_Tung[i_1_Tung] << "  ";
		if (i_1_Tung == rear_1_Tung)
			break;
		i_1_Tung++;
		if (i_1_Tung == MAX_1_Tung)
			i_1_Tung = 0;
	}
	cout << endl;
}

int main()
{
	int chon_1_Tung;
	int x_1_Tung;
	init_1_Tung(a_1_Tung, front_1_Tung, rear_1_Tung);
	do
	{
		cout << "Menu hang doi (VONG)" << endl;
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
			cout << "nhap gia tri can them vao hang doi:";
			cin >> x_1_Tung;
			if (Push_1_Tung(a_1_Tung, front_1_Tung, rear_1_Tung, x_1_Tung) == 1)
			{
				cout << "them thanh cong" << endl;
				xuat_1_Tung(a_1_Tung, front_1_Tung, rear_1_Tung);
			}
			else
				cout << "Hang doi day!" << endl;
			break;
		case 3:
			if (Pop_1_Tung(a_1_Tung, front_1_Tung, rear_1_Tung, x_1_Tung) == 1)
			{
				cout << "Gia tri vua lay la:" << x_1_Tung << endl;
				xuat_1_Tung(a_1_Tung, front_1_Tung, rear_1_Tung);
			}
			else
				cout << "Hang doi rong!" << endl;
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
