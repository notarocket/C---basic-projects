#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct storedValue{
    int num;
    int y_pos;
    int x_pos;
};

int main(){
    string fileText;

    vector<vector<int>> matrix;

    ifstream ReadFile("matrix.txt");
    int i = 0;
    while (getline(ReadFile, fileText)) {
        matrix.push_back({});
        string item;

        stringstream s(fileText);
        
        while (getline(s, item, ' ')){
            int numItem = stoi( item );
            matrix[i].push_back(numItem);
        }
        i++;
        
    }

    for(int i = 0; i < matrix[0].size()-1; i++){

    }

    
    vector<vector<storedValue>> orderedmatrix;
    
    //ROWS -- smallest for each row
    for(i = 0; i<matrix.size(); i++){
        orderedmatrix.push_back({});
        int n = matrix.size();
        while(n > 0){
            int lowestval = 2147483646;
            int lowestIndex = 0;
            for(int x = 0; x < matrix[i].size(); x++){
                if(lowestval > matrix[i][x]){
                    lowestval = matrix[i][x];
                    lowestIndex = x;
                }
            }           
            orderedmatrix[i].push_back({lowestval, i, lowestIndex});
            matrix[i][lowestIndex] = 2147483647;
            n--;
        }
    }
    vector<int> bestSequence;
    vector<int> usedRows;
    vector<int> usedYRows;
    vector<int> permUsedRows;
    vector<int> finalSequence;
    for(int y = 0; y<orderedmatrix.size(); y++){
        for(i = 0; i<orderedmatrix.size(); i++){
            bool found = false;
            int b = 0;
            while (!found) {      
                if(usedRows.size() > 0){
                    if(find(usedRows.begin(), usedRows.end(), orderedmatrix[i][b].x_pos)==usedRows.end() && find(usedYRows.begin(), usedYRows.end(), orderedmatrix[i][b].y_pos)==usedYRows.end()){
                        found = true;
                        bestSequence.push_back(orderedmatrix[i][b].num);
                        usedRows.push_back(orderedmatrix[i][b].x_pos);
                    }else{
                        b++;
                    
                    }
                    if(b == 20){
                        found = true;
                        bestSequence.push_back(2147483647);
                    }
                }else{
                    found = true;
                    bestSequence.push_back(orderedmatrix[i][b].num);
                    usedRows.push_back(orderedmatrix[i][b].x_pos);
                }
            }

        }
        
        auto min = min_element(bestSequence.begin(), bestSequence.end());
        int minele = distance(begin(bestSequence), min);
        permUsedRows.push_back(usedRows[minele]);
        finalSequence.push_back(bestSequence[minele]);
        usedYRows.push_back(minele);
        usedRows.clear();
        bestSequence.clear();
        usedRows = permUsedRows;
        
    }
    
    int sum = 0;
    for (int num : finalSequence){
        sum += num;
    }
    cout << sum;
}


int add_vals(vector<vector<string>> matrix, vector<int> currentConfig){
    int value = 0;

    return value;
}