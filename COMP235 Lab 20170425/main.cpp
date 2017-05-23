

#include <set>
#include <map>
#include <iterator> //for ostream_iterator
#include <regex>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    /*
     Part 1 (STL::set) Copy and paste this into your IDE. Extract words into a set, display the set.
     */
    string gdp = { "GDP is commonly used as an indicator of the economic\
        health of a country, as well as a gauge of a country's \
        standard of living. Since the mode of measuring GDP is\
        uniform from country to country, GDP can be used to \
        compare the productivity of various countries with a \
        high degree of accuracy. Adjusting for inflation from \
        year to year allows for the seamless comparison of \
        current GDP measurements with measurements from previous \
        years or quarters. In this way, a nation's GDP from any \
        period can be measured as a percentage relative to \
        previous years or quarters. When measured in this way, \
        GDP can be tracked over long spans of time and used in \
        measuring a nation's economic growth or decline, as well \
        as in determining if an economy is in recession. GDP's \
        popularity as an economic indicator in part stems from \
        its measuring of value added through economic processes. \
        For example, when a ship is built, GDP does not reflect \
        the total value of the completed ship, but rather the \
        difference in values of the completed ship and of the \
        materials used in its construction. Measuring total \
        value instead of value added would greatly reduce GDP's \
        functionality as an indicator of progress or decline, \
        specifically within individual industries and sectors. \
        Proponents of the use of GDP as an economic measure \
        tout its ability to be broken down in this way and \
        thereby serve as an indicator of the failure or success \
        of economic policy as well. For example, from 2004 to \
        2014 France's GDP increased by 53.1%, while Japan's \
        increased by 6.9% during the same period." };
    
    //Convert everthing to lowercase
    for (int i = 0; i < gdp.length(); i++)
        gdp[i] = tolower(gdp[i]);
    
    //Get rid of everything except a-z or space
    regex e("[^a-zA-Z\\s]");
    gdp = regex_replace(gdp, e, "");
    
    //TO DO (1): Move words into a set
    multiset<string> gdpMultiSet;
    
    stringstream ss;
    
    ss << gdp;
    
    string line;
    while (!ss.eof()) {
        ss >> line;
        gdpMultiSet.insert(line);
    }
    
    set<string>::iterator setIterator = gdpMultiSet.begin();
    cout << "CONTENT: \n";
    for (; setIterator != gdpMultiSet.end(); setIterator++) {
        cout << *setIterator << endl;
    }
    
    
    //TO DO (2): Use the copy algorithm to iterate and display your set
    cout << "PART 2!====================\n";
    // mapped dictionary
    map<string, int> word_counts;
    
    set<string>::iterator another_set_iterator = gdpMultiSet.begin();
    cout << "CONTENT: \n";
    for (; another_set_iterator != gdpMultiSet.end(); another_set_iterator++) {
        
        string word = *another_set_iterator;
        cout << "WORD: " << word << "\n";

        if (word_counts.count(word) == 0) {
            word_counts[*another_set_iterator];
            word_counts[*another_set_iterator]++;
        } else if (word_counts.count(word) > 0) {
            word_counts[*another_set_iterator]++;
        }
        
    }
    
    // iterator
    map<string, int>::iterator map_itr = word_counts.begin();
    
    while (map_itr != word_counts.end()) {
        cout << map_itr->first << " " << map_itr->second << endl;
        map_itr++;
    }
    
    cout << endl;
    
    
    
    
    
    
    return 0;
}
