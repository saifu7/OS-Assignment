#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
struct process
{
	int priority, burst_time, rem_burst_time;
//	char process_name[3];
//	void RR();
	int t;
};

void RR(struct process prc, int tq )
{
	while(1)
	{
		bool done = true;
		
	}


int main()
{
	int i, j, n, k,l,cnt = 0;
	int queue[3][2];
	printf("Enter range of priority of queues:\n");
	for(i = 0; i< 3; i++)
	{	
		printf("Queue %d:",i+1);
		for(j = 0; j<2; j++ )
		scanf("%d", &queue[i][j]);
	}
	printf("\nEnter total number of process:");
	scanf("%d", &n);
	
	struct process p[n];
	printf("Enter process's priority and burst time:\n");
	for(i = 0; i < n; i++ )
	{
		printf("Process %d:" ,i + 1);
		scanf("%d%d", &p[i].priority, &p[i].burst_time);
		p[i].rem_burst_time = p[i].burst_time;
	}
//	for(i = 0; i < n; i++ )
//	{
//		printf("Process %d:",i+1);
//		printf("%d %d", p[i].priority, p[i].burst_time);
//		printf("\n");
//	}
	
		for(i = 0; i <= i%3; i++ )
		{
			i = i%3;
			if(p[i].rem_burst_time == 0	)
			cnt++;
			if(cnt == 3)
			break;
			
			for(k = 0,l=0; k< 3; k++)
			{		
//				printf("Queue %d:",k+1);
				if(p[k].rem_burst_time >= queue[k][l] &&  p[k].rem_burst_time <= queue[k][l+1])
				{
					
					RR(p[k], 4);
				}
				if(p[k].rem_burst_time >= queue[k][l] &&  p[k].rem_burst_time <= queue[k][l+1])
				{
					PS(p[k] );
				}
				if(p[k].rem_burst_time >= queue[k][l] &&  p[k].rem_burst_time <= queue[k][l+1])
				{
					FCFS(p[k]);
				}
			}		
			
		}
	
		return 0;
}
