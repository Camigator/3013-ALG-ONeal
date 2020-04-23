#include <iostream>

using namespace std;

int parent[26];
int Child[26];

void Make_Tree(int x);
int Find(int x);
void Join(int &x, int &y);




int main(){
    int T,n,x,y,ans;
    char c;
    string s;
    
    scanf("%d\n\n",&T);   // scan the first digit store in  T
    
    for(int i = 1; i <= T; i ++){
        getline(cin,s);   // get largest node 
        n=s[0]-'A'+1;     // Creates the ascII value 
        
        ans=n;

        for(int i=0;i<n;i++) 
          Make_Tree(i); //Makes our arrays
        
        while(1){

            if(!getline(cin,s) || s.empty()) //Travel through the loop until their are no more nodes
             break;
            
            x=s[0]-'A'; y=s[1]-'A'; // finding the valuse of the char, by switch to numbers
            
            //if char are not equal to each other connect them
            if(Find(x)!=Find(y)){
                Join(x,y);
                ans--;
            }
        }
        
        if(i !=1)
        printf("\n");
        printf("%d\n",ans); // print out number of connections by which has the most.
    }
    
    return 0;
}



void Make_Tree(int x)
{
    parent[x]=x;
    Child[x]=0;
}

// Search our tree through recursion
// by looking for a the ascII value of our char
int Find(int x)
{
    if(x!=parent[x])
     parent[x]=Find(parent[x]);
    return parent[x];
}

void Join(int &x, int &y)

{
    int J = Find(x), I = Find(y);

    if(Child[J]>Child[I])
        parent[I]=J;
    else{
        parent[J]=I;
        if(Child[J]==Child[I])
            Child[I]++;
    }
}
