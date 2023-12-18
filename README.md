# Client-TFTP

Creation d'un client TFTP

![Titre](img/UtilisationTFTP.png)
On a utilisé la commande TFTP pour transférer ce fichier vers un serveur TFTP situé sur srvtpinfo1.ensea.fr.Le transfert s'est déroulé avec succès, comme indiqué par le message "Sent 15 bytes in 0.0 seconds" dans l'interface TFTP.
Par la suite, on a supprimé le fichier test.txt localement avec la commande rm et vérifié que le fichier a été supprimé avec succès en utilisant à nouveau la commande ls.
Ensuite, on a utilisé à nouveau la commande TFTP pour télécharger le fichier test.txt depuis le serveur TFTP. Le transfert a été réussi, comme indiqué par le message "Received 15 bytes in 0.0 seconds" dans l'interface TFTP. Et aprés on a vérifié le contenu du fichier téléchargé avec la commande cat et confirmé que le texte "hello world" était présent.

## Question 1
Dans cette partie on prend des arguments en ligne de commande pour définir des informations de requêtes, notamment le serveur (host), le nom du fichier à transférer (filename), le nom du fichier local (localfile), et, en option, le port (port). Le code utilise une fonction parse_arguments pour effectuer l'analyse des arguments et renvoyer les valeurs correspondantes à travers des pointeurs.

Dans la fonction main, les variables nécessaires (host, filename, localfile, ip) sont déclarées et passées à la fonction parse_arguments. Si la fonction réussit à analyser les arguments, elle renvoie EXIT_SUCCESS, sinon, elle affiche un message d'utilisation et renvoie EXIT_FAILURE. Cela permet au programme principal de déterminer si les arguments sont corrects.

La fonction parse_arguments vérifie d'abord si le nombre d'arguments est soit 4 (cas standard) ou 5 (cas optionnel avec le port). Ensuite, elle alloue dynamiquement de la mémoire pour stocker les valeurs des arguments et les copie à travers les pointeurs correspondants. Si le port est fourni en tant que cinquième argument, il est également stocké dans la variable port.

En fin de compte, le programme principal affiche un message d'utilisation et renvoie EXIT_FAILURE si la fonction parse_arguments échoue, sinon, il peut continuer à utiliser les valeurs des variables host, filename, localfile, et port pour effectuer d'autres opérations, comme le transfert de fichiers via TFTP.

Il est important de noter que le code assume que les utilisateurs fournissent les arguments corrects lors de l'exécution du programme et prend en charge la gestion de la mémoire pour les allocations dynamiques.
## Question 2

Cette section du code implémente une requête avec trois arguments,où le premier argument est l'adress du serveur. Si l'adress existe, le programme fournit l'adresse IP associée à cet argument. En revanche, s'il ne trouve pas d'adresse correspondante, il retourne un message indiquant que l'adresse est invalide.

![Test du Programme](img/Question%202.png)

## Question 3

Pour la réservation d’un socket de connexion vers le serveur. Notre approche consiste à analyser et interpréter les arguments fournis en ligne de commande, tels que l'hôte, le nom du fichier distant, le nom du fichier local et le port. Cette tâche est réalisée par une fonction de parse des arguments. Ensuite, nous avons utilisé la fonction getaddrinfo pour obtenir des informations d'adresse en fonction des paramètres fournis. Ces informations incluent notamment la famille d'adresse (IPv4 ou IPv6) et le type de socket (flux dans notre cas). Après avoir obtenu ces informations, nous avons parcouru la liste des adresses résolues et les avons affichées à des fins de vérification. Par la suite, nous avons créé un socket en fonction des informations d'adresse obtenues à l'aide de la fonction create_socket. Enfin, nous avons libéré la mémoire allouée pour les informations d'adresse à l'aide de freeaddrinfo et fermé le socket. Ce processus constitue une étape cruciale dans la mise en place d'une connexion avec le serveur, préparant ainsi le terrain pour des échanges de données ultérieurs.

## Question 4


