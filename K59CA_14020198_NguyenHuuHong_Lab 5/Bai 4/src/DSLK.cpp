#include "DSLK.h"
using namespace std;

/** \brief ham tao khong doi
 */
template<class T>
DSLK<T>::DSLK(): front(NULL), back(NULL){}

/** \brief destructor, huy tat ca cac gia tri cua Node trong danh sach
 */
template<class T>
DSLK<T>::~DSLK()
{
    T *current = front;
    while(current != NULL){
        front = front->getLink();
        delete current;
        current = front;
    }
}

/** \brief them 1 phan tu moi vao trong danh sach
 */

template<class T>
void DSLK<T>::addOne()
{
    T* temp;
    temp = new T;
    cin >> *temp;
    if(back == NULL){
        front = back = new T(temp->getData(), NULL);
    }else{
        back->setLink(new T(temp->getData(), NULL));
        back = back->getLink();
    }
}
/** \brief them nhieu phan tu  moi vao trong danh sach khong dung operator >>
 */
template<class T>
void DSLK<T>::addAll()
{
    cout << "Nhap du lieu cho toan bo danh sach: " << endl;
    char asw;
    while(1){
        addOne();
        cout << "Tiep tuc? (y/n)";
        asw = cin.get();
        cin.ignore(1000, '\n');
        if(asw == 'n' || asw == 'N') break;
    }
}

/** \brief hien thi gia tri tat ca cac Node trong danh sach, khong dung operator
 */
template<class T>
void DSLK<T>:: output(){
    T* current = front;
    while(current != NULL){
        cout << *current << endl;
        current = current ->getLink();
    }
}
/** \brief xoa 1 node trong danhs sach theo ten
 */

template<class T>
void DSLK<T>::deleteOne()
{
    T* discard;
    discard = new T;
    cout << "Nhap ten phan tu muon xoa: ";
    getline(cin, discard->name());
    T* current0 = front;
    T* current1 = front;
    if(front->name() == discard->name()){
        front = front ->getLink();
        delete current0;
        return;
    }
    else{
        current1 = current1->getLink();
        while(current1 != NULL){
            if(current1->name() == discard->name()){
                current0->setLink(current1->getLink());
                delete current1;
                return;
            }
            current1 = current1->getLink();
            current0 = current0->getLink();
        }
    }
    cout << "Khong tim thay trong danh sach!" << endl;
}

/** \brief xap xep cac phan tu lai theo tuoi
 */

template<class T>
void DSLK<T>::sort()
{
    int n = 0;
    T* current = front;
    while(current != NULL){
        current = current->getLink();
        n++;
    }
    front = mergeSort(front, n);
    current = front;
    for(int i = 0; i < n; i++){
        current = current->getLink();
    }
    back = current;
}
/** \brief xep sep cac n phan tu theo tuoi, bat dau tu phan tu head1 tiep den n
 * \param head1: phan tu dau tien cua day ban dau can sap xep
 * \param n: so luong phan tu cua day
 * \return phan tu dau tien cua day moi da duoc sap xep
 */

template<class T>
T* DSLK<T>::mergeSort(T *head1, int n)
{
    if(n < 2) return head1;
    T* middle = head1;
    for(int i = 0; i < n/2 - 1; i++) middle = middle->getLink();
    T* head2 = middle->getLink();
    middle->getLink() = NULL;
    head1 = mergeSort(head1, n/2);
    head2 = mergeSort(head2, n - n/2);
    return merge (head1 , head2);
}
/** \brief ghep 2 day da duoc sap xep co thu tu vao nhau
 * \param head1: phan tu dau tien cua day 1
 * \param head2: phan tu dau tien cua day 2
 */

template <class T>
T* DSLK<T>::merge(T *head1, T *head2)
{
    T* front = NULL, *back = NULL;
    if(*head1 < *head2){
        front = back = head1;
        head1 = head1->getLink();
    }
    else{
        front = back = head2;
        head2 = head2->getLink();
    }
    while(head1 != NULL && head2 != NULL){
        if(*head1 < *head2){
            back->setLink(head1);
            back = head1;
            head1 = head1->getLink();
        }
        else{
            back->setLink(head2);
            back = head2;
            head2 = head2->getLink();
        }
    }

    if(head1 == NULL) back->setLink(head2);
    if(head2 == NULL) back->setLink(head1);
    return front;
}



























