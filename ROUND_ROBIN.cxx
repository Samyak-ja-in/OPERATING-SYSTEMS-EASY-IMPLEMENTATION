/*  
    FLAG=0=PROCESS IS NOT RESPONEDED YET
    FLAG=1;PROCESS IS COMPLETED
    FLAG=2;PROCESS IS RESPONDED BUT NOT COMPLETED
    FLAG=3;PROCESS SHOULD NOT BE REPUSHED TO READY QUEUE IF ONCE ARRIVED

*/

#include<iostream>
#include<queue>
using namespace std;


int flag[20],at[20];
int curt,n;
queue<int>rq;
int bt[20],ct[20],rt[20],tat[20],wt[20],bti[20];
float sum_rt=0,sum_tat=0,avg_rt,avg_tat=0,sum_wt=0,avg_wt=0;
int tq,i,exec;
int sum_bt=0;

void check_arrival()
{
    for(int i=0;i<n;i++)
    {
        if(flag[i]==0 && at[i]<=curt)
        {
            rq.push(i);
            flag[i]=3;
        }
    }
}

int main()
{
    
    
    cout<<"\nENTER NUMBER OF PROCESS ";
    cin>>n;

    cout<<"\nENTER THE TIME QUANTUM ";
    cin>>tq;

    cout<<"ENTER THE ARRIVAL AND BURST TIME OF PROCESS ";
    curt=99;
    for(i=0;i<n;i++)
    {
        cin>>at[i]>>bt[i];

        bti[i]=bt[i];
        flag[i]=0;
        sum_bt=sum_bt+bt[i];
        if(at[i]<curt)
        curt=at[i];
    }

    cout<<"\nORDER OF EXECUTION IS ";
    check_arrival();
    while(curt!=sum_bt)
    {
        
        exec=rq.front();
        cout<<exec+1<<"->";
        rq.pop();

        if(flag[exec]==0 || flag[exec]==3)
        {
            flag[exec]=2;
            rt[exec]=curt-at[exec];
        }
        if(flag[exec]!=1)
        {
            if(bt[exec]>tq)
            {
                bt[exec]=bt[exec]-tq;
                curt=curt+tq;
                check_arrival();
                rq.push(exec);
            }
            else
            {
                if(bt[exec]==tq)
                {
                    bt[exec]=0;
                    curt=curt+tq;
                    
                }
                else
                {
                    curt=curt+bt[exec];
                    bt[exec]=0;
                    
                }
                flag[exec]=1;
                ct[exec]=curt;
                tat[exec]=ct[exec]-at[exec];
                wt[exec]=tat[exec]-bti[exec];
                check_arrival();
            }
        }
        

    }

    cout<<"\nPro\tArr\tBur\tCt\tTat\tRt\tWt\n";
    for(i=0;i<n;i++)
    {
        cout<<i+1<<"\t"<<at[i]<<"\t"<<bti[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<rt[i]<<"\t"<<wt[i]<<"\n";
    }

    for(i=0;i<n;i++)
    {
        sum_rt=sum_rt+rt[i];
        sum_tat=sum_tat+tat[i];
        sum_wt=sum_wt+wt[i];
    }

    avg_rt=sum_rt/n;
    avg_tat=sum_tat/n;
    avg_wt=sum_wt/n;

    cout<<"\nAverage response "<<avg_rt<<" and turnaround time is "<<avg_tat<<"Average waiting "<<avg_wt;

}