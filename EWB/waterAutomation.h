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
        float idealMoisture, int hoursSinceFed, bool nightFeeding, FeedInfo feedingList[], int num_plants);


//maintenance flush 
//maintenance feed 

void query(Plant *plant, int num_plants);
void deletePlant(Plant *plant, int cubeNo);
void movePlant(Plant *plant, int oldCubeNo, int newCubeNo, int num_plants);
void switchPlant(Plant *plant, int cubeNo1, int cubeNo2);
//void movePlant(Plant *plant, int newCubeNo);
void showPlants(Plant *plant);

float analyzeMoisture(Plant *plant, int cubeNo);
void changeMoisture(Plant *plant, int cubeNo, float newMoisture);


Plant createPlant(Plant *plant, string name, int cubeNo, int waterAmt, int frequency, 
        float idealMoisture, int hoursSinceFed, bool nightFeeding, FeedInfo feedingList[], int num_plants)
{
    for (int i = 0; i < num_plants; i++) {
        if (plant == nullptr) {
            plant[i].name = name;
            plant[i].cubeNo = cubeNo;
            plant[i].waterAmt = waterAmt;
            plant[i].frequency = frequency;
            plant[i].idealMoisture = idealMoisture;
            plant[i].hoursSinceFed = hoursSinceFed;
            plant[i].nightFeeding = nightFeeding;
            //plant[i].feedingList = feedingList;
            break;
        }
    }
}


void showPlants(Plant *plant, int num_plants)
{
    for(int i = 0; i < num_plants; i++){
        cout << "Plant #" << i+1 << " : " << plant[i].name << endl;
        cout << "- Transported through Cube: " << plant[i].cubeNo << endl;
        cout << "- Hours since last fed: " << plant[i].hoursSinceFed << endl;
        cout << "- Plants ideal moisture level: " << plant[i].idealMoisture << endl;
    }
}

void movePlant(Plant *plant, int oldCubeNo, int newCubeNo, int num_plants)
{
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

void deletePlant(Plant *plant, int cubeNo)
{

}

void query(Plant *plant, int num_plants)
{
    string current_query;
    cout << "Possible queries: 1 (Move the plant), 2 (Delete a plant), 3"; 
    cout << "(Show list of plants), 4 (Analyze Moisture Levels), 5 (Change Moisture Levels), 6 (Create plant), q (Exit query)" << endl;
    cout << "Enter a query: ";
    cin >> current_query;
    while(current_query != "q"){
        if(current_query == "1"){
            int oldCubeNo, newCubeNo;
            cout << "What plant cube number would you like to change? ";
            cin >> oldCubeNo;
            cout << "What is the new cube number you would like to place the plant?";
            cin >> newCubeNo;
            movePlant(plant, oldCubeNo, newCubeNo, num_plants);
        }else if(current_query == "2"){
            
        }else if(current_query == "3"){
            showPlants(plant, num_plants);
        }else if(current_query == "4"){
            
        }else if(current_query == "5"){
            
        }else if(current_query == "6"){
            string name; 
            int cubeNo, waterAmt, frequency;
            int hoursSinceFed = 0;
            float idealMoisture;
            bool nightFeeding;
            
            cout << "What would you like to name this plant? ";
            cin >> name;
            cout << "What cube number is this plant in? ";
            cin >> cubeNo;
            cout << "How much water should this plant recieve per feeding (ml)? ";
            cin >> waterAmt;
            cout << "How often should this plant be fed (hours)? ";
            cin >> frequency;
            cout << "What is this plants ideal moisture level? ";
            cin >> idealMoisture;
            cout << "Will this plant require night feeding or day feeding? (1 for night, 0 for day) ";
            cin >> nightFeeding;
            FeedInfo **feedingList = new FeedInfo*[frequency];
            for (int i = 0; i < frequency; i++) {
                feedingList[i] = new FeedInfo[waterAmt];
            }
            createPlant(plant, name, cubeNo, waterAmt, frequency, idealMoisture, hoursSinceFed, nightFeeding, feedingList[], num_plants);
        }else{
            cout << current_query << " not recognized" << endl;
        }
        cout << endl << "Enter a query: ";
        cin >> current_query;
    }
}
#endif