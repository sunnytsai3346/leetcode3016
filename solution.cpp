#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to calculate the minimum number of key presses needed
int minKeyPresses(string word) {
  // step1 . set up a frequency[]
  // step2 . from the from 2-9 , 8 positions to dispatch
  vector<int> frequency(26, 0);
  for (char ch : word) {
    frequency[ch - 'a']++;
  }
  // sorting frequency
  sort(frequency.begin(), frequency.end(), greater<int>());
  // 26/8=3...2
  int minresult = 0;
  int push = 1;
  for (int i = 0; i < 26 && frequency[i]; ++i) {
    minresult += frequency[i] * push;
    if ((i +1) % 8 == 0) 
      push += 1;
  }
  return minresult;
}

int main() {
    string word = "alporfmdqsbhncwyu";
    cout << "Minimum key presses needed: " << minKeyPresses(word) << endl;
    return 0;
}
