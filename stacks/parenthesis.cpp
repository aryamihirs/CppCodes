bool isValid(string s) {
    stack<char> st;
    vector<int> count(6, 0);
    string::iterator it;
    for(it = s.begin(); it!=s.end(); it++)
    {
        //cout << "*it" << *it << "\n";
        if(*it == '('){
            st.push(*it);
            count[0]++;
        }
        if(*it == '{'){
            st.push(*it);
            count[1]++;
        }
        if(*it == '['){
            st.push(*it);
            count[2]++;
        }
        if(*it == ')'){
            count[3]++;
        }
        if(*it == '}'){
            count[4]++;
        }
        if(*it == ']'){
            count[5]++;
        }

        if(!st.empty()){
            if((st.top() == '(' && *it == ')') || (st.top() == '{' && *it == '}') || (st.top() == '[' && *it==']'))
            {
                //cout << "I am inside else if " << "\n";
                st.pop();
            }
        }
    }
    // for(int i=0; i<6; i++)
    //     cout << count[i] << '\n';

    //cout << s[0] << "\n";
    //st.pop();
    //cout << st.top() << "\n";

    if(st.empty()){
        //cout << "I am here bitch!" << "\n" ;
        if(count[0] == count[3] && count[1] == count[4] && count[2] == count[5])
            return true;
        else
            return false;
    }


    else if((s[0] == '}' || s[0] == ']' || s[0] == ')') || !st.empty())
        return false;

    //return st.empty() ? true : false;
}
