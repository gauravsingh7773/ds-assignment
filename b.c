#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*temp;
void append(struct node **s,int num);
void display(struct node *q);
void delete(struct node **s,int num);
int count=0;

void create()
{
    int data;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->next=NULL;
    printf("enterbthe value to node\n");
    scanf("%d",temp->data);
    count++;
}
void append(struct node **s,int num)
{
    struct node *r ,*q=*s;
    if(*s==NULL)
    {
        *s=(struct node*)malloc(sizeof(struct node));
        (*s)->prev=NULL;
        (*s)->data=num;
        (*s)->next=num;
    }
    else
    {
        while(q->next!=NULL)
            q=q->next;
        r=(struct node*)malloc(sizeof(struct node));
        r->data=num;
        r->next=NULL;
        r->prev=q;
        q->next=r;
    }
}
void display(struct node *q)
{
    while(q!=NULL)
    {
        printf("%d",q->data);
        q=q->next;
    }
    printf("\n");
}
void delete(struct node **s,int num)
{
    struct node *q=*s;
    while(q!=NULL)
    {
        if(q->data==num)
        {
            if(q==*s)
            {
                *s=(*s)->next;
                (*s)->prev=NULL;
            }
            else
            {
                if(q->next==NULL)
                    q->prev->next=NULL;
                else
                {
                    q->prev->next=q->next;
                    q->next->prev=q->prev;
                }
                free(q);
            }
            return;
        }
        q=q->next;
    }
    printf("%d not found\n",num);
}
int main()
{
    struct node *p,*q;
    p=NULL;
    append(&p,11);append(&p,55);append(&p,34);append(&p,45);append(&p,44);append(&p,32);
    printf("nodes before deletion \n");
    display(p);
    delete(&p,11);delete(&p,55);delete(&p,44);
    printf("nodes after deletion\n");
    display(p);
    return 0;
}

