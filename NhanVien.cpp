#include <NhanVien.h>

// getters
string getUser()
{
	return strUser;
}
string getPassWord()
{
	return strPassWord;
}
// setters
void setUser(string User)
{
	strUser = User;
}
void setPassWord(string PassWord)
{
	strPassWord = PassWord;
}
// constructor
// Khoi tao NhanVien mac dinh
NhanVien();
// Khoi tao NhanVien co tham so
NhanVien(string User, string PassWord)
{
	strUser = User;
	strPassWord = PassWord;
}