#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void menue (){
    cout << "==============================IKRAM============================"<<endl;
    cout << "|                                                             |"<<endl;
    cout << "|        1.Perfect number              2.Friendly number      |"<<endl;
    cout << "|                                                             |"<<endl;
    cout << "|        3.Narcessic                   4.Armstrong            |"<<endl;
    cout << "|                                                             |"<<endl;
    cout << "|        5.Pythagorian                 6.Mantissa             |"<<endl;
    cout << "|                                                             |"<<endl;
    cout << "|        6.LC & GD                     8.Exit                 |"<<endl;
    cout << "|                                                             |"<<endl;
    cout << "===========================Bousfiha============================"<<endl;
}
bool perfecto(int num) {
    int divisors_sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            divisors_sum += i;
        }
    }
    return divisors_sum == num;
}
void p(int a, int b) {
    int i=0 ;
    for (int num = a; num <= b; num++) {
        if (perfecto(num)) {
            i++;
            vector<int> divisors;
            for (int i = 1; i < num; i++) {
                if (num % i == 0) {
                    divisors.push_back(i);
                }
            }
            cout << num << " = ";
            for (size_t j = 0; j < divisors.size(); j++) {
                cout << divisors[j];
                if (j != divisors.size() - 1) {
                    cout << " + ";
                }
            }

            cout << endl;
        }

    }
    cout<<"theres is just "<<i << " between "<<a<<" and "<<b<<"."<<endl;
}
void Perfect(){
    cout<< "A perfect number is a positive integer that is equal to the sum of all its proper divisors(真因子). For example, 6, whose proper divisors are 1, 2, and 3, and indeed 6 = 1 + 2 + 3" <<endl ;
    int a ,b ;
    cout << "Please input the start number : "<<endl;
    cin >>a;
    cout<< "Please input the end number : "<<endl;
    cin >>b;
    p(a, b);
}
bool po(int a, int b) {
  if (a <= 0 || b <= 0) {
    return false;
  }

  int sa = 1; 
  int sb = 1;

  for (int i = 2; i * i <= a; ++i) {
    if (a % i == 0) {
      sa += (i + (a / i));  
      if (i * i == a) {                 
        sa -= i;
      }
    }
  }
  for (int i = 2; i * i <= b; ++i) {
    if (b % i == 0) {
      sb += (i + (b / i));  
      if (i * i == b) {               
        sb -= i;
      }
    }
  }
  return (a == sb) && (b == sa);
}

void ff(int x, int y) {
  if (x <= 0 || y < 0 || x > y) {
    cout << "Invalid interval. Please enter positive integers with lower bound less than or equal to upper bound." << endl;
    return;
  }

  for (int i = x; i <= y; ++i) {
    for (int j = i + 1; j <= y; ++j) { 
      if (po(i, j)) {
        cout << i << " and " << j << " are friendly numbers." << endl;
      }
    }
  }
}
void fre(){
    int x, y;
  cout << "Enter the lower bound of the interval (positive integer): ";
  cin >> x;
  cout << "Enter the upper bound of the interval (positive integer): ";
  cin >> y;

  ff(x, y);
}
bool nar(int num) {
  if (num <= 0) {
    return false; 
  }

  int d = to_string(num).length();
  int sumof = 0;
  int temp = num;

  while (temp > 0) {
    int digit = temp % 10;
    sumof += pow(digit, d);
    temp /= 10;
  }

  return (sumof == num);
}

void narcessic(int xx, int yy) {
  if (xx > yy) {
    cout << "Invalid interval. Lower bound should be less than or equal to upper bound." << endl;
    return;
  }

  cout << "Narcissistic numbers between " << xx << " and " << yy << " (inclusive):" << endl;
  for (int num = xx; num <= yy; ++num) {
    if (nar(num)) {
      cout << num << " ";
    }
  }
  cout << endl;
}
void nare(){
    int xx, yy;
  cout << "Enter the lower bound of the interval (positive integer): ";
  cin >> xx;
  cout << "Enter the upper bound of the interval (positive integer): ";
  cin >> yy;

  narcessic(xx, yy);
}
bool am(int num) {
    int originalNum = num;
    int numDigits = 0;
    int sum = 0;
    while (originalNum != 0) {
        originalNum /= 10;
        numDigits++;
    }
    originalNum = num;
    while (originalNum != 0) {
        int digit = originalNum % 10;
        sum += pow(digit, numDigits);
        originalNum /= 10;
    }
    return sum == num;
}
void fredm(int digits) {
    int start = pow(10, digits - 1);
    int end = pow(10, digits) - 1;

    for (int num = start; num <= end; num++) {
        if (am(num)) {
            cout << num << " ";
        }
    }
    cout << endl;
}
void amtrs(){
    cout << "Enter the number of digits to find Armstrong numbers: ";
    int digits;
    cin >> digits;

    cout << "The Armstrong numbers of " << digits << " digits are: ";
    fredm(digits);
}
struct Triple {
    int a, b, c;

    Triple(int x, int y, int z) : a(x), b(y), c(z) {}
};

vector<Triple> generatePythagoreanTriples(int lower, int upper) {
    vector<Triple> triples;
    for (int a = lower; a <= upper; ++a) {
        for (int b = a + 1; b <= upper; ++b) {
            int cSquare = a * a + b * b;
            int c = sqrt(cSquare);
            if (c * c == cSquare && c <= upper) {
                triples.push_back(Triple(a, b, c));
            }
        }
    }
    return triples;
}
void py()
{
    int lower, upper;
    cout << "Enter the lower bound of the interval: ";
    cin >> lower;
    cout << "Enter the upper bound of the interval: ";
    cin >> upper;

    vector<Triple> triples = generatePythagoreanTriples(lower, upper);
    
    cout << "Pythagorean triples in the interval [" << lower << ", " << upper << "]:" << endl;
    for (size_t i = 0; i < triples.size(); ++i) {
        cout << "(" << triples[i].a << ", " << triples[i].b << ", " << triples[i].c << ")" << endl;
    }
}
int ex(int base, int exponent, int mod) {
    if (mod == 1) return 0; 
    int result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        exponent = exponent >> 1; 
        base = (base * base) % mod;
    }
    return result;
}
void manti(){
    int base, exponent, digits;
    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;
    cout << "Enter the number of digits to find: ";
    cin >> digits;

    int mod = 1;
    for (int i = 0; i < digits; i++) {
        mod *= 10;
    }

    int lastDigits = ex(base, exponent, mod);
    cout << "The last " << digits << " digits of " << base << "^" << exponent << " are: " << lastDigits << endl;

}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}


int lcm(int a, int b) {
  if (a == 0 || b == 0) return 0; 
  return (a * b) / gcd(a, b);
}

void gl(){
    int num1, num2;

  cout << "Enter first number: ";
  cin >> num1;

  cout << "Enter second number: ";
  cin >> num2;

  int greatestCommonDivisor = gcd(num1, num2);
  int leastCommonMultiple = lcm(num1, num2);

  cout << "GCD of " << num1 << " and " << num2 << " is: " << greatestCommonDivisor << endl;
  cout << "LCM of " << num1 << " and " << num2 << " is: " << leastCommonMultiple << endl;

}
int main (){
    int choice ;
    do
    {
        menue();
        cin>>choice ;

        switch (choice) {
            case 1 : 
                Perfect();
            case 2 : 
                fre();
            case 3 :
                nare();
            case 4:    
                amtrs();
            case 5 :
                py();
            case 6 :
                manti();

            case 7:
                gl();

        }
    }
    while (choice != 8);
    return 0;
}

