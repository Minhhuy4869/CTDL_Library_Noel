#include <BanDoc.h>

// getters
string BanDoc::getMaBanDoc()
{
	return strMaBanDoc;
}
string BanDoc::getHoTen()
{
	return strHoTen;
}
string BanDoc::getNgayDangKy()
{
	return strNgayDangKy;
}
//setters
void BanDoc::setMaBanDoc(string maBanDoc)
{
	strMaBanDoc = maBanDoc;
}
void BanDoc::setHoTen(string hoTen)
{
	strHoTen = hoTen;
}
void BanDoc::setNgayDangKy(string ngayDangKy)
{
	strNgayDangKy = ngayDangKy;
}
// constructor
// Khoi tao BanDoc mac dinh
BanDoc::BanDoc()
{
	strMaBanDoc = "";
	strHoTen = "";
	strNgayDangKy = "";
}
// Khoi tao BanDoc co tham so
BanDoc::BanDoc(string maBanDoc, string hoTen, string ngayDangKy)
{
	strMaBanDoc = maBanDoc;
	strHoTen = hoTen;
	strNgayDangKy = ngayDangKy;
}