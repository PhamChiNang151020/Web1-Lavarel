// MSSV: 
// Ho ten: Nguyen Bui Duy Tung
// Chuong 4 - Bai 1 + Bai 1b: Cay nhi phan tim kiem (NPTK)
//
// BST: nut trai < nut hien tai < nut phai.
// Moi nut cap phat dong, 2 con tro left/right. Nut la: 2 con = NULL.

#include <iostream>
using namespace std;

#define COUNT_1_Tung 10 // khoang cach khi in cay xoay 90 do

// 1. Khai bao cau truc cay
struct Node_1_Tung
{
	int info_1_Tung;            // khoa (gia tri)
	Node_1_Tung* left_1_Tung;   // cay con trai
	Node_1_Tung* right_1_Tung;  // cay con phai
};

Node_1_Tung* root_1_Tung;

// 2. Khoi tao cay rong
void init_1_Tung()
{
	root_1_Tung = NULL;
}

// 3. Them 1 nut vao cay (de quy)
// x < p -> sang trai; x > p -> sang phai; gap NULL thi tao nut moi
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
			return; // da co gia tri nay, khong them trung
		else if (p_1_Tung->info_1_Tung > x_1_Tung)
			Them_1_Tung(p_1_Tung->left_1_Tung, x_1_Tung);
		else
			Them_1_Tung(p_1_Tung->right_1_Tung, x_1_Tung);
	}
}

// 4. Tim 1 phan tu trong cay (de quy)
Node_1_Tung* Tim_1_Tung(Node_1_Tung* p_1_Tung, int x_1_Tung)
{
	if (p_1_Tung != NULL)
	{
		if (p_1_Tung->info_1_Tung == x_1_Tung)
			return p_1_Tung;
		else if (x_1_Tung > p_1_Tung->info_1_Tung)
			return Tim_1_Tung(p_1_Tung->right_1_Tung, x_1_Tung);
		else
			return Tim_1_Tung(p_1_Tung->left_1_Tung, x_1_Tung);
	}
	return NULL;
}

// 5. Duyet cay LNR dung de quy (trai - nut - phai)
void duyetLNR_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung != NULL)
	{
		duyetLNR_1_Tung(p_1_Tung->left_1_Tung);
		cout << p_1_Tung->info_1_Tung << "\t";
		duyetLNR_1_Tung(p_1_Tung->right_1_Tung);
	}
}

// 6. Duyet cay LRN dung de quy (trai - phai - nut)
void duyetLRN_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung != NULL)
	{
		duyetLRN_1_Tung(p_1_Tung->left_1_Tung);
		duyetLRN_1_Tung(p_1_Tung->right_1_Tung);
		cout << p_1_Tung->info_1_Tung << "\t";
	}
}

// 7. Duyet cay NLR dung de quy (nut - trai - phai)
void duyetNLR_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung != NULL)
	{
		cout << p_1_Tung->info_1_Tung << "\t";
		duyetNLR_1_Tung(p_1_Tung->left_1_Tung);
		duyetNLR_1_Tung(p_1_Tung->right_1_Tung);
	}
}

// 8. Tim khoa lon nhat: di lien ve phai
Node_1_Tung* TimMax_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung == NULL)
		return NULL;
	while (p_1_Tung->right_1_Tung != NULL)
		p_1_Tung = p_1_Tung->right_1_Tung;
	return p_1_Tung;
}

// 9. Tim khoa nho nhat: di lien ve trai
Node_1_Tung* TimMin_1_Tung(Node_1_Tung* p_1_Tung)
{
	if (p_1_Tung == NULL)
		return NULL;
	while (p_1_Tung->left_1_Tung != NULL)
		p_1_Tung = p_1_Tung->left_1_Tung;
	return p_1_Tung;
}

// 10. Xoa 1 nut trong cay (3 truong hop)
void Xoa_1_Tung(Node_1_Tung*& p_1_Tung, int x_1_Tung)
{
	if (p_1_Tung == NULL)
		return; // khong tim thay
	if (x_1_Tung < p_1_Tung->info_1_Tung)
		Xoa_1_Tung(p_1_Tung->left_1_Tung, x_1_Tung);
	else if (x_1_Tung > p_1_Tung->info_1_Tung)
		Xoa_1_Tung(p_1_Tung->right_1_Tung, x_1_Tung);
	else
	{
		// Truong hop 1: nut la -> cha tro NULL
		if (p_1_Tung->left_1_Tung == NULL && p_1_Tung->right_1_Tung == NULL)
		{
			delete p_1_Tung;
			p_1_Tung = NULL;
		}
		// Truong hop 2: nut bac 1 -> cha tro thang sang con con lai
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
		// Truong hop 3: nut bac 2
		// The bang nut cuc trai cua nhanh con phai
		else
		{
			Node_1_Tung* t_1_Tung = p_1_Tung->right_1_Tung;
			while (t_1_Tung->left_1_Tung != NULL)
				t_1_Tung = t_1_Tung->left_1_Tung;
			p_1_Tung->info_1_Tung = t_1_Tung->info_1_Tung; // chep khoa the mang
			Xoa_1_Tung(p_1_Tung->right_1_Tung, t_1_Tung->info_1_Tung); // xoa nut the mang
		}
	}
}

// Xuat cay xoay 90 do, in nhanh phai truoc
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

void Process_Tree_1_Tung()
{
	print2DUtil_1_Tung(root_1_Tung, 15);
	cout << endl;
}

void menu_1_Tung()
{
	cout << "------- CHUONG 4 : CAY NPTK -------" << endl;
	cout << "1. Khoi tao CAY NPTK rong" << endl;
	cout << "2. Them phan tu vao CAY NPTK" << endl;
	cout << "3. Tim phan tu co gia tri x trong CAY NPTK" << endl;
	cout << "4. Xoa phan tu co gia tri x trong CAY NPTK" << endl;
	cout << "5. Duyet cay NPTK theo LNR" << endl;
	cout << "6. Duyet cay NPTK theo NLR" << endl;
	cout << "7. Duyet cay NPTK theo LRN" << endl;
	cout << "8. Xuat cay NPTK" << endl;
	cout << "9. Tim khoa nho nhat / lon nhat" << endl;
	cout << "10. Thoat" << endl;
	cout << "Nhap lua chon: ";
}

int main()
{
	int chon_1_Tung;
	int x_1_Tung;
	init_1_Tung();
	do
	{
		menu_1_Tung();
		cin >> chon_1_Tung;
		switch (chon_1_Tung)
		{
		case 1:
			init_1_Tung();
			cout << "Ban vua khoi tao CAY NPTK thanh cong!" << endl;
			break;
		case 2:
			cout << "Nhap gia tri can them: ";
			cin >> x_1_Tung;
			Them_1_Tung(root_1_Tung, x_1_Tung);
			Process_Tree_1_Tung();
			break;
		case 3:
			cout << "Nhap gia tri can tim: ";
			cin >> x_1_Tung;
			if (Tim_1_Tung(root_1_Tung, x_1_Tung) != NULL)
				cout << "Tim thay " << x_1_Tung << " trong cay NPTK" << endl;
			else
				cout << "Ko Tim thay " << x_1_Tung << " trong cay NPTK" << endl;
			break;
		case 4:
			cout << "Nhap node can xoa: ";
			cin >> x_1_Tung;
			if (Tim_1_Tung(root_1_Tung, x_1_Tung) == NULL)
				cout << "Ko Tim thay " << x_1_Tung << " trong cay NPTK" << endl;
			else
			{
				cout << "Xoa node " << x_1_Tung << " trong cay:" << endl;
				Xoa_1_Tung(root_1_Tung, x_1_Tung);
				duyetLNR_1_Tung(root_1_Tung);
				cout << endl;
				Process_Tree_1_Tung();
			}
			break;
		case 5:
			cout << "LNR: ";
			duyetLNR_1_Tung(root_1_Tung);
			cout << endl;
			break;
		case 6:
			cout << "NLR: ";
			duyetNLR_1_Tung(root_1_Tung);
			cout << endl;
			break;
		case 7:
			cout << "LRN: ";
			duyetLRN_1_Tung(root_1_Tung);
			cout << endl;
			break;
		case 8:
			Process_Tree_1_Tung();
			break;
		case 9:
		{
			Node_1_Tung* min_1_Tung = TimMin_1_Tung(root_1_Tung);
			Node_1_Tung* max_1_Tung = TimMax_1_Tung(root_1_Tung);
			if (min_1_Tung == NULL)
				cout << "Cay rong!" << endl;
			else
			{
				cout << "nut co khoa nho nhat la: " << min_1_Tung->info_1_Tung << endl;
				cout << "nut co khoa lon nhat la: " << max_1_Tung->info_1_Tung << endl;
			}
			break;
		}
		case 10:
			cout << "Thoat chuong trinh!" << endl;
			break;
		default:
			cout << "Lua chon khong hop le!" << endl;
		}
	} while (chon_1_Tung != 10);
	return 0;
}
