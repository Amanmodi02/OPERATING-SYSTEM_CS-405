#include <iostream>
using namespace std;

int main()
{
	int blocksize[10], processsize[10], blockno, processno, flags[10], allocation[10], i, j;
	for(i=0; i<10; i++)
	{
		flags[i] = 0;
		allocation[i] = -1;
	}
    cout<<endl;
    cout<<"======================================================================="<<endl;
	cout<<"Fill The Number Of Blocks --> ";
	cin>>blockno;
    cout<<"======================================================================="<<endl;
	cout<<"Fill Size Of Each Block --> ";
	
	for(i = 0; i<blockno; i++)
		cin>>blocksize[i];
    cout<<"======================================================================="<<endl;
	cout<<"Fill The Number Of Processes --> ";
	cin>>processno;
    cout<<"======================================================================="<<endl;
	cout<<"Enter Each Process Size --> ";
	
	for(i = 0; i<processno; i++)
		cin>>processsize[i]; 

	for(i=0; i< processno; i++)
	
	for(j = 0; j<blockno; j++)
	
	if(flags[j] == 0 && blocksize[j]> processsize[i])
	{
		allocation[j] = i;
		flags[j] = 1;
		break;
	}
    cout<<"======================================================================="<<endl;
	cout<<"Block Number \tSize \t\tProcess Number \t\tSize"<<endl;
    cout<<"======================================================================="<<endl;
	for(i=0; i<blockno; i++)
	{
		cout<<"\n"<<i<<"\t\t"<<blocksize[i]<<"\t\t";

		if(flags[i] == 1)
			cout<<allocation[i]<<"\t\t\t"<<processsize[allocation[i]];
		else
			cout<<"Not allocated"<<endl;
    }
    cout<<"======================================================================="<<endl;
    cout<<endl;
	return 0;
}