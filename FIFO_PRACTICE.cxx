#include<iostream>
#include<queue>
using namespace std;

queue<char>fifo;

bool present_in(queue<char>q,char ch)
{
    while(!q.empty())
    {
        if(q.front()==ch)
        return 1;
        q.pop();
    }
    return 0;
}

int main()
{
    char str[30];
    int count=0,n;
    float hit_ratio,fault_ratio,fault=0,hit=0;
    char ch;
    bool p;

    cout<<"\nEnter the string ";
    cin>>str;

    cout<<"\nENTER NUMBER OF FRAMES ";
    cin>>n;

    ch=str[0];
    while(ch!='\0')
    {
        p=present_in(fifo,ch);
        if(fifo.size()!=n)
        {
            if(p==0)
            {
                fifo.push(ch);
                fault++;
            }
        }
        else
        {
            if(p==0)
            {
                fifo.pop();
                fifo.push(ch);
                fault++;
            }
        }
        count++;
        ch=str[count];
    }

    cout<<"\nLENGTH OF STRING IS ";
    cout<<count;
    hit=count-fault;
    cout<<"\nNUMBER OF HITS IS "<<hit;
    cout<<"\nNUMBER OF FAULT IS "<<fault;

    cout<<"\nHIT RATIO "<<hit/count;
    cout<<"\nFAULT RATIO "<<fault/count;


}