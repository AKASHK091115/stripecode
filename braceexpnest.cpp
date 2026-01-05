string pre1, pre2;
vector<string> options;

bool inBrace = false;
bool braceDone = false;

string temp = "";

for(char c : s) {
    if (!inBrace && !braceDone) {
        if (c == '{') {
            inBrace = true;
        } else {
            pre1 += c;
        }
    }
    else if (inBrace) {
        // inside options zone
        if (c == ',' ) {
            options.push_back(temp);
            temp.clear();
        }
        else if (c == '}') {
            options.push_back(temp);
            temp.clear();
            inBrace = false;
            braceDone = true;   
        }
        else {
            temp += c;
        }
    }
    else {
        pre2 += c;
    }
}

for (auto &opt : options)
    result.push_back(pre1 + opt + pre2);
