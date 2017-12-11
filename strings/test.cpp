#include<bits/stdc++.h>

using namespace std;

bool isIsomorphic(string s, string t) {
        int l = s.size(), i, a, b;
        vector<int> A,B;

        for(i = 0; i < 26; i++){
            A.push_back(-1);
            B.push_back(-1);
        }

        for(i = 0; i < l; i++){
            a = s[i] - 'a';
            b = t[i] - 'a';
            cout << i << "\n";
            cout << "a: " << a << "\n";
            cout << "b: " << b << "\n";
            std::cout << "A[i]: " << A[i] << '\n';
            for(i = 0; i < l; i++){
              std::cout << "B[i]: " << B[i] << '\n';}

            cout << "A[a], B[b] " << A[a] << ", "<< B[b] << "\n";
            if(A[a] == -1 && B[b] == -1){
                A[a] = b;
                B[b] = a;
                cout << "YESSS!" << "\n";
            }

            else{
                if(!(A[b] == a && B[a] == b))return false;
            }
        }
        return true;
}

void computeLPS(string p, int M, int* lps){
  int i = 1, len = 0;
  lps[0] = 0;
  while(i < M){
    if(p[i] == p[len]){
      len++;
      lps[i] = len;
      i++;
    }
    else{
      if(len != 0){
        len = lps[len-1];
      }
      else{
        lps[i] = 0;
        i++;
      }
    }
  }
}

void KMP(string txt, string pat){
  int i = 0, j = 0;
  int M = pat.length(), N = txt.length();
  int lps[M];
  computeLPS(pat, M, lps);
  while(i < N){
    if(txt[i] == pat[j]){
      i++;
      j++;
    }

    if(j == M){
      cout << "Pattern Found at: " << i - j << "\n";
      j = lps[j-1];
    }

    else if(txt[i] != pat[j] && i < N){
      if (j != 0)
        j = lps[j-1];

      else
        i++;
    }
  }
}

int LCS(string p, string q){
  int M = q.length(), N = p.length(), i, j, maxa = 0;
  int lcs[N+1][M+1];
  for(i = 0; i < N+1; i++)
    lcs[i][0] = 0;

  for(j = 0; j < M+1; j++)
    lcs[0][j] = 0;

  for(i = 1; i < N+1; i++){
    for(j = 1; j < M+1; j++){
      if(p[i-1] != q[j-1]){
        lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
      }
      else if(p[i-1] == q[j-1])
        lcs[i][j] = 1 + lcs[i-1][j-1];
    }
    // if(maxa < lcs[i][j])maxa = lcs[i][j];
  }

  return lcs[N][M];
}
// void reverseWords(string &s){
//   int r = 0, n = s.length(), i = 0, numwords = 0, start = 0, j, end = s.length()-1, c = 0;
//   string t;
//   reverse(s.begin(), s.end());
//   for(j = 0; j < s.length(); j++){
//       if(s[j] == ' ')start++;
//       else break;
//   }
//
//   for(j = n-1; j >= 0; j--){
//       if(s[j] == ' ')end--;
//       else break;
//   }
//
//   s = s.substr(start,end-start+1);
//   string::iterator it = s.begin();
//   std::cout << "s after substr: " << s <<'\n';
//
//   for(j = 0; j < s.length(); j++){
//       if(s[j] == ' ')c++;
//   }
//
//   if(c != 0)
//   {
//     // if(c == n)s = t;
//     while(i < n){
//         while(s[r] != ' ' && r < n){
//             r++;
//         }
//         std::cout << "r, before r--: " << r << '\n';
//         std::cout << "i, before r--: " << i << '\n';
//         r--;
//         reverse(it+i, it+r+1);
//         std::cout << "s_curr: " << s <<'\n';
//         r = r+2;
//         i = r;
//     }
//   }
// }

void reverseWords(string &s){
    int r = 0, n, i = 0, numwords = 0, start = 0, j, end = s.length()-1, c = 0;
    string temp, ans;
    reverse(s.begin(), s.end());
    // for(j = 0; j < s.length(); j++){
    //     if(s[j] == ' ')start++;
    //     else break;
    // }
    //
    // for(j = n-1; j >= 0; j--){
    //    if(s[j] == ' ')end--;
    //    else break;
    // }
    // s = s.substr(start,end-start+1);
    // std::cout << "new str: " << "'"<< s << "'"<< '\n';
    n = s.length();
    while(i < n){
        if(s[i] == ' ')i++;
        else{
            r = i;
            while(s[r] != ' ' && r < n)
                r++;
            cout << "i: " << i << "\n";
            std::cout << "r: " << r << '\n';
            std::cout << "n: " << n << '\n';
            temp = s.substr(i,r-i);
            std::cout << "temp: " << "'"<< temp << "'"<< '\n';
            reverse(temp.begin(), temp.end());
            ans.append(temp);
            // if(r < n-1)
            ans.append(" ");
            i = r;
        }
    }
    s = ans;
    n = s.length();
    s  = s.substr(0,n-1);
    std::cout << "n: " << n << '\n';
    std::cout << "s new: " << "'" << s << "'" << '\n';
}
// MS !
string transform(string s){
  int l = s.length(), i = 0, j = 2;
  string ans;

  if(l == 0 || l == 1 || l == 2)
    return s;

  while(i < l){
    if(s[i] == 'a' && s[j] == 'e')
    {
      if(j < l && s[j+1] == 'e')
        j++;

      else{
        ans += s[i];
        i = j;
        j += 2;
      }
    }

    else{
      ans+=s[i];
      i++;
      j++;
    }
  }
  return ans;
}

void minLenCommonWords(string p, string q){
  char *q_char = new char[q.length()];
  strcpy(q_char, q.c_str());
  char *pat_tok = strtok(q_char , " ");
  int pat_l = strlen(pat_tok);
  cout << "l: " << pat_l << "\n";
  vector<string> q_words;
  while(pat_tok){
    string temp(pat_tok);
    q_words.push_back(temp);
    cout << pat_tok << "\n";
    pat_tok = strtok(NULL, " ");
  }
  for(int i = 0; i < q_words.size(); i++){
    cout << q_words[i] << " ";
  }
}

void tokSpacePrint(string s){
  char *temp;
  temp = new char[s.length()];
  strcpy(temp, s.c_str());
  char *tok = strtok(temp, " ");
  while(tok){
    cout << tok << "\n";
    tok = strtok(NULL, " ");
  }
}
void tokQuotesPrint(string s){
  std::cout << '"' << s << '"' << '\n';
}

void tokanize(string s){
  vector<string> v;
  char *temp;
  int c = 0;
  temp = new char[s.length()];
  strcpy(temp, s.c_str());
  char *tok1 = strtok(temp, "“”");
  while(tok1){
    string temp(tok1);
    v.push_back(temp);
    //std::cout << tok1 << '\n';
    tok1 = strtok(NULL, "“”");
  }

  for(int i = 0; i < v.size(); i++){
    if(i%2 == 0){
      tokSpacePrint(v[i]);
    }
    else{
      tokQuotesPrint(v[i]);
    }
  }
}

int main(){
  //string p = "add";
  //string q = "egg";
  string s = "    a a a a  ";
  string test = "memememe";
  // (isIsomorphic(p,q))?std::cout << "YESSS!" : std::cout << "Noooo";

  string txt = "aaaabaaaa";
  string pat = "aaaa";

  string a = "acdef";
  string b = "bbcd";
  string ss = "aaee";
  // KMP(txt,pat);
  // std::cout << "n: " << s.length() <<'\n';
  // reverseWords(s);
  // string::iterator it = test.begin();
  // reverse(it+1, it+3);
  // std::cout << "Here is my output: " << "'" << s << "'" << "\n";

  // std::cout << "len of LCS for a, b: " << LCS(a,b) << '\n';

  string p = "what about the lazy brown fox that jumped over the other brown one which lazy dog ate the food of the fox";
  string q = "lazy brown dog";

  string ip = "abc pqr mnp “asdasd asdsad” lol pip “adsad”";
  tokanize(ip);
  //minLenCommonWords(p , q);

  // std::cout << "string after transformation: " <<"'" <<transform(ss) << "'"<< '\n';
  return 0;
}
