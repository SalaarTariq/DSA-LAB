#include<iostream>


    void merge(int m, int n, int a[],int b[],int c[]){
        int i,j,k;
        i=0,j=0,k=0;
        while(i<m&& j<n){
            if (A[i]<= B[j]){
                c[k]=A[i];
                i++;

            }
            else{
                c[k]=B[j];
                j++;
            }
        k++;
        }
        if(i<m){
            for(int p=i;p<m;p++){
                c[k]=b[p];
                k++;
            }
        }
    }

void mergersort(int numbers[],int temp[],int array_size){
    m_sort(numbers,temp,0,array_size-1);}
void m_sort(int numbers[],int temp[],int left,int right){
    int mid;
    if(right>left)
    mid = (right+left)/2;
    m_sort(numbers,temp,left,mid);
    
    m_sort(numbers,temp,mid+1,right);
    merge(numbers,temp,left,mid+1,right);}