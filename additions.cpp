#include "iostream"
#include "list"

using namespace std;

list<list<uint> *> get_sums(uint number, uint max_b) {
    list<list<uint> *> sums = {};
    uint b;

    for (auto a = min(number - 1, max_b); a >= 1; --a) {
        b = number - a;

        if (b <= a) {
            sums.push_back(new list<uint>{a, b});
        }

        if (b != 1) {
            auto b_sums = get_sums(b, a);

            for (auto &sum: b_sums) {
                sums.push_back(new list<uint>{a});
                auto addends = sums.back();

                (*addends).splice((*addends).end(), *sum);
            }
        }
    }

    return sums;
}

list<list<uint> *> get_sums(uint number) {
    return get_sums(number, number);
}

void print_additions(const uint original) {
    uint size, i;

    auto sums = get_sums(original);

    for (const auto &sum: sums) {
        i = 1;
        size = (*sum).size();

        cout << original << "=";

        for (const auto &addend: *sum) {
            cout << addend;

            if (i < size) {
                cout << "+";
            }

            i++;
        }
        cout << endl;
    }
}

int main() {
    uint a;
    cin >> a;

    print_additions(a);


    return 0;
}
