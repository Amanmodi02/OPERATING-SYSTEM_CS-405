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
				int min=i;
				for(j=i+1;j<n;j++)
					if(blocksize[j]<blocksize[min])
						min=j;
			
				swap(&blocksize[min],&blocksize[i]);
				swap(&blockId[min],&blockId[i]);				
			}
			
			n=processno;
			for(i=0;i<n-1;i++)
			{
				int min=i;
				for(j=i+1;j<n;j++)
					if(processsize[j]<processsize[min])
						min=j;
			
				swap(&processsize[min],&processsize[i]);
				swap(&processId[min],&processId[i]);				
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
            cout<<"Fill The Number Of Blocks : ";
			cin>>blockno;
            cout<<"======================================================================="<<endl;
			cout<<"Fill Size Of Each Block : ";

			for(i = 0; i<blockno; i++)
			{			
				cin>>blocksize[i];
				blockId[i]=i;
			}
			cout<<"======================================================================="<<endl;
            cout<<"Fill The Number Of Processes : ";
			cin>>processno;
            cout<<"======================================================================="<<endl;
			cout<<"Enter Each Process Size : ";
			
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
                cout<<"======================================================================="<<endl;
				cout<<" || Block Number || Size || Process Number || Size || "<<endl;
				for(i=0; i<blockno; i++)
				{
					cout<<"\n"<<blockId[i]<<"\t\t"<<blocksize[i]<<"\t\t"<<endl;
					if(flags[i] == 1)
						cout<<"\t"<<processId[allocation[i]]<<"\t\t"<<processsize[allocation[i]]<<endl;
					else
						cout<<"\tNot Allocated"<<endl;
				}
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