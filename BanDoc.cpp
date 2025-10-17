#include <iostream>
#include <string>
using namespace std;

class BanDoc
{
    string id;        // Mã bạn đọc (duy nhất)
    string name;      // Họ tên bạn đọc
    string date;   // Ngày đăng ký tham gia
public:
    // --- Getter ---
    string getId() 
    { 
        return id; 
    }
    string getName()  
    { 
        return name; 
    }
    string getDate() 
    { 
        return date; 
    }
    // --- Setter ---
    void setId(string value) 
    { 
        id = value; 
    }
    void setName(string value) 
    { 
        name = value; 
    }
    void setDate(string value) 
    { 
        date = value; 
    }
    // --- Constructor ---
    BanDoc() 
    {
        id = "50.01.103.027";
        name = "Minh Huy";
        date = "17/10/2025";
    }
    BanDoc(string _id, string _name, string _date)
    {
        id = _id;
        name = _name;
        date = _date;
    }
};

int main()
{
    return 0;
}
