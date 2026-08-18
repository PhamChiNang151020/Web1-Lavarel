// Ho ten: Nguyen Bui Duy Tung
// Chuong 5 - Bai 6: Bieu dien do thi - ma tran ke + danh sach ke
// Ma tran ke A[i][j] = 1 neu co canh i-j.
// Danh sach ke: first[i] la DSLK cac dinh ke (insert_first theo slide).

#include <iostream>
using namespace std;

#define MAX_1_Tung 20
#define max_1_Tung 100

// ========== MA TRAN KE ==========
int A_1_Tung[MAX_1_Tung][MAX_1_Tung];
int nMT_1_Tung;
char tenDinh_1_Tung[MAX_1_Tung];

void initMT_1_Tung()
{
	nMT_1_Tung = 0;
}

void inputMT_1_Tung()
{
	cout << "nhap so dinh do thi n: ";
	cin >> nMT_1_Tung;
	for (int i_1_Tung = 0; i_1_Tung < nMT_1_Tung; i_1_Tung++)
	{
		cout << "nhap vao dong thu " << i_1_Tung + 1 << ": ";
		for (int j_1_Tung = 0; j_1_Tung < nMT_1_Tung; j_1_Tung++)
			cin >> A_1_Tung[i_1_Tung][j_1_Tung];
	}
}

void outputMT_1_Tung()
{
	for (int i_1_Tung = 0; i_1_Tung < nMT_1_Tung; i_1_Tung++)
	{
		for (int j_1_Tung = 0; j_1_Tung < nMT_1_Tung; j_1_Tung++)
			cout << A_1_Tung[i_1_Tung][j_1_Tung] << " ";
		cout << endl;
	}
}

void inputMT_Ten_1_Tung()
{
	cout << "Nhap so luong dinh: ";
	cin >> nMT_1_Tung;
	cout << "Nhap ten cac dinh: ";
	for (int i_1_Tung = 0; i_1_Tung < nMT_1_Tung; i_1_Tung++)
		cin >> tenDinh_1_Tung[i_1_Tung];
	for (int i_1_Tung = 0; i_1_Tung < nMT_1_Tung; i_1_Tung++)
	{
		cout << "nhap (1/0) cua cac dinh voi dinh " << tenDinh_1_Tung[i_1_Tung] << ": ";
		for (int j_1_Tung = 0; j_1_Tung < nMT_1_Tung; j_1_Tung++)
			cin >> A_1_Tung[i_1_Tung][j_1_Tung];
	}
}

void outputMT_Ten_1_Tung()
{
	cout << "    ";
	for (int i_1_Tung = 0; i_1_Tung < nMT_1_Tung; i_1_Tung++)
		cout << tenDinh_1_Tung[i_1_Tung] << " ";
	cout << endl;
	for (int i_1_Tung = 0; i_1_Tung < nMT_1_Tung; i_1_Tung++)
	{
		cout << tenDinh_1_Tung[i_1_Tung] << "   ";
		for (int j_1_Tung = 0; j_1_Tung < nMT_1_Tung; j_1_Tung++)
			cout << A_1_Tung[i_1_Tung][j_1_Tung] << " ";
		cout << endl;
	}
}

// Do thi mau 6 dinh A-F trong slide
void napMauMT_1_Tung()
{
	nMT_1_Tung = 6;
	int mau_1_Tung[6][6] = {
		{0, 1, 1, 1, 0, 0},
		{1, 0, 1, 0, 1, 1},
		{1, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 1},
		{0, 1, 0, 0, 0, 1},
		{0, 1, 1, 1, 1, 0}
	};
	char ten_1_Tung[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	for (int i_1_Tung = 0; i_1_Tung < 6; i_1_Tung++)
	{
		tenDinh_1_Tung[i_1_Tung] = ten_1_Tung[i_1_Tung];
		for (int j_1_Tung = 0; j_1_Tung < 6; j_1_Tung++)
			A_1_Tung[i_1_Tung][j_1_Tung] = mau_1_Tung[i_1_Tung][j_1_Tung];
	}
	cout << "Da nap do thi mau 6 dinh A-F!" << endl;
}

// ========== DANH SACH KE ==========
struct node_1_Tung
{
	int info_1_Tung;
	node_1_Tung* link_1_Tung;
};

node_1_Tung* first_1_Tung[max_1_Tung];
int nDS_1_Tung;

void initDS_1_Tung()
{
	for (int i_1_Tung = 0; i_1_Tung < nDS_1_Tung; i_1_Tung++)
		first_1_Tung[i_1_Tung] = NULL;
}

void insert_first_1_Tung(node_1_Tung*& f_1_Tung, int x_1_Tung)
{
	node_1_Tung* p_1_Tung;
	p_1_Tung = new node_1_Tung;
	p_1_Tung->info_1_Tung = x_1_Tung;
	p_1_Tung->link_1_Tung = f_1_Tung;
	f_1_Tung = p_1_Tung;
}

void inputDS_1_Tung()
{
	int d_1_Tung, x_1_Tung, m_1_Tung;
	cout << "nhap so dinh do thi n: ";
	cin >> nDS_1_Tung;
	initDS_1_Tung();
	for (int i_1_Tung = 0; i_1_Tung < nDS_1_Tung; i_1_Tung++)
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
	if (f_1_Tung != NULL)
	{
		node_1_Tung* p_1_Tung = f_1_Tung;
		while (p_1_Tung != NULL)
		{
			cout << p_1_Tung->info_1_Tung << " ";
			p_1_Tung = p_1_Tung->link_1_Tung;
		}
	}
}

void outputDS_1_Tung()
{
	if (nDS_1_Tung > 0)
		for (int i_1_Tung = 0; i_1_Tung < nDS_1_Tung; i_1_Tung++)
		{
			cout << endl << "Danh sach thu " << i_1_Tung + 1 << ": ";
			output_list_1_Tung(first_1_Tung[i_1_Tung]);
		}
	else
		cout << "rong";
	cout << endl;
}

int main()
{
	int chon_1_Tung;
	initMT_1_Tung();
	nDS_1_Tung = 0;
	initDS_1_Tung();
	do
	{
		cout << "======= BAI 6: BIEU DIEN DO THI =======" << endl;
		cout << "--- Ma tran ke ---" << endl;
		cout << "1. Nap do thi mau A-F" << endl;
		cout << "2. Nhap ma tran ke" << endl;
		cout << "3. Xuat ma tran ke" << endl;
		cout << "4. Nhap ma tran ke co ten dinh" << endl;
		cout << "5. Xuat ma tran ke co ten dinh" << endl;
		cout << "--- Danh sach ke ---" << endl;
		cout << "6. Nhap danh sach ke" << endl;
		cout << "7. Xuat danh sach ke" << endl;
		cout << "0. Thoat" << endl;
		cout << "Nhap lua chon: ";
		cin >> chon_1_Tung;
		switch (chon_1_Tung)
		{
		case 1:
			napMauMT_1_Tung();
			outputMT_Ten_1_Tung();
			break;
		case 2:
			inputMT_1_Tung();
			break;
		case 3:
			outputMT_1_Tung();
			break;
		case 4:
			inputMT_Ten_1_Tung();
			break;
		case 5:
			outputMT_Ten_1_Tung();
			break;
		case 6:
			inputDS_1_Tung();
			break;
		case 7:
			outputDS_1_Tung();
			break;
		}
	} while (chon_1_Tung != 0);
	return 0;
}
