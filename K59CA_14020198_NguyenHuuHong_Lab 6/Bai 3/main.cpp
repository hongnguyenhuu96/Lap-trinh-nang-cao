/** \file main.cpp (project Bai 3)
 * \brief Doc va xuat thong tin cua cac sinh vien, diem so cac mon
 * \author Nguyen Huu Hong - 14020198
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Diem{ // lop Diem
private:
    string subject; // ten mon hoc
    double value; // diem so cua mon hoc nay
public:
    Diem(){
        subject = "";
        value = 0;
    }
    Diem(string theSub, double theValue){
        subject = theSub;
        value = theValue;
    }
    friend ostream& operator << (ostream &os, Diem &a){ // hien thi gia tri ten mon hoc va diem so
        os << "," << a.subject  << "," << a.value;
        return os;
    }
};

class SinhVien // : public vector <Diem>
{
private:
    string name;
    int age;
    vector<Diem> mS; // markStudent: luu tru tat ca cac loai diem cua 1 sinh vien
    static vector<SinhVien> dS; // luu du lieu toan bo sinh vien trong danh sach nhap tu file
public:
    SinhVien(){ // ham tao
        name = "";
        age = 0;
    }
    friend ostream& operator << (ostream& os, SinhVien &a); // xem cac gia tri cua 1 sinh vien
    void readOne(string oneline); // xu ly lay thong tin cua 1 sinh vien tu string oneline : 1 dong trong file
    static void getAllStudent(const char* filename); // lay du lieu tu file roi luu vao bo nho
    static void getAllStudent2(const char* filename); // truong hop co tinh chu thich dau # (bo qua dong nay)
    static void showFile(const char* filename); // in du lieu doc duoc ra file
    static void showScreen(); // in du lieu doc duoc ra man hinh
};
/** \brief du lieu cua 1 sinh vien vao dong xuat os
 * \param os: dong xuat
 * \param a: sinh vien can xem du lieu
 * \return os: de co the su dung << <<
 */

ostream& operator << (ostream& os, SinhVien &a){
    os << a.name << "," << a.age;
    int size = a.mS.size();
    for(int i = 0; i < size; i++){
        os << a.mS[i];
    }
    os << endl;
    return os;
}
/** \brief doc du lieu string oneline : 1 dong tren file
 * \param oneline: string chua du lieu cua 1 sinh vien
 */

void SinhVien::readOne(string oneline){
        string sub; // subject
        double val; // values
        stringstream ss(oneline);
        getline(ss,name,',');
        ss >> age;
        if(!ss) throw string("Age is error");
        ss.get();
        while(ss){
            getline(ss,sub,',');
            ss >> val;
            if(!ss) throw string("Mark is error");
            mS.push_back(Diem(sub, val));
            ss.get();
        }
    }

// khai bao bien static
vector<SinhVien> SinhVien::dS;

/** \brief lay tat ca du lieu cua sinh vien vao bien  static vector dS (khong tinh chu thich #)
 * \param filename: file chua toan bo du lieu sinh vien
 */

void SinhVien::getAllStudent(const char* filename){
    ifstream f(filename);
    if(!f.is_open()){
        throw string("Khong the mo duoc file: " + string(filename));
    }
    SinhVien temp;
    string oneLine;
    while(!f.eof()){
        getline(f,oneLine);
        temp.readOne(oneLine);
        dS.push_back(temp);
    }
}

/** \brief lay tat ca du lieu cua sinh vien vao bien static vector dS (bo cach dong duoc chu thich dang: # aksdfkahdf)
 * \param filename: file chua du lieu toan bo sinh vien
 */

void SinhVien::getAllStudent2(const char* filename){ // chu thich # o dau dong thi khong tinh
    ifstream f(filename);
    if(!f.is_open()){
        throw string("Khong the mo duoc file: " + string(filename));
    }
    string oneLine;
    while(!f.eof()){
        SinhVien temp;
        getline(f,oneLine);
        if(oneLine == "") continue;// neu gap dong trong thi bo khong doc
        if(oneLine[0] == '#') continue; // gap chu thich thi bo khong doc
        temp.readOne(oneLine);
        dS.push_back(temp);
    }
}

/** \brief xuat thong ra file
 * \param filename: ten file se chua thong tin
 */
void SinhVien::showFile(const char* filename){ // ham xuat thong tin ra file
    ofstream f(filename);
    int size = dS.size();
    for (int i = 0; i < size; i++)
        f << dS[i];
}

/** \brief xuat thong tin ra man hinh
 */
void SinhVien::showScreen(){ // ham xuat thong tin ra man hinh
    int size = dS.size();
    for(int i = 0; i < size; i++){
        cout << dS[i];
    }
}
int main(){
    try{
        SinhVien::getAllStudent2("danhsach.txt");
    } catch(string a){
        cout << a;
    }
    SinhVien::showFile("Ket qua.txt");
}
