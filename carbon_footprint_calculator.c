#include <stdio.h> 


const float car_factor = 0.2;
const float bus_factor = 0.1;
const float taxi_factor = 3.0;
const float subway_factor = 0.04;
const float electricity_factor= 0.4;
const float water_factor = 3.0;
const float gas_factor = 2.0;
const float meat_factor = 27.0;
const float waste_factor = 10.5;
const float cigarettes_factor = 14.0;


float transport_car();
float transport_bus();
float transport_taxi();
float transport_subway();
float energy_electricity();
float energy_gas();
float water();
float food_meat();
float waste();
float cigarettes();


int main() {
    int choice;
    float total = 0;
    float categories[10]={0};
    do{
        printf("Carbon Footprint Calculator\n");
        printf("1 Transport (car)\n");
        printf("2 Transport (bus)\n");
        printf("3 Transport (taxi)\n");
        printf("4 Transport (subway)\n");
        printf("5 Energy (electricity)\n");
        printf("6 Energy (gas)\n");
        printf("7 Water\n");
        printf("8 Food (meat)\n");
        printf("9 Waste\n");
        printf("10 Cigarettes\n");
        printf("0 End and result\n");
        printf("Choose a category from 0 to 10\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: categories[0] = transport_car(); total += categories[0]; break;
        case 2: categories[1] = transport_bus(); total += categories[1]; break;
        case 3: categories[2] = transport_taxi(); total += categories[2]; break;
        case 4: categories[3] = transport_subway(); total += categories[3]; break;
        case 5: categories[4] = energy_electricity(); total += categories[4]; break;
        case 6: categories[5] = energy_gas(); total += categories[5]; break;
        case 7: categories[6] = water(); total += categories[6]; break;
        case 8: categories[7] = food_meat(); total += categories[7]; break;
        case 9: categories[8] = waste(); total += categories[8]; break;
        case 10: categories[9] = cigarettes(); total += categories[9]; break;
        case 0: printf("=============================================\n"); break;
        default: printf("Invalid selection!\n"); break;
        }

    }
    while(choice!=0);
    
     const char* names[10] = {
        "Transport (car)",
        "Transport (bus)",
        "Transport (taxi)",
        "Transport (subway)",
        "Energy (electricity)",
        "Energy (gas)",
        "Water",
        "Food (meat)",
        "Waste",
        "Cigarettes"
    };

    FILE *f = fopen("results.txt", "w");

    if (f == NULL) {
        printf("Error: could not open results.txt for writing.\n");
        return 1;
    }

    fprintf(f, "Total carbon footprint per month: %.2f kg CO2\n\n", total);

    for (int i = 0; i < 10; i++) {
        if (categories[i] > 0) {
            fprintf(f, "%d %s: %.2f %%\n", i+1, names[i], (categories[i] / total) * 100);
        }
    }

    fclose(f);
    printf("Results saved to results.txt\n");
}


float transport_car(){
   float km;
   do{
       printf("Enter km by car per month: ");
       scanf("%f", &km);
       if(km<0){
           printf("Should be a positive number!\n");
       }
    }
    while(km<0);

    return km * car_factor;
}

float transport_bus(){
    float times;
    do{
        printf("Enter how many times you use the bus per month: ");
        scanf("%f", &times);
        if(times<0){
            printf("Should be a positive number!\n");
        }
    }
    while(times<0);

    return times * bus_factor;
}

float transport_taxi(){
    float times;
    do{
        printf("Enter how many times you use the taxi per month: ");
        scanf("%f", &times);
        if(times<0){
            printf("Should be a positive number!\n");
        }
    }
    while(times<0);

    return times * taxi_factor;
}

float transport_subway(){
    float times;
    do{
        printf("Enter how many times you use the subway per month: ");
        scanf("%f", &times);
        if(times<0){
            printf("Should be a positive number!\n");
        }
    }
    while(times<0);

    return times * subway_factor;
}

float energy_electricity(){
    float kwh;
    do{
        printf("Enter electricity consumed (kWh) per month: ");
        scanf("%f", &kwh);
        if(kwh<0){
            printf("Should be a positive number!\n");
        }
    }
    while(kwh<0);

    return kwh * electricity_factor;
}

float energy_gas(){
    float cubm;
    do{
        printf("Enter gas consumed (m^3) per month: ");
        scanf("%f", &cubm);
        if(cubm<0){
            printf("Should be a positive number!\n");
        }
    }
    while(cubm<0);

    return cubm * gas_factor;
}

float water(){
    float cubm;
    do{
        printf("Enter water consumed (m^3) per month: ");
        scanf("%f", &cubm);
        if(cubm<0){
            printf("Should be a positive number!\n");
        }
    }
    while(cubm<0);

    return cubm * water_factor;
}

float food_meat(){
    float kg;
    do{
        printf("Enter meat consumed (kg) per month: ");
        scanf("%f", &kg);
        if(kg<0){
            printf("Should be a positive number!\n");
        }
    }
    while(kg<0);

    return kg * meat_factor;
}

float waste(){
    float count;
    do{
        printf("Enter the number of trash bags per month: ");
        scanf("%f", &count);
        if(count<0){
            printf("Should be a positive number!\n");
        }
    }
    while(count<0);

    return count * waste_factor;
}

float cigarettes(){
    float count;
    do{
        printf("Enter the number of cigarette packs per month: ");
        scanf("%f", &count);
        if(count<0){
            printf("Should be a positive number!\n");
        }
    }
    while(count<0);

    return count * cigarettes_factor;
}
