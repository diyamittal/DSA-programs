#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<string, int> m;

    pair<string, int> p=make_pair("babbar", 3);
    m.insert(p);
    
    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    m["mera"]=1;
    m["mera"]=2;

    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;
    cout<<m["unknown"]<<endl;

    cout<<m.size()<<endl;
    
    //check presence
    cout<<m.count("bro")<<endl;
    cout<<m.count("love")<<endl;

    m.erase("love");
    cout<<m.size()<<endl;

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    unordered_map<string, int> :: iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
}