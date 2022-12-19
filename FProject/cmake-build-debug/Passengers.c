//
// Created by amitg on 13/12/2022.
//
#include "Passengers.h"

struct Passengers passini()
{
    struct Passengers A;
    printf("Enter first name: ");
    scanf_s("%s",A.first_name);
    printf("Enter last name: ");
    scanf_s("%s",A.last_name);
    printf("Enter ID: ");
    scanf_s("%d",&A.id);
    printf("Enter Seat: ");//A29 for example.
    scanf_s("%s",&A.seat);

    return A;
}

struct plane planeini()
{
    struct plane A;
    int i=0;
    for(i=0;i<Plane_Size;i++)
    {
        A.People[i] = NULL;
    }
    A.Occupied = 0;
    A.MoneyEarned = 0;
    return A;
}

void profit(int num) {
    printf("expected profit from flight is %d",num*Price);
}

void AddPassenger(struct plane *A)
{
    int num;
    struct Passengers *B = NULL;
    int i=0,j=0;

    printf("Enter number of passengers: ");
    scanf_s("%d",&num);
    B =(struct Passengers*)malloc(sizeof(struct Passengers)*num);
    if(B == NULL)
    {
        printf("Error allocating memory.");
        return;
    }

    for(i=0;i<num;i++)
    {
        B[i] = passini();
    }
    for(i=0;i<Plane_Size;i++)
    {
        if(A->People[i] == NULL)
        {
            A->People[i] = &B[j];
            j++;
        }
        else
        {
            continue;
        }
    }
    A->Occupied+=num;
    A->MoneyEarned+=Price*num;

    profit(num);
}


