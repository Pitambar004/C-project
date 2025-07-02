#include<stdio.h>
#include<conio.h>



float calculateCharges(float hours){

    float charge;

    if(hours<=3){
        charge = 2.00;
    }
    else if(hours<=24){
        charge = 2.00 + 0.50 *(hours-3);
        if (charge>10.00){
            charge=10.00;
        }
    }


    return charge;

}


int main(){

    float hrs, totalRecipent=0, charge;
    int people;

    while(1){
        printf("Enter the time in hours(Negative to stop the program):");
        scanf("%f",&hrs);

        if(hrs<0){
            break;
        }
        people++;

        charge= calculateCharges(hrs);
        totalRecipent= totalRecipent + charge ;

       

        printf("Current Charge %.2f, Total recipt of %d people is %.2f\n", charge,people,totalRecipent);
    }





    return 0;
}