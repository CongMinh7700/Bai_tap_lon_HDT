#include <iostream>
#include <conio.h>
#include <math.h>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
//NGO CONG MINH(NT)_6151071074
//TRAN NGOC SANG_6151071093
//BANH GIA HUNG_6151071059
using namespace std;

//LOP DIEM
class Diem
{
  protected:
	float dtb;
	float Dvan;
	float Dtoan;
	float Dly;
	float Dhoa;

  public:
	virtual void Nhap();
	virtual void Xuat();
	virtual float TinhDTB() = 0;

	float getDTB()
	{
		return dtb;
	}
	float getToan()
	{
		return Dtoan;
	}
	float getVan()
	{
		return Dvan;
	}
	float getLy()
	{
		return Dly;
	}
	float getHoa()
	{
		return Dhoa;
	}
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
	int getNam()
	{
		return nam;
	}
};
//LOP HOC SINH
class HocSinh : public Date
{
  private:
	string hoten;
	string mssv;
	string lop;
	string diachi;
	string gioitinh;

  public:
	void Nhap();
	void Xuat();
	float TinhDTB();
	void XepLoai();
	string getMS()
	{
		return this->mssv;
	}
	string getTen()
	{
		return this->hoten;
	}
	string getLop()
	{
		return this->lop;
	}
	string getDC()
	{
		return this->diachi;
	}
	string getGT()
	{
		return this->gioitinh;
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
	void XoaID();
	void CapNhat();
	void SapXepMaSo();
	void TimTen();
	void TimMaSo();
	void GhiFile(char *Ttep);
	void DocFile(char *Ttep);
	bool check();
};

//Nhap diem
void Diem::Nhap()
{
	cout << "\nNhap diem van : ";
	cin >> Dvan;
	cout << "\nNhap diem toan : ";
	cin >> Dtoan;
	cout << "\nNhap diem ly : ";
	cin >> Dly;
	cout << "\nNhap diem hoa : ";
	cin >> Dhoa;
}
//Xuat diem
void Diem::Xuat()
{
	cout << "\t" << Dvan;
	cout << "\t" << Dtoan;
	cout << "\t" << Dly;
	cout << "\t" << Dhoa;
}
//Tinh diem trung binh
float HocSinh::TinhDTB()
{
	dtb = 0;
	dtb = (Dvan + Dtoan + Dly + Dhoa) / 4;
	cout << "\t" << dtb;
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
	cout << "\t" << ngay << "/" << thang << "/" << nam;
}
//Xep loai
void HocSinh::XepLoai()
{
	if (getDTB() < 5.0)
	{
		cout << " Kem ";
	}
	else if (getDTB() >= 5.0 && getDTB() < 6.5)
	{
		cout << " Trung binh ";
	}
	else if (getDTB() >= 6.5 && getDTB() < 8.0)
	{
		cout << " Kha ";
	}
	else
		cout << " Gioi ";
}
//Nhap Thong Tin Hoc Sinh
void HocSinh::Nhap()
{
	cout << "\nNhap ho ten : ";
	fflush(stdin);
	getline(cin, hoten);
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
	cout << "\t" << hoten;
	cout << "\t" << mssv;
	Date::Xuat();
	cout << "\t" << gioitinh;
	cout << "\t\t" << lop;
	cout << "\t" << diachi;
	Diem::Xuat();
	TinhDTB();
	cout << "\t";
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
		HS.push_back(a);
		a->Nhap();
		if (check() == true)
		{
			cout << "\nMSSV bi trung vui long nhap lai";
			i--;
			HS.at(i)->Nhap();
			break;
		}
		cout << endl;
	}
}
bool DanhSach::check()
{
	for (int i = 0; i < HS.size(); i++)
	{
		for (int j = 1; j < HS.size(); j++)
		{
			if (HS.at(i)->getMS() == HS.at(j)->getMS())
			{
				return true;
			}else {
					return false;
			}
		}
	}

}

//Xuat Danh Sach
void DanhSach::XuatDS()
{
	cout << endl;
	cout << "\n\t\t\t\t\t\t\t********** Danh Sach Hoc Sinh **********";
	cout << endl;
	cout << "\n__________________________________________________________________________________________________________________________________________________________________";
	cout << "\nSTT\tHo ten\tMSSV\tNam Sinh\tGioi Tinh\tLop\tDia Chi\tToan\tLy\tHoa\tVan\tDiemTB\tHoc luc";
	for (int i = 0; i < HS.size(); i++)
	{
		cout << "\n"
			 << i + 1;
		this->HS.at(i)->Xuat();
		cout << endl;
	}
	cout << "\n__________________________________________________________________________________________________________________________________________________________________";
}

//Xoa Theo Ma So Sinh Vien
void DanhSach::XoaID()
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
			}
			HS.erase(HS.begin() + n - 1);
			cout << "\nDanh Sach Sau Khi Xoa La !!!";
			XuatDS();
			break;
		}
	}
	if (tim == 0)
	{
		cout << "\nKhong tim thay ma so nay !!";
		cout << endl;
	}
}
// Cap Nhat Thong Tin Theo Ma So
void DanhSach::CapNhat()
{
	string msv;
	int tim = 0;
	cout << "\nNhap ma so sinh vien can cap nhat: ";
	cin.ignore();
	getline(cin, msv);
	for (int i = 0; i < HS.size(); i++)
	{
		if (HS.at(i)->getMS() == msv)
		{
			tim = 1;
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
//Ham Sap Xep Theo Ma So Tang Dan
void DanhSach::SapXepMaSo()
{
	for (int i = 0; i < HS.size() - 1; i++)
	{
		for (int j = i + 1; j < HS.size(); j++)
		{
			if (HS.at(i)->getMS() > HS.at(j)->getMS())
			{
				HocSinh *t = HS.at(i);
				HS.at(i) = HS.at(j);
				HS.at(j) = t;
			}
		}
	}
	cout << "\nDanh Sach sau khi sap xep la";
	XuatDS();
}

//Tim theo Ho Ten
void DanhSach::TimTen()
{
	string ten;
	int tim = 0;
	cout << "\nNhap Ten  can tim: ";
	cin.ignore();
	getline(cin, ten);
	for (int i = 0; i < HS.size(); i++)
	{
		if (HS.at(i)->getTen() == ten)
		{
			tim = 1;
			cout << endl;
			cout << "\n__________________________________________________________________________________________________________________________________________________________________";
			cout << endl;
			cout << "\nSTT\tHo ten\tMSSV\tNam Sinh\tGioi Tinh\tLop\tDia Chi\tToan\tLy\tHoa\tVan\tDiemTB\tHoc luc";
			cout << "\n"
				 << i + 1;
			HS.at(i)->Xuat();
			cout << endl;
			cout << "\n__________________________________________________________________________________________________________________________________________________________________";
			cout << endl;
			break;
		}
	}
	if (tim == 0)
	{
		cout << "\nTen khong ton tai !!!";
	}
}
//Tim theo Ma So
void DanhSach::TimMaSo()
{
	string msv;
	int tim = 0;
	cout << "\nNhap ma so hoc sinh  can tim: ";
	cin.ignore();
	getline(cin, msv);
	for (int i = 0; i < HS.size(); i++)
	{
		if (HS.at(i)->getMS() == msv)
		{
			tim = 1;
			cout << endl;
			cout << "\n__________________________________________________________________________________________________________________________________________________________________";
			cout << endl;
			cout << "\nSTT\tHo ten\tMSSV\tNam Sinh\tGioi Tinh\tLop\tDia Chi\tToan\tLy\tHoa\tVan\tDiemTB\tHoc luc";
			cout << "\n"
				 << i + 1;
			HS.at(i)->Xuat();
			cout << endl;
			cout << "\n__________________________________________________________________________________________________________________________________________________________________";
			cout << endl;
			break;
		}
	}

	if (tim == 0)
	{
		cout << "\nMa So khong ton tai !!!";
	}
}
void DanhSach::GhiFile(char *Ttep)
{
	ofstream f;
	f.open(Ttep, ios::app);
	if (f.bad())
	{
		cout << "\nTep " << Ttep << "khong ton tai ";
		cout << "\nCo ghi de ? - C/K";
		int ch = getch();
		if (toupper(ch) == 'C')
		{
			f.close();
			f.open(Ttep);
		}
		else
		{
			exit(1);
		}
	}
	f << setprecision(3) << setiosflags(ios::showpoint);
	f << "__________________________________________________________________________________________________________________________________________________________________";
	f << endl;
	f << "STT" << setw(10) << "ten" << setw(10) << "namsinh" << setw(10) << "maso" << setw(10) << "lop" << setw(12) << "diachi" << setw(12) << "gioitinh" << setw(10) << "diemtoan" << setw(10) << "diemvan" << setw(10) << "diemly" << setw(10) << "diemhoa";
	for (int i = 0; i < HS.size(); ++i)
	{
		f << endl;
		f << i + 1 << setw(12) << HS.at(i)->getTen() << setw(10) << HS.at(i)->getNam() << setw(10) << HS.at(i)->getMS() << setw(10) << HS.at(i)->getLop() << setw(10) << HS.at(i)->getDC() << setw(10) << HS.at(i)->getGT();
		f << setw(10) << HS.at(i)->getToan() << setw(10) << HS.at(i)->getVan() << setw(10) << HS.at(i)->getLy() << setw(10) << HS.at(i)->getHoa();
	}
	f << "\n__________________________________________________________________________________________________________________________________________________________________";
	f.close();
}
void DanhSach::DocFile(char *Ttep)
{
	ifstream f;

	f.open(Ttep);
	if (f.bad())
	{
		cout << "\nTen " << Ttep << "khong ton tai";
		getch();
		exit(1);
	}
	f.ignore();
	for (int i = 0; i < HS.size(); ++i)
	{
		HS.at(i)->getTen();
		HS.at(i)->getNam();
		HS.at(i)->getMS();
		HS.at(i)->getLop();
		HS.at(i)->getDC();
		HS.at(i)->getGT();
		HS.at(i)->getToan();
		HS.at(i)->getVan();
		HS.at(i)->getLy();
		HS.at(i)->getHoa();
		f.ignore();
	}
	f.close();
}

//Ham Main
int main()
{
	DanhSach ds;
	int key;
	while (true)
	{
		cout << endl;
		cout << "              CHUONG TRINH QUAN LY HOC SINH ";
		cout << "\n*************************MENU**************************\n";
		cout << "**  1. Nhap Danh Sach Hoc Sinh                       **\n";
		cout << "**  2. Xuat Danh Sach Hoc Sinh                       **\n";
		cout << "**  3. Xoa Theo Ma So Hoc Sinh                       **\n";
		cout << "**  4. Cap Nhat Thong Tin Hoc Sinh Theo Ma So        **\n";
		cout << "**  5. Sap Xep Hoc Sinh Theo Ma So                   **\n";
		cout << "**  6. Tim Ten Hoc Sinh.                             **\n";
		cout << "**  7. Tim Ma So Hoc Sinh                            **\n";
		cout << "**  8. Ghi Danh Dach Hoc Sinh vao file.              **\n";
		cout << "**  0. Thoat                                         **\n";
		cout << "*******************************************************\n";
		cout << "Nhap tuy chon: ";

		cin >> key;
		if (key > 9 || key < 0)
			continue;
		switch (key)
		{
		case 1:

			cout << " Ban da chon Nhap Danh Sach Hoc Sinh";
			ds.NhapDS();
			break;
		case 2:
			cout << " Ban da chon Xuat Danh Sach Hoc Sinh";
			ds.XuatDS();
			break;
		case 3:
			cout << " Ban da chon Xoa Theo Ma So Hoc Sinh";
			ds.XoaID();
			break;
		case 4:
			cout << " Ban da chon Cap Nhat Hoc Sinh Theo Ma So";
			ds.CapNhat();
			break;
		case 5:
			cout << "Ban da chon Sap Xep Hoc Sinh Theo Ma So";
			ds.SapXepMaSo();
			break;
		case 6:
			cout << "Ban da chon Tim Ten Hoc Sinh";
			ds.TimTen();
			break;
		case 7:
			cout << "Ban da chon Tim Ma So Hoc Sinh";
			ds.TimMaSo();
			break;
		case 8:
			cout << "Ban da chon Ghi Danh Sach Hoc Sinh Vao File";
			cout << endl;
			ds.GhiFile("hocsinh.txt");
			break;
		case 0:
			cout << "\nBan da chon thoat chuong trinh!";
			getch();
			return 0;
		default:
			cout << "\nKhong co chuc nang nay!";
			cout << "\nVui long chon lai phim khac de tiep tuc!\n";
			getch();
			break;
		}
	}
}