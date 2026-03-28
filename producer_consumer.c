#include<stdio.h>

int main()
{
    int mutex=1, full=0, empty=3;
    int x=0;
    int choice;

    while(1)
    {
        printf("\n1. Produce");
        printf("\n2. Consume");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            if(mutex==1 && empty!=0)
            {
                mutex=0;
                full=full+1;
                empty=empty-1;
                x=x+1;

                printf("Producer produced item %d",x);

                mutex=1;
            }
            else
            {
                printf("Buffer is full");
            }
        }

        else if(choice==2)
        {
            if(mutex==1 && full!=0)
            {
                mutex=0;
                printf("Consumer consumed item %d",x);

                full=full-1;
                empty=empty+1;
                x=x-1;

                mutex=1;
            }
            else
            {
                printf("Buffer is empty");
            }
        }

        else if(choice==3)
        {
            break;
        }
    }
}
