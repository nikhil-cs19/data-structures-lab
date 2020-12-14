#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node* link;
};
struct node* first;
struct node* first2;
void insert_rear(){
struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter the element\n");
scanf("%d",&temp->info);
temp->link=NULL;
if(first==NULL){
    first=temp;
}
else{
    struct node* p;
    p=first;
    while(p->link!=NULL){
        p=p->link;
    }
   p->link=temp;
}
}
void insert_rear2(){
struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter the element\n");
scanf("%d",&temp->info);
temp->link=NULL;
if(first2==NULL){
    first2=temp;
}
else{
    struct node* p;
    p=first2;
    while(p->link!=NULL){
        p=p->link;
    }
   p->link=temp;
}
}
void display(){
struct node* temp;
if(first==NULL){
    printf("list is empty\n");
}
else{
    temp=first;
    while(temp!=NULL){
    printf("%d\n",temp->info);
    temp=temp->link;
}
}
}
int length(){
int len=1;
struct node* temp;
temp=first;
if(first==NULL){
    len=0;
}
else{
    while(temp->link!=NULL){
    temp=temp->link;
    len++;
}
}
return len;
}
void delete_rear(){
  struct node* temp;
  struct node* p;
  int len;
  len=length();
  temp=first;
  p=first;
  if(first==NULL){
    printf("List is empty\n");
  }
  else{
    while(temp->link!=NULL){
    temp=temp->link;
  }
  for(int i=1;i<len-1;i++){
    p=p->link;
  }
  p->link=NULL;
  free(temp);
  }
}
void delete_front(){
struct node* temp;
temp=first;
first=temp->link;
temp->link=NULL;
free(temp);
}

void Asc_sort(){
struct node* temp;
struct node* p;
int tmp;
temp=first;
while(temp!=NULL){
    p=temp;
    while(p!=NULL){
        if(temp->info>p->info){
            tmp=p->info;
            p->info=temp->info;
            temp->info=tmp;
        }
        p=p->link;
    }
    temp=temp->link;
}
}
void Dsc_sort(){
struct node* temp;
struct node* p;
int tmp;
temp=first;
while(temp!=NULL){
    p=temp;
    while(p!=NULL){
        if(temp->info<p->info){
            tmp=p->info;
            p->info=temp->info;
            temp->info=tmp;
        }
        p=p->link;
    }
    temp=temp->link;
}
}
void reverse(){
if(first==NULL){
    printf("list is empty\n");
}
else{
    struct node *temp,*cur;
    while(first!=NULL){
        temp=first;
        first=first->link;
        temp->link=cur;
        cur=temp;
    }
    first=cur;
}
}
void concatenate(){
struct node* temp;
temp=first;
while(temp->link!=NULL){
    temp=temp->link;
}
temp->link=first2;
}
void main(){
int choice=80;
while(choice!=0){
    printf("Enter your choice\n1. Insert into list1 \n2. Insert into list2 \n3. Display\n4. Sort \n5. Reverse \n6. Concatenate\n7. Stack\n8. Queue\n");
    scanf("%d",&choice);
    switch(choice){
      case 0:break;
      case 1:{
         int n;
         printf("Enter the no of elements to be inserted\n");
         scanf("%d",&n);
         for(int i=0;i<n;i++){
            insert_rear();
         }
         break;
      }
      case 2:{
         int n;
         printf("Enter the no of elements to be inserted\n");
         scanf("%d",&n);
         for(int i=0;i<n;i++){
            insert_rear2();
         }
         break;
      }
      case 3:{
        display();
        break;
      }
      case 4:{
        int k;
        printf("1. Ascending sort\n2. Descending sort\n");
        scanf("%d",&k);
        if(k==1)
            Asc_sort();
        if(k==2)
            Dsc_sort();
        break;
      }
      case 5:{
        reverse();
        break;
      }
      case 6:{
        concatenate();
        break;
      }
      case 7:{
       int k=30;
       while(k!=0){
        printf("Enter your choice\n0.Exit\n1.Push \n2.pop \n3.display\n");
        scanf("%d",&k);
        switch(k){
         case 0:{
             break;
         }
         case 1:{
         insert_rear();
         break;
         }
         case 2:{
         delete_rear();
         break;
         }
         case 3:{
         display();
         break;
         }
         default:{
         printf("Wrong choice!\n");
         break;
         }
        }
       }
       break;
      }
      case 8:{
       int k=30;
       while(k!=0){
        printf("Enter your choice\n0.Exit\n1.Push \n2.pop \n3.display\n");
        scanf("%d",&k);
        switch(k){
         case 0:break;
         case 1:{
         insert_rear();
         break;
         }
         case 2:{
         delete_front();
         break;
         }
         case 3:{
         display();
         break;
         }
         default:{
         printf("Wrong choice!\n");
         break;
         }
        }
       }
       break;
      }
      default:{
        printf("Wrong choice!\n");
        break;
      }
    }
}
}
