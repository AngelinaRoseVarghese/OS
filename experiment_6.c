#include<stdio.h>
int main()
{
	int count,i,j,temp,choice,quantum,avg=0;
	printf("How many processor do you want: ");
	scanf("%d",&count);
	int output[8][count];   // extra row for priority
	for(i=0;i<count;i++)
	{
		output[0][i]=i+1;
		printf("Enter the arrival time of P-%d: ",i+1);
		scanf("%d",&output[1][i]);
		printf("Enter the burst time of P-%d: ",i+1);
		scanf("%d",&output[2][i]);
	}
	printf("What do you want:\n1. FCFS\n2. SJF Non Pre-emptive\n3. Priority non pre-emptive\n4. Round Robin\n5. Exit\n");
	scanf("%d",&choice);
	while(choice!=5)
	{
/* ---------------- FCFS ---------------- */
		if(choice==1)
		{
			for(i=0;i<count-1;i++)
			{
				for(j=0;j<count-i-1;j++)
				{
					if(output[1][j] > output[1][j+1])
					{
						for(int k=0;k<3;k++)
						{
							temp=output[k][j];
							output[k][j]=output[k][j+1];
							output[k][j+1]=temp;
						}
					}
				}
			}
			for(i=0;i<count;i++)
			{
				if(i==0)
					output[3][i]=output[1][i]+output[2][i];
				else
				{
					if(output[3][i-1] < output[1][i])
						output[3][i]=output[1][i]+output[2][i];
					else
						output[3][i]=output[3][i-1]+output[2][i];
				}
				output[4][i]=output[3][i]-output[1][i];
				output[5][i]=output[4][i]-output[2][i];
			}
			printf("\nPID\AT\BT\CT\TAT\WT\n");
			for(i=0;i<count;i++)
			{
				printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
				output[0][i],output[1][i],output[2][i],
				output[3][i],output[4][i],output[5][i]);
			}
			avg = 0;
			for(i=0;i<count;i++)
			{
				avg=avg+output[5][i];
			}
			avg=avg/count;
			printf("Avg.WT:%d\n",avg);
		}
/* ---------------- SJF Non Preemptive ---------------- */
		else if(choice==2)
		{
			for(i=0;i<count-1;i++)
			{
				for(j=0;j<count-i-1;j++)
				{
					if(output[2][j] > output[2][j+1])
					{
						for(int k=0;k<3;k++)
						{
							temp=output[k][j];
							output[k][j]=output[k][j+1];
							output[k][j+1]=temp;
						}
					}
				}
			}
			output[3][0]=0;
			for(i=1;i<count;i++)
				{
				output[3][i]=output[3][i-1]+output[2][i-1];
				}
			printf("\nPID\AT\BT\WT\n");
			for(i=0;i<count;i++)
			{
				printf("P%d\t%d\t%d\t%d\n",
				output[0][i],output[1][i],output[2][i],output[3][i]);
			}
			avg = 0;
			for(i=0;i<count;i++)
			{
				avg=avg+output[3][i];
			}
			avg=avg/count;
			printf("Avg.WT:%d\n",avg);
		}
/* ---------------- Priority Non Preemptive ---------------- */
		else if(choice==3)
		{
			printf("Enter priority for each process (smaller number = higher priority)\n");
			for(i=0;i<count;i++)
			{
				printf("Priority of P%d: ",i+1);
				scanf("%d",&output[6][i]);
			}
			for(i=0;i<count-1;i++)
			{
				for(j=0;j<count-i-1;j++)
				{
					if(output[6][j] > output[6][j+1])
					{
						for(int k=0;k<4;k++)
						{
							temp=output[k][j];
							output[k][j]=output[k][j+1];
							output[k][j+1]=temp;
						}
						temp=output[6][j];
						output[6][j]=output[6][j+1];
						output[6][j+1]=temp;
					}
				}
			}
			output[3][0]=output[2][0];
			for(i=1;i<count;i++)
				{
				output[3][i]=output[3][i-1]+output[2][i];
				}
			printf("\nPID\tBT\tPriority\tCT\n");
			for(i=0;i<count;i++)
			{
				printf("P%d\t%d\t%d\t\t%d\n",
				output[0][i],output[2][i],output[6][i],output[3][i]);
			}
			avg = 0;
			for(i=0;i<count;i++)
			{
				output[5][i] = output[3][i] - output[2][i];
				avg=avg+output[5][i];
			}
			avg=avg/count;
			printf("Avg.WT:%d\n",avg);
		}
/* ---------------- Round Robin ---------------- */
		else if(choice==4)
{
    printf("Enter Time Quantum: ");
    scanf("%d",&quantum);
    int remaining[count],time=0,completed=0;
    for(i=0;i<count;i++)
    {
        remaining[i]=output[2][i];   // copy burst time
    }
    while(completed < count)
    {
        for(i=0;i<count;i++)
        {
            if(remaining[i] > 0)
            {
                if(remaining[i] > quantum)
                {
                    time = time + quantum;
                    remaining[i] = remaining[i] - quantum;
                }
                else
                {
                    time = time + remaining[i];
                    output[3][i] = time;   // completion time
                    remaining[i] = 0;
                    completed++;
                }
            }
        }
    }
    printf("\nPID\tBurst Time\tCompletion Time\n");
    for(i=0;i<count;i++)
    {
        printf("P%d\t%d\t\t%d\n",
        output[0][i],output[2][i],output[3][i]);
    }
	avg = 0;
	for(i=0;i<count;i++)
			{
				output[5][i] = output[3][i] - output[1][i] - output[2][i];
				avg=avg+output[5][i];
			}
	avg=avg/count;
			printf("Avg.WT:%d\n",avg);
}

		printf("\nWhat do you want:\n1.FCFS\n2.SJF Non Pre-emptive\n3.Priority Non Pre-emptive\n4.Round Robin\n5.Exit\n");
		scanf("%d",&choice);
	}

	return 0;
}
