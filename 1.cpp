#include<iostream>
#include <cstdlib>
using namespace std;
void create(int set[],int n);
void display(int set[]);
void intersection(int set1[],int set2[],int set3[]);
void unions(int set1[],int set2[],int set3[]);
void diff(int set1[],int set2[],int set3[]);
int member(int set[],int x);
int subset(int set[],int sset[]);
int member(int set[],int n,int x);
#define max 30
int main()
{
    system("COLOR FC");
    system("cls");
	int set1[max],set2[max],set_union[max],set_int[max],set_diff[max],set_s[max];
	int c;
	do
	{
		cout<<"\n=============================MENU====================================\n"<<endl;
		cout<<"\n1.Create\n2.Display\n3.Intersection\n4.Union\n5.A-B\n6.B-A\n7.Check subset\n8.Exit\n";
		cout<<"\n=====================================================================\n"<<endl;
		cout<<"\nEnter your choice - ";
		cin>>c;
		switch(c)
		{
			case 1:{
						int s1,s2;
						cout<<"\nEnter number elements of set A -";
						cin>>s1;
						create(set1,s1);
						cout<<"\nEnter number elements of set B - ";
						cin>>s2;
						create(set2,s2);
					}
					break;
			case 2:{
						cout<<"\nThe elements of set A are -  ";
						display(set1);
						cout<<"\nThe elements of set B are - ";
						display(set2);
					}
					break;
			case 3:{
						intersection(set1,set2,set_int);
						cout<<"\nThe intersection of A and B is - ";
						display(set_int);
					}
					break;
			case 4:{
						unions(set1,set2,set_union);
						cout<<"\nThe union of A and B is - ";
						display(set_union);
					}
					break;
			case 5:{
						diff(set1,set2,set_diff);
						cout<<"\nThe difference between A and B is - ";
						display(set_diff);
					}
					break;
			case 6:{
						diff(set2,set1,set_diff);
						cout<<"\nThe difference between B and A is -";
						display(set_diff);
					}
					break;
			case 7:{
						int n;
						cout<<"\nEnter number elements of subset - ";
						cin>>n;
						create(set_s,n);
						if(subset(set1,set_s) && subset(set2,set_s))
							cout<<"\nThe given set is a subset of both sets\n";
						else if(subset(set2,set_s))
							cout<<"\nThe given set is a subset of set B\n";
						else if(subset(set1,set_s))
							cout<<"\nThe given set is a subset of set A\n";
						else
							cout<<"\nThe given set is not a subset of any set\n";
					}
					break;
		}
	}while(c!=8);
	return 0;
}
void create(int set[],int n)
{
	set[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>set[i];
	}
	set[0]=n;
}
void display(int set[])
{
	int n=set[0];
	for(int i=1;i<=n;i++)
	{
		cout<<set[i]<<"\t";
	}
	cout<<endl;
}
int member(int set[],int x)
{
	int n=set[0];
	for(int i=1;i<=n;i++)
	{
		if(set[i]==x)
			return 1;
	}
	return 0;
}
void intersection(int set1[],int set2[],int set3[])
{
	set3[0]=0;
	int n=set1[0];
	for(int i=1;i<=n;i++)
	{
		if(member(set2,set1[i]))
		{
			set3[0]++;
			set3[set3[0]]=set1[i];
		}
	}
}
void unions(int set1[],int set2[],int set3[])
{
	int n=set1[0];
	set3[0]=n;
	for(int i=1;i<=n;i++)
	{
		set3[i]=set1[i];
	}
	n=set2[0];
	for(int i=1;i<=n;i++)
	{
		if(!member(set3,set2[i]))
		{
			set3[0]++;
			set3[set3[0]]=set2[i];
		}
	}
}
void diff(int set1[],int set2[],int set3[])
{
	set3[0]=0;
	int n=set1[0];
	for(int i=1;i<=n;i++)
	{
		if(!member(set2,set1[i]))
		{
			set3[0]++;
			set3[set3[0]]=set1[i];
		}
	}
}
int subset(int set[],int sset[])
{
	int n=sset[0];
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(!member(set,sset[i]))
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
