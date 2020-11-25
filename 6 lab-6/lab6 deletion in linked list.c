#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node* link;
};
struct node* first;
void insert_rear(){
struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter the integer\n");
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
void insert_front(){
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter the integer\n");
  scanf("%d",&temp->info);
  temp->link=NULL;
    if(first==NULL){
        first=temp;
}
    else{
        temp->link=first;
        first=temp;
    }
}
void insert_loc(){
 struct node* temp;
 struct node* p;
 int loc,count=1;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("enter the location at which you want to insert\n");
 scanf("%d",&loc);
 printf("Enter the integer\n");
 scanf("%d",&temp->info);
 temp->link=NULL;
 p=first;
 while(loc>count){
    p=p->link;
    count+=1;
 }
 temp->link=p->link;
 p->link=temp;
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
void delete_pos(){
struct node* temp;
struct node* p;
int loc,i=1;
temp=first;
printf("Enter the location\n");
scanf("%d",&loc);
if(loc>length()){
    printf("Invalid location\n");
}
else{
    while(i<loc-1){
    temp=temp->link;
    i++;
}
   p=temp->link;
   temp->link=p->link;
   p->link=NULL;
   free(p);
}
}
void delete_front(){
struct node* temp;
temp=first;
first=temp->link;
temp->link=NULL;
free(temp);
}


void main(){
int choice=15,len;
while(choice!=0){
    printf("Enter your choice\n 0 Exit\n 1 insert at the end \n 2 insert in the front \n 3 insert at a location \n 4 display the nodes\n 5 delete in the front \n 6 delete at a position \n 7 delete at the end \n");
    scanf("%d",&choice);
    switch(choice){
       case 0:{
         break;
       }
       case 1:{
         insert_rear();
         break;
       }
       case 2:{
         insert_front();
         break;
       }
       case 3:{
         insert_loc();
         break;
       }
       case 4:{
        display();
        break;
       }
       case 5:{
        delete_front();
        break;
       }
       case 6:{
        delete_pos();
        break;
       }
       case 7:{
        delete_rear();
        break;
       }
       default:{
           printf("Wrong choice!\n");
           break;
       }
    }
}
printf("over");
}
