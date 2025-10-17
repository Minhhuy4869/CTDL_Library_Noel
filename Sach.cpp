#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

class Sach
{
    string id;
    string name;
    string author;
    string publisher;
    int cost;
    int year;
    int page;
    string day;
    int check;
public:
    // get - set
    string getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    string getAuthor()
    {
        return author;
    }
    string getPublicer()
    {
        return publisher;
    }
    int getCost()
    {
        return cost;
    }
    int getYear()
    {
        return year;
    }
    int getPage()
    {
        return page;
    }
    string getDay()
    {
        return day;
    }
    int getCheck()
    {
        return check;
    }
    void setId(string value)
    {
        id = value;
    }
    void setName(string value)
    {
        name = value;
    }
    void setAuthor(string value)
    {
        author = value;
    }
    void setPublisher(string value)
    {
        publisher = value;
    }
    void setCost(int value)
    {
        cost = value;
    }
    void setYear(int value)
    {
        year = value;
    }
    void setDay(string value)
    {
        day = value;
    }
    void setCheck(int value)
    {
        check = value;
    }
    // constructor
    // operator overloading
    friend istream& operator >> (istream& in, Sach& s)
    {
        getline(in, s.id);
        getline(in, s.name);
        getline(in, s.author);
        getline(in, s.publisher);
        in>>s.cost>>s.year>>s.page;
        in.ignore(); // bỏ ký tự xuống dòng trước khi đọc ngày
        getline(in, s.day);
        in>>s.check;
        in.ignore(); // bỏ dòng thừa (nếu có)
        return in;
    }
    friend ostream& operator << (ostream& out, Sach s)
    {
        out<<"Ma sach: "<<s.id<<"\n";
        out<<"Ten sach: "<<s.name<<"\n";
        out<<"Tac gia: "<<s.author<<"\n";
        out<<"Nha xuat ban: "<<s.publisher<<"\n";
        out<<"Gia ban: "<<s.cost<<"\n";
        out<<"Nam phat hanh: "<<s.year<<"\n";
        out<<"So trang: "<<s.page<<"\n";
        out<<"Ngay nhap: "<<s.day<<"\n";
        out<<"Tinh trang: "<<s.check<<"\n";
        out<<"-----------------------------\n";
        return out;
    }
};

void hienThi(vector<Sach>& ds)
{
    cout<<"\n===== DANH SACH CAC QUYEN SACH =====\n";
    for (int i=0; i<ds.size(); ++i)
        cout<<ds[i];
}    
void themSach(vector<Sach> &ds)
{
    Sach s;
    cout<<"Nhap thong tin sach moi:\n";
    cin.ignore(); // tránh lỗi trôi dòng
    cin>>s;
    for (int i=0; i<ds.size(); ++i)
    {
        if (ds[i].getId() == s.getId())
        {
            cout<<"Sach da ton tai!\n";
            return;
        }
    }
    ds.push_back(s);
    cout<<"Them sach thanh cong!\n";
}
void xoaSach(vector<Sach> &ds)
{
    string id;
    cout<<"Nhap ma sach can xoa: ";
    cin>>id;
    for (int i=0; i<ds.size(); ++i)
    {
        if (ds[i].getId() == id)
        {
            if (ds[i].getCheck() != 0)
            {
                cout<<"Khong the xoa sach do sach dang duoc muon!\n";
                return;
            }
            ds.erase(ds.begin() + i);
            cout<<"Xoa sach thanh cong!\n";
            return;
        }
    }
    cout<<"Khong tim thay sach!\n";
}

int main()
{
    freopen("Sach.txt", "r", stdin);
    vector<Sach> ds;
    Sach s;
    while (cin>>s)
        ds.push_back(s);
    for (int i=0; i<ds.size(); ++i)
        cout<<ds[i];
    return 0;
}
