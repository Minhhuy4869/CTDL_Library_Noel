#include "Brain.h"

//--------------------------------------------------------------------------------------
// NHÓM HÀM XỬ LÝ GIAO DIỆN CONSOLE
//--------------------------------------------------------------------------------------

/********************************************
- Chuc nang: Ham doi mau chu console
- Tham so  : Ma mau muon doi (int color)
********************************************/
void setColor(int color)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

/********************************************
- Chuc nang: Ham doi mau background va mau chu
- Tham so  : Ma mau nen (int backgound_color), Ma mau chu (int text_color)
********************************************/
void setColor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}

/********************************************
- Chuc nang: Ham hien thi hieu ung loading
- Tham so  : So giay delay moi lan lap (int sleep), So lan chay thanh loading (int n)
********************************************/
void loading(int sleep, int n) {
	setColor(0, 6);
	cout << "\n\n\n\n\t\t\t\t\tDANG THUC HIEN...\n\t\t";
	for (int i = 0; i < n; i++) {
		cout << "|";
		Sleep(sleep);
	}
	setColor(7);
}


//--------------------------------------------------------------------------------------
// NHÓM HÀM XỬ LÝ NGÀY THÁNG VÀ THỜI GIAN
//--------------------------------------------------------------------------------------

/********************************************
- Chuc nang: Ham tra ve timestamp hien tai
- Gia tri tra ve: Timestamp hien tai (long)
********************************************/
long getTimeNow()
{
	time_t now = time(0);
	return now;
}

/********************************************
- Chuc nang: Ham chuyen doi ngay thang sang timestamp
- Tham so  : Ngay (int day), thang (int month), nam (int year), gio (int hour = 0), phut (int min = 0), giay (int sec = 0)
- Gia tri tra ve: Timestamp cua ngay thang do (long)
********************************************/
long convertDateToTimestamp(int day, int month, int year,
	int hour = 0, int min = 0, int sec = 0) 
{
	struct tm tm;
	time_t rawtime;
	time(&rawtime);
	tm = *localtime(&rawtime);

	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_hour = hour;
	tm.tm_min = min;
	tm.tm_sec = sec;
	tm.tm_mday = day;

	return mktime(&tm);
}

/********************************************
- Chuc nang: Ham lay ngay thang gio hien tai
- Gia tri tra ve: Chuoi ngay thang gio hien tai (string)
********************************************/
string getCurrentDate() {
	string result = "";
	time_t now = time(0);
	tm* ltm = localtime(&now);
	string day, month, year, hour, min;

	stringstream days, months, years, hours, mins;

	days << ltm->tm_mday; days >> day;
	months << (1 + ltm->tm_mon); months >> month;
	years << (1900 + ltm->tm_year); years >> year;
	hours << ltm->tm_hour; hours >> hour;
	mins << ltm->tm_min; mins >> min;

	if (1 + ltm->tm_mon < 10) { month = "0" + month; }
	if (ltm->tm_mday < 10) { day = "0" + day; }
	if (ltm->tm_hour < 10) { hour = "0" + hour; }
	if (ltm->tm_min < 10) { min = "0" + min; }

	result = day + "/" + month + "/" + year + " " + hour + ":" + min;
	return result;
}

//--------------------------------------------------------------------------------------
// NHÓM HÀM XỬ LÝ CHUỖI VÀ INPUT
//--------------------------------------------------------------------------------------

/********************************************
- Chuc nang: Ham chuyen chuoi thanh UpperCase va xoa tat ca khoang trang
- Tham so  : Chuoi can chuyen (string x)
- Gia tri tra ve: Chuoi sau khi chuyen (string)
********************************************/
string convertUpperCaseAndDeleteSpace(string x) 
{
	string result = "";
	for (char c : x) 
	{
		if (c >= 'a' && c <= 'z') 
		{
			c -= 32;
		}
		if (c != ' ') 
		{
			result += c;
		}
	}
	return result;
}

/********************************************
- Chuc nang: Ham chuyen chuoi thanh UpperCase
- Tham so  : Chuoi can chuyen (string x)
- Gia tri tra ve: Chuoi sau khi chuyen (string)
********************************************/
string convertUpperCase(string x) 
{
	for (char& c : x) 
	{
		if (c >= 'a' && c <= 'z') 
		{
			c -= 32;
		}
	}
	return x;
}

/********************************************
- Chuc nang: Ham ma hoa chuoi thanh dau "*" khi nhap lieu
- Tham so  : Do dai toi da cua chuoi (int maxLength)
- Gia tri tra ve: Chuoi goc (string)
********************************************/
string passwordInput(int maxLength) 
{
	string pw = "";
	for (char c; (c = getch()); )
	{
		if (c == '\n' || c == '\r') 
		{
			cout << "\n";
			break;
		}
		else if (c == '\b') 
		{
			if (!pw.empty()) 
			{
				pw.pop_back();
				cout << "\b \b";
			}
		}
		else if (isprint(c) && pw.size() < maxLength) 
		{
			cout << '*';
			pw += c;
		}
	}
	return pw;
}

/********************************************
- Chuc nang: Ham kiem tra chuoi co chua khoang trang hay khong
- Tham so  : Chuoi can kiem tra (string s)
- Gia tri tra ve: True neu co khoang trang, False neu khong (bool)
********************************************/
bool checkContainsSpacing(string s) 
{
	for (char c : s) 
	{
		if (c == ' ') 
		{
			return true;
		}
	}
	return false;
}

/********************************************
- Chuc nang: Ham kiem tra chuoi co phai la chuoi so hay khong
- Tham so  : Chuoi can kiem tra (string s)
- Gia tri tra ve: True neu chuoi chi toan so, False neu co ki tu khac (bool)
********************************************/
bool checkIsNumberString(string s) 
{
	for (char c : s) {
		if (c < '0' || c > '9') {
			return false;
		}
	}
	return true;
}


//--------------------------------------------------------------------------------------
// NHÓM HÀM MENU CHÍNH & ADMIN
//--------------------------------------------------------------------------------------

/********************************************
- Chuc nang: Ham hien thi menu chuc nang chinh
********************************************/
void menuChucNang() {
	setColor(2);
	cout << "\t\t\t\t\t";
	cout << "MENU CHUC NANG THU VIEN:" << endl;
	setColor(14);
	cout << setfill('=') << "\t\t\t" << setw(50) << "=" << endl;
	cout << setfill(' ');

	cout << "\t\t\t | \t" << "1. Hien thi danh sach sach. " << "\t\t\t |" << endl;
	cout << "\t\t\t | \t" << "2. Muon sach (Tao phieu muon). " << "\t\t |" << endl;
	cout << "\t\t\t | \t" << "3. Quan ly Thu vien (Dang nhap). " << "\t\t |" << endl;
	cout << "\t\t\t | \t" << "0. Thoat chuong trinh. " << "\t\t\t |" << endl;

	setColor(14);
	cout << setfill('=') << "\t\t\t" << setw(50) << "=" << endl;
	setColor(4);
	cout << "\t\t\t\t Nhap thao tac muon chon: ";
	setColor(7);
}

/********************************************
- Chuc nang: Ham hien thi menu dang nhap nhan vien
- Tham so  : Chuoi username (string& username), Chuoi password (string& password)
********************************************/
void dangNhapNhanVien (string &user, string &password) 
{
	// Giữ nguyên logic này để nhập liệu cho user/password
	// ... (code không thay đổi)
	cin.ignore();
	setColor(14);
	cout << setfill('*') << "\t\t\t" << setw(60) << "*" << endl;
	setColor(2);
	cout << "\t\t\t* \t\t DANG NHAP HE THONG QUAN LY THU VIEN \t\t *" << endl;
	setColor(14);
	cout << setfill('*') << "\t\t\t" << setw(60) << "*" << endl;
	setColor(7);

	setColor(2); cout << "\t\t\t" << "     User";
	setColor(7); cout << ":     ";
	getline(cin, user);
	cout << endl;

	setColor(2); cout << "\t\t\t" << "     Password";
	setColor(7); cout << ": ";
	password = passwordInput(10);
}

/********************************************
- Chuc nang: Ham hien thi menu chuc nang cua nhan vien (Level 2)
********************************************/
void menuNhanVien()
{
	setColor(2);
	cout << "\t\t\t\t\t";
	cout << "MENU QUAN LY THU VIEN:" << endl;
	setColor(14);
	cout << setfill('=') << "\t\t\t" << setw(50) << "=" << endl;
	cout << setfill(' ');

	cout << "\t\t\t | \t" << "1. Quan ly SACH. " << "\t\t\t\t |" << endl;
	cout << "\t\t\t | \t" << "2. Quan ly PHIEU MUON. " << "\t\t\t |" << endl;
	cout << "\t\t\t | \t" << "3. Thong ke. " << "\t\t\t\t |" << endl;
	cout << "\t\t\t | \t" << "0. Quay lai. " << "\t\t\t\t |" << endl;

	setColor(14);
	cout << setfill('=') << "\t\t\t" << setw(50) << "=" << endl;
	setColor(4);
	cout << "\t\t\t\t Moi nhan vien chon thao tac: ";
	setColor(7);
}

/********************************************
- Chuc nang: Ham hien thi menu chuc nang thong ke cua nhan vien (Level 3 - Thong Ke)
********************************************/
void menuAdminThongKe() 
{
	setColor(2);
	cout << "\t\t\t\t\t";
	cout << "MENU THONG KE THU VIEN:" << endl;
	setColor(14);
	cout << setfill('=') << "\t\t\t" << setw(65) << "=" << endl;
	cout << setfill(' ');

	cout << "\t\t\t | \t" << "1. Thong ke chi tiet theo Ma Sach. " << "\t\t\t |" << endl;
	cout << "\t\t\t | \t" << "2. Thong ke so luong sach con/dang muon. " << "\t\t |" << endl;
	cout << "\t\t\t | \t" << "0. Quay lai. " << "\t\t\t\t\t\t |" << endl;

	setColor(14);
	cout << setfill('=') << "\t\t\t" << setw(65) << "=" << endl;
	setColor(4);
	cout << "\t\t\t\t Nhap thao tac muon chon: ";
	setColor(7);
}

//--------------------------------------------------------------------------------------
// NHÓM HÀM MENU CON (LEVEL 3) - BỔ SUNG THEO YÊU CẦU
//--------------------------------------------------------------------------------------

/********************************************
- Chuc nang: Ham hien thi menu quan ly sach (Level 3)
********************************************/
void menuQuanLySach() 
{
	setColor(10);
	cout << "\t\t\t\t\t\t";
	cout << "MENU QUAN LY SACH:" << endl;
	setColor(14);
	cout << setfill('=') << "\t\t\t" << setw(60) << "=" << endl;
	cout << setfill(' ');

	cout << "\t\t\t | \t" << "1. Hien thi tat ca sach. " << "\t\t\t\t |" << endl; // Yeu cau: Hien thi thong tin sach
	cout << "\t\t\t | \t" << "2. Them sach moi. " << "\t\t\t\t |" << endl; // Yeu cau: Them sach
	cout << "\t\t\t | \t" << "3. Xoa sach (tinh trang = 0). " << "\t\t\t |" << endl; // Yeu cau: Xoa sach
	cout << "\t\t\t | \t" << "0. Quay lai Menu Nhan Vien. " << "\t\t\t |" << endl;

	setColor(14);
	cout << setfill('=') << "\t\t\t" << setw(60) << "=" << endl;
	setColor(4);
	cout << "\t\t\t\t Nhap thao tac muon chon: ";
	setColor(7);
}

/********************************************
- Chuc nang: Ham hien thi menu quan ly phieu muon (Level 3)
********************************************/
void menuQuanLyPhieuMuon() 
{
	setColor(10);
	cout << "\t\t\t\t\t\t";
	cout << "MENU QUAN LY PHIEU MUON:" << endl;
	setColor(14);
	cout << setfill('=') << "\t\t\t" << setw(60) << "=" << endl;
	cout << setfill(' ');

	cout << "\t\t\t | \t" << "1. Hien thi tat ca phieu muon. " << "\t\t\t |" << endl; // Yeu cau: Hien thi thong tin cac PM
	cout << "\t\t\t | \t" << "2. Tao phieu MUON SACH. " << "\t\t\t |" << endl; // Yeu cau: Muon sach
	cout << "\t\t\t | \t" << "3. Xu ly TRA SACH. " << "\t\t\t\t |" << endl; // Yeu cau: Tra sach
	cout << "\t\t\t | \t" << "0. Quay lai Menu Nhan Vien. " << "\t\t\t |" << endl;

	setColor(14);
	cout << setfill('=') << "\t\t\t" << setw(60) << "=" << endl;
	setColor(4);
	cout << "\t\t\t\t Nhap thao tac muon chon: ";
	setColor(7);
}