//
//  main.c
//  归并排序
//
//  Created by assassin on 2017/7/1.
//  Copyright © 2017年 assassin. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
 


void MergeSort(int arr[], unsigned int first, unsigned int last);
void merge(int arr[], int low, int mid, int high);
void xuanzhe(int arr[]);
int main(int argc, const char * argv[]) {
    printf("before merge sort:");
    int a[7] = {49,38,65,97,76,13,27};
    int low = 0;
    int height = 6;
    
    printf("before merge sort:");
    
    for (int i = 0; i <= height; i++) {
        printf("%d ,",a[i]);
    }
    
    MergeSort(a, low, height);
    //xuanzhe(a);
    printf("After merge sort: ");
    
    for (int i = low; i <= height; i++) {
        printf("%d ,",a[i]);
    }

    return 0;
}


void merge(int arr[], int low, int mid, int high){
    int i, k;
    int *tmp = (int *)malloc((high-low+1)*sizeof(int));
    //申请空间，使其大小为两个
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;

    for(k=0; left_low<=left_high && right_low<=right_high; k++){  // 比较两个指针所指向的元素
        if(arr[left_low]<=arr[right_low]){
            tmp[k] = arr[left_low++];
        }else{
            tmp[k] = arr[right_low++];
        }
    }

    if(left_low <= left_high){  //若第一个序列有剩余，直接复制出来粘到合并序列尾
    //memcpy(tmp+k, arr+left_low, (left_high-left_low+l)*sizeof(int));
    for(i=left_low;i<=left_high;i++)
        tmp[k++] = arr[i];
    }

    if(right_low <= right_high){
    //若第二个序列有剩余，直接复制出来粘到合并序列尾
    //memcpy(tmp+k, arr+right_low, (right_high-right_low+1)*sizeof(int));
        for(i=right_low; i<=right_high; i++)
            tmp[k++] = arr[i];
    }

    for(i=0; i<high-low+1; i++)
        arr[low+i] = tmp[i];
    free(tmp);
    return;
}


void MergeSort(int arr[], unsigned int first, unsigned int last){
    int mid = 0;
    if(first<last){
        mid = (first+last)/2; /* 注意防止溢出 */
        /*mid = first/2 + last/2;*/
        //mid = (first & last) + ((first ^ last) >> 1);
        MergeSort(arr, first, mid);
        MergeSort(arr, mid+1,last);
        merge(arr,first,mid,last);
    }
    return;
}





void xuanzhe(int arr[]){
    for(int i = 0;i < 7;i++){
        for(int t = i ;t < 7 ;t++){
            if(arr[i] > arr[t]){
                int a = arr[t];
                arr[t] = arr[i];
                arr[i] = a;
            }
        }
    }
}

