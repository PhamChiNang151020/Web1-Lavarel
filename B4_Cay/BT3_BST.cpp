// Ho ten: Tung
// BT3: Cay NPTK - doc file Input.txt, duyet khong de quy
// Bien khai bao theo dang x_1_Tung

#include <iostream>
#include <fstream>
using namespace std;

#define MAX_1_Tung 100

struct Node_1_Tung
{
	int info_1_Tung;
	Node_1_Tung* left_1_Tung;
	Node_1_Tung* right_1_Tung;
};

Node_1_Tung* root_1_Tung;

void init_1_Tung()
{
	root_1_Tung = NULL;
}

void Them_1_Tung(Node_1_Tung*& p_1_Tung, int x_1_Tung)
{
	if (p_1_Tung == NULL)
	{
		p_1_Tung = new Node_1_Tung;
		p_1_Tung->info_1_Tung = x_1_Tung;
		p_1_Tung->left_1_Tung = NULL;
		p_1_Tung->right_1_Tung = NULL;
	}
	else
	{
		if (p_1_Tung->info_1_Tung == x_1_Tung)
			return;
		else if (p_1_Tung->info_1_Tung > x_1_Tung)
			Them_1_Tung(p_1_Tung->left_1_Tung, x_1_Tung);
		else
			Them_1_Tung(p_1_Tung->right_1_Tung, x_1_Tung);
	}
}

// Doc file Input.txt: dong 1 so phan tu, dong 2 day so
void docFile_1_Tung()
{
	ifstream fi_1_Tung("Input.txt");
	if (!fi_1_Tung)
	{
		cout << "Khong mo duoc file Input.txt!" << endl;
		return;
	}
	int n_1_Tung, x_1_Tung;
	fi_1_Tung >> n_1_Tung;
	init_1_Tung();
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
	{
		fi_1_Tung >> x_1_Tung;
		Them_1_Tung(root_1_Tung, x_1_Tung);
	}
	fi_1_Tung.close();
	cout << "Da them " << n_1_Tung << " gia tri tu Input.txt vao cay!" << endl;
}

// Duyet NLR khong de quy (dung stack mang)
void duyetNLR_KhongDeQuy_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung == NULL)
	{
		cout << "Cay rong!" << endl;
		return;
	}
	Node_1_Tung* st_1_Tung[MAX_1_Tung];
	int top_1_Tung = -1;
	st_1_Tung[++top_1_Tung] = p_1_Tung;
	while (top_1_Tung >= 0)
	{
		Node_1_Tung* q_1_Tung = st_1_Tung[top_1_Tung--];
		cout << q_1_Tung->info_1_Tung << "\t";
		if (q_1_Tung->right_1_Tung != NULL)
			st_1_Tung[++top_1_Tung] = q_1_Tung->right_1_Tung;
		if (q_1_Tung->left_1_Tung != NULL)
			st_1_Tung[++top_1_Tung] = q_1_Tung->left_1_Tung;
	}
	cout << endl;
}

// Duyet LNR khong de quy
void duyetLNR_KhongDeQuy_1_Tung(Node_1_Tung* p_1_Tung)
{
	Node_1_Tung* st_1_Tung[MAX_1_Tung];
	int top_1_Tung = -1;
	Node_1_Tung* curr_1_Tung = p_1_Tung;
	while (curr_1_Tung != NULL || top_1_Tung >= 0)
	{
		while (curr_1_Tung != NULL)
		{
			st_1_Tung[++top_1_Tung] = curr_1_Tung;
			curr_1_Tung = curr_1_Tung->left_1_Tung;
		}
		curr_1_Tung = st_1_Tung[top_1_Tung--];
		cout << curr_1_Tung->info_1_Tung << "\t";
		curr_1_Tung = curr_1_Tung->right_1_Tung;
	}
	cout << endl;
}

// Duyet LRN khong de quy (2 stack)
void duyetLRN_KhongDeQuy_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung == NULL)
	{
		cout << "Cay rong!" << endl;
		return;
	}
	Node_1_Tung* st1_1_Tung[MAX_1_Tung];
	Node_1_Tung* st2_1_Tung[MAX_1_Tung];
	int top1_1_Tung = -1;
	int top2_1_Tung = -1;
	st1_1_Tung[++top1_1_Tung] = p_1_Tung;
	while (top1_1_Tung >= 0)
	{
		Node_1_Tung* q_1_Tung = st1_1_Tung[top1_1_Tung--];
		st2_1_Tung[++top2_1_Tung] = q_1_Tung;
		if (q_1_Tung->left_1_Tung != NULL)
			st1_1_Tung[++top1_1_Tung] = q_1_Tung->left_1_Tung;
		if (q_1_Tung->right_1_Tung != NULL)
			st1_1_Tung[++top1_1_Tung] = q_1_Tung->right_1_Tung;
	}
	while (top2_1_Tung >= 0)
		cout << st2_1_Tung[top2_1_Tung--]->info_1_Tung << "\t";
	cout << endl;
}

int laNT_1_Tung(int n_1_Tung)
{
	if (n_1_Tung < 2)
		return 0;
	for (int i_1_Tung = 2; i_1_Tung * i_1_Tung <= n_1_Tung; i_1_Tung++)
		if (n_1_Tung % i_1_Tung == 0)
			return 0;
	return 1;
}

int demNT_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung == NULL)
		return 0;
	int d_1_Tung = laNT_1_Tung(p_1_Tung->info_1_Tung) ? 1 : 0;
	return d_1_Tung + demNT_1_Tung(p_1_Tung->left_1_Tung) + demNT_1_Tung(p_1_Tung->right_1_Tung);
}

int demDu2Con_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung == NULL)
		return 0;
	int d_1_Tung = 0;
	if (p_1_Tung->left_1_Tung != NULL && p_1_Tung->right_1_Tung != NULL)
		d_1_Tung = 1;
	return d_1_Tung + demDu2Con_1_Tung(p_1_Tung->left_1_Tung) + demDu2Con_1_Tung(p_1_Tung->right_1_Tung);
}

void menu_1_Tung()
{
	cout << "======= BT3: CAY NPTK (FILE + KHONG DE QUY) =======" << endl;
	cout << "1. Khoi tao cay rong" << endl;
	cout << "2. Them tu file Input.txt" << endl;
	cout << "3. Duyet NLR khong de quy" << endl;
	cout << "4. Duyet LNR khong de quy" << endl;
	cout << "5. Duyet LRN khong de quy" << endl;
	cout << "6. Dem node so nguyen to" << endl;
	cout << "7. Dem node co du 2 con" << endl;
	cout << "0. Thoat" << endl;
	cout << "Nhap lua chon: ";
}

int main()
{
	init_1_Tung();
	int chon_1_Tung;
	do
	{
		menu_1_Tung();
		cin >> chon_1_Tung;
		switch (chon_1_Tung)
		{
		case 1:
			init_1_Tung();
			cout << "Da khoi tao cay rong!" << endl;
			break;
		case 2:
			docFile_1_Tung();
			break;
		case 3:
			cout << "NLR: ";
			duyetNLR_KhongDeQuy_1_Tung(root_1_Tung);
			break;
		case 4:
			cout << "LNR: ";
			duyetLNR_KhongDeQuy_1_Tung(root_1_Tung);
			break;
		case 5:
			cout << "LRN: ";
			duyetLRN_KhongDeQuy_1_Tung(root_1_Tung);
			break;
		case 6:
			cout << "So node nguyen to: " << demNT_1_Tung(root_1_Tung) << endl;
			break;
		case 7:
			cout << "So node co du 2 con: " << demDu2Con_1_Tung(root_1_Tung) << endl;
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
