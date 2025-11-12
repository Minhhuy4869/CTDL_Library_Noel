#include "Sach.h"

// getters
string Sach::getMaSach()
{
	return strMaSach;
}
string Sach::getTenSach()
{
	return strTenSach;
}
string Sach::getTacGia()
{
	return strTacGia;
}
string Sach::getNhaXuatBan()
{
	return strNhaXuatBan;
}
int Sach::getGiaBan()
{
	return iGiaBan;
}
int Sach::getNamPhatHanh()
{
	return iNamPhatHanh;
}
int Sach::getSoTrang()
{
	return iSoTrang;
}
string Sach::getNgayNhapKho()
{
	return strNgayNhapKho;
}
int Sach::getTinhTrang()
{
	return iTinhTrang;
}

// setters
void Sach::setMaSach(string maSach)
{
	strMaSach = maSach;
}
void Sach::setTenSach(string tenSach)
{
	strTenSach = tenSach;
}
void Sach::setTacGia(string tacGia)
{
	strTacGia = tacGia;
}
void Sach::setNhaXuatBan(string nhaXuatBan)
{
	strNhaXuatBan = nhaXuatBan;
}
void Sach::setGiaBan(int giaBan)
{
	iGiaBan = giaBan;
}
void Sach::setNamPhatHanh(int namPhatHanh)
{
	iNamPhatHanh = namPhatHanh;
}
void Sach::setSoTrang(int soTrang)
{
	iSoTrang = soTrang;
}
void Sach::setNgayNhapKho(string ngayNhapKho)
{
	strNgayNhapKho = ngayNhapKho;
}
void Sach::setTinhTrang(int tinhTrang)
{
	iTinhTrang = tinhTrang;
}

// Ham khoi tao Sach moi
Sach::Sach()
{
	strMaSach = "";
	strTenSach = "";
	strTacGia = "";
	strNhaXuatBan = "";
	iGiaBan = 0;
	iNamPhatHanh = 0;
	iSoTrang = 0;
	strNgayNhapKho = "";
	iTinhTrang = 0;
}

// Ham khoi tao Sach co tham so
Sach::Sach(string maSach, string tenSach, string tacGia, string nhaXuatBan, int giaBan, 
			int namPhatHanh, int soTrang, string ngayNhapKho, int tinhTrang)
{
	strMaSach = maSach;
	strTenSach = tenSach;
	strTacGia = tacGia;
	strNhaXuatBan = nhaXuatBan;
	iGiaBan = giaBan;
	iNamPhatHanh = namPhatHanh;
	iSoTrang = soTrang;
	strNgayNhapKho = ngayNhapKho;
	iTinhTrang = tinhTrang;
}