/** \file main.cpp (project Bai 2)
 * \brief Ma tran thua (nhap xuat ra file, phep tinh +, *)
 * \author Nguyen Huu Hong - 14020198
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cstdlib>

using namespace std;

struct oneSquare // cau truc cua 1 o trong ma tran gom co chi so hang,chi so cot va gia tri
{
    int row, col;
    double values;
    oneSquare(int row1 = -1, int col1 = -1, double values1 = 0) : row(row1), col(col1), values(values1){}
    ~oneSquare(){
        row = -1;
        col = -1;
        values = 0;
    }
};

class SparseMatrix // lop ma tran thua
{
private:
    int rows, cols; // tong so hang va so cot cua ma tran
    vector <oneSquare> a; // 1 phan tu cua vector la 1 o != 0 cua ma tran
public:
    SparseMatrix() : rows(-1),cols(-1){}
    ~SparseMatrix(){
        rows = -1;
        cols = -1;
        a.resize(0);
    }
    void Nhap_a(const char* filename); // nhap ma tran theo dinh dang cau a tu file: filename
    void Nhap_b(const char* filename); // nhap ma tran theo dinh dang cau b tu file: filename
    void Xuat(const char* filename); // xuat ma tran ra file co ten: filename
    void XuatManHinh(); // hien thi mot ma tran ra man hinh
    SparseMatrix operator + (const SparseMatrix& other); // cong 2 ma tran
    SparseMatrix operator * (const SparseMatrix& other); // nhan 2 ma tran
    double get(int i, int j); // lay gia tri cua 1 phan tu trong ma tran
};


/** \brief lay gia tri cua 1 phan tu trong ma tran
 * \param i: chi so hang
 * \param j: chi so cot
 * \return gia tri cua phan tu (i, j) trong ma tran
 */
double SparseMatrix:: get(int i, int j){
    if (i < 0 || j < 0 || i >= rows || j >= cols)
    {
        stringstream ss;
        ss << "invalid position " << i << ", " << j;
        throw (ss.str());
    }
    int k = 0;
    int size = a.size();
    for(k = 0; k < size; k++){
        if(a[k].row == i && a[k].col == j) break;
    }
    return a[k].values;
    return 0;
}
/** \brief nhap ma tran theo format cau a (2 dong dau ghi so hang va cot, cac dong tiep ghi [chi so cot] : [gia tri])
 * \param filename: ten file cung thu muc can lay du lieu tu day
 */

void SparseMatrix::Nhap_a(const char* filename){
    ifstream f;
    f.open(filename);
    if(a.size() != 0) a.resize(0);
    if(!f.is_open()){
        throw string("file: " + string(filename) + " khong ton tai\n");
    }
    f >> rows; // nhap vao so hang va so cots
    f >> cols;
    if(!f) throw string("Error: Khong doc duoc so hang va so cot cua ma tran\n");
    int temp_row = 0; // bien luu so dong hien tai cua ma tran
    int temp_col = 0;
    float temp_val = 0;
    while(!f.eof()){
        string line;
        getline(f, line);
        if(line == "") continue;
        int length = line.length();
        for (int i = 0; i < length; i++){
            if(line[i] == ':') line[i] = ' ';
        }
        stringstream ss(line);
        while(ss){
            ss >> temp_col;
            ss >> temp_val;
            if(ss){
                oneSquare temp;
                temp.col = temp_col;
                temp.row = temp_row;
                temp.values = temp_val;
                a.push_back(temp);
            }
            else{
                if(!ss.eof()) throw string("Error: Mot phan tu trong file co gia tri loi, khong doc duoc\n");
            }
        }
        temp_row ++;
    }
    f.close();
}
/** \brief nhap ma tran theo format cau b (cac dong deu ghi [chi so cot] : [gia tri])
 * \param filename: ten file dat cung thu muc can lay du lieu de nhap
 */

void SparseMatrix::Nhap_b(const char* filename){ // chu y nhap b tuong tu nhu nhap a va chi can bo di phan nhap so hang va so cot o dau tien
    ifstream f;
    f.open(filename);
    if(!f.is_open()){
        throw string("file: " + string(filename) + " khong ton tai\n");
    }
    if(a.size() != 0) a.resize(0);
    rows = 0; cols = 0;
    int temp_row = 0;
    int temp_col = 0;
    int temp_val = 0;
    while(!f.eof()){
        string line;
        getline(f, line);
        if(line == "") continue;
        int length = line.length();
        for(int i = 0; i < length; i++){ // xoa cac ky tu : va thay bang ' '
            if(line[i] == ':') line[i] = ' ';
        }
        stringstream ss(line);
        while(ss){
            ss >> temp_col;
            ss >> temp_val;
            if(ss){
                if(temp_col > cols) cols = temp_col;
                oneSquare temp;
                temp.col = temp_col;
                temp.row = temp_row;
                temp.values = temp_val;
                a.push_back(temp);
            }else{
                if(!ss.eof()) throw string("Error: Mot phan tu trong file co gia tri loi, khong doc duoc\n");
            }
        }
        temp_row++;
    }
    rows = temp_row;
    cols++;
    f.close();
}

/** \brief xuat ma tran ra file
 * \param filename: ten file se xuat ma tran ra
 */
void SparseMatrix::Xuat(const char* filename){ // in ma tran ra file: filename
    ofstream f;
    f.open(filename);
    int size = a.size(); // so phan tu cua ma tran = size
    if(size == 0) return;
    int k = a[0].row;
    for(int i = 0; i < size; i++){
        if(a[i].row == k){
            f << setw(2) << a[i].col << ":"  << setw(2)<< a[i].values;
            if(i + 1 < size)
                if(a[i + 1].row == k) f << " ";
        } else{
            k = a[i].row;
            f << endl;
            f << setw(2) << a[i].col << ":" << setw(2) << a[i].values;
            if(i + 1 < size)
                if(a[i + 1].row == k) f << " ";
        }
    }
    f.close();
}
/** \brief xuat mot ma tran ra man hinh
 */

void SparseMatrix::XuatManHinh(){ // in ma tran ra man hinh
    int size = a.size(); // so phan tu cua ma tran  = size
    if(size == 0) return;
    int k = a[0].row;
    for(int i = 0; i < size; i++){
        if(a[i].row == k){
            cout << setw(2) << a[i].col << ":" << setw(2) << a[i].values;
            if(i + 1 < size)
                if(a[i + 1].row == k) cout << " ";
        } else{
            k = a[i].row;
            cout << endl;
            cout << setw(2) << a[i].col << ":" << setw(2) << a[i].values;
            if(i + 1 <size)
                if(a[i + 1].row == k) cout << " ";
        }
    }
}
/** \brief cong 2 ma tran
 *
 * \param other: ma tran khac cong voi ma tran *this
 * \return c: ma tran ket qua
 */

SparseMatrix SparseMatrix:: operator + (const SparseMatrix& other){
    SparseMatrix c;
    if (rows != other.rows || cols != other.cols) // kiem tra cung kich thuoc khong
        throw string ("Error: Cong ma tran: Hai ma tran nay khong cung kich thuoc\n");
    c.rows = rows;
    c.cols = cols; // neu 2 ma tran cung kich thuoc thi kich thuoc cua ma tran tong = kich thuoc nay

    for(int i = 0; i < rows; i++){
        vector <oneSquare> mergeswap; // lay tat ca cac gia tri cua hang i trong this va other dat vao vector nay
        int size = a.size();
        for(int j = 0; j < size; j++){ // lay tat ca phan tu o dong thu i trong ma tran this vao vector
            if(a[j].row == i){
                mergeswap.push_back(a[j]);
            }
        }
        size = other.a.size();
        for(int j = 0; j < size; j++){ // lay tat ca phan tu o dong thu i trong ma tran other vao vector
            if(other.a[j].row == i){
                mergeswap.push_back(other.a[j]);
            }
        }
        int s_merge = mergeswap.size(); // s_merge : size cua vector mergeswap
        for(int j = 0; j < s_merge - 1; j++){ // sap xep cac phan tu cua vector mergeswap theo thu tu col tu be den lon
            for(int k = j + 1; k < s_merge; k++){
                if(mergeswap[k].col < mergeswap[j].col){ // swap
                    oneSquare temp = mergeswap[j];
                    mergeswap[j] = mergeswap[k];
                    mergeswap[k] = temp;
                }
            }
        }
        // cong cac phan tu cua vector mergeswap vao C (ma tran luu ket qua)
        for(int j = 0; j < s_merge; j++){
            if(j + 1 < s_merge){ // neu chua den phan tu cuoi cung cua vector mergeswap thi (co the dung mergeswap[j + 1])
                if(mergeswap[j].col == mergeswap[j+1].col){ // neu 2 phan tu co collum giong nhau thi cong values cua no  va gan vao c
                    c.a.push_back(oneSquare(mergeswap[j].row,mergeswap[j].col,mergeswap[j].values + mergeswap[j + 1].values));
                    j++;
                }else{ //neu khong giong nhau thi khong can cong chi can gan thang vao C
                    c.a.push_back(oneSquare(mergeswap[j].row,mergeswap[j].col,mergeswap[j].values));
                }
            } else{ // neu den phan tu cuoi cung cua vector mergeswap roi, thi chi con 1 minh no nen cho not vao C la duoc
                c.a.push_back(oneSquare(mergeswap[j].row,mergeswap[j].col,mergeswap[j].values));
            }
        }
    }
    return c;
}

/** \brief nhan 2 ma tran
 * \param other: ma tran nhan voi ma tran *this
 * \return result: ma tran chua ket qua
 */

SparseMatrix SparseMatrix:: operator * (const SparseMatrix& other){
  //  c[i,j] = a[i,1]*b[1,j] + a[i,2]*b[2,j] + ... + a[i,n]*b[n,j] (A(m*n) * B(n*p) = C[m*p] )
    if(cols != other.rows) throw string("Error: Nhan ma tran: So cot ma tran ben trai khac so dong ma tran ben phai\n");
    SparseMatrix result; // Ma tran luu ket qua
    result.rows = rows;
    result.cols = other.cols;
    int left_size = a.size(); // so phan tu ma tran ben trai
    int right_size = other.a.size(); // so phan tu ma tran ben phai
    for(int i = 0; i < result.rows; i++){
        vector <oneSquare> left;
        for(int j = 0; j < left_size; j++){ // lay tat ca cac phan tu hang i o ben trai gan vao left
            if(a[j].row == i){
                left.push_back(a[j]);
            }
        }
        for(int j = 0; j < result.cols; j++){
            vector <oneSquare> right;
            for(int k = 0; k < right_size; k++){
                if(other.a[k].col == j){
                    right.push_back(other.a[k]);
                }
            }
        // tinh left * right;
            oneSquare temp;
            temp.row = i;
            temp.col = j;
            temp.values = 0;
            int lsize = left.size(), rsize = right.size();
            for(int m = 0; m < lsize ; m++){
                for(int n = 0; n < rsize; n++){
                    if(left[m].col == right[n].row){
                        temp.values += (left[m].values * right[n].values);
                        break;
                    }
                }
            }
            result.a.push_back(temp);
        }
    }
    return result;
}

int main()
{
    SparseMatrix a, b, c;
    // cong 2 ma tran
    try{
        cout << endl << "Cong 2 ma tran: " << endl;
        a.Nhap_a("matrana1.txt");
        cout << endl << "matran a" << endl;
        a.XuatManHinh();
        b.Nhap_a("matrana2.txt");
        cout << endl << "matran b" << endl;
        b.XuatManHinh();
        c = a + b;
        cout << endl << "matran tong cua a va b: (c)" << endl;
        c.XuatManHinh();
        c.Xuat("Ket_qua_cong.txt");
    }catch (string a){
        cout << a;
    }
    // nhan 2 ma tran
    try{
        cout << endl << endl << "Nhan 2 ma tran: " << endl;
        a.Nhap_b("matranb1.txt");
        cout << endl << "matran a" << endl;
        a.XuatManHinh();
        b.Nhap_b("matranb2.txt");
        cout << endl << "matran b" << endl;
        b.XuatManHinh();
        c = a * b;
        cout << endl << "matran tich cua a va b: (c)" << endl;
        c.XuatManHinh();
        c.Xuat("Ket_qua_nhan.txt");
    } catch(string a){
        cout << a;
    }
    // lay gia tri cua 1 phan tu trong ma tran
    try{
        cout << endl << "Gia tri cua phan tu (1,1) trong ma tran a la:" << endl;
        cout << a.get(1,1);
    }catch (string a){
        cout << a;
    }
    return 0;
}
