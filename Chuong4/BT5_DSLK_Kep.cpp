// Ho ten: Nguyen Bui Duy Tung
// Chuong 4 - BT5: DSLK kep - Phan so + Da thuc (giong BT4, dung next/prev)

#include <iostream>
using namespace std;

struct PhanSo_1_Tung
{
	int tu_1_Tung;
	int mau_1_Tung;
};

struct NodePS_1_Tung
{
	PhanSo_1_Tung info_1_Tung;
	NodePS_1_Tung* next_1_Tung;
	NodePS_1_Tung* prev_1_Tung;
};

NodePS_1_Tung* firstPS_1_Tung;
NodePS_1_Tung* lastPS_1_Tung;

int UCLN_1_Tung(int a_1_Tung, int b_1_Tung)
{
	if (a_1_Tung < 0)
		a_1_Tung = -a_1_Tung;
	if (b_1_Tung < 0)
		b_1_Tung = -b_1_Tung;
	while (b_1_Tung != 0)
	{
		int r_1_Tung = a_1_Tung % b_1_Tung;
		a_1_Tung = b_1_Tung;
		b_1_Tung = r_1_Tung;
	}
	return a_1_Tung;
}

void rutGon_1_Tung(PhanSo_1_Tung& ps_1_Tung)
{
	if (ps_1_Tung.mau_1_Tung == 0)
		return;
	if (ps_1_Tung.mau_1_Tung < 0)
	{
		ps_1_Tung.tu_1_Tung = -ps_1_Tung.tu_1_Tung;
		ps_1_Tung.mau_1_Tung = -ps_1_Tung.mau_1_Tung;
	}
	int u_1_Tung = UCLN_1_Tung(ps_1_Tung.tu_1_Tung, ps_1_Tung.mau_1_Tung);
	if (u_1_Tung != 0)
	{
		ps_1_Tung.tu_1_Tung /= u_1_Tung;
		ps_1_Tung.mau_1_Tung /= u_1_Tung;
	}
}

void nhap1PS_1_Tung(PhanSo_1_Tung& ps_1_Tung)
{
	cout << "  Tu so: ";
	cin >> ps_1_Tung.tu_1_Tung;
	cout << "  Mau so: ";
	cin >> ps_1_Tung.mau_1_Tung;
	while (ps_1_Tung.mau_1_Tung == 0)
	{
		cout << "  Mau != 0, nhap lai mau: ";
		cin >> ps_1_Tung.mau_1_Tung;
	}
	rutGon_1_Tung(ps_1_Tung);
}

void xuat1PS_1_Tung(PhanSo_1_Tung ps_1_Tung)
{
	cout << ps_1_Tung.tu_1_Tung << "/" << ps_1_Tung.mau_1_Tung;
}

void themCuoiPS_1_Tung(PhanSo_1_Tung x_1_Tung)
{
	NodePS_1_Tung* p_1_Tung = new NodePS_1_Tung;
	p_1_Tung->info_1_Tung = x_1_Tung;
	p_1_Tung->next_1_Tung = NULL;
	p_1_Tung->prev_1_Tung = lastPS_1_Tung;
	if (firstPS_1_Tung == NULL)
	{
		firstPS_1_Tung = p_1_Tung;
		lastPS_1_Tung = p_1_Tung;
	}
	else
	{
		lastPS_1_Tung->next_1_Tung = p_1_Tung;
		lastPS_1_Tung = p_1_Tung;
	}
}

void nhapN_PS_1_Tung()
{
	int n_1_Tung;
	cout << "Nhap so luong phan so: ";
	cin >> n_1_Tung;
	firstPS_1_Tung = NULL;
	lastPS_1_Tung = NULL;
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
	{
		cout << "Phan so thu " << i_1_Tung + 1 << ":" << endl;
		PhanSo_1_Tung ps_1_Tung;
		nhap1PS_1_Tung(ps_1_Tung);
		themCuoiPS_1_Tung(ps_1_Tung);
	}
}

void xuatDS_PS_1_Tung()
{
	NodePS_1_Tung* p_1_Tung = firstPS_1_Tung;
	if (p_1_Tung == NULL)
	{
		cout << "DS phan so rong!" << endl;
		return;
	}
	cout << "DS phan so: ";
	while (p_1_Tung != NULL)
	{
		xuat1PS_1_Tung(p_1_Tung->info_1_Tung);
		cout << "  ";
		p_1_Tung = p_1_Tung->next_1_Tung;
	}
	cout << endl;
}

PhanSo_1_Tung congPS_1_Tung(PhanSo_1_Tung a_1_Tung, PhanSo_1_Tung b_1_Tung)
{
	PhanSo_1_Tung kq_1_Tung;
	kq_1_Tung.tu_1_Tung = a_1_Tung.tu_1_Tung * b_1_Tung.mau_1_Tung + b_1_Tung.tu_1_Tung * a_1_Tung.mau_1_Tung;
	kq_1_Tung.mau_1_Tung = a_1_Tung.mau_1_Tung * b_1_Tung.mau_1_Tung;
	rutGon_1_Tung(kq_1_Tung);
	return kq_1_Tung;
}

void tongDS_PS_1_Tung()
{
	if (firstPS_1_Tung == NULL)
	{
		cout << "DS rong!" << endl;
		return;
	}
	PhanSo_1_Tung tong_1_Tung;
	tong_1_Tung.tu_1_Tung = 0;
	tong_1_Tung.mau_1_Tung = 1;
	NodePS_1_Tung* p_1_Tung = firstPS_1_Tung;
	while (p_1_Tung != NULL)
	{
		tong_1_Tung = congPS_1_Tung(tong_1_Tung, p_1_Tung->info_1_Tung);
		p_1_Tung = p_1_Tung->next_1_Tung;
	}
	cout << "Tong cac phan so = ";
	xuat1PS_1_Tung(tong_1_Tung);
	cout << endl;
}

struct DonThuc_1_Tung
{
	float heso_1_Tung;
	int somu_1_Tung;
};

struct NodeDT_1_Tung
{
	DonThuc_1_Tung info_1_Tung;
	NodeDT_1_Tung* next_1_Tung;
	NodeDT_1_Tung* prev_1_Tung;
};

NodeDT_1_Tung* firstDT_1_Tung;
NodeDT_1_Tung* lastDT_1_Tung;

void themDonThuc_1_Tung(float hs_1_Tung, int sm_1_Tung)
{
	NodeDT_1_Tung* p_1_Tung = new NodeDT_1_Tung;
	p_1_Tung->info_1_Tung.heso_1_Tung = hs_1_Tung;
	p_1_Tung->info_1_Tung.somu_1_Tung = sm_1_Tung;
	p_1_Tung->next_1_Tung = NULL;
	p_1_Tung->prev_1_Tung = lastDT_1_Tung;
	if (firstDT_1_Tung == NULL)
	{
		firstDT_1_Tung = p_1_Tung;
		lastDT_1_Tung = p_1_Tung;
	}
	else
	{
		lastDT_1_Tung->next_1_Tung = p_1_Tung;
		lastDT_1_Tung = p_1_Tung;
	}
}

void nhapDaThuc_1_Tung()
{
	int n_1_Tung;
	cout << "Nhap so luong don thuc: ";
	cin >> n_1_Tung;
	firstDT_1_Tung = NULL;
	lastDT_1_Tung = NULL;
	for (int i_1_Tung = 0; i_1_Tung < n_1_Tung; i_1_Tung++)
	{
		float hs_1_Tung;
		int sm_1_Tung;
		cout << "Don thuc " << i_1_Tung + 1 << " (he so, so mu): ";
		cin >> hs_1_Tung >> sm_1_Tung;
		themDonThuc_1_Tung(hs_1_Tung, sm_1_Tung);
	}
}

void xuatDaThuc_1_Tung()
{
	NodeDT_1_Tung* p_1_Tung = firstDT_1_Tung;
	if (p_1_Tung == NULL)
	{
		cout << "Da thuc rong!" << endl;
		return;
	}
	cout << "P(x) = ";
	int dau_1_Tung = 1;
	while (p_1_Tung != NULL)
	{
		if (!dau_1_Tung && p_1_Tung->info_1_Tung.heso_1_Tung >= 0)
			cout << " + ";
		else if (!dau_1_Tung)
			cout << " ";
		cout << p_1_Tung->info_1_Tung.heso_1_Tung << "x^" << p_1_Tung->info_1_Tung.somu_1_Tung;
		dau_1_Tung = 0;
		p_1_Tung = p_1_Tung->next_1_Tung;
	}
	cout << endl;
}

float tinhDaThuc_1_Tung(float x_1_Tung)
{
	float kq_1_Tung = 0;
	NodeDT_1_Tung* p_1_Tung = firstDT_1_Tung;
	while (p_1_Tung != NULL)
	{
		float luythua_1_Tung = 1;
		for (int i_1_Tung = 0; i_1_Tung < p_1_Tung->info_1_Tung.somu_1_Tung; i_1_Tung++)
			luythua_1_Tung *= x_1_Tung;
		kq_1_Tung += p_1_Tung->info_1_Tung.heso_1_Tung * luythua_1_Tung;
		p_1_Tung = p_1_Tung->next_1_Tung;
	}
	return kq_1_Tung;
}

void menu_1_Tung()
{
	cout << "======= BT5: DSLK KEP - PHAN SO & DA THUC =======" << endl;
	cout << "--- Phan so ---" << endl;
	cout << "1. Nhap 1 phan so (them vao ds)" << endl;
	cout << "2. Nhap n phan so" << endl;
	cout << "3. Xuat ds phan so (da rut gon)" << endl;
	cout << "4. Tinh tong phan so" << endl;
	cout << "--- Da thuc ---" << endl;
	cout << "5. Nhap da thuc" << endl;
	cout << "6. Xuat da thuc" << endl;
	cout << "7. Tinh P(x)" << endl;
	cout << "0. Thoat" << endl;
	cout << "Nhap lua chon: ";
}

int main()
{
	firstPS_1_Tung = NULL;
	lastPS_1_Tung = NULL;
	firstDT_1_Tung = NULL;
	lastDT_1_Tung = NULL;
	int chon_1_Tung;
	do
	{
		menu_1_Tung();
		cin >> chon_1_Tung;
		switch (chon_1_Tung)
		{
		case 1:
		{
			PhanSo_1_Tung ps_1_Tung;
			nhap1PS_1_Tung(ps_1_Tung);
			themCuoiPS_1_Tung(ps_1_Tung);
			xuatDS_PS_1_Tung();
			break;
		}
		case 2:
			nhapN_PS_1_Tung();
			xuatDS_PS_1_Tung();
			break;
		case 3:
			xuatDS_PS_1_Tung();
			break;
		case 4:
			tongDS_PS_1_Tung();
			break;
		case 5:
			nhapDaThuc_1_Tung();
			xuatDaThuc_1_Tung();
			break;
		case 6:
			xuatDaThuc_1_Tung();
			break;
		case 7:
		{
			float x_1_Tung;
			cout << "Nhap x: ";
			cin >> x_1_Tung;
			cout << "P(" << x_1_Tung << ") = " << tinhDaThuc_1_Tung(x_1_Tung) << endl;
			break;
		}
		case 0:
			cout << "Thoat!" << endl;
			break;
		default:
			cout << "Sai lua chon!" << endl;
		}
	} while (chon_1_Tung != 0);
	return 0;
}
