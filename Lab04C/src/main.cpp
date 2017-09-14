/* CSCI 261 Lab 04C: Fix Loop Errors
*
* Author: XXXX (_INSERT_YOUR_NAME_HERE_)
*
*    This program illustrates a variety of common loop errors.
*    Fix the errors in each section.
*/

#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to Loop World" << endl;

// SECTION I: update comment below on how you fixed this section's code, and tests run
// FIX = change the initial value of i to 0 and change less than to less than or equal to
// TESTS: Manually add the numbers and check the result

    cout << endl << "Section I" << endl;

    int sum;  // Accumulates the total
    int i;    // Used as loop control variable
    for (i = 1; i <= 5; ++i) {
         sum += i;
     }
    cout << "The sum of the numbers from 1 to 5 (inclusive) is: " << sum << endl;

// SECTION II: update comment below on how you fixed this section's code, and tests run
// FIX = Changing less than to less than or equals to and move total=0 to before the beginning of the loop
// TESTS: Totaling the price of three items

    cout << endl << "Section II" << endl;

    double total;     // Accumulates total
    double price;    // Gets next price from user
    int num_items;     // Number of items
    int counter = 1;  // Loop control counter

    cout << "How many items do you have? ";
    cin >> num_items;

    total=0;
    price=0;
    while (counter <= num_items) {
        cout << "Enter the price of item " << counter << ": ";
        cin >> price;
        total += price;
        counter++;
    }
    cout << "The total price is: " << total << endl;

// SECTION III: update comment below on how you fixed this section's code, and tests run
// FIX = Change the AND condition to an OR condition because the reply can't both be 'y' and 'Y'
// TESTS: add two items then answer n and check the sum

    cout << endl << "Section III" << endl;

    char reply;  // loop control variable
    do {
        cout << "Enter the price of the next item: ";
        cin >> price;
        total += price;

        cout << "Do you have more items? (y or n) ";
        cin >> reply;
    } while (reply == 'y' || reply == 'Y');

    cout << "The total price is: " << total << endl;

// SECTION IV: update comment below on how you fixed this section's code, and tests run
// FIX = change the count <= sum to counter <= 4 and increase the counter on each loop
// TESTS: check the accuracy of the sum at the end

    cout << endl << "Section IV" << endl;

    cout << "I will now calculate ";
    cout << "the sum of numbers from 1 to 4 (inclusive)" << endl;

    sum=0;
    counter = 1;

    do {
        sum += counter;
        cout << "Sum so far: " << sum << endl;
        counter++;
    } while (counter <= 4);

// SECTION V: update comment below on how you fixed this section's code, and tests run
// FIX = Change i>0 to i<=4, and change the initial value of i to 0
// TESTS: Manually calculate the output and insure it is correct. (Also ensure the loop terminates.)

    cout << endl << "Section V" << endl;

    cout << "I will now calculate ";
    cout << "the sum of squares from 1 to 4 (inclusive)" << endl;

    sum = 0;
    for (i=1; i<=4; i++) {
        sum += i*i;
    }

    cout << "The sum of squares from 1 to 4 is: " << sum << endl;

// SECTION VI: update comment below on how you fixed this section's code, and tests run
// FIX = Change counter < 10 to counter <= 4; move counter++ inside the while loop
// TESTS: Manually calculate the output and insure it is correct. (Also ensure the loop terminates.)

    cout << endl << "Section VI" << endl;

    cout << "I will now calculate ";
    cout << "the sum of cubes from 1 to 4 (inclusive)" << endl;

    sum = 0;
    counter = 1;

    while (counter <= 4) {
        sum += (counter * counter * counter);

        counter++;
    }

    cout << "The sum of cubes from 1 to 4 is: " << sum << endl;

// SECTION VII: update comment below on how you fixed this section's code, and tests run
// FIX = move sum+= counter inside the for loop
// TESTS: Manually calculate the answer and check if it is correct.

    cout << endl << "Section VII" << endl;

    cout << "I can calculate the sum of 1 to 5 using a for loop" << endl;
    sum=0;
    for (counter=0; counter<= 5; counter++) {
       sum += counter;
    }

    cout << "The sum of numbers from 1 to 5 (inclusive) is: " << sum << endl;

// SECTION VIII: update comment below on how you fixed this section's code, and tests run
// FIX = change counter != 9 to counter <= 9
// TESTS: Manually calculate the answer and check if it is correct.

    cout << endl << "Section VIII" << endl;

    cout << "I can print all the odd numbers from 1 to 9" << endl;

    for (counter=1; counter <= 9; counter=counter+2)
        cout << counter << endl;

    return 0;
}
