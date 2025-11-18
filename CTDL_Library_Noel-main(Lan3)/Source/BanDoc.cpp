#include "BanDoc.h"

// getters
string BanDoc::getMaBanDoc()
{
	return _strMaBanDoc;
}
string BanDoc::getHoTen()
{
	return _strHoTen;
}
string BanDoc::getNgayDangKy()
{
	return _strNgayDangKy;
}
//setters
void BanDoc::setMaBanDoc(string maBanDoc)
{
	_strMaBanDoc = maBanDoc;
}
void BanDoc::setHoTen(string hoTen)
{
	_strHoTen = hoTen;
}
void BanDoc::setNgayDangKy(string ngayDangKy)
{
	_strNgayDangKy = ngayDangKy;
}
// constructor
// Khoi tao BanDoc mac dinh
BanDoc::BanDoc()
{
	_strMaBanDoc = "";
	_strHoTen = "";
	_strNgayDangKy = "";
}
// Khoi tao BanDoc co tham so
BanDoc::BanDoc(string maBanDoc, string hoTen, string ngayDangKy)
{
	_strMaBanDoc = maBanDoc;
	_strHoTen = hoTen;
	_strNgayDangKy = ngayDangKy;
}
