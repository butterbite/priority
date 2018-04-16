
#include<iostream>
using namespace std;
void scheduling(struct process p[],struct process q[], int n,int *current,int* previous);
void maximumarrivaltime(struct process q[],int n);
void sortonpriority(struct process q[],int n);
bool checkingforpreemption(struct process q[],int totaltime,int totaltime1,int **current,int** previous, int n);
void input(struct process p[],int n);
void print(struct process p[],int n);
void decreasepriority(struct process q[],int n,int *totaltime);
void remtime(struct process p[],struct process q[],int **previous,int **current,int *totaltime,int *totaltime1,int n);
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
static int previous=-1;
static int current=0;
int totaltime,totaltime1=0;
void maximumarrivaltime(struct process q[],int n)
{
    maxat=q[n-1].at;
}
void sortonarrivaltime(struct process q[],int n)
{
 for(int i=0;i<n;i++)
 {
     
     
     for(int j=i+1;j<n-1;j++)
     {
     if(q[i].at>q[j].at)
     {
   swap(q[i],q[j]);
    
    
}
     }
 }
    
}
void sortonpriority(struct process q[],int n)
{
  
 for(int i=0;i<n;i++)
 {
     
     
     for(int j=i+1;j<n-1;j++)
     {
     if(q[i].pt>q[j].pt)
     {
         swap(q[i],q[j]);
    
    
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

bool checkingforpreemption(struct process q[],int totaltime,int totaltime1,int **current,int** previous, int n)
{
     cout<<"value of previous and current"<<**previous<<**current<<"totaltime is"<<totaltime<<"Totaltime one"<<totaltime1<<"\n";
     //   cout<<"\nllllllllllllllll";
    bool check=false;
    for(int i=0;i<n;i++)
    {
        if(**previous!=-1)
        {
            cout<<"is this running\n";
    if(q[i].at==totaltime && q[i].pt<q[**current].pt)
    {
        check=true;
        **previous=**current;
        **current=i;
        
     return true;
     break;
        
    }
            
        }
    if(q[i].at==totaltime && **previous==-1)
    {
            
      
//        if(q[i].at==totaltime && q[i].pt<q[**previous].pt )
        {
        cout<<"is this running\n";
            check=true;
            **previous=**current;
        **current=i;
                    
     return true;
     break;
        }
        
        
    }
        
        
    }
    return check;
    
    
    
}
void assigning(struct process p[],struct process q[],int totaltime1,int **current,int **previous)
{
    
    
         //   cout<<"value of previous and current"<<previous<<current<<"\n";
    if(**previous==0)
    {
        
    p[q[**previous].pno].start=0;
    p[q[**previous].pno].end=totaltime;
    p[q[**previous].pno].bt=p[q[**previous].pno].bt - (p[q[**previous].pno].end - p[q[**previous].pno].start);
  q[**previous].bt=  p[q[**previous].pno].bt;
        q[**previous].wstatus=true;
    }
    else
    {
     p[q[**current].pno].start=p[q[**previous].pno].end+2;
     p[q[**current].pno].end=totaltime1;
        //totaltime1=totaltime1+2;
     p[q[**current].pno].bt=p[q[**current].pno].bt - (p[q[**current].pno].end - p[q[**current].pno].start);    
        
     q[**current].bt=p[q[**current].pno].bt;
     q[**current].wstatus=true;
     
    }
    
    
    
    
    
    
    
    
    
    
}
void assigning1(struct process p[],struct process q[],int totaltime1,int **current,int **previous)
{
    
    
    int temp=totaltime1;
    {
     p[q[**current].pno].start=p[q[**previous].pno].end+2;
     p[q[**current].pno].end=temp;
     
        //totaltime1=totaltime1+2;
     p[q[**current].pno].bt=p[q[**current].pno].bt - (p[q[**current].pno].end - p[q[**current].pno].start);    
        
     q[**current].bt=p[q[**current].pno].bt;
     q[**current].wstatus=true;
     
    }
    
    
    
    
    
    
    
    
    
    
}



void finishuntill(struct process p[],struct process q[],int **current,int **previous,int k,int *totaltime,int *totaltime1,int n)
{
    int h=*totaltime;
    int j=*totaltime1;
    
 for(;k<q[**current].bt;k++)
 {
 cout<<"totaltime one is"<<*totaltime1<<" value of k "<<k<<"\n";
     h++;
     j++;
  *totaltime=h;
  *totaltime1=j;
 /* if(*totaltime1%2==0)
  {
      int yolo=*totaltime1;
   decreasepriority(q,n,&yolo); 
   sortonpriority(q,n);
  }*/
 }
 
    
    
}
void decreasepriority(struct process q[],int n,int *totaltime)
{
    
 for(int i=0;i<n;i++)
 {
  if(q[i].bt>0 && q[i].wstatus==true && q[i].at<*totaltime)
  {
      
   q[i].pt=q[i].pt--;   
  }
     
 }
    
}

void scheduling(struct process p[],struct process q[], int n,int *current,int* previous)
{
    
int i=0;
for(;i<q[*current].bt;)
{
   // cout<<previous;
    i++;
     totaltime++;
     totaltime1++;
      //  cout<<"value of previous and current"<<*previous<<*current<<"totaltime is"<<totaltime<<"\n";
     if(totaltime%2==0)
     {
      decreasepriority(q,n,&totaltime);   
     }
   if( checkingforpreemption(q,totaltime,totaltime1,&current,&previous,n))
    {
     assigning(p,q,totaltime1,&current,&previous);   
     totaltime1=totaltime1+2;
     i=0;
     continue;
    }
    
    if(totaltime>=maxat)
    {
    //    assigning(p,q,totaltime1,&current,&previous);
        finishuntill(p,q,&current,&previous,i,&totaltime,&totaltime1,n);
        assigning1(p,q,totaltime1,&current,&previous);
        remtime(p,q,&previous,&current,&totaltime,&totaltime1,n);
        //*previous=*current;
         cout<<"value of previous and current"<<*previous<<*current<<"totaltime is"<<totaltime<<"Totaltime one"<<totaltime1<<"\n";
         cout<<"\nnow exiting";
         
        break;
    }
    
    if(q[*current].bt==i)
    {
      assigning(p,q,totaltime1,&current,&previous);  
  sortonpriority(q,n);
  int j;
  for(j=0;j<n;j++)
  {
      if(q[j].bt!=0)
  {   
   *previous=*current;   
  *current=j;
  
  break;
  }
  }
   //totaltime1=totaltime1+2;
   i=0;
  continue;
  
  }
     
     
     
 
     
     
 }
    
    
    
    
    
    
}

void remtime(struct process p[], process q[],int **previous,int **current,int *totaltime,int *totaltime1,int n)
{


int h=*totaltime;
int po=*totaltime1;
 for(int i=0;i<n;i++)
 {
     if(q[i].bt>0)
     {
 **current=i;
     for(int j=0;j<q[i].bt;j++)
     {
         h++;
         po++;
    *totaltime=h;
         *totaltime1=po;
       /*  if(*totaltime1%2==0)
         {
             int z=*totaltime1;
          decreasepriority(q,n,&z);   
         }*/
 }
 int temp1=*totaltime1;
 
 int shivam=**current;
 int pandey=**previous;
 int *shivam1=&shivam;
 int *pandey1=&pandey;
 assigning1(p,q,temp1,&shivam1,&pandey1);
 **previous=**current;
    
    
    
    
    
    
    
    
    
}
 }
}



void print(struct process p[],int n)
{
    for(int i=0;i<n;i++){
        cout<<"process No"<<p[i].pno<<"\n";
 cout<<"Burst Time"<<p[i].bt<<"\n";
 cout<<"Start"<<p[i].start<<"\n";
 cout<<"End"<<p[i].end<<"\n";
    }   
  //  return 5;   
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
    scheduling(p,q,n,&current,&previous);

print(p,n);
}

