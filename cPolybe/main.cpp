#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int TAILLE = 5;

// Fonction pour afficher le tableau de Polybe
void afficherPolybe(vector<vector<char>>& polybeTable) {
    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            cout << polybeTable[i][j] << " ";
        }
        cout << endl;
    }
}

// Fonction pour remplir le tableau de Polybe avec le mot clé
void remplirTableau(vector<vector<char>>& polybeTable, const string& motCle) {
    string cleUnique = "";
    // Obtenir les lettres uniques du mot clé dans l'ordre
    for (char c : motCle) {
        if (c != 'J' && cleUnique.find(c) == string::npos) {
            cleUnique += c;
        }
    }

    // Remplir le tableau avec les lettres du mot clé
    int indexMotCle = 0;
    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            if (indexMotCle < cleUnique.size()) {
                polybeTable[i][j] = cleUnique[indexMotCle++];
            }
        }
    }

    // Compléter le reste du tableau avec les lettres de A à Z qui ne sont pas dans le mot clé
    char currentChar = 'A';
    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            if (polybeTable[i][j] == 0) {
                while (cleUnique.find(currentChar) != string::npos || currentChar == 'J') {
                    ++currentChar;
                }
                polybeTable[i][j] = currentChar++;
            }
        }
    }
}

pair<int, int> trouverPosition(const vector<vector<char>>& polybeTable, char lettre) {
    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            if (polybeTable[i][j] == lettre) {
                return make_pair(i, j);
            }
        }
    }
    // Retourner une paire -1, -1 si la lettre n'est pas trouvée
    return make_pair(-1, -1);
}

// Fonction pour crypter un message avec le chiffre de Polybe
string crypterPolybe(const vector<vector<char>>& polybeTable, const string& message) {
    string messageCrypte = "";

    for (char c : message) {
        pair<int, int> position = trouverPosition(polybeTable, c);
        if (position.first != -1 && position.second != -1) {
            // Ajouter les coordonnées au message crypté
            messageCrypte += to_string(position.first) + to_string(position.second);
        }
    }

    return messageCrypte;
}

int main() {
    vector<vector<char>> polybeTable(TAILLE, vector<char>(TAILLE, 0));

    // Demander à l'utilisateur d'entrer le mot clé
    string motCle;
    cout << "Entrez le mot clé : ";
    cin >> motCle;

    remplirTableau(polybeTable, motCle);

    // Afficher le tableau de Polybe résultant
    cout << "Tableau de Polybe :" << endl;
    afficherPolybe(polybeTable);

    // Demander à l'utilisateur d'entrer le message à crypter
    string message;
    cout << "Entrez le message à crypter (en majuscules) : ";
    cin >> message;

    // Crypter le message avec le chiffre de Polybe
    string messageCrypte = crypterPolybe(polybeTable, message);

    // Afficher le message crypté
    cout << "Message crypté : " << messageCrypte << endl;

    return 0;
}


/********************************************************************************************************************************************
#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 5;

// Fonction pour trouver la position d'une lettre dans le tableau de Polybe


int main() {
    // Utiliser le tableau de Polybe créé précédemment
    vector<vector<char>> polybeTable(SIZE, vector<char>(SIZE, 0));
    string keyword;

    // Demander à l'utilisateur d'entrer le mot clé
    cout << "Entrez le mot clé : ";
    cin >> keyword;

    remplirTableau(polybeTable, keyword);

    // Afficher le tableau de Polybe résultant
    cout << "Tableau de Polybe :" << endl;
    afficherPolybe(polybeTable);


    return 0;
}
*/
