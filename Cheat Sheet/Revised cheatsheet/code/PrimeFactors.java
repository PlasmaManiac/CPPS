ArrayList<Integer> F = new ArrayList();
int i = 2;     
while (n != 1 && (i * i <= n)) {
    while (n % i == 0) { 
        n /= i; F.add((int)i); 
    } 
    i += 2; if (i == 4) i--;                      
}
if (n != 1) F.add(n);//if n is prime
return F; 