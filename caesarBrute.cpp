#include <iostream>
#include <string>
#include <locale>
#include <algorithm>
#include <cctype>

using namespace std;

bool inCharArray(char c, char arr[]){
    bool found = false;
    for(int i = 0; i < arr.length(); i++){
        if(c == arr[i]){
            found = true;
        }
    }
    return found;
}

int atPosition(char c, char arr[]){
    for(int i = 0; i< arr.length(); i++){
        if(c == arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    //the user will input the message to be ran through all possible keys
    char message[100000];
    cout << "Please paste the message to be deciphered by brute force: ";
    cin.getline(message, 100000);
    cout << message << endl;
    //the following will convert the message to all lowercase for decryption
    int i = 0;
    char x;
    char lower[100000];
    while(message[i]){
        x = message[i];
        x = tolower(x);
        lower[i] = x;
        i++;
    }
    //an array will make using the key easy
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    int key;
    for(key = 0; key < alpha.length(); key++){
        //for outputting each character solved until completion
        output = "";  
        for(int i = 0; i < lower.length; i++){
            //if the current letter in lower is in alpha, apply key shift
            if(found(lower[i], alpha)){
                int pos = atPosition(lower[i], alpha);
                if(pos + key < 26){
                    output
            }
        }
    }
   
   
    
    return 0;
}
