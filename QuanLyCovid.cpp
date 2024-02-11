#include <string>
#include <vector>
#include "D:/0.C++/ThuVienTaoSan/Date.h"
void XoaBoDem(){
    while (cin.get() != '\n') {
        continue;
    }
}
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
    friend ostream &operator << (ostream &out, const Person &p){
        return out << p.HoTen << endl
             << p.NgaySinh << endl
             << p.QueQuan << endl
             << p.cccd << endl;
    }
    friend istream &operator >> (istream &in, Person &p){
        cout << "Nhap ten: ";
        getline(in, p.HoTen);
        cout << "Nhap ngay sinh:";
        in >> p.NgaySinh;
        XoaBoDem();
        cout << "Nhap cccd: ";
        in >> p.cccd;
        XoaBoDem();
        cout << "Nhap que quan: ";
        getline(in, p.QueQuan);
        return in;
    }
    
};
class F0 : public Person
{
    Date NgayXetNghiem, NgayBatDauDieuTri, NgayKetThucDieuTri;
    bool KetQuaDieuTri;
    string BenhVien;

public:
    F0(Date NgayXetNghiem = Date(1, 1, 2019), Date NgayBatDauDieuTri = Date(1, 1, 2019), Date NgayKetThucDieuTri = Date(1, 1, 2023), bool KetQuaDieuTri = true, string BenhVien = "Bach Mai") : Person(), NgayXetNghiem(NgayXetNghiem), NgayBatDauDieuTri(NgayBatDauDieuTri), NgayKetThucDieuTri(NgayKetThucDieuTri), KetQuaDieuTri(KetQuaDieuTri), BenhVien(BenhVien) {}
    
    friend ostream &operator <<(ostream &out, const F0 &f0){
        out << static_cast <const Person &>(f0)
        << "Xet nghiem ngay: " << f0.NgayXetNghiem << endl
        << "Dieu tri tu ngay: " << f0.NgayBatDauDieuTri << " den " << f0.NgayKetThucDieuTri << " tai benh vien " << f0.BenhVien
        << "\nKet qua: " << (f0.KetQuaDieuTri ? "duong tinh" : "am tinh");
        return out;
    }
    friend istream &operator<< (istream &in, F0 &f0){
        in >> static_cast<Person &>(f0);
        cout << "Nhap ngay xet nghiem: ";
        in >> f0.NgayXetNghiem;
        cout << "Nhap ngay bat dau dieu tri: ";
        in >> f0.NgayBatDauDieuTri;
        cout << "Nhap ngay ket thuc dieu tri: ";
        in >> f0.NgayKetThucDieuTri;
        cout << "Nhap ngay ket qua dieu tri(1/0): ";
        in >> f0.KetQuaDieuTri;
        XoaBoDem();
        cout << "Nhap benh vien dieu tri: ";
        getline(in, f0.BenhVien);
        return in;
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
       int SoNguoiTiepXuc = 1,
       vector<F0> DanhSachTiepXuc = {F0()}) : Person(),
                                          SoNguoiTiepXuc(SoNguoiTiepXuc),
                                          NgayXetNghiem(NgayXetNghiem), NgayBatDauCachLy(NgayBatDauCachLy),
                                          NgayKetThucCachLy(NgayKetThucCachLy), DiaDiemCachLy(DiaDiemCachLy), KetQuaXetNghiem(KetQuaXetNghiem),
                                          DanhSachTiepXuc(DanhSachTiepXuc) {}

public:
    friend ostream &operator<<(ostream &out, const F1 &f1){
        out << static_cast<const Person &>(f1) << endl
        << "Ket qua xet nghiem: " << (f1.KetQuaXetNghiem ? "duong tinh" : "am tinh")
        << "\nXet nghiem ngay: " << f1.NgayXetNghiem
        << "\nCach ly tu ngay: " << f1.NgayBatDauCachLy << " den ngay " << f1.NgayKetThucCachLy << " tai " << f1.DiaDiemCachLy;
        if (f1.SoNguoiTiepXuc)
        {
            out << "\n\nDa tiep xuc voi " << f1.SoNguoiTiepXuc << " F0: \n";
            for (int i = 0; i < f1.SoNguoiTiepXuc; i++)
            {
                out << f1.DanhSachTiepXuc[i];
                out << endl;
            }
        }
        else
        {
            out << "\nChua tiep xuc voi F0 nao!\n";
        }
        return out;
    }
    friend istream &operator >> (istream &in, F1 &f1){
        in >> static_cast<Person &>(f1);
        cout << "Nhap ngay xet nghiem: ";
        in >> f1.NgayXetNghiem;
        cout << "Nhap ngay bat dau cach ly: ";
        in >> f1.NgayBatDauCachLy;
        cout << "Nhap ngay ket thuc cach ly: ";
        in >> f1.NgayKetThucCachLy;
        XoaBoDem();
        cout << "Nhap dia chi cach ly: ";
        getline(in, f1.DiaDiemCachLy);
        cout << "Nhap ket qua xet nghiem(1/0): ";
        in >> f1.KetQuaXetNghiem;
        cout << "Nhap so nguoi tiep xuc: ";
        in >> f1.SoNguoiTiepXuc;
        XoaBoDem();
        f1.DanhSachTiepXuc.clear();
        for (int i = 0; i < f1.SoNguoiTiepXuc; i++)
        {
            cout << "Nhap nguoi F0 thu " << i + 1 << endl;
            F0 f0;
            cin << f0;
            f1.DanhSachTiepXuc.push_back(f0);
            XoaBoDem();
        }
        return in;
    }
   
};
int main()
{
    F1 quang;
    cin >> quang;
    cout << quang;

    return 0;
}