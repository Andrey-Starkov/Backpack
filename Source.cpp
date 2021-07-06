#include<iostream>
#include<string>
using namespace std;
struct thing {
	int ci;
	int wi;
};


int main() {
	setlocale(LC_ALL, "Russian");
	int k;
	string s = " ";
	int W, n;
		cout << "total weigh: ";
		cin >> W;
		cout << endl << "n: ";
		cin >> n;
		thing* things = new thing[n];
		for (int i = 0; i < n; i++) {
			cout << endl << "Weight: ";
			cin >> things[i].wi;
			cout << endl << "price: ";
			cin >> things[i].ci;
		}



	int** A = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		A[i] = new int[W + 1];
	}

	for (int j = 0; j <= W; j++) {
		A[0][j] = 0;
	}
	int a, b, c;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			if (j < things[i - 1].wi) {
				A[i][j] = A[i - 1][j];
			}
			if (j >= things[i - 1].wi) {
				A[i][j] = max(A[i - 1][j], A[i - 1][j - things[i - 1].wi] + things[i - 1].ci);
			}


		}
	}
	cout << "\t";
	for (int i = 0; i <= W; i++) {
		cout << i << "\t";
	}
	cout << endl;
	for (int i = 0; i <= n; i++) {
		cout << i;
		for (int j = 0; j <= W; j++) {
			cout << "\t" << A[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = n; i >= 1; i--) {
		for (int j = W; j >= 0; j--) {
			if (A[i][j] == A[i - 1][j]) {
				break;
			}
			else { cout << i; W -= things[i - 1].wi; break; }
		}
	}


}