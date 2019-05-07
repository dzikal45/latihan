#include<iostream>
using namespace std;
struct ElementQueue{
  string nama ;
  int umur;
  ElementQueue* next;
};
typedef ElementQueue* pointer;
typedef pointer list;
struct queue{
  list head;
  list tail;
};
 queue  q;
 void createlist(queue& q){
   q.head= NULL;
   q.tail=NULL;
 }
 void createElmt(pointer& pBaru){
   pBaru = new ElementQueue;
   cout<<"Masukan nama :"; cin>>pBaru->nama;
   cout<<"Masukan umur :"; cin>>pBaru->umur;
   pBaru->next= NULL;
 }
 void insertQueue(pointer pBaru){
   pointer pBantuPrev=q.head;
   pointer pBantu=q.head;
   pointer batas;
   if(q.head == NULL && q.tail == NULL){
    q.head = pBaru;
    q.tail = pBaru;
   }
   else{
    while(pBaru->umur >= 50 || pBaru->umur < 50){
     if(pBantu->next == NULL){
      break;
     }
     pBantu = pBantu->next;
    }
    if(pBantu == q.head && pBaru->umur <50){
       pBantu->next = pBaru;
       q.tail=pBaru;
    }
    else if(pBantu == q.tail && pBaru->umur < 50){
      pBantu->next=pBaru;
      q.tail=pBaru;
    }
    else {
     pBaru->next = pBantuPrev;
     q.head=pBaru;
    }
   }

  }

  void deleteQueue(queue& q,pointer& pHapus){
    if(q.head==NULL && q.tail==NULL){
      pHapus=NULL;
      cout<<"list kosong";
    }
    else if(q.head->next==NULL){
      pHapus=q.head;
      q.head=NULL;
      q.tail=NULL;
    }
    else{
      pHapus=q.head;
      q.head=q.head->next;
      pHapus->next=NULL;

    }
  }

 void traversal(queue q){
   pointer pBantu;
   pBantu=q.head;
   while(pBantu!=NULL){
     cout<<pBantu->nama<<",";
     pBantu=pBantu->next;
   }
 }
 main(){
   pointer pb,ph;
   int n;
   createlist(q);
   cout<<"masukan banyak antrian="; cin>>n;
   for(int i=0;i<n;i++){
     createElmt(pb);
     insertQueue(pb);
   }
   traversal(q);
 }
