#include <stdio.h>

int main(){
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i < n; i++){
        if((i == 0 || arr[i] > arr[i-1]) && (i == n-1 || arr[i] > arr[i+1])){
            printf("Peak element: %d", arr[i]);
            return 0;
        }
    }

    return 0;
}