#include<bits/stdc++.h>
using namespace std;

struct author {
    string surname;
    vector<string> name;

    author() {
        surname = "";
    }
    
    author(string S, vector<string>& N) {
        surname = S;
        name = N;
    }

    bool operator < (const author ot) const {
        if (surname != ot.surname) return surname < ot.surname;
        return name < ot.name;
    }

    bool operator == (const author ot) const {
        return (surname == ot.surname && name == ot.name);
    }

    bool operator != (const author ot) const {
        return (surname != ot.surname || name != ot.name);
    }
};

struct reference {
    vector<author> authors;
    string rest;
    string title;
    int volume;
    
    reference() {
        rest = "";
    }

    reference(vector<author> A, string S, string T, string V = "") {
        authors = A;
        rest = S;
        title = T;
        if (V == "") 
            volume = INT_MAX;
        else volume = stoi(V);
    }

    bool operator < (const reference ot) const {
        if (authors != ot.authors) return authors < ot.authors;
        if (title != ot.title) return title < ot.title;
        return volume < ot.volume;
    }
};

ifstream bibin ("bibtex.in", ifstream::in);
ofstream bibout ("bibtex.out", ofstream::out);

pair<string, string> interpret(string& line) {
    string left, right;
    int i;
    left = right = "";
    
    for (i = 0; i < (int)line.size(); i++) {
        if (line[i] == '\"') break;
        if (isalpha(line[i])) left += line[i];        
    }
    i++;
    
    for (; i < (int)line.size(); i++) {
        if (line[i] == '\"') break;
        right += line[i];
    }
    
    return pair<string, string>(left, right);
}

unordered_map<string, string> unmarshal() {
    unordered_map<string, string> hashMap;
    string line;
    getline(bibin, line);

    assert(line == "{");
    getline(bibin, line);

    while (line != "}") {
        pair<string, string> relation = interpret(line);
        hashMap[relation.first] = relation.second;
        getline(bibin, line);
    }

    return hashMap;
}

vector<author> getAuthors(string str) {
    vector<string> name;
    vector<author> authors;
    string cur = "";
    
    for (int i = 0; i < (int)str.size(); i++) {
        if (!isspace(str[i])) cur += str[i];
        else {
            if (cur == "and") {
                string surname = name.back();
                name.pop_back();
                authors.push_back(author(surname, name));
                cur = "";
                name.clear();
            } else {
                name.push_back(cur);
                cur = "";
            }
        }
    }

    name.push_back(cur);
    string surname = name.back();
    name.pop_back();
    authors.push_back(author(surname, name));
    cur = "";

    return authors;
}

string shortAuthors(vector<author> authors) {
    string ret = "";
    for (auto A : authors) {
        if (ret != "") ret += ", ";
        ret += A.surname;
        for (string name : A.name) {
            string initial = string(1, name[0]);
            ret += " " + initial + ".";
        }
    }

    return ret;
}

bool interval(string& str) {
    for (int i = 1; i < (int)str.size(); i++) {
        if (str[i] == '-' && str[i - 1] == '-') return true;
    }

    return false;
}

reference buildBook() {
    unordered_map<string, string> fields = unmarshal();
    reference result;
    vector<author> authors;
    string rest;
    string title;
    string volume = "";
    
    if (fields.find("author") != fields.end()) {
        authors = getAuthors(fields["author"]);
        sort(authors.begin(), authors.end());

        rest += shortAuthors(authors);
    } else {
        cerr << "Missing author" << endl;
        exit(-1);
    }

    if (fields.find("title") != fields.end()) {
        rest += " " + fields["title"];
        title = fields["title"];
    } else {
        cerr << "Missing title" << endl;
        exit(-1);
    }

    if (fields.find("volume") != fields.end()) {
        rest += ", Vol. " + fields["volume"];
        volume = fields["volume"];
    } 
    
    if (fields.find("publisher") != fields.end()) {
        rest += " -- " + fields["publisher"];
    } else {
        cerr << "Missing author" << endl;
        exit(-1);
    }
    
    if (fields.find("year") != fields.end()) {
        rest += ", " + fields["year"];
    } else {
        cerr << "Missing author" << endl;
        exit(-1);
    }

    result = reference(authors, rest, title, volume);
    return result;
}

reference buildArticle() {
    unordered_map<string, string> fields = unmarshal();
    reference result;
    vector<author> authors;
    string rest;
    string title;

    if (fields.find("author") != fields.end()) {
        authors = getAuthors(fields["author"]);
        sort(authors.begin(), authors.end());

        rest += shortAuthors(authors);
    } else {
        cerr << "Missing author" << endl;
        exit(-1);
    }

    if (fields.find("title") != fields.end()) {
        rest += " " + fields["title"];
        title = fields["title"];
    } else {
        cerr << "Missing title" << endl;
        exit(-1);
    }

    if (fields.find("journal") != fields.end()) {
        rest += " // " + fields["journal"];
    } else {
        cerr << "Missing author" << endl;
        exit(-1);
    }

    if (fields.find("volume") != fields.end()) {
        rest += ", " + fields["volume"];
    } 

    if (fields.find("number") != fields.end()) {
        rest += " (" + fields["number"] + ")";
    } 

    if (fields.find("year") != fields.end()) {
        rest += " -- " + fields["year"];
    } else {
        cerr << "Missing author" << endl;
        exit(-1);
    }

    if (fields.find("pages") != fields.end()) {
        string prep = interval(fields["pages"]) ? "pp." : "p.";
        rest += " -- " + prep + " " + fields["pages"];
    } 
    
    result = reference(authors, rest, title);
    return result;    
}

void printAnswer(vector<reference> answer) {
    sort(answer.begin(), answer.end());
    int i = 1;
    
    for (reference ans : answer) {
        bibout << "[" << i++ << "] " << ans.rest << endl;
    }    
}
int main() {
    string type;    
    vector<reference> answer;

    
    while (getline(bibin, type)) {
        if (type == "@book") {
            answer.push_back(buildBook());
        } else if (type == "@article") {
            answer.push_back(buildArticle());
        } else if (type != "") {
            cerr << "Type not supported" << endl;
            return -1;
        }
    }

    printAnswer(answer);

    return 0;
}
