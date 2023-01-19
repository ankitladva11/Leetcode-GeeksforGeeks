class Solution {
public:
    
    bool f2(string &p,int ind){
        if(ind<0) return true;
        if(p[ind]=='*') return f2(p,ind-2);
        return false;
    }
    
    bool f(string &s,string &p,int ind1,int ind2,int m,int n){
        
        if(ind1<0 and ind2<0) return true;
    
        if(ind1<0){
            string s1 = "";
            string p1 = p.substr(0,ind2+1);
            return f2(p1,ind2);
        }
        
        if(ind1<0 or ind2<0) return false;
        
        if(s[ind1]==p[ind2] || p[ind2]=='.') return f(s,p,ind1-1,ind2-1,m,n);
        
        if(p[ind2]=='*')
            if(p[ind2-1]==s[ind1] || p[ind2-1]=='.') return f(s,p,ind1-1,ind2-2,m,n) || f(s,p,ind1-1,ind2,m,n) || f(s,p,ind1,ind2-2,m,n);
            else return f(s,p,ind1,ind2-2,m,n);
        
        
        return false;
        
    }
    
    bool isMatch(string s, string p) {
        return f(s,p,s.size()-1,p.size()-1,s.size(),p.size());
    }
};