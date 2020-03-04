/* -*- coding: utf-8 -*-
  !@time: 2020-03-04 03:23
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0044_reverse_words.cpp
 */
#include <environment.h>

#include <utility>

class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty())
            return str;
        vector<string> words = splitString(std::move(str));
        string ret;
        for (vector<string>::const_iterator iter = words.cend() - 1; iter != words.cbegin() - 1; iter--) {
            ret += *iter;
            if (iter != words.cbegin())
                ret += " ";
        }
        return ret;
    }

    vector<string> splitString(const string &str) {
        vector<string> words;
        stringstream ss;
        ss.str(str);
        string item;
        char delim = ' ';
        while (getline(ss, item, delim)) {
            words.push_back(item);
        }
        return words;
    }
    string ReverseSentence_template(string str) {
        string res, tmp;
        for(char i : str){
            if(i == ' ') res = " " + tmp + res, tmp = "";
            else tmp += i;
        }
        if(!tmp.empty()) res = tmp + res;
        return res;
    }
};

int fun() {
    string str = "world! hello";
    str = Solution().ReverseSentence(str);
    printf("%s", str.c_str());
    return 0;
}