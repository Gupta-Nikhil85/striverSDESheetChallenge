// double findNthRootOfM(int n, long long m) {
// 	// Write your code here.
//     double high = (double) m, low=1.0;
//     double esp=1e-8;
//     while(high-low>esp){
//         double mid=(high-low)/2 + low;
//         double curr=pow(mid,n);
//         if(curr > (double) m){
//             high=mid;
//         }
//         else{
//             low=mid;
//         }
//     }
//     return low;
// }
double findNthRootOfM(int n, long long m) {
    // Write your code here.
    double t=1.000000/n;
    double ans=pow(m,t);
    return ans;
}