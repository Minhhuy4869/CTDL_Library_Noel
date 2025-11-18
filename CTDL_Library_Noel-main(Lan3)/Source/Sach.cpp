#include "Sach.h"

// getters
string Sach::getMaSach()
{
	return _strMaSach;
}
string Sach::getTenSach()
{
	return _strTenSach;
}
string Sach::getTacGia()
{
	return _strTacGia;
}
string Sach::getNhaXuatBan()
{
	return _strNhaXuatBan;
}
int Sach::getGiaBan()
{
	return _iGiaBan;
}
int Sach::getNamPhatHanh()
{
	return _iNamPhatHanh;
}
int Sach::getSoTrang()
{
	return _iSoTrang;
}
string Sach::getNgayNhapKho()
{
	return _strNgayNhapKho;
}
int Sach::getTinhTrang()
{
	return _iTinhTrang;
}

// setters
void Sach::setMaSach(string maSach)
{
	_strMaSach = maSach;
}
void Sach::setTenSach(string tenSach)
{
	_strTenSach = tenSach;
}
void Sach::setTacGia(string tacGia)
{
	_strTacGia = tacGia;
}
void Sach::setNhaXuatBan(string nhaXuatBan)
{
	_strNhaXuatBan = nhaXuatBan;
}
void Sach::setGiaBan(int giaBan)
{
	_iGiaBan = giaBan;
}
void Sach::setNamPhatHanh(int namPhatHanh)
{
	_iNamPhatHanh = namPhatHanh;
}
void Sach::setSoTrang(int soTrang)
{
	_iSoTrang = soTrang;
}
void Sach::setNgayNhapKho(string ngayNhapKho)
{
	_strNgayNhapKho = ngayNhapKho;
}
void Sach::setTinhTrang(int tinhTrang)
{
	_iTinhTrang = tinhTrang;
}

// Ham khoi tao Sach moi
Sach::Sach()
{
	_strMaSach = "";
	_strTenSach = "";
	_strTacGia = "";
	_strNhaXuatBan = "";
	_iGiaBan = 0;
	_iNamPhatHanh = 0;
	_iSoTrang = 0;
	_strNgayNhapKho = "";
	_iTinhTrang = 0;
}

// Ham khoi tao Sach co tham so
Sach::Sach(string maSach, string tenSach, string tacGia, string nhaXuatBan, int giaBan, 
			int namPhatHanh, int soTrang, string ngayNhapKho, int tinhTrang)
{
	_strMaSach = maSach;
	_strTenSach = tenSach;
	_strTacGia = tacGia;
	_strNhaXuatBan = nhaXuatBan;
	_iGiaBan = giaBan;
	_iNamPhatHanh = namPhatHanh;
	_iSoTrang = soTrang;
	_strNgayNhapKho = ngayNhapKho;
	_iTinhTrang = tinhTrang;
}
