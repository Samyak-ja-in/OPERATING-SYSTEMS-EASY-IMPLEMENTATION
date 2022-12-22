/*
    here count variable is made for checking only preamption
    if a new process with same burst time as executing process comes then context will not be switched and process will continue executing
    prev is the variable which stores index of previous process

*/

#include<iostream>
using namespace std;

int main()
{
    int at[20],bt[20],ct[20],rt[20],tat[20],wt[20],bti[20],flag[20];
    float sum_rt=0,sum_tat=0,avg_rt,avg_tat=0,sum_wt=0,avg_wt=0;
    int n,i,curt,count=0,prev;
    int sum_bt,exec,burst;

    cout<<"\nENTER NUMBER OF PROCESS ";
    cin>>n;

    curt=99;
    cout<<"\nENTER ARRIVAL AND BURST TIMES OF PROCESS ";
    for(i=0;i<n;i++)
    {
        cin>>at[i]>>bt[i];
        bti[i]=bt[i];
        sum_bt=sum_bt+bt[i];
        flag[i]=0;
        if(at[i]<curt)
        curt=at[i];
    }

    while(curt!=sum_bt)
    {
        burst=99;
        for(i=0;i<n;i++)
        {
            if(at[i]<=curt && bt[i]<burst && flag[i]!=1)
            {
                exec=i;
                burst=bt[i];
            }
        }
        if(count!=0)
        {
            if(bt[exec]==bt[prev])
            {
                exec=prev;
            }
        }
        
        if(flag[exec]==0)
        {
            rt[exec]=curt-at[exec];
            flag[exec]=2;
        }
        bt[exec]=bt[exec]-1;
        curt=curt+1;
        prev=exec;
        if(bt[exec]==0)
        {
            flag[exec]=1;
            ct[exec]=curt;
            tat[exec]=ct[exec]-at[exec];
            wt[exec]=tat[exec]-bti[exec];
        }

        count++;

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