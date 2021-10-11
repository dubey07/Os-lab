#include<iostream>
using namespace std;
int main()
{
	int n,i,qt,temp,bt[10],wt[10],tat[10],rem_bt[10],count=0,temp2=0;
	float awt=0,atat=0;
	cout<<"Enter the no of process :\n";
	cin>>n;
	cout<<"Enter the no. of burst time:\n";
	for(i=0;i<n;i++)
	{
		cin>>bt[i];
		rem_bt[i] = bt[i];
	}
	cout<<"Enter the time quantum:\n";
	cin>>qt;
	while(1)
	{
		for(i=0,count=0;i<n;i++)
		{
			temp = qt;
			if(rem_bt[i] == 0)
			{
				count++;
				continue;
			}
			if(rem_bt[i] > qt)
			{
				rem_bt[i] = rem_bt[i] - qt;
			}
			else
			{
				if(rem_bt[i] >= 0)
				{
					temp = rem_bt[i];
					rem_bt[i] = 0;	
				}
			}
			temp2 = temp2+temp;
			tat[i] = temp2;
		}
		if(n == count)
		{
			break;
		}	
	}
	cout<<"\nProcess\tBurst Time\tCompletion Time\tTuraround Time\tWaiting Time\n";
	for(i=0; i<n; i++)
	{
		wt[i] = tat[i] - bt[i];
		awt = awt + wt[i];
		atat = atat + tat[i];
		cout<<"\n"<<i+1<<"\t"<<bt[i]<<"\t\t"<<tat[i]<<"\t\t"<<tat[i]<<"\t\t"<<wt[i]<<"\n";
	}
	cout<<"\n";
	awt = awt/n;
	atat = atat/n;
	cout<<"Average Waiting Time :"<<awt<<endl;
	cout<<"Average Turnaround Time :"<<atat<<endl;
	return 0;
}
