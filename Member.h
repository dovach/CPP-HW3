#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
class Member
{
 public:
    static int newID;
    static int counter;
    string name;
    vector <string> followers;
    vector <string> following;

    Member();
    int Getid();
    static int count();
    int numFollowing();
    int numFollowers();
    void follow(Member& other);
    void unfollow(Member& other);
 private:
    const int id;

 
};