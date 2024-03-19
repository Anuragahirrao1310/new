#include<stdlib.h>
#include<iostream>
using namespace std;

struct o {int a ; struct o*add }

int main
{
int n,i;
struct o *y,*head;

printf("no node  want:  ");
scanf("%d",&n);

for(i=0;i<=n;i++)
{
        if(i==0){
            struct o* y = (struct o*)malloc(sizeof(struct o));
            printf("Enter data for node %d: ", i + 1);
            scanf("%d",&y->data);
            y->add=NULL;
            head=y;
        }
         
         else
         y ->add = (struct o*)malloc(sizeof(struct o));
         y= y-> add;
            printf("Enter data for node %d: ", i + 1);
            scanf("%d",&y->data);
            y->add=NULL;
            head=y;
}
printf("THE LINKLIST IS:");
y=head;
while(y!=NULL){
    printf("y->data");
    y=y->add;
}



}
