//Demo water automation system 1.0 

#include <waterAutomation.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

Plant createPlant(string name, int cubeNo, int waterAmt, int frequency, float idealMoisture, int hoursSinceFed, bool nightFeeding, FeedInfo feedingList[]);
void deletePlant();
void movePlant(Plant &plant, int newCubeNo);

int main(){

    return 0;
}

void createPlant(Plant *plant){
    string name
    int cubeNo, waterAmt, frequency, hoursSinceFed;
    float idealMoisture;
    string nightFeeding;
    FeedInfo feedingList[];
    
    Plant output;

    cout << "To create a plant, please enter the following data points: " << endl;
    cout << "Name (word): ";
    cin >> output.name;

    cout << "Cube number (number): " << endl;
    cin >> output.cubeNo;

    cout << "What is the ideal moisture level? (number):" << endl;
    cin >> output.idealMoisture;

    while (nightFeeding != "yes" && nightFeeding != "no" && nightFeeding != "y" && nightFeeding != "n") {
        cout << "Should it be fed at night? Please write 'y' or 'n' for yes or no." << endl;
        cin >> nightFeeding;
        if(nightFeeding != "yes" && nightFeeding != "no" && nightFeeding != "y" && nightFeeding != "n"){
            cout << "You didn't enter valid input." << endl;
        }
    }
    
    if(nightFeeding == "yes" || nightFeeding == "y"){
        output.nightFeeding = 1;
    } else {
        output.nightFeeding = 0;
    }
    
    output.idealMoisture = idealMoisture;
    output.hoursSinceFed = hoursSinceFed;
    output.nightFeeding = nightFeeding;
    output.feedingList = feedingList;

    output.waterAmt = feedingList[0].waterAmt;
    output.frequency = feedingList[0].freq;
}

void deletePlant(){
    
} 

void movePlant(Plant &plant, int newCubeNo){
    plant.cubeNo = newCubeNo;
}
