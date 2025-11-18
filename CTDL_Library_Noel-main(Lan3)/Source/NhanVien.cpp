#include "NhanVien.h"

// getters
string NhanVien::getUser() 
{
    return _strUser;
}
string NhanVien::getPassWord() 
{
    return _strPassWord;
}

// setters
void NhanVien::setUser(string User) 
{
    _strUser = User;
}
void NhanVien::setPassWord(string PassWord) 
{
    _strPassWord = PassWord;
}

// constructor
NhanVien::NhanVien() 
{  // mặc định
    _strUser = "";
    _strPassWord = "";
}

NhanVien::NhanVien(string User, string PassWord) 
{ // có tham số
    _strUser = User;
    _strPassWord = PassWord;
}

