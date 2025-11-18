#include "PhieuMuon.h"

// Constructor
PhieuMuon::PhieuMuon() 
{
    _strMaPhieu = "";
    _strMaBanDoc = "";
    _strMaSach = "";
    _strNgayMuon = "";
    _strNgayTra = "";
    _iTinhTrang = 1;
}

PhieuMuon::PhieuMuon(string maPhieu, string maBanDoc, string maSach, string ngayMuon, string ngayTra, int tinhTrang) 
{
    _strMaPhieu = maPhieu;
    _strMaBanDoc = maBanDoc;
    _strMaSach = maSach;
    _strNgayMuon = ngayMuon;
    _strNgayTra = ngayTra;
    _iTinhTrang = tinhTrang;
}

// Getters
string PhieuMuon::getMaPhieu() { return _strMaPhieu; }
string PhieuMuon::getMaBanDoc() { return _strMaBanDoc; }
string PhieuMuon::getMaSach() { return _strMaSach; }
string PhieuMuon::getNgayMuon() { return _strNgayMuon; }
string PhieuMuon::getNgayTra() { return _strNgayTra; }
int PhieuMuon::getTinhTrang() { return _iTinhTrang; }

// Setters
void PhieuMuon::setMaPhieu(string maPhieu) { _strMaPhieu = maPhieu; }
void PhieuMuon::setMaBanDoc(string maBanDoc) { _strMaBanDoc = maBanDoc; }
void PhieuMuon::setMaSach(string maSach) { _strMaSach = maSach; }
void PhieuMuon::setNgayMuon(string ngayMuon) { _strNgayMuon = ngayMuon; }
void PhieuMuon::setNgayTra(string ngayTra) { _strNgayTra = ngayTra; }
void PhieuMuon::setTinhTrang(int tinhTrang) { _iTinhTrang = tinhTrang; }
