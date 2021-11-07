#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//lop ten
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

//Lop diem
class DTB : public Ten
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
//lop ngay
class Date : public DTB
{
  private:
	unsigned int ngay;
	unsigned int thang;
	unsigned int nam;

  public:
	void Nhap();
	void Xuat();
};
//lop  sinh vien
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

	string getMS()
	{
		return this->mssv;
	}
};
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
void DTB::Nhap()
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
void DTB::Xuat()
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
//Danh Sach
class DanhSach
{
  private:
	vector<HocSinh *> HS;

  public:
	void NhapDS();
	void XuatDS();
	void XoaID();
	void CapNhat();
};
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
void DanhSach::XuatDS()
{
	cout << endl;
	cout << "\n*******Danh Sach Hoc Sinh *******";
	for (int i = 0; i < HS.size(); i++)
	{
		this->HS.at(i)->Xuat();
		cout << endl;
	}
}

//Nhap thong tin sinh vien
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
	DTB::Nhap();
}
//Xuat thong tin sinh vien
void HocSinh::Xuat()
{
	Ten::Xuat();
	cout << "\nMa so sinh vien :" << mssv;
	Date::Xuat();
	cout << "\nGioi tinh :" << gioitinh;
	cout << "\nLop :" << lop;
	cout << "\nDia chi :" << diachi;
	DTB::Xuat();

	cout << endl;
}
//Xoa id
void DanhSach::XoaID()
{
	int tim = 0;
	int i,j;
	string msv;
	cout << "\nNhap ma so sinh vien can xoa:";
	fflush(stdin);
	getline(cin, msv);
	for (int i =0; i < HS.size(); i++)
	{
		if (msv == HS.at(i)->getMS())
		{
			tim = 1;
			for (int j = i; j < HS.size(); j++)
			{
				HS.at(j) = HS.at(j + 1);
			}
			cout << "\nDa xoa sinh vien co ma so sinh vien la :" << msv;
			HS.erase(HS.begin()+i,HS.begin()+j);
			XuatDS();
			break;
		}
	}
	if (tim == 0)
	{
		cout << "\nKhong tim thay ma so nay !!";
	}
}
int main()
{
	DanhSach ds;
	ds.NhapDS();
	ds.XuatDS();
	ds.XoaID();
	ds.XuatDS();
}
