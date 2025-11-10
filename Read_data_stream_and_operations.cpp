/** 
Write a function that reads a data stream and returns output based on the sign of parameter n:
  n > 0 → Output the first n elements.
  n < 0 → Output the last |n| elements.
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> processStream(istream& input, int n) {
	// cout<<"steam called";
	vector<int> result;

	if (n > 0) {
		int value;
		while (n-- > 0 && input >> value) {
			result.push_back(value);
		}
	} else if (n < 0) {
		deque<int> buffer;
		int value;
		int count = -n;
		while (input >> value) {
			buffer.pop_front();
		}
		buffer.push_back(value);
	}
	result.assign(buffer.begin(), buffer.end());
}

return result;
}

int main() {
	cout << "Enter n (positive or negative): ";
	int n;
	cin >> n;

	cout << "Enter stream of integers (Ctrl+D to end input):\n";
	vector<int> output = processStream(cin, n);

	cout << "Output:\n";
	for (int num : output) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}
