#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define z 1000000007
#define sh 100000
#define pb push_back
#define pr(x) printf("%d ", x)

struct util 
{
	int id;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
}

ar[sh + 1];

struct util1 
{
	int p_id;
	int bt1;
};

util1 range;

util1 tr[4 * sh + 5];

int mp[sh + 1];

bool cmp(util a, util b)
{
	if (a.at == b.at)
		return a.id < b.id;
	return a.at < b.at;
}

void update(int node, int st, int end,int ind, int id1, int b_t)
{
	if (st == end) 
	{
		tr[node].p_id = id1;
		tr[node].bt1 = b_t;
		return;
	}
	int mid = (st + end) / 2;
	if (ind <= mid)
	{
		update(2 * node, st, mid, ind, id1, b_t);
	}	
	else
	{
		update(2 * node + 1, mid + 1, end, ind, id1, b_t);
	}	
	if (tr[2 * node].bt1 < tr[2 * node + 1].bt1) 
	{
		tr[node].bt1 = tr[2 * node].bt1;
		tr[node].p_id = tr[2 * node].p_id;
	}
	else 
	{
		tr[node].bt1 = tr[2 * node + 1].bt1;
		tr[node].p_id = tr[2 * node + 1].p_id;
	}
}

util1 query(int node, int st, int end, int lt, int rt)
{
	if (end < lt || st > rt)
	{
		return range;
	}	
	if (st >= lt && end <= rt)
	{
		return tr[node];
	}	
	int mid = (st + end) / 2;
	util1 lm = query(2 * node, st, mid, lt, rt);
	util1 rm = query(2 * node + 1, mid + 1, end, lt, rt);
	if (lm.bt1 < rm.bt1)
	{
		return lm;
	}	
	return rm;
}

void non_preemptive_sjf(int n)
{
	int counter = n;
	int upper_range = 0;
	int tm = min(INT_MAX, ar[upper_range + 1].at);

	while (counter) 
	{
		for (; upper_range <= n;) 
		{
			upper_range++;
			if (ar[upper_range].at > tm || upper_range > n) 
			{
				upper_range--;
				break;
			}

			update(1, 1, n, upper_range,
				ar[upper_range].id, ar[upper_range].bt);
		}

		util1 res = query(1, 1, n, 1, upper_range);

		if (res.bt1 != INT_MAX) 
		{
			counter--;
			int index = mp[res.p_id];
			tm += (res.bt1);
			ar[index].ct = tm;
			ar[index].tat = ar[index].ct - ar[index].at;
			ar[index].wt = ar[index].tat - ar[index].bt;
			update(1, 1, n, index, INT_MAX, INT_MAX);
		}
		else 
		{
			tm = ar[upper_range + 1].at;
		}
	}
}

void execute(int n)
{
	sort(ar + 1, ar + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		mp[ar[i].id] = i;
	}
	non_preemptive_sjf(n);
}

void print(int n)
{

	cout << "ProcessId "<< "Arrival Time "<< "Burst Time "<< "Completion Time "<< "Turn Around Time "<< "Waiting Time\n";
	for (int i = 1; i <= n; i++) 
	{
		cout << ar[i].id << " \t          "<< ar[i].at << " \t           "<< ar[i].bt << " \t         "<< ar[i].ct << " \t          "<< ar[i].tat << " \t "<< ar[i].wt << " \n";
	}
}

int main()
{
	int n = 5;

	range.p_id = INT_MAX;
	range.bt1 = INT_MAX;

	for (int i = 1; i <= 4 * sh + 1; i++) 
	{
		tr[i].p_id = INT_MAX;
		tr[i].bt1 = INT_MAX;
	}

	ar[1].at = 1;
	ar[1].bt = 7;
	ar[1].id = 1;

	ar[2].at = 2;
	ar[2].bt = 5;
	ar[2].id = 2;

	ar[3].at = 3;
	ar[3].bt = 1;
	ar[3].id = 3;

	ar[4].at = 4;
	ar[4].bt = 2;
	ar[4].id = 4;

	ar[5].at = 5;
	ar[5].bt = 8;
	ar[5].id = 5;

	execute(n);
	print(n);
}

