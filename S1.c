#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str[100];
    char letters[100] = "", numbers[100] = "", alphanumeric[100] = "";
    int l = 0, n = 0, a = 0;
    int i = 0;
    
    printf("Enter a string (e.g., abc123a1b2): ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline
    
    // Extract individual characters and categorize
    while(str[i] != '\0'){
        int hasLetter = 0, hasDigit = 0;
        char temp[50];
        int j = 0;
        
        // Extract a continuous word/segment
        while(str[i] != '\0' && isalnum(str[i])){
            temp[j++] = str[i];
            if(isalpha(str[i])) hasLetter = 1;
            if(isdigit(str[i])) hasDigit = 1;
            i++;
        }
        temp[j] = '\0';
        
        // Categorize the segment
        if(j > 0){
            if(hasLetter && hasDigit){
                // Alphanumeric (mixed letters and numbers)
                strcpy(alphanumeric + a, temp);
                a += j;
                alphanumeric[a++] = ' ';
            }
            else if(hasLetter){
                // Pure letters
                strcpy(letters + l, temp);
                l += j;
                letters[l++] = ' ';
            }
            else if(hasDigit){
                // Pure numbers
                strcpy(numbers + n, temp);
                n += j;
                numbers[n++] = ' ';
            }
        }
        if(str[i] != '\0') i++;
    }
    
    letters[l] = '\0';
    numbers[n] = '\0';
    alphanumeric[a] = '\0';
    
    printf("\nLetters: %s\n", l > 0 ? letters : "None");
    printf("Numbers: %s\n", n > 0 ? numbers : "None");
    printf("Alphanumeric: %s\n", a > 0 ? alphanumeric : "None");
    
    return 0;
}