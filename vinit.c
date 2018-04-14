
#include<iostream>
using namespace std;
struct process 
{
 
    int pno;
    int at;
    int bt;
    int pt;
    int start;
    int end;
bool wstatus=false;//wstatus means waiting status
int waiting;
int turnaround;

};
int maxat=0;
int prev=0;
int current=0;
int totaltime,totaltime1=0;
void maximumarrivaltime(struct process q[],int n)
{
    maxat=q[n-1].at;
}
void sortonarrivaltime)struct process q[],int n)
{
 for(int i=0;i<n;i++)
 {
     
     
     for(intj=i+1;j<n-1;j++)
     {
     if(q[i].at>q[j].at)
     {
         swap(q[i],q[j]
    
    
}
     }
 }
    
}
    
    

void input(struct process p[],int n)
{
	
	for(int i=0;i<n;i++)
	{cout<<"Enter arrrival time for process";
	cin>>p[i].at;
	cout<<"Enter burst time for process";
	cin>>p[i].bt;
	cout<<"Enter priority for process";
	cin>>p[i].pt;
    p[i].pno=i;
}
}
void copy(struct process q[],struct process p[],int n)
{
 for(int i=0;i<n;i++)
 {
     q[i]=p[i];
 }
 
}

bool checkingforpreemption(struct process q[],int totaltime, n)
{
    bool check=false;
    for(int i=0;i<n;i++)
    {
    if(q[i].at==totaltime)
    {
        check=true;
        current=i;
     return true;
     break;
        
    }
        
        
    }
    return check;;
    
    
    
}
void assigning(struct process p[],struct process q[],int n,int index)
{
    
    
    int a=q[index].pno;
    p[a].
    
    
    
    
    
    
    
    
    
    
}
void scheduling(struct process p[],struct process q[], int n)
{
    
 while(totaltime<=q[n-1].bt+maxat)
 {
     totaltime++;
    if( checkingforpreemption(q,totaltime,n))
    {
     assigning(p,q,n,current);   
    }
     
     
     
     
     
     
 }
    
    
    
    
    
    
}

int main()
{
    
    int n;
    cout<<"Enter total no of process";
    cin>>n;
    struct process p[n],q[n];
    input(p,n);
    copy(q,p,n);
    sortonarrivaltime(q,n);
    maximumarrivaltime(q,n);
}
    
}
