#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(int stalls[],int k,int n,int mid){
    int cowcount=1;
    int lastpos=stalls[0];
    for(int i=0;i<n;i++){
        if(stalls[i]-lastpos>=mid){
            cowcount++;
            if(cowcount==k){
                return true;
            }
            lastpos=stalls[i];
        }
    }
    return false;
}

int aggresivecows(int stalls[],int k,int n){
    
    sort(stalls,stalls+n);          //Sorting is done bcz at the time of placeing the cows we are place them in a sorted array..

    int s=0;
    int maxi=-1;
    for(int i=0;i<n;i++){
        maxi=max(maxi,stalls[i]);
    }
    int e=maxi;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(isPossible(stalls,k,n,mid)){       //Basically if mid may be the possible solution then we do this..
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

int main(){
    int arr[5]={4,2,1,3,6};
    cout<<"Answer is: "<<aggresivecows(arr,2,5)<<endl;
    return 0;
}