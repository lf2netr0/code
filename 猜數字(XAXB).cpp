#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int q[5];
int a,a1=10000,a2=100000,t,v,ans[5],A,B,C,times=0,control;

void question();
int main(void){
    question();
    do{
        control = 0;
        printf("Enter a integer between 12345 to 98765:\n");
        scanf("%d",&a);
        ans[0]=a/10000;
        ans[1]=(a/1000)%10;
        ans[2]=(a/100)%10;
        ans[3]=(a/10)%10;
        ans[4]=a%10;
        if (a==0)
                {
                    printf("Answer is %d%d%d%d%d.\n",q[0],q[1],q[2],q[3],q[4]);
                    break;
                }
        if(a>a1)
        {
            if(a<a2)
            {
                for(t=0;t<=4;t++){
                    for(v=t+1;v<=4;v++){
                        if(ans[t]==ans[v]){
                            printf("Every number can't repeat.\n");
                            control = 1;
                            break;
                        }
                    }
                }
                if(control==0)
                {
                    while(1)
                    {
                        times+=1;
                        printf("The %d times\n",times);
                        A=0;
                        B=0;
                        C=0;
                        for(t=0;t<=4;t++){
                            if(q[t]==ans[t]){
                                A=A+1;
                            }
                            else{
                                for(v=0;v<=4;v++){
                                    if(q[t]==ans[v]){
                                        B=B+1;
                                    }
                                }
                            }
                        }
                        C=5-B-A;
                        printf("%dA%dC\n",A,C);
                        if(A==5){
                            printf("You win the Game!\n");
                            printf("Answer is %d%d%d%d%d.\n",q[0],q[1],q[2],q[3],q[4]);
                            break;
                        }
                        else{
                            control=1;
                            break;
                        }
                    }
                }
            }
            else if(a>a2)
            {
                printf("Please enter integer between 12345 to 98765.\n");
                control=1;
            }
        }
        else
        {
            printf("Please enter integer between 12345 to 98765.\n");
            control=1;
        }
    }while(control == 1);

    system("pause\n");
    return 0;
}

void question(){//產生問題(利用時間種子產生亂數)
    int i,j;
    int repeat;
    srand(time(NULL));
    q[0]=rand()%9+1;
    do{
        repeat=0;
        for(i=1;i<=4;i++){
            q[i]=rand()%10;
            for(j=0;j<i;j++){
                if(q[i]==q[j]){
                    repeat=1;
                    break;
                }
            }
        }
    }while(repeat==1);
}
