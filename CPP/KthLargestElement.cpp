// kth largest in an unsorted array
#include <iostream>
using namespace std;
int partition(int * arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
int kthlargest(int k, int n, int arr[],int l,int h)
{
    int i;
    i=partition(arr,l,h);
    if(i==k){
        return arr[i];
    }
    else if(i>k){
        kthlargest(k,n,arr,l,i-1);
    }
    else{
        kthlargest(k,n,arr,i+1,h);
    }

}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    k=n-k;
    cout << kthlargest(k,n,arr,0,n-1)<<endl;
    return 0;
}
