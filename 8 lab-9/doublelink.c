#include<stdio.h>
#include<stdlib.h>
struct node{
struct node* left;
int info;
struct node* right;
};
struct node* first;
void insert_rear(){
struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter the element to be inserted\n");
scanf("%d",&temp->info);
temp->left=NULL;
temp->right=NULL;
if(first==NULL){
    first=temp;
}
else{
    struct node* p;
    p=first;
    while(p->right!=NULL){
        p=p->right;
    }
    p->right=temp;
    temp->left=p;
}
}
void insert_front(){
struct node* temp;
temp=(struct node*)malloc(sizeof(struct node*));
printf("Enter the element to be inserted\n");
scanf("%d",&temp->info);
temp->right=NULL;
temp->left=NULL;
if(first==NULL){
    first=temp;
}
else{
    first->left=temp;
    temp->right=first;
    first=temp;
}
}
void insert_specific(){
struct node* temp;
int loc;
temp=(struct node*)malloc(sizeof(struct node*));
printf("Enter the location at which you want insert\n");
scanf("%d",&loc);
printf("Enter the element to be inserted\n");
scanf("%d",&temp->info);
if(first==NULL){
    first=temp;
}
else if(loc==1){
    first->left=temp;
    temp->right=first;
    first=temp;
}
else{
    struct node* p;
    p=first;
    for(int i=1;i<loc;i++){
    p=p->right;
    }
    temp->right=p;
    temp->left=p->left;
    p->left->right=temp;
    p->left=temp;
}
}
void delete_specific(){
struct node* temp;
temp=first;
int loc;
printf("Enter the location of the node to be deleted\n");
scanf("%d",&loc);
if(loc==1){
    first=temp->right;
    free(temp);
    first->left=NULL;
}
else {
    for(int i=1;i<loc;i++){
    temp=temp->right;
   }
   if(temp->right==NULL){
      temp->left->right=NULL;
      free(temp);
   }
   else{
    temp->right->left=temp->left;
    temp->left->right=temp->right;
    free(temp);
   }
}
}
void display(){
if(first==NULL){
    printf("list is empty\n");
}
else{
    struct node* temp;
    temp=first;
    while(temp!=NULL){
      printf("%d\n",temp->info);
      temp=temp->right;
    }
}
}
void main(){
int choice;
while(free){
    printf("Enter your choice \n 0 Exit \n 1 Insert \n 2 Delete \n 3 Display \n");
    scanf("%d",&choice);
    switch(choice){
    case 0:{
    exit(0);
    break;
    }
    case 1:{
    insert_specific();
    break;}
    case 2:{
    delete_specific();
    break;}
    case 3:{
    display();
    break;}
    default:{
    printf("wrong choice!\n");
    break;
    }
}
}
}
