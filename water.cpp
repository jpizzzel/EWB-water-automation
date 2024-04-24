/*
 *  Water Automation Header File
 *  Kinan Rabbat and Co.
 *  04/01/2024
 *
 *  Implementation for water automation
 */

;
#include <stdexcept>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <list>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "water.h"


using namespace std;

const PlantList::Plant emptyPlant = {-1, "", -1, -1, -1, -1, -1, -1};

/*
 * purpose:   initialize an empty plant list, initialize presets list
 * arguments: none
 * returns:   none
 * effects:   none
 */
PlantList::PlantList(){
    //open presets.txt
    string filename = "presets.txt";
    ifstream infile;
    string line;
    infile.open(filename);
     if (!infile.is_open()) {
        std::cerr << "Error opening presets.txt." << std::endl;
    }

    //read each line from the file, add 
    while (std::getline(infile, line)) {
        istringstream iss(line);
        string word;
        
        //read the second word (plant name)
        if (iss >> word) {
            if (iss >> word) {
                //add plant preset name to the preset name list
                presetNames.push_back(word);
            }
        }
    }

    //close presets.txt
    infile.close();
    
    numCubes = 0;
}

/*
 * purpose:   initialize an empty plant list, initialize presets list
 * arguments: integer specifing the number of cubes which is 
 * returns:   none
 * effects:   fills plant vector with empty plants
 */
PlantList::PlantList(int cubeNum){
    //open presets.txt
    string filename = "presets.txt";
    ifstream infile;
    string line;
    infile.open(filename);
     if (!infile.is_open()) {
        cerr << "Error opening presets.txt." << endl;
        exit(EXIT_FAILURE);
    }

    //read each line from the file, add 
    while (std::getline(infile, line)) {
        istringstream iss(line);
        string word;
        
        //read the second word (plant name)
        if (iss >> word) {
            if (iss >> word) {
                //add plant preset name to the preset name list
                presetNames.push_back(word);
            }
        }
    }

    //close presets.txt
    infile.close();

    numCubes = cubeNum;
    // plants = new Plant[cubeNum];

    for(int i = 0; i < cubeNum; i++){
        plants.push_back(emptyPlant);
    }
    
}

/*
 * purpose:   clean the plants list
 * arguments: none
 * returns:   none
 * effects:   none
 */
PlantList::~PlantList() {
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
 * tested:    yes
 */
void PlantList::createPreset() {
    string filename = "presets.txt";
    Plant newPlant;
    //setting preset cube number to 0
    newPlant.cubeNo = 0;
    cout << "Enter plant name: " << endl;
    
    //loop until a unique name is chosen
    bool uniqueName = 0;
    while(uniqueName == 0){
        cin >> newPlant.name;
        uniqueName = 1;
        for(const string& plantName : presetNames){
            if(newPlant.name == plantName){
                uniqueName = 0;
                cout << "Plant name already used. Please choose a different name: " << endl;
            }
        }
    }
    cout << "Enter water amount per feeding (ml): " << endl;
    cin >> newPlant.waterAmt;
    cout << "Enter feeding frequency (days): " << endl;
    cin >> newPlant.frequency;
    cout << "Enter ideal moisture level: " << endl;
    cin >> newPlant.idealMoisture;
    newPlant.hoursSinceFeed = 0;
    cout << "How many feedings until the plant is an adult? " << endl;
    cin >> newPlant.feedingsTillAdult;
    cout << "How much should it be fed as an adult? " << endl;
    cin >> newPlant.adultWaterAmt;

    //open preset file
    ofstream outfile(filename);  

    if (outfile.is_open()) {

        //write plant preset to preset file
        outfile << newPlant.cubeNo << setw(10) << newPlant.name << setw(10)
                << newPlant.waterAmt << setw(10) << newPlant.frequency << setw(10) << newPlant.idealMoisture
                << setw(10) << newPlant.feedingsTillAdult << setw(10) << newPlant.adultWaterAmt << endl;

        //close preset file
        outfile.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
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
    string filename = "presets.txt";
    ifstream infile(filename);

    vector<string> lines;
    string line;
    string input;

    cout << "Would you like to delete a preset? (y/n) ";
    cin >> input;

    bool deleteIntention = false;

    if(input == "y") {;
        cout << "\nWhat is the plant name of the preset: ('exit' to quit)";
        cin >> input;
        if(input != "exit") {
            deleteIntention = true;
        }
    }

    if(deleteIntention) {
        while(getline(infile, line)) {
             
        }
    }

    // if(input == "y"){
    //     cout << endl << "What is the plant name of the preset: ('exit' to quit)";
    //     cin >> input;
    //     //checks if user wants to exit
    //     if(input != "exit"){

    //         bool presetFound = 0;

    //         //read each line and store in vector, skipping the line to delete
    //         int currentLineNum = 1;
    //         while (getline(infile, line)) {
    //             string word;
    //             istringstream iss(line);

    //             //read the second word (plant name)
    //             if (iss >> word) {
    //                 if (iss >> word) {
    //                     if(input == word){
    //                         presetFound = 1;
        
    //                     } else {
    //                         //push line to vector if it isn't the preset we're looking for
    //                         lines.push_back(line);
    //                     }
    //                 }
    //             }

    //             currentLineNum++;
    //         }
    //         infile.close();

    //         if(presetFound == 0){
    //             cout << "Preset not found. " << endl;
    //         } else {
    //             //delete from presetNames if preset is found
    //             for (auto it = presetNames.begin(); it != presetNames.end(); it++) {
    //                 if (*it == newName) {
    //                     //erase preset name from presetNames list if match
    //                     it = presetNames.erase(it); 
    //                 } 
    //             }
    //         }


    //         //rewrite remaining lines to the file
    //         ofstream outfile(filename);
    //         for (const string& remainingLine : lines) {
    //             outfile << remainingLine << endl;
    //         }
            
    //         output.close();
    //     }
    // }
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
    cout << "Enter cube number: " << endl;
    cin >> newPlant.cubeNo;
    if(plants.at(newPlant.cubeNo).name != ""){
        cout << "That cube number is taken, retry and pick a different cube or delete this cube first" << endl;
       
    } else {

        cin >> newPlant.cubeNo;
        cout << "Enter plant name: " << endl;
        cin >> newPlant.name;
        cout << "Enter water amount per feeding (ml): " << endl;
        cin >> newPlant.waterAmt;
        cout << "Enter feeding frequency (days): " << endl;
        cin >> newPlant.frequency;
        cout << "Enter ideal moisture level: " << endl;
        cin >> newPlant.idealMoisture;
        newPlant.hoursSinceFeed = 0;
        cout << "How many feedings until the plant is an adult? " << endl;
        cin >> newPlant.feedingsTillAdult;
        cout << "How much should it be fed as an adult? " << endl;
        cin >> newPlant.adultWaterAmt;


        plants.at(newPlant.cubeNo) = newPlant;
        storeState();
    }
}

/*
 * purpose:   asks user to choose a preset, creates plant in plant list, 
 *            stores plant in plantState.txt 
 * arguments: none
 * returns:   none
 * effects:   none
 */
void PlantList::createPlantFromPreset() {
    string filename = "presets.txt";
    ifstream infile(filename);

    vector<std::string> lines;
    string line;
    string input;
    Plant newPlant;

    cout << "What preset would you like to use: ";
    cin >> input;
   
    bool presetFound = 0;

    //read each line and search for preset
    while (std::getline(infile, line)) {
        string word;
        istringstream iss(line);
        iss >> word;
        iss >> word;
        //read the second word (plant name)
        if(input == word){
            //found preset, make new plant
            presetFound = 1;

            Plant newPlant;
                    
            cin >> newPlant.cubeNo;
            if(plants.at(newPlant.cubeNo).name != ""){
                cout << "That cube number is taken, retry and pick a different cube or delete this cube first" << endl;
            } else {
                iss >> word;
                newPlant.name = word;
                iss >> word;
                newPlant.waterAmt = stof(word);
                iss >> word;
                newPlant.frequency = stof(word);
                iss >> word;
                newPlant.idealMoisture = stof(word);
                newPlant.hoursSinceFeed = 0;
                iss >> word;
                newPlant.feedingsTillAdult = stoi(word);
                iss >> word;
                newPlant.adultWaterAmt = stof(word);

                plants.at(newPlant.cubeNo) = newPlant;
                storeState();
            }

        }
    }
    
    infile.close();

    if(presetFound == 0){
        cout << "Preset not found. " << endl;
    }
}

/*
 * purpose:   removes plant from plant list and removes its corresponding line
 *            from plantState.txt
 * arguments: none
 * returns:   none
 * effects:   none
 */
void PlantList::deletePlant() {
    unsigned long cubeNumber;
    cout << "Enter cube number of plant to delete: ";
    cin >> cubeNumber;
    
    bool correctIndex = 1;

    if(cubeNumber < 0 or cubeNumber >= plants.size()) {
        correctIndex = 0;
    }

    if(correctIndex){
        if(plants.at(cubeNumber).name == ""){
            cout << "That cube number doesn't have a plant." << endl;
        } else { 
            plants.at(cubeNumber) = emptyPlant;
            storeState();
        }
    }
}

/*
 * purpose:   none
 * arguments: prints plantState.txt
 * returns:   none
 * effects:   none
 */
void PlantList::displayPlants() {
    //open presets.txt
    string filename = "plantState.txt";
    ifstream infile;
    infile.open(filename);
    string line;

    //print each line from the file
    while (getline(infile, line)) {
        // istringstream iss(line);
        cout << line << endl;
    }

    //close presets.txt
    infile.close();
}

/*
 * purpose:   none
 * arguments: prints presets.txt
 * returns:   none
 * effects:   none
 */
void PlantList::displayPresets() {
    //open presets.txt
    string filename = "presets.txt";
    ifstream infile;
    infile.open(filename);
    
    string line;

    //print each line from the file
    while (std::getline(infile, line)) {
        istringstream iss(line);
        cout << line << endl;
    }

    //close presets.txt
    infile.close();
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
    if(cube1 >= numCubes){
        cout << "That is not a valid cube number. " << endl;
    } else {
        cout << "Enter cube number of second plant to swap: ";
        cin >> cube2;
        if(cube2 >= numCubes){
            cout << "That is not a valid cube number. " << endl;
        } else {
            if(plants.at(cube1).name != "" and plants.at(cube2).name != ""){
                Plant currPlant = plants.at(cube1);
                plants.at(cube1) = plants.at(cube2); 
                plants.at(cube2) = currPlant;
            } else {
                cout << "One or both of those cubes don't have a plant. " << endl;
            }
        }
    }
}

/*
 * purpose:   none
 * arguments: moves plant to different cube
 * returns:   none
 * effects:   plant list, plantState.txt
 */
void PlantList::movePlant() {
    int oldCube, newCube;
    cout << "Enter cube number of plant to move: ";
    cin >> oldCube;
    cout << "Enter new cube number for plant : ";
    cin >> newCube;
    if(plants.at(oldCube).name == ""){
        cout << "That cube doesn't have a plant." << endl;
    } else {
        cout << "Enter new cube number: ";
        cin >> newCube;
        if(plants.at(newCube).name == ""){
            plants.at(newCube) = plants.at(oldCube);
            plants.at(oldCube) = emptyPlant;
            cout << "Plant moved successfully" << endl;
        } else {
            cout << "That cube is full. " << endl;
        }
    }
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

    if(cubeNumber >= numCubes){
        cout << "That is not a valid cube number. " << endl;
    } else { 
        cout << "What would you like to change the plant name to: " << endl;
        cin >> newName;
        plants.at(cubeNumber).name = newName;
        storeState();
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
    float newWaterAmt;
    cout << "Enter cube number of plant to change water feed amount: ";
    cin >> cubeNumber;
    if(cubeNumber >= numCubes){
        cout << "That is not a valid cube number. " << endl;
    } else { 
        cout << "What would you like to change the water feed amount to: " << endl;
        cin >> newWaterAmt;
        plants.at(cubeNumber).waterAmt = newWaterAmt;
        storeState();
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
    float newFrequency;
    cout << "Enter cube number of plant to change feed frequency: ";
    cin >> cubeNumber;
    if(cubeNumber >= numCubes){
        cout << "That is not a valid cube number. " << endl;
    } else { 
        cout << "What would you like to change the feed frequency to: " << endl;
        cin >> newFrequency;
        plants.at(cubeNumber).frequency = newFrequency;
        storeState();
    }
}

/*
 * purpose:   changes feeding list of a plant
 * arguments: none
 * returns:   none
 * effects:   plant list, plantState.txt
 */
// void PlantList::changeFeedingList() {
//     int cubeNumber;
//     cout << "Enter cube number of plant to change feeding list: ";
//     cin >> cubeNumber;

// }

// /*
//  * purpose:   changes ideal moisture level of a plant
//  * arguments: none
//  * returns:   none
//  * effects:   plant list, plantState.txt
//  */
// void PlantList::changeMoisture() {
//     int cubeNumber;
//     cout << "Enter cube number of plant to change ideal moisture level: ";
//     cin >> cubeNumber;

// }

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
    string filename = "plantState.txt";

    //delete current contents
    ofstream deleteContents(filename, ofstream::trunc);
    deleteContents.close();
    
    //open file to add current state
    ofstream outfile(filename);
    outfile.open(filename);
    if (!outfile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    //create titles for column
    outfile << "Cube Number" << setw(10) << "Plant Name" << setw(10) <<
    "Water Amt" << setw(10) << "Frequency" << setw(10) << "Ideal Moisture Level"
    << setw(10) << "Feedings Till Adult" << setw(10) << "Adult Water Amt" << endl;

    // for (const auto& plant : plants) {
    //     outfile <<  setw(10) << plant.cubeNo << setw(10) << plant.name << setw(10)
    //             << plant.waterAmt << setw(10) << plant.frequency << setw(10) << plant.idealMoisture
    //             << setw(10) << plant.feedingsTillAdult << setw(10) << plant.eventualWaterAmt << endl;
    // }


    outfile <<  "FOOD" << endl;
    for (const auto& plant : plants) {
        outfile <<  "FOOD" << endl;
    }
    outfile.close();
}