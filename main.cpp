
#include "water.h"
#include <iostream>

using namespace std;

int main(){
    PlantList plants = PlantList(5);
    // while(1)
    //     commandLine();
    // plants.storeState();
    // plants.createPreset();
    plants.createPlant();
    plants.displayPlants();

    return 0;
}