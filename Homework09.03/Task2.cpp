#include <iostream>   
#include <math.h>

using namespace std;

struct  Node
{
    int data;
    Node * next = 0;
    Node * previos = 0;
};

struct SortedList
{
    Node * pHead = 0;
    Node * pAss = 0;

    void Push(int data){
        Node * fr = pHead;
        int i = 0;
        
        
        if (!pHead){
            Node * node = new Node;
            node->data = data;
            node->next = 0;
            node->previos = 0;
            pHead = node;
            pAss = node;
        }
        else if (data < fr->data){
                Node * node = new Node;
                node->data = data;
                fr->previos = node;
                node->next = fr;
                pHead = node;
            }
 
        else{
            while (fr){

                if (data == fr->data){
                    break;
                }
                else{

                if (data < fr->data){
                    Node * node = new Node;
                    node->data = data;
                    node->next = fr;
                    node->previos = fr->previos;
                    fr->previos->next = node;
                    fr->previos = node;
                    break;
                }

                if (fr->next){
                    fr = fr->next;
                }
                else{
                    Node * node = new Node;
                    node->data = data;
                    fr->next = node;
                    node->previos = fr;
                    pAss = node;
                    break;
                }

                }

               



            }
        }
    }
    void PrntAll(){
        Node * fr = pHead;
        while(fr){
            cout << fr->data << endl;
            if (fr->next){
                fr = fr->next;
            }
            else{
                break;

            }
        }
        cout << endl;
    }

    int get(int ind){
        int elem;
        int el = 0;
        Node * fr = pHead;
        while (fr){
            el += 1; 
            if (el == ind){
                elem = fr->data;
                break;

            }
            if (fr->next)
                {
                    fr = fr->next;               
                }

        }
        

        return elem;
    }
    
    void removeAt(int ind){
        Node * fr = pHead;
        int x = 0;
        while (fr){
            x += 1; 
            if (x == ind)
              {
                if (fr->previos)
                {
                    if (fr->next)
                    {
                        fr->previos->next = fr->next;
                        fr->next->previos = fr->previos;
                        delete fr;

                    }
                    else
                    {
                        delete fr;
                    }
                }
                else
                {
                    pHead = fr->next;
                    delete fr;
                }
                break;

            }
            if (fr->next)
                {
                    fr = fr->next;               
                }
        

        }

    }
};

int main()                        
{  

    SortedList * a = new SortedList;
    SortedList * b = new SortedList;

    a->Push(50);
    b->Push(50);
    a->Push(46);
    b->Push(46);
    a->Push(16);
    b->Push(16);
    a->PrntAll();
    b->PrntAll();
    delete a;
    return 0;

}                              
