#include<stdio.h>
#include<conio.h>
struct node
 {
  int info;
  struct node *rlink;
  struct node *llink;
 };
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
 {
printf("mem full\n");
exit(0);
 }
 return x;
}
void freenode(NODE x)
{
free(x);
}
NODE insert(NODE root,int item)
{
NODE temp,cur,prev;
temp=getnode();
temp->rlink=NULL;
temp->llink=NULL;
temp->info=item;
if(root==NULL)
 return temp;
prev=NULL;
cur=root;
while(cur!=NULL)
{
prev=cur;
cur=(item<cur->info)?cur->llink:cur->rlink;
}
if(item<prev->info)
prev->llink=temp;
else
prev->rlink=temp;
return root;
}
void preorder(NODE root)
{
if(root!=NULL)
 {
printf("%d\n",root->info);
preorder(root->llink);
preorder(root->rlink);
  }
 }
void postorder(NODE root)
{
if(root!=NULL)
 {

postorder(root->llink);
postorder(root->rlink);
printf("%d\n",root->info);
  }
 }
void inorder(NODE root)
{
if(root!=NULL)
 {

inorder(root->llink);
printf("%d\n",root->info);
inorder(root->rlink);
  }
 }
void main()
{
int item,choice;
NODE root=NULL;
for(;;)
{
printf("1.insert\n2.pre\n3.post\n4.in\n");
printf("enter the choice\n");
scanf("%d",&choice);
switch(choice)
 {
  case 1:printf("enter the item\n");
		scanf("%d",&item);
		 root=insert(root,item);
		 break;
  case 2:preorder(root);
		 break;
  case 3:postorder(root);
		 break;
  case 4:inorder(root);
		 break;
default:exit(0);
		  break;
	  }
	}
 }
