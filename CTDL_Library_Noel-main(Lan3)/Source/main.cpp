#include "iostream"
#include "vector"
#include "string"
#include "fstream"
#include "sstream"
#include "conio.h"
#include "windows.h"
#include "ctime"

#include "NhanVien.h"
#include "BanDoc.h"
#include "Sach.h"
#include "PhieuMuon.h"

using namespace std;

// ===== Hàm đổi màu chữ =====
void textColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ===== Hàm di chuyển con trỏ =====
void gotoxy(int x, int y) {
    COORD coord = {short(x), short(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// ===== Hàm tách chuỗi =====
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(str);
    while (getline(ss, token, delimiter)) tokens.push_back(token);
    return tokens;
}

// ===== Hàm nhập password =====
string inputPassword() {
    string pass;
    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == 27) return "ESC";
        if (ch == '\b') {
            if (!pass.empty()) { pass.pop_back(); cout << "\b \b"; }
        } else { pass.push_back(ch); cout << '*'; }
    }
    cout << endl;
    return pass;
}

// ===== Đọc danh sách nhân viên =====
vector<NhanVien> docDanhSachNhanVien() {
    vector<NhanVien> ds;
    ifstream file("Admin.txt");
    if (!file.is_open()) return ds;
    string line;
    while (getline(file, line)) {
        vector<string> parts = split(line, '\\');
        if (parts.size() == 2) ds.push_back(NhanVien(parts[0], parts[1]));
    }
    return ds;
}

// ===== Hàm đăng nhập =====
bool dangNhap(vector<NhanVien> ds) {
    string user, pass;
    int currentField = 0, demSai = 0;
    char ch;
    int consoleWidth = 80, consoleHeight = 25;
    int khungWidth = 50, khungHeight = 10;
    int khungX = (consoleWidth - khungWidth) / 2 + 45;
    int khungY = (consoleHeight - khungHeight) / 2;

    while (demSai < 3) {
        system("cls");
        textColor(14);
        gotoxy(khungX, khungY); cout << "**********************************";
        gotoxy(khungX, khungY + 1); cout << "*"; textColor(10); cout << "       DANG NHAP HE THONG       "; textColor(14); cout << "*";
        gotoxy(khungX, khungY + 2); cout << "**********************************"; textColor(15);

        string labelUser = "User: ";
        string labelPass = "Password: ";
        int nhapX = khungX + 3;

        gotoxy(nhapX, khungY + 5); textColor(11); cout << labelUser; textColor(15); cout << user;
        gotoxy(nhapX, khungY + 7); textColor(11); cout << labelPass; textColor(15);
        for (int i = 0; i < pass.size(); i++) cout << '*';

        gotoxy(nhapX + (currentField==0? labelUser.length()+user.size() : labelPass.length()+pass.size()), khungY + 5 + currentField*2);

        ch = _getch();
        if (ch == 13) { // Enter
            if (currentField == 1) {
                bool found = false;
                for (auto nv : ds)
                    if (nv.getUser() == user && nv.getPassWord() == pass) { found = true; break; }
                if (found) { textColor(10); gotoxy(khungX + 5, khungY + 9); cout << "Dang nhap thanh cong!"; Sleep(800); textColor(15); return true; }
                demSai++; textColor(12); gotoxy(khungX + 3, khungY + 9); cout << "Sai user/password (" << demSai << "/3)"; textColor(15); Sleep(1000); user=pass=""; currentField=0;
            } else currentField=1;
        }
        else if (ch==27) { textColor(12); gotoxy(khungX+3, khungY+9); cout << "Ban da thoat chuong trinh."; textColor(15); Sleep(800); return false; }
        else if (ch==72) { if(currentField>0) currentField--; } 
        else if (ch==80) { if(currentField<1) currentField++; } 
        else if (ch==8) { if(currentField==0 && !user.empty()) user.pop_back(); else if(currentField==1 && !pass.empty()) pass.pop_back(); }
        else if (isprint(ch)) { if(currentField==0) user.push_back(ch); else pass.push_back(ch); }
    }
    system("cls"); textColor(12); cout << "\n\n\tNhap sai 3 lan. Thoat chuong trinh.\n"; textColor(15); Sleep(1000);
    return false;
}

// ===== Lớp template quản lý danh sách =====
template<class T>
class QuanLyDanhSach {
    vector<T> ds;
public:
    void docFile(const string& filename);
    void ghiFile(const string& filename);
    void them(T obj);
    void xoa(string ma); // dùng chung tên "ma" cho các lớp
    void hienThi();
    vector<T>& getDS() { return ds; }
};

template<>
void QuanLyDanhSach<Sach>::docFile(const string& filename){
    ds.clear(); ifstream file(filename); if(!file.is_open()) return;
    string line;
    while(getline(file,line)){
        vector<string> parts = split(line,'\\');
        if(parts.size()==9) ds.push_back(Sach(parts[0], parts[1], parts[2], parts[3],
                                               stoi(parts[4]), stoi(parts[5]), stoi(parts[6]),
                                               parts[7], stoi(parts[8])));
    }
}

template<>
void QuanLyDanhSach<Sach>::ghiFile(const string& filename){
    ofstream file(filename);
    for(auto s:ds) file << s.getMaSach() << "\\" << s.getTenSach() << "\\" << s.getTacGia() << "\\" 
                        << s.getNhaXuatBan() << "\\" << s.getGiaBan() << "\\" << s.getNamPhatHanh() << "\\" 
                        << s.getSoTrang() << "\\" << s.getNgayNhapKho() << "\\" << s.getTinhTrang() << "\n";
}

template<>
void QuanLyDanhSach<Sach>::them(Sach s){ ds.push_back(s); }

template<>
void QuanLyDanhSach<Sach>::xoa(string ma){
    for(auto it=ds.begin(); it!=ds.end(); ++it){
        if(it->getMaSach()==ma && it->getTinhTrang()==0){ ds.erase(it); break; }
    }
}

template<>
void QuanLyDanhSach<Sach>::hienThi(){
    for(auto s: ds){
        textColor(6); cout << "Ma sach: "; textColor(15); cout << s.getMaSach() << " |\n";
        textColor(6); cout << "Ten sach: "; textColor(15); cout << s.getTenSach() << " |\n";
        textColor(6); cout << "Tac gia: "; textColor(15); cout << s.getTacGia() << " |\n";
        textColor(6); cout << "NXB: "; textColor(15); cout << s.getNhaXuatBan() << " |\n";
        textColor(6); cout << "Gia ban: "; textColor(15); cout << s.getGiaBan() << " |\n";
        textColor(6); cout << "Nam phat hanh: "; textColor(15); cout << s.getNamPhatHanh() << " |\n";
        textColor(6); cout << "So trang: "; textColor(15); cout << s.getSoTrang() << " |\n";
        textColor(6); cout << "Ngay nhap kho: "; textColor(15); cout << s.getNgayNhapKho() << " |\n";
        textColor(6); cout << "Tinh trang: "; textColor(15); cout << (s.getTinhTrang()==0?"Con sach":"Dang muon") << "\n";
        cout << "---------------------------------------------------\n";
    }
}

// --- Lớp template BanDoc ---
template<>
void QuanLyDanhSach<BanDoc>::docFile(const string& filename){
    ds.clear(); ifstream file(filename); if(!file.is_open()) return;
    string line; while(getline(file,line)){
        vector<string> parts = split(line,'\\'); if(parts.size()==3) ds.push_back(BanDoc(parts[0],parts[1],parts[2]));
    }
}

template<>
void QuanLyDanhSach<BanDoc>::ghiFile(const string& filename){
    ofstream file(filename);
    for(auto b: ds) file << b.getMaBanDoc() << "\\" << b.getHoTen() << "\\" << b.getNgayDangKy() << "\n";
}

template<>
void QuanLyDanhSach<BanDoc>::them(BanDoc b){ ds.push_back(b); }

template<>
void QuanLyDanhSach<BanDoc>::xoa(string ma){
    for(auto it=ds.begin(); it!=ds.end(); ++it){ if(it->getMaBanDoc()==ma){ ds.erase(it); break; } }
}

template<>
void QuanLyDanhSach<BanDoc>::hienThi(){
    for(auto b: ds){
        textColor(6); cout << "Ma Ban Doc: "; textColor(15); cout << b.getMaBanDoc() << " |\n";
        textColor(6); cout << "Ho Ten: "; textColor(15); cout << b.getHoTen() << " |\n";
        textColor(6); cout << "Ngay Dang Ky: "; textColor(15); cout << b.getNgayDangKy() << "\n";
        cout << "--------------------------------------------\n";
    }
}

// --- Lớp template PhieuMuon ---
template<>
void QuanLyDanhSach<PhieuMuon>::docFile(const string& filename){
    ds.clear(); ifstream file(filename); if(!file.is_open()) return;
    string line; while(getline(file,line)){
        vector<string> parts=split(line,'\\'); if(parts.size()==6) ds.push_back(PhieuMuon(parts[0],parts[1],parts[2],parts[3],parts[4],stoi(parts[5])));
    }
}

template<>
void QuanLyDanhSach<PhieuMuon>::ghiFile(const string& filename){
    ofstream file(filename);
    for(auto p: ds) file << p.getMaPhieu() << "\\" << p.getMaBanDoc() << "\\" << p.getMaSach() << "\\" 
                          << p.getNgayMuon() << "\\" << p.getNgayTra() << "\\" << p.getTinhTrang() << "\n";
}

template<>
void QuanLyDanhSach<PhieuMuon>::them(PhieuMuon p){ ds.push_back(p); }

template<>
void QuanLyDanhSach<PhieuMuon>::xoa(string ma){
    for(auto it=ds.begin(); it!=ds.end(); ++it){ if(it->getMaPhieu()==ma){ ds.erase(it); break; } }
}

template<>
void QuanLyDanhSach<PhieuMuon>::hienThi(){
    for(auto p: ds){
        textColor(6); cout << "Ma Phieu: "; textColor(15); cout << p.getMaPhieu() << " |\n";
        textColor(6); cout << "Ma Ban Doc: "; textColor(15); cout << p.getMaBanDoc() << " |\n";
        textColor(6); cout << "Ma Sach: "; textColor(15); cout << p.getMaSach() << " |\n";
        textColor(6); cout << "Ngay Muon: "; textColor(15); cout << p.getNgayMuon() << " |\n";
        textColor(6); cout << "Ngay Tra: "; textColor(15); cout << p.getNgayTra() << " |\n";
        textColor(6); cout << "Tinh Trang: "; textColor(15); cout << (p.getTinhTrang()==1?"Dang muon":"Da tra") << "\n";
        cout << "---------------------------------------------------------\n";
    }
}

// ===== Hàm lấy ngày hiện tại =====
string getNgayHienTai(int congNgay=0){
    time_t now=time(0); tm* ltm=localtime(&now); ltm->tm_mday+=congNgay; mktime(ltm);
    char buf[11]; strftime(buf,sizeof(buf),"%d/%m/%Y",ltm); return string(buf);
}

// ===== Menu quản lý =====
void menuQuanLySach(QuanLyDanhSach<Sach>& qls){
    qls.docFile("Sach.txt");
    int chon;
    do {
        system("cls");
        textColor(11); cout << "====== QUAN LY SACH ======\n"; textColor(10);
        cout << "1. Hien thi sach\n2. Them sach\n3. Xoa sach\n0. Quay lai menu chinh\n"; textColor(15);
        cout << "Nhap lua chon: "; cin >> chon; cin.ignore();
        switch(chon){
            case 1: qls.hienThi(); system("pause"); break;
            case 2: {
                string ma, ten, tacgia, nxb, ngay; int gia, nam, trang, tinhtrang=0;
                cout << "Ma sach: "; getline(cin, ma);
                bool exists=false; for(auto s: qls.getDS()) if(s.getMaSach()==ma){exists=true; break;}
                if(exists){ cout << "Ma sach da ton tai!\n"; system("pause"); break; }
                cout << "Ten sach: "; getline(cin, ten);
                cout << "Tac gia: "; getline(cin, tacgia);
                cout << "Nha xuat ban: "; getline(cin, nxb);
                cout << "Gia ban: "; cin >> gia;
                cout << "Nam phat hanh: "; cin >> nam;
                cout << "So trang: "; cin >> trang; cin.ignore();
                cout << "Ngay nhap kho: "; getline(cin, ngay);
                qls.them(Sach(ma,ten,tacgia,nxb,gia,nam,trang,ngay,tinhtrang));
                qls.ghiFile("Sach.txt");
                cout << "Them sach thanh cong!\n"; system("pause"); break;
            }
            case 3: {
                string ma; cout << "Nhap ma sach can xoa: "; getline(cin, ma);
                qls.xoa(ma); qls.ghiFile("Sach.txt"); cout << "Xoa sach thanh cong!\n"; system("pause"); break;
            }
        }
    } while(chon!=0);
}

void menuQuanLyBanDoc(QuanLyDanhSach<BanDoc>& qlbd){
    qlbd.docFile("BanDoc.txt");
    int chon;
    do{
        system("cls"); textColor(11); cout << "====== QUAN LY BAN DOC ======\n"; textColor(10);
        cout << "1. Hien thi ban doc\n2. Them ban doc\n3. Xoa ban doc\n0. Quay lai menu chinh\n"; textColor(15);
        cout << "Nhap lua chon: "; cin >> chon; cin.ignore();
        switch(chon){
            case 1: qlbd.hienThi(); system("pause"); break;
            case 2: {
                string ma, ten, ngay; cout << "Ma ban doc: "; getline(cin, ma);
                cout << "Ho ten: "; getline(cin, ten); cout << "Ngay dang ky: "; getline(cin, ngay);
                qlbd.them(BanDoc(ma,ten,ngay)); qlbd.ghiFile("BanDoc.txt"); cout << "Them ban doc thanh cong!\n"; system("pause"); break;
            }
            case 3: {
                string ma; cout << "Nhap ma ban doc can xoa: "; getline(cin, ma);
                qlbd.xoa(ma); qlbd.ghiFile("BanDoc.txt"); cout << "Xoa ban doc thanh cong!\n"; system("pause"); break;
            }
        }
    }while(chon!=0);
}

// ===== Menu quản lý phiếu mượn =====
void menuQuanLyPhieuMuon(QuanLyDanhSach<PhieuMuon>& qlpm, QuanLyDanhSach<Sach>& qls, QuanLyDanhSach<BanDoc>& qlbd){
    qlpm.docFile("PhieuMuon.txt"); qls.docFile("Sach.txt"); qlbd.docFile("BanDoc.txt");
    int chon;
    do{
        system("cls"); textColor(11); cout << "====== QUAN LY PHIEU MUON ======\n"; textColor(10);
        cout << "1. Hien thi tat ca phieu muon\n2. Them phieu muon moi\n3. Tra sach\n0. Quay lai menu chinh\n"; textColor(15);
        cout << "Nhap lua chon: "; cin >> chon; cin.ignore();
        switch(chon){
            case 1: qlpm.hienThi(); system("pause"); break;
            case 2: {
                string maBanDoc, maSach; cout << "Ma ban doc: "; getline(cin, maBanDoc); cout << "Ma sach: "; getline(cin, maSach);
                bool docExists=false, sachExists=false;
                for(auto b: qlbd.getDS()) if(b.getMaBanDoc()==maBanDoc){docExists=true; break;}
                if(!docExists){ cout << "Ma ban doc khong ton tai!\n"; system("pause"); break; }
                for(auto &s: qls.getDS()){ if(s.getMaSach()==maSach){ sachExists=true; if(s.getTinhTrang()!=0){ cout << "Sach dang duoc muon!\n"; system("pause"); break; }}}
                if(!sachExists){ cout << "Ma sach khong ton tai!\n"; system("pause"); break; }
                int stt = qlpm.getDS().size()+1;
                string ngayMuon=getNgayHienTai(), ngayTra=getNgayHienTai(7);
                qlpm.them(PhieuMuon(to_string(stt),maBanDoc,maSach,ngayMuon,ngayTra,1));
                for(auto &s: qls.getDS()) if(s.getMaSach()==maSach) s.setTinhTrang(1);
                qlpm.ghiFile("PhieuMuon.txt"); qls.ghiFile("Sach.txt");
                cout << "Them phieu muon thanh cong!\n"; system("pause"); break;
            }
            case 3: {
                string maPhieu; cout << "Nhap ma phieu muon can tra: "; getline(cin, maPhieu);
                bool found=false;
                for(auto &p: qlpm.getDS()){
                    if(p.getMaPhieu()==maPhieu && p.getTinhTrang()==1){
                        p.setTinhTrang(0);
                        for(auto &s: qls.getDS()) if(s.getMaSach()==p.getMaSach()) s.setTinhTrang(0);
                        ofstream f("PhieuDuocTra.txt", ios::app);
                        if(f.is_open()) f << p.getMaPhieu() << "\\" << p.getMaBanDoc() << "\\" << p.getMaSach() << "\\" << p.getNgayMuon() << "\\" << getNgayHienTai() << "\\Da tra\n";
                        f.close();
                        found=true; break;
                    }
                }
                if(!found) cout << "Khong tim thay phieu muon hoac da tra roi!\n";
                qlpm.ghiFile("PhieuMuon.txt"); qls.ghiFile("Sach.txt"); system("pause"); break;
            }
        }
    }while(chon!=0);
}

// ===== Menu chính =====
void menuChinh(){
    QuanLyDanhSach<Sach> qls;
    QuanLyDanhSach<BanDoc> qlbd;
    QuanLyDanhSach<PhieuMuon> qlpm;
    int khungX=(80-50)/2+45;
    int chon;
    do{
        system("cls");
        gotoxy(khungX,5); textColor(11); cout << "====== HE THONG QUAN LY THU VIEN ======"; textColor(15);
        gotoxy(khungX,7); cout << "1. Quan ly sach";
        gotoxy(khungX,8); cout << "2. Quan ly ban doc";
        gotoxy(khungX,9); cout << "3. Quan ly phieu muon";
        gotoxy(khungX,10); cout << "0. Thoat chuong trinh";
        gotoxy(khungX,12); cout << "Nhap lua chon: "; cin >> chon; cin.ignore();
        switch(chon){
            case 1: menuQuanLySach(qls); break;
            case 2: menuQuanLyBanDoc(qlbd); break;
            case 3: menuQuanLyPhieuMuon(qlpm, qls, qlbd); break;
            case 0: cout << "\nDang thoat chuong trinh...\n"; Sleep(700); break;
            default: cout << "\nLua chon khong hop le!\n"; system("pause");
        }
    }while(chon!=0);
}

// ===== Main =====
int main(){
    vector<NhanVien> dsNhanVien = docDanhSachNhanVien();
    if(dangNhap(dsNhanVien)) menuChinh();
    textColor(7);
    return 0;
}
