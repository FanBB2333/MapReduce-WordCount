#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
#include <fstream>
using namespace std;

bool cmp(pair<string, int> w1, pair<string, int> w2) {
    if(w1.second == w2.second){
        return w1.first < w2.first;
    }
    return w1.second > w2.second;
}


int main()
{
    vector<pair<string, int>> wordCount;
    string filename = "input.txt";
    ifstream ifs(filename);
    string word;
    bool find{false};
    while(!ifs.eof()){
        find = false;
        ifs >> word;
        for(auto iter = wordCount.begin(); iter != wordCount.end();iter++){
            if(iter->first == word){
                iter->second += 1;
                find = true;
                break;
            }
        }
        if(!find){
            wordCount.emplace_back(word, 1);
        }

    }
    sort(wordCount.begin(), wordCount.end(), cmp);

    for(auto &word : wordCount){
        cout << word.first << " " << word.second << endl;
    }
    return 0;
}

