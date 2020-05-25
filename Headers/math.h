int maxp(int a) {return a;}
template<typename... Args>
int maxp(int a, Args... args) {return max(a, maxp(args...));}