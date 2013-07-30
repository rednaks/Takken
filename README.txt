Description : 
Ceci est le code de base de l'éditeur de mVision : Takken
Takken est une platforme qui regrouppe une démonstration de quelques exemples sur le traitement d'image à savoir, des filtres, la segmentation, la morphologie
mathématique et la caractérisation. 
L'implémentation de ces exemples a été faite à l'aide de la bibliothèque OpenCV.

Installation :
  LINUX : 
    1- Vous devez tout d'abort installer les bibliothèques necessaire pour compiler, opencv-2.3 (ou supérieur) et Qt4
      Sous ubuntu/debian vous pouvez lancer la commande suivante : sudo apt-get install libqt4-dev libopencv-dev
    2- Pour compiler : cd src/ && qmake && make
    3- Enfin lancer le binaire : ./mvison.bin

  WINDOWS:
    1- Installez de Qt4 et QtCreator et opencv-2.4.3.
    2- Ouvrir le fichier mvision.pro avec QtCreator.
    3- Changer le chemin pour OpenCV dans le fichier mvision.pro.
    4- Compiler et Lancer.


LICENCE: 
  Ce code source est sous licence MIT.

TEAM : 
  Emna Fraj
  Alexandre BM
  Amine Akrout
  Hermann Fotso
