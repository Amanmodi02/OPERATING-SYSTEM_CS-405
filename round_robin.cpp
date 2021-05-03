#include<iostream>
using namespace std;

int main()
 {  
    int et[30],
    ts,n,i, x=0,
    tot=0;
    int pn[10];
    cout<<endl;
    cout<<"======================================================================="<<endl;
    cout<<"Enter The Number Of Processes : ";
    cin>>n; 
    cout<<"======================================================================="<<endl;
    cout<<"Enter The Time Quantum : ";
    cin>>ts; 
    cout<<"======================================================================="<<endl;
    
    for(i=0;i<n;i++) 
    { 
        cout<<endl;
        cout<<"======================================================================="<<endl; 
        cout<<"Enter Process Name & Estimated Time : "; 
        cin>>pn[i]>>et[i];
        cout<<"======================================================================="<<endl; 
    }    
    cout<<endl;
    cout<<"======================================================================="<<endl;
    cout<<"The Processes Are : ";
     for(i=0;i<n;i++)
     cout<<i+1<<pn[i]; 
     for(i=0;i<n;i++) 
     tot=tot+et[i];
     
	 while(x!=tot) 
    {
         for(i=0;i<n;i++)
      {
        if(et[i]>ts) 
        {
             x=x+ts; cout<<pn[i]<<" -> "<<ts<<endl; 
             et[i]=et[i]-ts; 
          } 
      else if((et[i]<=ts)&&et[i]!=0) 
       {
         x=x+et[i]; 
         cout<<pn[i]<<" "<<et[i];
		 et[i]=0;} } }
         cout<<"\n Total Estimated Time "<<x<<endl;
      }