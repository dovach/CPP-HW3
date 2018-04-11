// https://codereview.stackexchange.com/questions/113119/c-mock-social-networking-program
//https://stackoverflow.com/questions/7781188/static-variable-for-object-count-in-c-classes?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
//https://stackoverflow.com/questions/10376065/pushing-unique-data-into-vector
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include "Member.h"
using namespace std;
    
    int Member::counter = 0;
    int Member::newID = 0;
    
    Member::Member(): id(Member::newID++){
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
         if(other.Getid()==1 && Getid()==0){
             //cout<<"Avi to follow benny"<<endl;
             //cout<<"1 means Avi not in bennys follower list: "
             //<<(find(other.followers.begin(), other.followers.end(), other.Getid()) ==  other.followers.end())<<endl;
            //  if(other.followers.size()>0){             
            //     cout<<"benny's first 2 in follower list: "<<other.followers[0]<<" , "<<other.followers[1]<<endl;
            //  }
         }
        if (find(other.followers.begin(), other.followers.end(), other.Getid()) ==  other.followers.end()) {
        // other.Getid() not in followers, add it
        other.followers.push_back(Getid());
        following.push_back(other.Getid());
        }
     }
     void Member::unfollow(Member& other){
       //  cout<<other.Getid()<<endl;
       //  cout<<"0 means ID exists in list: "<<(find(other.followers.begin(), other.followers.end(), other.Getid()) ==  other.followers.end())<<endl;
       // if (find(other.followers.begin(), other.followers.end(), other.Getid()) !=  other.followers.end()) {
       //                 if(other.followers.size()>0){             
       //         cout<<"benny's first 2 in follower list: "<<other.followers[0]<<" , "<<other.followers[1]<<endl;
       //      }
        // other.Getid() in followers, remove it
        other.followers.erase(remove(other.followers.begin(), other.followers.end(), Getid()), other.followers.end());
        following.erase(remove(following.begin(), following.end(), other.Getid()),following.end());
        //}
     }




