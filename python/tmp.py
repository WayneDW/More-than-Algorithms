def factorial( n ):
   if n <1:   # base case
       return 1
   else:
       return (1+ 1/n) * factorial( n - 1 )  # recursive call


print factorial(999)