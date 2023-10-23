/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Burak Yesil
 * Date        : 09-30-2021
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector< vector<int> > get_ways(int num_stairs) {
    // TODO: Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.
    if (num_stairs<=0) return {{}};
    vector<vector <int>> ways;
    for(int i = 1; i<4; i++){
        if (num_stairs>=i){
            vector <vector <int>> result = get_ways(num_stairs-i);
            for (unsigned int j = 0; j<result.size(); j++) result[j].insert(result[j].begin(), i);
            ways.insert(ways.end(), result.begin(), result.end());
        }
    }
    return ways;
}


void display_ways(const vector< vector<int> > &ways) {
    // TODO: Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.
    int counter = 0;
    for(unsigned int i = ways.size(); i > 0; i = i/10) counter++;
    for(unsigned int i = 0; i<ways.size(); i++){
        cout<<setw(counter)<< i+1 << ". ";
        for(auto target = ways[i].cbegin(); target != ways[i].cend(); target++){
            if (target == ways[i].cbegin()) cout<<"["<< *target;
            else cout << ", " << *target;
        }
        cout << "]" << endl; 
    }
}

int main(int argc, char * const argv[]) { 
    int m;
    istringstream iss;

    //checking input
    if (argc != 2){
        cerr << "Usage: " <<argv[0]<< " <number of stairs>" << endl;
        return 1;
    }

    iss.str(argv[1]);

    if(!(iss >> m)){
        cerr << "Error: Number of stairs must be a positive integer." <<endl;
        return 1;
    }

    if(m<0){
        cerr << "Error: Number of stairs must be a positive integer." <<endl;
        return 1;
    }

    vector< vector<int>> result = get_ways(m);

    if (result.size() == 1){
        cout << "1 way to climb 1 stair.\n" << "1. [1]" << endl;
    }
    else{
        cout << result.size() << " ways to climb " << m << " stairs." << endl;
        display_ways(result);
    }
}
