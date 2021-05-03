#include<iostream>
using namespace std;

void findWaitingTime(int processes[],int n,int bt[],int wt[])
{
	wt[0]=0;
	
		for(int i=1;i<n;i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
	} 
}

void findTurnAroundTime(int processes[],int n,int bt[],int wt[],int tat[])
{
	for(int i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
}

void findAverageTime(int processes[],int n,int bt[])
{
	int wt[n],tat[n],total_wt=0,total_tat=0;
	findWaitingTime(processes,n,bt,wt);
	findTurnAroundTime(processes,n,bt,wt,tat);
    cout<<endl;
    cout<<"======================================================================="<<endl;
	cout<<" || Processes "<<" ||  Burst Time "<<" ||  Waiting Time "<<" || Turn Around Time || "<<endl;
	
	for(int i=0;i<n;i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		cout<<"\t"<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;		
	}
    cout<<"======================================================================="<<endl;
	cout<<"average waiting time "<<total_wt/4.0<<" ms \n";
	cout<<"average turn around time "<<total_tat/4.0<<" ms";
    cout<<endl;
    cout<<"======================================================================="<<endl;
	cout<<endl;
}

int main()
{
	int processes[]={1,2,3};
	int n=sizeof processes/sizeof processes[0];
	int burst_time[]={15,12,9,};
	findAverageTime(processes,n,burst_time);
	return 0;	
} 