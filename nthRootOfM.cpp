double multiply (double num, int n) {
  double ans = 1;
  for (int i=0; i<n; i++) {
    ans *= num;
  }
  return ans;
}

int NthRoot(int n, int m) {
  // Write your code here.
  long low = 1;
  long high = m;

  while ((high-low)>1) {
    int mid = low+((high-low)/2);
    if (multiply(mid, n)>m) {
      high = mid;
    }
    else if (multiply(mid, n)<m) {
      low=mid;
    }
    else return mid;
  }

  return -1;

  

}
