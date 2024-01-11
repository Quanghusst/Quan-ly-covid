#include <string>
#include <vector>
#include <iostream>
using namespace std;

void XoaBoDem(){
    while (cin.get() != '\n') {
        continue;
    }
}
class Date
{
    int day, month, year;

public:
    Date(int day = 1, int month = 1, int year = 2000) : day(day), month(month), year(year) {}

public:
    friend istream &operator>>(istream &in, Date &d)
    {
        cout << "\n\tngay: ";
        in >> d.day;
        cout << "\tthang: ";
        in >> d.month;
        cout << "\tnam: ";
        in >> d.year;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Date &d)
    {
        if (d.day < 10)
            out << 0;
        out << d.day << '/';
        if (d.month < 10)
            out << 0;
        out << d.month << '/';
        return out << d.year;
    }
};

class Person
{
protected:
    string cccd;
    string HoTen;
    Date NgaySinh;
    string QueQuan;

public:
    Person(string cccd = "038204008212", string HoTen = "Le Dang Quang", Date NgaySinh = Date(15, 10, 2004), string QueQuan = "Thanh Hoa") : cccd(cccd), HoTen(HoTen), NgaySinh(NgaySinh), QueQuan(QueQuan) {}

public:
    void SetPerson()
    {
        cout << "Nhap ten: ";
        getline(cin, HoTen);
        cout << "Nhap ngay sinh:";
        cin >> NgaySinh;
        XoaBoDem();
        cout << "Nhap cccd: ";
        cin >> cccd;
        XoaBoDem();
        cout << "Nhap que quan: ";
        getline(cin, QueQuan);
    }

    void PrintPerson()
    {
        cout << HoTen << endl
             << NgaySinh << endl
             << QueQuan << endl
             << cccd << endl;
    }
};
class F0 : public Person
{
    Date NgayXetNghiem, NgayBatDauDieuTri, NgayKetThucDieuTri;
    bool KetQuaDieuTri;
    string BenhVien;

public:
    F0(Date NgayXetNghiem = Date(1, 1, 2019), Date NgayBatDauDieuTri = Date(1, 1, 2019), Date NgayKetThucDieuTri = Date(1, 1, 2023), bool KetQuaDieuTri = true, string BenhVien = "Bach Mai") : Person(), NgayXetNghiem(NgayXetNghiem), NgayBatDauDieuTri(NgayBatDauDieuTri), NgayKetThucDieuTri(NgayKetThucDieuTri), KetQuaDieuTri(KetQuaDieuTri), BenhVien(BenhVien) {}
    void SetF0()
    {
        SetPerson();
        cout << "Nhap ngay xet nghiem: ";
        cin >> NgayXetNghiem;
        cout << "Nhap ngay bat dau dieu tri: ";
        cin >> NgayBatDauDieuTri;
        cout << "Nhap ngay ket thuc dieu tri: ";
        cin >> NgayKetThucDieuTri;
        cout << "Nhap ngay ket qua dieu tri(1/0): ";
        cin >> KetQuaDieuTri;
        XoaBoDem();
        cout << "Nhap benh vien dieu tri: ";
        getline(cin, BenhVien);
    }
    void PrintF0()
    {
        PrintPerson();
        cout << "Xet nghiem ngay: " << NgayXetNghiem << endl;
        cout << "Dieu tri tu ngay: " << NgayBatDauDieuTri << " den " << NgayKetThucDieuTri << " tai benh vien " << BenhVien;
        cout << "\nKet qua: " << (KetQuaDieuTri ? "duong tinh" : "am tinh") << endl;
      
    }
};
class F1 : public Person
{
    Date NgayXetNghiem, NgayBatDauCachLy, NgayKetThucCachLy;
    string DiaDiemCachLy;
    vector<F0> DanhSachTiepXuc;
    bool KetQuaXetNghiem;
    int SoNguoiTiepXuc;

public:
    F1(Date NgayXetNghiem = Date(1, 1, 2019),
       Date NgayBatDauCachLy = Date(1, 1, 2019),
       Date NgayKetThucCachLy = Date(1, 1, 2019),
       string DiaDiemCachLy = "Dai hoc Bach Khoa Ha Noi",
       bool KetQuaXetNghiem = true,
       int SoNguoiTiepXuc = 0,
       vector<F0> DanhSachTiepXuc = {}) : Person(),
                                          SoNguoiTiepXuc(SoNguoiTiepXuc),
                                          NgayXetNghiem(NgayXetNghiem), NgayBatDauCachLy(NgayBatDauCachLy),
                                          NgayKetThucCachLy(NgayKetThucCachLy), DiaDiemCachLy(DiaDiemCachLy), KetQuaXetNghiem(KetQuaXetNghiem),
                                          DanhSachTiepXuc(DanhSachTiepXuc) {}

public:
    void PrintF1()
    {
        PrintPerson();
        cout << "Ket qua xet nghiem: " << (KetQuaXetNghiem ? "duong tinh" : "am tinh");
        cout << "\nXet nghiem ngay: " << NgayXetNghiem;
        cout << "\nCach ly tu ngay: " << NgayBatDauCachLy << " den ngay " << NgayKetThucCachLy << " tai " << DiaDiemCachLy;
        if (SoNguoiTiepXuc)
        {
            cout << "\n\nDa tiep xuc voi " << SoNguoiTiepXuc << " F0: \n";
            for (int i = 0; i < SoNguoiTiepXuc; i++)
            {
                DanhSachTiepXuc[i].PrintF0();
                cout << endl;
            }
        }
        else
        {
            cout << "\nChua tiep xuc voi F0 nao!\n";
        }
    }
    void SetF1()
    {
        SetPerson();
        cout << "Nhap ngay xet nghiem: ";
        cin >> NgayXetNghiem;
        cout << "Nhap ngay bat dau cach ly: ";
        cin >> NgayBatDauCachLy;
        cout << "Nhap ngay ket thuc cach ly: ";
        cin >> NgayKetThucCachLy;
        XoaBoDem();
        cout << "Nhap dia chi cach ly: ";
        getline(cin, DiaDiemCachLy);
        cout << "Nhap ket qua xet nghiem(1/0): ";
        cin >> KetQuaXetNghiem;
        cout << "Nhap so nguoi tiep xuc: ";
        cin >> SoNguoiTiepXuc;
        XoaBoDem();
        DanhSachTiepXuc.clear();
        for (int i = 0; i < SoNguoiTiepXuc; i++)
        {
            cout << "Nhap nguoi F0 thu " << i + 1 << endl;
            F0 f0;
            f0.SetF0();
            DanhSachTiepXuc.push_back(f0);
            XoaBoDem();
        }
    }
};
int main()
{
    F1 quang;
    quang.SetF1();
    quang.PrintF1();
    return 0;
}