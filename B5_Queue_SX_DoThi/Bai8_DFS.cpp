// Ho ten: Tung
// B5 - Bai 8: DFS (ma tran ke + Queue/Stack danh sach dac)
// Bien khai bao theo dang x_1_Tung

#include <iostream>
using namespace std;

#define MAX_1_Tung 20

int A_1_Tung[MAX_1_Tung][MAX_1_Tung];
int n_1_Tung;
int chuaxet_1_Tung[MAX_1_Tung];

void init_1_Tung()
{
	n_1_Tung = 0;
}

void input_1_Tung()
{
	cout << "nhap so dinh do thi n: ";
	cin >> n_1_Tung;
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
	{
		cout << "nhap vao dong thu " << i_1_Tung + 1 << ": ";
		for (int j_1_Tung = 0; j_1_Tung < n_1_Tung; j_1_Tung++)
			cin >> A_1_Tung[i_1_Tung][j_1_Tung];
	}
}

void output_1_Tung()
{
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
	{
		for (int j_1_Tung = 0; j_1_Tung < n_1_Tung; j_1_Tung++)
			cout << A_1_Tung[i_1_Tung][j_1_Tung] << " ";
		cout << endl;
	}
}

void napMau_1_Tung()
{
	n_1_Tung = 6;
	int mau_1_Tung[6][6] = {
		{0, 1, 1, 1, 0, 0},
		{1, 0, 1, 0, 1, 1},
		{1, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 1},
		{0, 1, 0, 0, 0, 1},
		{0, 1, 1, 1, 1, 0}
	};
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
		for (int j_1_Tung = 0; j_1_Tung < n_1_Tung; j_1_Tung++)
			A_1_Tung[i_1_Tung][j_1_Tung] = mau_1_Tung[i_1_Tung][j_1_Tung];
	cout << "Da nap ma tran ke mau 6 dinh (0=A ... 5=F)!" << endl;
}

// Queue danh sach dac
int Q_1_Tung[MAX_1_Tung];
int qfront_1_Tung, qrear_1_Tung;

void Qinit_1_Tung()
{
	qfront_1_Tung = -1;
	qrear_1_Tung = -1;
}

int Qempty_1_Tung()
{
	return qfront_1_Tung == -1;
}

void Qpush_1_Tung(int x_1_Tung)
{
	if (qfront_1_Tung == -1)
		qfront_1_Tung = 0;
	Q_1_Tung[++qrear_1_Tung] = x_1_Tung;
}

int Qpop_1_Tung(int& x_1_Tung)
{
	if (qfront_1_Tung == -1)
		return 0;
	x_1_Tung = Q_1_Tung[qfront_1_Tung++];
	if (qfront_1_Tung > qrear_1_Tung)
	{
		qfront_1_Tung = -1;
		qrear_1_Tung = -1;
	}
	return 1;
}

// Stack danh sach dac
int S_1_Tung[MAX_1_Tung];
int stop_1_Tung;

void Sinit_1_Tung()
{
	stop_1_Tung = -1;
}

int Sempty_1_Tung()
{
	return stop_1_Tung == -1;
}

void Spush_1_Tung(int x_1_Tung)
{
	S_1_Tung[++stop_1_Tung] = x_1_Tung;
}

int Spop_1_Tung(int& x_1_Tung)
{
	if (stop_1_Tung == -1)
		return 0;
	x_1_Tung = S_1_Tung[stop_1_Tung--];
	return 1;
}

void BFS_1_Tung(int start_1_Tung)
{
	if (start_1_Tung < 0 || start_1_Tung >= n_1_Tung)
	{
		cout << "Dinh khong hop le!" << endl;
		return;
	}
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
		chuaxet_1_Tung[i_1_Tung] = 1;
	Qinit_1_Tung();
	Qpush_1_Tung(start_1_Tung);
	chuaxet_1_Tung[start_1_Tung] = 0;
	cout << "BFS: ";
	int u_1_Tung;
	while (Qpop_1_Tung(u_1_Tung) == 1)
	{
		cout << u_1_Tung << " ";
		for (int v_1_Tung = 0; v_1_Tung < n_1_Tung; v_1_Tung++)
		{
			if (A_1_Tung[u_1_Tung][v_1_Tung] == 1 && chuaxet_1_Tung[v_1_Tung] == 1)
			{
				Qpush_1_Tung(v_1_Tung);
				chuaxet_1_Tung[v_1_Tung] = 0;
			}
		}
	}
	cout << endl;
}

void DFS_1_Tung(int start_1_Tung)
{
	if (start_1_Tung < 0 || start_1_Tung >= n_1_Tung)
	{
		cout << "Dinh khong hop le!" << endl;
		return;
	}
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
		chuaxet_1_Tung[i_1_Tung] = 1;
	Sinit_1_Tung();
	Spush_1_Tung(start_1_Tung);
	chuaxet_1_Tung[start_1_Tung] = 0;
	cout << "DFS: ";
	int u_1_Tung;
	while (Spop_1_Tung(u_1_Tung) == 1)
	{
		cout << u_1_Tung << " ";
		for (int v_1_Tung = n_1_Tung - 1; v_1_Tung >= 0; v_1_Tung--)
		{
			if (A_1_Tung[u_1_Tung][v_1_Tung] == 1 && chuaxet_1_Tung[v_1_Tung] == 1)
			{
				Spush_1_Tung(v_1_Tung);
				chuaxet_1_Tung[v_1_Tung] = 0;
			}
		}
	}
	cout << endl;
}

int timDFS_1_Tung(int x_1_Tung)
{
	if (n_1_Tung == 0)
		return 0;
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
		chuaxet_1_Tung[i_1_Tung] = 1;
	Sinit_1_Tung();
	Spush_1_Tung(0);
	chuaxet_1_Tung[0] = 0;
	int u_1_Tung;
	while (Spop_1_Tung(u_1_Tung) == 1)
	{
		if (u_1_Tung == x_1_Tung)
			return 1;
		for (int v_1_Tung = 0; v_1_Tung < n_1_Tung; v_1_Tung++)
		{
			if (A_1_Tung[u_1_Tung][v_1_Tung] == 1 && chuaxet_1_Tung[v_1_Tung] == 1)
			{
				Spush_1_Tung(v_1_Tung);
				chuaxet_1_Tung[v_1_Tung] = 0;
			}
		}
	}
	return 0;
}

int main()
{
	int chon_1_Tung, x_1_Tung;
	init_1_Tung();
	do
	{
		cout << "======= BAI 8: DFS (MA TRAN KE + QUEUE/STACK MANG) =======" << endl;
		cout << "1. Nap ma tran ke mau" << endl;
		cout << "2. Nhap ma tran ke" << endl;
		cout << "3. Xuat ma tran ke" << endl;
		cout << "4. Duyet BFS (Queue mang)" << endl;
		cout << "5. Duyet DFS (Stack mang)" << endl;
		cout << "6. Kiem tra dinh X (bang DFS)" << endl;
		cout << "0. Thoat" << endl;
		cout << "Nhap lua chon: ";
		cin >> chon_1_Tung;
		switch (chon_1_Tung)
		{
		case 1:
			napMau_1_Tung();
			output_1_Tung();
			break;
		case 2:
			input_1_Tung();
			break;
		case 3:
			output_1_Tung();
			break;
		case 4:
			cout << "Nhap dinh bat dau (0..n-1): ";
			cin >> x_1_Tung;
			BFS_1_Tung(x_1_Tung);
			break;
		case 5:
			cout << "Nhap dinh bat dau (0..n-1): ";
			cin >> x_1_Tung;
			DFS_1_Tung(x_1_Tung);
			break;
		case 6:
			cout << "Nhap dinh X: ";
			cin >> x_1_Tung;
			if (timDFS_1_Tung(x_1_Tung) == 1)
				cout << "Dinh " << x_1_Tung << " CO ton tai tren do thi (DFS)" << endl;
			else
				cout << "Dinh " << x_1_Tung << " KHONG ton tai tren do thi (DFS)" << endl;
			break;
		}
	} while (chon_1_Tung != 0);
	return 0;
}
