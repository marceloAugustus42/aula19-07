#include <bits/stdc++.h>

using namespace std;

int acha_maior(vector<int> v){
    int maior = v[0];
    for (int i = 1; i < v.size(); i++){
        if (maior < v[i]){
            maior = v[i];
        }
    }
    return maior;    
}

void counting_sort(vector<int> v){
    //cria vetor m+1
    vector<int> freq(acha_maior(v)+1);
    vector<int> copia(v.size());

    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    //preenche frequencia
    for (int i = 0; i < freq.size(); i++){
        if (v[i]==i){
            freq[i]+=1;
        }
    }

    //calcula frequencia
    for (int i = 1; i < freq.size(); i++){
        freq[i]= freq[i-1]+freq[i];
    }

    for (int i = 0; i < freq.size(); i++){
        cout << freq[i] << " ";
    }
    cout <<" xxxxxx" << endl;

    //coloca na copia
    for (int i = v.size()-1; i > 0; i--){
        if (freq[i] > freq[i-1])
        {
            copia[freq[v[i]]-1] = v[i];
            freq[v[i]]--; 
        }
    }
    for (int i = 0; i < freq.size(); i++){
        cout << copia[i] << " ";
    }
    cout <<" xxxxxx" << endl;

    for (int i = 0; i < v.size(); i++){
        v[i]= copia[i];
        cout << v[i] << " ";
    }
    cout << endl;
    
}

int main(){
    srand(time(NULL));
    int tam = 10;
    vector<int> vet(10);

    for (int i = 0; i < tam; i++){
        vet[i] = 1 + rand()%100;
    }

    counting_sort(vet);

    return 0;
}