#include <iostream>
#include <vector>
#include <string>

typedef std::string Name;
typedef std::size_t Size;

using namespace std;


int getVec(Name &S)
{
    vector<pair<int, char> > letters;
    std::size_t idx=0;
    letters.push_back(std::make_pair(1, S[0]));
    for(std::size_t i=1; i< S.size(); ++i) {
        if(S[i] == letters[idx].second) {
            pair<int, char>& p = letters[idx];
            ++(p.first);
        } else {
            pair<int, char> p = std::make_pair(1, S[i]);
            letters.push_back(p);
            ++idx;
        }
    }
    
    int max = 0;
    for(std::size_t i=0; i< letters.size(); ++i) {
        if('0' == (letters[i].second) && max < (letters[i].first) ) {
            max = letters[i].first;
        }
    }

    return max;
}

Name bin(unsigned n)
{
    Name s;
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? s += "1" : s += "0";
    return s;
}

int getGap(const Name& s) {

    Size idx1 = s.find_first_of("1");
    Size idx2 = s.find_last_of("1");
    Name str = s.substr(idx1, idx2-idx1);

    return getVec(str);
}

int solution(int N) {

    Name s = bin(N);
    return getGap(s);
    // write your code in C++14 (g++ 6.2.0)
}

int main() {

    std::cerr << solution(1041) << std::endl;
    return 0;
}