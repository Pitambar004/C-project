#include<stdio.h>
#include<conio.h>

float residentialBill(){

    float totalUsage, bill;

    printf("Enter the toal usage in Kilowatt Hours(KWH):\n");
    scanf("%f",&totalUsage);
    bill=(totalUsage*0.12)+8.07;
    bill=(bill*0.05)+bill;
    return bill;
}



float BusinessBill(){
    float totalUsage, bill, premiumChannel;
    printf("Enter the toal usage in Kilowatt Hours(KWH):\n");
    scanf("%f",&totalUsage);
    printf("Enter the number of Premium channel used:\n");
    scanf("%f",&premiumChannel);
    if(totalUsage<=1200){
        bill=(totalUsage*0.17)+(premiumChannel*47.00)+17.07;
    }

    else{
        bill=(1200*0.17)+((totalUsage-1200)*0.12)+(premiumChannel*47.00)+17.07;
    }
    bill=(bill*0.08)+bill;

    return bill;


}


    



void changeInConsumption( float Namount){
    float lastamount , change;

    printf("Enter the amount due of your previous bill\n");
    scanf("%f",&lastamount);
    if(lastamount > Namount){
        change= (lastamount-Namount)/lastamount;
        printf("The change in consumption is decreasing by %.2lf%%, when comparing with previous due\n", change * 100);
    }else if(Namount>lastamount){
        change=(Namount-lastamount)/lastamount;
        printf("The change in consumption is increasing by %.2lf%%, when comparing with previous due\n", change * 100);
    }else{
        printf("There is no change in the consumption\n");
    }


}


void InstallmentCalculator(float amount){
    int installments;
    float rate,nAmount,installAmount;
    printf("Enter the number of required Installment (2,3,4):\n");
    scanf("%d",&installments);
    if(installments==2){
        rate=0.0535;
        nAmount=amount+(amount*rate);
        installAmount=nAmount/installments;
        printf("With %d installment your bill of $%.2lf will be worth $%.2lf.\n", installments, amount, nAmount);
        printf("Each installment will be worth $%.2lf.\n", installAmount);
    }else if( installments == 3){
        rate=0.055;
        nAmount=amount+(amount*rate);
        installAmount=nAmount/installments;
        printf("With %d installment your bill of $%.2lf will be worth $%.2lf.\n", installments, amount, nAmount);
        printf("Each installment will be worth $%.2lf.\n", installAmount);

    }else if( installments ==4){
        rate=0.0575;
        nAmount=amount+(amount*rate);
        installAmount=nAmount/installments;
        printf("With %d installment your bill of $%.2lf will be worth $%.2lf.\n", installments, amount, nAmount);
        printf("Each installment will be worth $%.2lf.\n", installAmount);
        
    }

}


void MenuDisplay(float amount)
{
    char choice;
    while(1)
    {
        printf("Please select an option:\n");
        printf("I- Enroll in our Installment Plan\n");
        printf("V- View change in consumption: Compare your current bill with your previous one\n");
        printf("E- Exit\n");
        scanf(" %c",&choice);

        if(choice=='E'){
            printf("Goodbye.\n");
            break;
        }
        else if(choice=='I'){
            char plan;
            printf("If you don not want to make a onetime payment, we have an easy\n installment plan for you. This is an interest charge plan.\n Sign up for the installment payment plan(Y/N)?\n");
            scanf(" %c",&plan);
            if(plan=='Y'){
                InstallmentCalculator(amount);
            }
        }
        else if(choice=='V'){
                changeInConsumption(amount);
            }

    }
        



}





int main(){
    char Customer;
    float Bill;
    printf("Enter the customer type: R,r(Residenal) or B,b(Business):\n");
    scanf(" %c",&Customer);
    if(Customer=='R' || Customer=='r'){
        printf("Welcome to Residental Customer\n");
        Bill= residentialBill();
    }
    else if(Customer=='B' || Customer=='b'){
        printf("Welcome to Business Customer\n");
        Bill= BusinessBill();
    }

    printf("Amount due= $%.2f\n",Bill);
    printf("30 Billing Days\n");
    printf("Average cost per Day = $%.2f\n",Bill/30);
    MenuDisplay(Bill);
    return 0;

}