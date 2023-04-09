//
// Created by Harsha Vardhan on 19/02/22.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool differs_by_a_single_letter(string one, string two) {
    int c = 0;
    for (int i = 0; i < one.size(); i++) {
        if (one[i] != two[i]) c++;
    }
    return c == 1;
}

void findLaddersHelper(vector<string> &wordList, string word, vector<string> tmp, vector<vector<string>> &ans,
                       unordered_set<string> visited, string endWord, int &res) {
    if (tmp.size() > res) return;
    if (word == endWord) {
        int k = tmp.size();
        res = min(res, k);
        ans.push_back(tmp);
        return;
    }
    for (int i = 0; i < wordList.size(); i++) {
        if (visited.find(wordList[i]) == visited.end() &&
            differs_by_a_single_letter(word, wordList[i])) {
            visited.insert(wordList[i]);
            tmp.push_back(wordList[i]);
            findLaddersHelper(wordList, wordList[i], tmp, ans, visited, endWord, res);
            tmp.pop_back();
        }
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
    vector<vector<string>> ans;
    unordered_set<string> visited;
    vector<string> tmp;
    tmp.push_back(beginWord);
    int res = INT_MAX;
    findLaddersHelper(wordList, beginWord, tmp, ans, visited, endWord, res);
    int min_size = INT_MAX;
    for (int i = 0; i < ans.size(); i++) {
        int k = ans[i].size();
        min_size = min(k, min_size);
    }
    vector<vector<string>> z;
    for (int i = 0; i < ans.size(); i++) {
        int k = ans[i].size();
        if (k == min_size) {
            z.push_back(ans[i]);
        }
    }
    return ans;
}

int main() {
    /*
     * "qa"
"sq"
["si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"]
     * */
    vector<string> wordList{"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av",
                            "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr",
                            "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as",
                            "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz",
                            "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st",
                            "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr",
                            "pa", "he", "lr", "sq", "ye"};
    vector<vector<string>> ans = findLadders("qa", "sq", wordList);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
