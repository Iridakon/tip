#include <iostream>
#include "list"

template <typename T>
class List
{
private:
    struct element
    {
        T data;
        element *next;
    };
    element *head;
    List (const List&);
    List operator=(const List&);
public:
    List() {head=NULL;}
    List(T dat){ //std::cout << "1" << std::endl;
        element* e= new element;
        head=e;
        e->data=dat;
        e->next=NULL;
        }
    ~List(){
        while (head!=NULL) {this->delFirst();}
        //std::cout << "Hello, World!" << std::endl;
        }
    void push(T dat)
    {
        element* e= new element;
        e->next=head;
        head=e;
        e->data=dat;
    }
    void delFirst()
    {
        element* e;
        e=head;
        head=head->next;
        delete e;
    }
    void push_back(T dat)
    {
        element* e= new element;
        element* a=head;
        if (a!=NULL){
        while (a->next!=NULL) {a=a->next;}
        a->next=e;
        e->next=NULL;
        e->data=dat;
        }
    }
    void delLast()
    {
        element* a=head;
        if (a!=NULL) {
            if (a->next==NULL) {  delete a; head=NULL;   }
            else
            {
            while (a->next->next != NULL) { a = a->next; }
            delete a->next;
            a->next=NULL;
            }
        }
    }
    void Pr()
    {
        element* a=head;
        while (a!=NULL)
        {
            std::cout << a->data<<" ";
            a=a->next;
        }
        std::cout  << std::endl;
    }

};


int main() {
    /*
    List<int> a(5);
    a.push(6);
    a.Pr();
    a.delFirst();
    a.Pr();*/
    List<char> b;
    b.push('a');
    //b.delLast();
    b.push('b');
    b.push('c');
    b.push_back('d');
    b.Pr();
    b.delFirst();
    b.delLast();
    b.Pr();
    List<char> c;
    //c=b;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
