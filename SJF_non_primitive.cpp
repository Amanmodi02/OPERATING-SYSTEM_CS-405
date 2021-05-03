#include<iostream>
using namespace std;

float pros[10][6];
void swap(float *a, float *b) 
{
	float z = *a;
	*a = *b;
	*b = z;
}

class SJFNonPrem
{
	int num;	
 public:
    int takeInput()
	{
        cout<<endl;
        cout<<"======================================================================="<<endl;
		cout<<"Enter number of Process : ";
		cin>>num;
        cout<<"======================================================================="<<endl;
		for(int i=0; i<num; i++) 
        {
            cout<<"======================================================================="<<endl;
			cout<<endl;
            cout<<"Process "<<i+1<<endl;
			cout<<"Enter Process Id : ";
			cin>>pros[i][0];
            cout<<"======================================================================="<<endl;
			cout<<"Enter Arrival Time : ";
			cin>>pros[i][1];
            cout<<"======================================================================="<<endl;
			cout<<"Enter Burst Time: ";
			cin>>pros[i][2];
            cout<<"======================================================================="<<endl;
		}
        return 0;	
	}

	void display(int n)
	{
		if(n==0)
		{
            cout<<"======================================================================="<<endl;
			cout<<"\n--------------------Before Arrange------------------\n\n";
			cout<<" || Process ID || Arrival Time || Burst Time || "<<endl;
			for(int i=0; i<num; i++)
			 {
				cout<<pros[i][0]<<"\t\t"<<pros[i][1]<<"\t\t"<<pros[i][2]<<endl;
                cout<<"======================================================================="<<endl;
			 }
		}
		else
        {
            cout<<"======================================================================="<<endl;
			cout<<"\n-----------------------Final Result--------------------\n\n";
			cout<<" || Process ID || Arrival Time || Burst Time || Waiting Time || Turn Around Time || "<<endl;
			for(int i=0; i<num; i++)
			{
				cout<<pros[i][0]<<"\t\t"<<pros[i][1]<<"\t\t"<<pros[i][2]<<"\t\t"<<pros[i][4]<<"\t\t"<<pros[i][5]<<"\n";
                cout<<"======================================================================="<<endl;
			}
		}
	}

	void setArrival(float pros[][6])
    {
		for(int i=0; i<num; i++)
        {
			for(int j=0; j<num-i-1; j++)
            {
				if(pros[j][1] > pros[j+1][1])
                {
					for(int k=0; k<5; k++)
                    {
						swap(pros[j][k], pros[j+1][k]);
					}
				}
			}
		}
	}

	void completionTime(float pros[][6]) 
    {
		float tempCt;
		int val;

		pros[0][3] = pros[0][1] + pros[0][2];
		pros[0][5] = pros[0][3] - pros[0][1];
		pros[0][4] = pros[0][5] - pros[0][2];

		for(int i=1; i<num; i++) 
        {
			tempCt = pros[i-1][3];
			float lowestBt = pros[i][2];

			for(int j=i; j<num; j++) 
            {
				if(tempCt >= pros[j][1] && lowestBt >= pros[j][2]) 
                {
					lowestBt = pros[j][2];
					val = j;
				}
			}
			pros[val][3] = tempCt + pros[val][2];
			pros[val][5] = pros[val][3] - pros[val][1];
			pros[val][4] = pros[val][5] - pros[val][2];

			for(int k=0; k<6; k++) 
            {
				swap(pros[val][k], pros[i][k]);
			}
		}
	}
};

int main() 
{
	SJFNonPrem obj;
	obj.takeInput();
	obj.display(0);
	obj.setArrival(pros);
	obj.completionTime(pros);
	obj.display(1);	
}