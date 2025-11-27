#pragma once
#include "Brain.h"

class Sach
{
private:
	string _strMaSach;
	string _strTenSach;
	string _strTacGia;
	string _strNhaXuatBan;
	int _iGiaBan;
	int _iNamPhatHanh;
	int _iSoTrang;
	string _strNgayNhapKho;
	int _iTinhTrang;
public:
	string getMaSach();
	string getTenSach();
	string getTacGia();
	string getNhaXuatBan();
	int getGiaBan();
	int getNamPhatHanh();
	int getSoTrang();
	string getNgayNhapKho();
	int getTinhTrang();
	void setMaSach(string maSach);
	void setTenSach(string tenSach);
	void setTacGia(string tacGia);
	void setNhaXuatBan(string nhaXuatBan);
	void setGiaBan(int giaBan);
	void setNamPhatHanh(int namPhatHanh);
	void setSoTrang(int soTrang);
	void setNgayNhapKho(string ngayNhapKho);
	void setTinhTrang(int tinhTrang);
	Sach();
	Sach(string maSach, string tenSach, string tacGia, string nhaXuatBan
		, int giaBan, int namPhatHanh, int soTrang, string ngayNhapKho, int tinhTrang);
};
