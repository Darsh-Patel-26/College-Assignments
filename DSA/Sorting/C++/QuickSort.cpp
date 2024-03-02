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

int partition(int arr[], int si, int ei)
{
    int i = si, j = ei;
    int key = arr[i];
    do
    {
        while (key>=arr[i])
        {
            i++;
        }
        while (key<arr[j])
        {
            j--;
        }
        if (i<j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        
    } while (i<j);
    int temp = arr[si];
    arr[si] = arr[j];
    arr[j] = temp;

    return si;
}

void quickSort(int arr[], int si, int ei)
{
    if (si<ei)
    {
        int pivotIdx = partition(arr,si,ei);

        quickSort(arr,si,pivotIdx-1);
        quickSort(arr,pivotIdx+1,ei);
    }
}

int main(int argc, char const *argv[])
{
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    setArray(arr);
    quickSort(arr,0,n-1);
    getArray(arr);
    return 0;
}