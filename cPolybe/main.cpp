/*#include <iostream>

using namespace std;

int main()
{
    const int L = 5;
    string motCle, tableau[L][L];

    //Demander à l'utilisateur d'entrer le mot clé.
    cout << "Entrez le clé. Il doit être constitué que de lettre." << endl;
    getline(cin, motCle);
    return 0;
}*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 5;

// Fonction pour afficher le tableau de Polybe
void afficherPolybe(vector<vector<char>>& polybeTable) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << polybeTable[i][j] << " ";
        }
        cout << endl;
    }
}

// Fonction pour remplir le tableau de Polybe avec le mot clé
void remplirTableau(vector<vector<char>>& polybeTable, const string& keyword) {
    string uniqueKeyword = "";

    // Obtenir les lettres uniques du mot clé dans l'ordre
    for (char c : keyword) {
        if (c != 'J' && uniqueKeyword.find(c) == string::npos) {
            uniqueKeyword += c;
        }
    }

    // Remplir le tableau avec les lettres du mot clé
    int keywordIndex = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (keywordIndex < uniqueKeyword.size()) {
                polybeTable[i][j] = uniqueKeyword[keywordIndex++];
            }
        }
    }

    // Compléter le reste du tableau avec les lettres de A à Z qui ne sont pas dans le mot clé
    char currentChar = 'A';
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (polybeTable[i][j] == 0) {
                while (uniqueKeyword.find(currentChar) != string::npos || currentChar == 'J') {
                    ++currentChar;
                }
                polybeTable[i][j] = currentChar++;
            }
        }
    }
}

int main() {
    vector<vector<char>> polybeTable(SIZE, vector<char>(SIZE, 0));

    // Demander à l'utilisateur d'entrer le mot clé
    string keyword;
    cout << "Entrez le mot clé : ";
    cin >> keyword;

    remplirTableau(polybeTable, keyword);

    // Afficher le tableau de Polybe résultant
    cout << "Tableau de Polybe :" << endl;
    afficherPolybe(polybeTable);

    return 0;
}
