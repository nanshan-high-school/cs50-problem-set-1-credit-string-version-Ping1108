#include <iostream>
using namespace std;

int main() {
    string number;
	cout << "請輸入卡號:";
    cin >> number;

    int oddSum = 0;
    int evenSum = 0;

    bool even = false;

    bool visaHead = false;
    bool mastercardHead = false;
    bool americanExpressHead = false;

    int i = 0;
	int digit[i];

    while ("number" - "0" > 0) {
        for (i = 0; number[i] != '\0'; i++) {
			digit[i] = number[i] - '\0';
		
		int now; 

        if (even) {
			int now = digit[i] * 2;

            evenSum += (now % 10) + (now / 10);

        } else {
            oddSum = oddSum + now;
        }
        
        even = !even;
		}

        if (digit[0] >= 10 && digit[0] <= 99) {
            if (digit[0] == 4) {
                visaHead = true;
            } else if (digit[0] == 5 && digit[1] >= 1 && digit[5] <= 5) {
                mastercardHead = true;
            } else if (digit[0] == 3 && digit[1] >= 4 && digit[1] <= 7) {
                americanExpressHead = true;
            }
        }

        even = !even;
    }

    int answer = oddSum + evenSum;

    if (answer % 10 != 0) {
        cout << "無效卡號";

        return 0;
    }
    
    if (visaHead && (i == 13 || i == 16)) {
        cout << "VISA";

        return 0;
    }

    if (mastercardHead && i == 16) {
        cout << "MasterCard";

        return 0;
    }

    if (americanExpressHead && i == 15) {
        cout << "American Express";

        return 0;
    }
}
