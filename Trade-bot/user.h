#pragma once
#include<bits/stdc++.h>
using namespace std ; 

struct User{
    static unordered_map<string , int> ids ;
    string id ; 
    string name ; 
    string email ;
    User(string id , string name , string email): id(id) , name(name) , email(email) {
        if(ids.find(id) != ids.end()){
            throw invalid_argument("Id must be unique. User with this ID already exists") ;
        }
        ids[id] = 1 ;
    }
};

unordered_map<string, int> User::ids;
