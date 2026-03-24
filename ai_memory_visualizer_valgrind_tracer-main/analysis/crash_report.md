## Programme : crash_example

### Description du crash
Le programme plante avec une erreur de segmentation lors de l’accès à un tableau libéré.

### Cause racine
- Mémoire concernée : heap
- La fonction malloc alloue de la mémoire pour un tableau.
- Ce tableau est libéré avec free().
- Ensuite, le programme tente d’écrire ou lire à partir du pointeur libéré (dangling pointer).

### Analyse
- free(a) libère la mémoire pointée par `a`.
- `b` pointe sur la même zone que `a` (aliasing).
- Tout accès à `b` après free provoque un comportement indéfini et crash.

### Correction proposée (optionnelle)
- Ne pas accéder à `b` après free(a).
- Si nécessaire, allouer un nouveau tableau pour `b`.