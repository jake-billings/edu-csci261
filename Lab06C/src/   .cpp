/* CSCI261 Lab 06C: Writing Files
 *
 * Author: Jake Billings
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
        ifstream data("secretMessage.txt");
        ofstream output("decryptedMessage.txt");

        if ( data.fail() ) {
           cerr << "Error opening input file";
           exit(1);
        }
        if ( output.fail() ) {
           cerr << "Error opening output file";
           exit(1);
        }

        while ( !data.eof() ) {
        	char in = data.get();
        	if (in=='~') {
        		in=' ';
        	} else if (in != '\n') {
        		in++;
        	}
            output << in;
        }

        data.close();
        output.close();
        return 0;
}
