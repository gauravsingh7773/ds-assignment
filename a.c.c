#include<stdio.h>
#include<stdlib.h>
void append();
int len;
void addatbegin(void);
struct node
{
    int data;
    struct node *link;
};
struct node *root=NULL;
void main()
{
    int t;
    while(1)
{
    printf("single list operations: \n");
    printf("1:append\n");
    printf("2.begin\n");
    printf("3.after\n");
    printf("4.length\n");
    printf("5.display\n");
    printf("6.delete\n");
    printf("7.quit\n");
    printf("enter the choice:");
    scanf("%d",&t);
    switch(t)
    {
        case 1:append();
               break;
        case 2:begin();
               break;
        case 3:after();
               break;
        case 4: length();
               break;
        case 5: display();
               break;
        case 6: delete();
               break;
        case 7: exit(1);
               default: printf("invalid choice\n");
    }

}

}
void append()
{
   struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("enter the node data:");
  scanf("%d",&temp->data);
  temp->link=NULL;
  if(root==NULL)
  {
      root=temp;

  }
  else
  {
      struct node *p;
      p=root;
      while(p->link !=NULL)
        {
            p=p->link;
        }
        p->link=temp;
  }
}
int lenth()
{
    int count =0;
    struct node *temp;
    temp=root;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    return count;

}
void display()
{
    struct node *temp;
    temp=root;
    if(temp==NULL)
    {
        printf("list is empty\n\n");

    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->link;

        }
        printf("\n\n");

    }
}
