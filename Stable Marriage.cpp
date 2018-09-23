#include<iostream>
using namespace std;

bool ok(int q[], int c) { // Finish this code
	static int mp[3][3] = { { 0,2,1 },  	 // Man#0's preferences
							{ 0,2,1 },		// Man#1's preferences
							{ 1,2,0 } };	// Man#2's preferences
						
	static int wp[3][3] = { { 2,1,0 },		// Woman#0's preferences
							{ 0,1,2 },		// Woman#1's preferences
							{ 2,0,1 } };	 // Woman#2's preferences
		int newm = c;
		int neww = q[c];
		
    for(int w = 0; w < c; w++) {
    	int x = w;
    	int b = q[w];
		if((b == neww) || (mp[x][neww] < mp[x][b]) && (wp[neww][x] < wp[neww][newm])) return false;
		if((mp[newm][b] < mp[newm][neww]) && (wp[b][newm] < wp [b][x]))
		return false;
	 }
	return true;
}

void print(int q[]) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	for (int i = 0; i < 3; i++)
	cout << i << '\t' << q[i] << endl;
	cout << endl;
}



int main() {
   int q[3] = {0};   
   int c=0;
   q[0]=0;
   while (c >= 0) { 
   	 c++;
      if(c==3){
        print(q);
        c--;
      }
      else{
      q[c]=-1;
    }
      while (c >= 0) {
         q[c]++;
         if(q[c]==3){
           c--;
    }
    else if(ok(q,c) == true){
        break;
        }
	}
    }
   
   return 0;
}
