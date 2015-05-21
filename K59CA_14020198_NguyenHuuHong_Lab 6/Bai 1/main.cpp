/** \file main.cpp
 * \brief doc ma tran va in ma tran theo dinh dang cho truoc
 * \author Nguyen Huu Hong - 14020198
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Matrix {
private:
    int cols;
    int rows;
    vector <double> a;
public:
    void nhap_a(const char* filename); // so dong + so cot, sau do cac gia tri o phia duoi
    void nhap_b(const char* filename); // chi co cac gia tri, khong co so dong va so cot
    void nhap_c(const char* filename); // chi co cac gia tri, khong co so dong va so cot, cac gia tri cach nhau boi dau ','
    void xuatFile(const char* filename);
    void xuatFileCSV (const char* filename); // CSV : comma separated values
    void xuatScreen();
};
/** \brief xuat gia tri cua ma tran ra file, cac so cach nhau voi dau ' '
 * \param filename : tenfile muon xuat gia tri ra
 */

void Matrix:: xuatFile(const char* filename){
    ofstream f(filename);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            f << a[i*cols + j] << " ";
        }
        f <<  endl;
    }
}
/** \brief xuat gia tri cua ma tran ra man hinh
 */

void Matrix:: xuatScreen(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << a[i*cols + j] << " ";
        }
        cout <<  endl;
    }
}
/** \brief xuat gia tri cua ma tran ra file, cac so cach nhau voi dau ','
 * \param filename : tenfile muon xuat gia tri ra
 */
void Matrix:: xuatFileCSV(const char* filename){
    ofstream f(filename);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            f << a[i*cols + j];
            if(j != cols - 1) f << ",";
        }
        f <<  endl;
    }
}
/** \brief nhap ma tran theo dinh dang cau a(dong dau tien chua chi so dong, cot,dong tiep theo chua cac gia tri)
 * \param filename: ten file chua du lieu cua ma tran can doc
 */

void Matrix:: nhap_a(const char* filename){
    ifstream f(filename);
    if(a.size() != 0) a.resize(0);
    if (!f.is_open()){
        throw string("Khong the mo file: " + string(filename));
    }
    int current_row = 0; // vi tri dong hien tai cua ma tran
    int count = 0; // tong so phan tu cua ma tran
    string line;
    getline(f, line);
    stringstream ss(line);
    ss >> rows;
    ss >> cols;
    if(!ss) throw string("Khong the doc duoc so hang va so cot cua ma tran");
    while(!f.eof()){
        getline(f, line);
        stringstream ss(line);
        if(line == "" && current_row >= rows) continue;
        int ss_col = 0; // luu so phan tu co  trong 1 dong ss;
        if(line == "" && current_row < rows){
            cout << current_row;
            a.resize(0);
            throw string("Error: empty line");
        }
        // dem so cot cua tung dong trong ma tran va kiem tra tong so phan tu
        while(ss){
            double temp;
            ss >> temp;
            if(ss){
                ss_col++;
                count ++;
                a.push_back(temp);
            }else{
                if(!ss.eof()){
                    a.resize(0);
                    throw string("Co phan tu bi loi khong doc duoc");
                }
            }
        }
        if(ss_col != cols){
            a.resize(0);
            stringstream ss;
            ss << "Dong thu: " << current_row << " thieu so phan tu";
            throw ss.str();
        }
        current_row ++;
    }
    if(count != rows * cols){
        a.resize(0);
        throw("Ma tran trong file thieu phan tu");
    }
}
/** \brief nhap ma tran theo dinh dang cau b(cac dong chua cac gia tri cua ma tran, cac gia tri cach nhau boi dau ' ')
 * \param filename: ten file chua du lieu cua ma tran can doc
 */

void Matrix:: nhap_b(const char* filename){
    ifstream f(filename);
    if(a.size()!= 0) a.resize(0);
    if(!f.is_open()){
        throw string("Khong the mo duoc file: " + string(filename));
    }
    int current_row = 0;
    int count = 0;
    while(!f.eof()){
        string line;
        getline(f,line);
        stringstream ss(line);
        int ss_col = 0;
        while(ss){
            double temp;
            ss >> temp;
            if(ss){
                ss_col++;
                count ++;
                a.push_back(temp);
            }else{
                if(!ss.eof()){
                    a.resize(0);
                    throw string ("Co phan tu cua ma tran trong file bi loi");
                }
            }
        }
        if(ss_col == 0 && !f.eof()){
                a.resize(0);
                throw string("Error: empty line");
        }
        if(current_row == 0){
            cols = ss_col;
        }else{
            if(ss_col != cols && !f.eof()){
                a.resize(0);
                throw string ("Cac hang co so cot khong bang nhau");
            }
        }
        current_row++;
    }
     rows = count / cols;
}
/** \brief nhap ma tran theo dinh dang cau b(cac dong chua cac gia tri cua ma tran, cac gia tri cach nhau boi dau ',')
 * \param filename: ten file chua du lieu cua ma tran can doc
 */
void Matrix:: nhap_c(const char* filename){
    ifstream f(filename);
    if(!f.is_open()){
        throw string("Khong the mo duoc file: " + string(filename));
    }
    if(a.size()!= 0) a.resize(0);
    int current_row = 0;
    int count = 0;
    while(!f.eof()){
        string line;
        getline(f,line);
        int length = line.length();
        for(int i = 0; i < length; i++){
            if(line[i] == ',') line[i] = ' ';
        }
        stringstream ss(line);
        int ss_col = 0;
        while(ss){
            double temp;
            ss >> temp;
            if(ss){
                ss_col++;
                count ++;
                a.push_back(temp);
            }else{
                if(!ss.eof()){
                    a.resize(0);
                    throw string ("Co phan tu cua ma tran trong file bi loi");
                }
            }
        }
        if(ss_col == 0 && !f.eof()){
                a.resize(0);
                throw string("Error: empty line");
        }
        if(current_row == 0){
            cols = ss_col;
        }else{
            if(ss_col != cols && !f.eof()){
                a.resize(0);
                throw string ("Cac hang co so cot khong bang nhau");
            }
        }
        current_row++;
    }
     rows = count / cols;
}

int main()
{
    Matrix a;
    try{
        a.nhap_a("nhap_a.txt");
        cout << "Cau A" << endl;
        a.xuatScreen();
        a.nhap_b("nhap_b.txt");
        cout << endl << "Cau B" << endl;
        a.xuatScreen();
        a.nhap_c("nhap_c.txt");
        cout << endl << "Cau C" << endl;
        a.xuatScreen();
        a.xuatFileCSV("Ket_qua_c.txt");
    }catch(string a){
        cout << a << endl;
    }

}
