#include<stdio.h>
int main()
{
	int count,i,j,temp,choice;
	printf("How many processor do you want: ");
	scanf("%d",&count);
	int output[6][count];
	for(i=0;i<count;i++)
	{
		output[0][i]=i+1;
		printf("Enter the arrival time of P-%d: ",i+1);
		scanf("%d",&output[1][i]);
		printf("Enter the burst time of P-%d: ",i+1);
		scanf("%d",&output[2][i]);
	}
	printf("What do you want:\n1. FCFS\n2. SJF Non Pre-emptive\n3. SJF Pre-emptive\n4. Priority non pre-emptive\n5. Round Robin\n5. Exit\n");
	scanf("%d",&choice);
	while(choice!=6)
	{
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
					    temp = output[k][j];
					    output[k][j] = output[k][j+1];
					    output[k][j+1] = temp;
					}
				    }
				}
			 }
			 for(i=0;i<count;i++)
			 {
				if(i==0)
				{
					output[3][i]=output[2][i]+output[1][i];
				}
				else
				{
					if(output[3][i-1] < output[1][i])
					{
					
						output[3][i] = output[1][i] + output[2][i];  
					}
					else
					{
						output[3][i] = output[3][i-1] + output[2][i];
					}
				}
				output[4][i]=output[3][i]-output[1][i];
				output[5][i]=output[4][i]-output[2][i];
			}
			printf("Output\n");
			printf("PID\tArrival Time\tBurst Time\tCompletion time\t Turn Around Time\tWaiting Time\n");
			for(i=0;i<count;i++)
			{
				printf("%d\t\t",output[0][i]);
				printf("%d\t\t",output[1][i]);
				printf("%d\t\t",output[2][i]);
				printf("%d\t\t\t",output[3][i]);
				printf("%d\t\t\t\t",output[4][i]);
				printf("%d\t\t",output[5][i]);
				printf("\n");
			}
		}
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
					    temp = output[k][j];
					    output[k][j] = output[k][j+1];
					    output[k][j+1] = temp;
					}
				    }
				}
			 }
			 for(i=0;i<count;i++)
			 {
			 	if(i==0)
			 	{
			 		output[3][i]=0;
			 	}
			 	else
			 	{
			 		output[3][i]=output[3][i-1]+output[2][i-1];
			 	}
			 }
			printf("Output\n");
			printf("PID\tArrival Time\tBurst Time\tWaiting Time\n");
			for(i=0;i<count;i++)
			{
				printf("%d\t\t",output[0][i]);
				printf("%d\t\t",output[1][i]);
				printf("%d\t\t",output[2][i]);
				printf("%d\t\t",output[3][i]);
				printf("\n");
			}
		}
		else if(choice==3)
		{
			
		}
		
		
		printf("What do you want:\n1. FCFS\n2. SJF Non Pre-emptive\n3. SJF Pre-emptive\n4. Priority non pre-emptive\n5. Round Robin\n5. Exit\n");
		scanf("%d",&choice);
	}
	
	
	return 0;
}
