#include<stdio.h>
#include<stdlib.h>
int queue;
bool isqueue_over(int t, int k)
{
	if(t <= 10 && k == 0)
	{
		queue = queue % 3 + 1;
		return true;	
	}
	else
	return false;
}
struct process
{
	int priority, burst_time, rem_burst_time;
//	char process_name[3];
//	void RR();
	int t;
	int wt;
	static int total_proc;
};

void RR(struct process prc, int tq , int i)
{
	int t = 0;
		while(prc[i].rem_burst_time > 0)
		{
			if(prc[i].rem_burst_time > 0 )
			{
				if(prc[i].rem_burst_time > 10 && t == 0)
				{
					t = t + 10;
					prc[i].rem_burst_time -= 10;
					queue = 2;
					break; 
				}
				if(prc[i].rem_burst_time > tq  && prc[i].rem_burst_time < 10)
				{
					t = t + tq;			
					prc[i].rem_burst_time -=  tq;
					if(isqueue_over(t, prc[i].rem_burst_time ))
					{
						break;
					}
				}
				else
				{
					t = t + prc[i].rem_burst_time;
					prc[i].wt = t - tq;			
					prc[i].rem_burst_time = 0;
					
				}
			}
		}
		if(queue == 2)
		break;
}




















int main()
{
	int i, j, n, k,l,cnt = 0;
	int prq[3][2];
	printf("Enter range of priority of queues:\n");
	for(i = 0; i< 3; i++)
	{	
		printf("Queue %d:",i+1);
		for(j = 0; j<2; j++ )
		scanf("%d", &prq[i][j]);
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

	if(p[0].priority >= prq[0][0] && p[0].priority <= prq[0][1]  )
		queue = 1;
	else if(p[0].priority >= prq[1][0] && p[0].priority <= prq[1][1]  )
		queue = 2;
		else
		queue = 3;
	
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
				if(p[k].rem_burst_time >= prq[k][l] &&  p[k].rem_burst_time <= prq[k][l+1] && queue = 1)
				{
					
					RR(p[k], 4, k);
				}
				if(p[k].rem_burst_time >= prq[k][l] &&  p[k].rem_burst_time <= prq[k][l+1] && queue = 2)
				{
					PS(p[k] );
				}
				if(p[k].rem_burst_time >= prq[k][l] &&  p[k].rem_burst_time <= prq[k][l+1] && queue = 3)
				{
					FCFS(p[k]);
				}
			}		
			
		}
		return 0;
}
