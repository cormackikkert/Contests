inn = "primes.in"
outn = "primes.out"
inf=open(inn);outf = open(outn,"w");fileInput=lambda:inf.readline().strip();
filePrint=lambda args,sep=' ',end='\n':[outf.write(sep.join(map(str,args))+end),outf.flush()]

aPrimes = [2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991, int('1'*19), int('1'*23), int('1'*317), int('1'*1031)]
num = int(fileInput())
high = int('1' + '0' * len(str(num)))
for prime in aPrimes:
    if num < prime < high:
        filePrint([prime])
        break
else:
    filePrint([0])
