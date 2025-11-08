#pragma once
#include <Brain.h>

class PhieuMuon
{
private:
	int iSoPhieuMuon;
	string strMaBanDoc;
	string strMaSach;
	string strNgayMuon;
public:
	//getters
	int getSoPhieuMuon();
	string getMaBanDoc();
	string getMaSach();
	string getNgayMuon();
	//setters
	void setSoPhieuMuon(int soPhieuMuon);
	void setMaBanDoc(string maBanDoc);
	void setMaSach(string maSach);
	void setNgayMuon(string ngayMuon);
	// constructor
	// Khoi tao PhieuMuon mac dinh
	PhieuMuon();
	// Khoi tao PhieuMuon co tham so
	PhieuMuon(int soPhieuMuon, string maBanDoc, string maSach, string ngayMuon);
};