#include "PhieuMuon.h"

// Constructor
PhieuMuon::PhieuMuon() {
    strMaPhieu = "";
    strMaBanDoc = "";
    strMaSach = "";
    strNgayMuon = "";
    strNgayTra = "";
    iTinhTrang = 1;
}

PhieuMuon::PhieuMuon(string maPhieu, string maBanDoc, string maSach, string ngayMuon, string ngayTra, int tinhTrang) {
    strMaPhieu = maPhieu;
    strMaBanDoc = maBanDoc;
    strMaSach = maSach;
    strNgayMuon = ngayMuon;
    strNgayTra = ngayTra;
    iTinhTrang = tinhTrang;
}

// Getters
string PhieuMuon::getMaPhieu() { return strMaPhieu; }
string PhieuMuon::getMaBanDoc() { return strMaBanDoc; }
string PhieuMuon::getMaSach() { return strMaSach; }
string PhieuMuon::getNgayMuon() { return strNgayMuon; }
string PhieuMuon::getNgayTra() { return strNgayTra; }
int PhieuMuon::getTinhTrang() { return iTinhTrang; }

// Setters
void PhieuMuon::setMaPhieu(string maPhieu) { strMaPhieu = maPhieu; }
void PhieuMuon::setMaBanDoc(string maBanDoc) { strMaBanDoc = maBanDoc; }
void PhieuMuon::setMaSach(string maSach) { strMaSach = maSach; }
void PhieuMuon::setNgayMuon(string ngayMuon) { strNgayMuon = ngayMuon; }
void PhieuMuon::setNgayTra(string ngayTra) { strNgayTra = ngayTra; }
void PhieuMuon::setTinhTrang(int tinhTrang) { iTinhTrang = tinhTrang; }
