#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the queen in column c is ok
bool ok(int q[], int c) {
   for (int i = 0; i < c; i++) { //Setting loop to check every element before c (Making sure its not <= because if it is then i == c and return false)
      if ((q[i] == q[c])  || (c - i) == abs(q[c] - q[i]))
      	 return false;
    }
   return true;
}

void print(int q[]) {
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ": ";
   for(int i = 0; i < 8; i++) {
   	cout << q[i];
   }
   cout << "\n";
}

int main() {
   int c = 0;
   int q[8] = {0}; 
   q[0] = 0;  // Initialize the array to 0.
   while (c >= 0) { // End the loop if you backtrack from the first column
      c++;// Move to the next column
      if (c == 8) {
        print(q);
	    c-=1;
 } else {
 	q[c] =- 1;
}
      while (c >= 0) {
      	q[c]++;
      	if(q[c] == 8) {
      		c--;
		} else {
        if ((ok(q,c)) == true)  
         break;
     }
      }
   }
   return 0;
}
