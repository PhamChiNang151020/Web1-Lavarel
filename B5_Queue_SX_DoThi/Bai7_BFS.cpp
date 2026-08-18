// Ho ten: Tung
// B5 - Bai 7: BFS (danh sach ke + Queue/Stack DSLK)
// Bien khai bao theo dang x_1_Tung

#include <iostream>
using namespace std;

#define max_1_Tung 100

struct node_1_Tung
{
	int info_1_Tung;
	node_1_Tung* link_1_Tung;
};

node_1_Tung* first_1_Tung[max_1_Tung];
int n_1_Tung;
int chuaxet_1_Tung[max_1_Tung];

void init_1_Tung()
{
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
		first_1_Tung[i_1_Tung] = NULL;
}

void insert_first_1_Tung(node_1_Tung*& f_1_Tung, int x_1_Tung)
{
	node_1_Tung* p_1_Tung = new node_1_Tung;
	p_1_Tung->info_1_Tung = x_1_Tung;
	p_1_Tung->link_1_Tung = f_1_Tung;
	f_1_Tung = p_1_Tung;
}

void input_1_Tung()
{
	int d_1_Tung, x_1_Tung, m_1_Tung;
	cout << "nhap so dinh do thi n: ";
	cin >> n_1_Tung;
	init_1_Tung();
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
	{
		cout << "\nnhap dinh thu " << i_1_Tung + 1 << " : ";
		cin >> d_1_Tung;
		insert_first_1_Tung(first_1_Tung[i_1_Tung], d_1_Tung);
		cout << "nhap vao so dinh ke cua " << d_1_Tung << " : ";
		cin >> m_1_Tung;
		for (int j_1_Tung = 0; j_1_Tung < m_1_Tung; j_1_Tung++)
		{
			cin >> x_1_Tung;
			insert_first_1_Tung(first_1_Tung[i_1_Tung], x_1_Tung);
		}
	}
}

void output_list_1_Tung(node_1_Tung* f_1_Tung)
{
	node_1_Tung* p_1_Tung = f_1_Tung;
	while (p_1_Tung != NULL)
	{
		cout << p_1_Tung->info_1_Tung << " ";
		p_1_Tung = p_1_Tung->link_1_Tung;
	}
}

void output_1_Tung()
{
	if (n_1_Tung > 0)
		for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
		{
			cout << endl << "Danh sach thu " << i_1_Tung + 1 << ": ";
			output_list_1_Tung(first_1_Tung[i_1_Tung]);
		}
	else
		cout << "rong";
	cout << endl;
}

// Nap do thi mau: dinh 0..5 tuong ung A..F
void napMau_1_Tung()
{
	n_1_Tung = 6;
	init_1_Tung();
	int ke_1_Tung[6][5] = {
		{1, 2, 3, -1, -1},
		{0, 2, 4, 5, -1},
		{0, 1, 3, 5, -1},
		{0, 2, 5, -1, -1},
		{1, 5, -1, -1, -1},
		{1, 2, 3, 4, -1}
	};
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
	{
		insert_first_1_Tung(first_1_Tung[i_1_Tung], i_1_Tung);
		for (int j_1_Tung = 0; j_1_Tung < 5; j_1_Tung++)
			if (ke_1_Tung[i_1_Tung][j_1_Tung] != -1)
				insert_first_1_Tung(first_1_Tung[i_1_Tung], ke_1_Tung[i_1_Tung][j_1_Tung]);
	}
	cout << "Da nap do thi mau 6 dinh (0=A ... 5=F)!" << endl;
}

int timViTri_1_Tung(int x_1_Tung)
{
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
	{
		if (first_1_Tung[i_1_Tung] == NULL)
			continue;
		node_1_Tung* p_1_Tung = first_1_Tung[i_1_Tung];
		while (p_1_Tung->link_1_Tung != NULL)
			p_1_Tung = p_1_Tung->link_1_Tung;
		if (p_1_Tung->info_1_Tung == x_1_Tung)
			return i_1_Tung;
	}
	return -1;
}

// Queue DSLK
struct QNode_1_Tung
{
	int info_1_Tung;
	QNode_1_Tung* link_1_Tung;
};

QNode_1_Tung* qfront_1_Tung;
QNode_1_Tung* qrear_1_Tung;

void Qinit_1_Tung()
{
	qfront_1_Tung = NULL;
	qrear_1_Tung = NULL;
}

int Qempty_1_Tung()
{
	return qfront_1_Tung == NULL;
}

void Qpush_1_Tung(int x_1_Tung)
{
	QNode_1_Tung* p_1_Tung = new QNode_1_Tung;
	p_1_Tung->info_1_Tung = x_1_Tung;
	p_1_Tung->link_1_Tung = NULL;
	if (qrear_1_Tung == NULL)
	{
		qfront_1_Tung = p_1_Tung;
		qrear_1_Tung = p_1_Tung;
	}
	else
	{
		qrear_1_Tung->link_1_Tung = p_1_Tung;
		qrear_1_Tung = p_1_Tung;
	}
}

int Qpop_1_Tung(int& x_1_Tung)
{
	if (qfront_1_Tung == NULL)
		return 0;
	QNode_1_Tung* p_1_Tung = qfront_1_Tung;
	x_1_Tung = p_1_Tung->info_1_Tung;
	qfront_1_Tung = qfront_1_Tung->link_1_Tung;
	if (qfront_1_Tung == NULL)
		qrear_1_Tung = NULL;
	delete p_1_Tung;
	return 1;
}

// Stack DSLK
struct SNode_1_Tung
{
	int info_1_Tung;
	SNode_1_Tung* link_1_Tung;
};

SNode_1_Tung* sfirst_1_Tung;

void Sinit_1_Tung()
{
	sfirst_1_Tung = NULL;
}

int Sempty_1_Tung()
{
	return sfirst_1_Tung == NULL;
}

void Spush_1_Tung(int x_1_Tung)
{
	SNode_1_Tung* p_1_Tung = new SNode_1_Tung;
	p_1_Tung->info_1_Tung = x_1_Tung;
	p_1_Tung->link_1_Tung = sfirst_1_Tung;
	sfirst_1_Tung = p_1_Tung;
}

int Spop_1_Tung(int& x_1_Tung)
{
	if (sfirst_1_Tung == NULL)
		return 0;
	SNode_1_Tung* p_1_Tung = sfirst_1_Tung;
	x_1_Tung = p_1_Tung->info_1_Tung;
	sfirst_1_Tung = sfirst_1_Tung->link_1_Tung;
	delete p_1_Tung;
	return 1;
}

void BFS_1_Tung(int start_1_Tung)
{
	int vt_1_Tung = timViTri_1_Tung(start_1_Tung);
	if (vt_1_Tung == -1)
	{
		cout << "Dinh bat dau khong ton tai!" << endl;
		return;
	}
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
		chuaxet_1_Tung[i_1_Tung] = 1;
	Qinit_1_Tung();
	Qpush_1_Tung(vt_1_Tung);
	chuaxet_1_Tung[vt_1_Tung] = 0;
	cout << "BFS: ";
	int u_1_Tung;
	while (Qpop_1_Tung(u_1_Tung) == 1)
	{
		node_1_Tung* p_1_Tung = first_1_Tung[u_1_Tung];
		int dinh_1_Tung = start_1_Tung;
		if (p_1_Tung != NULL)
		{
			node_1_Tung* t_1_Tung = p_1_Tung;
			while (t_1_Tung->link_1_Tung != NULL)
				t_1_Tung = t_1_Tung->link_1_Tung;
			dinh_1_Tung = t_1_Tung->info_1_Tung;
		}
		cout << dinh_1_Tung << " ";
		p_1_Tung = first_1_Tung[u_1_Tung];
		while (p_1_Tung != NULL)
		{
			int v_1_Tung = timViTri_1_Tung(p_1_Tung->info_1_Tung);
			if (v_1_Tung != -1 && chuaxet_1_Tung[v_1_Tung] == 1)
			{
				Qpush_1_Tung(v_1_Tung);
				chuaxet_1_Tung[v_1_Tung] = 0;
			}
			p_1_Tung = p_1_Tung->link_1_Tung;
		}
	}
	cout << endl;
}

void DFS_1_Tung(int start_1_Tung)
{
	int vt_1_Tung = timViTri_1_Tung(start_1_Tung);
	if (vt_1_Tung == -1)
	{
		cout << "Dinh bat dau khong ton tai!" << endl;
		return;
	}
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
		chuaxet_1_Tung[i_1_Tung] = 1;
	Sinit_1_Tung();
	Spush_1_Tung(vt_1_Tung);
	chuaxet_1_Tung[vt_1_Tung] = 0;
	cout << "DFS: ";
	int u_1_Tung;
	while (Spop_1_Tung(u_1_Tung) == 1)
	{
		node_1_Tung* p_1_Tung = first_1_Tung[u_1_Tung];
		int dinh_1_Tung = start_1_Tung;
		if (p_1_Tung != NULL)
		{
			node_1_Tung* t_1_Tung = p_1_Tung;
			while (t_1_Tung->link_1_Tung != NULL)
				t_1_Tung = t_1_Tung->link_1_Tung;
			dinh_1_Tung = t_1_Tung->info_1_Tung;
		}
		cout << dinh_1_Tung << " ";
		p_1_Tung = first_1_Tung[u_1_Tung];
		while (p_1_Tung != NULL)
		{
			int v_1_Tung = timViTri_1_Tung(p_1_Tung->info_1_Tung);
			if (v_1_Tung != -1 && chuaxet_1_Tung[v_1_Tung] == 1)
			{
				Spush_1_Tung(v_1_Tung);
				chuaxet_1_Tung[v_1_Tung] = 0;
			}
			p_1_Tung = p_1_Tung->link_1_Tung;
		}
	}
	cout << endl;
}

int timBFS_1_Tung(int x_1_Tung)
{
	if (n_1_Tung == 0)
		return 0;
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
		chuaxet_1_Tung[i_1_Tung] = 1;
	Qinit_1_Tung();
	Qpush_1_Tung(0);
	chuaxet_1_Tung[0] = 0;
	int u_1_Tung;
	while (Qpop_1_Tung(u_1_Tung) == 1)
	{
		node_1_Tung* p_1_Tung = first_1_Tung[u_1_Tung];
		while (p_1_Tung != NULL)
		{
			if (p_1_Tung->info_1_Tung == x_1_Tung)
				return 1;
			int v_1_Tung = timViTri_1_Tung(p_1_Tung->info_1_Tung);
			if (v_1_Tung != -1 && chuaxet_1_Tung[v_1_Tung] == 1)
			{
				Qpush_1_Tung(v_1_Tung);
				chuaxet_1_Tung[v_1_Tung] = 0;
			}
			p_1_Tung = p_1_Tung->link_1_Tung;
		}
	}
	return 0;
}

int main()
{
	int chon_1_Tung, x_1_Tung;
	n_1_Tung = 0;
	do
	{
		cout << "======= BAI 7: BFS (DSLK KE + QUEUE/STACK DSLK) =======" << endl;
		cout << "1. Nap do thi mau" << endl;
		cout << "2. Nhap danh sach ke" << endl;
		cout << "3. Xuat danh sach ke" << endl;
		cout << "4. Duyet BFS (Queue DSLK)" << endl;
		cout << "5. Duyet DFS (Stack DSLK)" << endl;
		cout << "6. Kiem tra dinh X (bang BFS)" << endl;
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
			cout << "Nhap dinh bat dau: ";
			cin >> x_1_Tung;
			BFS_1_Tung(x_1_Tung);
			break;
		case 5:
			cout << "Nhap dinh bat dau: ";
			cin >> x_1_Tung;
			DFS_1_Tung(x_1_Tung);
			break;
		case 6:
			cout << "Nhap dinh X: ";
			cin >> x_1_Tung;
			if (timBFS_1_Tung(x_1_Tung) == 1)
				cout << "Dinh " << x_1_Tung << " CO ton tai tren do thi (BFS)" << endl;
			else
				cout << "Dinh " << x_1_Tung << " KHONG ton tai tren do thi (BFS)" << endl;
			break;
		}
	} while (chon_1_Tung != 0);
	return 0;
}
