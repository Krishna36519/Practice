#include <stdio.h>

int main(){
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Check first element
    if(n == 1 || arr[0] > arr[1]){
        printf("Peak element: %d", arr[0]);
        return 0;
    }

    // Check middle elements
    for(int i = 1; i < n-1; i++){
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            printf("Peak element: %d", arr[i]);
            return 0;
        }
    }

    // Check last element
    if(arr[n-1] > arr[n-2]){
        printf("Peak element: %d", arr[n-1]);
    }

    return 0;
}