
#include <iostream>
#include <map>
#include <utility>
#include <vector>

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    std::map<char,char> reverse;
    
    for(auto x : {'A', 'H','I','M','O','T','U','V','W','X','Y','1','8'})
        reverse[x] = x;
    for(auto x : {'B', 'C','D','F','G','K','N','P','Q','R','4','6','7','9'})
        reverse[x] = ' ';
    using T = std::vector<std::pair<char,char>>;
    for(auto [x,y] : T{{'E','3'}, {'J','L'}, {'S','2'}, {'Z','5'}}) {
        reverse[x] = y;
        reverse[y] = x;
    }
    
    std::string word;
    std::cin >> word;
    auto palindrome = true;
    auto mirrored = true;
    for(int s=0, e=word.size()-1; s<=e; ++s, --e) {
        if(word[s] != word[e]) 
            palindrome = false;
        if(word[s] != reverse[word[e]]) 
            mirrored = false;
    }

    std::cout << word;
    if(!palindrome && !mirrored){
        std::cout << " -- is not a palindrome.\n";
    } else if (palindrome && !mirrored){
        std::cout << " -- is a regular palindrome.\n";
    } else if (!palindrome && mirrored){
        std::cout << " -- is a mirrored string.\n";
    } else if (palindrome && mirrored){
        std::cout << " -- is a mirrored palindrome.\n";
    }
   
    return 0;
}
