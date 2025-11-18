#pragma once
#include "Brain.h"

class NhanVien
{
private:
	string _strUser;
	string _strPassWord;
public:
	// getters
	string getUser();
	string getPassWord();
	// setters
	void setUser(string User);
	void setPassWord(string PassWord);
	// constructor
	// Khoi tao NhanVien mac dinh
	NhanVien();
	// Khoi tao NhanVien co tham so
	NhanVien(string User, string PassWord);

};
