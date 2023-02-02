#Thème de projet: Mythologie nordique les 9 MONDES 

#Présentation du groupe et du thème d’énigme: 
Le groupe est constitué de 3 personnes: Arnaud, Hamidur et Regan. Arnaud s’occupe de la partie énigme, Hamidur de la partie communication et Regan de la partie déplacement du véhicule. Le thème général de l’escape game: Il y a 5 groupes de 3 personnes. Chaque groupe est dans un monde différent comme le monde du feu ou le monde des géants, ce sont les mondes de la mythologie nordique, notre groupe est dans le monde du froid qui se nomme Niflheim. Le but de chaque groupe est de sortir de ce monde pour atteindre la Terre. Mais pour réussir à sortir, il faut résoudre des énigmes ce qui va permettre de d'obtenir une clef afin de quitter ce monde.

#Voici le script de l'énigme de notre groupe:
	Le joueur a devant lui un pad sur lequel s’affiche un calcul que le joueur devra résoudre, il devra résoudre une équation de type 3x² - 28 = -1, (trouver X). Après avoir trouver x, le joueur trouvera une lettre qui va lui dire d’aller sur un point précis, devant une porte.   
Deuxième énigme: le joueur est devant  la porte, et pour l’ouvrir il doit émettre une pression précise. Ensuite, derrière la porte se trouvera la clé pour repartir sur Terre.
   





#Niflheim monde de glace

temps limité car extrème température négative (10 min max)
 Calculs mathématiques : si bon résultat/bonne réponse alors fonte de la glace clé obtenu : capteur pad, écran
 capteur force pour ouvrir la porte pression exigée pour l’ouvrir (0,2N à 20N) en X temps

Le joueur a devant lui un pad sur lequel s’affiche un calcul que le joueur devra résoudre ( Ici se trouve une clé, une clé importante piégée dans ce bloc de glace car permettra de retrouver ton monde. Selon ta réponse la glace fondra…ou pas. Ma question est la suivante: sauras-tu trouver X ?). Si bonne réponse, la carte arduino envoie le signal au robot pour son déplacement. Ensuite il se trouve devant  un porte, et pour l’ouvrir il doit émettre une pression précise (Une force bien utilisée est un point fort, mal utilisée elle devient une faiblesse, contrôle celle-ci pour atteindre X et pouvoir partir d’ici). Ensuite il a la clé pour repartir sur Midgard. 
site de ecran:
Grove - 16x2 LCD - Seeed Wiki
site pad:
https://wiki.seeedstudio.com/Grove-12-Channel-Capacitive-Touch-Keypad-ATtiny1616-/

#Travail individuelle de chaque membre du groupe:
Arnaud:
        J’ai commencé à travailler sur le capteur de force et la led pour s'allume si le capteur de force est sollicitée et s'éteigne si non sollicitée le 3eme jour car, le 2ème jour, je fus en sortie 1h puis on construit l'énigme petit à petit. Ne sachant pas par quoi commencer, j’ai regardé sur https://wiki.seeedstudio.com/Grove-Round_Force_Sensor_FSR402 ethttps://wiki.seeedstudio.com/Grove-LED_Socket_Kit/pour avoir les programmes de base et puis pour je l’ai modifier par la suite regardé sur https://www.arduino.cc/reference/fr pour modifier les programmes. Le 3ème jour, j'ai enlevé chaque ligne des programmes, unes par unes et je rajoutais sur celui du capteur de force puis je televersais à chaque fois pour comprendre à quoi elle servait chacune entre-temps Regan, Hamidur et moi se sont mis d'accord sur le déroulement de l'énigme. Elle allait se dérouler dans un temps limité (- de 10 min). J'ai modifié le Serial.begin(9600) qui était dans void setup(){  pour le passer en 500 pour que la force utilisée défile moins vite. Dans void loop() { , j'ai rajouté digitalWrite(LED, HIGH) et digitalWrite(LED, LOW); mais ça mettait un message d'erreur à chaque fois.
4 ème jour, j'ai demandé à Hamidur de m'aider mais malheureusement nous avons pas eu le temps de modifier le programme convenablement.


Hamidur: 
Le premier jour, moi et Regan nous avons commencé à voir comment fonctionnent le pad et l’écran (On ne savait pas par quoi commencer), pour ça nous avons utilisé le site wiki.seeedstudio.com, sur ce site nous avons pu avoir le code arduino de chacun des deux composant et nous les avons exécuter pour voir leur fonctionnement. Pour le pad, le code était assez simple et donc nous avons compris assez rapidement  mais pour l’écran nous avons eu quelques difficulté qui à étais très vite résolu par l’aide de M.lampure qui nous a expliqué quelque partie du code qu’on avait pas saisi. 
Et ensuite nous avons essayé de rattacher le pad avec l’écran. Pour 
ça nous avons intégré le code de Pad dans le code de l’écran, à chaque SERIAL.println on a mis lcd.println.
Puis j’ai commencé à voir le code arduino de communication Wifi et j’ai travaillé avec Grégory qui faisait aussi  la partie communication de son groupe. On avait seulement réussi à se connecter entre nous sans rien de plus, sans pouvoir s’envoyer des messages. Mais encore une fois grâce à l’aide de M. Lampure j’ai réussi à comprendre l'essentiel et ensuite j’ai commencé à réfléchir à ce que mon  programme doit faire. J’ai donc pris le code de premier engine (Trouver le X), et je l’ai mis tout les paramètre de envoyeur et j’ai ajouter une ligne de code: à la fin quand l'énigme sera validé, ce script va envoyer “#1” au receveur. Et puis j’ai pris le code de Regan, du robot, et j’ai mis tous les paramètres de receveur, et j’ai fait un “if” donc if (si) on reçois “#1” on fait le 1er mouvement. J’ai aussi fait if “#2” mais l'énigme n'était pas finie donc ils ne servaient à rien. 
Pour finir, j'ai un peu aidé Arnaud pour la programmation de son énigme 2.

Regan: 
Au début nous avons trouvé sur quelles énigmes se basera notre étape dans l’escape game et avons essayé comprendre comment fonctionnent nos capteurs( capteur de force, écran lcd, pad numérique).
Ensuite je suis passé sur ma partie, c'est-à-dire la partie déplacement du robot. Pour commencer j’ai du comprendre comment fonctionnaient les servomoteur du robot qui sont indépendant donc qu’ils ont chacun une vitesse de rotation mais les vitesses sont quand même plus ou moins identiques.
Sur Arduino la roue de droite avançait à partir d’environ 1200 et reculait à partir d’environ 1800 et s'arrêtait à environ 1500 .

La roue de gauche avançait à partir de 1900 et reculait à partir de 1200 et s'arrêtait à environ 1500  .

Donc pour trouver à quelle vitesse tournaient les deux roues j’ai dû mesurer le nombre de tour que fait une roue sur un 10 sec en changeant la vitesse sur ARDUINO de tous les 100-200 et avec les valeurs obtenu j’ai fait un tableau pour chaque roue et j’ai fait un produit en croix pour chaque valeur pour en faire un graphique sur TABLEUR.
Pour finir j’ai utilisé MATLAB pour trouver la vitesse de rotation de chaque roue par rapport à la distance ou l’angle à laquelle doivent tourner les roues.


