#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void dfs(vector<string>& grid, int x, int y) {
    int N = grid.size();
    int M = grid[0].size();

    if (x < 0 || x >= N || y < 0 || y >= M || grid[x][y] != '#') {
        return;
    }

    grid[x][y] = '.';

    dfs(grid, x + 1, y);
    dfs(grid, x - 1, y);
    dfs(grid, x, y + 1);
    dfs(grid, x, y - 1);
}

int countPlots(vector<string>& grid) {
    int n = grid.size();
    if (n == 0) {
        return 0;
    }
    int m = grid[0].size();

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                count++;
                dfs(grid, i, j);
            }
        }
    }

    return count;
}

int main() {
    setlocale(LC_ALL, "ru");

    //int N, M;
    //cout << "Введите колличество строк, и символов в строке: " << endl;
    //cin >> N >> M;

    //vector<string> grid(N);
    //for (int i = 0; i < N; i++) {
    //    cout << "Введите " << i+1 << "-ую строчку: " << endl;
    //    cin >> grid[i];
    //}

    ifstream inputFile;
    inputFile.open("z6.txt");
    if (!inputFile.is_open()) {
        cout << "Ошибка открытия файла." << endl;
        return 1;
    }

    int n, m;
    inputFile >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        inputFile >> grid[i];
    }
    inputFile.close();

    int result = countPlots(grid);
    cout << "Количество участков на поле: " << result << endl;



    return 0;
}