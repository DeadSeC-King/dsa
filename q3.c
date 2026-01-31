//wap to convert a string from upper case to lower case
#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    printf("Enter a string in upper case:");
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]=str[i]+32;
        }
    }
    printf("String in lower case:%s",str);
    return 0;
}