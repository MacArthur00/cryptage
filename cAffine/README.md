# Programme de Cryptage et Décryptage

Ce programme en C++ effectue le cryptage et le décryptage en utilisant la méthode du chiffre affine.

## Utilisation

1. Compilez le code.
2. Exécutez le fichier exécutable.

## Opérations

Le programme propose deux opérations :
1. *Crypter le message* : Crypter un message avec le chiffre affine.
2. *Décrypter le message* : Décrypter un message avec le chiffre affine.

## Comment Utiliser

1. Entrez le numéro de l'opération que vous souhaitez effectuer (1 ou 2).
2. Pour le cryptage, fournissez le coefficient directeur (a) et l'ordonnée à l'origine (b).
3. Entrez le message à crypter ou décrypter.
4. Suivez les invitations pour continuer ou quitter le programme.

## Remarque

- Le programme assure que le coefficient directeur (a) et 26 sont premiers entre eux.
- Le cryptage s'applique aux caractères entre 'A' et 'Z' (majuscules) et 'a' et 'z' (minuscules).
- Le décryptage nécessite une congruence inverse valide du coefficient directeur (a) modulo 26.

## Exemple

```plaintext
Entrez le numéro de l'opération que vous souhaitez effectuer.
1. Crypter le message.
2. Décrypter le message.
