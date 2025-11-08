#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <conio.h>

using namespace std;

//--------------------------------------------------------------------------------------
// NHÓM HÀM XỬ LÝ GIAO DIỆN CONSOLE
//--------------------------------------------------------------------------------------

void setColor (int color);
void setColor (int backgound_color, int text_color);
void loading (int sleep, int n);

//--------------------------------------------------------------------------------------
// NHÓM HÀM XỬ LÝ NGÀY THÁNG VÀ THỜI GIAN
//--------------------------------------------------------------------------------------

long getTimeNow();
long convertDateToTimestamp (int day, int month, int year, int hour = 0, int min = 0, int sec = 0);
string getCurrentDate();

//--------------------------------------------------------------------------------------
// NHÓM HÀM XỬ LÝ CHUỖI VÀ INPUT
//--------------------------------------------------------------------------------------

string convertUpperCaseAndDeleteSpace (string x);
string convertUpperCase (string x);
string passwordInput (int maxLength);
bool checkContainsSpacing (string s);
bool checkIsNumberString (string s);

//--------------------------------------------------------------------------------------
// NHÓM HÀM MENU
//--------------------------------------------------------------------------------------

void menuChucNang();        // Menu Chính (Level 1)
void dangNhapNhanVien (string& user, string& password); // Form Đăng nhập
void menuNhanVien();        // Menu Quản lý Thư viện (Level 2)
void menuAdminThongKe();    // Menu Thống kê (Level 3 - Con của Level 2)
void menuQuanLySach();      // Menu Quản lý Sách (Level 3 - Con của Level 2)
void menuQuanLyPhieuMuon(); // Menu Quản lý Phiếu Mượn (Level 3 - Con của Level 2)