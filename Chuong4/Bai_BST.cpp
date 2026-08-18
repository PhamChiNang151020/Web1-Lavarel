// Ho ten: Nguyen Bui Duy Tung
// Chuong 4 - Cay NPTK (tt): them, tim, xoa 3 TH, duyet de quy
//
// Xoa nut: la / bac 1 / bac 2 (the bang cuc trai cua cay con phai).

#include <iostream>
using namespace std;

#define COUNT_1_Tung 10

// 1. Khai bao cau truc cay nhi phan tim kiem
struct Node_1_Tung
{
	int info_1_Tung;
	Node_1_Tung* left_1_Tung;
	Node_1_Tung* right_1_Tung;
};

Node_1_Tung* root_1_Tung;

// 2. Khoi tao cay rong
void init_1_Tung()
{
	root_1_Tung = NULL;
}

// 3. Them 1 ptu vao cay (de quy)
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

// 4. Tim 1 ptu trong cay (de quy)
Node_1_Tung* Tim_1_Tung(Node_1_Tung* p_1_Tung, int x_1_Tung)
{
	if (p_1_Tung == NULL)
		return NULL;
	if (p_1_Tung->info_1_Tung == x_1_Tung)
		return p_1_Tung;
	if (x_1_Tung > p_1_Tung->info_1_Tung)
		return Tim_1_Tung(p_1_Tung->right_1_Tung, x_1_Tung);
	return Tim_1_Tung(p_1_Tung->left_1_Tung, x_1_Tung);
}

// 5. Xoa 1 nut trong cay (de quy) - 3 truong hop
void Xoa_1_Tung(Node_1_Tung*& p_1_Tung, int x_1_Tung)
{
	if (p_1_Tung == NULL)
		return;
	if (x_1_Tung < p_1_Tung->info_1_Tung)
		Xoa_1_Tung(p_1_Tung->left_1_Tung, x_1_Tung);
	else if (x_1_Tung > p_1_Tung->info_1_Tung)
		Xoa_1_Tung(p_1_Tung->right_1_Tung, x_1_Tung);
	else
	{
		// TH1: nut la -> gan NULL
		if (p_1_Tung->left_1_Tung == NULL && p_1_Tung->right_1_Tung == NULL)
		{
			delete p_1_Tung;
			p_1_Tung = NULL;
		}
		// TH2: nut bac 1 -> noi cha voi con con lai
		else if (p_1_Tung->left_1_Tung == NULL)
		{
			Node_1_Tung* t_1_Tung = p_1_Tung;
			p_1_Tung = p_1_Tung->right_1_Tung;
			delete t_1_Tung;
		}
		else if (p_1_Tung->right_1_Tung == NULL)
		{
			Node_1_Tung* t_1_Tung = p_1_Tung;
			p_1_Tung = p_1_Tung->left_1_Tung;
			delete t_1_Tung;
		}
		// TH3: nut bac 2 - the bang nut cuc trai cua nhanh con phai
		else
		{
			Node_1_Tung* t_1_Tung = p_1_Tung->right_1_Tung;
			while (t_1_Tung->left_1_Tung != NULL)
				t_1_Tung = t_1_Tung->left_1_Tung; // di het nhanh trai
			p_1_Tung->info_1_Tung = t_1_Tung->info_1_Tung;
			Xoa_1_Tung(p_1_Tung->right_1_Tung, t_1_Tung->info_1_Tung);
		}
	}
}

// 6. Duyet NLR de quy
void duyetNLR_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung != NULL)
	{
		cout << p_1_Tung->info_1_Tung << "\t";
		duyetNLR_1_Tung(p_1_Tung->left_1_Tung);
		duyetNLR_1_Tung(p_1_Tung->right_1_Tung);
	}
}

// 7. Duyet LNR de quy
void duyetLNR_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung != NULL)
	{
		duyetLNR_1_Tung(p_1_Tung->left_1_Tung);
		cout << p_1_Tung->info_1_Tung << "\t";
		duyetLNR_1_Tung(p_1_Tung->right_1_Tung);
	}
}

// 8. Duyet LRN de quy
void duyetLRN_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung != NULL)
	{
		duyetLRN_1_Tung(p_1_Tung->left_1_Tung);
		duyetLRN_1_Tung(p_1_Tung->right_1_Tung);
		cout << p_1_Tung->info_1_Tung << "\t";
	}
}

void print2DUtil_1_Tung(Node_1_Tung* p_1_Tung, int space_1_Tung)
{
	if (p_1_Tung == NULL)
		return;
	space_1_Tung += COUNT_1_Tung;
	print2DUtil_1_Tung(p_1_Tung->right_1_Tung, space_1_Tung);
	cout << endl;
	for (int i_1_Tung = COUNT_1_Tung; i_1_Tung < space_1_Tung; i_1_Tung++)
		cout << " ";
	cout << p_1_Tung->info_1_Tung << "\n";
	print2DUtil_1_Tung(p_1_Tung->left_1_Tung, space_1_Tung);
}

int main()
{
	int chon_1_Tung, x_1_Tung;
	init_1_Tung();
	do
	{
		cout << "======= CAY NPTK (XOA 3 TRUONG HOP) =======" << endl;
		cout << "1. Khoi tao cay rong" << endl;
		cout << "2. Them 1 phan tu" << endl;
		cout << "3. Tim 1 phan tu" << endl;
		cout << "4. Xoa 1 nut" << endl;
		cout << "5. Duyet NLR" << endl;
		cout << "6. Duyet LNR" << endl;
		cout << "7. Duyet LRN" << endl;
		cout << "8. Xuat cay" << endl;
		cout << "0. Thoat" << endl;
		cout << "Nhap lua chon: ";
		cin >> chon_1_Tung;
		switch (chon_1_Tung)
		{
		case 1:
			init_1_Tung();
			cout << "Da khoi tao cay rong!" << endl;
			break;
		case 2:
			cout << "Nhap x: ";
			cin >> x_1_Tung;
			Them_1_Tung(root_1_Tung, x_1_Tung);
			print2DUtil_1_Tung(root_1_Tung, 15);
			cout << endl;
			break;
		case 3:
			cout << "Nhap x can tim: ";
			cin >> x_1_Tung;
			if (Tim_1_Tung(root_1_Tung, x_1_Tung) != NULL)
				cout << "Tim thay " << x_1_Tung << endl;
			else
				cout << "Ko Tim thay " << x_1_Tung << " trong cay NPTK" << endl;
			break;
		case 4:
			cout << "Nhap x can xoa: ";
			cin >> x_1_Tung;
			Xoa_1_Tung(root_1_Tung, x_1_Tung);
			cout << "Xoa node " << x_1_Tung << " trong cay:" << endl;
			duyetLNR_1_Tung(root_1_Tung);
			cout << endl;
			break;
		case 5:
			cout << "NLR: ";
			duyetNLR_1_Tung(root_1_Tung);
			cout << endl;
			break;
		case 6:
			cout << "LNR: ";
			duyetLNR_1_Tung(root_1_Tung);
			cout << endl;
			break;
		case 7:
			cout << "LRN: ";
			duyetLRN_1_Tung(root_1_Tung);
			cout << endl;
			break;
		case 8:
			print2DUtil_1_Tung(root_1_Tung, 15);
			cout << endl;
			break;
		}
	} while (chon_1_Tung != 0);
	return 0;
}
