#ifndef LBAG_H
#define LBAG_H

#include <cstdlib>
#include <ostream>
#include "node.h"

template <class T>
class LBag
{
public:
    // pre: none
    // post: creates an empty LBag
    LBag();

    // pre: none
    // post: creates an LBag that is a copy of given LBag
    LBag(const LBag &);

    //Returns all memory to the runtime environment and sets head and tail to nullptr
    ~LBag();

    //pre: none
    //post:  change this bag to be a copy of the parameter bag
    void operator =(const LBag &);

    //pre: none
    //post:  returns the number of nodes in the linked list
    std::size_t size() const;

    //pre: none
    //post:  returns the number of times the parameter value appears in the bag
    std::size_t count(const T &) const;

    //pre: none
    //Post:  the parameter value is inserted at the head of the bag
    void insert(const T &);

    //pre: none
    //post:  our bag includes all of its elements, followed by all of the parameter bag's elements
    void operator +=(const LBag &);//homework

    //pre: none
    //post:  removes the first instance of the parameter value in the bag, if there is one.
    bool erase_one(const T &val);//homework

    //pre: none
    //post:  removes all instances of the parameter value in the bag.
    std::size_t erase(const T &val);//homework

    template <typename T2>
    friend std::ostream& operator <<(std::ostream& out, const LBag<T2> & b);
    //friend functions can use private members

private:
    node<T> *head, *tail;
};

template <class T>
LBag<T> operator +(const LBag<T> &, const LBag<T> &);
//template <class T>//This is a template function because it operates on
//a template class object, but it is NOT a member function of a template class
//std::ostream& operator <<(std::ostream& out, const LBag<T> &);

    // pre: none
    // post: creates an empty LBag
    template <class T>
    LBag<T>::LBag(){
      head=nullptr;
      tail = nullptr;
    }
    // pre: none
    // post: creates an LBag that is a copy of given LBag
    template <class T>
    LBag<T>::LBag(const LBag & b){
      list_copy(b.head, b.tail, head, tail);
    }
    //Returns all memory to the runtime environment and
    //sets head and tail to nullptr
    template <class T>
    LBag<T>::~LBag(){
      list_clear(head, tail);
    }

    //pre: none
    //post:  change this bag to be a copy of the parameter bag
    template <class T>
    void LBag<T>::operator =(const LBag & b){
      list_clear(head, tail);
      list_copy(b.head, b.tail, head, tail);
    }
    //pre: none
    //post:  returns the number of nodes in the linked list
    template <class T>
    std::size_t LBag<T>::size() const{
      return list_size(head);
    }

    //pre: none
    //post:  returns the number of times the parameter value appears in the bag
    template <class T>
    std::size_t LBag<T>::count(const T & value) const{
      node<T>* temp=head;
      std::size_t count = 0;
      while(temp!=nullptr){
        if(value==temp->data())//each value is equal to the value, increment counter
          count++;
        temp = temp->link();
      }
      return count;
    }
    //pre: none
    //Post:  the parameter value is inserted at the head of the bag
    template <class T>
    void LBag<T>::insert(const T & value){
      list_head_insert(head, tail, value);
    }

    template <class T>
    std::ostream& operator <<(std::ostream& out,
      const LBag<T> & b){
        out<<b.head;
        return out;
      }

    template <class T>
    void LBag<T>::operator +=(const LBag<T> &o){
        for(node<T>* tmp = o.head; tmp; tmp=tmp->link()){
            list_tail_insert(head,tail,tmp->data());
        }
    }
    template <class T>
    LBag<T> operator +(const LBag<T> &l, const LBag<T> &r){
        LBag<T> tmp(l);
        tmp += r; 
        return tmp;
    }

    //iterate through points with cur and prev
    //when cur == val -> exit loop
    //check head or not
    //delete base that
    template <class T>
    bool LBag<T>::erase_one(const T &val){
        node<T>* tmp = head, *prev;
        while(tmp && tmp->data() != val){
            //does this work?
            prev = tmp;
            tmp=tmp->link();
        }    
        if(tmp){
            if(tmp != head) list_remove(prev,tail); 
            else list_head_remove(head,tail);
            return true;
        } 
        return false;
    }

    //same thing as before
    //but instead of starting from head
    //start from last tmp
    using namespace std;
    template <class T>
    std::size_t LBag<T>::erase(const T &val){
        int cnt = 0;
        node<T>* tmp = head, *prev = head;
        while(tmp){
            while(tmp && tmp->data() != val){
                prev = tmp;
                tmp=tmp->link();
            }    
            if(tmp){
                //resets bc tmp is null or deleted
                //prev never nullptr unless head
                //prev = null for head
                if(tmp != head){
                    list_remove(prev,tail); 
                    tmp = prev;
                }
                else{
                    list_head_remove(head,tail);
                    tmp = head;
                }
                cnt++;
            } 
        }
        return cnt;
    }

#endif // LBAG_H
