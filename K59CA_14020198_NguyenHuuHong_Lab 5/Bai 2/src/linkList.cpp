#include "linkList.h"

/** \brief ham constructor khong doi
 */
linkList::linkList()
{
    front = NULL;
    back = NULL;
}

/** \brief ham destructor
 */
linkList::~linkList()
{
    while(front != NULL){
        Student *current = front;
        front = front ->getLink();
        delete current;
    }
}
/** \brief them 1 sinh vien moi vao danh sach
 */

void linkList::addOne()
{
    Student *temp;
    temp = new Student;
    cin >> *temp;
    if(front  == NULL){
        front  = back = new Student(temp->getData(), NULL);
    }else{
        back->setLink(new Student(temp->getData(), NULL));
        back = back ->getLink();
    }
}
/** \brief operator >> them toan bo sinh vien vao danh sach
 * \param is: dong nhap
 * \param a: danh sach can them sinh vien vao day
 * \return is: de su dung cho nhap lien tiep >> >>
 */

istream& operator >> (istream& is, linkList &a)
{
    cout << "Nhap thong tin cho toan bo danh sach:" << endl;
    while(1){
        char ans;
        a.addOne();
        cout << "Tiep tuc (y/ n)?";
        cin >> ans;
        cin.ignore(1000,'\n');
        if(ans == 'n'|| ans == 'N') break;
    }
    return is;
}

/** \brief operator << hien thi toan bo sinh vien co trong danh sach
 * \param os: dong xuat
 * \param a: danh sach sinh vien can hien thi
 * \return os: de xuat lien tiep 2 danh sach << <<
 */
ostream& operator << (ostream& os, const linkList &a)
{
    cout << "Danh sach tat ca cac Sinh Vien: "<< endl;
    Student *current = a.front;
    while(current != NULL){
        cout << *current;
        current = current -> getLink();
    }
    return os;
}
/** \brief xoa 1 sinh vien ra khoi danh sach theo ten
 */

void linkList:: deleteOne()
{
    cout << endl << "Nhap ten sinh vien ban muon xoa khoi danh sach: ";
    string del;
    getline(cin, del);
    Student *current0 = front;
    Student *current1 = front;
    if(front->getName() == del){
        front = front->getLink();
        delete current0;
        return;
    }
    else{
        current1 = current1->getLink();
        while(current1 != NULL){
            if(current1 ->getName() == del){
                current0->setLink(current1->getLink());
                delete current1;
                return;
            }
            current0 = current0->getLink();
            current1 = current1->getLink();
        }
    }
    cout << "Khong tim thay sinh vien co ten nhu vay!";
}
/** \brief sap xep sinh vien theo tuoi
 */

void linkList::sort(){
    int n = 0;
    Student *current = front;
    while(current != NULL){
        current = current->getLink();
        n++;
    }
    front = mergeSort(front, n);
    current = front;
    while(current ->getLink() != NULL){
        current = current->getLink();
    }
    back = current;
}
/** \brief Sap xep danh sach sinh vien ban dau, danh sach nay co n phan tu
 * \param head1: con tro dau tien cua danh sach ban dau
 * \param n: so luong phan tu trong danh sach can sap xep
 * \return con tro dau tien trong danh sach da sap xep xong theo tuoi
 *
 */

Student*linkList:: mergeSort(Student *head1, int n)
{
    if(n < 2) return head1;
    Student *middle = head1;
    for(int i = 0; i < n/2 - 1; i++) middle = middle ->getLink();
    Student *head2 = middle->getLink();
    middle->setLink(NULL);
    head1 = mergeSort(head1, n/2);
    head2 = mergeSort(head2, n - n/2);
    return merge(head1, head2);
}
/** \brief tron 2 danh sach co cac sinh vien da duoc sap xep theo tuoi vao nhau
 * \param head1: con tro dau tien cua danh sach thu 1 (da duoc sap xep tang dan theo tuoi)
 * \param head2: con tro dau tien cua danh sach thu 2 (da duoc sap xep tang dan theo tuoi)
 * \return front: con tro dau tien trong danh sach da sap xep tron 2 danh sach head1 va head2 theo tuoi
 */

Student* linkList:: merge(Student *head1, Student *head2){
    Student *front = NULL; // con tro dau tien cua danh sach sau sap xep
    Student *back = NULL; // con tro cuoi cung cua danh sach sau sap xep
    if(head1->getAge() < head2 ->getAge()){
        front = back = head1;
        head1 = head1->getLink();
    }else{
        front = back = head2;
        head2 = head2 ->getLink();
    }
    while(head1 != NULL && head2 != NULL){
        if(head1->getAge() < head2->getAge()){
            back->setLink(head1);
            back = back->getLink();
            head1 = head1->getLink();
        }
        else{
            back->setLink(head2);
            back = back->getLink();
            head2 = head2->getLink();
        }
    }
    if(head1 == NULL) back->setLink(head2); // cho not phan con lai cua danh sach van con sinh vien vao danh sach chinh
    if(head2 == NULL) back->setLink(head1);
    return front;
}





