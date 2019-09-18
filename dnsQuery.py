import dns.resolver
#from time import perf_counter 
#import sys

#t1_start = perf_counter()  

def get_domain_dns(domain):
        
        dns.resolver.default_resolver = dns.resolver.Resolver(configure=False)
        dns.resolver.default_resolver.nameservers = ['200.1.116.10']
        
        g=open("resultados.txt","a+")
                
        dns_records = list()

        try:
            # get the dns resolutions for this domain
            dns_results = dns.resolver.query(domain)
            dns_records = [ip.address for ip in dns_results]
        except dns.resolver.NXDOMAIN as e:
            # the domain does not exist so dns resolutions remain empty
            g.write(url + "\n")
            pass
        except dns.resolver.NoAnswer as e:
            # the resolver is not answering so dns resolutions remain empty
            g.write(url + "\n")
            pass
        except dns.resolver.NoNameservers as e:
            #sys.stdout=open("resultados.txt","a")
            #print(url)
            #sys.stdout.close()
            g.write(url + "\n")
            pass

        return dns_records 
        
### Abre el archivo que contiene las URLs ###

f = open("urls.txt","r")
dominios = f.read()
urls = dominios.splitlines()

### Abre el archivo donde se almacenarán los resultados encontrados ###
g=open("resultados.txt","w")

### Realiza las consultas DNS para cada URL del archivo
for url in urls:
    get_domain_dns(url)

#t1_stop = perf_counter() 
#print("Tiempo total:", t1_stop-t1_start)
