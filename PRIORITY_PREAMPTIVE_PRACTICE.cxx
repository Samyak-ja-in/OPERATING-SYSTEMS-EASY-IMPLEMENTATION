#include<iostream>
using namespace std;

int main()
{
    int at[20],bt[20],bti[20],pr[20],ct[20],rt[20],tat[20],wt[20],flag[20];
    int n,i,curt,prior,exec;
    float sum_rt=0,sum_tat=0,avg_rt,avg_tat=0,sum_wt=0,avg_wt=0;
    int sum_bt=0;

    cout<<"\nENTER NUMBER OF PROCESS ";
    cin>>n;

    cout<<"\nENTER ARRIVAL BURST AND PRIORITY ";
    curt=99;
    for(i=0;i<n;i++)
    {
        cin>>at[i]>>bt[i]>>pr[i];

        bti[i]=bt[i];
        sum_bt=sum_bt+bt[i];
        flag[i]=0;
        if(at[i]<curt)
        curt=at[i];
    }

    while(sum_bt!=curt)
    {

        prior=99;
        for(i=0;i<n;i++)
        {
            if(at[i]<=curt && pr[i]<prior && flag[i]!=1)
            {
                exec=i;
                prior=pr[i];
            }
        }

        if(flag[exec]==0)
            rt[exec]=curt-at[exec];
        

        bt[exec]=bt[exec]-1;
        curt=curt+1;
        flag[exec]=2;
        if(bt[exec]==0)
        {
            ct[exec]=curt;
            tat[exec]=ct[exec]-at[exec];
            flag[exec]=1;
            wt[exec]=tat[exec]-bti[exec];
        }
    }

    cout<<"\nPro\tArr\tBur\tPRI\tCt\tTat\tRt\tWt\n";
    for(i=0;i<n;i++)
    {
        cout<<i+1<<"\t"<<at[i]<<"\t"<<bti[i]<<"\t"<<pr[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<rt[i]<<"\t"<<wt[i]<<"\n";
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

    cout<<"\nAverage response "<<avg_rt<<" and turnaround time is "<<avg_tat<<" Average waiting "<<avg_wt;
}