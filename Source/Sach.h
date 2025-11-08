#pragma once
#include <Brain.h>

class Sach
{
private:
	string strMaSach;
	string strTenSach;
	string strTacGia;
	string strNhaXuatBan;
	int iGiaBan;
	int iNamPhatHanh;
	int iSoTrang;
	string strNgayNhapKho;
	int iTinhTrangSach;
public:
	// getters
	string getMaSach();
	string getTenSach();
	string getTacGia();
	string getNhaXuatBan();
	int getGiaBan();
	int getNamPhatHanh();
	int getSoTrang();
	string getNgayNhapKho();
	int getTinhTrang();
	// setters
	void setMaSach(string maSach);
	void setTenSach(string tenSach);
	void setTacGia(string tacGia);
	void setNhaXuatBan(string nhaXuatBan);
	void setGiaBan(int giaBan);
	void setNamPhatHanh(int namPhatHanh);
	void setSoTrang(int soTrang);
	void setNgayNhapKho(string ngayNhapKho);
	void setTinhTrang(int tinhTrang);
	// constructor
	// Khoi tao Sach mac dinh
	Sach();
	// Khoi tao Sach co tham so
	Sach(string maSach, string tenSach, string tacGia, string nhaXuatBan
		, int giaBan, int namPhatHanh, int soTrang, string ngayNhapKho, int tinhTrang);
};