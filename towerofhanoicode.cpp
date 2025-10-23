#include <iostream>
#include <cmath>
using namespace std;

void restrictedHanoi(int n, char source, char aux, char dest, long long &moves) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " → " << aux << endl;
        cout << "Move disk 1 from " << aux << " → " << dest << endl;
        moves += 2;
        return;
    }

 
    restrictedHanoi(n - 1, source, aux, dest, moves);
  
    cout << "Move disk " << n << " from " << source << " → " << aux << endl;
    moves++;

    restrictedHanoi(n - 1, dest, aux, source, moves);
  
    cout << "Move disk " << n << " from " << aux << " → " << dest << endl;
    moves++;
  
    restrictedHanoi(n - 1, source, aux, dest, moves);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    long long moves = 0;
    cout << "\nSequence of moves:\n";
    restrictedHanoi(n, 'A', 'B', 'C', moves);

    cout << "\nTotal moves = " << moves;
    cout << "\nFormula check (3^n - 1) = " << (long long)pow(3, n) - 1 << endl;

    return 0;
}
