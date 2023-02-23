#include <bits/stdc++.h> 
using namespace std;

int main() { 
    int i, j, k; 
    int n; //number of processes 
    int m; //number of resources 

    cout<<"Enter number of processes: ";
    cin>>n;
    cout<<"Enter number of resources: ";
    cin>>m;

    int allocation[n][m]; //Each row represents a process 
    cout<<"Enter Allocation matrix: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"For process "<<i<<":\t ";
        for(int j=0;j<m;j++){
            cin>>allocation[i][j];
        }
    }
    int max[n][m];//Maximum resources that can be allocated 
    cout<<"Enter Maximum matrix: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"For process "<<i<<":\t ";
        for(int j=0;j<m;j++){
            cin>>max[i][j];
        }
    }

    int available[m]; //Available resources at start
    cout<<"\nEnter the availability matrix: " ;
    for(int i=0;i<m;i++){
        cin>>available[i];
    }
  
    int finish[n] = {0};
    int ans[n] = {0};
    int idx =  0; 
    
    int need[n][m];  //Calculating Need matrix
    for(int i=0;i<n;i++)
    { 
        for(int j=0;j<m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        } 
    } 

    cout<<"Need Matrix: "<<endl;
    for(int i=0;i<n;i++){
        cout<<endl;
        for(int j=0;j<m;j++){
            cout<<need[i][j]<<" ";
        }
    }

    
    int y = 0; 
    for (int k=0;k<5;k++) 
    { 
        for(int i=0;i<n;i++)
        { 
            if(finish[i]==0)
            { 
                int flag = 0; 
                for(int j=0;j<m;j++)
                { 
                    if(need[i][j]>available[j])
                    { 
                        flag = 1; //if needed resources are more in number than the available ones, move to the next process
                        break; 
                    }
                } 
                
                if(flag==0)
                {  //if available resources fulfilled the need
                    ans[idx++] = i; //the index of process, that has been allocated the resources
                    for(int y=0;y<m;y++)
                    { 
                        available[y] += allocation[i][y]; 
                    }
                    finish[i] = 1; 
                } 
            } 
        } 
    } 
    
    bool flag = true;
    for(int i=0; i<n; i++)
    {
        if(finish[i] == 0)
        { 
            flag = false; 
            cout<<"\nSystem is in deadlock !!"; break; 
        }
    }
    
    if(flag==true)
    {
        cout<<"\nSystem is in safe state and following is the safe sequence: ";
        for(int i=0;i<n-1;i++)
        {
            cout<<"P"<<ans[i]<<" -> "; 
        }
        cout<<"P"<<ans[n-1]<<endl;
    }  
    return 0; 
} 
