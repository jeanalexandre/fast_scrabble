#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>

using namespace std;

template<class Cle, class T>
void AfficherMultimapRange(const multimap<Cle, T>& m, const Cle& k);

int main(int argc, char *argv[])
{
   ifstream fichier(argv[2], ios::in); //on ouvre le fichier en lecture
   multimap<string, string> MonMultimap; //on cree un multimap
   string inputWord;
   int i;
    int wordLength;

   if(fichier) //si l'ouverture a réussi
   {
       // instructions
       string word;
       string oldWord;

       while(getline(fichier, word)) //tant que l'on peut mettre la ligne dans "contenu"
       {
           wordLength = word.length();
           if (!word.empty() && word[word.size() - 1] == '\r')
               word.erase(word.size() - 1);
           oldWord = word;
           for(i=0;i<wordLength;i++){ //on met tout les caracteres au formats minuscules
               word[i] = tolower(word[i]);
           }
           sort(word.begin(),word.end()); //on tri les caracteres du mot par ordre croissant pour en obtenir un clé
           MonMultimap.insert(make_pair((string)word, (string)oldWord));
       }
       fichier.close(); //on ferme le fichier
   }

   while(1){
       cin >> inputWord;
       wordLength = inputWord.length();
       for(i=0;i<wordLength;i++){
           inputWord[i] = tolower(inputWord[i]);
       }
       sort(inputWord.begin(),inputWord.end());

       AfficherMultimapRange(MonMultimap, (string)inputWord);
   }
}

template<class Cle, class T>
void AfficherMultimapRange(const multimap<Cle, T>& m, const Cle& k)
{
   typedef typename multimap<Cle, T>::const_iterator  Itor;

   pair<Itor, Itor> p = m.equal_range(k);
   for (Itor i = p.first; i != p.second; ++i)
       cout << i->second << "\n";
}