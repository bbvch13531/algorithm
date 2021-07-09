#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int a, b;   
    cin >> a >> b;
    cout << a + b << endl;
}