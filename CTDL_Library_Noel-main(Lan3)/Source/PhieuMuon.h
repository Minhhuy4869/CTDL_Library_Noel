#pragma once
#include <string>
using namespace std;

class PhieuMuon 
{
private:
    string _strMaPhieu;
    string _strMaBanDoc;
    string _strMaSach;
    string _strNgayMuon;
    string _strNgayTra;
    int _iTinhTrang; // 1: đang mượn, 0: đã trả
public:
    PhieuMuon();
    PhieuMuon(string maPhieu, string maBanDoc, string maSach, string ngayMuon, string ngayTra, int tinhTrang);
    string getMaPhieu();
    string getMaBanDoc();
    string getMaSach();
    string getNgayMuon();
    string getNgayTra();
    int getTinhTrang();
    void setMaPhieu(string maPhieu);
    void setMaBanDoc(string maBanDoc);
    void setMaSach(string maSach);
    void setNgayMuon(string ngayMuon);
    void setNgayTra(string ngayTra);
    void setTinhTrang(int tinhTrang);
};
