#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<stdlib.h>
using namespace std;
long a,b,c,d,last,now;
string tempp;
struct node
{
    //char s1[100];
    string s1;
    string s2;
    //char s2[100];
}rec[6699];//rec是单词组
void sc(long lt,long rt)
{
    int i,j;
    system("clear");
    for (i=lt;i<=rt;i++)
    {
        cout<<"                      "<<rec[i].s1<<endl;
        //system("PAUSE");
        cout<<"           "<<rec[i].s2<<endl;
        cout<<"*************************************************************************"<<endl;
    }
    //system("PAUSE");
}
void px(long lt,long rt)
{
    int i,j;
    //char temp[100];
    string temp;
 system("clear");
    for (i=lt;i<=rt;i++)
    {
        for (;;)
        {
            cout<<"请写出单词："<<endl;
            cout<<rec[i].s2<<endl;
            cin>>temp;
            //if (strcmp(temp,rec[i].s1)==0)
            if(temp==rec[i].s1)
            {
                cout<<"正确！"<<endl;
                //system("PAUSE");
                system("clear");
                break;
            }
            else
            {
                cout<<"不对哦！"<<endl;
                cout<<"1:重新拼写"<<endl;
                cout<<"2:查看单词"<<endl;
                cout<<"0:返回上一层"<<endl;
                cin>>j;
                system("clear");
                if (j==0) return;
                if (j==1) continue;
                else
                {
                    cout<<rec[i].s1<<endl;
                    //system("PAUSE");
                    system("clear");
                }
            }
        }
    }
}
void learn(long lt,long rt)
{
    long i,j;
    for (;;)
    {
    system("clear");
    cout<<"所有单词："<<endl;
    for (i=lt;i<=rt;i++)
    cout<<rec[i].s1<<"      "<<rec[i].s2<<endl;
    cout<<"1:拼写单词"<<endl;
    cout<<"2:识词"<<endl;
    cout<<"0:退出"<<endl;
    cin>>i;
    if (i==1) px(lt,rt);
    else if (i==2) sc(lt,rt);
    else return;
}
}
int main()
{
    cout<<"加载中......"<<endl;
    ifstream fin;
    fin.open("data");
    fin>>last;//last是计数
    cout<<last<<endl;
    for (a=1;a<=6698;a++)
    {
        //string tmp;
        fin>>rec[a].s1;
        //rec[a].s1=tmp
        //tmp(rec[a].s1);
        //int length1=rec[a].s1.length();
       // cout<<length1;
        //cout<<tmp;
        getline(fin,rec[a].s2);

    }
    fin.close();
 cout<<"加载完成！"<<endl;
 now=last;
 for (;;)
 {
    cout<<"当前位置："<<now<<endl;
    if (now>0&&now<6699) cout<<rec[now].s1<<' '<<rec[now].s2<<endl;
    cout<<"1：从当前位置学习新单词"<<endl;
    cout<<"n：复习前n次学习的单词"<<endl;
    cout<<"0:保存当前位置并结束"<<endl;
    for (;;)
    {
        cin>>a;
        if (a>=0) break;
        cout<<"输入格式不正确奥。请重新输入。"<<endl;
    }
    if (a==1)
    {
        learn(now+1,now+20);
        now+=20;
    }
    else if (a>0)
    learn(now-a*20+1,now);
    else
    {
        ofstream fout;
        fout.open("data");
        fout<<now<<endl;
        for (a=1;a<=6698;a++)
        fout<<rec[a].s1<<' '<<rec[a].s2<<endl;
        fout.close();
        break;
    }
    system("clear");
 }
 return 0;
}
