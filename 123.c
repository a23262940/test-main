#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void aa(){
    FILE *fp;
    int h,i=0,sum=0;
    fp = fopen("t.txt","r");
    while(!feof(fp)){
        fscanf(fp, "%d", &h);
        i++;
        sum += h;
    }
    printf("%d,%d",i, sum);
    fclose(fp);
}
void bb(){
    FILE *fp;
    char str[21];
    int count=0;
    fp = fopen("t.txt", "r");
    if (fp != NULL){
        fgets(str, 21, fp);
        for(int i=0; i<strlen(str); i++){
            if(str[i]!=' ')
                count++;
            if(i==strlen(str)-2)
                break;
        }
        printf("Ans=%d,",count);
        for(int i=0; i<strlen(str); i++){
            if(str[i]>str[strlen(str)-1] && str[i]!=' '){
                printf("1");
            }else if(str[i]<str[strlen(str)-1] && str[i]!=' '){
                printf("0");
            }else if(str[i]!=' '){
                printf("%c", str[i]);
            }
            if(i==strlen(str)-3){
                break;
            }
        }
    }
}
void cc(){
    int arr1[] = {100, 925, 833, 530, 863, 467, 340, 786, 715, 202, 884, 148, 326, 10, 992, 567, 527, 839, 482, 863, 911, 40, 699, 428, 544, 904, 250, 167, 109, 25, 991, 150, 203, 219, 487, 656, 79, 632, 592, 937, 832, 916, 677, 225, 895, 939, 706, 892, 833, 975};
    int in,index,sum1=0,sum2=0;
    printf("Enter an integer: ");
    scanf("%d", &in);
    if (in<2){
        in = 2;
    }else if (in>10){
        in = 10;
    }
    index = sizeof(arr1) / sizeof(arr1[0]);
    for (int i = 0;i<index;i++){
        if(i%in == 0){
            sum1 += arr1[i];
        }else if(i%in!=0 && i!=index-1){
            sum2 += arr1[i];
        }
    }
    printf("%d,%d\n",sum1,sum2);
    printf("A=%d\tB=%d", index-1, sum2-sum1);
}

int main(int argc, char *argv[]){
    char ch;
    int sum=0,index,arr2[][4] = {{28, 18, 40, 34}, {328, 893, 140, 34}, {566, 722, 531, 323}, {658, 512, 145, 32}, {17, 5, 35, 546}, {287, 927, 378, 6}, {45, 954, 516, 892}, {6, 322, 852, 343}, {7,78, 937, 668}, {184, 660, 633, 76}, {211, 662, 862, 272}, {99, 351, 577, 331}, {859, 43, 754,10}};
    printf("Enter a char: ");
    scanf("%c", &ch);
    if(ch<65 || ch>68){
        printf("Only A B C D E");
        return 1;
    }
    index = sizeof(arr2) / sizeof(arr2[0]);
    for (int i = 0; i < index;i++)
        sum += arr2[i][ch - 65];
    printf("%c : %d\n",ch,sum);
}