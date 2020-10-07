
#ifndef AS3_LINKEDLIST_H
#define AS3_LINKEDLIST_H

#include<iostream>
#include<string>
#include <sstream>

using namespace std;

template <class Object>
class LinkedList{
private:
    void IndexOutOfBoundsException(){
        cout << "IndexOutOfBoundsException";
        exit(1);
    }
    void NoSuchElementException(){
        cout << "NoSuchElementException";
        exit(1);
    }
    struct Node{
    public:
        Object element=NULL;
        Node* previous= nullptr;
        Node* next=nullptr;
        void set(Node* previous,Object value,Node* next){
            this->element = value;
            this->previous = previous;
            this->next = next;
        }
    };
    int length=0;
    Node *first= nullptr;
    Node *last=nullptr;
    template<typename T> string TtoString(const T& t){
        ostringstream oss;
        oss<<t;
        return oss.str();
    }
    void linkLast(Object o){
        Node* l=this->last;
        Node* newNode=new Node();
        newNode->set(l,o,new Node());
        this->last=newNode;
        if(l==nullptr){
            this->first=newNode;
        }
        else{
            l->next=newNode;
        }
        length++;
    }
    void linkBefore(Object e,Node* succ){
        Node* pred=succ->previous;
        Node* newNode=new Node();
        newNode->set(pred,e,succ);
        succ->previous=newNode;
        if(pred==nullptr){
            this->first=newNode;
        }
        else{
            pred->next=newNode;
        }
        length++;
    }
    Node* node(int index){
        Node* x;
        int i;
        if(index<this->length>>1){
            x=this->first;
            for(i=0;i<index;++i){
                x=x->next;
            }
            return x;
        }
        else{
            x=this->last;
            for(i=this->length-1;i>index;--i){
                x=x->previous;
            }
            return x;
        }
    }
    bool isElementIndex(int index){
        return index >= 0 && index < this->length;
    }
    void chackElementIndex(int index){
        if(!this->isElementIndex(index)){
            IndexOutOfBoundsException();
        }
    }
    void linkFirst(Object o){
        Node* f=first;
        Node* newNode=new Node();
        newNode->set(NULL,o,f);
        first=newNode;
        if(f==nullptr){
            this->last=newNode;
        }
        else{
            f->previous=newNode;
        }
        length++;
    }
    Object unlinkFirst(Node* f){
        Object element=f->element;
        Node* next=f->next;
        f->next=nullptr;
        f->element=NULL;
        first=next;
        if(next==nullptr){
            last=nullptr;
        }
        else{
            next->previous=nullptr;
        }
        length--;
        return element;
    }
    Object unlinkLast(Node* l){
        Object element=l->element;
        Node* prev=l->previous;
        l->previous=nullptr;
        l->element=NULL;
        last=prev;
        if(prev==nullptr){
            first=nullptr;
        }
        else{
            prev->next=nullptr;
        }
        length--;
        return element;
    }
    Object unlink(Node* x){
        Object element=x->element;
        Node* next=x->next;
        Node* prev=x->previous;
        if(next==nullptr){
            last=prev;
        }else{
            next->previous=prev;
            x->next=nullptr;
        }
        if (prev==nullptr){
            first=next;
        }else{
            prev->next=next;
            x->previous=nullptr;
        }
        x->element=NULL;
        length--;
        return element;
    }
public:
    int indexOf(Object o) {
        int index = 0;
        Node* x;
        if (o == NULL) {
            for(x = this->first; x != nullptr; x = x->next) {
                if (x->element == NULL) {
                    return index;
                }
                ++index;
            }
        } else {
            for(x = this->first; x != nullptr; x = x->next) {
                if (o==x->element) {
                    return index;
                }

                ++index;
            }
        }

        return -1;
    }
    Object element(){
        return this->getFirst();
    }
    Object getFirst(){
        const Node* f=first;
        if (f==nullptr){NoSuchElementException();}
        return f->element;
    }
    Object getLast(){
        const Node* l=last;
        if(l==nullptr){NoSuchElementException();}
        return l->element;
    }
    Object removeFirst(){
        const Node* f=first;
        if(f==nullptr){NoSuchElementException();}
        return unlinkFirst(f);
    }
    Object removeLast(){
        const Node* l=last;
        if(l==nullptr){NoSuchElementException();}
        return unlinkLast(l);
    }
    void addFirst(Object e){
        linkFirst(e);
    }
    void addLast(Object e){
        linkLast(e);
    }
    bool contains(Object o){
        return indexOf(o)!=-1;
    }
    void add(int index,Object o){
        if(index>length||index<0){
            IndexOutOfBoundsException();
        }
        else if(index==length){
            this->linkLast(o);
        }
        else{
            this->linkBefore(o,this->node(index));
        }
    }
    Object remove(){
        return this->removeFirst();
    }
    Object remove(int index){
        this->chackElementIndex(index);
        return this->unlink(this->node(index));
    }
    template<class T>
    bool remove(T o){
        Node* x;
        if(o==NULL){
            for(x = this->first; x != nullptr; x = x->next) {
                if (x->element==NULL){
                    this->unlink(x);
                    return true;
                }
            }
        }else{
            for(x = this->first; x != nullptr; x = x->next) {
                if(o==x->element){
                    this->unlink(x);
                    return true;
                }
            }
        }
        return false;
    }
    void add(Object o){
        this->linkLast(o);
    }
    Object* toArray(){
        Object* result=new Object[length];
        int i=0;
        for(Node* x=this->first;x!=nullptr;x=x->next){
            result[i++]=x->element;
        }
        return result;
    }
    LinkedList<Object> clone(){
        LinkedList<Object> clone;
        clone.first=clone.last=nullptr;
        clone.length=0;
        for(Node* x=this->first;x!=nullptr;x=x->next){
            clone.add(x->element);
        }
        return clone;
    }
    void clear(){
        Node* next;
        for(Node* x=this->first;x!=nullptr;x=next){
            next=x->next;
            x->element=NULL;
            x->next=nullptr;
            x->previous=nullptr;
        }
        this->first=this->last=nullptr;
        this->length=0;
    }
    int size() {return this->length;}
    Object get(int index){
        this->chackElementIndex(index);
        return this->node(index)->element;
    }
    Object set(int index,Object element){
        this->chackElementIndex(index);
        Node* x=this->node(index);
        Object oldElement=x->element;
        x->element=element;
        return oldElement;
    }
    string toString(){
        if (length==0)
        {
            string s2;
            s2="[]";
            return s2;
        }
        else
        {
            string s;
            s.append("[");
            int i=0;
            while(true){
                s.append(TtoString(get(i)));
                i++;
                if(i==length){
                    s.append("]");
                    return s;
                }
                s.append(", ");
            }
        }
    }
    Object pop(){
        return this->removeFirst();
    }
    void push(Object e){
        this->addFirst(e);
    }
    bool removeFirstOccurrence(Object o) {
        return this->remove(o);
    }
    bool removeLastOccurrence(Object o) {
        Node* x;
        if (o == NULL) {
            for(x = this->last; x != nullptr; x = x->prev) {
                if (x->element == NULL) {
                    this->unlink(x);
                    return true;
                }
            }
        } else {
            for(x = this->last; x != nullptr; x = x->prev) {
                if (o==x->element) {
                    this->unlink(x);
                    return true;
                }
            }
        }

        return false;
    }

};

#endif //AS3_LINKEDLIST_H
