#include <PhieuMuon.h>

//getters
int getSoPhieuMuon()
{
	return iSoPhieuMuon;
}
string getMaBanDoc()
{
	return strMaBanDoc;
}
string getMaSach()
{
	return strMaSach;
}
string getNgayMuon()
{
	return strNgayMuon;
}
//setters
void setSoPhieuMuon(int soPhieuMuon)
{
	iSoPhieuMuon = soPhieuMuon;
}
void setMaBanDoc(string maBanDoc)
{
	strMaBanDoc = maBanDoc;
}
void setMaSach(string maSach)
{
	strMaSach = maSach;
}
void setNgayMuon(string ngayMuon)
{
	strNgayMuon = ngayMuon;
}
// constructor
// Khoi tao PhieuMuon mac dinh
PhieuMuon::PhieuMuon()
{
	iSoPhieuMuon = 0;
	strMaBanDoc = "";
	strMaSach = "";
	strNgayMuon = "";
}
// Khoi tao PhieuMuon co tham so
PhieuMuon::PhieuMuon(int soPhieuMuon, string maBanDoc, string maSach, string ngayMuon)
{
	iSoPhieuMuon = soPhieuMuon;
	strMaBanDoc = maBanDoc;
	strMaSach = maSach;
	strNgayMuon = ngayMuon;
}