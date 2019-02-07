#include <iostream>
#include <string>
#include <locale>
#include <algorithm>
#include <cctype>

using namespace std;

bool contains(char c, string s){
    bool found = false;
    for(int i = 0; i < s.length(); i++){
        if(c == s[i]){
            found = true;
        }
    }
    return found;
}

int atPosition(char c, string s){
    for(int i = 0; i< s.length(); i++){
        if(c == s[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    //the user will input the message to be ran through all possible keys
    string message;
    cout << "Please paste the message to be deciphered by brute force: ";
    getline(cin, message);
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    transform(message.begin(), message.end(), message.begin(), ::tolower);
    int key;
    for(key = 0; key < alpha.length(); key++){
        //for outputting each character solved until completion
        cout << "Key " << (26 - key) << ":  ";
        //for the current key shift, parse the entire message
        for(int i = 0; i < message.length(); i++){
            //if the current letter is in alpha, apply key shift
            if(contains(message[i], alpha)){
                int pos = atPosition(message[i], alpha);
                if(pos + key <= 25){
                    cout << (alpha[pos + key]);
                }
                else{ 
                    cout << (alpha[pos - (26 - key)]); 
                }
            }
            else{
                cout << message[i];
            }
        }
        cout << endl;
        cout << endl;
    }
    return 0;
}
