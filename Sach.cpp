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
        in >> s.cost >> s.year >> s.page;
        in.ignore(); // bỏ ký tự xuống dòng trước khi đọc ngày
        getline(in, s.day);
        in >> s.check;
        in.ignore(); // bỏ dòng thừa (nếu có)
        return in;
    }
    friend ostream& operator << (ostream& out, Sach s)
    {
        out << "Ma sach: " << s.id << '\n';
        out << "Ten sach: " << s.name << '\n';
        out << "Tac gia: " << s.author << '\n';
        out << "Nha xuat ban: " << s.publisher << '\n';
        out << "Gia ban: " << s.cost << '\n';
        out << "Nam phat hanh: " << s.year << '\n';
        out << "So trang: " << s.page << '\n';
        out << "Ngay nhap: " << s.day << '\n';
        out << "Tinh trang: " << s.check << '\n';
        out << "-----------------------------\n";
        return out;
    }
};

int main()
{
    freopen("Sach.txt", "r", stdin);
    vector<Sach> ds;
    Sach s;
    while (cin >> s)
        ds.push_back(s);
    for (int i = 0; i < ds.size(); ++i)
        cout << ds[i];
    return 0;
}
