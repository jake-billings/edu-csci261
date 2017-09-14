/* CSCI261 Lab 06B: Reading data files
 *
 * Author: Jake Billings
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
        ifstream data("populations.txt");

        if ( data.fail() ) {
           cerr << "Error opening input file";
           exit(1);
        }

        int totalPopulation = 0;
        int totalCount = 0;

        while ( !data.eof() ) {
        	int population;
            data >> population;

            totalPopulation += population;
            totalCount++;
        }

        data.close();

        double averagePopulation = static_cast<double>(totalPopulation)/static_cast<double>(totalCount);

        cout << "The average population of America's " << totalCount << " cities is " << averagePopulation << "." << endl;

        return 0;
}
