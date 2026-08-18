// Ho ten: Nguyen Bui Duy Tung
// Chuong 5 - Bai 5: Bubble, Interchange, Quick, Heap, Merge
// Mang mau slide: 44 55 12 42 94 18 6 67  ->  6 12 18 42 44 55 67 94

#include <iostream>
using namespace std;

void hoanVi_1_Tung(int& a_1_Tung, int& b_1_Tung)
{
	int t_1_Tung = a_1_Tung;
	a_1_Tung = b_1_Tung;
	b_1_Tung = t_1_Tung;
}

void output_1_Tung(int a_1_Tung[], int n_1_Tung)
{
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
		cout << a_1_Tung[i_1_Tung] << "\t";
	cout << endl;
}

void copyMang_1_Tung(int src_1_Tung[], int dst_1_Tung[], int n_1_Tung)
{
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
		dst_1_Tung[i_1_Tung] = src_1_Tung[i_1_Tung];
}

// 1. BUBBLE: so sanh cap ke, noi bot ptu nho len dau (sx tang)
void Bubble_1_Tung(int a_1_Tung[], int n_1_Tung)
{
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung - 1; i_1_Tung++)
		for (int j_1_Tung = n_1_Tung - 1; j_1_Tung > i_1_Tung; j_1_Tung--)
			if (a_1_Tung[j_1_Tung] < a_1_Tung[j_1_Tung - 1])
				hoanVi_1_Tung(a_1_Tung[j_1_Tung], a_1_Tung[j_1_Tung - 1]);
}

// 2. INTERCHANGE: doi cho moi cap (i,j) neu a[i] > a[j]
void Interchange_1_Tung(int a_1_Tung[], int n_1_Tung)
{
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung - 1; i_1_Tung++)
		for (int j_1_Tung = i_1_Tung + 1; j_1_Tung < n_1_Tung; j_1_Tung++)
			if (a_1_Tung[i_1_Tung] > a_1_Tung[j_1_Tung])
				hoanVi_1_Tung(a_1_Tung[i_1_Tung], a_1_Tung[j_1_Tung]);
}

// 3. QUICK SORT: chon moc (pivot giua), phan hoach roi de quy 2 nua
void Quick_1_Tung(int a_1_Tung[], int left_1_Tung, int right_1_Tung)
{
	int i_1_Tung = left_1_Tung;
	int j_1_Tung = right_1_Tung;
	int x_1_Tung = a_1_Tung[(left_1_Tung + right_1_Tung) / 2]; // pivot
	while (i_1_Tung <= j_1_Tung)
	{
		while (a_1_Tung[i_1_Tung] < x_1_Tung)
			i_1_Tung++;
		while (a_1_Tung[j_1_Tung] > x_1_Tung)
			j_1_Tung--;
		if (i_1_Tung <= j_1_Tung)
		{
			hoanVi_1_Tung(a_1_Tung[i_1_Tung], a_1_Tung[j_1_Tung]);
			i_1_Tung++;
			j_1_Tung--;
		}
	}
	if (left_1_Tung < j_1_Tung)
		Quick_1_Tung(a_1_Tung, left_1_Tung, j_1_Tung);
	if (i_1_Tung < right_1_Tung)
		Quick_1_Tung(a_1_Tung, i_1_Tung, right_1_Tung);
}

// 4. HEAP SORT: tao max-heap, lap doi a[0] voi cuoi roi heapify
void heapify_1_Tung(int a_1_Tung[], int n_1_Tung, int i_1_Tung)
{
	int largest_1_Tung = i_1_Tung;          // nut cha
	int l_1_Tung = 2 * i_1_Tung + 1;        // con trai
	int r_1_Tung = 2 * i_1_Tung + 2;        // con phai
	if (l_1_Tung < n_1_Tung && a_1_Tung[l_1_Tung] > a_1_Tung[largest_1_Tung])
		largest_1_Tung = l_1_Tung;
	if (r_1_Tung < n_1_Tung && a_1_Tung[r_1_Tung] > a_1_Tung[largest_1_Tung])
		largest_1_Tung = r_1_Tung;
	if (largest_1_Tung != i_1_Tung)
	{
		hoanVi_1_Tung(a_1_Tung[i_1_Tung], a_1_Tung[largest_1_Tung]);
		heapify_1_Tung(a_1_Tung, n_1_Tung, largest_1_Tung);
	}
}

void Heap_1_Tung(int a_1_Tung[], int n_1_Tung)
{
	// dung max-heap tu duoi len
	for (int i_1_Tung = n_1_Tung / 2 - 1; i_1_Tung >= 0; i_1_Tung--)
		heapify_1_Tung(a_1_Tung, n_1_Tung, i_1_Tung);
	// moi vong: dua max ve cuoi, heapify nua con lai
	for (int i_1_Tung = n_1_Tung - 1; i_1_Tung > 0; i_1_Tung--)
	{
		hoanVi_1_Tung(a_1_Tung[0], a_1_Tung[i_1_Tung]);
		heapify_1_Tung(a_1_Tung, i_1_Tung, 0);
	}
}

// 5. MERGE SORT: chia doi, sx 2 nua, tron (merge) thanh 1 doan
void merge_1_Tung(int a_1_Tung[], int l_1_Tung, int m_1_Tung, int r_1_Tung)
{
	int n1_1_Tung = m_1_Tung - l_1_Tung + 1;
	int n2_1_Tung = r_1_Tung - m_1_Tung;
	int L_1_Tung[100], R_1_Tung[100];
	for (int i_1_Tung = 0; i_1_Tung < n1_1_Tung; i_1_Tung++)
		L_1_Tung[i_1_Tung] = a_1_Tung[l_1_Tung + i_1_Tung];
	for (int j_1_Tung = 0; j_1_Tung < n2_1_Tung; j_1_Tung++)
		R_1_Tung[j_1_Tung] = a_1_Tung[m_1_Tung + 1 + j_1_Tung];
	int i_1_Tung = 0, j_1_Tung = 0, k_1_Tung = l_1_Tung;
	while (i_1_Tung < n1_1_Tung && j_1_Tung < n2_1_Tung)
	{
		if (L_1_Tung[i_1_Tung] <= R_1_Tung[j_1_Tung])
			a_1_Tung[k_1_Tung++] = L_1_Tung[i_1_Tung++];
		else
			a_1_Tung[k_1_Tung++] = R_1_Tung[j_1_Tung++];
	}
	while (i_1_Tung < n1_1_Tung)
		a_1_Tung[k_1_Tung++] = L_1_Tung[i_1_Tung++];
	while (j_1_Tung < n2_1_Tung)
		a_1_Tung[k_1_Tung++] = R_1_Tung[j_1_Tung++];
}

void Merge_1_Tung(int a_1_Tung[], int l_1_Tung, int r_1_Tung)
{
	if (l_1_Tung < r_1_Tung)
	{
		int m_1_Tung = (l_1_Tung + r_1_Tung) / 2;
		Merge_1_Tung(a_1_Tung, l_1_Tung, m_1_Tung);
		Merge_1_Tung(a_1_Tung, m_1_Tung + 1, r_1_Tung);
		merge_1_Tung(a_1_Tung, l_1_Tung, m_1_Tung, r_1_Tung);
	}
}

int main()
{
	int mau_1_Tung[] = { 44, 55, 12, 42, 94, 18, 6, 67 };
	int n_1_Tung = 8;
	int a_1_Tung[100];
	int chon_1_Tung;
	do
	{
		cout << "======= BAI 5: CAC THUAT TOAN SAP XEP =======" << endl;
		cout << "Mang mau: 44 55 12 42 94 18 6 67" << endl;
		cout << "1. BUBBLE" << endl;
		cout << "2. INTERCHANGE" << endl;
		cout << "3. QUICK SORT" << endl;
		cout << "4. HEAP SORT" << endl;
		cout << "5. MERGE SORT" << endl;
		cout << "6. Chay tat ca" << endl;
		cout << "0. Thoat" << endl;
		cout << "Nhap lua chon: ";
		cin >> chon_1_Tung;
		if (chon_1_Tung >= 1 && chon_1_Tung <= 6)
			copyMang_1_Tung(mau_1_Tung, a_1_Tung, n_1_Tung);
		switch (chon_1_Tung)
		{
		case 1:
			Bubble_1_Tung(a_1_Tung, n_1_Tung);
			cout << "Xep thu tu danh sach bang BUBBLE SORT" << endl;
			output_1_Tung(a_1_Tung, n_1_Tung);
			break;
		case 2:
			Interchange_1_Tung(a_1_Tung, n_1_Tung);
			cout << "Xep thu tu danh sach bang INTERCHANGE SORT" << endl;
			output_1_Tung(a_1_Tung, n_1_Tung);
			break;
		case 3:
			Quick_1_Tung(a_1_Tung, 0, n_1_Tung - 1);
			cout << "Xep thu tu danh sach bang QUICK SORT" << endl;
			output_1_Tung(a_1_Tung, n_1_Tung);
			break;
		case 4:
			Heap_1_Tung(a_1_Tung, n_1_Tung);
			cout << "Xep thu tu danh sach bang HEAP SORT" << endl;
			output_1_Tung(a_1_Tung, n_1_Tung);
			break;
		case 5:
			Merge_1_Tung(a_1_Tung, 0, n_1_Tung - 1);
			cout << "Xep thu tu danh sach bang MERGE SORT" << endl;
			output_1_Tung(a_1_Tung, n_1_Tung);
			break;
		case 6:
			copyMang_1_Tung(mau_1_Tung, a_1_Tung, n_1_Tung);
			Bubble_1_Tung(a_1_Tung, n_1_Tung);
			cout << "BUBBLE: "; output_1_Tung(a_1_Tung, n_1_Tung);
			copyMang_1_Tung(mau_1_Tung, a_1_Tung, n_1_Tung);
			Interchange_1_Tung(a_1_Tung, n_1_Tung);
			cout << "INTERCHANGE: "; output_1_Tung(a_1_Tung, n_1_Tung);
			copyMang_1_Tung(mau_1_Tung, a_1_Tung, n_1_Tung);
			Quick_1_Tung(a_1_Tung, 0, n_1_Tung - 1);
			cout << "QUICK: "; output_1_Tung(a_1_Tung, n_1_Tung);
			copyMang_1_Tung(mau_1_Tung, a_1_Tung, n_1_Tung);
			Heap_1_Tung(a_1_Tung, n_1_Tung);
			cout << "HEAP: "; output_1_Tung(a_1_Tung, n_1_Tung);
			copyMang_1_Tung(mau_1_Tung, a_1_Tung, n_1_Tung);
			Merge_1_Tung(a_1_Tung, 0, n_1_Tung - 1);
			cout << "MERGE: "; output_1_Tung(a_1_Tung, n_1_Tung);
			break;
		case 0:
			break;
		default:
			cout << "Sai lua chon!" << endl;
		}
	} while (chon_1_Tung != 0);
	return 0;
}
