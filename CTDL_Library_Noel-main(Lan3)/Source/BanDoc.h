#pragma once
#include "Brain.h"

class BanDoc
{
private:
	string _strMaBanDoc;
	string _strHoTen;
	string _strNgayDangKy;
public:
	string getMaBanDoc();
	string getHoTen();
	string getNgayDangKy();
	void setMaBanDoc(string maBanDoc);
	void setHoTen(string hoTen);
	void setNgayDangKy(string ngayDangKy);
	BanDoc();
	BanDoc(string maBanDoc, string hoTen, string ngayDangKy);
};

