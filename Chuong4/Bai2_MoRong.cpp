// Ho ten: Nguyen Bui Duy Tung
// Chuong 4 - Bai 2: Cac thao tac mo rong tren cay NPTK
// Dem nut, la, nut trong, chieu cao, muc k, tong, min/max...

#include <iostream>
using namespace std;

#define COUNT_1_Tung 10

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

void xuatCay_1_Tung()
{
	print2DUtil_1_Tung(root_1_Tung, 15);
	cout << endl;
}

// 1. Dem so nut tren cay (de quy: 1 + trai + phai)
int demNut_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung == NULL)
		return 0;
	return 1 + demNut_1_Tung(p_1_Tung->left_1_Tung) + demNut_1_Tung(p_1_Tung->right_1_Tung);
}

// 2. Dem so nut la (2 con deu NULL)
int demLa_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung == NULL)
		return 0;
	if (p_1_Tung->left_1_Tung == NULL && p_1_Tung->right_1_Tung == NULL)
		return 1;
	return demLa_1_Tung(p_1_Tung->left_1_Tung) + demLa_1_Tung(p_1_Tung->right_1_Tung);
}

// 3. Dem nut khong la (co it nhat 1 con)
int demKhongLa_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung == NULL)
		return 0;
	if (p_1_Tung->left_1_Tung == NULL && p_1_Tung->right_1_Tung == NULL)
		return 0;
	return 1 + demKhongLa_1_Tung(p_1_Tung->left_1_Tung) + demKhongLa_1_Tung(p_1_Tung->right_1_Tung);
}

// Nut trong (trung gian): co du 2 con
int demNutTrong_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung == NULL)
		return 0;
	int d_1_Tung = 0;
	if (p_1_Tung->left_1_Tung != NULL && p_1_Tung->right_1_Tung != NULL)
		d_1_Tung = 1;
	return d_1_Tung + demNutTrong_1_Tung(p_1_Tung->left_1_Tung) + demNutTrong_1_Tung(p_1_Tung->right_1_Tung);
}

// 4. Chieu cao: max(trai, phai) + 1 ; cay rong = 0
int chieuCao_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung == NULL)
		return 0;
	int trai_1_Tung = chieuCao_1_Tung(p_1_Tung->left_1_Tung);
	int phai_1_Tung = chieuCao_1_Tung(p_1_Tung->right_1_Tung);
	return (trai_1_Tung > phai_1_Tung ? trai_1_Tung : phai_1_Tung) + 1;
}

// 5. Dem nut co gia tri bang x
int demGiaTriX_1_Tung(Node_1_Tung* p_1_Tung, int x_1_Tung)
{
	if (p_1_Tung == NULL)
		return 0;
	int d_1_Tung = (p_1_Tung->info_1_Tung == x_1_Tung) ? 1 : 0;
	return d_1_Tung + demGiaTriX_1_Tung(p_1_Tung->left_1_Tung, x_1_Tung) + demGiaTriX_1_Tung(p_1_Tung->right_1_Tung, x_1_Tung);
}

// 6. Min / Max
int timMin_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung == NULL)
		return 0;
	while (p_1_Tung->left_1_Tung != NULL)
		p_1_Tung = p_1_Tung->left_1_Tung;
	return p_1_Tung->info_1_Tung;
}

int timMax_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung == NULL)
		return 0;
	while (p_1_Tung->right_1_Tung != NULL)
		p_1_Tung = p_1_Tung->right_1_Tung;
	return p_1_Tung->info_1_Tung;
}

// 7. Tong cac gia tri
int tong_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung == NULL)
		return 0;
	return p_1_Tung->info_1_Tung + tong_1_Tung(p_1_Tung->left_1_Tung) + tong_1_Tung(p_1_Tung->right_1_Tung);
}

// Xuat cac ptu nho hon 6 (theo man hinh mau bai 2)
void xuatNhoHon_1_Tung(Node_1_Tung* p_1_Tung, int x_1_Tung)
{
	if (p_1_Tung == NULL)
		return;
	xuatNhoHon_1_Tung(p_1_Tung->left_1_Tung, x_1_Tung);
	if (p_1_Tung->info_1_Tung < x_1_Tung)
		cout << p_1_Tung->info_1_Tung << "\t";
	xuatNhoHon_1_Tung(p_1_Tung->right_1_Tung, x_1_Tung);
}

// 8. Xuat nut o muc k (muc root = 1)
void xuatMucK_1_Tung(Node_1_Tung* p_1_Tung, int k_1_Tung, int muc_1_Tung)
{
	if (p_1_Tung == NULL)
		return;
	if (muc_1_Tung == k_1_Tung)
	{
		cout << p_1_Tung->info_1_Tung << "\t";
		return;
	}
	xuatMucK_1_Tung(p_1_Tung->left_1_Tung, k_1_Tung, muc_1_Tung + 1);
	xuatMucK_1_Tung(p_1_Tung->right_1_Tung, k_1_Tung, muc_1_Tung + 1);
}

// 9. Dem nut la o muc k
int demLaMucK_1_Tung(Node_1_Tung* p_1_Tung, int k_1_Tung, int muc_1_Tung)
{
	if (p_1_Tung == NULL)
		return 0;
	if (muc_1_Tung == k_1_Tung)
	{
		if (p_1_Tung->left_1_Tung == NULL && p_1_Tung->right_1_Tung == NULL)
			return 1;
		return 0;
	}
	return demLaMucK_1_Tung(p_1_Tung->left_1_Tung, k_1_Tung, muc_1_Tung + 1)
		+ demLaMucK_1_Tung(p_1_Tung->right_1_Tung, k_1_Tung, muc_1_Tung + 1);
}

void menu_1_Tung()
{
	cout << "======= BAI 2: THAO TAC MO RONG CAY NPTK =======" << endl;
	cout << "1. Them 1 phan tu vao cay" << endl;
	cout << "2. Tinh tong cac phan tu trong cay" << endl;
	cout << "3. GTLN trong cay" << endl;
	cout << "4. GTNN trong cay" << endl;
	cout << "5. So luong cac nut trong cay" << endl;
	cout << "6. So luong cac nut la trong cay" << endl;
	cout << "7. So luong cac nut ko la trong cay" << endl;
	cout << "8. So luong cac nut --trong(trung gian)-- trong cay" << endl;
	cout << "9. xuat cac ptu nho hon 6 trong cay" << endl;
	cout << "10. Tinh chieu cao cua cay" << endl;
	cout << "11. xuat ra man hinh cac nut o muc k" << endl;
	cout << "12. dem nut la o muc k" << endl;
	cout << "13. xuat cay" << endl;
	cout << "14. Dem nut co gia tri bang x" << endl;
	cout << "0. Thoat" << endl;
	cout << "Nhap lua chon: ";
}

int main()
{
	init_1_Tung();
	int chon_1_Tung;
	int x_1_Tung, k_1_Tung;
	do
	{
		menu_1_Tung();
		cin >> chon_1_Tung;
		switch (chon_1_Tung)
		{
		case 1:
			cout << "Nhap phan tu can them: ";
			cin >> x_1_Tung;
			Them_1_Tung(root_1_Tung, x_1_Tung);
			break;
		case 2:
			cout << "Tong cac phan tu: " << tong_1_Tung(root_1_Tung) << endl;
			break;
		case 3:
			if (root_1_Tung == NULL)
				cout << "Cay rong!" << endl;
			else
				cout << "GTLN: " << timMax_1_Tung(root_1_Tung) << endl;
			break;
		case 4:
			if (root_1_Tung == NULL)
				cout << "Cay rong!" << endl;
			else
				cout << "GTNN: " << timMin_1_Tung(root_1_Tung) << endl;
			break;
		case 5:
			cout << "So nut: " << demNut_1_Tung(root_1_Tung) << endl;
			break;
		case 6:
			cout << "So nut la: " << demLa_1_Tung(root_1_Tung) << endl;
			break;
		case 7:
			cout << "So nut ko la: " << demKhongLa_1_Tung(root_1_Tung) << endl;
			break;
		case 8:
			cout << "So nut trong (trung gian): " << demNutTrong_1_Tung(root_1_Tung) << endl;
			break;
		case 9:
			cout << "Cac ptu nho hon 6: ";
			xuatNhoHon_1_Tung(root_1_Tung, 6);
			cout << endl;
			break;
		case 10:
			cout << "Chieu cao cay: " << chieuCao_1_Tung(root_1_Tung) << endl;
			break;
		case 11:
			cout << "Nhap muc k: ";
			cin >> k_1_Tung;
			cout << "Cac nut o muc " << k_1_Tung << ": ";
			xuatMucK_1_Tung(root_1_Tung, k_1_Tung, 1);
			cout << endl;
			break;
		case 12:
			cout << "Nhap muc k: ";
			cin >> k_1_Tung;
			cout << "So nut la o muc " << k_1_Tung << ": "
				<< demLaMucK_1_Tung(root_1_Tung, k_1_Tung, 1) << endl;
			break;
		case 13:
			xuatCay_1_Tung();
			break;
		case 14:
			cout << "Nhap x: ";
			cin >> x_1_Tung;
			cout << "So nut co gia tri " << x_1_Tung << ": "
				<< demGiaTriX_1_Tung(root_1_Tung, x_1_Tung) << endl;
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
