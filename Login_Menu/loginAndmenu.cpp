#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <map>
using namespace std;

// ======= Đổi màu chữ =======
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ======= Đọc file và tô màu =======
void printFileWithColor(const string &filename) {
    ifstream f(filename);
    if (!f.is_open()) {
        cout << "Khong the mo file: " << filename << endl;
        return;
    }
    string line;
    while (getline(f, line)) {
        if (line.find("MENU") != string::npos) setColor(14);
        else setColor(7);
        cout << line << endl;
    }
    setColor(7);
    f.close();
}

// ======= Đọc user & password từ file =======
map<string,string> loadCredentials(const string &filename) {
    map<string,string> m;
    ifstream f(filename);
    if (!f.is_open()) return m;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        size_t pos = line.find('=');
        if (pos == string::npos) continue;
        string user = line.substr(0, pos);
        string pass = line.substr(pos + 1);

        // Xóa khoảng trắng đầu và cuối
        auto trim = [](string &s) {
            while (!s.empty() && isspace((unsigned char)s.front())) s.erase(s.begin());
            while (!s.empty() && isspace((unsigned char)s.back())) s.pop_back();
        };
        trim(user);
        trim(pass);
        if (!user.empty()) m[user] = pass;
    }
    f.close();
    return m;
}

// ======= Nhập password có hiện dấu * ngay khi gõ =======
string inputPasswordMasked() {
    string pw;
    char ch;
    while (true) {
        ch = _getch(); // đọc 1 ký tự mà không hiển thị
        if (ch == '\r') { // Enter
            cout << endl;
            break;
        }
        else if (ch == '\b') { // Backspace
            if (!pw.empty()) {
                pw.pop_back();
                cout << "\b \b";
            }
        }
        else if (isprint(ch)) { // nếu là ký tự in được
            pw.push_back(ch);
            setColor(7); // Màu của *
            cout << "*";  // hiển thị sao ngay lập tức
        }
    }
    return pw;
}

// ======= MENU ADMIN =======
void adminMenu() {
    int choice;
    do {
        system("cls");
        printFileWithColor("D:\\C++\\Login_Menu\\menu_admin.txt");

        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                setColor(11);
                cout << "\n[DANH SACH NGUOI DUNG]\n";
                cout << "- user1\n- user2\n- admin\n";
                setColor(7);
                system("pause");
                break;
            case 2:
                setColor(10);
                cout << "\n[THEM NGUOI DUNG]\nNhap ten nguoi dung moi: ";
                {
                    string newUser;
                    getline(cin, newUser);
                    cout << "Nguoi dung \"" << newUser << "\" da duoc them tam thoi.\n";
                }
                setColor(7);
                system("pause");
                break;
            case 3:
                setColor(12);
                cout << "\n[XOA NGUOI DUNG]\nNhap ten nguoi dung can xoa: ";
                {
                    string delUser;
                    getline(cin, delUser);
                    cout << "Nguoi dung \"" << delUser << "\" da bi xoa tam thoi.\n";
                }
                setColor(7);
                system("pause");
                break;
            case 4:
                cout << "\nDang xuat...\n";
                Sleep(1000);
                exit(0);
            default:
                cout << "Lua chon khong hop le.\n";
                Sleep(1000);
                break;
        }
    } while (choice != 8);
}

// ======= MAIN =======
int main() {
    map<string,string> creds = loadCredentials("D:\\C++\\Login_Menu\\admin.txt");
    if (creds.empty()) {
        cout << "Khong the mo file admin.txt hoac file rong!\n";
        return 0;
    }

    printFileWithColor("D:\\C++\\Login_Menu\\login.txt");

    setColor(7);
    cout << "Username: ";
    string user;
    getline(cin, user);

    cout << "Password: ";
    string pass = inputPasswordMasked();
    

    auto it = creds.find(user);
    if (it != creds.end() && it->second == pass) {
        setColor(10);
        cout << "\nDang nhap thanh cong!\n";
        setColor(7);
        Sleep(1000);
        adminMenu();
    } else {
        setColor(12);
        cout << "\nThong tin dang nhap khong dung!\n";
        setColor(7);
    }
    return 0;
}
