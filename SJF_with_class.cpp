#include<iostream>
using namespace std;

class SJF
{
	int p[20],bt[20],wt[20],tat[20];
	float wtavg,tatavg;
	int i,k,n,temp;
	public:
		void takeBT()
	{
        cout<<endl;
        cout<<"======================================================================="<<endl;
		cout<<"Enter The Number Of Processes --> ";
		cin>>n;
        cout<<"======================================================================="<<endl;
		for (i=0;i<n;i++)
		{
			p[i]=i;
            cout<<"======================================================================="<<endl;
			cout<<"Enter Burst Time For Process --> "<<i+1<<" ";
			cin>>bt[i];
            cout<<"======================================================================="<<endl;
		}
	}
	
	void sortBT()
	{
		for(i=0;i<n;i++)
			for(k=i+1;k<n;k++)
			if(bt[i]>bt[k])
			{
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
				
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
			}
	}
	
	void findAverageTime()
	{
		wt[0]=wtavg=0;
		tat[0]=tatavg=bt[0];
		
		for(i=1;i<n;i++)
		{
			wt[i]=wt[i-1]+bt[i-1];
			tat[i]=tat[i-1]+bt[i];
			wtavg=wtavg+wt[i];
			tatavg=tatavg+tat[i];
		}
		wtavg=wtavg/n;
		tatavg=tatavg/n;
	}
	
	void display()
	{	
        cout<<"======================================================================="<<endl;
		cout<<" || Processes "<<" ||  Burst Time "<<" || Waiting time "<<" || Turn Around Time || "<<endl;	
			
		for(int i=0;i<n;i++)
		{
			cout<<"\t"<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;	
		} 
		cout<<"======================================================================="<<endl;
		cout<<"Average Waiting Time --> "<<wtavg<<" ms "<<endl;
		cout<<"Average Waiting Time --> "<<wtavg<<" ms "<<endl;
		cout<<"Average Turn Around Time --> "<<tatavg<<" ms "<<endl;
        cout<<"======================================================================="<<endl;
		}
};

int main()
{
	SJF obj1;
	obj1.takeBT();
	obj1.sortBT();
	obj1.findAverageTime();
	obj1.display();
}