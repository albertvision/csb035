#include "iostream"


using namespace std;

ushort calc_steps(int a, int b) {
    int tmp, q, r, steps = 0;

    do {
        q = a / b;
        r = a % b;

        a = b;
        b = r;

        steps++;
    } while (r != 0);

    return steps;
}

int main() {
    int a, b, tmp;

    a = 18;
    b = 30;

    tmp = max(a, b);
    b = min(a, b);
    a = tmp;

    auto steps = calc_steps(a, b);
    int **table = new int *[4];

    for (int i = 0; i < 4; ++i) {
        table[i] = new int[steps + 2];
    }

    table[0][0] = a;
    table[0][1] = b;

    int column = 1;

    do {
        table[1][column] = a / b;
        table[0][++column] = a % b;

        a = b;
        b = table[0][column];

    } while (column <= steps);


    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < steps + 2; ++j) {
            cout << table[i][j] << '\t';
        }

        cout << endl;
    }

    return 0;
}
