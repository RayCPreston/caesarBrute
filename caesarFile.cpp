#include <iostream>
#include <string>
#include <locale>
#include <algorithm>
#include <cctype>
#include <fstream>

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
    ifstream infile ("cipher.txt");
    string message;
    //cout << "Please paste the message to be deciphered by brute force: ";
    getline(infile, message);
    infile.close();
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    transform(message.begin(), message.end(), message.begin(), ::tolower);
    int key;
    ofstream outfile ("output.txt");
    for(key = 0; key < alpha.length(); key++){
        //for outputting each character solved until completion
        outfile << "Key " << (26 - key) << ":  ";
        //for the current key shift, parse the entire message
        for(int i = 0; i < message.length(); i++){
            //if the current letter is in alpha, apply key shift
            if(contains(message[i], alpha)){
                int pos = atPosition(message[i], alpha);
                if(pos + key <= 25){
                    outfile << (alpha[pos + key]);
                }
                else{ 
                    outfile << (alpha[pos - (26 - key)]); 
                }
            }
            else{
                outfile << message[i];
            }
        }
        outfile << endl;
        outfile << endl;
    }
    outfile.close();
    return 0;
}
