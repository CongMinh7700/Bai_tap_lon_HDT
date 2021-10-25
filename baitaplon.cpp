#include <iostream>
#include <math.h>
#include <string>
using namespace std;
//lop ten
class Ten
{
  private:
	string ho;
	string tendem;
	string ten;

  public:
	void NhapT();
	void XuatT();
};

//Lop diem
class DTB 
{
  protected:
	float dtb;
	float Dvan;
	float Dtoan;
	float Dly;
	float Dhoa;

  public:
	void NhapD();
	void XuatD();
	void TinhDTB();
	float getDTB();
};
//lop ngay
class Date 
{
  private:
	unsigned int ngay;
	unsigned int thang;
	unsigned int nam;

  public:
	void Nhap1();
	void Xuat1();
};
//lop  sinh vien
class SinhVien : public Date,public Ten,public DTB
{
  private:
	string mssv;
	string lop;
	string diachi;
	string gioitinh;

  public:
	void Nhap();
	void Xuat();
	friend void NhapN(SinhVien a[], int n);
	friend void XuatN(SinhVien a[], int n);
	void CapNhat(SinhVien &sv);
	void CapNhatN(SinhVien a[], int n);
	void XoaID(SinhVien a[], int n);
};
//Nhap ten
void Ten::NhapT()
{
	cout << "\nNhap ho  :";
	fflush(stdin);
	getline(cin, ho);
	cout << "\nNhap ten dem:";
	fflush(stdin);
	getline(cin, tendem);
	cout << "\nNhap ten :";
	fflush(stdin);
	getline(cin, ten);
}
//Xuat ten
void Ten::XuatT()
{
	cout << "\nHo ten: " << ho << " " << tendem << " " << ten;
}
//Nhap diem
void DTB::NhapD()
{
	cout << "\nNhap diem van: ";
	cin >> Dvan;
	cout << "\nNhap diem toan: ";
	cin >> Dtoan;
	cout << "\nNhap diem ly: ";
	cin >> Dly;
	cout << "\nNhap diem hoa: ";
	cin >> Dhoa;
}
//Xuat diem
void DTB::XuatD()
{
	cout << "\nDiem van: " << Dvan;
	cout << "\nDiem toan: " << Dtoan;
	cout << "\nDiem ly: " << Dly;
	cout << "\nDiem hoa: " << Dhoa;
	cout << "\nDiem trung binh la:";
	TinhDTB();
}
//tinh diem trung binh
void DTB::TinhDTB()
{
	dtb = 0;
	dtb = (Dvan + Dtoan + Dly + Dhoa) / 4;
	cout << dtb;
}
float DTB::getDTB()
{
	return this->dtb;
}
//Nhap ngay
void Date::Nhap1()
{
	cout << "\nNhap ngay :";
	cin >> ngay;
	cout << "\nNhap thang :";
	cin >> thang;
	cout << "\nNhap nam: ";
	cin >> nam;
}
//Xuat ngay
void Date::Xuat1()
{
	cout << "\nNam sinh :" << ngay << "/" << thang << "/" << nam;
}
//Nhap thong tin sinh vien
void SinhVien::Nhap()
{
	NhapT();
	Nhap1();
	cout << "\nNhap ma so sinh vien:";
	fflush(stdin);
	getline(cin, mssv);
	cout << "\nNhap lop :";
	fflush(stdin);
	getline(cin, lop);
	cout << "\nNhap dia chi:";
	fflush(stdin);
	getline(cin, diachi);
	cout << "\nNhap gioi tinh :";
	fflush(stdin);
	getline(cin, gioitinh);
	NhapD();
}
//Xuat thong tin sinh vien
void SinhVien::Xuat()
{
	XuatT();
	cout << "\nMa so sinh vien :" << mssv;
	Xuat1();
	cout << "\nGioi tinh :" << gioitinh;
	cout << "\nLop :" << lop;
	cout << "\nDia chi :" << diachi;
	XuatD();

	cout << endl;
}
//Nhap danh sach
void NhapN(SinhVien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap sinh vien thu " << i + 1 << ":";
		a[i].Nhap();
	}
}
//in ra danh sach
void XuatN(SinhVien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nSinh vien thu " << i + 1 << ":";
		a[i].Xuat();
	}
}
//Xoa id
void SinhVien::XoaID(SinhVien a[], int n)
{
	int tim = 0;
	cout << "\nNhap ma so sinh vien can xoa:";
	cin >> mssv;
	for (int i = 0; i < n; i++)
	{
		if (a[i].mssv == mssv)
		{
			tim = 1;
			for (int j = i; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			cout << "\nDa xoa sinh vien co ma so sinh vien la :" << mssv;
			
		XuatN(a, n - 1);

			break;
		}
			}
	if (tim == 0)
	{
		cout << "\nKhong tim thay ma so nay !!";
	}
}
// Cap nhat
void SinhVien::CapNhat(SinhVien &sv)
{
	sv.Nhap();
}
void SinhVien::CapNhatN(SinhVien a[], int n)
{
	int tim = 0;
	cout << "\nNhap ma so sinh vien can cap nhat: ";
	cin >> mssv;
	for (int i = 0; i < n; i++)
	{
		tim = 1;
		if (a[i].mssv == mssv)
		{
			a[i].CapNhat(a[i]);
			XuatN(a, n);
		}
		else if (tim == 0)
		{
			cout << "\nKhong tim thay ma so nay";
		}
	}
}
//Ham main
int main()
{
	SinhVien sv;
	SinhVien a[100];
	int n;
	cout << "\nNhap n :";
	cin >> n;
	cout << "\nNhap thong tin sinh vien ! ";
	NhapN(a, n);
	cout << "\n==============";
	cout << "\nXuat sinh vien !";
	XuatN(a, n);
	cout << "\n===============";
	sv.XoaID(a, n);
	cout << "\n===============";
	sv.CapNhatN(a, n);
}
