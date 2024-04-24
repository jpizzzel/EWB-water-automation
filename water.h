/*
 *  Water Automation Header File
 *  Kinan Rabbat and Co.
 *  04/01/2024
 *
 *  Defines functions for water automation
 * 
 * Uses plantState.txt to store the current state of plants
 * Uses presets.txt to store presets
 * 
 */

#ifndef WATER
#define WATER

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class PlantList{
public:
    PlantList();
    PlantList(int cubeNum);
    ~PlantList();
    void commandLine();
    void createPreset();
    void deletePreset();

    void createPlant();
    void createPlantFromPreset();
    void deletePlant();

    void displayPlants();
    void displayPresets();

    void swapPlants();
    void movePlant();
    void changeNumCubes();

    void changeName();
    void changeFeedAmount();
    void changeFeedFrequency();
    // void changeFeedingList();
    // void changeMoisture();
    // void changeFeedList();
    
    struct Plant{
        int cubeNo;
        string name;
        float waterAmt;           //water per feeding (ml)
        float frequency;          //days
        float idealMoisture;    //ideal moisture level at feeding
        int hoursSinceFeed; 
        int feedingsTillAdult;
        float adultWaterAmt;
    };

private:

    void storePreset();
    void storeState();

    list<string> presetNames;
    vector<Plant> plants;
    int numCubes;
};

#endif