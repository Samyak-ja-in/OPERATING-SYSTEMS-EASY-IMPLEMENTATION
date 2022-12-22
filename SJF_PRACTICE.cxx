/*
                                SJF ALGORITHM
    *FIND THE MINIMUM TIME AMONG THE ARRIVAL ARRAY
    *MAKE THIS MINIMUM TIME AS CURRENT TIME
    *FIND THE PROCESS WHICH IS ARRIVED AND HAVE MINIMUM BURST TIME AMONG ALL PROCESS AND NOT EXECUTED YET(flag=0)
    *Execute this process and calculate ct,rt,tat


                                DRAWBACK THIS ALGO
    #IF PROCESSES IS ARRIVED HAVE SAME BURST TIMES AND THEN FCFS SHOULD BE FOLLOWED BUT IN THIS CASE IF WE HAVE NOT ASCENDING ORDER ARRANGED ARRIVAL ARRAY THEN WE WILL GET ERROR IN OUTPUT,THEN MORE ARRIVAL TIME ARRAY MAY BE SELECTED IN THIS CASE.
*/

#include<iostream>
using namespace std;

int main()
{
    int at[20],bt[20],ct[20],tat[20],rt[20],wt[20],flag[20];
    int n,i,sum_bt,curt,burst,exec;//exec is index of process to be executed;
    float sum_rt=0,sum_tat=0,avg_rt,avg_tat=0;
    sum_bt=0;

    cout<<"\nEnter number of process ";
    cin>>n;

    curt=100;//LET CURRENT TIME BE 100SEC FOR SATISFYING ALGORITHM for finding minimum time as current time
    cout<<"\nEnter arrival and burst times of process ";
    for(i=0;i<n;i++)
    {
        cin>>at[i]>>bt[i];
        sum_bt=sum_bt+bt[i];
        flag[i]=0;
        if(at[i]<curt)
        {
            curt=at[i];
        }
    }

    //now here current time curt will contain min time of the array
    cout<<"\nOrder of execution of processes is ";
    while(curt!=sum_bt)
    {
        burst=100;         //Assumed burst time for algorithm satisfaction for finding min burst time
        for(i=0;i<n;i++)
        {
            if(flag[i]==0 && at[i]<=curt)
            {
                if(bt[i]<burst)
                {
                    exec=i;
                    burst=bt[i];   
                }              
            }
        }
        cout<<exec+1<<"->";
        rt[exec]=curt-at[exec];
        curt=curt+bt[exec];
        ct[exec]=curt;
        tat[exec]=ct[exec]-at[exec];
        flag[exec]=1;
    }

    cout<<"\nPro\tArr\tBur\tCt\tTat\tRt\n";
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