#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
//LOP TEN
class Ten
{
  private:
	string ho;
	string tendem;
	string ten;

  public:
	virtual void Nhap();
	virtual void Xuat();
};

//LOP DIEM
class Diem : public Ten
{
  protected:
	float dtb;
	float Dvan;
	float Dtoan;
	float Dly;
	float Dhoa;

  public:
	void Nhap();
	void Xuat();
	void TinhDTB();
	float getDTB();
};
//LOP NGAY THANG NAM
class Date : public Diem
{
  private:
	unsigned int ngay;
	unsigned int thang;
	unsigned int nam;

  public:
	void Nhap();
	void Xuat();
};
//LOP HOC SINH
class HocSinh : public Date
{
  private:
	string mssv;
	string lop;
	string diachi;
	string gioitinh;

  public:
	void Nhap();
	void Xuat();
	void XepLoai();
	string getMS()
	{
		return this->mssv;
	}
};
//LOP DANH SACH
class DanhSach
{
  private:
	vector<HocSinh *> HS;

  public:
	void NhapDS();
	void XuatDS();
	int XoaID();
	void XoaK();
	void CapNhat();
};
//Nhap ten
void Ten::Nhap()
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
void Ten::Xuat()
{
	cout << "\nHo ten: " << ho << " " << tendem << " " << ten;
}
//Nhap diem
void Diem::Nhap()
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
void Diem::Xuat()
{
	cout << "\nDiem van: " << Dvan;
	cout << "\nDiem toan: " << Dtoan;
	cout << "\nDiem ly: " << Dly;
	cout << "\nDiem hoa: " << Dhoa;
	TinhDTB();
}
//Tinh diem trung binh
void Diem::TinhDTB()
{
	dtb = 0;
	dtb = (Dvan + Dtoan + Dly + Dhoa) / 4;
	cout << "\nDiem trung binh la :" << dtb;
}
//get Diem Trung Binh
float Diem::getDTB()
{
	return this->dtb;
}
//Nhap ngay
void Date::Nhap()
{
	cout << "\nNhap ngay :";
	cin >> ngay;
	cout << "\nNhap thang :";
	cin >> thang;
	cout << "\nNhap nam: ";
	cin >> nam;
}
//Xuat ngay
void Date::Xuat()
{
	cout << "\nNam sinh :" << ngay << "/" << thang << "/" << nam;
}
//Xep loai
void HocSinh::XepLoai()
{
	if (getDTB() < 5.0)
	{
		cout << " Kem ";
	}
	else if (getDTB() > 5.0 && getDTB() < 6.5)
	{
		cout << " Trung binh ";
	}
	else if (getDTB() > 6.5 && getDTB() < 8.0)
	{
		cout << " Kha ";
	}
	else
		cout << " Gioi ";
}
//Nhap Thong Tin Hoc Sinh
void HocSinh::Nhap()
{
	Ten::Nhap();
	Date::Nhap();
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
	Diem::Nhap();
}
//Xuat Thong Tin Hoc Sinh
void HocSinh::Xuat()
{
	Ten::Xuat();
	cout << "\nMa so sinh vien :" << mssv;
	Date::Xuat();
	cout << "\nGioi tinh :" << gioitinh;
	cout << "\nLop :" << lop;
	cout << "\nDia chi :" << diachi;
	Diem::Xuat();
	cout << "\nHoc Luc :";
	XepLoai();
	cout << endl;
}
//Nhap Danh Sach
void DanhSach::NhapDS()
{
	int n;
	HocSinh *a;
	cout << "\nNhap so luong hoc sinh :";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap Hoc Sinh thu " << i + 1 << ":" << endl;
		a = new HocSinh;
		a->Nhap();
		HS.push_back(a);
		cout << endl;
	}
}
//Xuat Danh Sach
void DanhSach::XuatDS()
{
	cout << endl;
	cout << "\n*******Danh Sach Hoc Sinh *******";
	for (int i = 0; i < HS.size(); i++)
	{
		cout << "\nHoc Sinh thu " << i + 1 << ":";
		this->HS.at(i)->Xuat();
		cout << endl;
	}
}

//Xoa Theo Ma So Sinh Vien
int DanhSach::XoaID()
{
	int tim = 0;
	string msv;
	cout << "\nNhap ma so sinh vien can xoa:";
	cin.ignore();
	getline(cin, msv);
	int n = HS.size();
	for (int i = 0; i < n; i++)
	{
		if (HS.at(i)->getMS() == msv)
		{
			tim = 1;
			for (int j = i; j < n - 1; j++)
			{
				HS.at(j) = HS.at(j + 1);
				n--;
				i--;
				HS.erase(HS.begin() + n - 1);
			}
		}
		cout << "\nDanh Sach Sau Khi Xoa La !!!";
		XuatDS();
		break;
	}

	return tim;

	if (tim == 0)
	{
		cout << "\nKhong tim thay ma so nay !!";
	}
}
// Cap Nhat Lai Danh Sach
void DanhSach::CapNhat()
{
	string msv;
	int tim = 0;
	cout << "\nNhap ma so sinh vien can cap nhat: ";
	cin.ignore();
	getline(cin, msv);
	for (int i = 0; i < HS.size(); i++)
	{
		tim = 1;
		if (HS.at(i)->getMS() == msv)
		{
			HS.at(i)->Nhap();
			cout << "\nDanh Sach Sau Khi Cap Nhat La !!!";
			XuatDS();
			break;
		}
	}
	if (tim == 0)
	{
		cout << "\nKhong tim thay ma so nay";
	}
}
//Ham Main
int main()
{
	DanhSach ds;
	ds.NhapDS();
	ds.XuatDS();
	ds.CapNhat();
	ds.XoaID();
}
