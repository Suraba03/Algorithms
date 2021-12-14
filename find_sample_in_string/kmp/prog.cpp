#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<size_t> prefix_function(string s) 
{
    size_t n =  s.length();
    // в i-м элементе (его индекс i-1) количество 
    // совпавших символов в начале и конце для подстроки длины i.
    vector<size_t> pi(n);  
			 // p[0]=0 всегда, p[1]=1, если начинается с двух одинаковых 
    for (size_t i=1; i<n; ++i) 
    {
       // ищем, какой префикс-суффикс можно расширить
        size_t j = pi[i-1]; // длина предыдущего префикса-суффикса, возможно нулевая
        while ((j > 0) && (s[i] != s[j])) // этот нельзя расширить,
            j = pi[j-1];   // берем длину меньшего префикса-суффикса

        if (s[i] == s[j]) 
            ++j;  // расширяем найденный (возможно пустой) префикс-суффикс
        pi[i] = j;
     }
     return pi;
}

vector<size_t> KMP(std::string pattern, std::string text)
{
    int n = text.length();
    int m = pattern.length();

    vector<size_t> Lps = prefix_function(pattern); // применяем префиекс функцию
    vector<size_t> out; // вектор с индексами вхождений
        
    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++; j++;
        } // если совпало, продолжаем
        if (j == m) { // если j==m это подтверждает то, что мы нашли образец в тексте
            out.push_back(i - m); // добавляем этот индекс минус длина образца в вектор out  
            j = Lps[j - 1]; // обновляем j как префикс последнего совпавшего символа 
        } else if (i < n && pattern[j] != text[i]) {  // если не совпало
            if (j == 0) {
                i++; // если j становится равным нулю, делаем инкремент индекса i
            } else {
                j = Lps[j - 1]; // обновляем j как префикс последнего совпавшего символа
            }
        }
    }
    return out;
}


int main(int argc, char const *argv[])
{
    // читаем образец с потока ввода
    string pattern;
    cout << "Enter pattern:" << endl;
    getline(cin, pattern);

    // читаем текст из файла, название которого получаем из потока ввода 
    string text;
    string name;
    cout << "Enter name of the file with test text: ";
    cin >> name;
    ifstream t(name);
    stringstream buffer;
    buffer << t.rdbuf();
    text = buffer.str();
    
    // выводим информацию о полученных данных
    cout << "for text \"" << text << "\" -- length is " << text.size()
         << "\nand pattern \"" << pattern << "\" -- length is "
         << pattern.size() << endl;  
    
    // применяем поиск и присваиваем
    // вектор индексов вхождений к вектору с именем prefix_array
    vector<size_t> prefix_array = KMP(pattern, text);
    
    cout << "Choose where you want to see output of the program file or terminal\n"
         << "if you choose file press f\nif you choose terminal press t\n";
    char c;
    cin >> c;
    if (c == 't') {
        // выводим индексы вхождений
        cout << "Array " << prefix_array.size() << " of enterings: ";
        for (auto i : prefix_array) cout << i << " "; 
        cout << endl;
    } else if (c == 'f') {
        cout << "Enter name of the output file: ";
        string name_out;
        cin >> name_out;
        ofstream f(name_out);
        cout << "Array " << prefix_array.size() << " of enterings saved in file - " << name_out;
        for (vector<size_t>::const_iterator i = prefix_array.begin(); i != prefix_array.end(); ++i)
            f << *i << ' ';
        f << endl;
    }
    return 0;
}
