// Ho ten: Nguyen Bui Duy Tung
// Chuong 5 - Bai 4: Insertion Sort + Selection Sort
// Insertion: chen a[i] vao doan [0..i-1] da co thu tu. O(n^2)
// Selection: moi vong dua ptu nho nhat ve dau doan chua sx. O(n^2)

#include <iostream>
using namespace std;

void hoanVi_1_Tung(int& a_1_Tung, int& b_1_Tung)
{
	int t_1_Tung = a_1_Tung;
	a_1_Tung = b_1_Tung;
	b_1_Tung = t_1_Tung;
}

// Cau 1.2: NHAP DANH SACH
void input_1_Tung(int a_1_Tung[], int& n_1_Tung)
{
	cout << "Nhap so phan tu n: ";
	cin >> n_1_Tung;
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
	{
		cout << "a[" << i_1_Tung << "] = ";
		cin >> a_1_Tung[i_1_Tung];
	}
}

// Cau 1.3: XUAT DANH SACH
void output_1_Tung(int a_1_Tung[], int n_1_Tung)
{
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
		cout << a_1_Tung[i_1_Tung] << "\t";
	cout << endl;
}

// Cau 1.4 Insertion Sort
// Ban dau doan [0] da sx. Lan luot chen a[i] vao dung cho trong doan [0..i]
void Insertion_1_Tung(int a_1_Tung[], int n_1_Tung)
{
	for (int i_1_Tung = 1; i_1_Tung < n_1_Tung; i_1_Tung++)
	{
		int x_1_Tung = a_1_Tung[i_1_Tung]; // phan tu muon chen vao doan con
		int pos_1_Tung = i_1_Tung - 1;
		/* Di chuyen cac ptu co gtri lon hon gtri key ve sau 1 vtri so voi vtri ban dau cua no */
		while (pos_1_Tung >= 0 && a_1_Tung[pos_1_Tung] > x_1_Tung)
		{
			a_1_Tung[pos_1_Tung + 1] = a_1_Tung[pos_1_Tung];
			pos_1_Tung--;
		}
		a_1_Tung[pos_1_Tung + 1] = x_1_Tung;
	}
}

// Selection Sort: vong k tim min trong [k..n-1] roi doi voi a[k]
void Selection_1_Tung(int a_1_Tung[], int n_1_Tung)
{
	// Di chuyen ranh gioi cua mang da sap xep va chua sx
	for (int k_1_Tung = 0; k_1_Tung < n_1_Tung - 1; k_1_Tung++)
	{
		// tim ptu nho nhat trong mang chua sx
		int vt_min_1_Tung = k_1_Tung;
		for (int i_1_Tung = k_1_Tung + 1; i_1_Tung < n_1_Tung; i_1_Tung++)
			if (a_1_Tung[i_1_Tung] < a_1_Tung[vt_min_1_Tung])
				vt_min_1_Tung = i_1_Tung;
		// doi cho ptu nho nhat voi ptu dau tien
		hoanVi_1_Tung(a_1_Tung[vt_min_1_Tung], a_1_Tung[k_1_Tung]);
	}
}

int main()
{
	int chon_1_Tung;
	do
	{
		cout << "======= BAI 4: INSERTION & SELECTION =======" << endl;
		cout << "1. Insertion Sort (mang mau 3 5 9 7 3 20)" << endl;
		cout << "2. Selection Sort (mang mau 3 -5 9 7 20)" << endl;
		cout << "3. Nhap mang roi Insertion" << endl;
		cout << "4. Nhap mang roi Selection" << endl;
		cout << "0. Thoat" << endl;
		cout << "Nhap lua chon: ";
		cin >> chon_1_Tung;
		if (chon_1_Tung == 1)
		{
			int a_1_Tung[] = { 3, 5, 9, 7, 3, 20 };
			int n_1_Tung = sizeof(a_1_Tung) / sizeof(a_1_Tung[0]);
			Insertion_1_Tung(a_1_Tung, n_1_Tung);
			cout << "Xep thu tu danh sach bang INSERTION SORT" << endl;
			output_1_Tung(a_1_Tung, n_1_Tung);
		}
		else if (chon_1_Tung == 2)
		{
			int a_1_Tung[] = { 3, -5, 9, 7, 20 };
			int n_1_Tung = sizeof(a_1_Tung) / sizeof(a_1_Tung[0]);
			Selection_1_Tung(a_1_Tung, n_1_Tung);
			cout << "Xep thu tu danh sach bang SELECTION SORT" << endl;
			output_1_Tung(a_1_Tung, n_1_Tung);
		}
		else if (chon_1_Tung == 3)
		{
			int a_1_Tung[100];
			int n_1_Tung;
			input_1_Tung(a_1_Tung, n_1_Tung);
			Insertion_1_Tung(a_1_Tung, n_1_Tung);
			cout << "Xep thu tu danh sach bang INSERTION SORT" << endl;
			output_1_Tung(a_1_Tung, n_1_Tung);
		}
		else if (chon_1_Tung == 4)
		{
			int a_1_Tung[100];
			int n_1_Tung;
			input_1_Tung(a_1_Tung, n_1_Tung);
			Selection_1_Tung(a_1_Tung, n_1_Tung);
			cout << "Xep thu tu danh sach bang SELECTION SORT" << endl;
			output_1_Tung(a_1_Tung, n_1_Tung);
		}
	} while (chon_1_Tung != 0);
	return 0;
}
