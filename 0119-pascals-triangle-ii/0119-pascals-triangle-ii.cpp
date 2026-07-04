 class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        long long coefficient = 1;

        for (int col = 1; col <= rowIndex; col++) {
            coefficient = coefficient * (rowIndex - col + 1) / col;
            row[col] = coefficient;
        }

        return row;
    }
};