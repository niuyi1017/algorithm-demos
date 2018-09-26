//慕课网 跟随练习

#include <iostream>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"


using namespace std;
//选择排序..............................................................................................................
template<typename T>
void selectionSort(T arr[], int n){
    for(int i=0;i<n;i++){
        int minIndex = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
}
//插入排序.....................................................................................................
template<typename T>
void insertionSort(T arr[],int n){
    for (int i = 1; i < n; i++)
    {
        //  寻找元素arr[i]合适的插入位置
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
        {
            swap(arr[j],arr[j-1]);
        }
    }
}
//插入排序PRO
template <typename T>
void insertionSort2(T arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        T e = arr[i];
        int j;
        //  寻找元素arr[i]合适的插入位置
        for (j = i; j > 0 && arr[j-1] > e; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

template<typename T>
//插入排序l to r

void insertionSortL2R(T arr[],int l,int r){
    for(int i = l+1;i<=r;i++){
        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j - 1] > e; j--)
            arr[j] = arr[j - 1];
        arr[j] = e;
    }
    return;
}

//并归排序.................................................................................................

template <typename T>
//将arr[l...mid]和arr[mid+1...r]进行归并
void __merge(T arr[], int l, int mid, int r)
{

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
            arr[k] = aux[j-l];
            j++;
        }
    }

}
//递归使用归并排序，对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[],int l,int r){
    // if(l>=r)//递归函数先要处理结束的条件
    //     return;

    if(r-l<=15){
        insertionSortL2R(arr,l,r);
        return;
    }
    int mid = (l+r)/2;
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);
    if(arr[mid]>arr[mid+1])
        __merge(arr,l,mid,r);

}
template<typename T>
void mergeSort(T arr[],int n){
    __mergeSort(arr,0,n-1);
}


main(){
    
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr,n);
    // int *arr3 = SortTestHelper::copyIntArray(arr,n);
    // int *arr4 = SortTestHelper::generateNearlyOrderedArray(n,200);
    
    // SortTestHelper::testSort("Selection Sort  ", selectionSort,arr,n);
    // SortTestHelper::testSort("Insertion Sort  ", insertionSort,arr2,n);
    // SortTestHelper::testSort("Insertion Sort 2", insertionSort2, arr3, n);
    // SortTestHelper::testSort("Insertion Sort 3", insertionSort2, arr4, n);
  
   
    SortTestHelper::testSort("Insertion Sort2  ", insertionSort2, arr, n);
    SortTestHelper::testSort("  Merge    Sort  ", mergeSort, arr2, n);
    
    delete[] arr;
    delete[] arr2;
    // delete[] arr3;
    // delete[] arr4;

    return 0;
    

}

// SortTestHelper::ptintArr(arr,n);

// for(int i=0;i<n;i++){
//    cout<<arr[i]<<"\t";
// }
// cout << endl;
// cout<<"hello world"<<" ";
// cout << endl;

// float b[10] = {10.5, 9.2, 8.2, 7.2, 6.2, 5.2, 42.1, 3.3, 2.5, 1.5};
// selectionSort(b, 10);
// for (int i = 0; i < 10; i++)
// {
//     cout << b[i] << " ";
// }
// cout<<endl;

// string c[4] = {"D","C","B","A"};
// selectionSort(c, 4);
// for (int i = 0; i < 4; i++)
// {
//     cout << c[i] << " ";
// }
// cout << endl;

// Student d[4] = {
//     {"d", 90},
//     {"c", 95},
//     {"b", 100},
//     {"a", 95}
// };
// selectionSort(d, 4);
// for (int i = 0; i < 4; i++)
// {
//     cout << d[i];
// }
// cout << endl;
   
