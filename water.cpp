/*
 *  Water Automation Header File
 *  Kinan Rabbat and Co.
 *  04/01/2024
 *
 *  Implementation for water automation
 */

#include <sstream>
#include <stdexcept>
#include <string>
#include <iostream>
#include "water.h"

using namespace std;

/*
 * purpose:   initialize an empty plant list
 * arguments: none
 * returns:   none
 * effects:   none
 */
PlantList::PlantList(){
    plants = nullptr;
    numCubes = 0;
}

/*
 * purpose:   initialize an empty plant list
 * arguments: none
 * returns:   none
 * effects:   none
 */
PlantList::PlantList(int cubeNum){
    numCubes = cubeNum;
    plants = new Plant[cubeNum];
}

/*
 * purpose:   clean the plants list
 * arguments: none
 * returns:   none
 * effects:   none
 */
PlantList::~PlantList() {
    delete[] plants;
    plants = nullptr;
}

/*
 * purpose:   prints a list of all possible commands and asks a user for a 
 *            command
 * arguments: none
 * returns:   none
 * effects:   none
 */
void PlantList::commandLine(){
    cout << "Possible commands (enter the number corresponding to the task): 1 (Move the plant), 2 (Delete a plant), 3"; 
    cout << "(Show list of plants), 4 (Analyze Moisture Levels), 5 (Change Moisture Levels), 6 (Create plant), q (Exit commandline)" << endl;
}


/*
 * purpose:   asks user to input plant parameters and stores plant preset 
 *            in presets.txt
 * arguments: none
 * returns:   none
 * effects:   none
 */
void PlantList::createPreset() {
    Plant newPlant;
    cout << "Enter plant name: ";
    cin >> newPlant.name;
    //setting preset cube number to 0
    newPlant.cubeNo = 0;
    cout << "Enter water amount per feeding (ml): ";
    cin >> newPlant.waterAmt;
    cout << "Enter feeding frequency (days): ";
    cin >> newPlant.frequency;
    cout << "Enter ideal moisture level: ";
    cin >> newPlant.idealMoisture;
    newPlant.hoursSinceFeed = 0;
    cout << "Do you want to manually enter how much )"
    cout << "Enter feeding list";
    for (int i = 0; i < 7; ++i) {
        cin >> newPlant.feedingList[i];
    }
    
}

/*
 * purpose:   removes preset from preset.txt by deleting corresponding line in
              presets.txt
 * arguments: none
 * returns:   none
 * effects:   none
 */
void PlantList::deletePreset() {
    
}

/*
 * purpose:   asks user to input plant parameters, creates plant in plant list, 
 *            stores plant in plantState.txt 
 * arguments: none
 * returns:   none
 * effects:   none
 */
void PlantList::createPlant() {
    Plant newPlant;
    cout << "Enter plant name: ";
    cin >> newPlant.name;
    cout << "Enter cube number: ";
    cin >> newPlant.cubeNo;
    cout << "Enter water amount per feeding (ml): ";
    cin >> newPlant.waterAmt;
    cout << "Enter feeding frequency (hours): ";
    cin >> newPlant.frequency;
    cout << "Enter ideal moisture level: ";
    cin >> newPlant.idealMoisture;
    cout << "Enter hours since last feed: ";
    cin >> newPlant.hoursSinceFeed;
    cout << "Enter feeding list";
    for (int i = 0; i < 7; ++i) {
        cin >> newPlant.feedingList[i];
    }

    Plant* newPlants = new Plant[numCubes + 1];
    for (int i = 0; i < numCubes; ++i) {
        newPlants[i] = plants[i];
    }
    newPlants[numCubes] = newPlant;
    delete[] plants;
    plants = newPlants;
    numCubes++;
}

/*
 * purpose:   asks user to choose a preset, creates plant in plant list, 
 *            stores plant in plantState.txt 
 * arguments: none
 * returns:   none
 * effects:   none
 */
void PlantList::createPlantFromPreset() {

}

/*
 * purpose:   removes plant from plant list and removes its corresponding line
 *            from plantState.txt
 * arguments: none
 * returns:   none
 * effects:   none
 */
void PlantList::deletePlant() {
    int cubeNumber;
    cout << "Enter cube number of plant to delete: ";
    cin >> cubeNumber;

    
}

/*
 * purpose:   none
 * arguments: prints plantState.txt
 * returns:   none
 * effects:   none
 */
void PlantList::displayPlants() {
    //open file plantState.txt
    //read in file
    //print out file
}

/*
 * purpose:   none
 * arguments: swaps the cubes two plants are at
 * returns:   none
 * effects:   plant list, plantState.txt
 */
void PlantList::swapPlants() {
    int cube1, cube2;
    cout << "Enter cube number of first plant to swap: ";
    cin >> cube1;
    cout << "Enter cube number of second plant to swap: ";
    cin >> cube2;
    int track1, track2 = 0;
    for(int i = 0; i < num_plants; i++){
        if(plant[i].cubeNo == cube1){
            track1 = i;
        }
        if(plant[i].cubeNo == cube2){
            track2 = i;
        }
    }
    plant[track1] = cube2;
    plant[track2] = cube1;
}

/*
 * purpose:   none
 * arguments: moves plant to different cube
 * returns:   none
 * effects:   plant list, plantState.txt
 */
void PlantList::movePlant() {
    int cubeNumber, newCube;
    cout << "Enter cube number of plant to move: ";
    cin >> cubeNumber;
    cout << "Enter new cube number: ";
    cin >> newCube;
    int check_if_worked = 0;
    for(int i = 0; i < num_plants; i++){
        if(plant[i].cubeNo == newCube){
            cout << "ERROR: There is already a plant in the new cube space" << endl;
            break;
        }
        if(plant[i].cubeNo == cubeNumber){
            check_if_worked++;
            plant[i].cubeNo = newCube;
        }
    }
    if(check_if_worked != 1){
        cout << "Please retry and enter a valid input" << endl;
    }
    //Plant x moved to cube y successfully
    //Cube y not found 
    //Cube y already has a plant

}

/*
 * purpose:   none
 * arguments: changes number of cubes, copies plant data to new plant list
 * returns:   none
 * effects:   plant list
 */
void PlantList::changeNumCubes() {
    int newNumCubes;
    cout << "Enter new number of cubes: ";
    cin >> newNumCubes;

    //Number of cubes changed to x
    //Changing cube number deletes existing plants, please delete plants first 

    // if (newNumCubes < numCubes) {
    //     Plant* newPlants = new Plant[newNumCubes];
    //     for (int i = 0; i < newNumCubes; ++i) {
    //         newPlants[i] = plants[i];
    //     }
    //     delete[] plants;
    //     plants = newPlants;
    //     numCubes = newNumCubes;
    //     cout << "Number of cubes changed to " << newNumCubes << ".\n";
    // } else {
    //     cout << "Cannot increase number of cubes.\n";
    // }
}

/*
 * purpose:   changes name of a plant at a cube
 * arguments: none
 * returns:   none
 * effects:   plant list, plantState.txt
 */
void PlantList::changeName() {
    int cubeNumber;
    string newName;
    cout << "Enter cube number of plant to change name: ";
    cin >> cubeNumber;
    int checker = 0;
    for(int i = 0; i < num_plants; i++){
        if(plant[i].cubeNo == cubeNumber){
            checker++;
            cout << "The plant you have selected to change: " << plant[i].name << endl;
        }
    }
    if(check != 1){
        cout << "Please retry and enter a cubeNumber with a valid plant." << endl;
    }
    cout << "Enter the new name for this plant";
    cin >> newName;
    for(int i = 0; i < num_plants; i++){
        if(plant[i].cubeNo == cubeNumber){
            plant[i].name = newName;
        }
    }
}

/*
 * purpose:   changes the amount to feed a plant each week manually
 * arguments: none
 * returns:   none
 * effects:   plant list, plantState.txt
 */
void PlantList::changeFeedAmount() {
    int cubeNumber;
    float feedAmt;
    cout << "Enter cube number of plant to change feed amount: ";
    cin >> cubeNumber;
    for(int i = 0; i < num_plants; i++){
        if(plant[i].cubeNo == cubeNumber){
            checker++;
            cout << "The plant you have selected to change and it's feed amount: " << plant[i].name << " "
            cout << plant[i].waterAmt << " (ml)" << endl;

        }
    }
    if(check != 1){
        cout << "Please retry and enter a cubeNumber with a valid plant." << endl;
    }
    cout << "Enter the new value for feed amount for the selected plant (ml).";
    cin >> feedAmt;
    for(int i = 0; i < num_plants; i++){
        if(plant[i].cubeNo == cubeNumber){
            plant[i].waterAmt = feedAmt;
        }
    }
}

/*
 * purpose:   changes the frequency to feed a plant each week manually
 * arguments: none
 * returns:   none
 * effects:   plant list, plantState.txt
 */
void PlantList::changeFeedFrequency() {
    int cubeNumber;
    float freq;
    cout << "Enter cube number of plant to change feed amount: ";
    cin >> cubeNumber;
    for(int i = 0; i < num_plants; i++){
        if(plant[i].cubeNo == cubeNumber){
            checker++;
            cout << "The plant you have selected to change and it's frequency: " << plant[i].name << " "
            cout << plant[i].waterAmt << " (ml)" << endl;

        }
    }
    if(check != 1){
        cout << "Please retry and enter a cubeNumber with a valid plant." << endl;
    }
    cout << "Enter the new frequency in which the selected plant should be feed (days).";
    cin >> freq;
    for(int i = 0; i < num_plants; i++){
        if(plant[i].cubeNo == cubeNumber){
            plant[i].frequency = freq;
        }
    }
}

/*
 * purpose:   changes feeding list of a plant
 * arguments: none
 * returns:   none
 * effects:   plant list, plantState.txt
 */
void PlantList::changeFeedingList() {
    int cubeNumber;
    cout << "Enter cube number of plant to change feeding list: ";
    cin >> cubeNumber;

}

/*
 * purpose:   changes ideal moisture level of a plant
 * arguments: none
 * returns:   none
 * effects:   plant list, plantState.txt
 */
void PlantList::changeMoisture() {
    int cubeNumber;
    cout << "Enter cube number of plant to change ideal moisture level: ";
    cin >> cubeNumber;

}

/*
 * purpose:   stores a plant as a preset to a line in presets.txt
 * arguments: none
 * returns:   none
 * effects:   none
 */
void PlantList::storePreset(){

}

/*
 * purpose:   stores current state of plant list in plantState.txt
 * arguments: none
 * returns:   none
 * effects:   none
 */
void PlantList::storeState(){

}
