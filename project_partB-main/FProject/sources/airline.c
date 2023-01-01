//
// Created by Barak
//

#include "../headers/functions.h"
#include "../headers/airline.h"

int initAirline(Airline* pAirline) {
    pAirline->name = createDynamicStr(ENTER_AIRLINE_NAME);
    if (!pAirline->name) {
        printf(ALLOCATE_ERR);
        return 0;
    }

    pAirline->num_of_flights = 0;
    pAirline->all_flights = (Flight**) malloc(sizeof(Flight*) * 10);

    if (!pAirline->all_flights) {
        printf(ALLOCATE_ERR);
        return 0;
    }

    return 1;
}

void printAirline(const AirportManager* pAirportManager, const Airline* pAirline) {
    printf(PRINT_AIRLINE, pAirline->num_of_flights, pAirline->name);

    for (int i = 0; i < pAirline->num_of_flights; i++)
        printFlight(pAirportManager, pAirline->all_flights[i]);
}

void freeAirline(Airline* pAirline) {
    free(pAirline->name);

    for (int i = 0; i < pAirline->num_of_flights; i++)
        free(pAirline->all_flights[i]);

    free(pAirline->all_flights);
}

int addFlight(const AirportManager* pAirportManager, Airline* pAirline) {
    Flight* pFlight = (Flight*) malloc(sizeof(Flight));
    if (!pFlight) {
        printf(ALLOCATE_ERR);
        return 0;
    }

    if (!initFlight(pAirportManager, pFlight))
        return 0;

    pAirline->all_flights = realloc(pAirline->all_flights,sizeof(Flight*) * (++pAirline->num_of_flights));
    pAirline->all_flights[pAirline->num_of_flights - 1] = pFlight;
    return 1;
}

void printAllFlightsInLine(const AirportManager* pAirportManager, const Airline* pAirline) {
    char origin_code[IATA_CODE_SIZE + 1], dest_code[IATA_CODE_SIZE + 1];

    getCode(origin_code, ENTER_ORIGIN_CODE);
    getCode(dest_code, ENTER_DEST_CODE);

    int exist = countSimilarFlights(pAirline->all_flights, pAirline->num_of_flights, origin_code, dest_code);

    char* origin_airport_country = findAirportByIATA(pAirportManager, origin_code)->country;
    char* dest_airport_country = findAirportByIATA(pAirportManager, dest_code)->country;

    if (exist == 0)
        printf(FLIGHT_NOT_EXIST);
    else {
        printf(ALL_FLIGHTS_BY_CODES, exist, origin_airport_country, dest_airport_country);

        for (int i = 0; i < pAirline->num_of_flights; i++)
            if (checkFlightDest(pAirline->all_flights[i], origin_code, dest_code))
                printFlight(pAirportManager, pAirline->all_flights[i]);

    }
}
