#include <iostream>
#include <vector>

using namespace std;

void diceACombo(vector<int>& elements, int length, vector<int>& current, vector<vector<int>>& allCombinations) {
    if (current.size() == length) {
        allCombinations.push_back(current);
        return;
    }
    for (int element : elements) {
        current.push_back(element);
        diceACombo(elements, length, current, allCombinations);
        current.pop_back();
    }
}

void diceBCombo(vector<int>& elements, int length, int start, vector<int>& current, vector<vector<int>>& allCombinations) {
    if (current.size() == length) {
        allCombinations.push_back(current);
        return;
    }
    for (int i = start; i < elements.size(); i++) {
        current.push_back(elements[i]);
        diceBCombo(elements, length, i + 1, current, allCombinations);
        current.pop_back();
    }
}

vector<double> probSum(const vector<int>& arr1, const vector<int>& arr2) {
    vector<double> psum1(12, 0.0);
    for (int i : arr1) {
        for (int j : arr2) {
            int k = i + j;
            psum1[k - 1] += 1;
        }
    }
    for (int i = 0; i < psum1.size(); i++) {
        if (psum1[i] != 0) {
            psum1[i] /= 36;
        }
    }
    return psum1;
}

void transform(const vector<int>& dieA, const vector<int>& dieB) {
    vector<int> elements1 = {1, 2, 3, 4};
    int length = 6;
    vector<int> current;
    vector<vector<int>> combo1;
    diceACombo(elements1, length, current, combo1);

    vector<int> elements2 = {1, 2, 3, 4, 5, 6, 7, 8};
    int start = 0;
    vector<vector<int>> combo2;
    diceBCombo(elements2, length, start, current, combo2);

    vector<double> psum = {0.0, 1.0 / 36, 2.0 / 36, 3.0 / 36, 4.0 / 36, 5.0 / 36, 6.0 / 36, 5.0 / 36, 4.0 / 36, 3.0 / 36, 2.0 / 36, 1.0 / 36};

    bool flag = false;
    for (const auto& i : combo1) {
        for (const auto& j : combo2) {
            if (probSum(i, j) == psum) {
                cout << "new die_a: ";
                for (int x : i) {
                    cout << x << " ";
                }
                cout << "\nnew die_b: ";
                for (int x : j) {
                    cout << x << " ";
                }
                cout << endl;
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
}

int main() {
    vector<int> dieA = {1, 2, 3, 4, 5, 6};
    vector<int> dieB = {1, 2, 3, 4, 5, 6};
    transform(dieA, dieB);
    return 0;
}