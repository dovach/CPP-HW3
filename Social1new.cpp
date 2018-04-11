// https://codereview.stackexchange.com/questions/113119/c-mock-social-networking-program
//https://stackoverflow.com/questions/7781188/static-variable-for-object-count-in-c-classes?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
//https://stackoverflow.com/questions/10376065/pushing-unique-data-into-vector
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include "Member.h"
using namespace std;
    
    int Member::counter = 0;
    
    Member::Member(): id(newID++){
        Member::counter++;
    }
    int Member::Getid()
    {
        return id;
    }
    int Member::count(){
        return Member::counter;
    }
    int Member::numFollowing(){
        return following.size();
    }
    int Member::numFollowers(){
        return followers.size();
    }
     void Member::follow(Member& other){
        if (find(other.followers.begin(), other.followers.end(), other.name) ==  other.followers.end()) {
        // other.name not in followers, add it
        other.followers.push_back(name);
        following.push_back(other.name);
        }
     }
     void Member::unfollow(Member& other){
        if (!(find(other.followers.begin(), other.followers.end(), other.name) ==  other.followers.end())) {
        // other.name in followers, remove it
        other.followers.erase(remove(other.followers.begin(), other.followers.end(), name), other.followers.end());
        following.erase(remove(following.begin(), following.end(), other.name),following.end());
        }
     }




