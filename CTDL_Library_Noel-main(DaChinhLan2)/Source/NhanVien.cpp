#include "NhanVien.h"

// getters
string NhanVien::getUser() {
    return strUser;
}
string NhanVien::getPassWord() {
    return strPassWord;
}

// setters
void NhanVien::setUser(string User) {
    strUser = User;
}
void NhanVien::setPassWord(string PassWord) {
    strPassWord = PassWord;
}

// constructor
NhanVien::NhanVien() {  // mặc định
    strUser = "";
    strPassWord = "";
}

NhanVien::NhanVien(string User, string PassWord) { // có tham số
    strUser = User;
    strPassWord = PassWord;
}
