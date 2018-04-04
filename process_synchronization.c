#include<stdio.h>
#include<stdlib.h>
int queue;

struct process
{
	int priority, burst_time, rem_burst_time;
	int wt;
};

void RR(struct process *prc, int tq , int i)
{
	int t = 0;
		while(prc[i].rem_burst_time > 0)
		{
				if(prc[i].rem_burst_time > 10 && t == 0)
				{
					t = t + 10;
					prc[i].rem_burst_time -= 10;
					prc[i].wt = 10 - prc[i].burst_time;
					queue = 2;
					break; 
				}
				if(prc[i].rem_burst_time > tq  && prc[i].rem_burst_time <= 10)
				{
					t = t + tq;			
					prc[i].rem_burst_time -=  tq;
					if(t == 10)
					{
						queue = 2;
						prc[i].wt = t - prc[i].burst_time;
						break;
					}
				}
				else
				{
					t = t + prc[i].rem_burst_time;
					prc[i].wt = t - tq;			
					prc[i].rem_burst_time = 0;
					break;
					
				}
		}
		if(queue == 2)
		return;
}

void PS(struct process *prc , int i)
{
	int t = 0;
	while(prc[i].rem_burst_time > 0)
	{
		if(prc[i].rem_burst_time > 10  && t == 0)
		{
			t = t + 10;
			prc[i].rem_burst_time -= 10;
			prc[i].wt = 10 - prc[i].burst_time;
			queue = 3;
			break;
		}
		if(prc[i].rem_burst_time <= 10)
		{
			t = t + prc[i].rem_burst_time;
			prc[i].wt = t - prc[i].burst_time;
			if(t == 10)
			{
				queue = 3;
				break;
			}
		}
	}
}
void FCFS(struct process *prc , int i)
{
	int t = 0;
	while(prc[i].rem_burst_time > 0)
	{
		if(prc[i].rem_burst_time > 10 && t == 0)
		{
			t = t + 10;
			prc[i].rem_burst_time -= 10;
			prc[i].wt = 10 - prc[i].burst_time;
			queue = 1;
			break;	
		}
		if(prc[i].rem_burst_time <= 10)
		{
			t = t + prc[i].rem_burst_time;
			prc[i].wt = t - prc[i].burst_time;
			if(t == 10)
			{
				queue = 1;
				break;
			}
		}
	}
	 
}

int main()
{
	int i, j, n,sum = 0, twt = 0, f ;
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
	
	struct process *p;
	printf("Enter process's priority and burst time:\n");
	for(i = 0; i < n; i++ )
	{
		printf("Process %d:" ,i + 1);
		scanf("%d%d", &p[i].priority, &p[i].burst_time);
		p[i].rem_burst_time = p[i].burst_time;
	}
	for(i = 0; i < n; i++ )
	{
		printf("Process %d:",i+1);
		printf("%d %d", p[i].priority, p[i].burst_time);
		printf("\n");
	}

	if(p[0].priority >= prq[0][0] && p[0].priority <= prq[0][1]  )
		queue = 1;
	else if(p[0].priority >= prq[1][0] && p[0].priority <= prq[1][1]  )
		queue = 2;
		else
		queue = 3;

	int  k = 0 , l = 0, m = 0;			
			while(1)
			{		
				k = k%3;
				l = l%3;
				m = m %n;
				if(p[m].rem_burst_time >= prq[k][l] &&  p[k].rem_burst_time <= prq[k][l+1] && queue == 1)
				{
					
					RR(&p, 4, m);
				}
				if(p[m].rem_burst_time >= prq[k][l] &&  p[k].rem_burst_time <= prq[k][l+1] && queue == 2)
				{
					
					PS(&p,m );
					
				}
				if(p[m].rem_burst_time >= prq[k][l] &&  p[k].rem_burst_time <= prq[k][l+1] && queue == 3)
				{
					FCFS(&p,m);
				}
				
				k++;
				l++;
				m++;
				for(f = 0 ;f < n;f++)
				{
					sum = sum + p[f].rem_burst_time;
					twt = twt + p[f].wt;
				}
				if(sum == 0)
				{
					break;
				}
			}		
			printf("\nAverage waiting time: %d", twt/n);
			
	return 0;
}
