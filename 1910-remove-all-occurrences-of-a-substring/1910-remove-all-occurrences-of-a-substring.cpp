class Solution {
public:
    string removeOccurrences(string s, string part) {
        // humko bass itna yaad rakhna  hai ki 
        while (s.find(part)<s.length()){
            s.erase(s.find(part), part.length());
    }
        return s;
    }
};