#include <stdio.h>
#include <stdlib.h>
int main()
{
    int head, i, j, choice, temp;
    int array[10];
    printf("Enter head position: ");
    scanf("%d", &head);
    array[0] = head;
    for(i = 1; i < 10; i++) 
    {
        array[i] = rand() % 5000;
    }
    for(i = 0; i < 10; i++) 
    {
        for(j = i + 1; j < 10; j++)   
        {
            if(array[i] > array[j]) 
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("\nRequests (including head): ");
    for(i = 0; i < 10; i++) 
    {
        printf("%d\t", array[i]);
    }
    while(1) 
    {
        printf("\n\nMenu:\n 1.SSTF\n 2.C-Scan\n 3.Look\n 4.Exit\n");
        scanf("%d", &choice);
        if(choice == 1)
        {
            int visited[10] = {0};
            int totalSSTF = 0;
            int currentHead = head;
            printf("\nSSTF head movements: %d", currentHead);
            for(i = 1; i < 10; i++) 
            {
                int minDistance = 10000;
                int nearestIndex = -1;
                for(j = 1; j < 10; j++)
                {
                    if(!visited[j])
                    {
                        int distance = abs(currentHead - array[j]);
                        if(distance < minDistance)
                        {
                            minDistance = distance;
                            nearestIndex = j;
                        }
                    }
                }
                totalSSTF += minDistance;
                currentHead = array[nearestIndex];
                visited[nearestIndex] = 1;
                printf(" \t%d\t", currentHead);
            }
            printf("\nTotal Head Movement (SSTF) = %d\n", totalSSTF);
        }
        else if(choice == 2) 
        {
            int totalCSCAN = 0;
            int currentHead = head;
            int maxCylinder = 4999;
            printf("\nC-SCAN head movements: %d", currentHead);
            for(i = 1; i < 10; i++)
            {
                if(array[i] >= head) 
                {
                    totalCSCAN += abs(currentHead - array[i]);
                    currentHead = array[i];
                    printf("\t%d\t", currentHead);
                }
            }
            totalCSCAN += abs(currentHead - maxCylinder);
            currentHead = 0;
            totalCSCAN += maxCylinder;
            printf(" \t%d", maxCylinder);
            printf(" \t%d", currentHead);
            for(i = 1; i < 10; i++)   
            {
                if(array[i] < head) 
                {
                    totalCSCAN += abs(currentHead - array[i]);
                    currentHead = array[i];
                    printf(" \t%d", currentHead);
                }
            }
            printf("\nTotal Head Movement (C-SCAN) = %d\n", totalCSCAN);
        }
        else if(choice == 3)   
        {
            int totalLOOK = 0;
            int currentHead = head;
            printf("\nLOOK head movements: %d", currentHead);
            for(i = 1; i < 10; i++) 
            {
                if(array[i] >= head)
                {
                    totalLOOK += abs(currentHead - array[i]);
                    currentHead = array[i];
                    printf(" \t%d", currentHead);
                }
            }
            for(i = 9; i >= 1; i--)   
            {
                if(array[i] < head)
                {
                    totalLOOK += abs(currentHead - array[i]);
                    currentHead = array[i];
                    printf(" -> %d", currentHead);
                }
            }
            printf("\nTotal Head Movement (LOOK) = %d\n", totalLOOK);
        }

        else if(choice == 4) 
        {
            break;
        }
        else 
        {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
