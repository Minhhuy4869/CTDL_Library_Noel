#pragma once
#include "Brain.h"

class NhanVien
{
private:
	string _strUser;
	string _strPassWord;
public:
	string getUser();
	string getPassWord();
	void setUser(string User);
	void setPassWord(string PassWord);
	NhanVien();
	NhanVien(string User, string PassWord);
};
