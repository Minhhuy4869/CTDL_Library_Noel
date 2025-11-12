#pragma once
#include <string>
using namespace std;

class PhieuMuon {
private:
    string strMaPhieu;
    string strMaBanDoc;
    string strMaSach;
    string strNgayMuon;
    string strNgayTra;
    int iTinhTrang; // 1: đang mượn, 0: đã trả

public:
    // Constructor
    PhieuMuon();
    PhieuMuon(string maPhieu, string maBanDoc, string maSach, string ngayMuon, string ngayTra, int tinhTrang);

    // Getters
    string getMaPhieu();
    string getMaBanDoc();
    string getMaSach();
    string getNgayMuon();
    string getNgayTra();
    int getTinhTrang();

    // Setters
    void setMaPhieu(string maPhieu);
    void setMaBanDoc(string maBanDoc);
    void setMaSach(string maSach);
    void setNgayMuon(string ngayMuon);
    void setNgayTra(string ngayTra);
    void setTinhTrang(int tinhTrang);
};
