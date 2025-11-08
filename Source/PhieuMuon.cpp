#include <PhieuMuon.h>

//getters
int PhieuMuon::getSoPhieuMuon()
{
	return iSoPhieuMuon;
}
string PhieuMuon::getMaBanDoc()
{
	return strMaBanDoc;
}
string PhieuMuon::getMaSach()
{
	return strMaSach;
}
string PhieuMuon::getNgayMuon()
{
	return strNgayMuon;
}
//setters
void PhieuMuon::setSoPhieuMuon(int soPhieuMuon)
{
	iSoPhieuMuon = soPhieuMuon;
}
void PhieuMuon::setMaBanDoc(string maBanDoc)
{
	strMaBanDoc = maBanDoc;
}
void PhieuMuon::setMaSach(string maSach)
{
	strMaSach = maSach;
}
void PhieuMuon::setNgayMuon(string ngayMuon)
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