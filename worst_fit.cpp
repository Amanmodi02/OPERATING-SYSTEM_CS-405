#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
		
struct bestFit
{
	int blocksize[10], processsize[10],processId[10], blockno,blockId[10], processno, flags[10], allocation[10], i, j;	
	public:
		void sorting()
		{	
			int n=blockno;
			for(i=0;i<n-1;i++)
			{
				int max=i;
				for(j=i+1;j<n;j++)
					if(blocksize[j]>blocksize[max])
						max=j;
				swap(&blocksize[max],&blocksize[i]);
				swap(&blockId[max],&blockId[i]);				
			}
			n=processno;
			for(i=0;i<n-1;i++)
			{
				int max=i;
				for(j=i+1;j<n;j++)
					if(processsize[j]>processsize[max])
						max=j;
				swap(&processsize[max],&processsize[i]);
				swap(&processId[max],&processId[i]);				
			}
		}

		void takeInput()
        {
			for(i=0; i<10; i++)
			{
				flags[i] = 0;
				allocation[i] = -1;
			}
			cout<<endl;
            cout<<"======================================================================="<<endl;
            cout<<"Fill The Number Of Blocks --> "<<endl;
			cin>>blockno;
			cout<<"Fill Size Of Each Block --> "<<endl;
			
			for(i = 0; i<blockno; i++)
			{			
				cin>>blocksize[i];
				blockId[i]=i;
			}
            cout<<endl;
			cout<<"Fill The Number Of Processes --> "<<endl;
			cin>>processno;
			cout<<"Enter Each Process Size --> "<<endl;
			
			for(i = 0; i<processno; i++)
			{
				cin>>processsize[i]; 
				processId[i]=i;
			}		
		}

		void allocate()
			{
				for(i=0; i< processno; i++)
				for(j = 0; j<blockno; j++)
				if(flags[j] == 0 && blocksize[j]> processsize[i])
				{
					allocation[j] = i;
					flags[j] = 1;
					break;
				}	
			}

		void  display()
			{
                cout<<endl;
                cout<<"======================================================================="<<endl;
				cout<<" || Block Number || \tSize\t || Process Number || \tSize \t|| "<<endl;
                cout<<"======================================================================="<<endl;
				for(i=0; i<blockno; i++)
				{
					cout<<"\n"<<blockId[i]<<"\t\t\t"<<blocksize[i]<<"\t\t\t";
					if(flags[i] == 1)
						cout<<processId[allocation[i]]<<"\t\t\t"<<processsize[allocation[i]]<<"\n";
					else
						cout<<"Not Allocated\n";
				}
				cout<<"======================================================================="<<endl;
                cout<<"\t\t\t || Code By Aayush Dubey || "<<endl;
                cout<<"======================================================================="<<endl;
			}
};

int main()
{
	bestFit obj;
	obj.takeInput();
	obj.sorting();
	obj.allocate();
	obj.display();
	return 0;
}