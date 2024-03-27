#ifndef WATER_AUTOMATION_H
#define WATER_AUTOMATION_H

#include <iostream>

using namespace std;

struct FeedInfo{
    int freq;
    int waterAmt;
};

struct Plant{
    string name;
    int cubeNo;               
    int waterAmt;               //water per feeding (ml)
    int frequency;              //hours
    float idealMoisture;        //ideal moisture level at feeding
    int hoursSinceFed;
    bool nightFeeding;          //0 for day feeding, 1 for night feeding
    FeedInfo feedingList[];     //2D array of feeding and feedAmt schedule
};

Plant createPlant(Plant *plant, string name, int cubeNo, int waterAmt, int frequency, 
        float idealMoisture, int hoursSinceFed, bool nightFeeding, FeedInfo feedingList[]);


//maintenance flush 
//maintenance feed 


void deletePlant(Plant *plant, int cubeNo);
void movePlant(Plant *plant, int oldCubeNo, int newCubeNo);
void switchPlant(Plant *plant, int cubeNo1, int cubeNo2);
//void movePlant(Plant *plant, int newCubeNo);
void showPlants(Plant *plant);

float analyzeMoisture(Plant *plant, int cubeNo);
void changeMoisture(Plant *plant, int cubeNo, float newMoisture);


Plant createPlant(Plant *plant, string name, int cubeNo, int waterAmt, int frequency, 
        float idealMoisture, int hoursSinceFed, bool nightFeeding, FeedInfo feedingList[])
{
    for (int i = 0; i < num_plants; i++) {
        if (plant[i] == nullptr) {
            plant[i] = new Plant;
            plant[i].name = name;
            plant[i].cubeNo = cubeNo;
            plant[i].waterAmt = waterAmt;
            plant[i].frequency = frequency;
            plant[i].idealMoisture = idealMoisture;
            plant[i].hoursSinceFed = hoursSinceFed;
            plant[i].nightFeeding = nightFeeding;
            plant[i].feedingList = feedingList;
            break;
        }
    }
}


void showPlants(Plant *plant)
{
    for(int i = 0; i < num_plants; i++){
        cout << "Plant #" << i+1 << " : " << plant[i].name << endl;
        cout << "- Transported through Cube: " << plant[i].cubeNo << endl;
        cout << "- Hours since last fed: " << plant[i].hourseSinceFed << endl;
        cout << "- Plants ideal moisture level: " << plant[i].idealMoisture << endl;
    }
}

void movePlant(Plant *plant, int oldCubeNo, int newCubeNo)
{
    cout << "What plant cube number would you like to change? ";
    cin >> oldCubeNo;
    cout << "What is the new cube number you would like to place the plant?";
    cin >> newCubeNo;
    int check_if_worked = 0;
    for(int i = 0; i < num_plants; i++){
        if(plant[i].cubeNo == oldCubeNo){
            check_if_worked++;
            plant[i].cubeNo = newCubeNo;
        }
    }
    if(check_if_worked != 1){
        cout << "Please retry and enter a valid input" << endl;
    }
}
#endif