// Document Distance Problem 6.006 Lec-2

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;

vector<string> filepaths = {"docDis1.txt", "docDis2.txt"};

string normalizeWord(string word){
  for(char &c  : word)
    c = tolower(c);

  word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
  return word;
}

double dotProd(const map<string,int> &vec1, const map<string, int> &vec2){
  double dot = 0;
  for(const auto &pair : vec1){
    auto it = vec2.find(pair.first);
    if (it != vec2.end())
      dot += pair.second * it->second;
  }
  return dot;
}

double mag(const map<string, int> &vec){
  double mag = 0;
  for(const auto &pair : vec)
    mag += pair.second * pair.second;
  return sqrt(mag);
}

double CosSimilarity(const map<string, int> &vec1, const map<string, int> &vec2){
  double dot = dotProd(vec1, vec2);
  double mag1 = mag(vec1);
  double mag2 = mag(vec2);
  if (mag1 == 0 || mag2 == 0)
    return 0;
  return dot / (mag1 * mag2);
  
}


int main(){
  map<string,int> wordCounts1, wordCounts2;
  for(int i=0; i<filepaths.size(); i++){
    ifstream file(filepaths[i]);
    string line;
    while(getline(file, line)){
      istringstream iss(line);
      string word;
      while(iss >> word){
        word = normalizeWord(word);
        if(i ==0)
          wordCounts1[word]++;
        else 
          wordCounts2[word]++;
      }
        
      }
    file.close();
    
  }
  double similar = CosSimilarity(wordCounts1, wordCounts2);
  cout << "Cosine similarity : " << similar << endl;
  return 0;
}

