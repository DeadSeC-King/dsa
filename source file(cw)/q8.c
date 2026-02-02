//wap to find eleement in array using binary search 
#include <stdio.h>
int main(){
    int arr[]={10,22,26,34,44,56,68,89};
    int n;
    printf("enter number to be find");
    scanf("%d",&n);
    int low=0,high=7,mid,flag=0;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==n){
            printf("%d found at index %d",n,mid);
            flag=1;
            break;
        }
        else if(arr[mid]<n){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }}