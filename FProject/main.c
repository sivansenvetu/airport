//
// Created by Barak
//

#include "headers/functions.h"
#include "headers/airport_manager.h"
#include "headers/airline.h"
#include "Passengers.h"
#include <time.h>



void freeAll(AirportManager* airportManager, Airline* airline) {
    freeAirportManager(airportManager);
    freeAirline(airline);
}
void print_random_weather() {
    // Seed the random number generator with the current time
    srand(time(0));

<<<<<<< HEAD
=======

#include <stdio.h>
#include <stdlib.h>
#include <time.h>






void print_random_weather() {
    // Seed the random number generator with the current time
    srand(time(0));

>>>>>>> origin/main
    // Declare an array of possible weather conditions
    char *conditions[] = {
            "clear skies",
            "partly cloudy",
            "mostly cloudy",
            "overcast",
            "light rain",
            "heavy rain",
            "thunderstorms",
            "snow"
    };

    // Generate a random index between 0 and the number of conditions - 1
    int index = rand() % (sizeof(conditions) / sizeof(char*));

    // Print the random weather condition
    printf("Current weather for the flight: %s\n", conditions[index]);
}
<<<<<<< HEAD
=======

>>>>>>> origin/main
void printMenu() {
    printf("\n1. Add Flight to airline\n"
           "2. Add Airport to AirportManager\n"
           "3. Print Airline data\n"
           "4. Print AirportManager data\n"
           "5. Print all flights by airports\n"
<<<<<<< HEAD
           "6. Add Passengers\n"
=======
           "6. Passengers Management\n"
>>>>>>> origin/main
           "7. show weather for today\n "
           "8. fuel consumption\n"
           "9. Quit\n\n"
           "Enter your choose:");
}

int getChoose() {
    int choose = 0;
    while (choose > 9 || choose < 1) {
        printMenu();
        scanf("%d", &choose);
    }
    return choose;
}

void printPassMenu() {
    printf("Add Passengers\n");
}

void run(AirportManager* airportManager, Airline* airline,struct plane *A) {
    int choose = getChoose();
    int PC;
    while (choose != 9) {
        flush();
        switch (choose) {
            case 1:
                addFlight(airportManager, airline);
                break;
            case 2:
                addAirport(airportManager);
                break;
            case 3:
                printAirline(airportManager, airline);
                break;
            case 4:
                printAirportManager(airportManager);
                break;
            case 5:
                printAllFlightsInLine(airportManager, airline);
                break;
            case 6:
                AddPassenger(&A);
                break;
            case 7: {
                print_random_weather();
                break;
            }
            case 8:{
                Gas_Consumption();
                break;
            }
            case 7: {
                print_random_weather();
            }
            case 8:{
                Gas_Consumption();
            }
        }
        choose = getChoose();
    }
    printf(EXIT);
}

int main() {

    struct plane A = planeini();


<<<<<<< HEAD
    printf("  \\----------------------------------\\\n"
           "   \\                                  \\        __\n"
           "    \\                                  \\       | \\\n"
           "     >                                  >------|  \\       ______\n"
           "    /                                  /       --- \\_____/**|_|_\\____  |\n"
           "   /                                  /          \\_______ --------- __>-}\n"
           "  /----------------------------------/              /  \\_____|_____/   |\n"
           "                                                    *         |\n"
           "                                                             {O}\n"
           "\n"
           "       /*\\       /*\\       /*\\       /*\\       /*\\       /*\\       /*\\\n"
           "      |***|     |***|     |***|     |***|     |***|     |***|     |***|\n"
           "       \\*/       \\*/ ____  \\*/       \\*/       \\*/       \\*/       \\*/\n"
           "        |         |  |  |   |         |         |         |         |\n"
           "  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    printf("\n");
=======
printf("  \\----------------------------------\\\n"
       "   \\                                  \\        __\n"
       "    \\                                  \\       | \\\n"
       "     >                                  >------|  \\       ______\n"
       "    /                                  /       --- \\_____/**|_|_\\____  |\n"
       "   /                                  /          \\_______ --------- __>-}\n"
       "  /----------------------------------/              /  \\_____|_____/   |\n"
       "                                                    *         |\n"
       "                                                             {O}\n"
       "\n"
       "       /*\\       /*\\       /*\\       /*\\       /*\\       /*\\       /*\\\n"
       "      |***|     |***|     |***|     |***|     |***|     |***|     |***|\n"
       "       \\*/       \\*/ ____  \\*/       \\*/       \\*/       \\*/       \\*/\n"
       "        |         |  |  |   |         |         |         |         |\n"
       "  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
printf("\n");
>>>>>>> origin/main
    // init Airport Manager
    AirportManager airportManager;
    initAirportManager(&airportManager);

    // add airports
    int airport_num;
    printf(ENTER_NUMBER_OF_AIRPORTS);
    scanf("%d", &airport_num);
    flush();

    for (int i = 0; i < airport_num; i++)
        addAirport(&airportManager);

    // init Airline
    Airline airline;
    initAirline(&airline);

    // menu
    run(&airportManager, &airline,&A);

    // exit
    freeAll(&airportManager, &airline);

    return 0;
}
