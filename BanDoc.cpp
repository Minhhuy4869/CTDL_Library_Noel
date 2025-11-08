#include <BanDoc.h>

// getters
string getMaBanDoc()
{
	return strMaBanDoc;
}
string getHoTen()
{
	return strHoTen;
}
string getNgayDangKy()
{
	return strNgayDangKy;
}
//setters
void setMaBanDoc(string maBanDoc)
{
	strMaBanDoc = maBanDoc;
}
void setHoTen(string hoTen)
{
	strHoTen = hoTen;
}
void setNgayDangKy(string ngayDangKy)
{
	strNgayDangKy = ngayDangKy;
}
// constructor
// Khoi tao BanDoc mac dinh
BanDoc()
{
	strMaBanDoc = "";
	strHoTen = "";
	strNgayDangKy = "";
}
// Khoi tao BanDoc co tham so
BanDoc(string maBanDoc, string hoTen, string ngayDangKy)
{
	strMaBanDoc = maBanDoc;
	strHoTen = hoTen;
	strNgayDangKy = ngayDangKy;
}