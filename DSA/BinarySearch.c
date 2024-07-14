#include<stdio.h>
int binarySearch(int a[], int l, int r, int s);
void main(){
    int n, i, s;
    printf("Enter size of array:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter sorted array elemensts:\n");
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
int left=0, right=n;
printf("Enter element to be searched:\n");
scanf("%d",&s);
binarySearch(a, left, right, s);
}
int binarySearch(int a[], int l, int r, int s){
    if(r>=l){
        int mid = l+(r-l/2);
    
    }int mid = l+(r-l/2);
    if(s==a[mid]){
        printf("Element found at index %d",mid);
    }
    else if(s<a[mid]){
        binarySearch(a, l, mid-1, s);
} else if(s>a[mid]){
    binarySearch(a, mid+1, r, s);
}
else{
    printf("Element not found");
}
    
return 0;
}