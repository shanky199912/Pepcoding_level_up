#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


void set1(){

    unordered_map<string,int> map;
    //put
    map["India"] = 1000;
    map["USA"] = 100000;
    map["China"] = 2000;
    map["Japan"] = 1500;
    map["pakistan"] = 300;

    //traverse ya print..
    cout<<"------------Traverse---------"<<endl;
    for(pair<string,int> ans : map){
        cout<<ans.first<<" "<<ans.second<<endl;
    }

    //get
    cout<<"------------Get-------------"<<endl;
    cout<<map["USA"]<<endl;
    cout<<map["India"]<<endl;
    //cout<<map["Usa"]<<endl;

    //find
    cout<<"----------find------------"<<endl;
    if(map.count("Usa")) //0 ya 1 return krti hai - 0 -false 1-true
        cout<<map["Usa"]<<endl;
    if(map.count("USA")) //0 ya 1 return krti hai - 0 -false 1-true
        cout<<map["USA"]<<endl;
    
    //erase
    cout<<"-------erase--------"<<endl;
    map.erase("USA");
    map.erase("pakistan");
    // map.erase("Usa"); 
    for(pair<string,int> ans : map){
        cout<<ans.first<<" "<<ans.second<<endl;
    }
}

int main(){
    set1();
    return 0;
}