#include<iostream>
#include<queue>
using namespace std;

queue<char>lru;

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

void rotate(queue<char>q,char ch)
{
    queue <char>local;
    while(!q.empty())
    {
        if(q.front()!=ch)
        {
            local.push(q.front());
            
        }
        q.pop();
    }
    local.push(ch);
    lru=local;
}
int main()
{
    char str[30];
    char ch;
    int n,count=0;
    bool p;
    float hit=0,fault=0,hit_ratio,fault_ratio;

    cout<<"\nENTER STRING ";
    cin>>str;

    cout<<"\nENTER NUMBER OF FRAMES ";
    cin>>n;

    ch=str[0];
    while(ch!='\0')
    {
        if(lru.size()!=n)
        {
            p=present_in(lru,ch);
            if(p==0)
            {
                lru.push(ch);
                fault++;
            }
            else
            {
                rotate(lru,ch);
            }
        }
        else
        {
            p=present_in(lru,ch);
            if(p==0)
            {
                lru.pop();
                lru.push(ch);
                fault++;
            }
            else
            {
                rotate(lru,ch);
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