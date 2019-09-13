import dns.resolver
import sys

def resolveDNS(dominio):
    
    resolver = dns.resolver.Resolver(); 
    answer = resolver.query(dominio , "A")
    return answer

urls = open("urls.txt","r")
content = urls.read()
dominios = content.splitlines()

archivo=open("resultados.txt","w")
archivo.close()

for dominio in dominios:
    resultDNS = resolveDNS(dominio)
    answer = ''
    for item in resultDNS:
        IP = ','.join([str(item), answer])
        #sys.stdout=open("resultados.txt","a")
        print(dominio + ": " + IP)
        #sys.stdout.close()