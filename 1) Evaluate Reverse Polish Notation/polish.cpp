int evalRPN(vector<string>& tok) {
        vector<int>st;
        for(int i = 0;i<tok.size();i++){
            if(tok[i]=="+" || tok[i]=="-" || tok[i]=="/" || tok[i]=="*"){
                int a = st.back();st.pop_back();
                int b = st.back();st.pop_back();
                int c;
                if(tok[i]=="*") c = a*b;
                else if(tok[i]=="/")    c = b/a;
                else if(tok[i]=="+")    c=b+a;
                else c=b-a;
                st.push_back(c);
            }
            else
                st.push_back(stoi(tok[i]));
        }
        return st.back();
    }