#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int N=100010;
int Case,n,m,i,a[N],mx,L,R;ll sum;
struct DS{
  int a[N];
  ll sum;
  set<P>T;
  void init(){
    sum=0;
    int i;
    T.clear();
    int mx=0;
    int j=0;
    T.insert(P(0,0));
    for(i=1;i<=n;i++)if(a[i]>mx){
      mx=a[i];
      T.insert(P(i,a[i]));
      sum+=1LL*a[j]*(i-j);
      //printf("%d %d %d\n",a[j],j,i);
      j=i;
    }
    //puts("end");
  }
  void change(int x,int y){
    set<P>::iterator it=T.lower_bound(P(x,0));
    it--;
    if(it->second>=y)return;
    P pre=*it;
    while(1){
      set<P>::iterator it=T.lower_bound(P(x,0));
      if(it==T.end())break;
      if(y<it->second)break;
      set<P>::iterator k=it;
      k++;
      P w=*it;
      sum-=1LL*pre.second*(w.first-pre.first);
      if(k!=T.end()){
        P nxt=*k;
        sum-=1LL*w.second*(nxt.first-w.first);
        sum+=1LL*pre.second*(nxt.first-pre.first);
      }
      T.erase(it);
    }
    if(true){
      T.insert(P(x,y));
      it=T.find(P(x,y));
      set<P>::iterator pre=it,nxt=it;
      pre--,nxt++;
      if(nxt!=T.end())sum-=1LL*pre->second*(nxt->first-pre->first);
      sum+=1LL*pre->second*(x-pre->first);
      if(nxt!=T.end())sum+=1LL*y*(nxt->first-x);
    }
  }
}A,B;
inline ll query(){
  return 1LL*mx*(R-L+1)+A.sum+B.sum-sum;
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&m);
    mx=0;
    L=R=0;
    sum=0;
    for(i=1;i<=n;i++){
      scanf("%d",&a[i]);
      sum+=a[i];
      A.a[i]=a[i];
      B.a[n-i+1]=a[i];
      if(a[i]>mx){
        mx=a[i];
        L=R=i;
      }else if(a[i]==mx){
        L=min(L,i);
        R=max(R,i);
      }
    }
    A.init();
    B.init();
    while(m--){
      char op[9];
      scanf("%s",op);
      if(op[0]=='P')printf("%lld\n",query());
      else{
        int x,y;
        scanf("%d%d",&x,&y);
        a[x]+=y;
        sum+=y;
        if(a[x]>mx)mx=a[x],L=R=x;
        else if(a[x]==mx){
          L=min(L,x);
          R=max(R,x);
        }
        A.change(x,a[x]);
        B.change(n-x+1,a[x]);
      }
    }
  }
}
