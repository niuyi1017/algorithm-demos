//算法练习cpp

#include<iostream>
#include "SortTestHelper.h"

using namespace std;


//选择排序
template< typename T>
void selectionSortNiu(T arr[],int n){
    for(int i = 0;i < n;i++){
        int minIndex = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[minIndex])
                minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }
}

template< typename T>
void selectionSortNiuNiu(T arr[],int n){
    for(int i = 0;i<n;i++){
        int minIndex = i;
        for(int j= i+1;j<n;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }

}


//插入排序
template<typename T>
void insertionSortNiu(T arr[],int n){
    for(int i=1;i<n;i++){
        for(int j = i;j>0&&arr[j]<arr[j-1];j--){
            swap(arr[j],arr[j-1]);
        }
    }
}
template<typename T>
void insertionSortNiuNiu(T arr[],int n){
        for (int i = 1; i<n;i++){
            for(int j=i;j>0 && arr[j] < arr[j-1]; j--){
                swap(arr[j],arr[j-1]);
            }
        }   
}

template<typename T>
void selectionSortNiu3(T arr[],int n){
    for(int i= 1;i<n;i++){
        for(int j = i;arr[j]<arr[j-1]&&j>0;j--){
            swap(arr[j],arr[j-1]);
        }
    }
}

//插入排序优化版
template<typename T>
void insertionSortNiuPro(T arr[],int n){
    for(int i = 1;i<n;i++){
        T e = arr[i];
        int j;
        for( j= i;j>0&&arr[j-1]>e;j--){
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}
template<typename T>
void insertionSortNiuProNiu(T arr[],int n){
    for (int i= 1;i<n;i++){
        T e = arr[i];
        int j;
        for(j = i;arr[j-1]>e&&j>0;j--){
            arr[j] = arr[j-1];
        }
        arr[j] = e;

    }
}
// 归并排序

template <typename T>
void __merge(T arr[],int l,int mid,int r){
   
    T aux[r-l+1];
    for(int i = l;i<=r;i++){
        aux[i-l] = arr[i];
    }

    int i = l,j = mid+1;
    for(int k = l;k<=r;k++){
       if(i>mid){
           arr[k] = aux[j-l];
           j++;
       }else if(j>r){
           arr[k] = aux[i-l];
           i++;
       }else if(aux[i-l]<aux[j-l]){
            arr[k] = aux[i-l];
            i++; 
        }else{
            arr[k]=aux[j-l];
            j++;
        }
    }
}

template <typename T>
void __mergeSort(T arr[], int l, int r){

    if(l>=r)
        return;
    int mid = (l+r)/2;
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);
    __merge(arr,l,mid,r);
}

template<typename T>
void mergeSortNiu(T arr[],int n){
    __mergeSort(arr,0,n-1);
}
main(){
    
    int n=10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr,n);
    int *arr3 = SortTestHelper::copyIntArray(arr, n);
    int *arr4 = SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("selectionSortNiuNiu",selectionSortNiuNiu,arr,n);
    SortTestHelper::testSort("insertionSortNiu",insertionSortNiu,arr2,n);
    SortTestHelper::testSort("insertionSortNiuPro", insertionSortNiuPro, arr3, n);
    SortTestHelper::testSort("   mergeSortNiu    ", mergeSortNiu, arr4, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    return 0;
}