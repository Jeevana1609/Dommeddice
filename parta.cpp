#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    vector<int> Die_A = {1, 2, 3, 4, 5, 6};
    vector<int> Die_B = {1, 2, 3, 4, 5, 6};

    int total_combinations = Die_A.size() * Die_B.size();
    cout << "Total combinations: " << total_combinations <<endl;

    vector<vector<pair<int, int>>> combinations(6, vector<pair<int, int>>(6));
    vector<int> sum_count(13);

    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            pair<int, int> combination = make_pair(Die_A[i], Die_B[j]);
            combinations[i][j] = combination;

            int sum = Die_A[i] + Die_B[j];
            sum_count[sum]++;
            
        }
    }

    // Display the 6x6 matrix of combinations
    cout << "\nMatrix of combinations:\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            pair<int, int> combination = combinations[i][j];
            cout << "(" << combination.first << ", " << combination.second << ") ";
        }
        cout << endl;
    }

    // Display probabilities for each sum
    cout << "\nProbability of each sum:\n";
    for (int i = 2; i <= 12; i++) {
        double probability = static_cast<double>(sum_count[i]) / total_combinations;
        cout << "P(Sum = " << i << ") = " << sum_count[i] << "/36 = " << probability << endl;
    }

    return 0;
}
