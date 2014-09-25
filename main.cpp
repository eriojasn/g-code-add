//
//  main.cpp
//  GCodeTransformer
//
//  Created by Eduardo Riojas on 6/22/14.
//  Copyright (c) 2014 Eduardo Riojas. All rights reserved.
//

#include <fstream>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

bool isWhitespace(char c)
{
    if (!isdigit(c) && c != '.' && c != '-')
        return true;
    else
        return false;
}

bool isCoordinateStart(char c)
{
    if (c == 'X' || c == 'Y' || c == 'Z' || c == 'I' || c == 'J' || c == 'K')
        return true;
    else
        return false;
}

int main(int argc, const char * argv[])
{
    ifstream myFile;
    myFile.open("gatorade1.txt");
    char x;
    
    ofstream newFile;
    newFile.open("gatorade.txt");

    bool coordinate = false;
    
    string numberString = "";
    
    double number = 0;
    
    while (myFile >> x) {
        if (isWhitespace(x)) {
            if (coordinate) {
                number = atof(numberString.c_str());
                number += 2;
                newFile << number;
                numberString = "";

                if (number - floor(number) == 0) {
                    newFile << ".";
                }
            }
            newFile << " ";
            coordinate = false;
        }
        
        if (x == 'N') {
            newFile << "\n";
        }
        
        if (!coordinate) {
            newFile << x;
        }
        
        if (coordinate) {
            numberString += x;
        }
        
        if (isCoordinateStart(x)) {
            coordinate = true;
        }
    }
    
    myFile.close();
    
    return 0;
}

