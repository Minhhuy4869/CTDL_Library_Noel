#pragma once
class BanDoc
{
private:
	string strMaBanDoc;
	string strHoTen;
	string strNgayDangKy;
public:
	// getters
	string getMaBanDoc();
	string getHoTen();
	string getNgayDangKy();
	//setters
	void setMaBanDoc(string maBanDoc);
	void setHoTen(string hoTen);
	void setNgayDangKy(string ngayDangKy);
	// constructor
	// Khoi tao BanDoc mac dinh
	BanDoc();
	// Khoi tao BanDoc co tham so
	BanDoc(string maBanDoc, string hoTen, string ngayDangKy);
};