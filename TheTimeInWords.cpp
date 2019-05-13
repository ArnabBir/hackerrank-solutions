#include <bits/stdc++.h>

using namespace std;

vector<string> numbers = {
    "zero",        "one",        "two",          "three",        "four",
    "five",        "six",        "seven",        "eight",        "nine",
    "ten",         "eleven",     "twelve",       "thirteen",     "fourteen",
    "fifteen",     "sixteen",    "seventeen",    "eighteen",     "nineteen",
    "twenty",      "twenty one", "twenty two",   "twenty three", "twenty four",
    "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine"};

// Complete the timeInWords function below.
string timeInWords(int h, int m) {

    if(m == 0) {
        return numbers[h] + " o' clock";
    }    
    else if(m == 15) {
      return "quarter past " + numbers[h];
    }
    else if(m == 45) {
        if(h == 12) return "quarter to " + numbers[1];
        else    return "quarter to " + numbers[h+1];
    }
    else if(m == 30) {
      return "half past " + numbers[h];
    }
    else if(m == 1) {
      return numbers[m] + " minute past " + numbers[h];  
    }
    else if(m < 30) {
      return numbers[m] + " minutes past " + numbers[h];
    }
    else if(m == 59) {
      if (h == 12)
        return numbers[60 - m] + " minute to " + numbers[1];
      else
        return numbers[60 - m] + " minute to " + numbers[h + 1];
    }
    else {
      if(h == 12)   return numbers[60 - m] + " minutes to " + numbers[1];
      else  return numbers[60 - m] + " minutes to " + numbers[h+1];
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
