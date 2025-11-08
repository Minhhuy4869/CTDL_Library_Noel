#include <NhanVien.h>

// getters
string NhanVien::getUser()
{
	return strUser;
}
string NhanVien::getPassWord()
{
	return strPassWord;
}
// setters
void NhanVien::setUser(string User)
{
	strUser = User;
}
void NhanVien::setPassWord(string PassWord)
{
	strPassWord = PassWord;
}
// constructor
// Khoi tao NhanVien mac dinh
NhanVien::NhanVien();
// Khoi tao NhanVien co tham so
NhanVien::NhanVien(string User, string PassWord)
{
	strUser = User;
	strPassWord = PassWord;
}