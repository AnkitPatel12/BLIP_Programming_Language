#include <string>
#include "Parse.h"
#include <iostream>
#include <vector>
#include "Implement.h"
#include <unordered_map>
using namespace std;

unordered_map <string, int> mp;
vector<string>arr;

// call on from main program to run
void run(){
    while(next_token_type != END){
        // need to first capture text
        string a = next_token();
        if(a == "//"){
            skip_line();
        }
        else if(a ==  "text"){ // if we need to print text
            read_next_token();
            string b = next_token();
            if(b == "//"){
                skip_line();
            }
            else{
                cout << b;
            }
        }
        else if(a == "output"){
            add();
            cout << evaluate(arr);
            arr.clear();
        }
        else if(a == "set"){
            read_next_token();
            string hold = next_token(); // gets the value of what we will set to
            add();// need to add the value being set to the vector
            if(mp.find(hold) == mp.end()){ // variarble was never intianzlied
                cout << "variable " << hold << " not declared" <<endl;
            }
            // need to add to map as said in program description
            mp[hold] = evaluate(arr);
            arr.clear();
        }
        else if(a == "var"){
            read_next_token();
            string name = next_token();
            add();
            if(mp.find(name) != mp.end()){
                cout << "variable " << name << " incorrectly re-initialized" << endl;
            }
            mp[name] = evaluate(arr);
            arr.clear();
        }
        read_next_token();
    }
}

bool check(string a){
    if(a == "+" || a == "-" || a == "*" || a == "/" || a == "%" || a == "<" || a == ">" || a == "=="|| a ==  "!=" || a == "&&"|| a == "<=" || a == ">=" || a == "||" || a== "!" || a == "~"){
        return true;
    }
     else return false;
}

void add(){
    // need to check if the value is not another task or fuction to be excuted
    while(string(peek_next_token()) != "var" && string(peek_next_token()) != "output" && next_token_type != END && string(peek_next_token()) != "text"  && string(peek_next_token()) != "set"){
        read_next_token();
        string a = next_token();
        // need to check if it a comment
        if(a == "//"){
            skip_line();
        }
        else{
            arr.push_back(a);
        }
        peek_next_token();
    }
}

int evaluate(vector<string> &track){
    string hold = track[0];
    track.erase(track.begin());
    // if the variable is by name;
    if(mp.find(hold) != mp.end()){
        return mp[hold];
    }
    else if(hold == "~"){
        return evaluate(track) *-1;
    }
    else if(hold == "!"){
        if(evaluate(track) != 0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if(check(hold)){ // need to check if its a operator
        int a = evaluate(track);
        int b = evaluate(track);
        if(hold == "*"){
            return a*b;
        }
        if(hold == "-"){
            return a-b;
        }
        if(hold == "+"){
            return a+b;
        }
        if(hold == "/"){
            return (a / b);
        }
        if(hold == ">"){
            return a > b;
        }
        if(hold == "<"){
            return a < b;
        }
        if(hold == "=="){
            return a == b;
        }
        if(hold == "%"){
            return a % b;
        }
        if(hold == "&&"){
            return a && b;
        }
        if(hold == "!="){
            return a != b;
        }
        if(hold == "||"){
            return a || b;
        }
        if(hold == ">="){
            return a >= b;
        }
        if(hold == "<="){
            return a <= b;
        }
    }
    if(!check(hold)){
        int c = stoi(hold);
        return c;
    }
}



