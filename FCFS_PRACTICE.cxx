/*
    FCFS
    *THOSE PROCESS COMES FIRST WILL BE SERVED FIRST

*/


#include<iostream>
using namespace std;

int main()
{
    int bt[20],rt[20],ct[20],tat[20],at[20];
    int n,i,curt=0;
    float sum_rt=0,sum_tat=0,avg_tat,avg_rt;

    cout<<"Enter number of process ";
    cin>>n;

    cout<<"\nEnter arrival and burst time of each process ";
    for(i=0;i<n;i++)
    {
        cin>>at[i];
        cin>>bt[i];
    }

    for(i=0;i<n;i++)
    {
        rt[i]=curt-at[i];
        curt=curt+bt[i];
        ct[i]=curt;
        tat[i]=ct[i]-at[i];
    }

    cout<<"Pro\tArr\tBur\tCt\tTat\tRt\n";
    for(i=0;i<n;i++)
    {
        cout<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<rt[i]<<"\n";
    }

    for(i=0;i<n;i++)
    {
        sum_rt=sum_rt+rt[i];
        sum_tat=sum_tat+tat[i];
    }

    avg_rt=sum_rt/n;
    avg_tat=sum_tat/n;

    cout<<"\nAverage response "<<avg_rt<<" and turnaround time is "<<avg_tat;
    
}