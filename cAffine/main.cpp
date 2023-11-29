#include <iostream>

using namespace std;

//Fonctionn de calcul du PGCD.
int pgcd(int a, int b)
{
    while (b!= 0) {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}

//Fonction pour déterminer l'inverse de a par la congruence.
int inverseCongruence(int a, int n)
{
    a = a % n;
    for (int i = 1 ; i < n ; i++) {
        if (((a*i) % n) == 1) {
            return i;
        }
    }
    return -1;
}

int main()
{
    cout << 'A' << endl;
    int decision;
    do {
        int a, b, choix;
        string message;

        //L'utilisateur choisira ce qu'il compte faire, crypter ou décrypter.
        cout << "Entrez le numéro de l'opération que vous souhaitez effectuer. \n 1. Crypter le message. \n 2. Décrypter le message." << endl;
        cin >> choix;

        //Il lui sera imposer de choisir une opération entre les deux qui lui ont été proposé.
        while (choix != 1 && choix != 2) {
            cout << "\n Vous devez choisir entre 1 et 2. \n Entrez le numéro de l'opération que vous souhaitez effectuer. \n 1. Crypter le message. \n 2. Décrypter le message." << endl;
            cin >> choix;
        }

        //En fonction de son choix, l'opération sera effectuée.
        string messageEnvoye = "";

        //Vérifier si a et 26 sont premiers entre eux.
        do {
            //a
            cout << "\n Entrez la valeur du coefficient directeur (a). Cette valeur doit être première avec 26." << endl;
            cin >> a;
        } while (pgcd(a, 26) != 1);
        //b
        cout << "\n Entrez la valeur de l'ordonnée à l'origine (b)." << endl;
        cin >> b;
        cin.ignore();

        //Le choix 1 correspond à l'opération de cryptage.
        if (choix == 1) {
            cout << "\n Entrez le message à crypter." << endl;
            getline(cin, message);
            for (char caractere : message) {
                if(caractere >= 'A' && caractere <= 'Z') {
                    //Des modifications seront appliquées uniquement si et seulement si le caractère est compris entre 'A' et 'Z'.
                    caractere = ((((caractere - 65)*a + b) % 26) + 65);
                    messageEnvoye = messageEnvoye + caractere;
                } else if(caractere >= 'a' && caractere <= 'z') {
                    //Des modifications seront appliquées uniquement si et seulement si le caractère est compris entre 'a' et 'z'.
                    caractere = ((((caractere - 97)*a + b) % 26) + 97);
                    messageEnvoye = messageEnvoye + caractere;
                } else {
                    messageEnvoye = messageEnvoye + caractere;
                }
            }
            cout << "\n Le message crypté est : " << messageEnvoye << "\n" << endl;
        } else {
            //Décryptage
            cout << "\n Entrez le message à décrypter." << endl;
            getline(cin, message);

            if (inverseCongruence(a, 26) != -1) {
                for (char caractere : message) {
                    if(caractere >= 'A' && caractere <= 'Z') {
                        caractere = ((inverseCongruence(a, 26)*(caractere - b - 65 + 26) % 26) + 65);
                        messageEnvoye = messageEnvoye + caractere;
                    } else if(caractere >= 'a' && caractere <= 'z') {
                        caractere = ((inverseCongruence(a, 26)*(caractere - b - 97 + 26) % 26) + 97);
                        messageEnvoye = messageEnvoye + caractere;
                    } else {
                        messageEnvoye = messageEnvoye + caractere;
                    }
                }
                cout << "\n Le message décrypté est : " << messageEnvoye << "\n" << endl;
            }
        }

        cout << "\n Choisissez 1 si vous voulez quitter le programme et un autre chiffre (différent de 1) si vous crypter ou décrypter un autre message. \n 1. Quitter \n 2. Continuer" << endl;
        cin >> decision;
    } while (decision != 1);

    return 0;
}
