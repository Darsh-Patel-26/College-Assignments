#include"iostream"

using namespace std;

int n;

void setArray(int arr[])
{
    cout<<"Enter "<<n<<" no. :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
}

void getArray(int arr[])
{
    cout<<"Array :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void mergeConqueror(int arr[], int si, int mid, int ei)
{
    int sorter[ei-si+1];
    int x=0,idx1 = si,idx2 = mid+1;

    while (idx1<=mid && idx2<=ei)
    {
        if (arr[idx1]<=arr[idx2])
        {
            sorter[x++] = arr[idx1++];
        }
        else
        {
            sorter[x++] = arr[idx2++];
        }
    }
    while (idx1<=mid)
    {
        sorter[x++] = arr[idx1++];
    }
    while (idx2<=ei)
    {
        sorter[x++] = arr[idx2++];
    }

    for (int i = 0, j=si; i < x; i++,j++)
    {
        arr[j] = sorter[i];
    }
    
}

void mergeDivider(int arr[], int si, int ei)
{
    if(si<ei)
    {
        int mid = si + (ei-si)/2;
        
        mergeDivider(arr,si,mid);
        mergeDivider(arr,mid+1,ei);

        mergeConqueror(arr,si,mid,ei);
    }
}

int main(int argc, char const *argv[])
{
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    setArray(arr);
    mergeDivider(arr,0,n-1);
    getArray(arr);
    return 0;
}