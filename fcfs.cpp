#include<iostream>
using namespace std;

void FindWaitingTime(int processes[], int n, int bt[], int wt[]){
    // waiting time for first process is 0
    
        wt[0]=0;
        for(int i=1;i<n;i++){
            wt[i]= bt[i-1]+wt[i-1];
        }  
}

void TurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]){
    for(int i=0;i<n;i++){
        tat[i]= wt[i] + bt[i] ;
        }
}

void AverageTime(int processes[], int n, int bt[]) {
    int wt[n],  tat[n], total_wt = 0, total_tat=0;

    FindWaitingTime(processes, n, bt, wt);

    TurnAroundTime(processes, n, bt, wt, tat );


    cout<<" processes  "<<"  burst time" << " waiting time  "<< " turn around time\n";

    for(int i=0;i<n;i++){
        total_wt= total_wt + wt[i];
        total_tat= total_tat + tat[i];

        cout<<"  "<<i+1<<"\t\t"<<bt[i]<<"\t    "<<wt[i]<<"\t\t  "<<tat[i]<<endl;
    
      }

      cout<<"average waiting time"<<
      (float)total_wt / (float)n;
      cout<<"\naverage turn Around Time = "<<
      (float)total_tat / (float)n;
}
int main(){
    int processes[]={1,2,3};
    int n = sizeof processes / sizeof  processes[0];
    int burst_time[]={10,5,8};

    AverageTime(processes, n, burst_time);
    return 0;

}