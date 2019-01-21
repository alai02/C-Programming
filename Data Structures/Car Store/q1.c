#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

typedef struct car {
    int mileage;
    char * plate_number;
    int returndate;  // will be 0 if car is in repair or is available for rent, 
                     // otherwise the car is in rent and will have an expected return date
    struct car * next;

} car;

car* makeNewCar(char* plate_no, int mileage){
    car * newcar = malloc(sizeof(car));
    newcar->mileage = mileage;
    newcar->plate_number = plate_no;
    newcar->returndate = 0;
    return newcar;
}

void printCars(car * head){  //takes any of the three lists and prints them
    car * current = head;  
    while(current != NULL){
        printf("car plate: %s, mileage: %i ,return date: %i\n", current->plate_number, current->mileage, current->returndate);
        current = current->next;
    }
    printf("\n");
}

void addToAvailableList(car ** availables, car* the_car){  // adds the car to the available cars list, sorted by their mileage
    car * current = *availables;  
    the_car->returndate = 0;
    if(current == NULL){
        *availables = the_car;
        the_car->next = NULL;
        return;
    }
    if(current->next == NULL){
        if(the_car->mileage < current->mileage){
            the_car->next = *availables;
            *availables = the_car;
        }else{         
            the_car->next = NULL;
            (*availables)->next = the_car;            
        }
        return;
    }
    car * before = *availables;
    while(true){
        if(current==NULL){//reached the end
            before->next = the_car;
            the_car->next = NULL;
            return;
        }
        if(the_car->mileage < current->mileage){
            if(current == before){
                the_car->next = *availables;
                (*availables)->next = the_car;
                return;
            }
            the_car->next = current;
            before->next = the_car;
            return;
        }
        before = current;
        current = current->next;
    }
    return;
}


void addToRepairList(car** repairs, car * broken_car){ // adds a broken car to the repairs list 
    broken_car->next = *repairs;
    *repairs = broken_car; 
}
void rentFromAvailable(car** rented_cars, car** available_cars, int expected_return_date){ //rents the first available car, sorts it by return date
    if(*available_cars == NULL){
        printf("There are no cars available. \n");
        return;
    }
    car * rented_car = *available_cars; // picking the car on the top (it will have the least mileage)
    rented_car->returndate = expected_return_date;
    *available_cars = (*available_cars)->next; // changing the head for the available_cars
    car * current = *rented_cars;
    if(current == NULL){// nothing in the list, simply add the rented car;
        *rented_cars = rented_car;
        rented_car->next = NULL;
        return;
    }
    if(current->next == NULL){// an item in the list: 
        if(rented_car->returndate < current->returndate){
            *rented_cars = rented_car;
            rented_car->next = current;
        }else{
            (*rented_cars)->next = rented_car;
            rented_car->next = NULL;
        }
        return;
    }
    car * before = *rented_cars;
    while(true){
        if(rented_car->returndate < current->returndate){
            if(before == *rented_cars){
                rented_car->next = *rented_cars;
                *rented_cars = rented_car;  // adding to the top;
                return;
            }
            before->next = rented_car;
            rented_car->next = current;
            return;
        }
        if(current->next == NULL){  //  reached the end of the list
            current->next = rented_car;
            rented_car->next = NULL;
            return; 
        }
        before = current;
        current = current->next;
    }
    return;
}

void addNewCar(car ** available_cars, char* plate_number, int miles){        // adds a new car to available
    car * newcar = makeNewCar(plate_number, miles);
    addToAvailableList(available_cars, newcar);
}

void calculateCost(int kms, float * total_cost){
    if(kms<100){
        *total_cost += (float) 40.0;
    }else{
        *total_cost += (float) (40.0 + (kms - 100.0) * 0.15);
    }
}


void returnedToAvailable(car ** rented_cars, car ** available_cars, int kilometers_used, char * plate_no, float * total_cost){ // adds a returned car to available
    car * current = *rented_cars;
    car * before = *rented_cars;    
    car * car_to_be_available; 
    while(true){
        if(current==NULL){
            printf("no car with such plate exists in rented cars list\n");
            return;
        }

        if(strcmp(current->plate_number, plate_no) == 0){
            if(before == current){
                car_to_be_available = current;
                *rented_cars = (*rented_cars)->next;
                break;
            }
            car_to_be_available = current;
            before->next = current->next;
            break;
        }
        before = current;
        current = current->next;
    }
    car_to_be_available->mileage += kilometers_used;
    calculateCost(kilometers_used, total_cost);
    addToAvailableList(available_cars, car_to_be_available); // adding that to the available cars
}

void transferToRepairs(car ** repairs, car ** rented_cars, char * plate_no, int kms_driven, float * total_cost){  //   WORK
    car * current = *rented_cars;
    car * before = *rented_cars;    
    car * car_to_be_repaired; 
    while(true){
        if(current==NULL){
            printf("no car with such plate exists in rented cars list\n");
            return;
        }
        if(strcmp(current->plate_number, plate_no) == 0){
            if(before == current){
                car_to_be_repaired = current;
                *rented_cars = (*rented_cars)->next;
                break;
            }
            car_to_be_repaired = current;
            before->next = current->next;
            break;
        }
        before = current;
        current = current->next;
    }
    car_to_be_repaired->mileage += kms_driven;
    calculateCost(kms_driven, total_cost);
    addToRepairList(repairs, car_to_be_repaired); // adding that car to repairs
}

void transferFromRepairs(car ** repairs, car ** availables, char * plate_no){
    car * current = *repairs;
    car * before = *repairs;
    car * car_to_be_available;
    while(true){
        if(current==NULL){
            printf("no car with such plate exists in repairs cars list\n");
            return;
        }
        if(strcmp(current->plate_number, plate_no) == 0){
            if(before == current){
                car_to_be_available = current;
                *repairs = (*repairs)->next;
                break;
            }
            car_to_be_available = current;
            before->next = current->next;
            break;
        }
        before = current;
        current = current->next;
    }
    
    addToAvailableList(availables, car_to_be_available);
}


void print_all_the_lists(car* rented, car* availables, car* repairs){
    printf("rented list : \n");
    printCars(rented);
    printf("availables list : \n");
    printCars(availables);
    printf("repairs list : \n");
    printCars(repairs);
    printf("\n");
}


int main() {

    car * available_for_rent = NULL;
    car * rented = NULL;
    car * in_repair = NULL;

    float total_cost = 0;

    int userInput;
    printf("Press 1 to add a new car to the available-for-rent list \n");
    printf("Press 2 to add a returned car to the available-for-rent list \n");
    printf("Press 3 to add a returned car to the repair list \n");
    printf("Press 4 to transfer a car from the repair list to the available-for-rent list \n");
    printf("Press 5 to rent the first car available \n");
    printf("Press 6 to print out all the lists \n");
    printf("Press 7 to quit \n");
    scanf("%d" , &userInput);
    while(true){
        if(userInput>7 || userInput <1){
            printf("invalid command, please enter one of the 7 commands (1 to 7) : \n");
            scanf("%d" , &userInput);
        }else{
            char * plate_number = (char *)malloc(100); 
            int kms_driven;
            int kms;
            int return_date; 

            switch(userInput){
                case 1:
                    printf("Adding a new car to the available cars list: \n");
                    printf("Please enter the car's plate number: \n");
                    scanf("%s", plate_number);
                    printf("Please enter the car's KMs: \n");
                    scanf("%d", &kms);
                    addNewCar(&available_for_rent, plate_number, kms);
                    break;
                case 2:
                    printf("Adding a returned car from the rented list to available cars list: \n");
                    printf("Please enter the car's plate number: \n");
                    scanf("%s", plate_number);
                    printf("Please enter the number of KMs driven with that car: \n");
                    scanf("%d", &kms_driven);
                    returnedToAvailable(&rented, &available_for_rent, kms_driven, plate_number, &total_cost);
                    break;
                case 3:
                    printf("Adding a returned car from the rented list to repairs list: \n");
                    printf("Please enter the car's plate number: \n");
                    scanf("%s", plate_number);
                    printf("Please enter the number of KMs driven with that car: \n");
                    scanf("%d", &kms_driven);
                    transferToRepairs(&in_repair, &rented, plate_number, kms_driven, &total_cost);
                    break;
                case 4: 
                    printf("Adding a returned car from the repairs list to the available cars list: \n");
                    printf("Please enter the car's plate number: \n");
                    scanf("%s", plate_number);
                    transferFromRepairs(&in_repair, &available_for_rent, plate_number);
                    break;
                case 5: 
                    printf("Renting the first available car: \n");
                    printf("Please enter the car's expected return date (format YYMMDD): \n");
                    scanf("%d", &return_date);
                    rentFromAvailable(&rented, &available_for_rent, return_date);
                    break;
                case 6: 
                    printf("Printing all the lists: \n");
                    print_all_the_lists(rented, available_for_rent, in_repair);
                    break;
                case 7:
                    printf("command 7 selected: Quitting... \n");
                    printf("total money made : %f \n", total_cost);
                    return 0;
                    break;
            }
            printf("please enter one of the 7 commands : \n");
            scanf("%d" , &userInput);
        }
    }
    return 0;
}
