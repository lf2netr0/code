//B10309002
#include<stdio.h>
#include<stdlib.h>
int a,c,i;
int year,month,date,week,first_space,feb_days;

int main(void){
    printf("First,let's set the system.\n");
    printf("Enter Year Now:\n");
    scanf("%d",&year);
    printf("Enter Month Now:\n");
    scanf("%d",&month);
    printf("Enter date Now:\n");
    scanf("%d",&date);
    printf("Enter week(0~6) Now:\n");
    scanf("%d",&week);

    if(year%4==0 && year%100!=0 || year%400==0){
       feb_days =29;
    }
    else{
       feb_days =28;
    }
    int days[13]={0,31,feb_days,31,30,31,30,31,31,30,31,30,31};
    c=date-1;
    for(i=month-1;i>1;i--){
        c=c+days[i];
    }
    first_space=(week+(c%7))%7;
    for(i=year;i>1;i--){
        if(i%4==0 && i%100!=0 || i%400==0){
            first_space=first_space-2;
        }
        else{
            first_space=first_space-1;
        }
        if(first_space<0){
            first_space*=(-1);
        }
    }
    printf("You can start to search in Calendar.\n");
    printf("Enter Year:\n");
    scanf("%d",&year);
    printf("Enter Month:\n");
    scanf("%d",&month);

    for(a=1;a<=(year-1);a++){
        if(a%4==0 && a%100!=0 || a%400==0){
            first_space=(first_space+366)%7;
        }
        else{
            first_space=(first_space+365)%7;
        }
    }
    if(year%4==0 && year%100!=0 || year%400==0){
       feb_days =29;
    }
    else{
       feb_days =28;
    }
    int space[13]={0,first_space,0,0,0,0,0,0,0,0,0,0,0};
    int days2[13]={0,31,feb_days,31,30,31,30,31,31,30,31,30,31};
    for(i=1;i<month;i++){
        space[i+1]=(space[i]+days2[i])%7;
    }

    char day[7][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    printf("Year:%d Month:%d\n",year,month);
    for(i=0;i<7;i++){
        printf("%s ",day[i]);
    }
    printf("\n");
    for(i=1;i<=space[month];i++){
        printf("    ");
    }
    for(i=1;i<=days2[month];i++){
        if(i<10){
            printf("  %d ",i);
        }
        else{
            printf(" %d ",i);
        }
        if(i%7==(7-space[month])%7){
            printf("\n");
        }
    }
    printf("\n");
    system("pause");
    return 0;

}
