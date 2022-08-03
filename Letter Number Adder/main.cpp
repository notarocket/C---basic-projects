#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;


int sumfunc(string input){
    vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int result = 0;
    for(char letter : input){
        result += (find(alphabet.begin(), alphabet.end(), letter) - alphabet.begin()) + 1;
    }
    return result;
}



int main(){

    string inpt;
    
    cout << "enter value: ";
    cin >> inpt;

    cout << sumfunc(inpt);

    

}
