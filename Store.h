#pragma once
class Store {
    string nCharString(size_t n, char c);


    string nCharString(size_t n, char c) {
        int i;
        string charStr;

        for (i = 0; i < n; ++i) {
            charStr += c;
        }
        return charStr;
    }
    
    
};

