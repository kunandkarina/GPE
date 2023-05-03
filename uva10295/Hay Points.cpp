#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin >> m >> n;
    map<string, int> dictionary;
    for(int i=0;i<m;i++){
      string word;
      int dollar;
      cin >> word >> dollar;
      dictionary[word] = dollar;
    }
    while(n--){
        string text;
        int total = 0;
        while(cin >> text && text != "."){
            if(dictionary[text]) total += dictionary[text];
        }
        cout << total << endl;
    }
}
