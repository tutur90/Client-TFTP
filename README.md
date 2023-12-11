# Client-TFTP

Creation d'un client TFTP

![Titre](img/UtilisationTFTP.png)
On a utilisé la commande TFTP pour transférer ce fichier vers un serveur TFTP situé sur srvtpinfo1.ensea.fr.Le transfert s'est déroulé avec succès, comme indiqué par le message "Sent 15 bytes in 0.0 seconds" dans l'interface TFTP.
Par la suite, on a supprimé le fichier test.txt localement avec la commande rm et vérifié que le fichier a été supprimé avec succès en utilisant à nouveau la commande ls.
Ensuite, on a utilisé à nouveau la commande TFTP pour télécharger le fichier test.txt depuis le serveur TFTP. Le transfert a été réussi, comme indiqué par le message "Received 15 bytes in 0.0 seconds" dans l'interface TFTP. Et aprés on a vérifié le contenu du fichier téléchargé avec la commande cat et confirmé que le texte "hello world" était présent.

## Question 1


