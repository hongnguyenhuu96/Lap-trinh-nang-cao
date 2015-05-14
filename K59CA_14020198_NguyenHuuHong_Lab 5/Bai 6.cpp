/** \file Bai 6.cpp
 * \brief Su dung lop vector
 * \author Nguyen Huu Hong - 14020198
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> A(3, 0); // khai bao A co 3 phan tu = 0
    vector<int> B(A); // B = A
    for (int i = 0; i < A.size(); i++){ // A.size() : so luong phan tu cua A
        cout << "A[" << i << "] = " <<  A[i] << endl; // xem cac phan tu cua A
    }
    cout << "B[2] = " << B.at(2) << endl << endl; // xem phan tu thu 2 cua B
    cout << "push_back: " << endl;
    A.push_back(1); // them phan tu gia tri = 1 vao cuoi cua A
    A.push_back(2); // them phan tu gia tri = 2 vao cuoi cua A
    A.push_back(3);// them phan tu gia tri = 3 vao cuoi cua A
    for (int i = 0; i < A.size(); i++){
        cout << "A[" << i << "] = " <<  A[i] << endl; // xem lai A sau khi them phan tu
    }
    cout << endl << "pop_back: " << endl;
    A.pop_back(); // bo phan tu cuoi cung cua A ra
    for (int i = 0; i < A.size(); i++){
        cout << "A[" << i << "] = " <<  A[i] << endl; // xem lai sau khi them
    }
    cout << endl << "clear A: ";
    A.clear(); // xoa cac phan tu cua A di
    if(A.empty()) cout << "A is empty!" << endl;

    A.swap(B); // chuyen A va B: do A luc nay trong, nen sau khi chuyen B trong va A co gia tri cua B
    for (int i = 0; i < A.size(); i++){
        cout << "A[" << i << "] = " <<  A[i] << endl; // xem gia tri cua A (do B swap sang)
    }
    for (int i = 0; i < B.size(); i++){
        cout << "B[" << i << "] = " <<  B[i] << endl; // xem gia tri cua B (B trong TH nay trong)
    }

    cout << endl << "matrix" << endl;
    vector< vector<int> > matrix(5, vector<int>(3,0)); // nhu mang 2 chieu matrix[5][3]
    for (int i = 0; i < 5; i++)
        for(int j = 0; j < 3; j++){
            matrix[i][j] = 1; // gan cac gia tri
        }
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            cout << matrix[i][j] << " "; // xem ma tran sau khi gan gia tri
        }
        cout << endl;
    }

}
