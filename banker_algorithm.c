#include<stdio.h>
int main()
{
	int resources,processes,i,j,k,count=0,prevcount;
	printf("Enter no.of processes and resources: ");
	scanf("%d%d",&processes,&resources);
	int allocation[processes][resources],max[processes][resources],need[processes][resources],available[resources];
	printf("Enter allocation matrix: ");
	for(i=0;i<processes;i++)
	{
		for(j=0;j<resources;j++)
		{
			scanf("%d",&allocation[i][j]);
		}
	}
	printf("Enter max matrix: ");
	for(i=0;i<processes;i++)
	{
		for(j=0;j<resources;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter available resources: ");
	for(j=0;j<resources;j++)
	{
		scanf("%d",&available[j]);
	}
	for(i=0;i<processes;i++)
	{
		for(j=0;j<resources;j++)
		{
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	int finish[processes],safe[processes],work[resources];
	for(i=0;i<processes;i++)
	{
		finish[i]=0;
	}
	for(j=0;j<resources;j++)
	{
		work[j]=available[j];
	}
	while(count<processes)
	{
		prevcount=count;
		for(i=0;i<processes;i++)
		{
			if(finish[i]==0)
			{
				for(j=0;j<resources;j++)
				{
					if(need[i][j]>work[j])
					{
						break;
					}
				}
				if(j==resources)
				{
					for(k=0;k<resources;k++)
					{
						work[k]=work[k]+allocation[i][k];
					}
					safe[count++]=i;
					finish[i]=1;
				}
			}
		}
		if(prevcount==count)
		{
			printf("System is Not safe\n");
			return 0;
		}
	}
	printf("System is safe\n Safe sequence: ");
	for(i = 0; i < processes; i++)
	{
        	printf("P%d\t", safe[i]);
	}
    	return 0;
}
