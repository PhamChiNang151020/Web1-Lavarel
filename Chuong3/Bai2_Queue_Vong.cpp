// Ho ten: Nguyen Bui Duy Tung
// Chuong 3 - Bai 2: Queue mang - phuong phap VONG
//
// Queue vong: khi rear (hoac front) den cuoi mang thi quay ve 0.
// Khong can don phan tu nhu tinh tien, them/xoa van O(1).
// Day khi: (rear - front == MAX-1) hoac (rear - front == -1) (theo slide).

#include <iostream>
using namespace std;

#define MAX_1_Tung 100

int a_1_Tung[MAX_1_Tung];
int front_1_Tung;
int rear_1_Tung;

// Khoi tao hang doi rong
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

// Day: hang lap day ca mang, ke ca khi da quay vong
int isFull_1_Tung(int front_1_Tung, int rear_1_Tung)
{
	if ((rear_1_Tung - front_1_Tung == MAX_1_Tung - 1) || (rear_1_Tung - front_1_Tung == -1))
		return 1;
	return 0;
}

// Them: neu rear o cuoi mang thi gan rear = -1, ++rear se ra 0 (quay vong)
int Push_1_Tung(int a_1_Tung[], int& front_1_Tung, int& rear_1_Tung, int x_1_Tung)
{
	if ((rear_1_Tung - front_1_Tung == MAX_1_Tung - 1) || (rear_1_Tung - front_1_Tung == -1))
		return 0; // hang doi bi day, them khong thanh cong
	else
	{
		if (front_1_Tung == -1) // hang doi rong
			front_1_Tung = 0; // nhan gia tri moi vo
		if (rear_1_Tung == MAX_1_Tung - 1) // hang doi bi tran, nhung ko day
			rear_1_Tung = -1; // quay ve -1 de tang len 1 se nam dau hang doi
		a_1_Tung[++rear_1_Tung] = x_1_Tung; // tang rear 1 don vi gan x vao
		return 1; // them thanh cong
	}
}

// Lay 1 ptu: front++ , neu vuot MAX thi front = 0
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
			front_1_Tung++; // sau khi co cum len 1 don vi
			if (front_1_Tung == MAX_1_Tung)
				front_1_Tung = 0; // quay vong ve dau mang
		}
		return 1; // Lay thanh cong
	}
	return 0; // ko thanh cong
}

// Xuat theo chieu vong tu front den rear
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
			i_1_Tung = 0; // quay vong
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
